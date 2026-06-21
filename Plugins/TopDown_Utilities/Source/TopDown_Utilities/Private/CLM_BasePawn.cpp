// Fill out your copyright notice in the Description page of Project Settings.


#include "CLM_BasePawn.h"

#include "AnimationEditorTypes.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ACLM_BasePawn::ACLM_BasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Capsule
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	CapsuleComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	RootComponent = CapsuleComponent;
	// Create SkeltalMeshComponent
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);
	// Create FloatingPawn
	FloatingPawnComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn"));
	// Create Selected Indicator
	SelectedIndicator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Selected Indicator"));
	SelectedIndicator->SetupAttachment(RootComponent);
	SelectedIndicator->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	SelectedIndicator->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void ACLM_BasePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACLM_BasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACLM_BasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACLM_BasePawn::SelectActorLocal(const bool Select)
{
	SelectedIndicator->SetHiddenInGame(!Select);
}

void ACLM_BasePawn::SelectActor_Implementation(const bool Select)
{
	SelectedIndicator->SetHiddenInGame(!Select);
}

