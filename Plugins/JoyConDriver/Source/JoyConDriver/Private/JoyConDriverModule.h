// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IJoyConDriverModule.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"

#define LOCTEXT_NAMESPACE "SwitchController"

class FJoyConDriverModule : public IJoyConDriverModule {
	
public:
	TWeakPtr<FJoyConDriverModule > JoyConInputDevice;
	
	FJoyConDriverModule();
	virtual ~FJoyConDriverModule();

	virtual void StartupModule() override;
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
	
};

#undef LOCTEXT_NAMESPACE