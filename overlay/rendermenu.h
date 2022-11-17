#pragma once
static void DrawESP();
static const char* LineEndPoint[] =
{
	"Head",
	"Foot",

};
static const char* boxStyle[] =
{
	"2D",
	"2D Filled",
	"2D Corner",
	"2D Corner Filled",

};
static const char* linemodes[]
{
	"Bottom",
	"Top",
	"Center"
};
void launchdiscord() {

#include <windows.h>
#include <shellapi.h>

	ShellExecute(0, 0, "https://discord.gg/VWcCwfn6", 0, 0, SW_SHOW);
}
void menu()
{


	
	{
		ImGuiStyle* style = &ImGui::GetStyle();

		ImVec4* colors = style->Colors;

		ImVec4* colorz = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImColor(255, 255, 255);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImColor(33, 36, 43, 255);
		colors[ImGuiCol_ChildBg] = ImColor(33, 36, 43, 255);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImColor(1, 1, 1, 255);
		colors[ImGuiCol_BorderShadow] = ImColor(74, 64, 189);;
		colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
		colors[ImGuiCol_FrameBgHovered] = ImColor(19, 19, 19, 188);
		colors[ImGuiCol_FrameBgActive] = ImColor(19, 19, 19, 188);
		colors[ImGuiCol_TitleBg] = ImColor(51, 56, 69, 255);
		colors[ImGuiCol_TitleBgActive] = ImColor(51, 56, 69, 255);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_ScrollbarGrab] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(19, 19, 19, 180);
		colors[ImGuiCol_ScrollbarGrabActive] = ImColor(19, 19, 19, 180);
		colors[ImGuiCol_CheckMark] = ImColor(130, 0, 0, 255);
		colors[ImGuiCol_SliderGrab] = ImColor(130, 0, 0, 255);
		colors[ImGuiCol_SliderGrabActive] = ImColor(130, 0, 0, 255);
		colors[ImGuiCol_Button] = ImColor(49, 71, 71, 255);
		colors[ImGuiCol_ButtonHovered] = ImColor(45, 60, 81, 255);
		colors[ImGuiCol_ButtonActive] = ImColor(49, 70, 71, 255);
		colors[ImGuiCol_Header] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_HeaderHovered] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_HeaderActive] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_Separator] = ImColor(255, 255, 255, 255);
		colors[ImGuiCol_SeparatorHovered] = ImColor(255, 255, 255, 255);
		colors[ImGuiCol_SeparatorActive] = ImColor(255, 255, 255, 255);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.000f, 1.000f, 0.917f, 1.000f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.000f, 1.000f, 0.917f, 1.000f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.000f, 1.000f, 0.917f, 1.000f);
		colors[ImGuiCol_Tab] = ImColor(47, 45, 45, 255);
		colors[ImGuiCol_TabHovered] = ImColor(255, 255, 255, 255);
		colors[ImGuiCol_TabActive] = ImColor(255, 255, 255, 255);
		colors[ImGuiCol_TabUnfocused] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_TabUnfocusedActive] = ImColor(13, 13, 13, 255);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.000f, 1.000f, 0.917f, 1.000f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.000f, 1.000f, 0.917f, 1.000f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

		ImGuiStyle& Style = ImGui::GetStyle();
		auto Color = Style.Colors;

		Style.WindowBorderSize = 0;

		Style.ChildRounding = 5;
		Style.FrameRounding = 5;
		Style.ScrollbarRounding = 0;
		Style.GrabRounding = 0;
		Style.PopupRounding = 0;
		Style.WindowRounding = 0;
		Style.WindowTitleAlign.x = 0.50f;
		Style.WindowPadding.x = 0.0f;

		float
			TextSpaceLine = 90.f,
			SpaceLineOne = 120.f,
			SpaceLineTwo = 280.f,
			SpaceLineThr = 420.f;

		int current = 1;
		{
			static int lolg = 0;

		


			ImGui::SetNextWindowSize({ 610,350 });
			ImGui::Begin("Polus Solutions | Slotted External 1.0", 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse);




			ImGui::SetCursorPos({ 8.f,30.f });
			////
			if (ImGui::Button((ICON_FA_HOME ""), { 90.f,40.f }))//ICON_FA_SCOPE
			{
				lolg = 0;
			}
			ImGui::SetCursorPosX({ 8.f });
			if (ImGui::Button((ICON_FA_SCOPE), { 90.f,40.f }))
			{
				lolg = 1;
			}
			ImGui::SetCursorPosX({ 8.f });
			if (ImGui::Button((ICON_FA_EYE/*_SLASH*/), { 90.f,40.f }))
			{
				lolg = 2;
			}
			ImGui::SetCursorPosX({ 8.f });
			if (ImGui::Button((ICON_FA_KEYBOARD), { 90.f,40.f }))
			{
				lolg = 3;
			}
			ImGui::SetCursorPosX({ 8.f });
			if (ImGui::Button((ICON_FA_PAINT_BRUSH), { 90.f,40.f }))
			{
				lolg = 4;
			}
			ImGui::SetCursorPosX({ 8.f });

			if (ImGui::Button((ICON_FA_COGS), { 90.f,40.f }))//
			{
				lolg = 5;
			}

			if (lolg == 0)
			{
				ImGui::SetCursorPos({ 250.f,30.f });
				ImGui::TextColored(ImColor(255, 0, 0), "Welcome To Polus Solutions  Slotted");
				ImGui::SetCursorPos({ 180.f,60.f });
				ImGui::TextColored(ImColor(0, 255, 0), "BE: Undetected");
				ImGui::SetCursorPosX({ 180.f });
				ImGui::TextColored(ImColor(0, 255, 0), "EAC: Undetected");
				ImGui::SetCursorPos({ 440.f,250.f });
				if (ImGui::Button(("Discord Sever"), { 134.f,28.f }))
				{
					launchdiscord();
				}
			}
			if (lolg == 1)
			{
				ImGui::SetCursorPos({ 150.f,30.f });
				ImGui::Text(("Aimbot Settings:"));
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("SoftAim"), &Settings::Aimbot);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Hitbox:"));
				ImGui::SameLine();
				ImGui::Checkbox(("Head"), &Settings::Head);

				if (Settings::Head)
				{
					Settings::Neck = false;
					Settings::Chest = false;
					Settings::hitbox = 68;
				}
				ImGui::SameLine();
				ImGui::Checkbox(("Neck"), &Settings::Neck);
				if (Settings::Neck)
				{
					Settings::Head = false;
					Settings::Chest = false;
					Settings::hitbox = 67;
				}
				ImGui::SameLine();
				ImGui::Checkbox(("Pelvis"), &Settings::Chest);
				if (Settings::Chest)
				{
					Settings::Head = false;
					Settings::Neck = false;
					Settings::hitbox = 2;
				}
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Aim Key:"));
				ImGui::SameLine();
				HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Draw Crosshair"), &Settings::Cross_Hair);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Draw Fov Circle"), &Settings::Draw_FOV_Circle);
				if (Settings::Draw_FOV_Circle)
				{
					Settings::SquareFOV = false;
				}

				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Draw Fov Square"), &Settings::SquareFOV);
				if (Settings::SquareFOV)
				{
					Settings::Draw_FOV_Circle = false;
				}
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Aim Line"), &Settings::lockline);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Shape:"));
				ImGui::SameLine();
				ImGui::SliderFloat(("##Shape"), &Settings::Shape, 10, 35);
				ImGui::SetCursorPosX({ 150.f });

				ImGui::Text(("FOV :"));
				ImGui::SameLine();
				ImGui::SliderFloat(("##FOV"), &Settings::AimFOV, 1, 350);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Smoothing :"));
				ImGui::SameLine();
				ImGui::SliderFloat(("##Smoothing"), &Settings::Aim_Speed, 1, 50);
			}
			if (lolg == 2)
			{
				ImGui::SetCursorPos({ 150.f,30.f });
				ImGui::Text(("Visuals:"));
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Box esp"), &Settings::Esp_box);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Corner Box"), &Settings::Esp_Corner_Box);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Skeleton"), &Settings::Esp_skeleton);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Filled Esp"), &Settings::Esp_box_fill);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Outline"), &Settings::outlineesp);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("SpanLines"), &Settings::Esp_line);

				if (Settings::Esp_line)
				{
					ImGui::SetCursorPosX({ 150.f });
					ImGui::Text("Line Type 1:");
					ImGui::SameLine();

					ImGui::Combo(("##Line Start Point"), &Settings::LineStyle, linemodes, sizeof(linemodes) / sizeof(*linemodes));

				}


				if (Settings::Esp_line)
				{
					ImGui::SetCursorPosX({ 150.f });
					ImGui::Text("Line Type 2:");
					ImGui::SameLine();

					ImGui::Combo(("##Line End Point"), &Settings::Endpoint, LineEndPoint, sizeof(LineEndPoint) / sizeof(*LineEndPoint));
				}

				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Distance_Esp"), &Settings::Distance_Esp);

				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Max Distance:"));
				ImGui::SameLine();
				ImGui::SliderFloat(("##Max Distance"), &Settings::VisDist, 0, 500);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Esp Thickness:"));
				ImGui::SameLine();
				ImGui::SliderFloat(("##Max Thickness"), &Settings::Thickness, 0.500, 50);
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Text(("Esp Width:"));
				ImGui::SameLine();
				ImGui::SliderFloat(("##Max width"), &Settings::width, 0.50, 50);
			}
			if (lolg == 4)
			{
				ImGui::SetCursorPos({ 150.f,30.f });
				ImGui::Text(("Colors:"));
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("Visble Check Color "), &Settings::vischeckcolor);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 231, 94, 255), ("[?]"));
				if (ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::Text(("To Use Costum Esp Color trun off this option"));
					ImGui::EndTooltip();
				}
				if (Settings::vischeckcolor)
				{
					ImGui::SetCursorPos({ 150.f,30.f });
					ImGui::ColorEdit3(("Visble Color "), Settings::Visible);
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("Non Visble Color"), Settings::NonVisible);
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("Outline"), Settings::outline5);
				}
				if (!Settings::vischeckcolor)
				{
					ImGui::SetCursorPos({ 150.f,30.f });
					ImGui::ColorEdit3(("2D BOX "), Settings::DBOX);
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("2D Corner Box"), Settings::BoxCornerESP);
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("2D Box  /2D Corner Box Fill"), Settings::DBOXANDCONNERFILL);
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("Snapline "), Settings::LineESP);
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("Skeleton"), Settings::Skeletonchik);
	
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("Snapline "), Settings::LineESP);
			
					ImGui::SetCursorPosX({ 150.f });
					ImGui::ColorEdit3(("Outline"), Settings::outline5);
			
			
				}

			}
			if (lolg == 5)
			{
				ImGui::SetCursorPos({ 150.f,30.f });
				ImGui::Text(("Stream:"));
				ImGui::SetCursorPosX({ 150.f });
				ImGui::Checkbox(("StreamProof"), &Settings::Streamproof);

			}
			ImGui::End();
		}

	}
}

void rendermenu()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		menulogs::showmenu = !menulogs::showmenu;
	}
	if (menulogs::showmenu)
	{
		menu();
	}


	DrawESP();
	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0) {
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}