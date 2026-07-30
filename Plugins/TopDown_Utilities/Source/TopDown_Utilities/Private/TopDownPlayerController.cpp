// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"

#include "CLM_BasePawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SelectableInterface.h"
#include "NavigableInterface.h"
#include "TopDownHUD.h"

ATopDownPlayerController::ATopDownPlayerController()
{
	bShowMouseCursor = true;
}

void ATopDownPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	TopDownHUD = Cast<ATopDownHUD>(GetHUD());
}

void ATopDownPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (!DefaultInputMappingContext)
	{
		return;
	}
	
	// EnhancedInput system
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (Subsystem)
	{
		Subsystem->AddMappingContext(DefaultInputMappingContext, 0);
		UE_LOG(LogTemp, Display, TEXT("Input mapping context added."))
	}
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind Select function to Select input action
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Completed, this, &ATopDownPlayerController::Select);

		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Started, this, &ATopDownPlayerController::SelectStart);
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Triggered, this, &ATopDownPlayerController::SelectOnGoing);
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Completed, this, &ATopDownPlayerController::SelectEnd);
		
		// Bind Command actioon to CommandSelectedActor
		EnhancedInputComponent->BindAction(CommandAction, ETriggerEvent::Completed, this, &ATopDownPlayerController::CommandSelectedActor);
	}
}

void ATopDownPlayerController::Select(const FInputActionValue& Value)
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, false, HitResult);
	
	if (SelectedActor)
	{
		if (SelectedActor->GetClass()->ImplementsInterface(USelectableInterface::StaticClass()))
		{
			ISelectableInterface::Execute_SelectActor(SelectedActor, false);
		}
	}

	
	SelectedActor = HitResult.GetActor();
	
	if (SelectedActor)
	{
		UE_LOG(LogTemp, Display, TEXT("%s"), *SelectedActor->GetName());
		
		if (SelectedActor->GetClass()->ImplementsInterface(USelectableInterface::StaticClass()))
		{
			ISelectableInterface::Execute_SelectActor(SelectedActor, true);
		}
	}
}

void ATopDownPlayerController::CommandSelectedActor(const FInputActionValue& Value)
{
	if (SelectedActor)
	{
		UE_LOG(LogTemp, Display, TEXT("Chúc mừng bạn"));
		FHitResult HitResult;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, false, HitResult);
		
		if (HitResult.bBlockingHit && SelectedActor->GetClass()->ImplementsInterface(UNavigableInterface::StaticClass()))
		{
			INavigableInterface::Execute_MoveToLocation(SelectedActor, HitResult.Location);
		}
	}
}

void ATopDownPlayerController::SelectStart(const FInputActionValue& Value)
{
	float MouseX, MouseY;
	GetMousePosition(MouseX, MouseY);
	SelectionStartPosition = FVector2D(MouseX, MouseY);
	UE_LOG(LogTemp, Display, TEXT("Selection started"));
}

void ATopDownPlayerController::SelectOnGoing(const FInputActionValue& Value)
{
	float MouseX, MouseY;
	GetMousePosition(MouseX, MouseY);
	SelectionSize = FVector2D(MouseX - SelectionStartPosition.X, MouseY - SelectionStartPosition.Y);
	UE_LOG(LogTemp, Display, TEXT("Selection ongoing"));
	
	if (true)
	{
		TopDownHUD->ShowSelectionRect(SelectionStartPosition, SelectionSize);
	}
}

void ATopDownPlayerController::SelectEnd(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Display, TEXT("Selection end"));
	if (TopDownHUD)
	{
		TopDownHUD->HideSelectionRect();
	}
}
