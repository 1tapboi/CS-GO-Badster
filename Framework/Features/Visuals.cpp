#include "../Cheat.h"

//#define TEXTURE_GROUP_CLIENT_EFFECTS				"ClientEffect textures"

void CVisuals::Run()
{
	if (I::Engine->IsTakingScreenshot())
		return;

	if( Vars.Visuals.Watermark )
		E::Visuals->Watermark();

	if( !InGame() )
		return;

	if( !Vars.Visuals.Enabled )
		return;

	if ( Vars.Visuals.FOVCircle)
		FOVCrosshair();

	if ( Vars.Visuals.Radar.Enabled )
		D::ShowRadar(Vars.Visuals.Radar.X, Vars.Visuals.Radar.Y, Vars.Visuals.Radar.Size);

	static bool crosshair = false;

	if (Vars.Visuals.Dlight)
		Dlight();

	if( Vars.Visuals.CrosshairEnabled )
	{
		DrawCrosshair( Color::Red() );
		if( !crosshair )
		{
			I::Engine->ClientCmd_Unrestricted( charenc( "crosshair 0" ) );
			crosshair = true;
		}
			
	}
	else
	{
		if( crosshair )
		{
			I::Engine->ClientCmd_Unrestricted( charenc( "crosshair 1" ) );
			crosshair = false;
		}
	}

	BombCarrier = nullptr;

	for( int i = 0; i < I::ClientEntList->GetHighestEntityIndex(); i++ )
	{
		PlayerESP( i );
		WorldESP( i );
		RadarEntity( i );
	}
}


void CVisuals::Dlight()
{
	if (!I::Engine->IsInGame())
		return;

	for (int i = 1; i < I::Engine->GetMaxClients(); ++i)
	{
		CBaseEntity* Entity = I::ClientEntList->GetClientEntity(i);

		if (!(Entity))
			continue;

		if (Entity == G::LocalPlayer)
			continue;

		dlight_t* dLight = I::Ceffect->CL_AllocDlight(i);
		dLight->key = i;
		dLight->color.r = Vars.Visuals.collight.r;
		dLight->color.g = Vars.Visuals.collight.g;
		dLight->color.b = Vars.Visuals.collight.b;
		dLight->color.exponent = true;
		dLight->flags = DLIGHT_NO_MODEL_ILLUMINATION;
		dLight->m_Direction = Entity->GetOrigin();
		dLight->origin = Entity->GetOrigin();
		dLight->radius = Vars.Visuals.RadiusDlight;
		dLight->die = I::Globals->curtime + 0.1f;
		dLight->decay = 20.0f;
	}
}

void CVisuals::RadarEntity(int index)
{
	if (!Vars.Visuals.Radar.Enabled)
		return;

		CBaseEntity* Entity = I::ClientEntList->GetClientEntity(index);

		if (EntityIsInvalid(Entity))
			return;

		if (!Entity->IsEnemy())
			return;

		QAngle LocalAngles;
		I::Engine->GetViewAngles(LocalAngles);

		int G = Entity->GetHealth() / 100.f * 255.f;
		int R = 255.f - G;
		int B = 0.f;
		D::DrawRadarEntity(Vars.Visuals.Radar.X, Vars.Visuals.Radar.Y, Vars.Visuals.Radar.Size, Color(R, G, B), G::LocalPlayer->GetOrigin(), Entity->GetOrigin(), LocalAngles, Entity->GetHealth(), false);
}

void Line(Vector2D start_pos, Vector2D end_pos, Color col)
{
	D::DrawLine(start_pos.x, start_pos.y, end_pos.x, end_pos.y, col);
}

void Circle(Vector2D position, float points, float radius, Color color)
{
	float step = (float)M_PI * 2.0f / points;

	for (float a = 0; a < (M_PI * 2.0f); a += step)
	{
		Vector2D start(radius * cosf(a) + position.x, radius * sinf(a) + position.y);
		Vector2D end(radius * cosf(a + step) + position.x, radius * sinf(a + step) + position.y);
		Line(start, end, color);
	}
}

void CVisuals::FOVCrosshair()
{
	if (!G::LocalPlayer->GetAlive())
		return;

	int width, height;
	I::Engine->GetScreenSize(width, height);

	int fov;

	if (G::LocalPlayer->GetWeapon()->IsPistol())
		fov = Vars.Legitbot.pistols.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsRifle())
		fov = Vars.Legitbot.rifles.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsSmg())
		fov = Vars.Legitbot.smg.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsShotgun())
		fov = Vars.Legitbot.shotguns.FOV;
	else if (G::LocalPlayer->GetWeapon()->IsSniper())
		fov = Vars.Legitbot.snipers.FOV;
	else if (!G::LocalPlayer->GetWeapon()->IsGun())
		fov = 360;

	float radAimbotFov = (float)(fov * M_PI / 180);
	float radViewFov = (float)(G::FOV * M_PI / 180);

	float circleRadius = tanf(radAimbotFov / 2) / tanf(radViewFov / 2) * width;
	#define LOC(x,y) Vector2D(x,y)
	Circle(LOC(width / 2, height / 2), 20, circleRadius, Color::White());
}

std::list<int> GetObservervators(int playerId)
{
	std::list<int> list;

	if (!I::Engine->IsInGame())
		return list;

	CBaseEntity* player = (CBaseEntity*)I::ClientEntList->GetClientEntity(playerId);
	if (!player)
		return list;

	if (!player->GetAlive())
	{
		CBaseEntity* observerTarget = (CBaseEntity*)I::ClientEntList->GetClientEntityFromHandle(player->GetObserverTargetHandle());
		if (!observerTarget)
			return list;

		player = observerTarget;
	}

	for (int i = 1; i < I::Engine->GetMaxClients(); i++)
	{
		CBaseEntity* pPlayer = (CBaseEntity*)I::ClientEntList->GetClientEntity(i);
		if (!pPlayer)
			continue;

		if (pPlayer->GetDormant() || pPlayer->GetAlive())
			continue;

		CBaseEntity* target = (CBaseEntity*)I::ClientEntList->GetClientEntityFromHandle(pPlayer->GetObserverTargetHandle());
		if (player != target)
			continue;

		list.push_back(i);
	}

	return list;
}

const char* ranks[] = {
	"Unranked",
	"Silver I",
	"Silver II",
	"Silver III",
	"Silver IV",
	"Silver Elite",
	"Silver Elite Master",

	"Gold Nova I",
	"Gold Nova II",
	"Gold Nova III",
	"Gold Nova Master",
	"Master Guardian I",
	"Master Guardian II",

	"Master Guardian Elite",
	"Distinguished Master Guardian",
	"Legendary Eagle",
	"Legendary Eagle Master",
	"Supreme Master First Class",
	"The Global Elite"
};

void CVisuals::SpectatorsTab()
{
	if (!Vars.Visuals.SpectatorsTab)
		return;

	if (!I::Engine->IsInGame())
		return;

	if (ImGui::Begin("Spectators", &Vars.Visuals.SpectatorsTab, ImVec2(300, 300), 0.9f, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders))
	{
		ImGui::Separator();

		for (int playerId : GetObservervators(I::Engine->GetLocalPlayer()))
		{
			CBaseEntity* player = (CBaseEntity*)I::ClientEntList->GetClientEntity(playerId);

			player_info_t entityInformation;
			I::Engine->GetPlayerInfo(playerId, &entityInformation);

			char* bufix;
			switch (player->GetTeam())
			{
			case 0:
				bufix = "[NO TEAM]";
				break;
			case 1:
				bufix = "[SPECTATOR]";
				break;
			case 2:
				bufix = "[TERRORIST]";
				break;
			case 3:
				bufix = "[COUNTER-TERRORIST]";
				break;
			}

			char buf[255]; sprintf_s(buf, "%s | %s", entityInformation.name, bufix);
			ImGui::Text("%s", buf);
		}

		ImGui::Separator();

		ImGui::End();
	}
}

void SnapRotate(int x, int y, int _x, int _y, int& ox, int& oy) {
	ox = _x - x;
	oy = _y - y;

	double ang = atan2(oy, ox);

	double xx = cos(ang - 1.57f);
	double yy = -cos(ang);

	ox = (int)(xx > 0 ? ceil(xx) : floor(xx));
	oy = (int)(yy > 0 ? ceil(yy) : floor(yy));
}
unsigned long Font[14];

/*void CreateFont(HFont fIndex, const char* pFontName, int iSize, int iWeight, int iFlags) {
	Font[fIndex] = ISurface()->CreateFont();
	ISurface()->SetFontGlyphSet(Font[fIndex], pFontName, iSize, iWeight, 0, 0, iFlags, 0, 0);
}*/

void CVisuals::PlayerESP( int index )
{
	CBaseEntity* Entity = I::ClientEntList->GetClientEntity( index );

	player_info_t pInfo;
	I::Engine->GetPlayerInfo(index, &pInfo);

	if (strcmp(pInfo.guid, "STEAM_ID") == 0)
		return;

	if( EntityIsInvalid( Entity ) )
		return;

	if( !Vars.Visuals.Filter.Friendlies && !Entity->IsEnemy() )
		return;

	if( !Vars.Visuals.Enabled && Entity->IsEnemy() )
		return;

	Vector max = Entity->GetCollideable()->OBBMaxs();
	Vector pos, pos3D;
	Vector top, top3D;
	pos3D = Entity->GetOrigin();
	top3D = pos3D + Vector( 0, 0, max.z );
	if( !D::WorldToScreen( pos3D, pos ) || !D::WorldToScreen( top3D, top ) )
		return;

	float height = ( pos.y - top.y );
	float width = height / 4.f;

	if( Entity->GetClientClass()->m_ClassID == 83 )
	{
		if( Vars.Visuals.InfoName )
			D::DrawString(F::ESP, top.x, top.y + 3, Color::Green(), FONT_CENTER, charenc("Hostage"));
			
		return;
	}

	int iScreenWidth, iScreenHeight;
	I::Engine->GetScreenSize( iScreenWidth, iScreenHeight );
	int iMiddle = (pos.y - top.y) + 4;
	int iWidth = iMiddle / 3.5;

	if( Vars.Visuals.Skeleton )
		Skeleton( Entity, Color::White() );


	if (Vars.Visuals.colorsNV2D == 0 && Vars.Visuals.colorsV2D == 0)
	{
		if (Entity->IsVisible(6) && Vars.Visuals.Box2D)
			PlayerBox(top.x, top.y, width, height, Entity->GetTeam() == 2 ? Color(5, 200, 5) : Color(5, 200, 5));
		else if (!Entity->IsVisible(6) && Vars.Visuals.Box2D)
			PlayerBox(top.x, top.y, width, height, Entity->GetTeam() == 2 ? Color(200, 5, 5) : Color(200, 5, 5));
	}
	else
	{
		if (Entity->IsVisible(6) && Vars.Visuals.Box2D)
			PlayerBox(top.x, top.y, width, height, Entity->GetTeam() == 2 ? Color(Vars.Visuals.colV2D.r, Vars.Visuals.colV2D.g, Vars.Visuals.colV2D.b) : Color(Vars.Visuals.colV2D.r, Vars.Visuals.colV2D.g, Vars.Visuals.colV2D.b));
		else if (!Entity->IsVisible(6) && Vars.Visuals.Box2D)
			PlayerBox(top.x, top.y, width, height, Entity->GetTeam() == 2 ? Color(Vars.Visuals.colNV2D.r, Vars.Visuals.colNV2D.g, Vars.Visuals.colNV2D.b) : Color(Vars.Visuals.colNV2D.r, Vars.Visuals.colNV2D.g, Vars.Visuals.colNV2D.b));
	}

	if( Vars.Visuals.InfoName )
		D::DrawString( F::ESP, top.x, top.y - 6, Color::White(), FONT_CENTER, "%s", Entity->GetName().c_str() );

	if (Vars.Visuals.Box3D)
	{
		int r, g, b;

		if (Entity->IsVisible(6))
			Entity->GetTeam() == 2 ? r = 247, g = 180,  b = 20 : r = 32, g = 180, b = 57;
		else
			Entity->GetTeam() == 2 ? r = 240, g = 30, b = 35 : r = 63, g = 72, b = 205;

		I::DebugOverlay->AddBoxOverlay(Entity->GetOrigin(), Entity->GetCollideable()->OBBMaxs(), Entity->GetCollideable()->OBBMins(), Entity->GetEyeAngles() / 55, r, g, b, 40, I::Globals->frametime + 0.02);
	}

	if (Vars.Visuals.InfoHealth) {
		RECT TextSizeHP = D::GetTextSize(F::ESP, "HP : 100");
		RECT TextSizeA = D::GetTextSize(F::ESP, "AP : 100");
        HealthBar(pos, top, Entity->GetHealth());

	if (Vars.Visuals.BulletTrace)
		BulletTrace(Entity, Color(200, 50, 50, 150));

	int bottom = 0;

	if (Vars.Visuals.InfoArmor)
	{
		if (Entity->GetArmor() >= 1)
		{
			ArmorBar(pos, top, Entity->GetArmor());
		}
	}

	if (Vars.Visuals.Tracers && Entity->GetTeam() != G::LocalPlayer->GetTeam())
	{
		int iMiddle3 = (pos.y - top.y);
		int ox, oy = 0;
		SnapRotate(iScreenWidth / 2, iScreenHeight, top.x, top.y + iMiddle3 - 1, ox, oy);
		D::DrawLine(iScreenWidth / 2 - ox, iScreenHeight - oy, top.x - ox, top.y + iMiddle3 - 1 - oy, Color(0, 0, 0));
		D::DrawLine(iScreenWidth / 2, iScreenHeight, top.x, top.y + iMiddle3 - 1, Color(200, 60, 60));
		D::DrawLine(iScreenWidth / 2 + ox, iScreenHeight + oy, top.x + ox, top.y + iMiddle3 - 1 + oy, Color(0, 0, 0));
	}

	if( Vars.Visuals.InfoWeapon )
		D::DrawString( F::ESP, top.x, top.y + height + 8 + ( 10 * bottom++ ), Color::White(), FONT_CENTER, "%s", Entity->GetWeapon()->GetWeaponName().c_str());

	if( Vars.Visuals.InfoFlashed && Entity->IsFlashed() )
		D::DrawString( F::ESP, top.x, top.y + height + 8 + ( 10 * bottom++ ), Color::Green(), FONT_CENTER, charenc( "Flashed" ) );

	if (Entity->GetUserID() == Vars.Bomber)
	D::DrawString(F::ESP, top.x, top.y + height + 8 + (10 * bottom++), Color::Red(), FONT_CENTER, charenc("Bomb"));

	if (Entity->GetUserID() == Vars.Hostage)
		D::DrawString(F::ESP, top.x, top.y + height + 8 + (10 * bottom++), Color::Red(), FONT_CENTER, charenc("Hostage"));

	if (Entity->GetUserID() == Vars.Defuser)
		D::DrawString(F::ESP, top.x, top.y + height + 8 + (10 * bottom++), Color::Red(), FONT_CENTER, charenc("Defuser"));
	}
}


void CVisuals::WorldESP( int index )
{
	CBaseEntity* Entity = I::ClientEntList->GetClientEntity( index );

	if( !Entity )
		return;

	BombTimer(Entity);

	Vector pos, pos3D;
	pos3D = Entity->GetOrigin();

	if( pos3D.IsZero() )
		return;

	if( !D::WorldToScreen( pos3D, pos ) )
		return;
	
	int owner = Entity->GetOwner();

	if( owner == -1 )
	{
		if( Vars.Visuals.Filter.Weapons )
		{
			if( strstr( Entity->GetClientClass()->m_pNetworkName, charenc( "CWeapon" ) ) )
			{
				D::DrawString( F::ESP, pos.x, pos.y, Color::White(), FONT_RIGHT, "%s", std::string( Entity->GetClientClass()->m_pNetworkName ).substr( 7 ).c_str() );
			}

			if( Entity->GetClientClass()->m_ClassID == 1 )
			{
				D::DrawString( F::ESP, pos.x, pos.y, Color::White(), FONT_RIGHT, "%s", charenc( "AK-47" ) );
			}

			if( Entity->GetClientClass()->m_ClassID == 39 )
			{
				D::DrawString( F::ESP, pos.x, pos.y, Color::White(), FONT_RIGHT, "%s", charenc( "Deagle") );
			}
		}
		
		if (Entity->GetClientClass()->m_ClassID == 29 && Vars.Visuals.Filter.C4) {
			D::DrawString(F::ESP, pos.x, pos.y, Color::LightBlue(), FONT_RIGHT, "%s", charenc("C4"));
		}
	}

	if( Entity->GetClientClass()->m_ClassID == 41 && Vars.Visuals.Filter.Decoy )
	{
		CBaseEntity* OwnerEntity = I::ClientEntList->GetClientEntity( owner & 0xFFF );
		D::DrawString( F::ESP, pos.x, pos.y, Color( 230, 78, 255 ), FONT_RIGHT, charenc( "Decoy - %s" ), OwnerEntity ? OwnerEntity->GetName().c_str() : charenc( "Disconnected" ) );
	}

	if (strstr(Entity->GetClientClass()->m_pNetworkName, charenc("CPlantedC4")) && Vars.Visuals.Filter.C4)
		D::DrawString(F::ESP, pos.x, pos.y, Color::Red(), FONT_CENTER, "%.1f", Entity->GetBombTimer());


}

void CVisuals::DrawGlow()
{
	CGlowObjectManager* GlowObjectManager = ( CGlowObjectManager* )offsets.GlowManager;

	for( int i = 0; i < GlowObjectManager->size; ++i )
	{
		CGlowObjectManager::GlowObjectDefinition_t* glowEntity = &GlowObjectManager->m_GlowObjectDefinitions[ i ];
		CBaseEntity* Entity = glowEntity->getEntity();

		if( glowEntity->IsEmpty() || !Entity )
			continue;

		player_info_t pInfo;
		I::Engine->GetPlayerInfo(i, &pInfo);

		if (strcmp(pInfo.guid, "STEAM_ID") == 0)
			return;

		switch( Entity->GetClientClass()->m_ClassID )
		{

		case 1:
			if( Vars.Visuals.Filter.Weapons )
				glowEntity->set( Color( 255, 138, 46, 250 ) );
			
			break;

		case 29:
			if( Vars.Visuals.Filter.C4 )
				glowEntity->set( Color( 84, 147, 230, 250 ) );
			
			break;

		case 39:
			if( Vars.Visuals.Filter.Weapons )
				glowEntity->set( Color( 255, 138, 46, 250 ) );

			break;

		case 41:
			if( Vars.Visuals.Filter.Decoy )
				glowEntity->set( Color( 230, 78, 255, 250 ) );

			break;

		case 105:
			if( Vars.Visuals.Filter.C4 )
				glowEntity->set( Color( 255, 39, 33, 250 ) );
			break;

		default:
			if( Vars.Visuals.Filter.Weapons )
			{
				if( strstr( Entity->GetClientClass()->m_pNetworkName, charenc( "CWeapon" ) ) )
					glowEntity->set( Color( 255, 138, 46, 250 ) );
			}
			break;
		}
	}
}

bool CVisuals::InGame()
{
	if( !I::Engine->IsInGame() )
		return false;

	if( !G::LocalPlayer )
		return false;

	return true;
}

bool CVisuals::EntityIsInvalid( CBaseEntity* Entity )
{
	if( !Entity )
		return true;
	if( Entity == G::LocalPlayer )
		return true;
	if( Entity->GetHealth() <= 0 )
		return true;
	if( Entity->GetDormant() )
		return true;

	return false;
}

void CVisuals::BulletTraceOverlay( CBaseEntity* entity, Color color )
{
	Vector src, dst, forward;
	trace_t tr;
	Ray_t ray;
	CTraceFilter filter;

	M::AngleVectors( entity->GetEyeAngles(), &forward );
	filter.pSkip = entity;
	src = entity->GetBonePosition( 6 );
	dst = src + (forward * Vars.Visuals.BulletTraceLength);

	ray.Init( src, dst );

	I::EngineTrace->TraceRay( ray, MASK_SHOT, &filter, &tr );

	I::DebugOverlay->AddLineOverlay( src, tr.endpos, color.r(), color.g(), color.b(), true, -1 );
}

void CVisuals::BulletTrace( CBaseEntity* entity, Color color )
{
	Vector src3D, dst3D, forward, src, dst;
	trace_t tr;
	Ray_t ray;
	CTraceFilter filter;

	M::AngleVectors( entity->GetEyeAngles(), &forward );
	filter.pSkip = entity;
	src3D = entity->GetBonePosition( 6 ) - Vector( 0, 0, 0 );
	dst3D = src3D + (forward * Vars.Visuals.BulletTraceLength);

	ray.Init( src3D, dst3D );

	I::EngineTrace->TraceRay( ray, MASK_SHOT, &filter, &tr );

	if( !D::WorldToScreen( src3D, src ) || !D::WorldToScreen( tr.endpos, dst ) )
		return;

	D::DrawLine( src.x, src.y, dst.x, dst.y, color );
	D::DrawRect( dst.x - 3, dst.y - 3, 6, 6, color );
}

void CVisuals::Watermark()
{
	static float rainbow;
	rainbow += 0.005f;
	if (rainbow > 1.f) rainbow = 0.f;
	D::DrawString(F::Watermark, 10, 18, Color::FromHSB(1.f, 1.f, 1.f), FONT_LEFT, "%s", charenc("BADSTER"));
	D::DrawString(F::Watermark, 72, 18, Color::FromHSB(rainbow, 1.f, 1.f), FONT_LEFT, "%s", charenc(".XYZ"));

}

void CVisuals::BombTimer(CBaseEntity* pEntity)
{
	RECT TextxSizeS = D::GetTextSize(F::Watermark, "");
	int screenW, screenH;
	I::Engine->GetScreenSize(screenW, screenH);

	int light = screenW - TextxSizeS.right - 20;

	if (Vars.Bomb && strstr(pEntity->GetClientClass()->m_pNetworkName, charenc("CPlantedC4")))
		D::DrawString(F::ESP, light, 12 + TextxSizeS.bottom + 3, Color::Red(), FONT_CENTER, "%.1f", pEntity->GetBombTimer());

}

void CVisuals::PlayerBox(float x, float y, float w, float h, Color clr)
{
	I::Surface->DrawSetColor( clr );
	I::Surface->DrawOutlinedRect( x - w, y, x + w, y + h );
	I::Surface->DrawSetColor(clr);
	I::Surface->DrawOutlinedRect(x - w + 1, y + 1, x + w - 1, y + h - 1);
}

void CVisuals::HealthBar( Vector bot, Vector top, float health )
{
	float h = ( bot.y - top.y );
	float offset = ( h / 4.f ) + 5;
	float w = h / 64.f;

	UINT hp = h - ( UINT )( ( h * health ) / 100 );

	int Red = 255 - ( health*2.55 );
	int Green = health*2.55;

	D::DrawOutlinedRect( ( top.x - offset ) - 1, top.y - 1, 3, h + 2, Color::Black() );

	D::DrawLine( ( top.x - offset ), top.y + hp, ( top.x - offset ), top.y + h, Color( Red, Green, 0, 255 ) );
}

void CVisuals::ArmorBar(Vector bot, Vector top, float armor)
{
	float h = (bot.y - top.y);
	float offset = (h / 4.f) + 5;
	float w = h / 64.f;

	UINT hp = h - (UINT)((h * armor) / 100);

	D::DrawOutlinedRect((top.x + offset) - 1, top.y - 1, 3, h + 2, Color::Black());

	D::DrawLine((top.x + offset), top.y + hp, (top.x + offset), top.y + h, Color(53, 174, 200, 255));
}

void CVisuals::Skeleton( CBaseEntity *Entity, Color color )
{
	studiohdr_t* pStudioModel = I::ModelInfo->GetStudioModel( Entity->GetModel() );
	if( pStudioModel )
	{
		static matrix3x4_t pBoneToWorldOut[ 128 ];
		if( Entity->SetupBones( pBoneToWorldOut, 128, 256, I::Globals->curtime ) )
		{
			for( int i = 0; i < pStudioModel->numbones; i++ )
			{
				mstudiobone_t* pBone = pStudioModel->pBone( i );
				if( !pBone || !( pBone->flags & 256 ) || pBone->parent == -1 )
					continue;

				Vector vBonePos1;
				if( !D::WorldToScreen( Vector( pBoneToWorldOut[ i ][ 0 ][ 3 ], pBoneToWorldOut[ i ][ 1 ][ 3 ], pBoneToWorldOut[ i ][ 2 ][ 3 ] ), vBonePos1 ) )
					continue;

				Vector vBonePos2;
				if( !D::WorldToScreen( Vector( pBoneToWorldOut[ pBone->parent ][ 0 ][ 3 ], pBoneToWorldOut[ pBone->parent ][ 1 ][ 3 ], pBoneToWorldOut[ pBone->parent ][ 2 ][ 3 ] ), vBonePos2 ) )
					continue;

				D::DrawLine( ( int )vBonePos1.x, ( int )vBonePos1.y, ( int )vBonePos2.x, ( int )vBonePos2.y, color );
			}
		}
	}
}

void CVisuals::DrawHitbox( matrix3x4a_t* matrix, Vector bbmin, Vector bbmax, int bone, Color color )
{
	Vector points[] = { 
		Vector( bbmin.x, bbmin.y, bbmin.z ),
		Vector( bbmin.x, bbmax.y, bbmin.z ),
		Vector( bbmax.x, bbmax.y, bbmin.z ),
		Vector( bbmax.x, bbmin.y, bbmin.z ),
		Vector( bbmax.x, bbmax.y, bbmax.z ),
		Vector( bbmin.x, bbmax.y, bbmax.z ),
		Vector( bbmin.x, bbmin.y, bbmax.z ),
		Vector( bbmax.x, bbmin.y, bbmax.z )
	};

	Vector pointsTransformed[ 8 ];

	for( int index = 0; index <= 8; ++index )
	{
		if( index != 0 )
			points[ index ] = ( ( ( ( points[ index ] + points[ 0 ] ) * .5f ) + points[ index ] ) * .5f );

		M::VectorTransform( points[ index ], matrix[ bone ], pointsTransformed[ index ] );
	}

	D::Draw3DBox( pointsTransformed, color );
}

void CVisuals::Hitboxes( CBaseEntity *Entity, Color color )
{
	matrix3x4a_t matrix[ MAXSTUDIOBONES ];

	if( !Entity->SetupBones( matrix, MAXSTUDIOBONES, BONE_USED_BY_HITBOX, I::Engine->GetLastTimeStamp() ) )
		return;

	studiohdr_t* pStudioModel = I::ModelInfo->GetStudioModel( Entity->GetModel() );
	if( !pStudioModel )
		return;

	mstudiohitboxset_t* set = pStudioModel->pHitboxSet( Entity->GetHitboxSet() );
	if( !set )
		return;

	for( int i = 0; i < set->numhitboxes; i++ )
	{
		mstudiobbox_t* hitbox = set->pHitbox( i );
		if( !hitbox )
			return;

		int bone = hitbox->bone;

		Vector vMaxUntransformed = hitbox->bbmax;
		Vector vMinUntransformed = hitbox->bbmin;

		if( hitbox->radius != -1.f )
		{
			vMinUntransformed -= Vector( hitbox->radius, hitbox->radius, hitbox->radius );
			vMaxUntransformed += Vector( hitbox->radius, hitbox->radius, hitbox->radius );
		}

		DrawHitbox( matrix, vMinUntransformed, vMaxUntransformed, hitbox->bone, color );
	}
}

void CVisuals::DrawCrosshair( Color color )
{
	int screenW, screenH;
	I::Engine->GetScreenSize( screenW, screenH );

	int crX = screenW / 2, crY = screenH / 2;
	int dy = screenH / G::FOV;
	int dx = screenW / G::FOV;
	int drX;
	int drY;

	if( Vars.Visuals.CrosshairType )
	{
		if( Vars.Visuals.RemovalsVisualRecoil )
		{
			drX = crX - ( int )( dx * ( G::LocalPlayer->GetPunch().y * 2 ) );
			drY = crY + ( int )( dy * ( G::LocalPlayer->GetPunch().x * 2 ) );
		}
		else
		{
			drX = crX - ( int )( dx * ( ( ( G::LocalPlayer->GetPunch().y * 2.f ) * 0.45f ) + G::LocalPlayer->GetViewPunch().y ) );
			drY = crY + ( int )( dy * ( ( ( G::LocalPlayer->GetPunch().x * 2.f ) * 0.45f ) + G::LocalPlayer->GetViewPunch().x ) );
		}
	}
	else
	{
		drX = crX;
		drY = crY;
	}

	if( Vars.Visuals.CrosshairStyle == 0 )
	{
		D::DrawLine( drX - 5, drY, drX + 5, drY, color );
		D::DrawLine( drX, drY - 5, drX, drY + 5, color );
	}
	if( Vars.Visuals.CrosshairStyle == 1 )
	{
		#define LOC(x,y) Vector2D(x,y)
		Circle(LOC(drX, drY), 20, 5 + G::LocalPlayer->GetWeapon()->GetSpread() + G::LocalPlayer->GetWeapon()->GetInaccuracy(), Color::White());
	}

	if( Vars.Visuals.CrosshairStyle == 2 )
	{
		D::DrawOutlinedRect( drX - 5, drY - 5, 10, 10, color );
	}

	if( Vars.Visuals.CrosshairStyle == 3 )
	{
		D::DrawLine( drX, drY, drX - 5, drY + 8, color );
		D::DrawLine(drX - 5, drY + 8, drX - 12, drY + 8, color);
		D::DrawLine(drX - 12, drY + 8, drX - 5, drY + 14, color);
		D::DrawLine(drX - 5, drY + 14, drX - 8, drY + 21, color);
		D::DrawLine(drX - 8, drY + 21, drX, drY + 18, color);
		D::DrawLine(drX, drY + 18, drX + 8, drY + 21, color);
		D::DrawLine(drX + 8, drY + 21, drX + 5, drY + 14, color);
		D::DrawLine(drX + 5, drY + 14, drX + 12, drY + 8, color);
		D::DrawLine(drX + 12, drY + 8, drX + 5, drY + 8, color);
		D::DrawLine(drX + 5, drY + 8, drX, drY, color);
	}
}
