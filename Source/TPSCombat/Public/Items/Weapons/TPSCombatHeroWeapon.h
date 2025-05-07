// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/TPSCombatWeaponBase.h"
#include "TPSCombat/Public/TPSCombatTypes/TPSCombatStructTypes.h"
#include "GameplayAbilitySpec.h"
#include "TPSCombatHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API ATPSCombatHeroWeapon : public ATPSCombatWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponData")
	FTPSCombatHeroWeaponData HeroWeaponData;
	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles);
	UFUNCTION(BlueprintCallable)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
