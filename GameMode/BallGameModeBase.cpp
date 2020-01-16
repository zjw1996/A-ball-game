#include "BallGameModeBase.h"
#include "Player/SphereBase.h"
#include "Engine.h"


ABallGameModeBase::ABallGameModeBase() 
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerDeathNumber = 0;
	IsEnd = false;
}


void ABallGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//获取指向玩家的指针
	ASphereBase* Pawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Pawn) {
		PlayPawn = Pawn;
		//用CurrentStart记录当前位置
		CurrentStart = PlayPawn->GetActorLocation();
	}


}

void ABallGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//可用此函数做闪现门
void  ABallGameModeBase::SetPlayerLocation(FVector Start)
{
	PlayPawn->SetActorLocation(Start);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}

//函数重载，在玩家死亡时回到最近的一个存档点
void  ABallGameModeBase::SetPlayerLocation()
{
	PlayPawn->SetActorLocation(CurrentStart);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
	PlayerDeathNumber++;
}

void ABallGameModeBase::SetCurrentStart(FVector Location)
{
		if (Location != FVector(0, 0, 0)) {
			CurrentStart = Location;
		}
}

void ABallGameModeBase::SetPlayerInput(bool isInput) {
	PlayPawn->IsInput = isInput;
	if (!isInput)
	{
		IsEnd = true;
	}
}
