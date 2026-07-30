// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TopDownHUD.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_UTILITIES_API ATopDownHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	bool bDrawSelectionRect = false;
	FVector2D SelectionRectStart;
	FVector2d SelectionRectSize;
	FLinearColor SelectionRectColor = FLinearColor(1.f, 0.f, 0.f, .2f);
	
protected:
	virtual void DrawHUD() override;
	
public:
	void ShowSelectionRect(const FVector2D InSelectionRectStart, const FVector2D InSelectionRectSize);
	void HideSelectionRect();
};
