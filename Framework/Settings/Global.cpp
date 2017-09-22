#include "../SDK.h"

bool				G::Aimbotting;
CBaseEntity*		G::LocalPlayer;
bool				G::Return;
CUserCmd*			G::UserCmd;
HMODULE				G::Dll;
HWND				G::Window;
bool				G::PressedKeys[ 256 ] = {};
bool				G::d3dinit = false;
float				G::FOV;
int					G::ChamMode = -1;
bool				G::SendPacket = true;
int					G::BestTarget = -1;
bool				G::KillStop = false;
DWORD				G::KillStopDelay = NULL;


VTHook*				H::VPanel;
VTHook*				H::ClientMode;
VTHook*				H::Client;
VTHook*				H::ModelRender;
VTHook*				H::Surface;
VTHook*				H::GameEvent;
VTHook*				H::D3D9;

CLegitBot*			E::LegitBot = new CLegitBot();
CRageBot*			E::RageBot = new CRageBot();
CVisuals*			E::Visuals = new CVisuals();
CMiscellaneous*		E::Misc = new CMiscellaneous();
CFakeLag*			E::FakeLag = new CFakeLag();
CClantagChanger*	E::ClantagChanger = new CClantagChanger();
CNameChanger*		E::NameChanger = new CNameChanger();
