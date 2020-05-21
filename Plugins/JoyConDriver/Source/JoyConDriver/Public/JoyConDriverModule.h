// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IJoyConDriverModule.h"
#include "JoyConInput.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

class FJoyConDriverModule : public IJoyConDriverModule {
	
public:
	TWeakPtr< FJoyConInput > JoyConInputDevice;

	// IInputDeviceModule overrides
	virtual void StartupModule() override;
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;

	// IJoyConDriverModule overrides
	virtual uint32 GetNumberOfControllers() const override;
	virtual bool ConnectJoyCons() const override;
	virtual bool DisconnectJoyCons() const override;
};

#undef LOCTEXT_NAMESPACE