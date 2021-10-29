// Fill out your copyright notice in the Description page of Project Settings.


#include "CppMotionTest.h"
#include "JoyConDriver/Public/IJoyConDriverModule.h"

// Sets default values
ACppMotionTest::ACppMotionTest() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppMotionTest::BeginPlay() {
	Super::BeginPlay();
	TArray<IJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<IJoyConDriverModule>(IJoyConDriverModule::GetModularFeatureName());
	for (IJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		JoyConModule = JoyConInputApi;
		break;
	}
}

// Called every frame
void ACppMotionTest::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (JoyConModule == nullptr) return;
	FRotator Rotation;
	if(JoyConModule->GetJoyConVector(0, Rotation)) {
		SetActorRotation(Rotation);
	}
}

