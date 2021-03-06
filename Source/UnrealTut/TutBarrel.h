// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "TutBarrel.generated.h"
class URadialForceComponent;

UCLASS()
class UNREALTUT_API ATutBarrel : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATutBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
	
	UFUNCTION(BlueprintNativeEvent, Category = "Spells|Exploding Barrel")
		void OnBarrelHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Explosion")
	URadialForceComponent* RadialForceComponent = nullptr;
};
