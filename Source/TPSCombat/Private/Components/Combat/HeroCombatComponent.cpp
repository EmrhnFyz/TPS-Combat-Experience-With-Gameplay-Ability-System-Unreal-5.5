// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/TPSCombatHeroWeapon.h"

ATPSCombatHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<ATPSCombatHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
