#include "SaveLocation.h"
#include "GameMode/BallGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ASaveLocation::ASaveLocation() {
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));
	HitBoxComp->SetupAttachment(SaveMeshComp);
}

void ASaveLocation::OnHitSphere(ASphereBase * sphere) {
	ABallGameModeBase * GameModeBase = Cast<ABallGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetCurrentStart(HitBoxComp->GetComponentLocation());
}