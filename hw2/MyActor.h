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

protected:
	// Вызывается при запуске игры или при появлении
	virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
        float ColorInterval;

    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties", meta = (AllowPrivateAccess = "true"))
        float MetallicInterval;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
        class UStaticMeshComponent* StaticMeshComponent1;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
        class UStaticMeshComponent* StaticMeshComponent2;

    FTimerHandle MetallicTimerHandle;
    FTimerHandle ColorTimerHandle;

    bool bChangingMetallic;
    bool bChangingColor;

    int32 MetallicChangeCount;
    int32 ColorChangeCount;

    void ChangeMetallic();
    void ChangeColor();

public:	
	// Вызывается каждый кадр
	virtual void Tick(float DeltaTime) override;
};
