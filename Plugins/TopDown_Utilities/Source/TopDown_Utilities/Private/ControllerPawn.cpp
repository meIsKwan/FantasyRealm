// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"

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
	
	// Create Floating Pawn Component
	FloatingComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Component"));
	// FloatingComponent->UpdatedComponent = Capsule_CP;
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

void AControllerPawn::Move(const FInputActionValue& Value)
{
	const FVector2D MovementInput = Value.Get<FVector2D>();

	if (Controller)
	{
		AddMovementInput(GetActorRightVector(), MovementInput.X);
		AddMovementInput(GetActorForwardVector(), MovementInput.Y);
	}
}

// Called to bind functionality to input
void AControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AControllerPawn::Move);
	}
}