// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TpsCombatTypes/TPSCombatEnumTypes.h"
#include "TPSCombatSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	ETPSCombatGameDifficulty SavedCurrentGameDifficulty;
};
