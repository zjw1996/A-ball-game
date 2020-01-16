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
	//��ȡָ����ҵ�ָ��
	ASphereBase* Pawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Pawn) {
		PlayPawn = Pawn;
		//��CurrentStart��¼��ǰλ��
		CurrentStart = PlayPawn->GetActorLocation();
	}


}

void ABallGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//���ô˺�����������
void  ABallGameModeBase::SetPlayerLocation(FVector Start)
{
	PlayPawn->SetActorLocation(Start);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}

//�������أ����������ʱ�ص������һ���浵��
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
