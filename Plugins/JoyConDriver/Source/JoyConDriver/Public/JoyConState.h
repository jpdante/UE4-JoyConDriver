// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IJoyConDriverModule.h"
#include "IMotionController.h"
#include "InputCoreTypes.h"
#include "GenericPlatform/GenericApplicationMessageHandler.h"

//-------------------------------------------------------------------------------------------------
// Button names
//-------------------------------------------------------------------------------------------------

enum EJoyConControllerButton : int {
	DPad_Up,
	DPad_Left,
	DPad_Right,
	DPad_Down,

	Minus,
	Plus,
	Home,
	Capture,

	Left_ThumbStick,

	Sr,
	Sl,

	L,
	Zl,

	/** Total number of controller buttons */
	TotalButtonCount,

	/** Extra buttons for game pad mode */
	X,
	Y,
	A,
	B,
	
	Right_ThumbStick,

	R,
	Zr,

	/** Extra thumb stick keys */
	Left_ThumbStick_X,
	Left_ThumbStick_Y,
    Right_ThumbStick_X,
    Right_ThumbStick_Y
};

//-------------------------------------------------------------------------------------------------
// FJoyConKey
//-------------------------------------------------------------------------------------------------

struct FJoyConKey {
	static const FKey JoyCon_DPad_Up;
	static const FKey JoyCon_DPad_Left;
	static const FKey JoyCon_DPad_Right;
	static const FKey JoyCon_DPad_Down;

	static const FKey JoyCon_Minus;
	static const FKey JoyCon_Plus;
	static const FKey JoyCon_Home;
	static const FKey JoyCon_Capture;

	static const FKey JoyCon_Left_ThumbStick;

	static const FKey JoyCon_Sr;
	static const FKey JoyCon_Sl;

	static const FKey JoyCon_L;
	static const FKey JoyCon_Zl;

	/** Extra buttons for game pad mode */
	static const FKey JoyCon_X;
	static const FKey JoyCon_Y;
	static const FKey JoyCon_A;
	static const FKey JoyCon_B;

	static const FKey JoyCon_Right_ThumbStick;

	static const FKey JoyCon_R;
	static const FKey JoyCon_Zr;

	/** Extra thumb stick keys */
	static const FKey JoyCon_Left_ThumbStick_X;
	static const FKey JoyCon_Left_ThumbStick_Y;
	static const FKey JoyCon_Right_ThumbStick_X;
	static const FKey JoyCon_Right_ThumbStick_Y;
};

//-------------------------------------------------------------------------------------------------
// FJoyConKeyNames
//-------------------------------------------------------------------------------------------------

struct FJoyConKeyNames {
	typedef FName Type;
	
	static const FName JoyCon_DPad_Up;
	static const FName JoyCon_DPad_Left;
	static const FName JoyCon_DPad_Right;
	static const FName JoyCon_DPad_Down;

	static const FName JoyCon_Minus;
	static const FName JoyCon_Plus;
	static const FName JoyCon_Home;
	static const FName JoyCon_Capture;

	static const FName JoyCon_Left_ThumbStick;

	static const FName JoyCon_Sr;
	static const FName JoyCon_Sl;

	static const FName JoyCon_L;
	static const FName JoyCon_Zl;

	/** Extra buttons for game pad mode */
	static const FName JoyCon_X;
	static const FName JoyCon_Y;
	static const FName JoyCon_A;
	static const FName JoyCon_B;

	static const FName JoyCon_Right_ThumbStick;

	static const FName JoyCon_R;
	static const FName JoyCon_Zr;

	/** Extra thumb stick keys */
	static const FName JoyCon_Left_ThumbStick_X;
	static const FName JoyCon_Left_ThumbStick_Y;
	static const FName JoyCon_Right_ThumbStick_X;
	static const FName JoyCon_Right_ThumbStick_Y;
};

//-------------------------------------------------------------------------------------------------
// FJoyConButtonState -  Digital button state
//-------------------------------------------------------------------------------------------------

struct FJoyConButtonState {
	/** The Unreal button this maps to. */
	FName Key;

	/** Whether we're pressed or not.  While pressed, we will generate repeat presses on a timer */
	bool bIsPressed;

	/** Next time a repeat event should be generated for each button */
	double NextRepeatTime;


	/** Default constructor that just sets sensible defaults */
	FJoyConButtonState() : Key(NAME_None), bIsPressed(false), NextRepeatTime(0.0) {}
};

//-------------------------------------------------------------------------------------------------
// FJoyConButtonState -  Analog stick state
//-------------------------------------------------------------------------------------------------

struct FJoyConAnalogState {
	float X;
	float Y;

	/** Default constructor that just sets sensible defaults */
	FJoyConAnalogState() : X(0.0), Y(0.0) {}
};

//-------------------------------------------------------------------------------------------------
// FJoyConControllerState
//-------------------------------------------------------------------------------------------------

struct FJoyConControllerState {
	/** Button states */
	FJoyConButtonState Buttons[static_cast<int32>(EJoyConControllerButton::TotalButtonCount)];
	/** Analog stick state */
	FJoyConAnalogState Stick;

	FJoyConControllerState() {
		for (FJoyConButtonState& Button : Buttons) {
			Button.bIsPressed = false;
			Button.NextRepeatTime = 0.0;
		}

		Stick.X = 0.0;
		Stick.Y = 0.0;

		Buttons[static_cast<int32>(EJoyConControllerButton::DPad_Up)].Key = FJoyConKeyNames::JoyCon_DPad_Up;
		Buttons[static_cast<int32>(EJoyConControllerButton::DPad_Down)].Key = FJoyConKeyNames::JoyCon_DPad_Down;
		Buttons[static_cast<int32>(EJoyConControllerButton::DPad_Left)].Key = FJoyConKeyNames::JoyCon_DPad_Left;
		Buttons[static_cast<int32>(EJoyConControllerButton::DPad_Right)].Key = FJoyConKeyNames::JoyCon_DPad_Right;
		
		Buttons[static_cast<int32>(EJoyConControllerButton::Minus)].Key = FJoyConKeyNames::JoyCon_Minus;
		Buttons[static_cast<int32>(EJoyConControllerButton::Plus)].Key = FJoyConKeyNames::JoyCon_Plus;
		Buttons[static_cast<int32>(EJoyConControllerButton::Home)].Key = FJoyConKeyNames::JoyCon_Home;
		Buttons[static_cast<int32>(EJoyConControllerButton::Capture)].Key = FJoyConKeyNames::JoyCon_Capture;

		Buttons[static_cast<int32>(EJoyConControllerButton::Left_ThumbStick)].Key = FJoyConKeyNames::JoyCon_Left_ThumbStick;

		Buttons[static_cast<int32>(EJoyConControllerButton::Sr)].Key = FJoyConKeyNames::JoyCon_Sr;
		Buttons[static_cast<int32>(EJoyConControllerButton::Sl)].Key = FJoyConKeyNames::JoyCon_Sl;

		Buttons[static_cast<int32>(EJoyConControllerButton::L)].Key = FJoyConKeyNames::JoyCon_L;
		Buttons[static_cast<int32>(EJoyConControllerButton::Zl)].Key = FJoyConKeyNames::JoyCon_Zl;
	}
};