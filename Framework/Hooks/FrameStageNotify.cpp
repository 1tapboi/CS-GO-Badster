#include "../Cheat.h"
#include "../SkinChanger.h"

struct PlayerAA
{
	CBaseEntity* player;
	QAngle angle;

	PlayerAA(CBaseEntity* player, QAngle angle)
	{
		this->player = player;
		this->angle = angle;
	}
};
std::vector<PlayerAA> player_data;

FrameStageNotifyFn oFrameStageNotify;
void __stdcall Hooks::FrameStageNotify( ClientFrameStage_t stage )
{
	{
		if( Vars.Ragebot.Antiaim.Resolver && I::Engine->IsInGame() && stage == FRAME_NET_UPDATE_POSTDATAUPDATE_START)
		{
			if( G::LocalPlayer && G::LocalPlayer->GetAlive() )
			{
				for( int i = 0; i <= I::Globals->maxClients; i++ )
				{
					CBaseEntity* Entity = I::ClientEntList->GetClientEntity( i );

					if( !Entity
						|| Entity == G::LocalPlayer
						|| Entity->GetTeam() == G::LocalPlayer->GetTeam()
						|| Entity->GetHealth() <= 0
						|| Entity->GetDormant()
						|| Entity->GetImmune() )
						continue;
					
					player_data.push_back( PlayerAA(Entity, *Entity->GetHeadRotation()) );
					
					Entity->GetHeadRotation()->y = *Entity->GetLowerBodyYawTarget();
				}
			}
		}
		else if (stage == FRAME_RENDER_END)
		{
			for (unsigned long i = 0; i < player_data.size(); i++)
			{
				PlayerAA player_aa_data = player_data[i];

				*player_aa_data.player->GetHeadRotation() = player_aa_data.angle;
			}

			player_data.clear();
		}
	}

	QAngle aim_punch_old;
	QAngle view_punch_old;

	QAngle* aim_punch = nullptr;
	QAngle* view_punch = nullptr;

	if( I::Engine->IsInGame() && stage == FRAME_RENDER_START && Vars.Visuals.RemovalsVisualRecoil )
	{
		if( G::LocalPlayer && G::LocalPlayer->GetAlive() )
		{
			aim_punch = ( QAngle* )( ( DWORD )G::LocalPlayer + offsets.m_aimPunchAngle );
			view_punch = ( QAngle* )( ( DWORD )G::LocalPlayer + offsets.m_viewPunchAngle );

			aim_punch_old = *aim_punch;
			view_punch_old = *view_punch;

			*aim_punch = QAngle( 0, 0, 0 );
			*view_punch = QAngle( 0, 0, 0 );
		}
	}

	//SkinChanger::FrameStageNotify(stage);

	oFrameStageNotify( stage );

	SkinChanger::FrameStageNotify(stage);




	if( aim_punch && view_punch && Vars.Visuals.RemovalsVisualRecoil )
	{
		*aim_punch = aim_punch_old;
		*view_punch = view_punch_old;
	}
	//return oFrameStageNotify(stage);
}