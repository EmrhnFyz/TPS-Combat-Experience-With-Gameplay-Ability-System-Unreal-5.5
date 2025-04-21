// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"

void UTPSCombatAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag))
		{
			continue;
		}

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UTPSCombatAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
