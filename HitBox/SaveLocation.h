#pragma once

#include "CoreMinimal.h"
#include "HitBox/HitBoxBase.h"
#include "SaveLocation.generated.h"

UCLASS()
class BALL_API ASaveLocation : public AHitBoxBase
{
	GENERATED_BODY()
public:
	ASaveLocation();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent * SaveMeshComp;
public:
	virtual void OnHitSphere(ASphereBase * sphere) override;
	
};
