// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AControllerPawn::AControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
	
	// Create Capsule Component in Blueprint
	Capsule_CP = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule_CP"));
	RootComponent = Capsule_CP;
	// Create SpringArm Component in Blueprint
	SpringArm_CP = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm_CP"));
	SpringArm_CP->SetupAttachment(RootComponent);
	SpringArm_CP->TargetArmLength = 1500.f;
	
	// Create Camera Component in Blueprint
	Camera_CP = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera_CP"));
	Camera_CP->SetupAttachment(SpringArm_CP, USpringArmComponent::SocketName);
	Camera_CP->SetProjectionMode(ECameraProjectionMode::Type::Orthographic);
}

// Called when the game starts or when spawned
void AControllerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControllerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

