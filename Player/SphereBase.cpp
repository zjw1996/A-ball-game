#include "SphereBase.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// 成员初始化
ASphereBase::ASphereBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IsInput = true;
	//球体速度默认初始化为300
	SphereSpeed = 300.0f;
	SpeedMin = SphereSpeed;
	//加速时为500
	SpeedMax = 500.0f;
	//sphere模型，在生成的蓝图类里设为小球
	SphereMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMeshComp"));
	SphereMeshComp->SetSimulatePhysics(true);
	//摄像机机臂初始化
	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmComp"));
	CameraArmComp->SetupAttachment(SphereMeshComp);
	//相机初始化
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

//绑定按键
void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASphereBase::MoveForward); //前后
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereBase::MoveRight);  //左右

	PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &ASphereBase::SpeedUp);//冲刺
	PlayerInputComponent->BindAction("SpeedUp", IE_Released, this, &ASphereBase::SpeedLow);//停止冲刺
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


