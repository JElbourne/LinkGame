// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LinkMainCamera.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinishedMovingDelegate);

UCLASS()
class LINKGAME_API ALinkMainCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALinkMainCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Link Main Camera")
	FFinishedMovingDelegate OnFinishedMoving;

	UFUNCTION(BlueprintCallable)
	void FinishedMovingCamera();

};
