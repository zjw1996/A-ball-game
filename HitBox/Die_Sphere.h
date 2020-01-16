// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBox/HitBoxBase.h"
#include "Die_Sphere.generated.h"

/**
 * 
 */
UCLASS()
class BALL_API ADie_Sphere : public AHitBoxBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector sphereVEC;

public:
	virtual void OnHitSphere(ASphereBase * sphere) override;

};