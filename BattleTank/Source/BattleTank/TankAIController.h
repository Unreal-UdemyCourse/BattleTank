// Copyright Mad Science Game Studio

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UTankAimingComponent* AimingComponent = nullptr;

private:
	
	void AimAtPlayer();

	//How close can the AI tank get
	float AcceptanceRadius = 3000;
};
