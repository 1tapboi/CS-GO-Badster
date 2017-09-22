#include "../Cheat.h"

CPredictionSystem* PredictionSystem = new CPredictionSystem;

void CPredictionSystem::StartPrediction()
{
	static bool bInit = false;
	if (!bInit) {
		m_pPredictionRandomSeed = *(int**)(U::FindPattern("client.dll", "8B 0D ? ? ? ? BA ? ? ? ? E8 ? ? ? ? 83 C4 04") + 2);
		bInit = true;
	}
	
	
	*m_pPredictionRandomSeed = MD5_PseudoRandom(G::UserCmd->command_number) & 0x7FFFFFFF;

	m_flOldCurtime = I::Globals->curtime;
	m_flOldFrametime = I::Globals->frametime;

	I::Globals->curtime = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;
	I::Globals->frametime = I::Globals->interval_per_tick;

	I::GameMovement->StartTrackPredictionErrors(G::LocalPlayer);
	
	memset(&m_MoveData, 0, sizeof(m_MoveData));
	I::MoveHelper->SetHost(G::LocalPlayer);
	I::Prediction->SetupMove(G::LocalPlayer, G::UserCmd, I::MoveHelper, &m_MoveData);
	I::GameMovement->ProcessMovement(G::LocalPlayer, &m_MoveData);
	I::Prediction->FinishMove(G::LocalPlayer, G::UserCmd, &m_MoveData);
}

void CPredictionSystem::EndPrediction()
{
	I::GameMovement->FinishTrackPredictionErrors(G::LocalPlayer);
	I::MoveHelper->SetHost(0);

	*m_pPredictionRandomSeed = -1;
	I::Globals->curtime = m_flOldCurtime;
	I::Globals->frametime = m_flOldFrametime;
}