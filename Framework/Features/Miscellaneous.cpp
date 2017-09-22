#include "../Cheat.h"
#include <sstream>
#include <fstream>
#include "../XOR.h"

int ii = 0;

void CMiscellaneous::Initialize()
{
	if (m_bInitialized)
		return;
}

void CMiscellaneous::Run()
{
	Bunnyhop();
}

void CMiscellaneous::Think()
{

}

void CMiscellaneous::Bunnyhop()
{
	static bool bLastJumped = false;
	static bool bShouldFake = false;

	if (!bLastJumped && bShouldFake)
	{
		bShouldFake = false;
		G::UserCmd->buttons |= IN_JUMP;
	}
	else if (G::UserCmd->buttons & IN_JUMP)
	{
		if (G::LocalPlayer->GetFlags() & FL_ONGROUND)
		{
			bLastJumped = true;
			bShouldFake = true;
		}
		else
		{
			G::UserCmd->buttons &= ~IN_JUMP;
			bLastJumped = false;
		}
	}
	else
	{
		bLastJumped = false;
		bShouldFake = false;
	}
}

void CMiscellaneous::LegitStrafe()
{
	CBaseEntity* localplayer;

	if (!(G::UserCmd->buttons & IN_RUN))
		return;

	if (localplayer->GetFlags() & FL_ONGROUND)
		return;

	if (G::UserCmd->buttons & IN_FORWARD || G::UserCmd->buttons & IN_BACK || G::UserCmd->buttons & IN_MOVELEFT || G::UserCmd->buttons & IN_MOVERIGHT)
		return;

	if (G::UserCmd->mousedx <= 1 && G::UserCmd->mousedx >= -1)
		return;

		switch (Vars.Misc.AutostrafeTypes)
		{
		case 0:
			G::UserCmd->sidemove = G::UserCmd->mousedx < 0.f ? -450.f : 450.f;
			break;
		case 1:
			G::UserCmd->sidemove = G::UserCmd->mousedx < 0.f ? 450.f : -450.f;
			break;
		case 2:
			G::UserCmd->forwardmove = G::UserCmd->mousedx < 0.f ? -450.f : 450.f;
			break;
		case 3:
			G::UserCmd->forwardmove = G::UserCmd->mousedx < 0.f ? 450.f : -450.f;
			break;
		default:
			break;
		}
}

void CMiscellaneous::RageStrafe()
{
	if (G::LocalPlayer->GetFlags() & FL_ONGROUND)
		return;

	if (!G::LocalPlayer->GetAlive())
		return;

	if (G::LocalPlayer->GetMoveType() == MOVETYPE_LADDER || G::LocalPlayer->GetMoveType() == MOVETYPE_NOCLIP)
		return;

	bool backwards = false;
	if (G::UserCmd->mousedx < 0) G::UserCmd->sidemove = backwards ? 650.f : -650.f;
	if (G::UserCmd->mousedx > 0) G::UserCmd->sidemove = backwards ? -650.f : 650.f;
}

size_t linenum = 0;

void CMiscellaneous::Run_LocationSpam()
{
	static std::string name;
	CBaseEntity* pEntity = NULL;

	while (!pEntity)
	{
		pEntity = I::ClientEntList->GetClientEntity(RandomInt(0, I::ClientEntList->GetHighestEntityIndex()));

		if (!pEntity) return;
		if (!pEntity->GetAlive()) return;
		name = pEntity->GetName();
		if (pEntity->GetName() == "GOTV" || pEntity->GetName() == "") return;

		if (Vars.Misc.LocationSpamEnemies && pEntity->GetTeam() == G::LocalPlayer->GetTeam())
			return;

		static float nextTime = 0.f;
		float flServerTime = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;

		if (nextTime > flServerTime)
			return;

		nextTime = flServerTime + Vars.Misc.ChatSpamDelay;

		if (!Vars.Misc.LocationSpam)
			return;

		char szCmd[256];

		if (pEntity->GetHealth() <= 0) return;

		if (Vars.Misc.LocationSpamChat)
			sprintf(szCmd, "say_team  \"%s is at %s with %d Health!\"", name.c_str(), pEntity->GetLastPlace().c_str(), pEntity->GetHealth());
		else
			sprintf(szCmd, "say \"%s is at %s with %d Health!\"", name.c_str(), pEntity->GetLastPlace().c_str(), pEntity->GetHealth());

		I::Engine->ClientCmd_Unrestricted(szCmd);
	}
}

//void CMiscellaneous::NameSteal()
//{
	//if (!Vars.Misc.NameSteal)
		//return;

	//static float nextTime = 0.f;
	//float flServerTime = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;

	//if (nextTime > flServerTime)
		//return;

	//nextTime = flServerTime + Vars.Misc.NameStealDelay;


	//static ConVar* name = I::Cvar->FindVar("name");

	//char* szName = NULL;

	//while (!szName)
	//{
		//player_info_t pInfo;
		//I::Engine->GetPlayerInfo(RandomInt(0, I::ClientEntList->GetHighestEntityIndex()), &pInfo);

		//if (strcmp(pInfo.name, "") != 0 && !(strcmp(pInfo.name, "GOTV") == 0)) szName = pInfo.name;
	//}

	//char nameChar[64];
	//sprintf(nameChar, "%s ", szName);
	//name->SetValue(nameChar);
//}

void CMiscellaneous::Chatspam()
{
	static float nextTime = 0.f;
	float flServerTime = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;

	if (nextTime > flServerTime)
		return;

	nextTime = flServerTime + Vars.Misc.ChatSpamDelay;

	if (!Vars.Misc.ChatSpam)
		return;

	char str[512];
	sprintf(str, "say %s", Vars.Misc.ChatSpamMode);

	if (I::Engine->IsConnected())
		I::Engine->ClientCmd_Unrestricted(str);
}

void CMiscellaneous::ChangeName(const char* name)
{
	ConVar* nameConvar = I::Cvar->FindVar(charenc("name"));
	*(int*)((DWORD)&nameConvar->fnChangeCallback + 0xC) = NULL;
	nameConvar->SetValue(name);
}

void CMiscellaneous::ChangeCName()
{
	ConVar* nameConvar = I::Cvar->FindVar(charenc("name"));
	*(int*)((DWORD)&nameConvar->fnChangeCallback + 0xC) = NULL;

	switch (Vars.Misc.ColourNickname)
	{
	case 0:
		break;
	case 1:
		nameConvar->SetValue("\x01\x0B\x02""B""\x05""A""\x02""D""\x05""S""\x02""T""\x05""E""\x02""R""\x03");
		break;
	}
}

void CMiscellaneous::AirStuck()
{
	if (Vars.Ragebot.Enabled && G::UserCmd->buttons & IN_ATTACK)
		return;

	bool airset = false;

	if (GetKeyState(Vars.Misc.AirStuckKey))
		airset = !airset;

	if (airset)
		G::UserCmd->tick_count = INT_MAX;
}

int GetPlayerIndex(CBaseEntity* pBasePlayer)
{
	for (int i = 0; i < I::ClientEntList->GetHighestEntityIndex(); i++)
	{
		CBaseEntity* pBaseEntity = I::ClientEntList->GetClientEntity(i);
		if (pBaseEntity == pBasePlayer)
			return i;
	}
	return -1;
}

#define nActiveCoinRank (DWORD)0x4840

void CMiscellaneous::GameResources()
{
	int Music = 20024;

	static DWORD CSPlayerResource = (U::FindPattern3("client.dll", (PBYTE)"\x8B\x3D\x00\x00\x00\x00\x85\xFF\x0F\x84\x00\x00\x00\x00\x81\xC7", "xx????xxxx????xx") + 0x2);

	DWORD ptrResource = *(PDWORD)((DWORD)CSPlayerResource);
	DWORD m_nMusicID = (DWORD)(ptrResource + offsets.m_nMusicID + (G::LocalPlayer->GetIndex() * 4));

	m_nMusicID = Music;
}

void CMiscellaneous::Panic()
{

	I::Engine->ClientCmd_Unrestricted(charenc("cl_mouseenable 1"));
	I::Engine->ClientCmd_Unrestricted(charenc("crosshair 1"));

	H::ModelRender->UnHook();
	H::VPanel->UnHook();
	H::ClientMode->UnHook();
	H::Client->UnHook();
	H::Surface->UnHook();
	H::GameEvent->UnHook();
	H::D3D9->UnHook();
	SetWindowLongPtr(G::Window, GWL_WNDPROC, (LONG_PTR)Hooks::oldWindowProc);
}