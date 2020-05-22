// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JoyConInformation.generated.h"

USTRUCT(BlueprintType)
struct FJoyConInformation {
	GENERATED_USTRUCT_BODY()
	
public:
	FJoyConInformation();

	/*
	 * Device Info
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ProductId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName BluetoothPath;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ProbableControllerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsLeft;
};
