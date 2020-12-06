// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "JoyConDriverModule.h"

#include "GenericPlatform/IInputInterface.h"
#include "XRMotionControllerBase.h"
#include "IHapticDevice.h"
#include "JoyConController.h"
#include "JoyConGrip.h"
#include "JoyConInformation.h"

DEFINE_LOG_CATEGORY_STATIC(LogJoyConDriver, Log, All);

class FJoyConInput : public IInputDevice, public FXRMotionControllerBase, public IHapticDevice {
public:
	/** Constructor that takes an initial message handler that will receive motion controller events */
	FJoyConInput(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);

	/** Clean everything up */
	virtual ~FJoyConInput();

	static void PreInit();

	/** Loads any settings from the config folder that we need */
	static void LoadConfig();

	/** Commands */
	TArray<FJoyConInformation>* SearchJoyCons();

	TArray<FJoyConInformation>* GetConnectedJoyCons();

	TArray<FJoyConInformation>* GetAttachedJoyCons();

	bool ResumeJoyConConnection();

	bool ConnectJoyCon(FJoyConInformation JoyConInformation, bool UseImu, bool UseLocalize, float Alpha, int& ControllerId);

	bool AttachJoyCon(int ControllerId, int GripIndex);

	bool DisconnectJoyCon(int ControllerId);

	bool DetachJoyCon(int ControllerId);

	bool GetJoyConAccelerometer(int ControllerId, FVector& Out);

	bool GetJoyConGyroscope(int ControllerId, FVector& Out);

	bool GetJoyConVector(int ControllerId, FRotator& Out);

	bool ReCenterJoyCon(int ControllerId);
	
	bool SetJoyConFilterCoefficient(int ControllerId, float Coefficient);

	bool SetJoyConGripMode(int GripIndex, EGripMode GripMode);

	bool SetJoyConRumble(int ControllerId, float LowFrequency, float HighFrequency, float Amplitude, int Time);

	// IInputDevice overrides
	virtual void Tick(float DeltaTime) override;
	virtual void SendControllerEvents() override;
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues& Values) override;

	// IMotionController overrides
	virtual FName GetMotionControllerDeviceTypeName() const override;
	virtual bool GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const override;
	virtual ETrackingStatus GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const override;

	// IHapticDevice overrides
	IHapticDevice* GetHapticDevice() override { return static_cast<IHapticDevice*>(this); }
	virtual void SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values) override;

	virtual void GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const override;
	virtual float GetHapticAmplitudeScale() const override;

private:
	int GetNextControllerId() const;
	static FName GetRightJoyConKeyName(int Index, FName OriginalKeyName);
	void SendButtonEvents(bool bButtonPressed, float CurrentTime, int GripIndex, FName KeyName, FJoyConButtonState *ButtonState) const;
	void SendAnalogEvents(bool bIsLeft, int GripIndex, FVector2D StickVector, FJoyConAnalogState* AnalogState) const;
	
private:
	/** The recipient of motion controller input events */
	TSharedPtr< FGenericApplicationMessageHandler > MessageHandler;

	/** Repeat key delays, loaded from config */
	static float InitialButtonRepeatDelay;
	static float ButtonRepeatDelay;
	
	bool HidInitialized;
	TArray<FJoyConController*> Controllers;
    TMap<int, FJoyConController*> ControllersMap;
	FJoyConGrip Grips[8];
};