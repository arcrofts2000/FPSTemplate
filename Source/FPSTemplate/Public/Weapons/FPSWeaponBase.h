// All Rights Reserved - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSWeaponBase.generated.h"

class USkeletalMeshComponent;

UCLASS()
class FPSTEMPLATE_API AFPSWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AFPSWeaponBase();

	
protected:
	virtual void BeginPlay() override;

	/** Components **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> ThirdPersonMesh;


public:
	/** Getters **/
	UFUNCTION(BlueprintPure, Category = "Weapon|Getter")
	FORCEINLINE USkeletalMeshComponent* GetFirstPersonWeapon() { return FirstPersonMesh; }

	UFUNCTION(BlueprintPure, Category = "Weapon|Getter")
	FORCEINLINE USkeletalMeshComponent* GetThirdPersonWeapon() { return ThirdPersonMesh; }
};
