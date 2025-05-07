// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickUp/TPSCombatPickUpBase.h"
#include "TPSCombatStoneBase.generated.h"

class UGameplayEffect;
class UTPSCombatAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API ATPSCombatStoneBase : public ATPSCombatPickUpBase
{
	GENERATED_BODY()

public:
	void Consume(UTPSCombatAbilitySystemComponent* AbilitySystemComponent, int32 ApplyLevel);

protected:
	virtual void OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Stone Consumed"))
	void BP_OnStoneConsumed();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> StoneGameplayEffectClass;
};
