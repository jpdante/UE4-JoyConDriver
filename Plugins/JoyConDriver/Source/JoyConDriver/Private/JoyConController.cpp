// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConController.h"
#include "Engine/Engine.h"
//#include "Windows/AllowWindowsPlatformTypes.h"
//#include <map>

#include "JoyConState.h"
#include "HAL/RunnableThread.h"
//#include "Windows/HideWindowsPlatformTypes.h"

FJoyConController::FJoyConController(const FJoyConInformation TempJoyConInformation, hid_device* Device, const bool UseImu, const bool UseLocalize, float Alpha, const bool IsLeft) :
	GlobalCount(0),
	DeadZone(0),
	Timestamp(0),
	TsDequeue(0),
	TsEnqueue(0),
	FilterWeight(0),
	Err(0),
	Thread(nullptr),
    Buttons{},
    RumbleObj(160, 320, 0, 0) {
	HidHandle = Device;
	JoyConInformation = TempJoyConInformation;
	bIsLeft = IsLeft;
	bImuEnabled = UseImu;
	bDoLocalize = UseLocalize;
	bStopPolling = true;
	State = EJoyConState::Not_Attached;
}

FJoyConController::~FJoyConController() {
	delete Thread;
	Thread = nullptr;
	if (HidHandle != nullptr) {
		hid_close(HidHandle);
	}
}

void FJoyConController::Attach(const uint8 Leds) {
	if (State > EJoyConState::No_JoyCons) return;
	State = EJoyConState::Attached;
	// Subcommand 0x03: Set input report mode
    // 0x3f - Simple HID mode. Pushes updates with every button press
	uint8 a[] = { 0x3f };
	SendSubCommand(0x3, a, 1);
	
	DumpCalibrationData();
	
	// Subcommand 0x01: Bluetooth manual pairing
	// Send host MAC and acquire Joy-Con MAC
	a[0] = 0x01;
	SendSubCommand(0x1, a, 1);
	
	// Acquire the XORed LTK hash
	a[0] = 0x02;
	SendSubCommand(0x1, a, 1);
	
	// Saves pairing info in Joy-Con
	a[0] = 0x03;
	SendSubCommand(0x1, a, 1);

	// Subcommand 0x30: Set player lights
	a[0] = Leds;
	SendSubCommand(0x30, a, 1);
	
	// Subcommand 0x40: Enable IMU (6-Axis sensor)
	a[0] = bImuEnabled ? 0x1 : 0x0;
	SendSubCommand(0x40, a, 1);
	
	// Subcommand 0x03: Set input report mode
    // 0x30 - Standard full mode. Pushes current state @60Hz
	SendSubCommand(0x3, new uint8[1]{ 0x30 }, 1);
	
	// Subcommand 0x48: Enable vibration
	SendSubCommand(0x48, new uint8[1]{ 0x1 }, 1);
}

void FJoyConController::Update() {
	if (bStopPolling || State <= EJoyConState::No_JoyCons) return;
	const auto ReportBuf = new uint8[ReportLen];
	ReportBuf[0] = 0x00;
	while (!Reports.IsEmpty()) {
		Mutex.Lock();
		FReport Rep;
		Reports.Dequeue(Rep);
		Rep.CopyBuffer(ReportBuf);
		Mutex.Unlock();
		if (bImuEnabled) {
			if (bDoLocalize) {
				ProcessImu(ReportBuf);
			} else {
				ExtractImuValues(ReportBuf, 0);
			}
		}
		if (TsDequeue == ReportBuf[1]) {
			UE_LOG(LogTemp, Display, TEXT("Duplicate timestamp dequeued."));
		}
		TsDequeue = ReportBuf[1];
		TsPrevious = Rep.GetTime();
	}
	ProcessButtonsAndStick(ReportBuf);
	if (!RumbleObj.TimedRumble) return;
	if (RumbleObj.Time < 0) {
		RumbleObj.SetValues(160, 320, 0, 0);
	} else {
		RumbleObj.Time -= FApp::GetDeltaTime();
	}
}

void FJoyConController::Pool() {
	while (!bStopPolling && State > EJoyConState::No_JoyCons) {
		SendRumbleData();
		int32 a = ReceiveRaw();
		a = ReceiveRaw();
		if (a > 0) {
			State = EJoyConState::Imu_Data_OK;
			ReadAttempts = 0;
		} else if (ReadAttempts > 1000) {
			State = EJoyConState::Dropped;
			return;
		} else {
			FPlatformProcess::Sleep(0.05);
		}
		ReadAttempts++;
	}
}

void FJoyConController::Detach() {
	bStopPolling = true;
	if (State > EJoyConState::No_JoyCons) {
		// Subcommand 0x30: Set player lights
		uint8 a[] = { 0x0 };
		SendSubCommand(0x30, a, 1);

		// Subcommand 0x40: Enable IMU (6-Axis sensor)
		a[0] = 0x0;
		SendSubCommand(0x40, a, 1);

		// Subcommand 0x48: Enable vibration
		a[0] = 0x0;
		SendSubCommand(0x48, a, 1);

		// Subcommand 0x03: Set input report mode
        // 0x3f - Simple HID mode. Pushes updates with every button press
		a[0] = 0x3f;
		SendSubCommand(0x3, a, 1);
	}
	State = EJoyConState::Not_Attached;
}

FVector2D FJoyConController::GetStick() {
	return FVector2D(Stick[0], Stick[1]);
}

FVector FJoyConController::GetGyroscope() const {
	return GyrG;
}

FVector FJoyConController::GetAccelerometer() const {
	return AccG;
}

FRotator FJoyConController::GetVector() const {
	FVector forward = FVector(J_B.X, I_B.X, K_B.X);
	FVector up = -FVector(J_B.Z, I_B.Z, K_B.Z);;

	forward = forward.GetSafeNormal();
	up = up - (forward * FVector::DotProduct(up, forward));
	up = up.GetSafeNormal();

	FVector vector = forward.GetSafeNormal();
	FVector vector2 = FVector::CrossProduct(up, vector);
	FVector vector3 = FVector::CrossProduct(vector, vector2);
	float m00 = vector.X;
	float m01 = vector.Y;
	float m02 = vector.Z;
	float m10 = vector2.X;
	float m11 = vector2.Y;
	float m12 = vector2.Z;
	float m20 = vector3.X;
	float m21 = vector3.Y;
	float m22 = vector3.Z;

	float num8 = (m00 + m11) + m22;
	FQuat quaternion = FQuat();

	if (num8 > 0.0f) {
		float num = (float)FMath::Sqrt(num8 + 1.0f);
		quaternion.W = num * 0.5f;
		num = 0.5f / num;
		quaternion.X = (m12 - m21) * num;
		quaternion.Y = (m20 - m02) * num;
		quaternion.Z = (m01 - m10) * num;
		return FRotator(quaternion);
	}

	if ((m00 >= m11) && (m00 >= m22)) {
		float num7 = (float)FMath::Sqrt(((1.0f + m00) - m11) - m22);
		float num4 = 0.5f / num7;
		quaternion.X = 0.5f * num7;
		quaternion.Y = (m01 + m10) * num4;
		quaternion.Z = (m02 + m20) * num4;
		quaternion.W = (m12 - m21) * num4;
		return FRotator(quaternion);
	}

	if (m11 > m22) {
		float num6 = (float)FMath::Sqrt(((1.0f + m11) - m00) - m22);
		float num3 = 0.5f / num6;
		quaternion.X = (m10 + m01) * num3;
		quaternion.Y = 0.5f * num6;
		quaternion.Z = (m21 + m12) * num3;
		quaternion.W = (m20 - m02) * num3;
		return FRotator(quaternion);
	}

	float num5 = (float)FMath::Sqrt(((1.0f + m22) - m00) - m11);
	float num2 = 0.5f / num5;
	quaternion.X = (m20 + m02) * num2;
	quaternion.Y = (m21 + m12) * num2;
	quaternion.Z = 0.5f * num5;
	quaternion.W = (m01 - m10) * num2;

	return FRotator(quaternion);
}

void FJoyConController::ReCenter() {
	FirstImuPacket = true;
}

void FJoyConController::SetRumble(const float LowFrequency, const float HighFrequency, const float Amplitude, const int Time) {
	if (State <= Attached) return;
	if (RumbleObj.TimedRumble == false || RumbleObj.Time < 0) {
		RumbleObj.SetValues(LowFrequency, HighFrequency, Amplitude, Time);
	}
}

void FJoyConController::SetFilterCoefficient(const float Coefficient) {
	FilterWeight = Coefficient;
}

bool FJoyConController::StartListenThread() {
	if (FPlatformProcess::SupportsMultithreading() && HidHandle != nullptr) {
		if(Thread != nullptr) {
			bStopPolling = true;
			Thread->Kill(true);
			delete Thread;
			Thread = nullptr;
		}
		bStopPolling = false;
		Thread = FRunnableThread::Create(this, TEXT("FJoyConInput"), 0, EThreadPriority::TPri_Normal);
		return true;
	} else {
		UE_LOG(LogTemp, Fatal, TEXT("Failed to start thread, the platform does not support multithreading or HidHandle null pointer exception."));
		return false;
	}
}

void FJoyConController::DumpCalibrationData() {
	auto Buf = ReadSpi(0x80, (bIsLeft ? static_cast<uint8>(0x12) : static_cast<uint8>(0x1d)), 9);
	auto Found = false;
	for (auto i = 0; i < 9; ++i) {
		if (Buf[i] == 0xff) continue;
		UE_LOG(LogTemp, Display, TEXT("Using user stick calibration data."));
		Found = true;
		break;
	}
	if (!Found) {
		UE_LOG(LogTemp, Display, TEXT("Using factory stick calibration data."));
		Buf = ReadSpi(0x60, (bIsLeft ? static_cast<uint8>(0x3d) : static_cast<uint8>(0x46)), 9);
	}
	StickCalibration[bIsLeft ? 0 : 2] = static_cast<uint16>((Buf[1] << 8) & 0xF00 | Buf[0]); // X Axis Max above center
	StickCalibration[bIsLeft ? 1 : 3] = static_cast<uint16>((Buf[2] << 4) | (Buf[1] >> 4));  // Y Axis Max above center
	StickCalibration[bIsLeft ? 2 : 4] = static_cast<uint16>((Buf[4] << 8) & 0xF00 | Buf[3]); // X Axis Center
	StickCalibration[bIsLeft ? 3 : 5] = static_cast<uint16>((Buf[5] << 4) | (Buf[4] >> 4));  // Y Axis Center
	StickCalibration[bIsLeft ? 4 : 0] = static_cast<uint16>((Buf[7] << 8) & 0xF00 | Buf[6]); // X Axis Min below center
	StickCalibration[bIsLeft ? 5 : 1] = static_cast<uint16>((Buf[8] << 4) | (Buf[7] >> 4));  // Y Axis Min below center

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

void FJoyConController::SendRumbleData() {
	RumbleObj.CalculateRumbleData();
	const auto Buf = new uint8[ReportLen];
	Buf[0] = 0x10;
	Buf[1] = GlobalCount;
	if (GlobalCount == 0xf) GlobalCount = 0;
	else ++GlobalCount;
	ArrayCopy(RumbleObj.RumbleData, 0, Buf, 2, 8);
	hid_write(HidHandle, Buf, ReportLen);
}


int FJoyConController::ReceiveRaw() {
	if (HidHandle == nullptr) return -2;
	hid_set_nonblocking(HidHandle, 0);
	const auto RawBuf = new uint8[ReportLen];
	if (bStopPolling) return 0;
	const auto Ret = hid_read(HidHandle, RawBuf, ReportLen);
	if (Ret <= 0) return Ret;
	Mutex.Lock();
	FReport Report;
	Report.ReportData = RawBuf;
	Report.Time = FDateTime::Now();
	Reports.Enqueue(Report);
	Mutex.Unlock();
	if (TsEnqueue == RawBuf[1]) {
		UE_LOG(LogTemp, Display, TEXT("Duplicate timestamp enqueued."));
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
			I_B.Set(1, 0, 0);
			J_B.Set(0, 1, 0);
			K_B.Set(0, 0, 1);
			FirstImuPacket = false;
		} else {
			K_Acc = -AccG.GetSafeNormal();
			Wa = FVector::CrossProduct(K_B, K_Acc);
			Wg = -GyrG * DT_Sec;
			DTheta = (FilterWeight * Wa + Wg) / (1.f + FilterWeight);
			K_B += FVector::CrossProduct(DTheta, K_B);
			I_B += FVector::CrossProduct(DTheta, I_B);
			J_B += FVector::CrossProduct(DTheta, J_B);
			//Correction, ensure new axes are orthogonal
			Err = FVector::DotProduct(I_B, J_B) * 0.5f;
			IB2 = (I_B - Err * J_B).GetSafeNormal();
			J_B = (J_B - Err * I_B).GetSafeNormal();
			I_B = IB2;
			K_B = FVector::CrossProduct(I_B, J_B);
		}
		DT = 1;
	}
	Timestamp = ReportBuf[1] + 2;
	return 0;
}

int32 FJoyConController::ProcessButtonsAndStick(uint8 ReportBuf[]) {
	if (ReportBuf[0] == 0x00) return -1;

	StickRaw[0] = ReportBuf[6 + (bIsLeft ? 0 : 3)];
	StickRaw[1] = ReportBuf[7 + (bIsLeft ? 0 : 3)];
	StickRaw[2] = ReportBuf[8 + (bIsLeft ? 0 : 3)];

	StickPreCalibration[0] = static_cast<uint16>(StickRaw[0] | ((StickRaw[1] & 0xf) << 8));
	StickPreCalibration[1] = static_cast<uint16>((StickRaw[1] >> 4) | (StickRaw[2] << 4));
	CenterSticks(StickPreCalibration);

	Buttons[EJoyConControllerButton::DPad_Up] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & (bIsLeft ? 0x02 : 0x02)) != 0;
	Buttons[EJoyConControllerButton::DPad_Left] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & (bIsLeft ? 0x08 : 0x01)) != 0;
	Buttons[EJoyConControllerButton::DPad_Right] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & (bIsLeft ? 0x04 : 0x08)) != 0;
	Buttons[EJoyConControllerButton::DPad_Down] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & (bIsLeft ? 0x01 : 0x04)) != 0;

	Buttons[EJoyConControllerButton::Minus] = (ReportBuf[4] & 0x01) != 0;
	Buttons[EJoyConControllerButton::Plus] = (ReportBuf[4] & 0x02) != 0;
	Buttons[EJoyConControllerButton::Home] = (ReportBuf[4] & 0x10) != 0;
	//Buttons[EButton::JoyCon_Capture].Update((ReportBuf[4] & 0x02) != 0);
	
    Buttons[EJoyConControllerButton::Left_ThumbStick] = (ReportBuf[4] & (bIsLeft ? 0x08 : 0x04)) != 0;
	
	Buttons[EJoyConControllerButton::Sr] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & 0x10) != 0;
	Buttons[EJoyConControllerButton::Sl] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & 0x20) != 0;

	Buttons[EJoyConControllerButton::L] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & 0x40) != 0;
	Buttons[EJoyConControllerButton::Zl] = (ReportBuf[3 + (bIsLeft ? 2 : 0)] & 0x80) != 0;

	return 0;
}

void FJoyConController::CenterSticks(uint16 Values[]) {
	for (uint32 i = 0; i < 2; ++i) {
		const float Diff = Values[i] - StickCalibration[2 + i];
		if (FGenericPlatformMath::Abs(Diff) < DeadZone) Stick[i] = 0;
		else if (Diff > 0) Stick[i] = Diff / StickCalibration[i];
		else Stick[i] = Diff / StickCalibration[4 + i];
	}
}

uint8* FJoyConController::SendSubCommand(const uint8 Sc, uint8 TempBuf[], const uint8 Len) {
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
		Buf = SendSubCommand(0x10, TBuf, 5);
		if (Buf[15] == Address2 && Buf[16] == Address1) {
			break;
		}
	}
	ArrayCopy(Buf, 20, ReadBuf, 0, Len);
	return ReadBuf;
}

void FJoyConController::ArrayCopy(uint8* SourceArray, const int SourceIndex, uint8* DestinationArray, const int DestinationIndex, const int Length) {
	memcpy(DestinationArray + DestinationIndex, SourceArray + SourceIndex, Length);
	//std::copy(SourceArray + SourceIndex, SourceArray + SourceIndex + Length, DestinationArray + DestinationIndex);
}

void FJoyConController::ArrayCopy(const uint8* SourceArray, const int SourceIndex, uint8* DestinationArray, const int DestinationIndex, const int Length) {
	memcpy(DestinationArray + DestinationIndex, SourceArray + SourceIndex, Length);
	//std::copy(SourceArray + SourceIndex, SourceArray + SourceIndex + Length, DestinationArray + DestinationIndex);
}

bool FJoyConController::Init() {
	return true;
}

uint32 FJoyConController::Run() {
	Pool();
	return 0;
}

void FJoyConController::Stop() {
	bStopPolling = true;
}