// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"

#include "CLM_BasePawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ATopDownPlayerController::ATopDownPlayerController()
{
	bShowMouseCursor = true;
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
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Completed, this, &ATopDownPlayerController::Select);
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
