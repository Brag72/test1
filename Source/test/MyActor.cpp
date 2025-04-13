// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "MyActor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
	IsAlive = true;
	EnemyNum = 0;

	Amplitude = 70.0f;
	Frequency = 4.0f;
}

void AMyActor::SinMovement()
{
	float Result = Frequency * UGameplayStatics::GetTimeSeconds(this);
	float ResultAmplSin = Amplitude * FMath::Sin(Result);
	SetActorLocation(FVector(InitialLocation.X, InitialLocation.Y, InitialLocation.Z + ResultAmplSin));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	InstanceName = GetName();

	InitialLocation = GetActorLocation();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SinMovement();
}

void AMyActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("Instance Name: %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("Enemy num: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}


