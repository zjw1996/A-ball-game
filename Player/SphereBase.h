#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SphereBase.generated.h"

UCLASS()
class BALL_API ASphereBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASphereBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereMeshComp")
		class UStaticMeshComponent * SphereMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraArmComp")
		class USpringArmComponent * CameraArmComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraComp")
		class UCameraComponent * CameraComp;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsInput; // �Ƿ������������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SphereSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SpeedMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SpeedMax;
	FVector	AngularVector;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//С���˶��ĳ�Ա����
	UFUNCTION(BlueprintCallable)
		void MoveForward(float val);

	UFUNCTION(BlueprintCallable)
		void MoveRight(float val);

	UFUNCTION(BlueprintCallable)
		void SpeedUp();
	UFUNCTION(BlueprintCallable)
		void SpeedLow();
};
