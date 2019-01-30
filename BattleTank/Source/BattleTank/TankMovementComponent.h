// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;

/**
 *  Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable)
	void IntendMoveRight(float Throw);

	UFUNCTION(BlueprintCallable)
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	//Check tank tracks for null pointer
	bool CheckTrackPointers();


private:
	UTankTrack*  LeftTrack = nullptr;
	UTankTrack*  RightTrack = nullptr;
};
