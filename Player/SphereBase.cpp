#include "SphereBase.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// ��Ա��ʼ��
ASphereBase::ASphereBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IsInput = true;
	//�����ٶ�Ĭ�ϳ�ʼ��Ϊ300
	SphereSpeed = 300.0f;
	SpeedMin = SphereSpeed;
	//����ʱΪ500
	SpeedMax = 500.0f;
	//sphereģ�ͣ������ɵ���ͼ������ΪС��
	SphereMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMeshComp"));
	SphereMeshComp->SetSimulatePhysics(true);
	//��������۳�ʼ��
	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmComp"));
	CameraArmComp->SetupAttachment(SphereMeshComp);
	//�����ʼ��
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraArmComp);

}

void ASphereBase::BeginPlay()
{
	Super::BeginPlay();

}

void ASphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AngularVector != FVector(0, 0, 0) && IsInput == true) {
		SphereMeshComp->SetPhysicsAngularVelocity(FVector(AngularVector));
	}
}

//�󶨰���
void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASphereBase::MoveForward); //ǰ��
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereBase::MoveRight);  //����

	PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &ASphereBase::SpeedUp);//���
	PlayerInputComponent->BindAction("SpeedUp", IE_Released, this, &ASphereBase::SpeedLow);//ֹͣ���
}

//
void ASphereBase::MoveForward(float val)
{	
	if (IsInput) {
		AngularVector.Y = SphereSpeed * val;
	}
}

void ASphereBase::MoveRight(float val)
{
	if (IsInput) {
		AngularVector.X = -SphereSpeed * val;
	}
}

void ASphereBase::SpeedUp()
{
	SphereSpeed = SpeedMax;
}

void ASphereBase::SpeedLow() {
	SphereSpeed = SpeedMin;
}


