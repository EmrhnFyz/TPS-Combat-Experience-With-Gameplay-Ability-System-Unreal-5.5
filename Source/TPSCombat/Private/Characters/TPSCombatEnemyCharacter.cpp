// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TPSCombatEnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/AssetManager.h"

#include "TPSCombatDebugHelper.h"
#include "Components/WidgetComponent.h"
#include "Components/UI/EnemyUIComponent.h"
#include "Widgets/TPSCombatWidgetBase.h"

ATPSCombatEnemyCharacter::ATPSCombatEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
	EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>(TEXT("EnemyUIComponent"));
	EnemyHealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyHealthWidgetComponent"));

	EnemyHealthWidgetComponent->SetupAttachment(GetMesh());
}

void ATPSCombatEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitEnemyStartUpData();
}

UPawnCombatComponent* ATPSCombatEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

UPawnUIComponent* ATPSCombatEnemyCharacter::GetPawnUIComponent() const
{
	return EnemyUIComponent;
}

UEnemyUIComponent* ATPSCombatEnemyCharacter::GetEnemyUIComponent() const
{
	return EnemyUIComponent;
}

void ATPSCombatEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (UTPSCombatWidgetBase* EnemyHealthWidget = Cast<UTPSCombatWidgetBase>(EnemyHealthWidgetComponent->GetUserWidgetObject()))
	{
		EnemyHealthWidget->InitEnemyCreatedWidget(this);
	}
}

void ATPSCombatEnemyCharacter::InitEnemyStartUpData()
{
	if (CharacterStartUpData.IsNull())
	{
		return;
	}

	UAssetManager::GetStreamableManager()
		.RequestAsyncLoad(
			CharacterStartUpData.ToSoftObjectPath(),
			FStreamableDelegate::CreateLambda(
				[this]()
				{
					if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.Get())
					{
						LoadedData->GiveToAbilitySystemComponent(TPSCombatAbilitySystemComponent);
					}
				}
			)
		);
}
