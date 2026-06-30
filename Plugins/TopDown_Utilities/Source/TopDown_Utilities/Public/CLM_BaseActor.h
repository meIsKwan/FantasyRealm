// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigableInterface.h"
#include "SelectableInterface.h"
#include "GameFramework/Actor.h"
#include "CLM_BaseActor.generated.h"

class UBoxComponent;
class USceneComponent;
class UStaticMeshComponent;
class ISelectableInterface; 

UCLASS()
class TOPDOWN_UTILITIES_API ACLM_BaseActor : public AActor, public ISelectableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACLM_BaseActor();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Override the function SelectActor
	virtual void SelectActor_Implementation(const bool Select) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Actor", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> RootScene;
	
	// Create Collision Box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxCollisionComponent;
	
	// Create Static Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Actor", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMeshComponent> StaticMeshComponent;
	
	// Create Selected Indicator
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Actor", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SelectedIndicator;
};
