// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class ATPSCombatHeroWeapon;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	ATPSCombatHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	ATPSCombatHeroWeapon* GetHeroCurrentEquippedWeapon() const;
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	float GetHeroCurrentEquppedWeaponDamageAtLevel(float InLevel) const;
	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor) override;
};
