// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IJoyConDriverModule.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

//-------------------------------------------------------------------------------------------------
// FJoyConDriverInputModule
//-------------------------------------------------------------------------------------------------

class FJoyConInput;

class FJoyConDriverModule : public IJoyConDriverModule {

public:
	TWeakPtr<FJoyConInput> JoyConInputDevice;

	// IInputDeviceModule overrides
	virtual void StartupModule() override;
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;

	// IJoyConDriverModule overrides
	virtual TArray<FJoyConInformation>* SearchForJoyCons() const override;
	virtual TArray<FJoyConInformation>* GetAttachedJoyCons() const override;
	virtual TArray<FJoyConInformation>* GetConnectedJoyCons() const override;
	virtual bool ResumeJoyConConnection() const override;
	virtual bool ConnectJoyCon(FJoyConInformation JoyConInformation, bool UseImu, bool UseLocalize, float Alpha, int& ControllerId) const override;
	virtual bool AttachJoyCon(int ControllerId, int GripIndex) const override;
	virtual bool DisconnectJoyCon(int ControllerId) const override;
	virtual bool DetachJoyCon(int ControllerId) const override;
	virtual bool GetJoyConAccelerometer(int ControllerId, FVector& Out) const override;
	virtual bool GetJoyConGyroscope(int ControllerId, FVector& Out) const override;
	virtual bool GetJoyConVector(int ControllerId, FRotator& Out) const override;
	virtual bool ReCenterJoyCon(int ControllerId) const override;
	virtual bool SetJoyConFilterCoefficient(int ControllerId, float Coefficient) const override;
	virtual bool SetJoyConGripMode(int GripIndex, uint8 GripMode) const override;
	virtual bool SetJoyConRumble(int ControllerId, float LowFrequency, float HighFrequency, float Amplitude, int Time) const override;
};

#undef LOCTEXT_NAMESPACE