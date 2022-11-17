#pragma once
#pragma once
#include <Windows.h>

#define OFFSET_UWORLD 0xE075F20

namespace Offsets {


	uintptr_t GameInstance = 0x1a8;
	uintptr_t LocalPlayers = 0x38;
	uintptr_t PlayerController = 0x30;
	uintptr_t LocalPawn = 0x328;

	uintptr_t PlayerState = 0x2a8;
	uintptr_t RootComponent = 0x190;
	uintptr_t Persistentlevel = 0x30;
	uintptr_t TeamIndex = 0x1098;
	uintptr_t AcotrCount = 0xA0;
	uintptr_t AAcotrs = 0x98;
	uintptr_t Mesh = 0x310;
	uintptr_t ReviveFromDBNOTime = 0x4180;
	uintptr_t RelativeLocation = 0x128;
	uintptr_t display_name = 0x90;
	uintptr_t bIsDying = 0x6f8;

	uintptr_t bIsDBNO = 0x782;
	uintptr_t CurrentWeapon = 0x828;
	uintptr_t is_reloading = 0x329;
	uintptr_t CurrWeapon = 0x828;
	uintptr_t weapondata = 0x3f0;
	uintptr_t tier = 0x74;
	//uintptr_t DisplayName = 0xFA8;

	/*uintptr_t CurrentWeapon = 0x790;
	uintptr_t bAlreadySearched = 0xF51;
	uintptr_t WeaponData = 0x3D8;*/
	uintptr_t CurrentActor = 0x8;
	//uintptr_t PrimaryPickupItemEntry = 0x2F8;
	//uintptr_t ItemDefinition = 0x18;
	uintptr_t Velocity = 0x170;
	uintptr_t ComponentToWorld = 0x240;//0x188
	uintptr_t BoneArray = 0x5a0;
	//uintptr_t bIsDying = 0x548;
	//uintptr_t bIsDBNO = 0x572;

}



namespace W2S {
	uintptr_t chain69 = 0xC8;
	uintptr_t chain699 = 0x7D0;
	uintptr_t chain = 0x70;
	uintptr_t chain1 = 0x98;
	uintptr_t chain2 = 0xF8;
	uintptr_t vDelta = 0x20;
	uintptr_t zoom = 0x690;
}