// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JoyConDriverFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class JOYCONDRIVER_API UJoyConDriverFunctionLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Connect"))
	static void ConnectJoyCons(bool& Success);

	UFUNCTION(BlueprintPure, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Search"))
	static void SearchForJoyCons(bool& Success, int &Count);

	UFUNCTION(BlueprintPure, Category = "JoyCon", meta = (Keywords = "Nintendo Switch Joy Con Cons JoyCon JoyCons Disconnect"))
	static void DisconnectJoyCons(bool& Success);
};
