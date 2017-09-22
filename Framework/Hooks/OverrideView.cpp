#include "../Cheat.h"

OverrideViewFn oOverrideView;
void __stdcall Hooks::OverrideView( CViewSetup* vsView )
{
	int SFOV = vsView->fov;
	if (I::Engine->IsInGame())
	{
		if (!G::LocalPlayer->IsScoped())
			vsView->fov = SFOV + Vars.Misc.FOV;
		else
			vsView->fov = SFOV;
	}

	G::FOV = vsView->fov;

	oOverrideView( vsView );
}