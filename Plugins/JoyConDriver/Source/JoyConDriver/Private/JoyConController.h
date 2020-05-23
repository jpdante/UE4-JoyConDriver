// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "hidapi.h"
#include "Containers/Queue.h"


enum EJoyConState {
	Not_Attached,
	Dropped,
	No_JoyCons,
	Attached,
	Input_Mode_0_X30,
	Imu_Data_OK,
};

enum EButton : int {
	DPad_Down = 0,
	DPad_Right = 1,
	DPad_Left = 2,
	DPad_Up = 3,
	Sl = 4,
	Sr = 5,
	Minus = 6,
	Home = 7,
	Plus = 8,
	Capture = 9,
	Stick = 10,
	Shoulder_1 = 11,
	Shoulder_2 = 12
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
		for (auto i = 0; i < 49; ++i) {
			DestinationArray[i] = ReportData[i];
		}
	}
};

class FJoyConController {

public:
	FJoyConController(hid_device* Device, FString TempSerialNumber, FString TempBluetoothPath, const bool UseImu, const bool UseLocalize, float Alpha, const bool IsLeft);
	~FJoyConController();

	void Attach(uint8 Leds);
	void Update();
	void Pool();
	void Detach();

	bool GetButtonDown(EButton Button);
	bool GetButton(EButton Button);
	bool GetButtonUp(EButton Button);
	FVector2D GetStick();
	FVector GetGyroscope() const;
	FVector GetAccelerometer() const;
	FRotator GetVector() const;
	void ReCenter();
	
	void SetFilterCoefficient(float Coefficient);

private:
	void DumpCalibrationData();
	int32 ReceiveRaw();
	void ExtractImuValues(uint8 ReportBuf[], int32 N);
	int32 ProcessImu(uint8 ReportBuf[]);
	int32 ProcessButtonsAndStick(uint8 ReportBuf[]);
	void CenterSticks(uint16 Values[]);

	uint8* SendCommand(uint8 Sc, uint8 TempBuf[], uint8 Len);
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

	// Buttons
	bool ButtonsDown[13];
	bool ButtonsUp[13];
	bool Buttons[13];
	bool Down[13];

	// Analog Stick Variables
	float Stick[2] = { 0, 0 };
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

public:
	FString SerialNumber;
	FString BluetoothPath;
	
};