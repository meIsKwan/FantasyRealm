// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPlayerController.generated.h"

class ACLM_BasePawn;
class UInputMappingContext;
class UInputAction;
class AActor;
class ATopDownHUD;
struct FInputActionValue;

UCLASS()
class TOPDOWN_UTILITIES_API ATopDownPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATopDownPlayerController();
	UPROPERTY(EditDefaultsOnly, Category="Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultInputMappingContext;
	
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
	void Select(const FInputActionValue& Value);

	void CommandSelectedActor(const FInputActionValue& Value);
	
	// Actor Rect Selection
	void SelectStart(const FInputActionValue& Value);
	void SelectOnGoing(const FInputActionValue& Value);
	void SelectEnd(const FInputActionValue& Value);
	void SelectMultipleActors();
	// ------------------------------------------------
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SelectAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> CommandAction;
	
	UPROPERTY()
	TObjectPtr<AActor> SelectedActor;
	
	UPROPERTY()
	TObjectPtr<ATopDownHUD> TopDownHUD;
	
	// Actor Rect Selection
	FVector2D SelectionStartPosition;
	FVector2D SelectionSize;
	
	TArray<AActor*> SelectedActors;
	// ------------------------------------------------
	
};
