// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConController.h"
#include "Engine/Engine.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <map>
#include "Windows/HideWindowsPlatformTypes.h"

FJoyConController::FJoyConController(hid_device* Device, const bool UseImu, const bool UseLocalize, float Alpha, const bool IsLeft) {
	HidHandle = Device;
	bIsLeft = IsLeft;
	bImuEnabled = UseImu;
	bDoLocalize = UseLocalize;
	bStopPolling = true;
	State = EJoyConState::Not_Attached;
}

FJoyConController::~FJoyConController() {
	if(HidHandle != nullptr) {
		hid_close(HidHandle);
	}
}

void FJoyConController::Attach(uint8 Leds) {
	State = EJoyConState::Attached;
	uint8 a[] = { 0x0 };
	// Input report mode
	SendCommand(0x3, new uint8[1]{ 0x3f }, 1);
	a[0] = 0x1;
	DumpCalibrationData();
	// Connect
	a[0] = 0x01;
	SendCommand(0x1, a, 1);
	a[0] = 0x02;
	SendCommand(0x1, a, 1);
	a[0] = 0x03;
	SendCommand(0x1, a, 1);
	a[0] = Leds;
	SendCommand(0x30, a, 1);
	if (bImuEnabled) {
		SendCommand(0x40, new uint8[1]{ 0x1 }, 1);
	}
	else {
		SendCommand(0x40, new uint8[1]{ 0x0 }, 1);
	}
	SendCommand(0x3, new uint8[1]{ 0x30 }, 1);
	SendCommand(0x48, new uint8[1]{ 0x1 }, 1);
	bStopPolling = false;
}

void FJoyConController::Update() {
	if (bStopPolling || State <= EJoyConState::No_JoyCons) return;
	auto ReportBuf = new uint8[ReportLen];
	while (!Reports.IsEmpty()) {
		FReport rep;
		//M_Mutex.Lock();
		Reports.Dequeue(rep);
		rep.CopyBuffer(ReportBuf);
		//M_Mutex.Unlock();
		if (bImuEnabled) {
			if (bDoLocalize) {
				ProcessImu(ReportBuf);
			}
			else {
				ExtractImuValues(ReportBuf, 0);
			}
		}
		if (TsDequeue == ReportBuf[1]) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString("Duplicate timestamp dequeued."));
		}
		TsDequeue = ReportBuf[1];
		TsPrevious = rep.GetTime();
		/*ProcessButtonsAndStick(reportBuf);
		if (!_rumbleObj.timedRumble) return;
		if (_rumbleObj.time < 0) {
			_rumbleObj.SetVals(160, 320, 0, 0);
		} else {
			_rumbleObj.time -= Time.deltaTime;
		}*/
	}
}

void FJoyConController::Pool() {
	if (!bStopPolling && State > EJoyConState::No_JoyCons) {
		//SendRumble(_rumbleObj.GetData());
		auto a = ReceiveRaw();
		a = ReceiveRaw();
		if (a > 0) {
			State = EJoyConState::Imu_Data_OK;
			ReadAttempts = 0;
		} else if (ReadAttempts > 1000) {
			State = EJoyConState::Dropped;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString("Connection lost. Is the Joy-Con connected?"));
			return;
		}
		/* else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString("Pause 5ms"));
			FPlatformProcess::Sleep(0.05);
		}*/
		ReadAttempts++;
	}
}

void FJoyConController::Detach() {
	bStopPolling = true;
	if (State > EJoyConState::No_JoyCons) {
		SendCommand(0x30, new uint8[1]{ 0x0 }, 1);
		SendCommand(0x40, new uint8[1]{ 0x0 }, 1);
		SendCommand(0x48, new uint8[1]{ 0x0 }, 1);
		SendCommand(0x3, new uint8[1]{ 0x3f }, 1);
	}
	/*if (State > EJoyConState::Dropped) {
		if (HidHandle != nullptr) hid_close(HidHandle);
	}*/
	State = EJoyConState::Not_Attached;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString("JoyCon detached!"));
}

void FJoyConController::DumpCalibrationData() {
	auto Buf = ReadSpi(0x80, (bIsLeft ? static_cast<uint8>(0x12) : static_cast<uint8>(0x1d)), 9);
	auto Found = false;
	for (auto i = 0; i < 9; ++i) {
		if (Buf[i] == 0xff) continue;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString("Using user stick calibration data."));
		Found = true;
		break;
	}
	if (!Found) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString("Using factory stick calibration data."));
		Buf = ReadSpi(0x60, (bIsLeft ? static_cast<uint8>(0x3d) : static_cast<uint8>(0x46)), 9);
	}
	StickCal[bIsLeft ? 0 : 2] = static_cast<uint16>((Buf[1] << 8) & 0xF00 | Buf[0]); // X Axis Max above center
	StickCal[bIsLeft ? 1 : 3] = static_cast<uint16>((Buf[2] << 4) | (Buf[1] >> 4));  // Y Axis Max above center
	StickCal[bIsLeft ? 2 : 4] = static_cast<uint16>((Buf[4] << 8) & 0xF00 | Buf[3]); // X Axis Center
	StickCal[bIsLeft ? 3 : 5] = static_cast<uint16>((Buf[5] << 4) | (Buf[4] >> 4));  // Y Axis Center
	StickCal[bIsLeft ? 4 : 0] = static_cast<uint16>((Buf[7] << 8) & 0xF00 | Buf[6]); // X Axis Min below center
	StickCal[bIsLeft ? 5 : 1] = static_cast<uint16>((Buf[8] << 4) | (Buf[7] >> 4));  // Y Axis Min below center

	Buf = ReadSpi(0x60, (bIsLeft ? static_cast<uint8>(0x86) : static_cast<uint8>(0x98)), 16);
	DeadZone = static_cast<uint16>((Buf[4] << 8) & 0xF00 | Buf[3]);

	Buf = ReadSpi(0x80, 0x34, 10);
	GyrNeutral[0] = static_cast<uint16>(Buf[0] | ((Buf[1] << 8) & 0xff00));
	GyrNeutral[1] = static_cast<uint16>(Buf[2] | ((Buf[3] << 8) & 0xff00));
	GyrNeutral[2] = static_cast<uint16>(Buf[4] | ((Buf[5] << 8) & 0xff00));

	// This is an extremely messy way of checking to see whether there is user stick calibration data present, but I've seen conflicting user calibration data on blank Joy-Cons. Worth another look eventually.
	if (GyrNeutral[0] + GyrNeutral[1] + GyrNeutral[2] != -3 && FGenericPlatformMath::Abs(GyrNeutral[0]) <= 100 && FGenericPlatformMath::Abs(GyrNeutral[1]) <= 100 && FGenericPlatformMath::Abs(GyrNeutral[2]) <= 100) return;
	Buf = ReadSpi(0x60, 0x29, 10);
	GyrNeutral[0] = static_cast<uint16>(Buf[3] | ((Buf[4] << 8) & 0xff00));
	GyrNeutral[1] = static_cast<uint16>(Buf[5] | ((Buf[6] << 8) & 0xff00));
	GyrNeutral[2] = static_cast<uint16>(Buf[7] | ((Buf[8] << 8) & 0xff00));
}

int FJoyConController::ReceiveRaw() {
	if (HidHandle == nullptr) return -2;
	hid_set_nonblocking(HidHandle, 0);
	const auto RawBuf = new uint8[ReportLen];
	if (bStopPolling) return 0;
	const auto Ret = hid_read(HidHandle, RawBuf, ReportLen);
	if (Ret <= 0) return Ret;
	//M_Mutex.Lock();
	//Reports.Enqueue(*new FReport(RawBuf, FDateTime::Now()));
	FReport Report;
	Report.ReportData = RawBuf;
	Report.Time = FDateTime::Now();
	Reports.Enqueue(Report);
	//M_Mutex.Unlock();
	if (TsEnqueue == RawBuf[1]) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString("Duplicate timestamp enqueued."));
	}
	TsEnqueue = RawBuf[1];
	return Ret;
}

void FJoyConController::ExtractImuValues(uint8 ReportBuf[], int32 N) {
	GyrR[0] = static_cast<int16_t>(ReportBuf[19 + N * 12] | ((ReportBuf[20 + N * 12] << 8) & 0xff00));
	GyrR[1] = static_cast<int16_t>(ReportBuf[21 + N * 12] | ((ReportBuf[22 + N * 12] << 8) & 0xff00));
	GyrR[2] = static_cast<int16_t>(ReportBuf[23 + N * 12] | ((ReportBuf[24 + N * 12] << 8) & 0xff00));
	AccR[0] = static_cast<int16_t>(ReportBuf[13 + N * 12] | ((ReportBuf[14 + N * 12] << 8) & 0xff00));
	AccR[1] = static_cast<int16_t>(ReportBuf[15 + N * 12] | ((ReportBuf[16 + N * 12] << 8) & 0xff00));
	AccR[2] = static_cast<int16_t>(ReportBuf[17 + N * 12] | ((ReportBuf[18 + N * 12] << 8) & 0xff00));
	for (auto i = 0; i < 3; ++i) {
		AccG[i] = AccR[i] * 0.00025f;
		GyrG[i] = (GyrR[i] - GyrNeutral[i]) * 0.00122187695f;
		if (FGenericPlatformMath::Abs(AccG[i]) > FGenericPlatformMath::Abs(Max[i])) Max[i] = AccG[i];
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Update Gyroscope: %d %d %d"), GyrR[0], GyrR[1], GyrR[2]));
}

int32 FJoyConController::ProcessImu(uint8 ReportBuf[]) {
	if (!bImuEnabled || State < EJoyConState::Imu_Data_OK) return -1;
	if (ReportBuf[0] != 0x30) return -1; // no gyro data
	// read raw IMU values
	auto DT = (ReportBuf[1] - Timestamp);
	if (ReportBuf[1] < Timestamp) DT += 0x100;
	for (auto n = 0; n < 3; ++n) {
		ExtractImuValues(ReportBuf, n);
		const auto DT_Sec = 0.005f * DT;
		Sum[0] += GyrG.X * DT_Sec;
		Sum[1] += GyrG.Y * DT_Sec;
		Sum[2] += GyrG.Z * DT_Sec;
		if (bIsLeft) {
			GyrG.Y *= -1;
			GyrG.Z *= -1;
			GyrG.Y *= -1;
			GyrG.Z *= -1;
		}
		if (FirstImuPacket) {
			I_B = new FVector(1, 0, 0);
			J_B = new FVector(0, 1, 0);
			K_B = new FVector(0, 0, 1);
			FirstImuPacket = false;
		}
		else {
			/*k_acc = -Vector3.Normalize(_accG);
			_wA = Vector3.Cross(k_b, k_acc);
			_wG = -_gyrG * dt_sec;
			_dTheta = (_filterweight * _wA + _wG) / (1f + _filterweight);
			k_b += Vector3.Cross(_dTheta, k_b);
			i_b += Vector3.Cross(_dTheta, i_b);
			j_b += Vector3.Cross(_dTheta, j_b);
			//Correction, ensure new axes are orthogonal
			_err = Vector3.Dot(i_b, j_b) * 0.5f;
			_iB = Vector3.Normalize(i_b - _err * j_b);
			j_b = Vector3.Normalize(j_b - _err * i_b);
			i_b = _iB;
			k_b = Vector3.Cross(i_b, j_b);*/
		}
		DT = 1;
	}
	Timestamp = ReportBuf[1] + 2;
	return 0;
}

uint8* FJoyConController::SendCommand(const uint8 Sc, uint8 TempBuf[], const uint8 Len) {
	const auto Buf = new uint8[ReportLen];
	const auto Response = new uint8[ReportLen];
	ArrayCopy(DefaultBuf, 0, Buf, 2, 8);
	ArrayCopy(TempBuf, 0, Buf, 11, Len);
	Buf[10] = Sc;
	Buf[1] = GlobalCount;
	Buf[0] = 0x1;
	if (GlobalCount == 0xf) GlobalCount = 0;
	else ++GlobalCount;
	hid_write(HidHandle, Buf, Len + 11);
	int Result = hid_read_timeout(HidHandle, Response, ReportLen, 50);
	return Response;
}

uint8* FJoyConController::ReadSpi(const uint8 Address1, const uint8 Address2, const uint32_t Len) {
	uint8 TBuf[5] = { Address2, Address1, 0x00, 0x00, static_cast<uint8>(Len) };
	const auto ReadBuf = new uint8[Len];
	auto Buf = new uint8[Len + 20];

	for (auto i = 0; i < 100; ++i) {
		Buf = SendCommand(0x10, TBuf, 5);
		if (Buf[15] == Address2 && Buf[16] == Address1) {
			break;
		}
	}
	ArrayCopy(Buf, 20, ReadBuf, 0, Len);
	return ReadBuf;
}

void FJoyConController::ArrayCopy(uint8* SourceArray, const int SourceIndex, uint8* DestinationArray, const int DestinationIndex, const int Length) {
	std::copy(SourceArray + SourceIndex, SourceArray + SourceIndex + Length, DestinationArray + DestinationIndex);
}

void FJoyConController::ArrayCopy(const uint8* SourceArray, const int SourceIndex, uint8* DestinationArray, const int DestinationIndex, const int Length) {
	std::copy(SourceArray + SourceIndex, SourceArray + SourceIndex + Length, DestinationArray + DestinationIndex);
}
