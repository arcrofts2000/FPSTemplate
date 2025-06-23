// All Rights Reserved - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/FPSWeaponInterface.h"
#include "FPSCharacter.generated.h"

class AFPSWeaponBase;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class FPSTEMPLATE_API AFPSCharacter : public ACharacter, public IFPSWeaponInterface
{
	GENERATED_BODY()

public:
	AFPSCharacter();

	
protected:
	virtual void BeginPlay() override;

protected:
	/** Sockets **/
	/* 
		These are defined in the Constructor, but made visible for animators to make sure they know the
		correct names to add to Skeletal Meshes.
	*/
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName HeadSocketName;
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName LeftHandSocketName;
	UPROPERTY(VisibleAnywhere, Category = "Sockets")
	FName RightHandSocketName;

	/** Weapon **/
	TObjectPtr<AFPSWeaponBase> CurrentWeapon;

	/** Components **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> FirstPersonCamera;
	

	/** IMC and Input Actions **/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultIMC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Look;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_MouseLook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> Input_Jump;


public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Getters **/
	UFUNCTION(BlueprintPure, Category = "Character|Getters")
	FORCEINLINE USkeletalMeshComponent* GetFirstPersonMesh() { return FirstPersonMesh; }

	UFUNCTION(BlueprintPure, Category = "Character|Getters")
	FORCEINLINE UCameraComponent* GetFirstPersonCamera() { return FirstPersonCamera; }

	UFUNCTION(BlueprintPure, Category = "Character|Getters")
	FORCEINLINE AFPSWeaponBase* GetCurrentWeapon() { return CurrentWeapon; }


public:
	/** Input Functions **/
	void MoveInput(const FInputActionValue& InputValue);

	void LookInput(const FInputActionValue& InputValue);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void TryMove(const float X, const float Y);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void TryLook(const float X, const float Y);


public:
	//~ Begin IFPSWeaponInterface

	UFUNCTION(BlueprintCallable, Category = "Weapon Interface")
	virtual void AddWeapon(const TSubclassOf<AFPSWeaponBase>& NewWeapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon Interface")
	virtual void AttachWeaponToMeshes(AFPSWeaponBase* Weapon);

	//~ End IFPSWeaponInterface
};
