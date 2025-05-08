// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TPSCombatGameplayAbility.h"
#include "TPSCombatHeroGameplayAbility.generated.h"

class ATPSCombatHeroCharacter;
class ATPSCombatHeroController;
class UHeroCombatComponent;

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatHeroGameplayAbility : public UTPSCombatGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	ATPSCombatHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	ATPSCombatHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "TPSCombat|Ability")
	UHeroUIComponent* GetHeroUIComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount);

private:
	TWeakObjectPtr<ATPSCombatHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<ATPSCombatHeroController> CachedHeroController;
};
