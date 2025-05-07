// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSCombat/Public/TPSCombatTypes/TPSCombatStructTypes.h"

#include "AbilitySystem/Abilities/TPSCombatGameplayAbility.h"

bool FHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
