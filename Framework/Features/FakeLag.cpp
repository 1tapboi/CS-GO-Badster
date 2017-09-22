#include "../Cheat.h"

CFakeLag* FakeLag;

void CFakeLag::Run()
{
	if (Vars.Misc.FakeLag <= 0)
		return;

	if (!I::Engine->IsInGame())
		return;

	if (G::UserCmd->buttons & IN_ATTACK)
	{
		G::SendPacket = true;
		return;
	}

	if (ticks >= ticksMax)
	{
		G::SendPacket = true;
		ticks = 0;
	}
	else
	{
		G::SendPacket = ticks < ticksMax - Vars.Misc.FakeLag;
	}

	ticks++;
}