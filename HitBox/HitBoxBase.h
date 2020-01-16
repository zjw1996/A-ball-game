#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitBoxBase.generated.h"

UCLASS()
class BALL_API AHitBoxBase : public AActor
{
	GENERATED_BODY()

public:
	AHitBoxBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent * HitBoxComp;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		virtual void OnHitSphere(class ASphereBase * sphere);
};