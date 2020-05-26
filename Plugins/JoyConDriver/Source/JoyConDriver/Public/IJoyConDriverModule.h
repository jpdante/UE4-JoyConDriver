// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"
#include "JoyConInformation.h"


/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules
 * within this plugin.
 */
class IJoyConDriverModule : public IInputDeviceModule {

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IJoyConDriverModule& Get() {
		return FModuleManager::LoadModuleChecked< IJoyConDriverModule >("JoyConDriver");
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("JoyConDriver");
	}

	/**
	 * Gets the number of Touch controllers that are active, so that games that require them can check to make sure they're present
	 *
	 * @return The number of Touch controllers that are active (but not necessarily tracked)
	 */
	virtual TArray<FJoyConInformation>* SearchForJoyCons() const = 0;
	virtual bool AttachJoyCon(FJoyConInformation JoyConInformation) const = 0;
	virtual bool DetachJoyCon(FJoyConInformation JoyConInformation) const = 0;
	virtual bool GetJoyConAccelerometer(FJoyConInformation JoyConInformation, FVector& Out) const = 0;
	virtual bool GetJoyConGyroscope(FJoyConInformation JoyConInformation, FVector& Out) const = 0;
	virtual bool GetJoyConVector(FJoyConInformation JoyConInformation, FRotator& Out) const = 0;
};
