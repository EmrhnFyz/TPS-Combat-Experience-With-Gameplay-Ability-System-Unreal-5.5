// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "TPSCombatHeroController.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API ATPSCombatHeroController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ATPSCombatHeroController();
	virtual FGenericTeamId GetGenericTeamId() const override;

private:
	FGenericTeamId HeroTeamId;
};
