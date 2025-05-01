// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "TPSCombatGameplayTags.h"
#include "TPSCombatFunctionLibrary.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);

	// TODO: Implement block check
	bool bIsValidBlock = false;

	const bool bIsPlayerBlocking = UTPSCombatFunctionLibrary::NativeDoesActorHaveTag(HitActor, TPSCombatGameplayTags::Player_Status_Block);
	constexpr bool bIsAttackUnblockable = false;


	if (bIsPlayerBlocking && !bIsAttackUnblockable)
	{
		bIsValidBlock = UTPSCombatFunctionLibrary::IsValidBlock(GetOwningPawn(), HitActor);
	}

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	if (bIsValidBlock)
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, TPSCombatGameplayTags::Player_Event_SuccessfulBlock, EventData);
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), TPSCombatGameplayTags::Shared_Event_MeleeHit, EventData);
	}
}
