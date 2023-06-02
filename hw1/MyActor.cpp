//Заполните уведомление об авторских правах на странице «Описание» в настройках проекта.

#include "MyActor.h"

// Устанавливает значения по умолчанию
AMyActor::AMyActor()
{
 	// Настройте этого актера на вызов Tick() в каждом кадре. Вы можете отключить это, чтобы улучшить производительность, если вам это не нужно.
	PrimaryActorTick.bCanEverTick = true;

}

// Вызывается при запуске игры или при появлении
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

//Вызывается каждый кадр
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

