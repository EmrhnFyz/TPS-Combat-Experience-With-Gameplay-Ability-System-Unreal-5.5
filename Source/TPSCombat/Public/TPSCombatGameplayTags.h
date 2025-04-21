// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace TPSCombatGameplayTags
{
	// Input Tags
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

	// Player Tags
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);

	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);

	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);
}
