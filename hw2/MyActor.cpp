//Заполните уведомление об авторских правах на странице «Описание» в настройках проекта.

#include "MyActor.h"

// Устанавливает значения по умолчанию
AMyActor::AMyActor()
{
 	// Настройте этого актера на вызов Tick() в каждом кадре. Вы можете отключить это, чтобы улучшить производительность, если вам это не нужно.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent1"));
	RootComponent = StaticMeshComponent1;

	StaticMeshComponent2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent2"));
	StaticMeshComponent2->SetupAttachment(RootComponent);
}

// Вызывается при запуске игры или при появлении
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	bChangingMetallic = false;
	bChangingColor = false;
	MetallicChangeCount = 0;
	ColorChangeCount = 0;

	GetWorldTimerManager().SetTimer(MetallicTimerHandle, this, &AMyActor::ChangeMetallic, MetallicInterval, true);
	GetWorldTimerManager().SetTimer(ColorTimerHandle, this, &AMyActor::ChangeColor, ColorInterval, true);

}

void AMyActor::ChangeMetallic()
{
	if (bChangingMetallic || MetallicChangeCount >= 5)
	{
		GetWorldTimerManager().ClearTimer(MetallicTimerHandle);
		return;
	}

	bChangingMetallic = true;
	MetallicChangeCount++;

	float MetallicValue = StaticMeshComponent1->GetScalarParameterValue(TEXT("Metallic"));
	MetallicValue = (MetallicValue == 0.0f) ? 1.0f : 0.0f;
	StaticMeshComponent1->SetScalarParameterValue(TEXT("Metallic"), MetallicValue);

	bChangingMetallic = false;
}

void AMyActor::ChangeColor()
{
	if (bChangingColor || ColorChangeCount >= 5)
	{
		GetWorldTimerManager().ClearTimer(ColorTimerHandle);
		return;
	}

	bChangingColor = true;
	ColorChangeCount++;

	FLinearColor BaseColorValue = StaticMeshComponent2->GetVectorParameterValue(TEXT("BaseColor"));
	if (BaseColorValue.R == 1.0f)
	{
		BaseColorValue.R = 0.0f;
		BaseColorValue.B = 1.0f;
	}
	else
	{
		BaseColorValue.R = 1.0f;
		BaseColorValue.B = 0.0f;
	}
	StaticMeshComponent2->SetVectorParameterValue(TEXT("BaseColor"), BaseColorValue);

	bChangingColor = false;
}

//Вызывается каждый кадр
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

