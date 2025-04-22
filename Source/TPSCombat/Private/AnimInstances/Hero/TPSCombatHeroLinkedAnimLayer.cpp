// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/TPSCombatHeroLinkedAnimLayer.h"

#include "AnimInstances/Hero/TPSCombatHeroAnimInstance.h"

UTPSCombatHeroAnimInstance* UTPSCombatHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UTPSCombatHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
