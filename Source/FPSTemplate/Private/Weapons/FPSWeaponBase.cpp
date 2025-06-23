// All Rights Reserved - Adam Crofts


#include "Weapons/FPSWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AFPSWeaponBase::AFPSWeaponBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>("First Person Mesh");
	FirstPersonMesh->SetCollisionProfileName("No Collision");
	FirstPersonMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::FirstPerson);
	
	ThirdPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Third Person Mesh");
	ThirdPersonMesh->SetCollisionProfileName("No Collision");
	ThirdPersonMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::WorldSpaceRepresentation);
}

// Called when the game starts or when spawned
void AFPSWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}
