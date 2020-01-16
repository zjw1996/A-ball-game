#include "Die_Sphere.h"
#include "Player/SphereBase.h"
#include "Engine.h"
#include "GameMode/BallGameModeBase.h"

void ADie_Sphere::OnHitSphere(ASphereBase * sphere)
{	//获取指向GameMode的指针
	ABallGameModeBase * GameModeBase = Cast<ABallGameModeBase>(GetWorld()->GetAuthGameMode());

	GameModeBase->SetPlayerLocation();
}

