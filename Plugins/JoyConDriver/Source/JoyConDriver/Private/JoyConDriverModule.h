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
	virtual bool AttachJoyCon(FJoyConInformation JoyConInformation, int& ControllerIndex) const override;
	virtual bool DetachJoyCon(int ControllerIndex) const override;
	virtual bool GetJoyConAccelerometer(int ControllerIndex, FVector& Out) const override;
	virtual bool GetJoyConGyroscope(int ControllerIndex, FVector& Out) const override;
	virtual bool GetJoyConVector(int ControllerIndex, FRotator& Out) const override;
};

#undef LOCTEXT_NAMESPACE