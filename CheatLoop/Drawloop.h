#pragma once
#include "DrawLoopDefines.h"
#include "Offsets.h"

void drawLoop(int width, int height) {


	while (true) {
		std::vector<FNlEntity> tmpList;
		Uworld = read_new<DWORD_PTR>(sdkversion::base + OFFSET_UWORLD);
		std::cout << "Uworld " << Uworld << std::endl;
		DWORD_PTR Gameinstance = read_new<DWORD_PTR>(Uworld + Offsets::GameInstance);
		DWORD_PTR LocalPlayers = read_new<DWORD_PTR>(Gameinstance + Offsets::LocalPlayers);
		Localplayer = read_new<DWORD_PTR>(LocalPlayers);
		PlayerController = read_new<DWORD_PTR>(Localplayer + Offsets::PlayerController);
		LocalPawn = read_new<DWORD_PTR>(PlayerController + Offsets::LocalPawn);
		PlayerState = read_new<DWORD_PTR>(LocalPawn + Offsets::PlayerState);
		Rootcomp = read_new<DWORD_PTR>(LocalPawn + Offsets::RootComponent);
		Persistentlevel = read_new<DWORD_PTR>(Uworld + Offsets::Persistentlevel);
		DWORD ActorCount = read_new<DWORD>(Persistentlevel + Offsets::AcotrCount);
		DWORD_PTR AActors = read_new<DWORD_PTR>(Persistentlevel + Offsets::AAcotrs);
		
		//float Timedilation = read_new<float>(LocalPawn + 0x64);
		//DWORD_PTR uengine = read_new<DWORD_PTR>(0x228);
		//DWORD_PTR UGameUserSettings = read_new<DWORD_PTR>(0x228);
		//uint32_t ResolutionSizeX = read_new<uint32_t>(UGameUserSettings + 0x88);

		for (int i = 0; i < ActorCount; i++) {
			uint64_t CurrentActor = read_new<uint64_t>(AActors + i * 0x8);
			CurrentActorMesh = read_new<uint64_t>(CurrentActor + Offsets::Mesh);
			int curactorid = read_new<int>(CurrentActor + 0x18);
			if (!CurrentActor || CurrentActor == LocalPawn) continue;
			int MyTeamId = read_new<int>(PlayerState + Offsets::TeamIndex);
			DWORD64 otherPlayerState = read_new<uint64_t>(CurrentActor + Offsets::PlayerState);
			int ActorTeamId = read_new<int>(otherPlayerState + Offsets::TeamIndex);
			if (MyTeamId == ActorTeamId) continue;
			int currentitemid = read_new<int>(CurrentActor + 0x18);


			auto player = read_new<float>(CurrentActor + Offsets::ReviveFromDBNOTime);
			if (player == 10) {
				FNlEntity fnlEntity{ };
				fnlEntity.Actor = CurrentActor;
				fnlEntity.mesh = read_new<uint64_t>(CurrentActor + Offsets::Mesh);
				fnlEntity.ID = curactorid;
				tmpList.push_back(fnlEntity);
			}

			


		}
	


		entityList = tmpList;
		Sleep(1);
	}

}
ImColor ESPColor;
void DrawSkeleton(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 98);
	Vector3 vHip = GetBoneWithRotation(mesh, 2);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 10);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 39);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 76);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 69);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 77);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 70);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 73);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 80);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImGui::GetColorU32({ Settings::Skeletonchik[0], Settings::Skeletonchik[1], Settings::Skeletonchik[2], 1.0f }));
}
void DrawSkeleton1(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 98);
	Vector3 vHip = GetBoneWithRotation(mesh, 2);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 10);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 39);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 76);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 69);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 77);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 70);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 73);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 80);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ESPColor);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ESPColor);
}
void DrawESP() {

	ImDrawList* Renderer = ImGui::GetOverlayDrawList();

	Vector3 Head2;


	if (Settings::SquareFOV) {

		int ScreenCenterXPos = (1920 / 2);
		int ScreenCenterYPos = (1080 / 2);

		ImGui::GetOverlayDrawList()->AddRect(ImVec2(ScreenCenterXPos - Settings::AimFOV, ScreenCenterYPos - Settings::AimFOV), ImVec2(ScreenCenterXPos + Settings::AimFOV, ScreenCenterYPos + Settings::AimFOV + Settings::Thickness), ImGui::GetColorU32({ Settings::SQ[0], Settings::SQ[1], Settings::SQ[2], 1.0f }), 1.0f);
	}

	if (Settings::Draw_FOV_Circle) {
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(Settings::AimFOV), ImGui::GetColorU32({ Settings::DrawFOVCircle[0], Settings::DrawFOVCircle[1], Settings::DrawFOVCircle[2], 1.0f }), Settings::Shape);
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(Settings::AimFOV), ImGui::GetColorU32({ Settings::DrawFOVCircle[0], Settings::DrawFOVCircle[1], Settings::DrawFOVCircle[2], 1.0f }), Settings::Shape);
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(Settings::AimFOV), ImGui::GetColorU32({ Settings::DrawFOVCircle[0], Settings::DrawFOVCircle[1], Settings::DrawFOVCircle[2], 1.0f }), Settings::Shape);
	}

	if (Settings::Cross_Hair) {
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 - 11, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImGui::GetColorU32({ Settings::CrossHair[0], Settings::CrossHair[1], Settings::CrossHair[2], 1.0f }), 1.0f);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 + 12, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImGui::GetColorU32({ Settings::CrossHair[0], Settings::CrossHair[1], Settings::CrossHair[2], 1.0f }), 1.0f);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 - 11), ImVec2(Width / 2, Height / 2), ImGui::GetColorU32({ Settings::CrossHair[0], Settings::CrossHair[1], Settings::CrossHair[2], 1.0f }), 1.0f);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 + 12), ImVec2(Width / 2, Height / 2), ImGui::GetColorU32({ Settings::CrossHair[0], Settings::CrossHair[1], Settings::CrossHair[2], 1.0f }), 1.0f);
	}

	if (Settings::Streamproof) {
		SetWindowDisplayAffinity(Window, WDA_EXCLUDEFROMCAPTURE);
	}
	if (!Settings::Streamproof) {
		SetWindowDisplayAffinity(Window, !WDA_EXCLUDEFROMCAPTURE);
	}
	//if (Settings::Cross_Hair) {
	//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 - 11, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImGui::GetColorU32({ 0, 0, 0, 255.f }), 1.0f);
	//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 + 12, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImGui::GetColorU32({ 0, 0, 0, 255.f }), 1.0f);
	//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 - 11), ImVec2(Width / 2, Height / 2), ImGui::GetColorU32({ 0, 0, 0, 255.f }), 1.0f);
	//	ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 + 12), ImVec2(Width / 2, Height / 2), ImGui::GetColorU32({ 0, 0, 0, 255.f }), 1.0f);
	//}



	auto entityListCopy = entityList;
	float closestDistance = FLT_MAX;
	DWORD_PTR closestPawn = NULL;

	DWORD_PTR AActors = read_new<DWORD_PTR>(Ulevel + Offsets::AAcotrs);

	int ActorTeamId = read_new<int>(Offsets::TeamIndex);

	int curactorid = read_new<int>(0x18);


	for (unsigned long i = 0; i < entityListCopy.size(); ++i) {
		FNlEntity entity = entityListCopy[i];

		uint64_t CurrentActor = read_new<uint64_t>(AActors + i * Offsets::CurrentActor);

		uint64_t CurActorRootComponent = read_new<uint64_t>(entity.Actor + Offsets::RootComponent);


		Vector3 RelativeLocation = read_new<Vector3>(CurActorRootComponent + Offsets::RelativeLocation);


		DWORD64 otherPlayerState = read_new<uint64_t>(entity.Actor + Offsets::PlayerState);


		localactorpos = read_new<Vector3>(Rootcomp + Offsets::RelativeLocation);

		Vector3 bone66 = GetBoneWithRotation(entity.mesh, 66);
		Vector3 aimbone = GetBoneWithRotation(entity.mesh, 66);
		Vector3 bone0 = GetBoneWithRotation(entity.mesh, 0);

		Vector3 top = ProjectWorldToScreen(bone66);
		Vector3 chest = ProjectWorldToScreen(bone66);
		Vector3 aimbotspot = ProjectWorldToScreen(aimbone);
		Vector3 bottom = ProjectWorldToScreen(bone0);


		Vector3 Head = ProjectWorldToScreen(Vector3(bone66.x, bone66.y, bone66.z + 15));

		float distance = localactorpos.Distance(bone66) / 100.f;
		float BoxHeight = (float)(Head.y - bottom.y);
		float CornerHeight = abs(Head.y - bottom.y);
		float CornerWidth = BoxHeight * 0.80;
		float Height1 = abs(Head.y - bottom.y);
		float Width1 = Height1 * Settings::width;

		int MyTeamId = read_new<int>(PlayerState + Offsets::TeamIndex);
		int ActorTeamId = read_new<int>(otherPlayerState + Offsets::TeamIndex);
		int curactorid = read_new<int>(CurrentActor + 0x18);
		auto IsVisible1 = isVisible(entity.mesh);
	
	
			if (IsVisible1) { ESPColor = ImGui::GetColorU32({ Settings::Visible[0], Settings::Visible[1], Settings::Visible[2], 1.0f }); }// grreen
			else { ESPColor = ImGui::GetColorU32({ Settings::NonVisible[0], Settings::NonVisible[1], Settings::NonVisible[2], 1.0f }); }//red
		
	



		if (MyTeamId != ActorTeamId) {
			if (distance < Settings::VisDist) {

				if (Settings::Endpoint == 0)//Top of player
				{
					LinePos = Head;
				}
				else if (Settings::Endpoint == 1)//Bottom of player
				{
					LinePos = bottom;
				}


				if (Settings::Esp_line)
				{
					if (Settings::vischeckcolor)// not costum
					{
						if (Settings::LineStyle == 0)///Bottom
						{
							ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, Height - 10), ImVec2(LinePos.x, LinePos.y), ESPColor, Settings::Thickness);
						}
						else if (Settings::LineStyle == 1)///Top
						{
							ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, (Height / 20000) + 10), ImVec2(LinePos.x, LinePos.y), ESPColor, Settings::Thickness);
						}
						else if (Settings::LineStyle == 2)///Center
						{
							ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, Height / 2), ImVec2(LinePos.x, LinePos.y), ESPColor, Settings::Thickness);
						}
					}
					if (!Settings::vischeckcolor)// costum
					{
						if (Settings::LineStyle == 0)///Bottom
						{
							ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, Height - 10), ImVec2(LinePos.x, LinePos.y), ImGui::GetColorU32({ Settings::LineESP[0], Settings::LineESP[1], Settings::LineESP[2], 1.0f }), Settings::Thickness);
						}
						else if (Settings::LineStyle == 1)///Top
						{
							ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, (Height / 20000) + 10), ImVec2(LinePos.x, LinePos.y), ImGui::GetColorU32({ Settings::LineESP[0], Settings::LineESP[1], Settings::LineESP[2], 1.0f }), Settings::Thickness);
						}
						else if (Settings::LineStyle == 2)///Center
						{
							ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, Height / 2), ImVec2(LinePos.x, LinePos.y), ImGui::GetColorU32({ Settings::LineESP[0], Settings::LineESP[1], Settings::LineESP[2], 1.0f }), Settings::Thickness);
						}
					}
				}

				if (Settings::Esp_box)
				{
					if (Settings::vischeckcolor)//not costum
					{
						if (Settings::outlineesp)
						{
							DrawNormalBox(Head.x - Width1 / 2 + 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawNormalBox(Head.x - Width1 / 2 - 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawNormalBox(Head.x - Width1 / 2, Head.y + 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawNormalBox(Head.x - Width1 / 2, Head.y - 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
						}
						if (Settings::Esp_box_fill)
						{
							DrawFilledRect(Head.x - (Width1 / 2), Head.y, Width1, Height1, ImColor(0, 0, 0, 125));
						}
						DrawNormalBox(Head.x - (Width1 / 2), Head.y, Width1, Height1, 1.0f, ESPColor);
					}
					else if (!Settings::vischeckcolor)// costum
					{
						if (Settings::outlineesp)
						{
							DrawNormalBox(Head.x - Width1 / 2 + 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawNormalBox(Head.x - Width1 / 2 - 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawNormalBox(Head.x - Width1 / 2, Head.y + 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawNormalBox(Head.x - Width1 / 2, Head.y - 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
						}
						if (Settings::Esp_box_fill)
						{
							DrawFilledRect(Head.x - (Width1 / 2), Head.y, Width1, Height1, ImGui::GetColorU32({ Settings::DBOXANDCONNERFILL[0], Settings::DBOXANDCONNERFILL[1], Settings::DBOXANDCONNERFILL[2], 1.0f }));
						}
						DrawNormalBox(Head.x - (Width1 / 2), Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::DBOX[0], Settings::DBOX[1], Settings::DBOX[2], 1.0f }));
					}
				}

				if (Settings::Esp_Corner_Box) {
					if (Settings::vischeckcolor)//not costum
					{
						if (Settings::outlineesp)
						{
							DrawCornerBox(Head.x - Width1 / 2 + 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawCornerBox(Head.x - Width1 / 2 - 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawCornerBox(Head.x - Width1 / 2, Head.y + 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawCornerBox(Head.x - Width1 / 2, Head.y - 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
						}
						if (Settings::Esp_box_fill)
						{
							DrawFilledRect(Head.x - (Width1 / 2), Head.y, Width1, Height1, ImColor(0, 0, 0, 125));
						}

						DrawCornerBox(Head.x - (Width1 / 2), Head.y, Width1, Height1, 1.0f, ESPColor);
					}
					else if (!Settings::vischeckcolor)//costum
					{
						if (Settings::outlineesp)
						{
							DrawCornerBox(Head.x - Width1 / 2 + 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawCornerBox(Head.x - Width1 / 2 - 1, Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawCornerBox(Head.x - Width1 / 2, Head.y + 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
							DrawCornerBox(Head.x - Width1 / 2, Head.y - 1, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::outline5[0], Settings::outline5[1], Settings::outline5[2], 1.0f }));
						}
						if (Settings::Esp_box_fill)
						{
							DrawFilledRect(Head.x - (Width1 / 2), Head.y, Width1, Height1, ImGui::GetColorU32({ Settings::DBOXANDCONNERFILL[0], Settings::DBOXANDCONNERFILL[1], Settings::DBOXANDCONNERFILL[2], 1.0f }));
						}

						DrawCornerBox(Head.x - (Width1 / 2), Head.y, Width1, Height1, 1.0f, ImGui::GetColorU32({ Settings::BoxCornerESP[0], Settings::BoxCornerESP[1], Settings::BoxCornerESP[2], 1.0f }));
					}
				}






				if (Settings::Distance_Esp)
				{
					char name[64];
					sprintf_s(name, ("  Dist:%.fm"), distance);
					ShadowRGBText(Head.x - 5, Head.y - 35, ImColor(255, 255, 255, 255), name);

				}


				

					if (Settings::Esp_skeleton) {
						if (Settings::vischeckcolor)// not costum
						{

							DrawSkeleton1(entity.mesh);
						}
						else if (!Settings::vischeckcolor)// not costum
						{

							DrawSkeleton1(entity.mesh);
						}
					}
				

				if (Settings::Aimbot & isVisible(entity.mesh)) {
					auto dx = aimbotspot.x - (Width / 2);
					auto dy = aimbotspot.y - (Height / 2);
					auto dz = aimbotspot.z - (Depth / 2);
					auto dist = sqrtf(dx * dx + dy * dy + dz * dz) / 100.0f;
				
				

						if (dist < Settings::AimFOV && dist < closestDistance) {
							closestDistance = dist;
							closestPawn = entity.Actor;

						}
					
				}
			}
		}
	

	}

	if (Settings::Aimbot) {

		if (closestPawn != 0) {

			if (Settings::Aimbot && closestPawn && GetAsyncKeyState(hotkeys::aimkey) < 0) {
			
				AimAt(closestPawn);


			}
		}
		else {
			isaimbotting = false;

			AimAt2(closestPawn);
		}

	}

	if (Settings::ConstantLock)
	{
		if (closestPawn != 0) {
			if (Settings::ConstantLock && closestPawn) {
				AimAt(closestPawn);
			}
		}
	}
	else
	{
		isaimbotting1 = false;
		AimAt2(closestPawn);
	}





}