//��������� ����������� �� ��������� ������ �� �������� ��������� � ���������� �������.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// ������������� �������� �� ��������� ��� ������� ����� ������
	AMyActor();
	{
		// ������������� ��� ���������
		MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
		SetRootComponent(MeshComponent);
	}
	// ������� BeginPlay, ���������� ��� ������ ����
	void BeginPlay() override
	{
		Super::BeginPlay();
		// ���������� ��������� �� �����
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("�������� �������� �� �����"));
		}
	}
	// ������� Tick, ���������� ������ ����
	void Tick(float DeltaTime) override
	{
		Super::Tick(DeltaTime);
		// ������� ���� � ���������� �������� Verbosity
		UE_LOG(LogTemp, Display, TEXT("��� Display ������ ����"));
		UE_LOG(LogTemp, Warning, TEXT("��� Warning ������ ����"));
		UE_LOG(LogTemp, Error, TEXT("��� Error ������ ����"));
	}

private:
	// ��������� ���� ���������
	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* MeshComponent;
};

protected:
	// ���������� ��� ������� ���� ��� ��� ���������
	virtual void BeginPlay() override;


public:	
	// ���������� ������ ����
	virtual void Tick(float DeltaTime) override;
};
