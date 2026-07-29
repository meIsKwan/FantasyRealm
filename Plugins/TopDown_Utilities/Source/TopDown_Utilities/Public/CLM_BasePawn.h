// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigableInterface.h"
#include "SelectableInterface.h"
#include "GameFramework/Pawn.h"
#include "CLM_BasePawn.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UFloatingPawnMovement;
class UStaticMeshComponent;

UCLASS()
class TOPDOWN_UTILITIES_API ACLM_BasePawn : public APawn, public ISelectableInterface, public INavigableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACLM_BasePawn();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	UFUNCTION()
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void SelectActorLocal(const bool Select);
	
	virtual void SelectActor_Implementation(const bool Select) override;
	
	virtual void MoveToLocation_Implementation(const FVector TargetLocation) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void OrientPawnToMovementDirection();
	
	FVector MoveTargetLocation = FVector::ZeroVector;
	bool bMoving = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Options", meta = (AllowPrivateAccess = "true"))
	float AcceptanceDistance = 50.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Options", meta = (AllowPrivateAccess = "true"))
	float CharacterTurnSpeed = 10.f;

private:
	// Create Capsule Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Collision", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;
	
	// Create Skeletal Mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pawn", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SkeletalMeshComponent;
	
	// Floating Pawn Movement Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pawn", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UFloatingPawnMovement> FloatingPawnComponent;
	
	// Floating Pawn Movement Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pawn", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SelectedIndicator;
	
};
