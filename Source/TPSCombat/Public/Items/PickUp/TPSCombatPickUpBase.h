// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSCombatPickUpBase.generated.h"

class USphereComponent;

UCLASS()
class TPSCOMBAT_API ATPSCombatPickUpBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATPSCombatPickUpBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pick Up Interaction")
	USphereComponent* PickUpCollisionSphere;

	UFUNCTION()
	virtual void OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
