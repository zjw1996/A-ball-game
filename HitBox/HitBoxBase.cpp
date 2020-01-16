#include "HitBoxBase.h"
#include "Components/BoxComponent.h"
#include "Player/SphereBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

AHitBoxBase::AHitBoxBase()
{
	PrimaryActorTick.bCanEverTick = true;
	HitBoxComp = CreateDefaultSubobject< UBoxComponent>(TEXT("HitBox"));
	HitBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AHitBoxBase::BeginHit);
}

void AHitBoxBase::BeginPlay()
{
	Super::BeginPlay();
}

void AHitBoxBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHitBoxBase::BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ASphereBase>(OtherActor)) {
		ASphereBase * sphere = Cast<ASphereBase>(OtherActor);
		OnHitSphere(sphere);
	}

}

void AHitBoxBase::OnHitSphere(ASphereBase * sphere)
{
}
