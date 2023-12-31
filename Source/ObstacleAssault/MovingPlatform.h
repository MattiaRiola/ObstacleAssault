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

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FRotator PlatformAngularVelocity = FRotator(0,0,100);
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	double MaxDistance = 100;

private:
	FVector StartLocation;
	UPROPERTY(VisibleAnywhere, Category="Moving Platform")
	double MovedDistance = -1;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MovePlatform(float DeltaTime);
    void UpdatePosition(float DeltaTime);
    void RotatePlatform(float DeltaTime);
    float CapLocationAndReverseVelocity();
    bool ShouldRevertMovementDirection() const;
    float GetDistanceMoved() const;
};
