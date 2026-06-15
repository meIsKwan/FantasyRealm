// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

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
	UEnhancedInputLocalPlayerSubsystem* Subsystem
}
