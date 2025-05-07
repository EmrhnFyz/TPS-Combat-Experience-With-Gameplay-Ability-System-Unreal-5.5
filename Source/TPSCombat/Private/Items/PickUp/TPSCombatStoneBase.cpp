// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/PickUp/TPSCombatStoneBase.h"
#include "Characters/TPSCombatHeroCharacter.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "TPSCombatGameplayTags.h"

void ATPSCombatStoneBase::Consume(UTPSCombatAbilitySystemComponent* AbilitySystemComponent, int32 ApplyLevel)
{
	check(StoneGameplayEffectClass);

	UGameplayEffect* EffectCDO = StoneGameplayEffectClass->GetDefaultObject<UGameplayEffect>();

	AbilitySystemComponent->ApplyGameplayEffectToSelf(
		EffectCDO,
		ApplyLevel,
		AbilitySystemComponent->MakeEffectContext()
	);

	BP_OnStoneConsumed();
}

void ATPSCombatStoneBase::OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ATPSCombatHeroCharacter* OverlappedHeroCharacter = Cast<ATPSCombatHeroCharacter>(OtherActor))
	{
		OverlappedHeroCharacter->GetTPSCombatAbilitySystemComponent()->TryActivateAbilityByTag(TPSCombatGameplayTags::Player_Ability_PickUp_Stones);
	}
}
