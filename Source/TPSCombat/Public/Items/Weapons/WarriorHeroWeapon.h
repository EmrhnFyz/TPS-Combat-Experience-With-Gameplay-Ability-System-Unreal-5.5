// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/TPSCombatWeaponBase.h"
#include "TpsCombatTypes/TPSCombatStructTypes.h"

#include "WarriorHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API AWarriorHeroWeapon : public ATPSCombatWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponData")
	FTPSCombatHeroWeaponData HeroWeaponData;
};
