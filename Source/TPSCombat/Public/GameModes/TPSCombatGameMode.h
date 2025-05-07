// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPSCombatTypes/TPSCombatEnumTypes.h"
#include "TPSCombatGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API ATPSCombatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATPSCombatGameMode();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	ETPSCombatGameDifficulty CurrentGameDifficulty;

public:
	FORCEINLINE ETPSCombatGameDifficulty GetCurrentGameDifficulty() const { return CurrentGameDifficulty; }
};
