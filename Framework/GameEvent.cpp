#include "Cheat.h"

IGameEvent* GameEventManager;
FireEventClientSideFn oFireEventClientSide;
bool __fastcall Hooks::hkFireEventClientSide(IGameEventManager2* thisptr, void* edx, IGameEvent* pEvent)
{
	if (pEvent)
	{

		if (!strcmp(pEvent->GetName(), "bomb_pickup"))
			Vars.Bomber = pEvent->GetInt("user_id");
		if (!strcmp(pEvent->GetName(), "hostage_follows"))
			Vars.Hostage = pEvent->GetInt("user_id");
		if (!strcmp(pEvent->GetName(), "bomb_begin_defuse"))
			Vars.Defuser = pEvent->GetInt("user_id");
		if (!strcmp(pEvent->GetName(), "bomb_abort_defuse"))
			Vars.Defuser = 0;
		if (!strcmp(pEvent->GetName(), "bomb_planted"))
			Vars.Bomb = true;
		if (!strcmp(pEvent->GetName(), "bomb_dropped"))
			Vars.Bomber = 0;


		if (!strcmp(pEvent->GetName(), "round_end"))
		{
			Vars.Defuser = 0;
			Vars.Hostage = 0;
			Vars.Bomb = false;
		}

		if (Vars.Misc.BombInfoChat)
		{
			if (!strcmp(pEvent->GetName(), "bomb_planted"))
			{
				auto userid = I::Engine->GetPlayerForUserID(pEvent->GetInt("user_id"));

				player_info_t info;
				char pszBuffer[128];
				if (I::Engine->GetPlayerInfo(userid, &info))
				{
					sprintf_s(pszBuffer, "say Bomb has benn Planted by %s", /*bombsite, */ info.name);
				}
				I::Engine->ClientCmd(pszBuffer);
			}

			if (!strcmp(pEvent->GetName(), "bomb_defused"))
			{
				auto userid = I::Engine->GetPlayerForUserID(pEvent->GetInt("user_id"));

				player_info_t info;
				char pszBuffer[128];
				if (I::Engine->GetPlayerInfo(userid, &info))
				{
					sprintf_s(pszBuffer, "say Bomb has been Defused by %s", /*bombsite, */ info.name);
				}
				I::Engine->ClientCmd(pszBuffer);
			}

			if (!strcmp(pEvent->GetName(), "bomb_begin_plant"))
				I::Engine->ClientCmd_Unrestricted("say Bomb are Planting");

			if (!strcmp(pEvent->GetName(), "bomb_begin_defuse"))
			{
				auto defusekits = pEvent->GetBool("Has Kit");
				const char* kits;

				if (defusekits)
					kits = "With Kits";
				else
					kits = "Without Kits";


				char pszBuffer[128];
				sprintf_s(pszBuffer, "say Bomb are Defusing (%s)", kits);
				I::Engine->ClientCmd_Unrestricted(pszBuffer);
			}

			if (!strcmp(pEvent->GetName(), "bomb_exploded"))
				I::Engine->ClientCmd_Unrestricted("say Bomb has been Exploded");
		}

		if (!strcmp(pEvent->GetName(), "player_death"))
		{
			auto userid = I::Engine->GetPlayerForUserID(pEvent->GetInt("user_id"));
			auto attacker = I::Engine->GetPlayerForUserID(pEvent->GetInt("attacker"));
			auto iLocalPlayer = I::Engine->GetLocalPlayer();

			if (attacker == iLocalPlayer && userid != iLocalPlayer)
			{

				if (Vars.Legitbot.Aimbot.KillStop)
					G::KillStop = true;

				if (Vars.Legitbot.Aimbot.KillStopDelay)
					G::KillStopDelay = NULL;

				bool IsHeadshot = pEvent->GetBool("headshot");
				if (IsHeadshot && Vars.Misc.HeadshotSay)
					I::Engine->ClientCmd("say Get Headshot, Cry in a Pillow, Buy BADSTER or Suck away my Dick :D");

				else
				{
					if (Vars.Misc.RefundSay)
					{
						player_info_t info;
						if (I::Engine->GetPlayerInfo(userid, &info))
						{
							char pszBuffer[128];
							sprintf_s(pszBuffer, "say %s you have REALLY Bought this SHIT???", info.name);
							I::Engine->ClientCmd(pszBuffer);
						}
					}
				}
			}
		}
	}
	/*---*/return oFireEventClientSide(thisptr, pEvent);/*---*/
}