// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "hidapi.h"
#include "InputCoreTypes.h"
#include "JoyConInformation.h"
#include "JoyConState.h"
#include "Containers/Queue.h"
#include "GenericPlatform/GenericApplicationMessageHandler.h"
#include "HAL/Runnable.h"

enum EJoyConState {
	Not_Attached,
	Dropped,
	No_JoyCons,
	Attached,
	Input_Mode_0_X30,
	Imu_Data_OK,
};

struct FReport {
	uint8* ReportData;
	FDateTime Time;

	FReport() {
		ReportData = nullptr;
	}

	FReport(uint8_t* TempReportData, const FDateTime TempTime) {
		ReportData = TempReportData;
		Time = TempTime;
	}

	FDateTime GetTime() const {
		return Time;
	}

	void CopyBuffer(uint8* DestinationArray) const {
		// Replace for with memcpy and report length(49)
		memcpy(DestinationArray, ReportData, 49);
		/*for (auto i = 0; i < 49; ++i) {
			DestinationArray[i] = ReportData[i];
		}*/
	}
};

struct FRumble {
	float HighFrequency;
	float LowFrequency;
	float Amplitude;
	float Time;
	bool TimedRumble;
	uint8 RumbleData[8];

	FRumble(): HighFrequency(0), LowFrequency(0), Amplitude(0), Time(0), TimedRumble(false), RumbleData{} {
	}

	FRumble(const float LowFrequencyTemp, const float HighFrequencyTemp, const float AmplitudeTemp, const int TimeTemp): RumbleData{} {
		HighFrequency = HighFrequencyTemp;
		LowFrequency = LowFrequencyTemp;
		Amplitude = AmplitudeTemp;
		TimedRumble = false;
		Time = 0;
		if (TimeTemp != 0) {
			Time = TimeTemp / 1000.0f;
			TimedRumble = true;
		}
	}

	void SetValues(const float LowFrequencyTemp, const float HighFrequencyTemp, const float AmplitudeTemp, const int TimeTemp) {
		HighFrequency = HighFrequencyTemp;
		LowFrequency = LowFrequencyTemp;
		Amplitude = AmplitudeTemp;
		TimedRumble = false;
		Time = 0;
		if (TimeTemp != 0) {
			Time = TimeTemp / 1000.0f;
			TimedRumble = true;
		}
	}
	
	static float Clamp(const float X, const float Min, const float Max) {
		if (X < Min) return Min;
		if (X > Max) return Max;
		return X;
	}

	void CalculateRumbleData() {
		//uint8 *RumbleData = static_cast<uint8*>(calloc(8, sizeof(uint8)));
		if (Amplitude == 0.0f) {
			RumbleData[0] = 0x0;
			RumbleData[1] = 0x1;
			RumbleData[2] = 0x40;
			RumbleData[3] = 0x40;
		} else {
			LowFrequency = Clamp(LowFrequency, 40.875885f, 626.286133f);
			Amplitude = Clamp(Amplitude, 0.0f, 1.0f);
			HighFrequency = Clamp(HighFrequency, 81.75177f, 1252.572266f);
			
			const uint16 HighFrequencyLocal = static_cast<uint16>((FMath::RoundToInt(32.0f * FMath::LogX(2, HighFrequency * 0.1f)) - 0x60) * 4);
			const uint8 LowFrequencyLocal = static_cast<uint8>(FMath::RoundToInt(32.0f * FMath::LogX(2, LowFrequency * 0.1f)) - 0x40);
			
			uint8 HighFrequencyAmplitude;
			if (Amplitude == 0) HighFrequencyAmplitude = 0;
			else if (Amplitude < 0.117) HighFrequencyAmplitude = static_cast<uint8>(((FMath::LogX(2, Amplitude * 1000) * 32) - 0x60) / (5 - FMath::Pow(Amplitude, 2)) - 1);
			else if (Amplitude < 0.23) HighFrequencyAmplitude = static_cast<uint8>(((FMath::LogX(2, Amplitude * 1000) * 32) - 0x60) - 0x5c);
			else HighFrequencyAmplitude = static_cast<uint8>((((FMath::LogX(2, Amplitude * 1000) * 32) - 0x60) * 2) - 0xf6);

			uint16 LowFrequencyAmplitude = static_cast<uint16>(FMath::RoundToInt(HighFrequencyAmplitude) * .5);
			const uint8 Parity = static_cast<uint8>(LowFrequencyAmplitude % 2);
			if (Parity > 0) {
				--LowFrequencyAmplitude;
			}

			LowFrequencyAmplitude = static_cast<uint16>(LowFrequencyAmplitude >> 1);
			LowFrequencyAmplitude += 0x40;
			if (Parity > 0) LowFrequencyAmplitude |= 0x8000;
			RumbleData[0] = static_cast<uint8>(HighFrequencyLocal & 0xff);
			RumbleData[1] = static_cast<uint8>((HighFrequencyLocal >> 8) & 0xff);
			RumbleData[2] = LowFrequencyLocal;
			RumbleData[3] = 0;
			
			RumbleData[1] += HighFrequencyLocal;
			RumbleData[2] += static_cast<uint8>((LowFrequencyAmplitude >> 8) & 0xff);
			RumbleData[3] += static_cast<uint8>(LowFrequencyAmplitude & 0xff);
		}
		for (int i = 0; i < 4; ++i) {
			RumbleData[4 + i] = RumbleData[i];
		}
		//return RumbleData;
	}
};

class FJoyConController : public FRunnable {

public:
	FJoyConController(FJoyConInformation TempJoyConInformation, hid_device* Device, const bool UseImu, const bool UseLocalize, float Alpha, const bool IsLeft);
	~FJoyConController();

	void Attach(uint8 Leds);
	void Update();
	void Pool();
	void Detach();

	FVector2D GetStick();
	FVector GetGyroscope() const;
	FVector GetAccelerometer() const;
	FRotator GetVector() const;
	void ReCenter();
	void SetRumble(float LowFrequency, float HighFrequency, float Amplitude, int Time = 0);

	void SetFilterCoefficient(float Coefficient);

	bool StartListenThread();

private:
	void DumpCalibrationData();
	void SendRumbleData();
	int32 ReceiveRaw();
	void ExtractImuValues(uint8 ReportBuf[], int32 N);
	int32 ProcessImu(uint8 ReportBuf[]);
	int32 ProcessButtonsAndStick(uint8 ReportBuf[]);
	void CenterSticks(uint16 Values[]);

	uint8* SendSubCommand(uint8 Sc, uint8 TempBuf[], uint8 Len);
	uint8* ReadSpi(uint8 Address1, uint8 Address2, uint32_t Len);

	static void ArrayCopy(uint8* SourceArray, int SourceIndex, uint8* DestinationArray, int DestinationIndex, int Length);
	static void ArrayCopy(const uint8* SourceArray, int SourceIndex, uint8* DestinationArray, int DestinationIndex, int Length);

private:
	hid_device* HidHandle;
	EJoyConState State;

	bool bStopPolling;
	bool bImuEnabled;
	bool bIsLeft;
	bool bDoLocalize;

	uint8 GlobalCount;
	uint32 ReadAttempts = 0;

	const uint32 ReportLen = 49;
	const uint8 DefaultBuf[8] = { 0x0, 0x1, 0x40, 0x40, 0x0, 0x1, 0x40, 0x40 };

	// Analog Stick Variables
	float Stick[2] = { 0, 0 };
	float StickMax[2] = { 0, 0 };
	uint8 StickRaw[3] = { 0, 0, 0 };
	uint16 StickCalibration[6] = { 0, 0, 0, 0, 0, 0 };
	uint16 DeadZone;
	uint16 StickPreCalibration[2] = { 0, 0 };

	// Accelerometer and Gyroscope Variables
	int16 GyrNeutral[3] = { 0, 0, 0 };
	int16 GyrR[3] = { 0, 0, 0 };
	int16 AccR[3] = { 0, 0, 0 };
	FVector AccG;
	FVector GyrG;

	float Max[3] = { 0, 0, 0 };
	float Sum[3] = { 0, 0, 0 };
	int Timestamp;
	TQueue<FReport> Reports;
	uint8 TsDequeue;
	uint8 TsEnqueue;
	FDateTime TsPrevious;
	float FilterWeight;
	float Err;
	bool FirstImuPacket = true;
	FVector I_B;
	FVector J_B;
	FVector K_B;
	FVector K_Acc;
	FVector Wa;
	FVector Wg;
	FVector DTheta;
	FVector IB2;
	FRumble RumbleObj;

	FRunnableThread* Thread;
	FCriticalSection Mutex;

public:
	FJoyConInformation JoyConInformation;
	FJoyConControllerState ControllerState;

	// Buttons
	bool Buttons[static_cast<int32>(EJoyConControllerButton::TotalButtonCount)];

	// FRunnable interface overrides
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;

};