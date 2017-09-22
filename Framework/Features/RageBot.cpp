#include "../Cheat.h"

float m_bestfov = 360.0f;
float m_bestdist = 8192.f;
float m_bestthreat = 0.f;
Vector m_besthitbox = Vector( 0, 0, 0 );
CBaseEntity* m_bestent = nullptr;
bool m_target = false;
QAngle AimStepLastAngle;

std::unordered_map<int, std::vector<const char*>> hitboxes = {
		{ HITBOX_HEAD, { "head_0" } },
		{ HITBOX_NECK, { "neck_0" } },
		{ HITBOX_PELVIS, { "pelvis" } },
		{ HITBOX_SPINE, { "spine_0", "spine_1", "spine_2", "spine_3" } },
		{ HITBOX_LEGS,{ "leg_upper_L", "leg_upper_R", "leg_lower_L", "leg_lower_R", "ankle_L", "ankle_R" } },
		{ HITBOX_ARMS,{ "hand_L", "hand_R", "arm_upper_L", "arm_lower_L", "arm_upper_R", "arm_lower_R" } },
};

void CRageBot::Run()
{
	QAngle oldAngle;
	I::Engine->GetViewAngles(oldAngle);
	oldForward = G::UserCmd->forwardmove;
	oldSideMove = G::UserCmd->sidemove;
	
	if (!Vars.Ragebot.Enabled)
		return;

	DropTarget();

	if( !G::LocalPlayer->GetWeapon()->IsGun() || G::LocalPlayer->GetWeapon()->IsEmpty() )
		return;

	if( G::BestTarget == -1 )
		FindTarget();

	if( Vars.Ragebot.OnKey && !G::PressedKeys[ Vars.Ragebot.Key ] )
		return;

	if( G::BestTarget != -1 && !G::LocalPlayer->GetWeapon()->IsReloading() && m_target )
		GoToTarget();
	
	M::CorrectMovement(oldAngle, G::UserCmd, oldForward, oldSideMove);	
}

void CRageBot::GetBestBone(CBaseEntity* entity, float& best_damage, Bone& best_bone)
{
	best_bone = BONE_HEAD;

	for (std::unordered_map<int, std::vector<const char*>>::iterator it = hitboxes.begin(); it != hitboxes.end(); it++)
	{
		if (!Vars.Ragebot.bones[it->first])
			continue;

		std::vector<const char*> hitboxList = hitboxes[it->first];
		for (std::vector<const char*>::iterator it2 = hitboxList.begin(); it2 != hitboxList.end(); it2++)
		{
			Bone bone = (Bone)entity->GetBoneByName( *it2 );
			Vector vec_bone = entity->GetBonePosition(bone);

			float damage = AutoWall->GetDamages(vec_bone);

			if (damage > best_damage)
			{
				best_damage = damage;
				best_bone = bone;
			}
		}
	}
}

void CRageBot::FindTarget()
{
	m_bestfov = Vars.Ragebot.FOV;
	m_bestdist = 8192.f;
	m_bestthreat = 0.f;
	m_besthitbox = Vector(0, 0, 0);
	m_target = false;
	m_bestent = nullptr;

	for (int i = 0; i <= I::Globals->maxClients; i++)
	{
		if (!EntityIsValid(i))
			continue;

		CBaseEntity* Entity = I::ClientEntList->GetClientEntity(i);
		Vector hitbox = Entity->GetBonePosition(Vars.Ragebot.Hitbox);

		QAngle viewAngles;
		I::Engine->GetViewAngles(viewAngles);

		if (Vars.Ragebot.Mode == 0)
		{
			float fov = M::GetFov(viewAngles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), hitbox));
			if (fov < m_bestfov)
			{
				G::BestTarget = i;
				if (Vars.Ragebot.HitscanAll)
				{
					float damage = 0.0f;
					Bone bone;
					GetBestBone(Entity, damage, bone);

					if (damage >= Vars.Ragebot.AutoWallAmount)
					{
						m_bestent = Entity;
						m_besthitbox = Entity->GetBonePosition(bone);
						m_target = true;
					}
				}
				else if (Vars.Ragebot.HitscanHitbox)
				{
					if (BestAimPointHitbox(Entity, m_besthitbox))
						m_target = true;
				}
				else
				{
					m_bestent = Entity;
					m_bestfov = fov;
					m_besthitbox = hitbox;
					m_target = true;
				}
			}
		}

		if (Vars.Ragebot.Mode == 1)
		{
			float fov = M::GetFov(viewAngles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), hitbox));
			float dist = M::VectorDistance(G::LocalPlayer->GetOrigin(), Entity->GetOrigin());
			if (dist < m_bestdist && fov < m_bestfov)
			{
				G::BestTarget = i;
				if (Vars.Ragebot.HitscanAll)
				{
					float damage = 0.0f;
					Bone bone;
					GetBestBone(Entity, damage, bone);

					if (damage >= Vars.Ragebot.AutoWallAmount)
					{
						m_bestent = Entity;
						m_besthitbox = Entity->GetBonePosition(bone);
						m_target = true;
					}
				}
				else if (Vars.Ragebot.HitscanHitbox)
				{
					if (BestAimPointHitbox(Entity, m_besthitbox))
						m_target = true;
				}
				else
				{
					m_bestent = Entity;
					m_bestdist = dist;
					m_besthitbox = hitbox;
					m_target = true;
				}
			}
		}

		if (Vars.Ragebot.Mode == 2)
		{
			float fov = M::GetFov(viewAngles, M::CalcAngle(G::LocalPlayer->GetEyePosition(), hitbox));
			float dist = M::VectorDistance(G::LocalPlayer->GetOrigin(), Entity->GetOrigin());
			float health = (float)Entity->GetHealth();

			float threat = health / dist;

			if (Entity->IsTargetingLocal())
				threat += 100;

			int memes = 0;

			if (threat > m_bestthreat && fov < m_bestfov)
			{
				G::BestTarget = i;
				if (Vars.Ragebot.HitscanAll)
				{
					float damage = 0.0f;
					Bone bone;
					GetBestBone(Entity, damage, bone);

					if (damage >= Vars.Ragebot.AutoWallAmount)
					{
						m_bestent = Entity;
						m_besthitbox = Entity->GetBonePosition(bone);
						m_target = true;
					}
				}
				else if (Vars.Ragebot.HitscanHitbox)
				{
					if (BestAimPointHitbox(Entity, m_besthitbox))
						m_target = true;

					else if (Vars.Ragebot.HitscanHeadshot)
					{
						switch (memes)
						{
						case 1:m_besthitbox.y - 15; break;
						case 2:m_besthitbox.y + 40; break;
						case 3:m_besthitbox.y - 40; break;
						case 4:m_besthitbox.y + 15; memes = 0; break;
						}
						memes++;
					}
				}
				else
				{
					m_bestent = Entity;
					m_bestthreat = threat;
					m_besthitbox = hitbox;
					m_target = true;
				}
			}
		}
	}
}

void CRageBot::GoToTarget()
{
	bool auto_shoot = false;
	bool can_shoot = true;
	bool reloading = false;

	if (!Vars.Ragebot.Enabled)
		return;

	auto weapon = G::LocalPlayer->GetWeapon();
	float server_time = G::LocalPlayer->GetTickBase() * I::Globals->interval_per_tick;

	float next_shot = weapon->GetNextPrimaryAttack() - server_time;
	if( next_shot > 0 || (Vars.Ragebot.ShootWhenStopped && G::LocalPlayer->GetVelocity().Length() > 60) )
		can_shoot = false;

	QAngle aim_angle = M::CalcAngle( G::LocalPlayer->GetEyePosition(), m_besthitbox );

	switch (Vars.Ragebot.RCS)
	{
	case 0:
		break;
	case 1:
		aim_angle -= G::LocalPlayer->GetPunch() * 2.f;
		break;
	case 2:
		aim_angle -= (G::LocalPlayer->GetPunch() * (2.f + (Vars.Ragebot.RCShow / 50.f)));
		break;
	}
	
	if ( can_shoot )
	{
		if ( Vars.Ragebot.AimStep )
		{
			auto_shoot = AimStep( aim_angle );
			if ( auto_shoot )
			G::UserCmd->viewangles = aim_angle;
		}
		else
		{
			auto_shoot = true;
			G::UserCmd->viewangles = aim_angle;
		}
	}
	
	
	if( Vars.Ragebot.AutoStop )
	{
		if (!Vars.Ragebot.ShootWhenStopped && (!Vars.Ragebot.AutoStopCanShoot || can_shoot))
		{
			if (!Vars.Ragebot.AutoStopFast || G::LocalPlayer->GetVelocity().Length() <= 60)
			{
				oldForward = 0;
				oldSideMove = 0;
				G::UserCmd->upmove = 0;
			}
			else
			{
				oldForward = -oldForward;
				oldSideMove = -oldSideMove;
				G::UserCmd->upmove = 0;
				auto_shoot = false;
			}
		}
	}
	
	if( Vars.Ragebot.AutoCrouch )
		G::UserCmd->buttons |= IN_DUCK;

	float hitchance = 75.f + ( Vars.Ragebot.HitchanceAmount / 4 );

	if( auto_shoot && can_shoot && Vars.Ragebot.AutoFire && ( !Vars.Ragebot.Hitchance || ( 1.0f - G::LocalPlayer->GetWeapon()->GetAccuracyPenalty() ) * 100.f >= hitchance ) )
		G::UserCmd->buttons |= IN_ATTACK;
		
	if (weapon->IsSniper() && Vars.Ragebot.AutoScope)
	{
		if (!G::LocalPlayer->IsScoped())
		{	
			G::UserCmd->buttons &= ~IN_ATTACK;
			G::UserCmd->buttons |= IN_ZOOM;
		}
	}
}

void CRageBot::DropTarget()
{
	if( !EntityIsValid( G::BestTarget ) ||  Vars.Ragebot.HitscanAll || Vars.Ragebot.HitscanHitbox || Vars.Ragebot.Hitscan)
		G::BestTarget = -1;
}

bool CRageBot::AimStep( QAngle& angle )
{
	if ( !G::Aimbotting )
		AimStepLastAngle = G::UserCmd->viewangles;

	float fov = M::GetFov(AimStepLastAngle, angle);

	G::Aimbotting = fov > Vars.Ragebot.AimStepAmount;

	if (!G::Aimbotting)
		return true;

	QAngle AimStepDelta = AimStepLastAngle - angle;

	if (AimStepDelta.y < 0)
		AimStepLastAngle.y += Vars.Ragebot.AimStepAmount;
	else
		AimStepLastAngle.y -= Vars.Ragebot.AimStepAmount;

	AimStepLastAngle.x = angle.x;
	angle = AimStepLastAngle;
	
	return false;
}

bool CRageBot::GetHitbox( CBaseEntity* target, Hitbox* hitbox )
{
	matrix3x4a_t matrix[ MAXSTUDIOBONES ];

	if( !target->SetupBones( matrix, MAXSTUDIOBONES, BONE_USED_BY_HITBOX, 0 ) )
		return false;


	studiohdr_t *hdr = I::ModelInfo->GetStudioModel( target->GetModel() );

	if( !hdr )
		return false;

	mstudiohitboxset_t *hitboxSet = hdr->pHitboxSet( target->GetHitboxSet() );
	mstudiobbox_t *untransformedBox = hitboxSet->pHitbox( hitbox->hitbox );

	Vector bbmin = untransformedBox->bbmin;
	Vector bbmax = untransformedBox->bbmax;

	if( untransformedBox->radius != -1.f )
	{
		bbmin -= Vector( untransformedBox->radius, untransformedBox->radius, untransformedBox->radius );
		bbmax += Vector( untransformedBox->radius, untransformedBox->radius, untransformedBox->radius );
	}

	Vector points[] = { ( ( bbmin + bbmax ) * .5f ),
		Vector( bbmin.x, bbmin.y, bbmin.z ),
		Vector( bbmin.x, bbmax.y, bbmin.z ),
		Vector( bbmax.x, bbmax.y, bbmin.z ),
		Vector( bbmax.x, bbmin.y, bbmin.z ),
		Vector( bbmax.x, bbmax.y, bbmax.z ),
		Vector( bbmin.x, bbmax.y, bbmax.z ),
		Vector( bbmin.x, bbmin.y, bbmax.z ),
		Vector( bbmax.x, bbmin.y, bbmax.z ) };


	for( int index = 0; index <= 8; ++index )
	{
		if( index != 0 )
			points[ index ] = ( ( ( ( points[ index ] + points[ 0 ] ) * .5f ) + points[ index ] ) * .5f );

		M::VectorTransform( points[ index ], matrix[ untransformedBox->bone ], hitbox->points[ index ] );
	}

	return true;
}

bool CRageBot::GetBestPoint( CBaseEntity* target, Hitbox* hitbox, BestPoint *point )
{
	Vector center = hitbox->points[ 0 ];

	if( hitbox->hitbox == HITBOX_HEAD )
	{
		Vector high = ( ( hitbox->points[ 3 ] + hitbox->points[ 5 ] ) * .5f );

		float pitch = target->GetEyeAngles().x;
		if( ( pitch > 0.f ) && ( pitch <= 89.f ) )
		{
			Vector height		= ( ( ( high - hitbox->points[ 0 ] ) / 3 ) * 4 );
			Vector new_height	= ( hitbox->points[ 0 ] + ( height * ( pitch / 89.f ) ) );

			hitbox->points[ 0 ] = new_height;
			point->flags |= FL_HIGH;
		}
		else if( ( pitch < 292.5f ) && ( pitch >= 271.f ) )
		{
			hitbox->points[ 0 ] -= Vector( 0.f, 0.f, 1.f );
			point->flags |= FL_LOW;
		}
	}

	for( int index = 0; index <= 8; ++index )
	{
		int temp_damage = AutoWall->GetDamages( hitbox->points[ index ] );

		if( ( point->dmg < temp_damage ) )
		{
			point->dmg = temp_damage;
			point->point = hitbox->points[ index ];
			point->index = index;
		}
	}

	return ( point->dmg > Vars.Ragebot.AutoWallAmount);
}

bool CRageBot::BestAimPointHitbox( CBaseEntity* target, Vector& hitbox )
{
	BestPoint aim_point;

	int hitboxnum = 0;

	switch( Vars.Ragebot.Hitbox )
	{
	case 0:
		hitboxnum = 3;
		break;
	case 1:
		hitboxnum = 6;
		break;
	case 2:
	case 3:
		hitboxnum = 4;
		break;
	case 4:
		hitboxnum = 7;
		break;
	case 5:
		hitboxnum = 1;
		break;
	case 6:
		hitboxnum = 0;
		break;
	default:
		hitboxnum = 0;
		break;
	}

	Hitbox hitboxx( hitboxnum );
	GetHitbox( target, &hitboxx );

	if( !GetBestPoint( target, &hitboxx, &aim_point ) )
		return false;

	if( aim_point.dmg > Vars.Ragebot.AutoWallAmount)
	{
		hitbox = aim_point.point;
		return true;
	}

	return false;
}

bool CRageBot::EntityIsValid( int i )
{
	CBaseEntity* Entity = I::ClientEntList->GetClientEntity( i );

	player_info_t pInfo;
	I::Engine->GetPlayerInfo(i, &pInfo);

	if (strcmp(pInfo.guid, "STEAM_ID") == 0)
		return false;
	if( !Entity )
		return false;
	if( Entity == G::LocalPlayer )
		return false;

	if( !Vars.Ragebot.FriendlyFire )
	{
		if( Entity->GetTeam() == G::LocalPlayer->GetTeam() )
			return false;
	}

	if( Entity->GetDormant() )
		return false;
	if( Entity->GetImmune() )
		return false;
	if( Entity->GetHealth() <= 0 )
		return false;

	if( !Vars.Ragebot.HitscanAll && !Vars.Ragebot.HitscanHitbox )
	{
		if( Vars.Ragebot.AutoWallAmount > AutoWall->GetDamages( Entity->GetBonePosition( Vars.Ragebot.Hitbox ) ) )
			return false;
	}

	return true;
}
