// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

private:
	bool IsGoingOutOfBoundaries();
	FVector StartPosition = FVector(0,0,0);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector MyPosition = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere)
	float MaxY = 0.0;
	UPROPERTY(EditAnywhere)
	float MinY = 0.0;
	UPROPERTY(EditAnywhere)
	float delta = 100.0;

	UPROPERTY(EditAnywhere)
	double DistanceMoved = 0.0d;

	UPROPERTY(EditAnywhere)
	double DistanceFromOriginalPosition = 0.0d;

};
