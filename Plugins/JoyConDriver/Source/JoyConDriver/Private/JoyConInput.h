// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "JoyConDriverModule.h"

#include "GenericPlatform/IInputInterface.h"
#include "XRMotionControllerBase.h"
#include "IHapticDevice.h"
#include "JoyConController.h"
#include "JoyConInformation.h"

DEFINE_LOG_CATEGORY_STATIC(LogJoyConDriver, Log, All);

namespace JoyConDriver {

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
		bool AttachJoyCon(FJoyConInformation JoyConInformation);
		bool DetachJoyCon(FJoyConInformation JoyConInformation);
		bool GetJoyConAccelerometer(FJoyConInformation JoyConInformation, FVector& Out);
		bool GetJoyConGyroscope(FJoyConInformation JoyConInformation, FVector& Out);
		bool GetJoyConVector(FJoyConInformation JoyConInformation, FRotator& Out);

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
		/** The recipient of motion controller input events */
		TSharedPtr< FGenericApplicationMessageHandler > MessageHandler;

		bool HidInitialized;
		TArray<FJoyConController*> Controllers;
	};

} // namespace JoyConDriver