// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UTPSCombatGameplayAbility;
class UTPSCombatAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UTPSCombatAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<UTPSCombatGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<UTPSCombatGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UTPSCombatGameplayAbility>>& InAbilitiesToGive, UTPSCombatAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
