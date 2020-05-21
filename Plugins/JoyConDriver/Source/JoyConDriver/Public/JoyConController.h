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
	FJoyConController(hid_device* Device, const bool UseImu, const bool UseLocalize, float Alpha, const bool IsLeft);
	~FJoyConController();

	void Attach(uint8 Leds);
	void Update();
	void Pool();
	void Detach();

private:
	void DumpCalibrationData();
	int32 ReceiveRaw();
	void ExtractImuValues(uint8 ReportBuf[], int32 N);
	int32 ProcessImu(uint8 ReportBuf[]);

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
	uint16 DeadZone;
	uint32 ReadAttempts = 0;

	const uint32 ReportLen = 49;
	const uint8 DefaultBuf[8] = { 0x0, 0x1, 0x40, 0x40, 0x0, 0x1, 0x40, 0x40 };

	uint16 StickCal[6] = { 0, 0, 0, 0, 0, 0 };
	int16_t GyrNeutral[3] = { 0, 0, 0 };
	int16_t GyrR[3] = { 0, 0, 0 };
	int16_t AccR[3] = { 0, 0, 0 };

	float Max[3] = { 0, 0, 0 };
	float Sum[3] = { 0, 0, 0 };
	int Timestamp;
	FVector AccG;
	FVector GyrG;
	TQueue<FReport> Reports;
	FCriticalSection M_Mutex;
	uint8 TsDequeue;
	uint8 TsEnqueue;
	FDateTime TsPrevious;
	float FilterWeight;
	bool FirstImuPacket = true;
	FVector* I_B;
	FVector* J_B;
	FVector* K_B;
	FVector* K_Acc;
	FVector* Wa;
	FVector* Wg;
};