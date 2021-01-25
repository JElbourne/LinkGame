// Fill out your copyright notice in the Description page of Project Settings.


#include "LinkEnemyBase.h"

// Sets default values
ALinkEnemyBase::ALinkEnemyBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ALinkEnemyBase::DamageEnemy(float DamageIn)
{
	Health -= DamageIn;
	if (Health <= 0)
	{
		Die();
	}
}

