// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownHUD.h"



void ATopDownHUD::DrawHUD()
{
	Super::DrawHUD();
	
	if (bDrawSelectionRect)
	{
		DrawRect(SelectionRectColor, SelectionRectStart.X, SelectionRectStart.Y, SelectionRectSize.X, SelectionRectSize.Y);
	}
	if (bSelectActors)
	{
		SelectActorsInRect();
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
	bSelectActors = true;
}

TArray<AActor*> ATopDownHUD::GetSelectedActors()
{
	return SelectedActors;
}

void ATopDownHUD::SelectActorsInRect()
{
	SelectedActors.Empty();
	FVector2D FirstPoint = SelectionRectStart;
	FVector2D SecondPoint = SelectionRectStart + SelectionRectSize;
	GetActorsInSelectionRectangle<AActor>(FirstPoint, SecondPoint, SelectedActors, false);
	bSelectActors = false;

	for (AActor* SomeActor : SelectedActors)
	{
		if (SomeActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Selected: %s"), *SomeActor->GetName());
	    }
	}
}
