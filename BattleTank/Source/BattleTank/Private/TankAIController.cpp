// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: No Tank Controlled"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: Possesed tank's name = %s"), *(ControlledTank->GetName()));
	}

	auto FirstPlayerController = GetPlayerTank();
	if (!FirstPlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: No player controller found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: First player controller name = %s"), *(FirstPlayerController->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}