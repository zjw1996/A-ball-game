#include "EndLocation.h"
#include "GameMode/BallGameModeBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

AEndLocation::AEndLocation() {
	EndMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndMeshComp"));
	HitBoxComp->SetupAttachment(EndMeshComp);
}

void AEndLocation::OnHitSphere(ASphereBase * sphere) {
	ABallGameModeBase * GameModeBase = Cast<ABallGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetPlayerInput(false);
}