// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TpsCombatTypes/TPSCombatStructTypes.h"
#include "TPSCombatAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|Ability", meta=(ApplyLevel="1"))
	void GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InWeaponDefaultAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles);
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Ability")
	void RemoveGrantedAbilitySpecHandles(UPARAM(ref)
		TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);
};
