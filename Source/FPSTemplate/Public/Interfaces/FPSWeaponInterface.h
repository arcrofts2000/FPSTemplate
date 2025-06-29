// All Rights Reserved - Adam Crofts

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FPSWeaponInterface.generated.h"

class AFPSWeaponBase;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFPSWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSTEMPLATE_API IFPSWeaponInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void AddWeapon(const TSubclassOf<AFPSWeaponBase>& NewWeapon) = 0;
	virtual void AttachWeaponToMeshes(AFPSWeaponBase* Weapon) = 0;
};
