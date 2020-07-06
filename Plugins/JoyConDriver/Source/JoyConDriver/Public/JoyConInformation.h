// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JoyConInformation.generated.h"

USTRUCT(BlueprintType)
struct FJoyConInformation {
	GENERATED_USTRUCT_BODY()

public:
	FJoyConInformation();
	FJoyConInformation(int TempProductId, int TempVendorId, int TempInterfaceNumber, int TempReleaseNumber, FString TempManufacturerString,
		FString TempBluetoothPath, FString TempProductString, FString TempSerialNumber, int TempControllerId, int TempUsage,
		int TempUsagePage, bool TempIsLeft, bool TempIsConnected);

	/*
	 * Device Info
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int ProductId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int VendorId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int InterfaceNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int ReleaseNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString ManufacturerString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString BluetoothPath;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString ProductString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString SerialNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int ControllerId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Usage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int UsagePage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool IsLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool IsConnected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool IsAttached;
};
