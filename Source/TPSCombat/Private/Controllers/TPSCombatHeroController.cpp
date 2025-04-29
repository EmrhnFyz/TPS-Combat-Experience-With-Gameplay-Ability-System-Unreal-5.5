// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TPSCombatHeroController.h"

ATPSCombatHeroController::ATPSCombatHeroController()
{
	HeroTeamId = FGenericTeamId(0);
}

FGenericTeamId ATPSCombatHeroController::GetGenericTeamId() const
{
	return HeroTeamId;
}
