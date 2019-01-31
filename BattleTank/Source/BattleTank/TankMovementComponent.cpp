// Copyright Mad Science Game Studio

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

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrottle = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrottle);

	float TurnThrottle = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendMoveRight(TurnThrottle);
}
