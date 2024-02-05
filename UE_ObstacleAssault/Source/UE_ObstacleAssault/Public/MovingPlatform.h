// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UE_OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:


	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector PlatformVelocity = FVector(0, 0, 250);

	FVector StartLocation;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float MoveDistance = 500;
	
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float OverShoot;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationalVelocity = FRotator::ZeroRotator;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;

	float GetDistanceMoved() const;
};
