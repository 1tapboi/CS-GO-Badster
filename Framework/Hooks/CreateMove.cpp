#include "../Cheat.h"

CreateMoveFn oCreateMove;
bool __stdcall Hooks::CreateMove( float flInputSampleTime, CUserCmd* cmd )
{
	G::LocalPlayer = U::GetLocalPlayer();
	G::UserCmd = cmd;

	if( Vars.Ragebot.Enabled ) Vars.Legitbot.Aimbot.Enabled = false;
	else if( Vars.Legitbot.Aimbot.Enabled ) Vars.Ragebot.Enabled = false;

	if( cmd->command_number == 0 || !I::Engine->IsInGame() )
		return false;

	if( !G::LocalPlayer || !G::LocalPlayer->GetAlive() )
		return G::Return;

	DWORD* framePointer;
	__asm mov framePointer, ebp;
	*( bool* )( *framePointer - 0x1C ) = G::SendPacket;
	
	G::SendPacket = true;

	if (Vars.Misc.Bunnyhop)
		E::Misc->Bunnyhop();

	if (Vars.Misc.Autostrafe)
	{
		switch (Vars.Misc.AutostrafeTypes)
		{
		case 0:
			E::Misc->LegitStrafe();
			break;
		case 1:
			E::Misc->LegitStrafe();
			break;
		case 2:
			E::Misc->LegitStrafe();
			break;
		case 3:
			E::Misc->LegitStrafe();
			break;
		case 4:
			E::Misc->RageStrafe();
			break;
		}
	}

	PredictionSystem->StartPrediction();

	E::LegitBot->Run();

	if( Vars.Ragebot.Enabled )
		E::RageBot->Run();
		
	if( Vars.Ragebot.Antiaim.Enabled )
		AntiAim->Run();

	if( Vars.Misc.AirStuck )
		E::Misc->AirStuck();
		
	if (Vars.Ragebot.AntiUntrusted)
		cmd->viewangles.Clamp();


	E::FakeLag->Run();
	
	PredictionSystem->EndPrediction();
	
		if (Vars.Misc.ColourNickname)
			E::Misc->ChangeCName();

		if (Vars.Misc.ChatSpam)
			E::Misc->Chatspam();

		if (Vars.Misc.LocationSpam)
			E::Misc->Run_LocationSpam();

		//if (Vars.Misc.NameSteal)
			//E::Misc->NameSteal();

	if (Vars.Ragebot.AntiUntrusted)
		cmd->viewangles.Clamp();

	bool rcs;
	bool psalo;
	bool salo;
	if (G::LocalPlayer->GetWeapon()->IsPistol() && Vars.Legitbot.Aimbot.Enabled)
	{
		rcs = Vars.Legitbot.pistols.RCSEnabled;
		psalo = Vars.Legitbot.pistols.pSilent;
		salo = Vars.Legitbot.pistols.pSilent;
	}
	else if (G::LocalPlayer->GetWeapon()->IsSniper() && Vars.Legitbot.Aimbot.Enabled) {
		psalo = Vars.Legitbot.snipers.pSilent;
		salo = Vars.Legitbot.snipers.pSilent;
	}
	else if (Vars.Legitbot.Aimbot.Enabled)
	{
		psalo = false;
		salo = false;
	}

	if (psalo && (G::LocalPlayer->GetWeapon()->IsPistol() || G::LocalPlayer->GetWeapon()->IsSniper()) && Vars.Legitbot.Aimbot.Enabled)
	{

		if (G::LocalPlayer->GetShotsFired() <= 1 && G::UserCmd->buttons & IN_ATTACK)
		{
			G::SendPacket = false;
		}
		else
		{
			G::SendPacket = true;
		}
	}

	if (Vars.Visuals.RemovalsVisualRecoil && rcs && Vars.Legitbot.Aimbot.Enabled)
		return false;

	if ((!Vars.Ragebot.Silent && Vars.Ragebot.Enabled))
		I::Engine->SetViewAngles(G::UserCmd->viewangles);

	if ((G::LocalPlayer->GetShotsFired() > 1 && psalo))
		I::Engine->SetViewAngles(G::UserCmd->viewangles);

	if ((!salo && !Vars.Ragebot.Enabled))
		I::Engine->SetViewAngles(G::UserCmd->viewangles);

	return false;
}