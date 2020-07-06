// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JoyConController.h"
#include "JoyConGrip.generated.h"

UENUM()
enum class EGripMode : uint8 {
	Auto         UMETA(DisplayName = "Auto"),
	Portrait     UMETA(DisplayName = "Portrait"),
	Landscape    UMETA(DisplayName = "Landscape"),
	GamePad      UMETA(DisplayName = "GamePad"),
};

USTRUCT(BlueprintType)
struct FJoyConGrip {
	GENERATED_USTRUCT_BODY()

public:
	FJoyConGrip();

	bool ContainsController(FJoyConInformation JoyConInformation);

	/*
	 * Device Info
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int GripIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TEnumAsByte<EGripMode> Mode;
	
		TArray<FJoyConController*> Controllers;
};
