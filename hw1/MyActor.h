//Заполните уведомление об авторских правах на странице «Описание» в настройках проекта.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Устанавливает значения по умолчанию для свойств этого актера
	AMyActor();
	{
		// Устанавливаем мэш персонажа
		MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
		SetRootComponent(MeshComponent);
	}
	// Функция BeginPlay, вызывается при начале игры
	void BeginPlay() override
	{
		Super::BeginPlay();
		// Добавление персонажа на сцену
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Персонаж добавлен на сцену"));
		}
	}
	// Функция Tick, вызывается каждый кадр
	void Tick(float DeltaTime) override
	{
		Super::Tick(DeltaTime);
		// Выводим логи с различными уровнями Verbosity
		UE_LOG(LogTemp, Display, TEXT("Лог Display каждый кадр"));
		UE_LOG(LogTemp, Warning, TEXT("Лог Warning каждый кадр"));
		UE_LOG(LogTemp, Error, TEXT("Лог Error каждый кадр"));
	}

private:
	// Компонент мэша персонажа
	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* MeshComponent;
};

protected:
	// Вызывается при запуске игры или при появлении
	virtual void BeginPlay() override;


public:	
	// Вызывается каждый кадр
	virtual void Tick(float DeltaTime) override;
};
