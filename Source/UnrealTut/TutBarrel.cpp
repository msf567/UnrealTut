// Fill out your copyright notice in the Description page of Project Settings.


#include "TutBarrel.h"

#include "TutProjectile.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ATutBarrel::ATutBarrel()
{
	PrimaryActorTick.bCanEverTick = false;
	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForce"));
	RadialForceComponent->SetupAttachment(RootComponent); // Root == StaticMeshComponent
	RadialForceComponent->Radius = 700.0f;
	RadialForceComponent->ImpulseStrength = 2000.0f;
	RadialForceComponent->bImpulseVelChange = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ATutBarrel::BeginPlay()
{
	Super::BeginPlay();
	MeshComp->OnComponentHit.AddDynamic(this, &ATutBarrel::OnBarrelHit);
}

void ATutBarrel::OnBarrelHit_Implementation(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (ATutProjectile* MagicProjectile = Cast<ATutProjectile>(OtherActor))
	{
		RadialForceComponent->FireImpulse();
	}
}

// Called every frame
void ATutBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

