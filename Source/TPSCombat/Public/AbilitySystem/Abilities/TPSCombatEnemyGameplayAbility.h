// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/TPSCombatGameplayAbility.h"
#include "TPSCombatEnemyGameplayAbility.generated.h"

class ATPSCombatEnemyCharacter;
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatEnemyGameplayAbility : public UTPSCombatGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	ATPSCombatEnemyCharacter* GetEnemyCharacterFromActorInfo();
	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ATPSCombatEnemyCharacter> CachedEnemyCharacter;
	TWeakObjectPtr<UEnemyCombatComponent> CachedEnemyCombatComponent;
};
