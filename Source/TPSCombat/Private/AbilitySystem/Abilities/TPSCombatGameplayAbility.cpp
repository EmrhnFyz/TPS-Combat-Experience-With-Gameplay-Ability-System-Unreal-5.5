// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TPSCombatGameplayAbility.h"
#include  "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"


void UTPSCombatGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UTPSCombatGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* UTPSCombatGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UTPSCombatAbilitySystemComponent* UTPSCombatGameplayAbility::GetTPSCombatAbilitySystemComponentFromActorInfo() const
{
	return Cast<UTPSCombatAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
