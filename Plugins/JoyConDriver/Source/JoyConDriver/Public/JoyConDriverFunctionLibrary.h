// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JoyConGrip.h"
#include "JoyConInformation.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JoyConDriverFunctionLibrary.generated.h"

	/**
	 *
	 */
UCLASS()
class JOYCONDRIVER_API UJoyConDriverFunctionLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Resume Connection"))
		static void ResumeJoyConConnection(bool& Success);
	
	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Connect"))
		static void ConnectJoyCon(FJoyConInformation JoyConInformation, bool UseImu, bool UseLocalize, bool& Success, int& ControllerIndex, float Alpha = 0.05f);
	
	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Attach"))
		static void AttachJoyCon(int ControllerId, int GripIndex, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Disconnect"))
		static void DisconnectJoyCon(int ControllerId, bool& Success);
	
	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Detach"))
		static void DetachJoyCon(int ControllerId, bool& Success);
	
	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Search"))
		static void SearchForJoyCons(TArray<FJoyConInformation>& JoyCons);

	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Get Attached"))
		static void GetAttachedJoyCons(TArray<FJoyConInformation>& JoyCons);

	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Get Attached"))
		static void GetConnectedJoyCons(TArray<FJoyConInformation>& JoyCons);

	UFUNCTION(BlueprintPure, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Accelerometer"))
		static void GetJoyConAccelerometer(int ControllerId, bool& Success, FVector& Accelerometer);

	UFUNCTION(BlueprintPure, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Gyroscope"))
		static void GetJoyConGyroscope(int ControllerId, bool& Success, FVector& Gyroscope);

	UFUNCTION(BlueprintPure, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons IMU Vector"))
		static void GetJoyConVector(int ControllerId, bool& Success, FRotator& Vector);
	
	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons ReCenter IMU"))
		static void ReCenterJoyCon(int ControllerId, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Set Filter Coefficient"))
		static void SetJoyConFilterCoefficient(int ControllerId, float Coefficient, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Recenter IMU"))
		static void SetJoyConGripMode(int GripIndex, EGripMode GripMode, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Recenter IMU"))
		static void SetJoyConRumble(int ControllerId, float LowFrequency, float HighFrequency, float Amplitude, int Time, bool& Success);
};