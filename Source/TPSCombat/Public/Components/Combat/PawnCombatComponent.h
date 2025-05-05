// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand,
};

class ATPSCombatWeaponBase;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ATPSCombatWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	ATPSCombatWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	ATPSCombatWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category="TPSCombat|Combat")
	void ToggleWeaponCollision(bool bShouldEnableCollision, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);

	UPROPERTY(BlueprintReadWrite, Category="TPSCombat|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

protected:
	virtual void ToggleCurrentEquippedWeaponCollision(bool bShouldEnable);
	virtual void ToggleBodyCollisionBoxCollision(bool bShouldEnable,EToggleDamageType ToggleDamageType);
	
	TArray<AActor*> OverlappedActors;

private:
	TMap<FGameplayTag, ATPSCombatWeaponBase*> CharacterCarriedWeaponMap;
};
