// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TPSCombatStructTypes.generated.h"
class UWarriorHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FTPSCombatHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponData")
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};
