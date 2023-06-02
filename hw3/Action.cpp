// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "Camera/CameraComponent.h"

Action::Action()
{
     CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
     CameraComponent->bUsePawnControlRotation = true;
    
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("RotateCamera", IE_Pressed, this, &AMyPlayerController::StartRotatingCamera);
    InputComponent->BindAction("RotateCamera", IE_Released, this, &AMyPlayerController::StopRotatingCamera);
}

void AMyPlayerController::StartRotatingCamera()
{
    bRotatingCamera = true;
}

void AMyPlayerController::StopRotatingCamera()
{
    bRotatingCamera = false;
}

void AMyPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (bRotatingCamera && CameraComponent != nullptr)
    {
        float MouseX, MouseY;
        GetInputMouseDelta(MouseX, MouseY);

        const float RotationSpeed = 0.1f;
        AddControllerYawInput(MouseX * RotationSpeed);
        AddControllerPitchInput(MouseY * RotationSpeed);
    }
}
