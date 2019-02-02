/// Copyright Mad Science Game Studio

#include "TankAIController.h"
#include "TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	APawn*PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check acceptance radius is in cm

	AimAtPlayer();

	if (!ensure(AimingComponent)) { return; }
	AimingComponent->Fire();
}

void ATankAIController::AimAtPlayer()
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank)) { return; }

	if (!ensure(AimingComponent)) { return; }

	AimingComponent->AimAt(PlayerTank->GetTargetLocation()); ///If there is a targeting problem consider using GetActorLocation()
}
