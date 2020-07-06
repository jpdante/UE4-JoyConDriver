// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConGrip.h"

FJoyConGrip::FJoyConGrip() {
	GripIndex = 0;
	Mode = EGripMode::Auto;
}

bool FJoyConGrip::ContainsController(const FJoyConInformation JoyConInformation) {
	for (FJoyConController* Controller : Controllers) {
		if (Controller->JoyConInformation.SerialNumber.Equals(JoyConInformation.SerialNumber) && Controller->JoyConInformation.BluetoothPath.Equals(JoyConInformation.BluetoothPath)) {
			return true;
		}
	}
	return false;
}