// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownHUD.h"

void ATopDownHUD::DrawHUD()
{
	Super::DrawHUD();
	
	if (bDrawSelectionRect)
	{
		DrawRect(SelectionRectColor, SelectionRectStart.X, SelectionRectStart.Y, SelectionRectSize.X, SelectionRectSize.Y);
	}
}

void ATopDownHUD::ShowSelectionRect(const FVector2D InSelectionRectStart, const FVector2D InSelectionRectSize)
{
	SelectionRectStart = InSelectionRectStart;
	SelectionRectSize = InSelectionRectSize;
	bDrawSelectionRect = true;
}

void ATopDownHUD::HideSelectionRect()
{
	bDrawSelectionRect = false;
}
