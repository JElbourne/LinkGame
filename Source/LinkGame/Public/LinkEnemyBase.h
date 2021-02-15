// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LinkMainCamera.h"
#include "LinkEnemyBase.generated.h"

UCLASS()
class LINKGAME_API ALinkEnemyBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALinkEnemyBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Enemy Base", meta = ( ExposeOnSpawn = "true"))
	FVector2D ZoneCoords;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Base", meta = (ExposeOnSpawn = "true"))
	FVector EnemyId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Base", meta = (ExposeOnSpawn = "true"))
	ALinkMainCamera* CameraReference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Base")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Base")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Base")
	bool CanTakeDamage;

	UFUNCTION(BlueprintCallable, Category = "Enemy Base")
	void DamageEnemy(float DamageIn);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Enemy Base")
	void Die();
};
