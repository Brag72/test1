// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f,1.0f,1.0f);
	
};

UCLASS()
class TEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintCallable)
	void SinMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();
		
	UPROPERTY(VisibleInstanceOnly)
	FString InstanceName;

	UPROPERTY(EditInstanceOnly)
	int EnemyNum;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive;

	UPROPERTY(EditInstanceOnly)
	float Amplitude;
	UPROPERTY(EditInstanceOnly)
	float Frequency;
	FVector InitialLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

};
