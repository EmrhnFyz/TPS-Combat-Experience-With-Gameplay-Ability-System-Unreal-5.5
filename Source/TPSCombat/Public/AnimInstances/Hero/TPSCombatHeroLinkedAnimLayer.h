// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/TPSCombatBaseAnimInstance.h"
#include "TPSCombatHeroLinkedAnimLayer.generated.h"

class UTPSCombatHeroAnimInstance;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatHeroLinkedAnimLayer : public UTPSCombatBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(NotBlueprintThreadSafe))
	UTPSCombatHeroAnimInstance* GetHeroAnimInstance() const;
};
