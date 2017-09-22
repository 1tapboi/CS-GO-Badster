#include "../Cheat.h"
#include "Menu.h"
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

void GUI_Init(IDirect3DDevice9* pDevice);

void color()
{
	ImGuiIO& io = ImGui::GetIO();

	io.Fonts->Clear();
	io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/Tahoma.ttf", 15.0f);
	io.Fonts->Build();

	ImGuiStyle * style = &ImGui::GetStyle();

	style->WindowMinSize = ImVec2(160, 20);
	style->FramePadding = ImVec2(4, 2);
	style->ItemSpacing = ImVec2(6, 2);
	style->ItemInnerSpacing = ImVec2(6, 4);
	style->Alpha = 0.95f;
	style->WindowRounding = 4.0f;
	style->FrameRounding = 2.0f;
	style->IndentSpacing = 6.0f;
	style->ItemInnerSpacing = ImVec2(2, 4);
	style->ColumnsMinSpacing = 50.0f;
	style->GrabMinSize = 14.0f;
	style->GrabRounding = 16.0f;
	style->ScrollbarSize = 12.0f;
	style->ScrollbarRounding = 16.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
	style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.58f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ComboBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_Column] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
	style->Colors[ImGuiCol_ColumnHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style->Colors[ImGuiCol_ColumnActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_CloseButton] = ImVec4(0.86f, 0.93f, 0.89f, 0.16f);
	style->Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.86f, 0.93f, 0.89f, 0.39f);
	style->Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.92f, 0.18f, 0.29f, 0.43f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.9f);
	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 0.73f);
}

namespace ImGui
{
	static auto vector_getter = [](void* vec, int idx, const char** out_text)
	{
		auto& vector = *static_cast<std::vector<std::string>*>(vec);
		if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
		*out_text = vector.at(idx).c_str();
		return true;
	};

	bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
	{
		if (values.empty()) { return false; }
		return Combo(label, currIndex, vector_getter,
			static_cast<void*>(&values), values.size());
	}

	bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values, int height_in_items = -1)
	{
		if (values.empty()) { return false; }
		return ListBox(label, currIndex, vector_getter,
			static_cast<void*>(&values), values.size(), height_in_items);
	}
}

void RageTab()
{
	ImGui::Checkbox(charenc("[ANTI-UNTRUSTED] Enabled"), &Vars.Ragebot.AntiUntrusted);
	SetTooltip("[WARNING!] ANTI-UNTRUSTED SHUTDOWN CHECKBOX");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Enabled"), &Vars.Ragebot.Enabled);
	SetTooltip("Ragebot Checkbox");
	ImGui::Separator();
	ImGui::Text(charenc("Aimbot"));
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("On Key"), &Vars.Ragebot.OnKey);
		SetTooltip("Shoots on Key when locking to an enemy");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Auto Fire"), &Vars.Ragebot.AutoFire);
		SetTooltip("Automatically shoots when locking to an enemy");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Silent"), &Vars.Ragebot.Silent);
		SetTooltip("Prevents camera from locking to an enemy, doesn't work for demos");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Aim Step"), &Vars.Ragebot.AimStep);
		SetTooltip("Stops you getting VAC Auth kicked in Casual / DM");
		ImGui::Combo(charenc("Key"), &Vars.Ragebot.Key, keyNames, IM_ARRAYSIZE(keyNames));
		SetTooltip("Key Combo");
		ImGui::SliderFloat(charenc("FOV"), &Vars.Ragebot.FOV, 1.f, 180.f, "%.0f");
		SetTooltip("FOV SliderFloat");
		ImGui::Combo(charenc("No Recoil Type"), &Vars.Ragebot.RCS, RcsType, IM_ARRAYSIZE(RcsType));
		SetTooltip("No Recoil Type Combo");
		ImGui::SliderFloat(charenc("No Recoil Amount"), &Vars.Ragebot.RCShow, 1.f, 100.f, "%.0f");
		SetTooltip("No Recoil SliderFloat");
		ImGui::SliderFloat(charenc("Angel Tick Amount"), &Vars.Ragebot.AimStepAmount, 1.f, 180.f, "%.0f");
		SetTooltip("Aim Step Angel Tick SliderFloat");
	}
	ImGui::NextColumn();
	{
		ImGui::Checkbox(charenc("Friendly Fire"), &Vars.Ragebot.FriendlyFire);
		SetTooltip("Whether to target Friendlies");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Auto Wall"), &Vars.Ragebot.AutoWall);
		SetTooltip("Shoots enemy through a wall if it does X amount of damage");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Hitscan"), &Vars.Ragebot.Hitscan);
		SetTooltip("Hitscan Checkbox");
		ImGui::Combo(charenc("Hitbox"), &Vars.Ragebot.Hitbox, aimBones, IM_ARRAYSIZE(aimBones));
		SetTooltip("Hitbox Combo");
		ImGui::Combo(charenc("Mode"), &Vars.Ragebot.Mode, targetMode, IM_ARRAYSIZE(targetMode));
		SetTooltip("Mode Combo");
		ImGui::SliderFloat(charenc("Damage Amount"), &Vars.Ragebot.AutoWallAmount, 0.1f, 100.f, "%.1f");
		SetTooltip("Damage SliderFloat");
		ImGui::Checkbox(charenc("[Hitscan] Normal (Bone)"), &Vars.Ragebot.HitscanHitbox);
		SetTooltip("Hitscan on Bone");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("[Hitscan] Low (Body)"), &Vars.Ragebot.HitscanAll);
		SetTooltip("Hitscan on Body");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("[Hitscan] High (Headshot)"), &Vars.Ragebot.HitscanHeadshot);
		SetTooltip("Hitscan on Headshot");
	}
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Checkbox(charenc("Hitchance"), &Vars.Ragebot.Hitchance);
	SetTooltip("Enabled Hitchance Checkbox");
	ImGui::SliderFloat(charenc("Hitchance Amount"), &Vars.Ragebot.HitchanceAmount, 1.f, 100.f, "%.1f");
	SetTooltip("Hitchance SliderFloat");
	ImGui::Separator();
	ImGui::Text(charenc("Accuracy"));
	ImGui::Separator();
	
	ImGui::Checkbox(charenc("Auto Crouch"), &Vars.Ragebot.AutoCrouch);
	SetTooltip("Auto Crouch when an enemy is in sight");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Auto Stop"), &Vars.Ragebot.AutoStop);
	SetTooltip("Auto Stop when an enemy is in sight");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Auto Scope"), &Vars.Ragebot.AutoScope);
	SetTooltip("Automatically Scopes weapons that have them");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Fast Auto Stop"), &Vars.Ragebot.AutoStopFast);
	SetTooltip("Fast Auto Stop when an enemy is in sight");
	ImGui::SameLine();
    ImGui::Checkbox(charenc("Auto Stop Until Can Shoot"), &Vars.Ragebot.AutoStopCanShoot);
	SetTooltip("Auto Stop Until Can Shoot");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Shoot When Stopped"), &Vars.Ragebot.ShootWhenStopped);
	SetTooltip("Shoot When Stopped");
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text(charenc("Anti-Aim"));
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("Anti-Aim On"), &Vars.Ragebot.Antiaim.Enabled);
		SetTooltip("Enabled Anti-Aim Checkbox");
		ImGui::Separator();
		ImGui::Checkbox(charenc("At Target"), &Vars.Ragebot.Antiaim.AtPlayer);
		SetTooltip("At Target Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Position Adjusment"), &Vars.Ragebot.Antiaim.PositionAdjusment);
		SetTooltip("Position Adjusment Checkbox");
		ImGui::Checkbox(charenc("Fake Y"), &Vars.Ragebot.Antiaim.FakeYaw);
		SetTooltip("Fake Y Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Resolver"), &Vars.Ragebot.Antiaim.Resolver);
		SetTooltip("Resolves all players on server");
		ImGui::Combo(charenc("P"), &Vars.Ragebot.Antiaim.Pitch, antiaimpitch, IM_ARRAYSIZE(antiaimpitch));
		SetTooltip("Enables Anti-Aim P Combo");
		ImGui::Combo(charenc("Y"), &Vars.Ragebot.Antiaim.YawReal, antiaimyaw, IM_ARRAYSIZE(antiaimyaw));
		SetTooltip("Enables Anti-Aim Y Combo");
		ImGui::Combo(charenc("Fake Y"), &Vars.Ragebot.Antiaim.YawFake, antiaimyaw, IM_ARRAYSIZE(antiaimyaw));
		SetTooltip("Anti-Aim Fake Y Combo");
		//ImGui::Combo(charenc("Zeta"), &Vars.Ragebot.Antiaim.Zeta, antiaimzeta, IM_ARRAYSIZE(antiaimzeta));
		//SetTooltip("Anti-Aim Zeta Combo");
		ImGui::NextColumn();
		ImGui::Checkbox(charenc("Custom Jitter"), &Vars.Ragebot.Antiaim.CustomJitter);
		SetTooltip("Custom Jitter Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Anti-Resolver"), &Vars.Ragebot.Antiaim.AntiResolver);
		SetTooltip("Simple resolver prevention");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Wall Detection"), &Vars.Ragebot.Antiaim.WallDetection);
		SetTooltip("Wall Detection Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Edge"), &Vars.Ragebot.Antiaim.Edge);
		SetTooltip("Aims your head into the closest wall");
		ImGui::SliderInt(charenc("Edge Distance"), &Vars.Ragebot.Antiaim.EdgeDistance, 1, 30);
		SetTooltip("Edge Distance SliderInt");
		ImGui::SliderInt(charenc("Spinbot Speed Amount"), &Vars.Ragebot.Antiaim.SpinbotSpeed, 1, 1000);
		SetTooltip("Spinbot Speed SliderInt");
		ImGui::SliderInt(charenc("Fake Spinbot Speed Amount"), &Vars.Ragebot.Antiaim.FakeSpinbotSpeed, 1, 1000);
		SetTooltip("Fake Spinbot Speed SliderInt");
	}
	ImGui::NextColumn();
	{
		bool unt = Vars.Ragebot.Antiaim.CustomJitter;
		if (unt)
		{
			ImGui::Checkbox(charenc("Enabled Custom Jitter P Checkbox"), &Vars.Ragebot.Antiaim.PitchCustom);
			SetTooltip("Enables Custom Jitter P Checkbox");
			ImGui::SliderFloat(charenc("Custom Jitter P"), &Vars.Ragebot.Antiaim.PCReal, unt ? -89 : -180, unt ? 89 : 180);
			SetTooltip("Custom Jitter P Amount");
			ImGui::SliderFloat(charenc("Custom Jitter Fake P"), &Vars.Ragebot.Antiaim.PCFake, unt ? -89 : -180, unt ? 89 : 180);
			SetTooltip("Custom Jitter Fake P Amount");
			ImGui::Checkbox(charenc("Enabled Custom Jitter Y Checkbox"), &Vars.Ragebot.Antiaim.YawCustom);
			SetTooltip("Enables Custom Jitter Y Checkbox");
			ImGui::SliderFloat(charenc("Custom Jitter Y"), &Vars.Ragebot.Antiaim.YCReal, unt ? -179 : -360, unt ? 179 : 360);
			SetTooltip("Custom Jitter Y Amount");
			ImGui::SliderFloat(charenc("Custom Jitter Fake Y"), &Vars.Ragebot.Antiaim.YCFake, unt ? -179 : -360, unt ? 179 : 360);
			SetTooltip("Custom Jitter Fake Y Amount");
		}
	}
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text("Disable on");
	ImGui::Separator();
	ImGui::Checkbox("Knife", &Vars.Ragebot.Antiaim.Knife);
	SetTooltip("Stops your Anti-Aim while you have your knife out.");
	ImGui::SameLine();
	ImGui::Checkbox("No Enemy", &Vars.Ragebot.Antiaim.NoEnemy);
	SetTooltip("Stops your Anti-Aim when there are no enemies visible.");

	ImGui::Separator();
	ImGui::Text(charenc("Hitscan Bone"));
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox("Head", &Vars.Ragebot.bones[HITBOX_HEAD]);
		SetTooltip("Hitscan on Head");
		ImGui::SameLine();
		ImGui::Checkbox("Neck", &Vars.Ragebot.bones[HITBOX_NECK]);
		SetTooltip("Hitscan on Neck");
		ImGui::SameLine();
		ImGui::Checkbox("Pelvis", &Vars.Ragebot.bones[HITBOX_PELVIS]);
		SetTooltip("Hitscan on Pelvis");
		ImGui::SameLine();
		ImGui::Checkbox("Spine", &Vars.Ragebot.bones[HITBOX_SPINE]);
		SetTooltip("Hitscan on Spine");
		ImGui::SameLine();
		ImGui::Checkbox("Leg", &Vars.Ragebot.bones[HITBOX_LEGS]);
		SetTooltip("Hitscan on Leg");
		ImGui::SameLine();
		ImGui::Checkbox("Arm", &Vars.Ragebot.bones[HITBOX_ARMS]);
		SetTooltip("Hitscan on Arm");
	}
	ImGui::Columns(1);
	ImGui::Separator();
}

void LegitTab()
{
	ImGui::Text(charenc("Aimbot"));
	ImGui::Separator();
	ImGui::Checkbox(charenc("Enabled"), &Vars.Legitbot.Aimbot.Enabled);
	SetTooltip("Aimbot Checkbox");
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		//ImGui::Checkbox(charenc("Ignore Key"), &Vars.Legitbot.Aimbot.AlwaysOn);
		//SetTooltip("Ignore Key Checkbox");
		ImGui::Checkbox(charenc("Aim on Key"), &Vars.Legitbot.Aimbot.OnKey);
		SetTooltip("Aim on Key Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Friendly Fire"), &Vars.Legitbot.Aimbot.FriendlyFire);
		SetTooltip("Friendly Fire Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Kill Stop"), &Vars.Legitbot.Aimbot.KillStop);
		SetTooltip("Kill Stop Checkbox");
		
		ImGui::Checkbox(charenc("Flash Check"), &Vars.Legitbot.Aimbot.FlashCkeck);
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Smoke Check"), &Vars.Legitbot.Aimbot.SmokeCheck);
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Kill Stop Delay"), &Vars.Legitbot.Aimbot.KillStopDelay);
		ImGui::SliderFloat(charenc("Kill Stop Delay Amount"), &Vars.Legitbot.Aimbot.KillStopDelayA, 0.f, 2000.f, "%.2f");

		ImGui::Combo(charenc("Aimbot Key"), &Vars.Legitbot.Aimbot.Key, keyNames, IM_ARRAYSIZE(keyNames));
		SetTooltip("Aimbot Key Combo");
		ImGui::Combo(charenc("Weapon Group"), &Vars.Legitbot.Aimbot.Group, wepGroups, IM_ARRAYSIZE(wepGroups));
		SetTooltip("Weapon Group Combo");
		switch (Vars.Legitbot.Aimbot.Group)
		{
		case 0:
			ImGui::SliderFloat(charenc("FOV Amount"), &Vars.Legitbot.pistols.FOV, 0.1f, 50.f, "%.2f");
			SetTooltip("FOV SliderFloat");
			ImGui::SliderFloat(charenc("Smooth Amount"), &Vars.Legitbot.pistols.Speed, 0.1f, 25000.f, "%.2f");
			SetTooltip("Smoothing reduces Aimbot \"snap\". 0 for full Snap. 1 for full Smoothing");
			ImGui::SameLine();
			ImGui::Checkbox(charenc("PSilent"), &Vars.Legitbot.pistols.pSilent);
			ImGui::SliderFloat(charenc("Delay Amount"), &Vars.Legitbot.pistols.Delay, 1.f, 500.f, "%.0f");
			SetTooltip("Delay SliderFloat");
			ImGui::SliderInt(charenc("Hitbox"), &Vars.Legitbot.pistols.Hitbox, 3.f, 8.f, "%.0f");
			SetTooltip("Hitbox SliderInt");
			ImGui::Checkbox(charenc("RCS Enabled"), &Vars.Legitbot.pistols.RCSEnabled);
			SetTooltip("Automatically Recoil Conrtol System");
			ImGui::SliderFloat(charenc("RCS Y Amount"), &Vars.Legitbot.pistols.RCSAmountY, 1.f, 100.f, "%.0f");
			SetTooltip("RCS Y SliderFloat");
			ImGui::SliderFloat(charenc("RCS X Amount"), &Vars.Legitbot.pistols.RCSAmountX, 1.f, 100.f, "%.0f");
			SetTooltip("RCS X SliderFloat");
			break;
		case 1:
			ImGui::SliderFloat(charenc("FOV Amount"), &Vars.Legitbot.rifles.FOV, 0.1f, 50.f, "%.2f");
			SetTooltip("FOV SliderFloat");
			ImGui::SliderFloat(charenc("Smooth Amount"), &Vars.Legitbot.rifles.Speed, 0.1f, 500.f, "%.2f");
			SetTooltip("Smoothing reduces Aimbot \"snap\". 0 for full Snap. 1 for full Smoothing");
			ImGui::SliderFloat(charenc("Delay Amount"), &Vars.Legitbot.rifles.Delay, 1.f, 500.f, "%.0f");
			SetTooltip("Delay SliderFloat");
			ImGui::SliderFloat(charenc("Time (Aimbot) Amount"), &Vars.Legitbot.rifles.Time, 0.0f, 5.f, "%.0f");
			SetTooltip("Time SliderFloat");
			ImGui::SliderInt(charenc("Hitbox"), &Vars.Legitbot.rifles.Hitbox, 3.f, 8.f, "%.0f");
			SetTooltip("Hitbox SliderInt");
			ImGui::SameLine();
			ImGui::Checkbox(charenc("Nearest (Hitbox)"), &Vars.Legitbot.rifles.Nearest);
			SetTooltip("Nearest Checkbox");
			ImGui::Checkbox(charenc("RCS Enabled"), &Vars.Legitbot.rifles.RCSEnabled);
			SetTooltip("Automatically Recoil Conrtol System");
			ImGui::SliderFloat(charenc("RCS Y Amount"), &Vars.Legitbot.rifles.RCSAmountY, 1.f, 100.f, "%.0f");
			SetTooltip("RCS Y SliderFloat");
			ImGui::SliderFloat(charenc("RCS X Amount"), &Vars.Legitbot.rifles.RCSAmountX, 1.f, 100.f, "%.0f");
			SetTooltip("RCS X SliderFloat");
			break;
		case 2:
			ImGui::SliderFloat(charenc("FOV Amount"), &Vars.Legitbot.smg.FOV, 0.1f, 50.f, "%.2f");
			SetTooltip("FOV SliderFloat");
			ImGui::SliderFloat(charenc("Smooth Amount"), &Vars.Legitbot.smg.Speed, 0.1f, 500.f, "%.2f");
			SetTooltip("Smoothing reduces Aimbot \"snap\". 0 for full Snap. 1 for full Smoothing");
			ImGui::SliderFloat(charenc("Delay Amount"), &Vars.Legitbot.smg.Delay, 1.f, 500.f, "%.0f");
			SetTooltip("Delay SliderFloat");
			ImGui::SliderFloat(charenc("Time (Aimbot) Amount"), &Vars.Legitbot.smg.Time, 0.0f, 5.f, "%.0f");
			SetTooltip("Time SliderFloat");
			ImGui::SliderInt(charenc("Hitbox"), &Vars.Legitbot.smg.Hitbox, 3.f, 8.f, "%.0f");
			SetTooltip("Hitbox SliderInt");
			ImGui::SameLine();
			ImGui::Checkbox(charenc("Nearest (Hitbox)"), &Vars.Legitbot.smg.Nearest);
			SetTooltip("Nearest Checkbox");
			ImGui::Checkbox(charenc("RCS Enabled"), &Vars.Legitbot.smg.RCSEnabled);
			SetTooltip("Automatically Recoil Conrtol System");
			ImGui::SliderFloat(charenc("RCS Y Amount"), &Vars.Legitbot.smg.RCSAmountY, 1.f, 100.f, "%.0f");
			SetTooltip("RCS Y SliderFloat");
			ImGui::SliderFloat(charenc("RCS X Amount"), &Vars.Legitbot.smg.RCSAmountX, 1.f, 100.f, "%.0f");
			SetTooltip("RCS X SliderFloat");
			break;
		case 3:
			ImGui::SliderFloat(charenc("FOV Amount"), &Vars.Legitbot.shotguns.FOV, 0.1f, 50.f, "%.2f");
			SetTooltip("FOV SliderFloat");
			ImGui::SliderFloat(charenc("Smooth Amount"), &Vars.Legitbot.shotguns.Speed, 0.1f, 5000.f, "%.2f");
			SetTooltip("Smoothing reduces Aimbot \"snap\". 0 for full Snap. 1 for full Smoothing");
			ImGui::SliderFloat(charenc("Delay Amount"), &Vars.Legitbot.shotguns.Delay, 1.f, 500.f, "%.0f");
			SetTooltip("Delay SliderFloat");
			ImGui::SliderInt(charenc("Hitbox"), &Vars.Legitbot.shotguns.Hitbox, 3.f, 8.f, "%.0f");
			SetTooltip("Hitbox SliderInt");
			break;
		case 4:
			ImGui::SliderFloat(charenc("FOV Amount"), &Vars.Legitbot.snipers.FOV, 0.1f, 50.f, "%.2f");
			SetTooltip("FOV SliderFloat");
			ImGui::SliderFloat(charenc("Smooth Amount"), &Vars.Legitbot.snipers.Speed, 0.1f, 25000.f, "%.2f");
			SetTooltip("Smoothing reduces Aimbot \"snap\". 0 for full Snap. 1 for full Smoothing");
			ImGui::SameLine();
			ImGui::Checkbox(charenc("PSilent"), &Vars.Legitbot.snipers.pSilent);
			ImGui::SliderFloat(charenc("Delay Amount"), &Vars.Legitbot.snipers.Delay, 1.f, 500.f, "%.0f");
			SetTooltip("Delay SliderFloat");
			ImGui::SliderInt(charenc("Hitbox"), &Vars.Legitbot.snipers.Hitbox, 3.f, 8.f, "%.0f");
			SetTooltip("Hitbox SliderInt");
			ImGui::SameLine();
			ImGui::Checkbox(charenc("Nearest (Hitbox)"), &Vars.Legitbot.snipers.Nearest);
			SetTooltip("Nearest Checkbox");
			ImGui::Checkbox(charenc("Stop Zoom"), &Vars.Legitbot.snipers.StopZoom);
			ImGui::SameLine();
			ImGui::Checkbox(charenc("Fast Zoom"), &Vars.Legitbot.snipers.FastZoom);
			if (Vars.Legitbot.snipers.FastZoom)
			{
				ImGui::SliderFloat(charenc("FOV Zoom"), &Vars.Legitbot.snipers.FOVZoom, 0.1f, 10.f, "%.2f");
			}
			break;
		}
	}
	ImGui::NextColumn();
	{
		ImGui::Checkbox(charenc("Triggerbot on Key"), &Vars.Legitbot.Triggerbot.Enabled);
		SetTooltip("Triggerbot on Key Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Auto Fire"), &Vars.Legitbot.Triggerbot.AutoFire);
		SetTooltip("Adds a Delay to Triggerbot");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Auto Wall"), &Vars.Legitbot.Triggerbot.AutoWall);
		SetTooltip("Triggerbot through Walls");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Hitchance"), &Vars.Legitbot.Triggerbot.HitChance);
		SetTooltip("Hitchance Checkbox");
		ImGui::Combo(charenc("Triggerbot Key"), &Vars.Legitbot.Triggerbot.Key, keyNames, IM_ARRAYSIZE(keyNames));
		SetTooltip("Triggerbot Key Combo");
		ImGui::SliderFloat(charenc("Hitchance Amount"), &Vars.Legitbot.Triggerbot.HitChanceAmount, 1.f, 100.f, "%.0f");
		SetTooltip("Hitchance SliderFloat");
		ImGui::Separator();
		ImGui::Checkbox(charenc("Triggerbot On Teammates"), &Vars.Legitbot.Triggerbot.Filter.Friendly);
	    SetTooltip("Triggerbot on Teammates");
	    ImGui::Checkbox(charenc("Triggerbot On Head"), &Vars.Legitbot.Triggerbot.Filter.Head);
		SetTooltip("Triggerbot on Head");
		ImGui::Checkbox(charenc("Triggerbot On Chest"), &Vars.Legitbot.Triggerbot.Filter.Chest);
		SetTooltip("Triggerbot on Chest");
		ImGui::Checkbox(charenc("Triggerbot On Stomach"), &Vars.Legitbot.Triggerbot.Filter.Stomach);
		SetTooltip("Triggerbot on Stomach");
		ImGui::Checkbox(charenc("Triggerbot On Arm"), &Vars.Legitbot.Triggerbot.Filter.Arms);
		SetTooltip("Triggerbot on Arm");
		ImGui::Checkbox(charenc("Triggerbot On Leg"), &Vars.Legitbot.Triggerbot.Filter.Legs);
		SetTooltip("Triggerbot on Leg");

	}
	ImGui::Columns(1);
	ImGui::Separator();
}

void VisualsTab()
{
	ImGui::Text(charenc("Watermark"));
	ImGui::Separator();
	ImGui::Checkbox(charenc("On"), &Vars.Visuals.Watermark);
	SetTooltip("Watermark Checkbox");
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text(charenc("Visuals"));
	ImGui::Separator();
	ImGui::Checkbox(charenc("Enabled"), &Vars.Visuals.Enabled);
	SetTooltip("Visuals Checkbox");
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("Flat 2D"), &Vars.Visuals.Box2D);
		SetTooltip("Outline players with a Box");
		ImGui::Checkbox(charenc("Box 3D"), &Vars.Visuals.Box3D);
		SetTooltip("3D Box Checkbox");
		ImGui::Checkbox(charenc("Skeleton"), &Vars.Visuals.Skeleton);
		SetTooltip("Show a players Skeleton");
		ImGui::Checkbox(charenc("FOV Circle "), &Vars.Visuals.FOVCircle);
		SetTooltip("Show circle around Aimbot FOV");
		ImGui::Checkbox(charenc("Spectators Tab"), &Vars.Visuals.SpectatorsTab);
		SetTooltip("Spectators Tab Checkbox");
	}
	ImGui::NextColumn();
	{
		//ImGui::Checkbox(charenc("No Weapon"), &Vars.Visuals.RemovalsWeapon);
		//SetTooltip("No Weapon Checkbox");
		ImGui::Checkbox(charenc("No Hands"), &Vars.Visuals.RemovalsHands);
		SetTooltip("No Hands Checkbox");
		ImGui::Checkbox(charenc("No Flash"), &Vars.Visuals.RemovalsFlash);
		SetTooltip("No Flash Checkbox");
		//ImGui::Checkbox(charenc("No Smoke"), &Vars.Visuals.RemovalsSmoke);
		//SetTooltip("No Smoke Checkbox");
		ImGui::Checkbox(charenc("Tracers"), &Vars.Visuals.Tracers);
		SetTooltip("Draws a line to each player");
		ImGui::Checkbox(charenc("Bullet Tracers"), &Vars.Visuals.BulletTrace);
		SetTooltip("Bullet Tracers Checkbox");
		ImGui::SliderFloat(charenc("Trace Length"), &Vars.Visuals.BulletTraceLength, 1.f, 3000.f, "%.0f");
		SetTooltip("Trace Length SliderFloat");
	}
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Combo(charenc("Colours 2D Box Visible"), &Vars.Visuals.colorsV2D, colors, IM_ARRAYSIZE(colors));
		SetTooltip("Colours 2D Box");
		switch (Vars.Visuals.colorsV2D)
		{
		case 0:
			Vars.Visuals.colV2D.r = 5;
			Vars.Visuals.colV2D.g = 200;
			Vars.Visuals.colV2D.b = 5;
			break;
		case 1:			// Black
			Vars.Visuals.colV2D.r = 0;
			Vars.Visuals.colV2D.g = 0;
			Vars.Visuals.colV2D.b = 0;
			break;
		case 2:			// White
			Vars.Visuals.colV2D.r = 255;
			Vars.Visuals.colV2D.g = 255;
			Vars.Visuals.colV2D.b = 255;
			break;
		case 3:			// Grey
			Vars.Visuals.colV2D.r = 128;
			Vars.Visuals.colV2D.g = 128;
			Vars.Visuals.colV2D.b = 128;
			break;
		case 4:			// Violet
			Vars.Visuals.colV2D.r = 238;
			Vars.Visuals.colV2D.g = 130;
			Vars.Visuals.colV2D.b = 238;
			break;
		case 5:			// Pink
			Vars.Visuals.colV2D.r = 255;
			Vars.Visuals.colV2D.g = 192;
			Vars.Visuals.colV2D.b = 203;
			break;
		case 6:			// Brown
			Vars.Visuals.colV2D.r = 165;
			Vars.Visuals.colV2D.g = 42;
			Vars.Visuals.colV2D.b = 42;
			break;
		case 7:			// Purple
			Vars.Visuals.colV2D.r = 128;
			Vars.Visuals.colV2D.g = 0;
			Vars.Visuals.colV2D.b = 128;
			break;
		case 8:			// Orange
			Vars.Visuals.colV2D.r = 255;
			Vars.Visuals.colV2D.g = 165;
			Vars.Visuals.colV2D.b = 0;
			break;
		case 9:			// Red
			Vars.Visuals.colV2D.r = 255;
			Vars.Visuals.colV2D.g = 0;
			Vars.Visuals.colV2D.b = 0;
			break;
		case 10:		// Blue
			Vars.Visuals.colV2D.r = 0;
			Vars.Visuals.colV2D.g = 0;
			Vars.Visuals.colV2D.b = 255;
			break;
		case 11:		// Green
			Vars.Visuals.colV2D.r = 0;
			Vars.Visuals.colV2D.g = 255;
			Vars.Visuals.colV2D.b = 0;
			break;
		case 12:		// Yellow
			Vars.Visuals.colV2D.r = 255;
			Vars.Visuals.colV2D.g = 255;
			Vars.Visuals.colV2D.b = 0;
			break;
		case 13:		// Custom
			ImGui::SliderInt(charenc("Red"), &Vars.Visuals.colV2D.r, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Green"), &Vars.Visuals.colV2D.g, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Blue"), &Vars.Visuals.colV2D.b, 0.f, 255.f, "%.0f");
			break;
		}
	}
	ImGui::NextColumn();
	{
		ImGui::Combo(charenc("Colours 2D Box Not Visible"), &Vars.Visuals.colorsNV2D, colors, IM_ARRAYSIZE(colors));
		SetTooltip("Colours 2D BOX");
		switch (Vars.Visuals.colorsNV2D)
		{
		case 0:
			Vars.Visuals.colNV2D.r = 200;
			Vars.Visuals.colNV2D.g = 5;
			Vars.Visuals.colNV2D.b = 5;
		case 1:			// Black
			Vars.Visuals.colNV2D.r = 0;
			Vars.Visuals.colNV2D.g = 0;
			Vars.Visuals.colNV2D.b = 0;
			break;
		case 2:			// White
			Vars.Visuals.colNV2D.r = 255;
			Vars.Visuals.colNV2D.g = 255;
			Vars.Visuals.colNV2D.b = 255;
			break;
		case 3:			// Grey
			Vars.Visuals.colNV2D.r = 128;
			Vars.Visuals.colNV2D.g = 128;
			Vars.Visuals.colNV2D.b = 128;
			break;
		case 4:			// Violet
			Vars.Visuals.colNV2D.r = 238;
			Vars.Visuals.colNV2D.g = 130;
			Vars.Visuals.colNV2D.b = 238;
			break;
		case 5:			// Pink
			Vars.Visuals.colNV2D.r = 255;
			Vars.Visuals.colNV2D.g = 192;
			Vars.Visuals.colNV2D.b = 203;
			break;
		case 6:			// Brown
			Vars.Visuals.colNV2D.r = 165;
			Vars.Visuals.colNV2D.g = 42;
			Vars.Visuals.colNV2D.b = 42;
			break;
		case 7:			// Purple
			Vars.Visuals.colNV2D.r = 128;
			Vars.Visuals.colNV2D.g = 0;
			Vars.Visuals.colNV2D.b = 128;
			break;
		case 8:			// Orange
			Vars.Visuals.colNV2D.r = 255;
			Vars.Visuals.colNV2D.g = 165;
			Vars.Visuals.colNV2D.b = 0;
			break;
		case 9:			// Red
			Vars.Visuals.colNV2D.r = 255;
			Vars.Visuals.colNV2D.g = 0;
			Vars.Visuals.colNV2D.b = 0;
			break;
		case 10:		// Blue
			Vars.Visuals.colNV2D.r = 0;
			Vars.Visuals.colNV2D.g = 0;
			Vars.Visuals.colNV2D.b = 255;
			break;
		case 11:		// Green
			Vars.Visuals.colNV2D.r = 0;
			Vars.Visuals.colNV2D.g = 255;
			Vars.Visuals.colNV2D.b = 0;
			break;
		case 12:		// Yellow
			Vars.Visuals.colNV2D.r = 255;
			Vars.Visuals.colNV2D.g = 255;
			Vars.Visuals.colNV2D.b = 0;
			break;
		case 13:		// Custom
			ImGui::SliderInt(charenc("Red"), &Vars.Visuals.colNV2D.r, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Green"), &Vars.Visuals.colNV2D.g, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Blue"), &Vars.Visuals.colNV2D.b, 0.f, 255.f, "%.0f");
			break;
		}
	}
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text(charenc("Visuals Settings"));
	ImGui::Separator();

	ImGui::Columns(2, NULL, true);
	{

		ImGui::Checkbox(charenc("Show Name"), &Vars.Visuals.InfoName);
		SetTooltip("Show Name");
		ImGui::Checkbox(charenc("Show Health"), &Vars.Visuals.InfoHealth);
		SetTooltip("Show Health");
		ImGui::Checkbox(charenc("Show Armor"), &Vars.Visuals.InfoArmor);
		SetTooltip("Show Armor");
		ImGui::Checkbox(charenc("Show Weapon"), &Vars.Visuals.InfoWeapon);
		SetTooltip("Show held Weapon");
		ImGui::Checkbox(charenc("Show If Flashed"), &Vars.Visuals.InfoFlashed);
		SetTooltip("Show whether they are Flashed");

	}
	ImGui::NextColumn();
	{


		ImGui::Checkbox(charenc("Show Teammates"), &Vars.Visuals.Filter.Friendlies);
		SetTooltip("Show Teammates");
		ImGui::Checkbox(charenc("Show Weapons"), &Vars.Visuals.Filter.Weapons);
		SetTooltip("Show Weapons on floor");
		ImGui::Checkbox(charenc("Show Decoy"), &Vars.Visuals.Filter.Decoy);
		SetTooltip("Show Decoy");
		ImGui::Checkbox(charenc("Show Bomb"), &Vars.Visuals.Filter.C4);
		SetTooltip("Show Bomb when planted");

	}


	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text(charenc("Misc Functions"));
	ImGui::Separator();
	ImGui::Checkbox(charenc("Chams On"), &Vars.Visuals.Chams.Enabled);
	SetTooltip("Change Players, Model Texture");
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Combo(charenc("Colours Chams Visible"), &Vars.Visuals.colorsV, colors, IM_ARRAYSIZE(colors));
		SetTooltip("Colours Chams");
		switch (Vars.Visuals.colorsV)
		{
		case 0:
			Vars.Visuals.colV.r = 5;
			Vars.Visuals.colV.g = 200;
			Vars.Visuals.colV.b = 5;
			break;
		case 1:			// Black
			Vars.Visuals.colV.r = 0;
			Vars.Visuals.colV.g = 0;
			Vars.Visuals.colV.b = 0;
			break;
		case 2:			// White
			Vars.Visuals.colV.r = 255;
			Vars.Visuals.colV.g = 255;
			Vars.Visuals.colV.b = 255;
			break;
		case 3:			// Grey
			Vars.Visuals.colV.r = 128;
			Vars.Visuals.colV.g = 128;
			Vars.Visuals.colV.b = 128;
			break;
		case 4:			// Violet
			Vars.Visuals.colV.r = 238;
			Vars.Visuals.colV.g = 130;
			Vars.Visuals.colV.b = 238;
			break;
		case 5:			// Pink
			Vars.Visuals.colV.r = 255;
			Vars.Visuals.colV.g = 192;
			Vars.Visuals.colV.b = 203;
			break;
		case 6:			// Brown
			Vars.Visuals.colV.r = 165;
			Vars.Visuals.colV.g = 42;
			Vars.Visuals.colV.b = 42;
			break;
		case 7:			// Purple
			Vars.Visuals.colV.r = 128;
			Vars.Visuals.colV.g = 0;
			Vars.Visuals.colV.b = 128;
			break;
		case 8:			// Orange
			Vars.Visuals.colV.r = 255;
			Vars.Visuals.colV.g = 165;
			Vars.Visuals.colV.b = 0;
			break;
		case 9:			// Red
			Vars.Visuals.colV.r = 255;
			Vars.Visuals.colV.g = 0;
			Vars.Visuals.colV.b = 0;
			break;
		case 10:	   // Blue
			Vars.Visuals.colV.r = 0;
			Vars.Visuals.colV.g = 0;
			Vars.Visuals.colV.b = 255;
			break;
		case 11:		// Green
			Vars.Visuals.colV.r = 0;
			Vars.Visuals.colV.g = 255;
			Vars.Visuals.colV.b = 0;
			break;
		case 12:		// Yellow
			Vars.Visuals.colV.r = 255;
			Vars.Visuals.colV.g = 255;
			Vars.Visuals.colV.b = 0;
			break;
		case 13:		// Custom
			ImGui::SliderInt(charenc("Red"), &Vars.Visuals.colV.r, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Green"), &Vars.Visuals.colV.g, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Blue"), &Vars.Visuals.colV.b, 0.f, 255.f, "%.0f");
			break;
		}
	}
	ImGui::NextColumn();
	{
		ImGui::Combo(charenc("Colours Chams Not Visible"), &Vars.Visuals.colorsNV, colors, IM_ARRAYSIZE(colors));
		SetTooltip("Colours Chams");
		switch (Vars.Visuals.colorsNV)
		{
		case 0:
			Vars.Visuals.colNV.r = 200;
			Vars.Visuals.colNV.g = 0;
			Vars.Visuals.colNV.b = 0;
		case 1:			// Black
			Vars.Visuals.colNV.r = 0;
			Vars.Visuals.colNV.g = 0;
			Vars.Visuals.colNV.b = 0;
			break;
		case 2:			// White
			Vars.Visuals.colNV.r = 255;
			Vars.Visuals.colNV.g = 255;
			Vars.Visuals.colNV.b = 255;
			break;
		case 3:			// Grey
			Vars.Visuals.colNV.r = 128;
			Vars.Visuals.colNV.g = 128;
			Vars.Visuals.colNV.b = 128;
			break;
		case 4:			// Violet
			Vars.Visuals.colNV.r = 238;
			Vars.Visuals.colNV.g = 130;
			Vars.Visuals.colNV.b = 238;
			break;
		case 5:			// Pink
			Vars.Visuals.colNV.r = 255;
			Vars.Visuals.colNV.g = 192;
			Vars.Visuals.colNV.b = 203;
			break;
		case 6:			// Brown
			Vars.Visuals.colNV.r = 165;
			Vars.Visuals.colNV.g = 42;
			Vars.Visuals.colNV.b = 42;
			break;
		case 7:			// Purple
			Vars.Visuals.colNV.r = 128;
			Vars.Visuals.colNV.g = 0;
			Vars.Visuals.colNV.b = 128;
			break;
		case 8:			// Orange
			Vars.Visuals.colNV.r = 255;
			Vars.Visuals.colNV.g = 165;
			Vars.Visuals.colNV.b = 0;
			break;
		case 9:			// Red
			Vars.Visuals.colNV.r = 255;
			Vars.Visuals.colNV.g = 0;
			Vars.Visuals.colNV.b = 0;
			break;
		case 10:		// Blue
			Vars.Visuals.colNV.r = 0;
			Vars.Visuals.colNV.g = 0;
			Vars.Visuals.colNV.b = 255;
			break;
		case 11:		// Green
			Vars.Visuals.colNV.r = 0;
			Vars.Visuals.colNV.g = 255;
			Vars.Visuals.colNV.b = 0;
			break;
		case 12:		// Yellow
			Vars.Visuals.colNV.r = 255;
			Vars.Visuals.colNV.g = 255;
			Vars.Visuals.colNV.b = 0;
			break;
		case 13:		// Custom
			ImGui::SliderInt(charenc("Red"), &Vars.Visuals.colNV.r, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Green"), &Vars.Visuals.colNV.g, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Blue"), &Vars.Visuals.colNV.b, 0.f, 255.f, "%.0f");
			break;
		}
	}
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("XQZ"), &Vars.Visuals.Chams.XQZ);
		SetTooltip("XQZ Checkbox");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Hands"), &Vars.Visuals.Chams.Hands);
		SetTooltip("Apply Chams to Hands");
		ImGui::SameLine();
		ImGui::Checkbox(charenc("Wireframe"), &Vars.Visuals.Chams.WireframeHands);
		SetTooltip("Wireframe Checkbox");
		ImGui::SameLine();
        ImGui::Checkbox(charenc("Rainbow"), &Vars.Visuals.Chams.RainbowHands);
		SetTooltip("Rainbow Checkbox");
		ImGui::Combo(charenc("Mode"), &Vars.Visuals.Chams.Mode, chamsMode, IM_ARRAYSIZE(chamsMode));
		SetTooltip("Mode Combo");
        ImGui::SliderFloat(charenc("Rainbow Amount"), &Vars.Visuals.Chams.RainbowTime, 1.f, 150.f, "%.0f");
		SetTooltip("Rainbow SliderFloat");
	}
	ImGui::NextColumn();
	{
		ImGui::Checkbox(charenc("Radar On"), &Vars.Visuals.Radar.Enabled);
		SetTooltip("Shows players on custom Radar");
		{
			if (Vars.Visuals.Radar.Enabled)
			{
				ImGui::SliderInt(charenc("Radar X Amount"), &Vars.Visuals.Radar.X, 100, 2000);
				SetTooltip("Radar X SliderFloat");
				ImGui::SliderInt(charenc("Radar Y Amount"), &Vars.Visuals.Radar.Y, 100, 2000);
				SetTooltip("Radar Y SliderFloat");
				ImGui::SliderInt(charenc("Radar Size Amount"), &Vars.Visuals.Radar.Size, 75, 200);
				SetTooltip("Radar Size SliderFloat");
				ImGui::SliderInt(charenc("Radar Range Amount"), &Vars.Visuals.Radar.Range, 5, 100);
				SetTooltip("Radar Range SliderFloat");
			}
		}
	}
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text(charenc("Removals"));
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("Crosshair Enabled"), &Vars.Visuals.CrosshairEnabled);
		SetTooltip("Show a Crosshair based on Recoil");
		ImGui::Checkbox(charenc("Show Recoil"), &Vars.Visuals.CrosshairType);
		SetTooltip("Show Recoil");
	}
	ImGui::NextColumn(); {

		ImGui::Combo(charenc("Crosshair Style"), &Vars.Visuals.CrosshairStyle, crosshairStyle, IM_ARRAYSIZE(crosshairStyle));
		SetTooltip("Crosshair Style Combo");
		ImGui::Checkbox(charenc("No Visible Recoil"), &Vars.Visuals.RemovalsVisualRecoil);
		SetTooltip("No Visible Recoil");
	}
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("Light"), &Vars.Visuals.Dlight);
		ImGui::SliderInt(charenc("Radius Light"), &Vars.Visuals.RadiusDlight, 0, 1000);
		ImGui::Combo(charenc("Light Colors"), &Vars.Visuals.collightt, colors, IM_ARRAYSIZE(colors));
		SetTooltip("Colours Light");
		switch (Vars.Visuals.collightt)
		{
		case 0:
			Vars.Visuals.collight.r = 5;
			Vars.Visuals.collight.g = 200;
			Vars.Visuals.collight.b = 5;
			break;
		case 1:			// Black
			Vars.Visuals.collight.r = 0;
			Vars.Visuals.collight.g = 0;
			Vars.Visuals.collight.b = 0;
			break;
		case 2:			// White
			Vars.Visuals.collight.r = 255;
			Vars.Visuals.collight.g = 255;
			Vars.Visuals.collight.b = 255;
			break;
		case 3:			// Grey
			Vars.Visuals.collight.r = 128;
			Vars.Visuals.collight.g = 128;
			Vars.Visuals.collight.b = 128;
			break;
		case 4:			// Violet
			Vars.Visuals.collight.r = 238;
			Vars.Visuals.collight.g = 130;
			Vars.Visuals.collight.b = 238;
			break;
		case 5:			// Pink
			Vars.Visuals.collight.r = 255;
			Vars.Visuals.collight.g = 192;
			Vars.Visuals.collight.b = 203;
			break;
		case 6:			// Brown
			Vars.Visuals.collight.r = 165;
			Vars.Visuals.collight.g = 42;
			Vars.Visuals.collight.b = 42;
			break;
		case 7:			// Purple
			Vars.Visuals.collight.r = 128;
			Vars.Visuals.collight.g = 0;
			Vars.Visuals.collight.b = 128;
			break;
		case 8:			// Orange
			Vars.Visuals.collight.r = 255;
			Vars.Visuals.collight.g = 165;
			Vars.Visuals.collight.b = 0;
			break;
		case 9:			// Red
			Vars.Visuals.collight.r = 255;
			Vars.Visuals.collight.g = 0;
			Vars.Visuals.collight.b = 0;
			break;
		case 10:	   // Blue
			Vars.Visuals.collight.r = 0;
			Vars.Visuals.collight.g = 0;
			Vars.Visuals.collight.b = 255;
			break;
		case 11:		// Green
			Vars.Visuals.collight.r = 0;
			Vars.Visuals.collight.g = 255;
			Vars.Visuals.collight.b = 0;
			break;
		case 12:		// Yellow
			Vars.Visuals.collight.r = 255;
			Vars.Visuals.collight.g = 255;
			Vars.Visuals.collight.b = 0;
			break;
		case 13:		// Custom
			ImGui::SliderInt(charenc("Red"), &Vars.Visuals.collight.r, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Green"), &Vars.Visuals.collight.g, 0.f, 255.f, "%.0f");
			ImGui::SliderInt(charenc("Blue"), &Vars.Visuals.collight.b, 0.f, 255.f, "%.0f");
			break;
		}
	}
	ImGui::NextColumn(); 
	{

	}
}

void MiscTab()
{
	const char* AnimationTypes[] = { "Static", "Marquee", "Letters", "Time" };
	const char* NameSpamerTypes[] = { "Start", "End", "Animation" };

	ImGui::Text(charenc("Miscellaneous"));
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::SliderInt(charenc("Change FOV Amount"), &Vars.Misc.FOV, 0, 60);
		SetTooltip("Change Camera FOV");
		ImGui::SliderInt(charenc("FakeLag Amount"), &Vars.Misc.FakeLag, 0, 16);
		SetTooltip("Chokes Packets so it appears you're Lagging");
		ImGui::Checkbox(charenc("Adaptive FakeLag"), &Vars.Misc.AdaptiveFakeLag);
		SetTooltip("Chokes packets based on velocity (minimum choked is FakeLag value)");
	}
	ImGui::NextColumn();
	{
		ImGui::Checkbox(charenc("Auto Pistol"), &Vars.Misc.AutoPistol);
		SetTooltip("Automatically shoots Pistol when holding fire");
		ImGui::Checkbox(charenc("Bunnyhop"), &Vars.Misc.Bunnyhop);
		SetTooltip("Auto Bunnyhop");
		ImGui::Checkbox(charenc("Autostrafe"), &Vars.Misc.Autostrafe);
		SetTooltip("Autostrafe when Bunnyhopping");
		ImGui::Checkbox(charenc("Edge Jump"), &Vars.Misc.EdgeJump);
		SetTooltip("Jumps off the Edges");
		ImGui::Combo(charenc("Autostrafe Type"), &Vars.Misc.AutostrafeTypes, autostrafeTypes, IM_ARRAYSIZE(autostrafeTypes));
		SetTooltip("Autostrafe Type Combo");
		//ImGui::Checkbox(charenc("Silent"), &Vars.Misc.Silent);
		//SetTooltip("Strafes won't be visible for spectators");
	}
	ImGui::Columns(1);
	ImGui::Separator();
	//ImGui::Combo(charenc("Colour Nickname"), &Vars.Misc.ColourNickname, cNametype, IM_ARRAYSIZE(cNametype));
	//SetTooltip("Colour Nickname Combo");
	//ImGui::Checkbox(charenc("Name Steal"), &Vars.Misc.NameSteal);
	//SetTooltip("Name Steal Checkbox");
	//ImGui::SameLine();
    //ImGui::SliderFloat(charenc("Interval Amount"), &Vars.Misc.NameStealDelay, 0.1f, 10.f);
	//SetTooltip("Interval Amount SliderFloat");
	ImGui::Separator();
	ImGui::Text(charenc("Chat Spam"));
	ImGui::Separator();
	ImGui::InputText(charenc("Message"), Vars.Misc.ChatSpamMode, 128);
	SetTooltip("Message InputText");
	ImGui::SliderFloat(charenc("Delay"), &Vars.Misc.ChatSpamDelay, 0.1f, 10.f);
	SetTooltip("Delay Checkbox");
	ImGui::Separator();
	ImGui::Checkbox(charenc("Chat Spam On"), &Vars.Misc.ChatSpam);
	SetTooltip("Chat Spam On Checkbox");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Location Spam"), &Vars.Misc.LocationSpam);
	SetTooltip("Location Spam");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Location Spam Enemies Only"), &Vars.Misc.LocationSpamEnemies);
	SetTooltip("Location Spam Enemies Only");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Location Spam Team Chat Only"), &Vars.Misc.LocationSpamChat);
	SetTooltip("Location Spam TeamChat Only");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Headshot"), &Vars.Misc.HeadshotSay);
	SetTooltip("Headshot");
	ImGui::SameLine();
	//ImGui::Checkbox(charenc("Refund"), &Vars.Misc.RefundSay);
	//SetTooltip("Refund");
	ImGui::SameLine();
	ImGui::Checkbox(charenc("Bomb Info"), &Vars.Misc.BombInfoChat);
	SetTooltip("Bomb Info");
	
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text(charenc("Misc Functions"));
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Checkbox(charenc("Auto Accept"), &Vars.Misc.AutoAccept);
		SetTooltip("Auto Accept games when in MM queue");
		ImGui::Checkbox(charenc("Ranks"), &Vars.Misc.Ranks);
		SetTooltip("Displays Competitive Rank of all players in the Scoreboard next to their name during a Competitive Match");
		ImGui::Checkbox(charenc("Ignore Scope"), &Vars.Misc.IgnoreScope);
		SetTooltip("Disable FOV Changer while scoping");
	}
	ImGui::NextColumn();
	{
		ImGui::Checkbox(charenc("Air Stuck"), &Vars.Misc.AirStuck);
		SetTooltip("Stops Tickrate so you Freeze in place");
		ImGui::Combo(charenc("Air Stuck Key"), &Vars.Misc.AirStuckKey, keyNames, IM_ARRAYSIZE(keyNames));
		SetTooltip("Air Stuck Key Combo");
	}
	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::Text("Clan Tag");
	ImGui::Separator();
	ImGui::Checkbox("Enabled", &Vars.Misc.ClantagChanger.enabled);
	SetTooltip("Display a custom Clan Tag");
	ImGui::Separator();
	ImGui::Columns(2, NULL, true);
	{
		//if (ImGui::InputText("##CLANTAGTEXT", Vars.Misc.ClantagChanger.value, 30))
			//E::ClantagChanger->UpdateClanTagCallback();
		if (ImGui::SliderInt("##ANIMATIONSPEED", &Vars.Misc.ClantagChanger.animation_speed, 0, 2000))
			E::ClantagChanger->UpdateClanTagCallback();
	}
	ImGui::NextColumn();
	{
		if (ImGui::Combo("##ANIMATIONTYPE", &Vars.Misc.ClantagChanger.type, AnimationTypes, IM_ARRAYSIZE(AnimationTypes)))
			E::ClantagChanger->UpdateClanTagCallback();
	}
	ImGui::Columns(1);

	ImGui::Separator();
	ImGui::Text("Nickname");
	ImGui::Separator();
	static char nickname[128] = "";
	static char nickseparator[128] = "";
	static bool init_nick = false;
	if (!init_nick)
	{
		sprintf(nickname, "BADSTER.XYZ");
		sprintf(nickseparator, "BADSTER.XYZ");
		init_nick = true;
	}

	ImGui::Columns(2, NULL, true);
	{
		ImGui::InputText("##NICKNAMETEXT", nickname, 127);
		SetTooltip("Nickname Text");
		std::string ctWithEscapesProcessed = std::string(nickname);

		ImGui::Text("Nickname Text");
		ImGui::InputText("##NICKNAMESEPARATOR", nickseparator, 127);
		SetTooltip("Nickname Text");
	}
	ImGui::NextColumn();
	{
		ImGui::Combo(charenc("Nickname Type"), &Vars.Misc.NameChangerseparator_animation, NameSpamerTypes, IM_ARRAYSIZE(NameSpamerTypes));
		if (ImGui::Button("Set Nickname", ImVec2(-1, 0)))
		{
			std::string ctWithEscapesProcessed = std::string(nickname);
			U::StdReplaceStr(ctWithEscapesProcessed, "\\n", "\n");

			E::Misc->ChangeName(ctWithEscapesProcessed.c_str());
		}
		if (ImGui::Button("Nickname Spam", ImVec2(-1, 0)))
		{
			E::NameChanger->nickname = nickname;
			E::NameChanger->separator = nickseparator;
			Vars.Misc.NameChangerenabled = true;
		}
		ImGui::Columns(1);
		ImGui::Separator();
	}
}

void ConfigTab()
{
	ImGui::Text(charenc("Configs"));
	ImGui::Separator();
	if (ImGui::Button(charenc("Default"), ImVec2(93.f, 20.f)))
		strcpy(Vars.Misc.configname, "Default");
	ImGui::SameLine();
	if (ImGui::Button(charenc("Legit1"), ImVec2(93.f, 20.f)))
		strcpy(Vars.Misc.configname, "Legit1");
	ImGui::SameLine();
	if (ImGui::Button(charenc("Legit2"), ImVec2(93.f, 20.f)))
		strcpy(Vars.Misc.configname, "Legit2");
	ImGui::SameLine();
	if (ImGui::Button(charenc("Rage1"), ImVec2(93.f, 20.f)))
		strcpy(Vars.Misc.configname, "Rage1");
	ImGui::SameLine();
	if (ImGui::Button(charenc("Rage2"), ImVec2(93.f, 20.f)))
		strcpy(Vars.Misc.configname, "Rage2");
	ImGui::SameLine();
	ImGui::Separator();
	ImGui::InputText(charenc("Name Config"), Vars.Misc.configname, 128);
	SetTooltip("Name Config");
	ImGui::PushItemWidth(190);
	ImGui::Columns(2, charenc("##config-settings"), false);
	ImGui::Separator();
	if (ImGui::Button(charenc("Load Config"), ImVec2(93.f, 20.f))) Config->Load();
	SetTooltip("Load Config");
	ImGui::SameLine();
	if (ImGui::Button(charenc("Save Config"), ImVec2(93.f, 20.f))) Config->Save();
	SetTooltip("Save Config");
	ImGui::SameLine();
	if (ImGui::Button(charenc("Unload"), ImVec2(93.f, 20.f))) {
		SetTooltip("Unload");
		E::Misc->Panic();
	}
	ImGui::Columns(1);
	ImGui::Separator();
}

void ColorsTab()
{
	
	
}

EndSceneFn oEndScene;
long __stdcall Hooks::EndScene(IDirect3DDevice9* pDevice)
{
	if (!G::d3dinit)
		GUI_Init(pDevice);

	H::D3D9->ReHook();

	ImGui::GetIO().MouseDrawCursor = Vars.Menu.Opened;

	ImGui_ImplDX9_NewFrame();

	if (Vars.Visuals.SpectatorsTab)
		E::Visuals->SpectatorsTab();

	if (Vars.Menu.Opened)
	{
		int pX, pY;
		I::InputSystem->GetCursorPosition(&pX, &pY);
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos.x = (float)(pX);
		io.MousePos.y = (float)(pY);

		static int page = 0;
		ImGui::SetNextWindowSize(ImVec2(960, 645), ImGuiSetCond_FirstUseEver);

		ImVec2 windowSize = ImGui::GetWindowSize();
		int widthz = windowSize.x - 0;


		if (ImGui::Begin("BADSTER FRAMEWORK FOR COUNTER-STRIKE: GLOBAL OFFENSIVE | Version 1.4", &Vars.Menu.Opened, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders))
		{
			const char* tabs[] = {
				"Ragebot",
				"Legitbot",
				"Visuals",
				"Misc",
				"Config",
				//"Colors",
			};
			int tabs_size = sizeof(tabs) / sizeof(tabs[0]);

			for (int i = 0; i < tabs_size; i++)
			{
				ImVec2 windowSize = ImGui::GetWindowSize();
				int width = windowSize.x / tabs_size - 10;

				int distance;
				if (i == page)
					distance = 0;
				else
					distance = i > page ? i - page : page - i;

				if (ImGui::Button(tabs[i], ImVec2(width, 0)))
					page = i;

				if (i < tabs_size - 1)
					ImGui::SameLine();
			}

			ImGui::Separator();

			switch (page)
			{
			case 0:
				RageTab();
				break;
			case 1:
				LegitTab();
				break;
			case 2:
				VisualsTab();
				break;
			case 3:
				MiscTab();
				break;
			case 4:
				ConfigTab();
				break;
		//	case 5:
			//	ColorsTab();
			//	break;
			}

			ImGui::End();
		}
	}
	ImGui::Render();

	return oEndScene(pDevice);
}

ResetFn oReset;
long __stdcall Hooks::Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	if (!G::d3dinit)
		return oReset(pDevice, pPresentationParameters);

	ImGui_ImplDX9_InvalidateDeviceObjects();

	auto hr = oReset(pDevice, pPresentationParameters);
	ImGui_ImplDX9_CreateDeviceObjects();


	return hr;
}

void GUI_Init(IDirect3DDevice9* pDevice)
{
	ImGui_ImplDX9_Init(G::Window, pDevice);

	color();

	G::d3dinit = true;
}