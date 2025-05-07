// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSCombatGameInstance.h"

TSoftObjectPtr<UWorld> UTPSCombatGameInstance::GetGameLevelByTag(FGameplayTag InTag) const
{
	for (const FTPSCombatGameLevelSet& GameLevelSet : GameLevelSets)
	{
		if (!GameLevelSet.IsValid())
		{
			continue;
		}

		if (GameLevelSet.LevelTag == InTag)
		{
			return GameLevelSet.Level;
		}
	}

	return TSoftObjectPtr<UWorld>();
}
