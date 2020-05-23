// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IJoyConDriverModule.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

//-------------------------------------------------------------------------------------------------
// FJoyConDriverInputModule
//-------------------------------------------------------------------------------------------------

namespace JoyConDriver {
	class FJoyConInput;
}

class FJoyConDriverModule : public IJoyConDriverModule {
	
public:
	TWeakPtr<JoyConDriver::FJoyConInput> JoyConInputDevice;

	// IInputDeviceModule overrides
	virtual void StartupModule() override;
	virtual TSharedPtr< class IInputDevice > CreateInputDevice( const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler ) override;

	// IJoyConDriverModule overrides
	virtual TArray<FJoyConInformation>* SearchForJoyCons() const override;
};

#undef LOCTEXT_NAMESPACE