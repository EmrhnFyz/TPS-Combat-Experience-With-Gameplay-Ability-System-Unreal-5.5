// Fill out your copyright notice in the Description page of Project Settings.


#include "TpsCombatTypes/TPSCombatStructTypes.h"

#include "AbilitySystem/Abilities/TPSCombatGameplayAbility.h"

bool FHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
