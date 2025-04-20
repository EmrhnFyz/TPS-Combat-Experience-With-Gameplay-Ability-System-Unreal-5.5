// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"


class ATPSCombatWeaponBase;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

	TMap<FGameplayTag, ATPSCombatWeaponBase*> CharacterCarriedWeaponMap;

public:
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ATPSCombatWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	ATPSCombatWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	ATPSCombatWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category="TPSCombat|Combat")
	FGameplayTag CurrentEquippedWeaponTag;
};
