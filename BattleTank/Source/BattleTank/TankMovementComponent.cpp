// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"





void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (CheckTrackPointers())
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	if (CheckTrackPointers())
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(-Throw);
		UE_LOG(LogTemp, Warning, TEXT("Throttle at %f"), Throw)
	}
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

bool UTankMovementComponent::CheckTrackPointers()
{
	// Handle null pointer
	if (LeftTrack == nullptr || RightTrack == nullptr) { return false; }
	else { return true; }
}
