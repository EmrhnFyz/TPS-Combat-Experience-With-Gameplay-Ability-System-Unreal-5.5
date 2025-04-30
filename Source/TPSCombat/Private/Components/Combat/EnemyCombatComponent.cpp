// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "TPSCombatGameplayTags.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);

	// TODO: Implement block check
	bool bIsValidBlock = false;

	constexpr bool bIsPlayerBlocking = false;
	constexpr bool bIsAttackUnblockable = false;


	if (bIsPlayerBlocking && !bIsAttackUnblockable)
	{
		// TODO: Check iof the block is valid	
	}

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	if (bIsValidBlock)
	{
		//TODO: Hande Successful block
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), TPSCombatGameplayTags::Shared_Event_MeleeHit, EventData);
	}
}
