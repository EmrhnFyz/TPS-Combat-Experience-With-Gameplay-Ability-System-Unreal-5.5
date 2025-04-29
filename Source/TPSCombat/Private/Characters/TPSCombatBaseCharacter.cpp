// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TPSCombatBaseCharacter.h"
#include "AbilitySystem/TPSCombatAttributeSet.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"

// Sets default values
ATPSCombatBaseCharacter::ATPSCombatBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	TPSCombatAbilitySystemComponent = CreateDefaultSubobject<UTPSCombatAbilitySystemComponent>(TEXT("TPSCombatAbilitySystemComponent"));
	TPSCombatAttributeSet = CreateDefaultSubobject<UTPSCombatAttributeSet>(TEXT("TPSCombatAttributeSet"));
}

UAbilitySystemComponent* ATPSCombatBaseCharacter::GetAbilitySystemComponent() const
{
	return GetTPSCombatAbilitySystemComponent();
}

UPawnCombatComponent* ATPSCombatBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* ATPSCombatBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}

void ATPSCombatBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (TPSCombatAbilitySystemComponent)
	{
		TPSCombatAbilitySystemComponent->InitAbilityActorInfo(this, this);
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("CharacterStartUpData is null,  Please check to %s"), *GetName());
	}
}
