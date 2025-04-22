// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TPSCombatHeroGameplayAbility.h"
#include "Characters/TPSCombatHeroCharacter.h"
#include "Controllers/TPSCombatHeroController.h"
#include "Components/Combat/HeroCombatComponent.h"

ATPSCombatHeroCharacter* UTPSCombatHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedHeroCharacter.IsValid())
	{
		CachedHeroCharacter = Cast<ATPSCombatHeroCharacter>(CurrentActorInfo->AvatarActor.Get());
	}

	return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

ATPSCombatHeroController* UTPSCombatHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<ATPSCombatHeroController>(GetOwningActorFromActorInfo()->GetInstigatorController());
	}

	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : Cast<ATPSCombatHeroController>(GetOwningActorFromActorInfo()->GetInstigatorController());
}

UHeroCombatComponent* UTPSCombatHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
