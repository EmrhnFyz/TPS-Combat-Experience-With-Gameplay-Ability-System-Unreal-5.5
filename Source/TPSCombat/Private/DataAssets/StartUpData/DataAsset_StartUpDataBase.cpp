// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/TPSCombatGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UTPSCombatAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass)
			{
				continue;
			}
			const UGameplayEffect* EffectClassDefaultObject = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf(EffectClassDefaultObject, ApplyLevel, InASCToGive->MakeEffectContext());
		}
	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UTPSCombatGameplayAbility>>& InAbilitiesToGive, UTPSCombatAbilitySystemComponent* InTASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UTPSCombatGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability)
		{
			continue;
		}
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InTASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InTASCToGive->GiveAbility(AbilitySpec);
	}
}
