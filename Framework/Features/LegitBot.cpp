#pragma once
#include <iostream>
#include "../Cheat.h"
CLegitBot* LegitBot;

int hitBox;

float m_fbestfov = 20.0f;
int m_ibesttargetlegit = -1;

float deltaTime;
float curAimTime;
float d = 0;
DWORD dwShotTime = NULL;
DWORD dST = NULL;
DWORD dwShotZoom = NULL;
DWORD dwShotZoom2 = NULL;
int ll = 0;
int xx = 0;
bool  bAttack;
bool  qq;
int huinia = 0;
int kkkk;

void CLegitBot::Run()
{
	if (Vars.Misc.AutoPistol && G::LocalPlayer->GetWeapon()->IsPistol() && G::UserCmd->buttons & IN_ATTACK)
		AutoPistol();

	if (ll == 1 && xx <= 3)
	{
		I::Engine->ClientCmd_Unrestricted("lastinv");
		++xx;
		dwShotZoom2 = GetTickCount();
	}

	if (Vars.Legitbot.Aimbot.KillStop)
		huinia = 1;
	else
		huinia = 0;

		DropTarget();

		static float oldServerTime = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;
		float serverTime = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;
		deltaTime = serverTime - oldServerTime;
		oldServerTime = serverTime;

		if (!G::LocalPlayer->GetWeapon()->IsGun() || G::LocalPlayer->GetWeapon()->IsEmpty())
			return;

		if ((G::PressedKeys[Vars.Legitbot.Triggerbot.Key] || Vars.Legitbot.Triggerbot.AutoFire) && Vars.Legitbot.Triggerbot.Enabled)
			Triggerbot();

		if ((!(G::UserCmd->buttons & IN_ATTACK) || m_ibesttargetlegit == -1) && Vars.Legitbot.Aimbot.Enabled)
			FindTarget();

		if (m_ibesttargetlegit != -1 && (Vars.Legitbot.Aimbot.AlwaysOn) || (Vars.Legitbot.Aimbot.OnKey && G::PressedKeys[Vars.Legitbot.Aimbot.Key]))
			GoToTarget();
				
}
void CLegitBot::FindTarget()
{
	if (G::LocalPlayer->GetWeapon()->IsPistol())
		m_fbestfov = Vars.Legitbot.pistols.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsRifle())
		m_fbestfov = Vars.Legitbot.rifles.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsSmg())
		m_fbestfov = Vars.Legitbot.smg.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsShotgun())
		m_fbestfov = Vars.Legitbot.shotguns.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsSniper())
		m_fbestfov = Vars.Legitbot.snipers.FOV;

	for (int i = 0; i <= I::Globals->maxClients; i++)
	{
		if (!EntityIsValid(i))
			continue;

		CBaseEntity* Entity = I::ClientEntList->GetClientEntity(i);

		if (!Entity)
			continue;

		Vector vEndS;

		QAngle viewangles = G::UserCmd->viewangles + G::LocalPlayer->GetPunch() * 2.f;

		if (G::LocalPlayer->GetWeapon()->IsPistol())
			hitBox = Vars.Legitbot.pistols.Hitbox;
		else if (G::LocalPlayer->GetWeapon()->IsRifle())
			hitBox = Vars.Legitbot.rifles.Hitbox;
		else if (G::LocalPlayer->GetWeapon()->IsSmg())
			hitBox = Vars.Legitbot.smg.Hitbox;
		else if (G::LocalPlayer->GetWeapon()->IsShotgun())
			hitBox = Vars.Legitbot.shotguns.Hitbox;
		else if (G::LocalPlayer->GetWeapon()->IsSniper())
			hitBox = Vars.Legitbot.snipers.Hitbox;

		float fov = M::GetFov(G::UserCmd->viewangles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), Entity->GetBonePosition(hitBox)));

		if (fov < m_fbestfov)
		{
			m_fbestfov = fov;
			m_ibesttargetlegit = i;
		}

		if (G::LocalPlayer->GetShotsFired() == 0)
		{
			d = 0;
			dST = NULL;
		}

		if (!(G::UserCmd->buttons & IN_ATTACK))
		{
			G::KillStop = false;
			dwShotTime = NULL;
			kkkk = 0;
		}
	}
}

void CLegitBot::GoToTarget()
{
	CBaseEntity* Entity = I::ClientEntList->GetClientEntity(m_ibesttargetlegit);


	if (!Entity)
	{
		return;
	}

	
	if ((G::LocalPlayer->GetWeapon()->IsRifle() && Vars.Legitbot.rifles.Nearest) || (G::LocalPlayer->GetWeapon()->IsSmg() && Vars.Legitbot.smg.Nearest) || (G::LocalPlayer->GetWeapon()->IsSniper() && Vars.Legitbot.snipers.Nearest))
	{
		Nearest();
	}
	else
	{
		CheckF();
	}
	
	if (!G::KillStopDelay)
		G::KillStopDelay = GetTickCount();

	if (Vars.Legitbot.Aimbot.FlashCkeck && G::LocalPlayer->GetFlashBangTime() - I::Globals->curtime > 1.5f)
		return;
	
	if (!Entity->IsVisible(hitBox))
		return;

	if (!Entity->IsVisible(G::LocalPlayer->GetEyePosition(), Entity->GetBonePosition(hitBox), G::LocalPlayer, Entity, Vars.Legitbot.Aimbot.SmokeCheck))
		return;

	if (Vars.Legitbot.Aimbot.KillStopDelay && G::KillStopDelay + Vars.Legitbot.Aimbot.KillStopDelayA >= GetTickCount())
		return;

	if (huinia == 1 && G::KillStop)
		return;

	Vector predicted = Entity->GetPredicted(Entity->GetBonePosition(hitBox));
	QAngle dst = M::CalcAngle(G::LocalPlayer->GetEyePosition(), predicted);
	QAngle ds;
	QAngle src = G::UserCmd->viewangles;

	float RCSY;
	float RCSX;

	auto CurrentPunch = G::LocalPlayer->GetPunch();
	QAngle angle = G::UserCmd->viewangles;
	QAngle RCSLastPunch;

	
		if (G::LocalPlayer->GetWeapon()->IsPistol()) 
		{
			RCSY = Vars.Legitbot.pistols.RCSAmountY;
			RCSX = Vars.Legitbot.pistols.RCSAmountX;
		}
		else if (G::LocalPlayer->GetWeapon()->IsRifle()) 
		{
			RCSY = Vars.Legitbot.rifles.RCSAmountY;
			RCSX = Vars.Legitbot.rifles.RCSAmountX;
		}
		else if (G::LocalPlayer->GetWeapon()->IsSmg()) 
		{
			RCSY = Vars.Legitbot.smg.RCSAmountY;
			RCSX = Vars.Legitbot.smg.RCSAmountX;
		}
		else if (G::LocalPlayer->GetWeapon()->IsShotgun()) 
		{
			RCSY = Vars.Legitbot.shotguns.RCSAmountY;
			RCSX = Vars.Legitbot.shotguns.RCSAmountX;
		}
		else if (G::LocalPlayer->GetWeapon()->IsSniper()) 
		{
			RCSY = Vars.Legitbot.snipers.RCSAmountY;
			RCSX = Vars.Legitbot.snipers.RCSAmountX;
		}



	auto qPunchAngles = G::LocalPlayer->GetPunch();
	QAngle delta;

	if ((G::LocalPlayer->GetWeapon()->IsPistol() && Vars.Legitbot.pistols.RCSEnabled) || (G::LocalPlayer->GetWeapon()->IsRifle() && Vars.Legitbot.rifles.RCSEnabled) || (G::LocalPlayer->GetWeapon()->IsSmg() && Vars.Legitbot.smg.RCSEnabled))
	{
		dst.y -= qPunchAngles.y * (RCSY / 50.f);
		dst.x -= qPunchAngles.x * (RCSX / 50.f);
		delta = dst - src;
	}
	else
	{
		delta = dst - src;
	}

	int slid = 0;
	float slider = 0;

	if (G::LocalPlayer->GetWeapon()->IsRifle())
	{
		slider = Vars.Legitbot.rifles.Time;
		slid = slider;
	}
	else if (G::LocalPlayer->GetWeapon()->IsSmg())
	{
		slider = Vars.Legitbot.smg.Time;
		slid = slider;
	}

	if (G::LocalPlayer->GetShotsFired() < slid)
		return;

	

		delta.Clamp();

	bool bIsNoShot;
	int m_fov;
	bool psalo;
	float smooth;



	if (G::LocalPlayer->GetWeapon()->IsPistol())
	{
		m_fov = Vars.Legitbot.pistols.FOV;
		psalo = Vars.Legitbot.pistols.pSilent;
		smooth = Vars.Legitbot.pistols.Speed;
	}
	else if (G::LocalPlayer->GetWeapon()->IsRifle()) {
		m_fov = Vars.Legitbot.rifles.FOV;
		psalo = false;
		smooth = Vars.Legitbot.rifles.Speed;
	}
	else if (G::LocalPlayer->GetWeapon()->IsSmg()) {
		m_fov = Vars.Legitbot.smg.FOV;
		psalo = false;
		smooth = Vars.Legitbot.smg.Speed;
	}
	else if (G::LocalPlayer->GetWeapon()->IsShotgun()) {
		m_fov = Vars.Legitbot.shotguns.FOV;
		psalo = false;
		smooth = Vars.Legitbot.shotguns.Speed;
	}
	else if (G::LocalPlayer->GetWeapon()->IsSniper()) {
		m_fov = Vars.Legitbot.snipers.FOV;
		psalo = Vars.Legitbot.snipers.pSilent;
		smooth = Vars.Legitbot.snipers.Speed;
	}

	if (!delta.IsZero())
	{

		float finalTime = delta.Length() / (smooth / 100.f);

		curAimTime += deltaTime;

		if (curAimTime > finalTime)
			curAimTime = finalTime;

		float percent = curAimTime / finalTime;

		delta *= percent;
		dst = src + delta;
	}

	if (!dwShotTime)
		dwShotTime = GetTickCount();

	G::UserCmd->viewangles = dst.Clamp();

	if ((G::LocalPlayer->GetWeapon()->IsPistol() && Vars.Legitbot.pistols.Delay > 1 && !psalo && kkkk == 0) || (G::LocalPlayer->GetWeapon()->IsRifle() && Vars.Legitbot.rifles.Delay > 1 && G::LocalPlayer->GetShotsFired() == 0) || (G::LocalPlayer->GetWeapon()->IsShotgun() && Vars.Legitbot.shotguns.Delay > 1) || (G::LocalPlayer->GetWeapon()->IsSmg() && Vars.Legitbot.smg.Delay > 1 && G::LocalPlayer->GetShotsFired() == 0) || (G::LocalPlayer->GetWeapon()->IsSniper() && Vars.Legitbot.snipers.Delay > 1 && !psalo))
	{
		if (G::LocalPlayer->GetWeapon()->IsPistol() && dwShotTime + Vars.Legitbot.pistols.Delay >= GetTickCount())
		{
			G::UserCmd->buttons &= ~IN_ATTACK;
			kkkk = 1;
		}

		if (G::LocalPlayer->GetWeapon()->IsRifle() && dwShotTime + Vars.Legitbot.rifles.Delay >= GetTickCount())
			G::UserCmd->buttons &= ~IN_ATTACK;

		if (G::LocalPlayer->GetWeapon()->IsShotgun() && dwShotTime + Vars.Legitbot.shotguns.Delay >= GetTickCount())
			G::UserCmd->buttons &= ~IN_ATTACK;

		if (G::LocalPlayer->GetWeapon()->IsSmg() && dwShotTime + Vars.Legitbot.smg.Delay >= GetTickCount())
			G::UserCmd->buttons &= ~IN_ATTACK;

		if (G::LocalPlayer->GetWeapon()->IsSniper() && dwShotTime + Vars.Legitbot.snipers.Delay >= GetTickCount())
			G::UserCmd->buttons &= ~IN_ATTACK;
	}

	if (!G::LocalPlayer->IsScoped() && G::LocalPlayer->GetWeapon()->IsAWPorSSG() && m_fbestfov < Vars.Legitbot.snipers.FOVZoom && Vars.Legitbot.snipers.FastZoom)
		G::UserCmd->buttons |= IN_ZOOM;

	if (!dwShotZoom)
		dwShotZoom = GetTickCount();

	if (G::LocalPlayer->IsScoped())
	{
		ll = 0;
		xx = 0;
	}

	if (G::UserCmd->buttons & IN_ATTACK && G::LocalPlayer->GetWeapon()->IsAWPorSSG() && Vars.Legitbot.snipers.StopZoom)
	{
		ll = 1;
		dwShotZoom = NULL;
	}

	
}

void CLegitBot::AutoPistol()
{
	CBaseCombatWeapon* revolver;

	auto weapon = G::LocalPlayer->GetWeapon();
	float server_time = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;
	float next_shot = weapon->GetNextPrimaryAttack() - server_time;

	if (next_shot > 0)
	{
		if (revolver->GetItemDefinitionIndex() == ItemDefinitionIndex::WEAPON_REVOLVER)
			G::UserCmd->buttons &= ~IN_ATTACK2;
		else
			G::UserCmd->buttons &= ~IN_ATTACK;
	}
}

void CLegitBot::DropTarget()
{
	if (!EntityIsValid(m_ibesttargetlegit))
	{
		m_ibesttargetlegit = -1;
		curAimTime = 0.f;
	}
}

bool CLegitBot::EntityIsValid(int i)
{
	CBaseEntity* pEntity = I::ClientEntList->GetClientEntity(i);
	int fov;

	if (G::LocalPlayer->GetWeapon()->IsPistol()) {
		fov = Vars.Legitbot.pistols.FOV;
		hitBox = Vars.Legitbot.pistols.Hitbox;
	}
	else if (G::LocalPlayer->GetWeapon()->IsRifle()) {
		fov = Vars.Legitbot.rifles.FOV;
		hitBox = Vars.Legitbot.rifles.Hitbox;
	}
	else if (G::LocalPlayer->GetWeapon()->IsSmg()) {
		fov = Vars.Legitbot.smg.FOV;
		hitBox = Vars.Legitbot.smg.Hitbox;
	}
	else if (G::LocalPlayer->GetWeapon()->IsShotgun()) {
		fov = Vars.Legitbot.shotguns.FOV;
		hitBox = Vars.Legitbot.shotguns.Hitbox;
	}
	else if (G::LocalPlayer->GetWeapon()->IsSniper()) {
		fov = Vars.Legitbot.snipers.FOV;
		hitBox = Vars.Legitbot.snipers.Hitbox;
	}


	if (!pEntity)
		return false;
	if (pEntity == G::LocalPlayer)
		return false;
	if (pEntity->GetHealth() <= 0)
		return false;
	if (pEntity->GetImmune())
		return false;
	if (pEntity->GetDormant())
		return false;
	if (pEntity->GetTeam() == G::LocalPlayer->GetTeam() && !Vars.Legitbot.Aimbot.FriendlyFire)
		return false;
	if (!pEntity->IsVisible(hitBox))
		return false;
	if (M::GetFov(G::UserCmd->viewangles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), pEntity->GetBonePosition(hitBox))) > fov)
		return false;
	player_info_t pInfo;
	I::Engine->GetPlayerInfo(i, &pInfo);

	if (strcmp(pInfo.guid, "STEAM_ID") == 0)
		return false;

	return true;
}

void CLegitBot::Triggerbot()
{
	CBaseEntity* localplayer = G::LocalPlayer;
	if (!localplayer || !localplayer->GetAlive())
		return;

	long currentTime_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()).count();
	static long timeStamp = currentTime_ms;
	long oldTimeStamp;

	Vector traceStart, traceEnd;
	trace_t tr;

	QAngle viewAngles;
	I::Engine->GetViewAngles(viewAngles);
	QAngle viewAngles_rcs = viewAngles + localplayer->GetPunch() * 2.0f;

	M::AngleVectors(viewAngles_rcs, &traceEnd);

	traceStart = localplayer->GetEyePosition();
	traceEnd = traceStart + (traceEnd * 8192.0f);

	if (Vars.Legitbot.Triggerbot.AutoWall)
	{
		CAutowall AutoWalls;
		CAutowall::FireBulletData data;
		if (AutoWalls.GetDamage(traceEnd, data) == 0.0f)
			return;

		tr = data.enter_trace;
	}
	else
	{
		Ray_t ray;
		ray.Init(traceStart, traceEnd);
		CTraceFilter traceFilter;
		traceFilter.pSkip = localplayer;
		I::EngineTrace->TraceRay(ray, 0x46004003, &traceFilter, &tr);
	}

	oldTimeStamp = timeStamp;
	timeStamp = currentTime_ms;

	CBaseEntity* player = (CBaseEntity*)tr.m_pEnt;

	if (!player)
		return;

	if (player->GetClientClass()->m_ClassID != 35)
		return;

	if (player == localplayer
		|| player->GetDormant()
		|| !player->GetAlive()
		|| player->GetImmune())
		return;

	if (player->GetTeam() == localplayer->GetTeam() && !Vars.Legitbot.Triggerbot.Filter.Friendly)
		return;

	bool filter;

	if (!tr.m_pEnt)
		return;

	if (strcmp(tr.m_pEnt->GetPlayerInfo().guid, "STEAM_ID") == 0)
		return;

	int hitgroup = tr.hitgroup;
	bool didHit = false;

	if (Vars.Legitbot.Triggerbot.Filter.Head && hitgroup == HITGROUP_HEAD)
		didHit = true;
	if (Vars.Legitbot.Triggerbot.Filter.Chest && hitgroup == HITGROUP_CHEST)
		didHit = true;
	if (Vars.Legitbot.Triggerbot.Filter.Stomach && hitgroup == HITGROUP_STOMACH)
		didHit = true;
	if (Vars.Legitbot.Triggerbot.Filter.Arms && (hitgroup == HITGROUP_LEFTARM || hitgroup == HITGROUP_RIGHTARM))
		didHit = true;
	if (Vars.Legitbot.Triggerbot.Filter.Legs && (hitgroup == HITGROUP_LEFTLEG || hitgroup == HITGROUP_RIGHTLEG))
		didHit = true;

	float hitchance = 75.f + (Vars.Legitbot.Triggerbot.HitChanceAmount / 4);
	if (didHit && (!Vars.Legitbot.Triggerbot.HitChance || (1.0f - G::LocalPlayer->GetWeapon()->GetAccuracyPenalty()) * 100.f >= hitchance)) {
		if (G::LocalPlayer->GetWeapon()->IsRevolver())
			G::UserCmd->buttons |= IN_ATTACK2;
		else
			G::UserCmd->buttons |= IN_ATTACK;
	}
}
QAngle m_oldangle;

void CLegitBot::Nearest()
{
	CBaseEntity* Entity = I::ClientEntList->GetClientEntity(m_ibesttargetlegit);
	
		for (int i = 3; i <= 8; i++)
		{
			float fov = M::GetFov(G::UserCmd->viewangles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), Entity->GetBonePosition(i)));

			if (fov < m_fbestfov)
			{
				m_fbestfov = fov;
				hitBox = i;
			}

		}
}

void CLegitBot::CheckF()
{
	CBaseEntity* Entity = I::ClientEntList->GetClientEntity(m_ibesttargetlegit);

	float fov = M::GetFov(G::UserCmd->viewangles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), Entity->GetBonePosition(hitBox)));

	if (fov < m_fbestfov)
	{
		m_fbestfov = fov;
	}
}