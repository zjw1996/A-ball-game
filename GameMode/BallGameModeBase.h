// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BallGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BALL_API ABallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ABallGameModeBase();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayPawn")
		class ASphereBase * PlayPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentStart")
		FVector CurrentStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerDeathNumber")
		int32 PlayerDeathNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IsEnd")
		bool IsEnd;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	//闪现到某个指定的位置
	UFUNCTION(BlueprintCallable, Category = "SetPlayerLocation")
	void SetPlayerLocation(FVector Start);
	//重载函数，使玩家回到默认的位置，即起始点
	void SetPlayerLocation();
	UFUNCTION(BlueprintCallable, Category = "SetCurrentStart")
	void SetCurrentStart(FVector Location);
	UFUNCTION(BlueprintCallable, Category = "SetPlayerInput")
	void SetPlayerInput(bool isInput);
};
