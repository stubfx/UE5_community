// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>("ProjectileSceneComponent");
	}
	if (!CollisionComponent)
	{
		// in this case no custom collision component is assigned from the blueprint, and likely never will be.
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

		CollisionComponent->InitSphereRadius(15.f);
		CollisionComponent->SetSimulatePhysics(true);
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		// since nothing has been assigned by the user, we are safe to set this as root of the object.
		RootComponent = CollisionComponent;
	}

	// no one has set the projectile move component, so we do it.
	if(!ProjectileMovementComponent)
	{
		// Use this component to drive this projectile's movement.
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	InitialLifeSpan = 3.f;// last 3 secs.

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Function that initializes the projectile's velocity in the shoot direction.
void AProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}
