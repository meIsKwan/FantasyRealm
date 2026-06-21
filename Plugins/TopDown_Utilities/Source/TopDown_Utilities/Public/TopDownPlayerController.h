// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPlayerController.generated.h"

class ACLM_BasePawn;
class UInputMappingContext;
class UInputAction;
class AActor;
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
	
	virtual void SetupInputComponent() override;
	
	void Select(const FInputActionValue& Value);
	
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SelectAction;
	
	UPROPERTY()
	AActor* SelectedActor;
};
