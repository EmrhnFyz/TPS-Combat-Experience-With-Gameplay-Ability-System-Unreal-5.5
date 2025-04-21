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

	// Player Tags
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	TPSCOMBAT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}
