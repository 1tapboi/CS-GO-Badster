#pragma once

#include "../SDK/Entity.h"
#include "../Cheat.h"
#include "../Enhancements.h"

namespace G
{
	extern bool			Aimbotting;
	extern CBaseEntity* LocalPlayer;
	extern bool			Return;
	extern CUserCmd*	UserCmd;
	extern HMODULE		Dll;
	extern HWND			Window;
	extern bool			PressedKeys[ 256 ];
	extern bool			d3dinit;
	extern float		FOV;
	extern int			ChamMode;
	extern bool			SendPacket;
	extern int			BestTarget;
	extern bool			KillStop;
	extern DWORD		KillStopDelay;
}

namespace H
{
	extern VTHook*	VPanel;
	extern VTHook*	ClientMode;
	extern VTHook*	Client;
	extern VTHook*	ModelRender;
	extern VTHook*	Surface;
	extern VTHook*  D3D9;
	extern VTHook*	GameEvent;
}

namespace E
{
	extern CLegitBot*			LegitBot;
	extern CRageBot*			RageBot;
	extern CVisuals*			Visuals;
	extern CMiscellaneous*		Misc;
	extern CPredictionSystem*	PredictionSystem;
	extern CFakeLag*			FakeLag;
	extern CClantagChanger*		ClantagChanger;
	extern CNameChanger*		NameChanger;
}