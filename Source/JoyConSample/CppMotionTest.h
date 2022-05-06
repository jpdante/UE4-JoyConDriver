// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IJoyConDriverModule.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppMotionTest.generated.h"

UCLASS()
class JOYCONSAMPLE_API ACppMotionTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppMotionTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	IJoyConDriverModule* JoyConModule;

};
