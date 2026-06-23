// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SelectableInterface.h"
#include "Components/SceneComponent.h"
#include "CLM_BaseActor.h"

// Sets default values
ACLM_BaseActor::ACLM_BaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create RootScene
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root Scene"));
	RootComponent = RootScene;
	
	// Create Box Component (Collision)
	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollisionComponent->SetupAttachment(RootComponent);
	BoxCollisionComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	RootComponent = BoxCollisionComponent;
	
	// Create Static Mesh (Building)
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Building"));
	StaticMeshComponent->SetupAttachment(BoxCollisionComponent);
	
	// Create Selected Indicator (With no collision)
	SelectedIndicator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Selected Indicator"));
	SelectedIndicator->SetupAttachment(BoxCollisionComponent);
	SelectedIndicator->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	SelectedIndicator->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void ACLM_BaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACLM_BaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACLM_BaseActor::SelectActor_Implementation(const bool Select)
{
	// ISelectableInterface::SelectActor_Implementation(Select);
	SelectedIndicator->SetHiddenInGame(!Select);
	
}

