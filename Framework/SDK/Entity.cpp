#include "../SDK.h"

int CBaseEntity::GetIndex()
{
	return this->index;
}

int	CBaseEntity::GetHealth( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iHealth );
}

int CBaseEntity::GetTeam( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iTeamNum );
}

int CBaseEntity::GetFlags( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_fFlags );
}

int CBaseEntity::GetTickBase( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_nTickBase );
}

int CBaseEntity::GetShotsFired()
{
	return *( int* ) ( ( DWORD )this + offsets.m_iShotsFired );
}
int CBaseEntity::GetMoveType( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_nMoveType );
}

int *CBaseEntity::GetModelIndex()
{
	return ( int* )( ( DWORD )this + offsets.m_nModelIndex );
}

int CBaseEntity::GetHitboxSet()
{
	return *( int* )( ( DWORD )this + offsets.m_nHitboxSet );
}

int CBaseEntity::GetUserID()
{
	return this->GetPlayerInfo().userid;
}

int CBaseEntity::GetArmor()
{
	return *( int* )( ( DWORD )this + offsets.m_ArmorValue );
}

int CBaseEntity::PhysicsSolidMaskForEntity()
{
	typedef unsigned int( __thiscall* OriginalFn )( void* );
	return U::GetVFunc<OriginalFn>( this, 154 )( this );
}

int CBaseEntity::GetOwner()
{
	return *( int* )( ( DWORD )this + offsets.m_hOwnerEntity );
}

int CBaseEntity::GetGlowIndex()
{
	return *( int* )( ( DWORD )this + offsets.m_iGlowIndex );
}

float CBaseEntity::GetBombTimer()
{
	float bombTime = *( float* )( ( DWORD )this + offsets.m_flC4Blow );
	float returnValue = bombTime - I::Globals->curtime;
	return ( returnValue < 0 ) ? 0.f : returnValue;
}

float CBaseEntity::GetFlashDuration()
{
	return *( float* )( ( DWORD )this + offsets.m_flFlashDuration );
}

bool CBaseEntity::IsFlashed()
{
	return GetFlashDuration() > 0 ? true : false;
}

int CBaseEntity::GetPlayerC4()
{
	return *(int*)((uintptr_t)this + offsets.m_iPlayerC4);
}

bool CBaseEntity::GetAlive( )
{
	return ( bool ) ( *( int* ) ( ( DWORD )this + offsets.m_lifeState ) == 0 );
}

HANDLE CBaseEntity::GetViewModel()
{
	return (HANDLE)(*(int*)((DWORD)this + offsets.m_ViewModel) == 0);
}

bool CBaseEntity::GetDormant( )
{
	return *( bool* ) ( ( DWORD )this + offsets.m_bDormant );
}

bool CBaseEntity::GetImmune( )
{
	return *( bool* ) ( ( DWORD )this + offsets.m_bGunGameImmunity );
}

bool CBaseEntity::IsScoped()
{
	return *( bool* )( ( DWORD )this + offsets.m_bIsScoped );
}

bool CBaseEntity::HasHelmet()
{
	return *( bool* )( ( DWORD )this + offsets.m_bHasHelmet );
}

float CBaseEntity::GetFlashBangTime()
{
	return *(float*)((uintptr_t)this + 0xABE4);
}

bool CBaseEntity::IsTargetingLocal()
{
	Vector src, dst, forward;
	trace_t tr;

	if( !this )
		return false;

	QAngle viewangle = this->GetEyeAngles();

	M::AngleVectors( viewangle, &forward );
	forward *= 8142.f;
	src = this->GetEyePosition();
	dst = src + forward;

	U::TraceLine( src, dst, MASK_SHOT, this, &tr );

	if( tr.m_pEnt == G::LocalPlayer )
		return true;

	return false;
}

model_t* CBaseEntity::GetModel()
{
	return *( model_t** )( ( DWORD )this + 0x6C );
}

bool CBaseEntity::IsEnemy()
{
	return ( this->GetTeam() == G::LocalPlayer->GetTeam() || this->GetTeam() == 0 ) ? false : true;
}

bool CBaseEntity::IsVisible( int bone )
{
	Ray_t ray;
	trace_t tr;
	m_visible = false;
	ray.Init( G::LocalPlayer->GetEyePosition(), this->GetBonePosition( bone ) );

	CTraceFilter filter;
	filter.pSkip = G::LocalPlayer;

	I::EngineTrace->TraceRay( ray, MASK_SHOT, &filter, &tr );

	if( tr.m_pEnt == this )
	{
		m_visible = true;
		return true;
	}

	return false;
}

bool CBaseEntity::LineGoesThroughSmoke(Vector pos1, Vector pos2) throw()
{
	typedef bool(*LineGoesThroughSmokeFn)(float, float, float, float, float, float, short);

	LineGoesThroughSmokeFn LineGoesThroughSmokeEx;
	LineGoesThroughSmokeEx = (LineGoesThroughSmokeFn)(offsets.LineGoesThroughSmoke);
	return LineGoesThroughSmokeEx(pos1.x, pos1.y, pos1.z, pos2.x, pos2.y, pos2.z, 1);
}

bool CBaseEntity::IsVisible(Vector vecAbsStart, Vector vecAbsEnd, CBaseEntity* pLocal, CBaseEntity* pBaseEnt, bool smokeCheck) throw()
{
	trace_t tr;
	Ray_t ray;
	CTraceFilter filter;

	filter.pSkip = pLocal;

	ray.Init(vecAbsStart, vecAbsEnd);

	I::EngineTrace->TraceRay(ray, MASK_SHOT, &filter, &tr);

	bool visible = (tr.m_pEnt == pBaseEnt || tr.fraction >= 0.96f);

	if (visible && smokeCheck)
		visible = !LineGoesThroughSmoke(vecAbsStart, vecAbsEnd);

	return visible;
}

bool CBaseEntity::IsBroken()
{
	return *( bool* ) ( ( DWORD )this + offsets.m_bIsBroken );
}

QAngle CBaseEntity::GetViewPunch( )
{
	return *( QAngle* ) ( ( DWORD )this + offsets.m_viewPunchAngle );
}

QAngle CBaseEntity::GetPunch( )
{
	return *( QAngle* ) ( ( DWORD )this + offsets.m_aimPunchAngle );
}

QAngle CBaseEntity::GetEyeAngles()
{
	return *( QAngle* )( ( DWORD )this + offsets.m_angEyeAngles );
}

QAngle* CBaseEntity::GetHeadRotation()
{
	return ( QAngle* )(( DWORD )this + offsets.m_angRotation);
}

float* CBaseEntity::GetLowerBodyYawTarget()
{
	return ( float* )(( DWORD )this + offsets.m_flLowerBodyYawTarget);
}

Vector CBaseEntity::GetOrigin( )
{
	return *( Vector* ) ( ( DWORD )this + offsets.m_vecOrigin );
}

Vector CBaseEntity::GetEyePosition( )
{
	Vector origin = this->GetOrigin();
	Vector offset = *( Vector* )( ( DWORD )this + offsets.m_vecViewOffset );

	return( origin + offset );
}

Vector CBaseEntity::GetBonePositionz(int iBone)
{
	matrix3x4_t boneMatrixes[128];
	if (this->SetupBones(boneMatrixes, 128, 0x100, 0))
	{
		matrix3x4_t boneMatrix = boneMatrixes[iBone];
		return Vector(boneMatrix.m_flMatVal[0][3], boneMatrix.m_flMatVal[1][3], boneMatrix.m_flMatVal[2][3]);
	}
	else return Vector(0, 0, 0);
}

Vector CBaseEntity::GetBonePosition(int iBone)
{
		matrix3x4_t boneMatrixes[128];
		if (this->SetupBones(boneMatrixes, 128, 0x100, 0))
		{
			matrix3x4_t boneMatrix = boneMatrixes[iBone];
			return Vector(boneMatrix.m_flMatVal[0][3], boneMatrix.m_flMatVal[1][3], boneMatrix.m_flMatVal[2][3]);
		}
		else return Vector(0, 0, 0);
}

bool CBaseEntity::SetupBones( matrix3x4_t *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime )
{
	__asm
	{
		mov edi, this
		lea ecx, dword ptr ds : [edi + 0x4]
		mov edx, dword ptr ds : [ecx]
		push currentTime
		push boneMask
		push nMaxBones
		push pBoneToWorldOut
		call dword ptr ds : [edx + 0x34]
	}
}

Vector CBaseEntity::GetVelocity( )
{
	return *( Vector* ) ( ( DWORD )this + offsets.m_vecVelocity );
}

Vector CBaseEntity::GetPredicted( Vector p0 )
{
	return M::ExtrapolateTick( p0, this->GetVelocity() );
}

ICollideable* CBaseEntity::GetCollideable( )
{
	return ( ICollideable* ) ( ( DWORD )this + offsets.m_Collision );
}

player_info_t CBaseEntity::GetPlayerInfo( )
{
	player_info_t pinfo;
	I::Engine->GetPlayerInfo( this->index, &pinfo );
	return pinfo;
}

std::string	CBaseEntity::GetName( )
{
	return this->GetPlayerInfo( ).name;
}

std::string	CBaseEntity::GetSteamID( )
{
	return this->GetPlayerInfo( ).name;
}

std::string CBaseEntity::GetLastPlace( )
{
	return std::string( ( const char* )this + offsets.m_szLastPlaceName );
}

HANDLE CBaseEntity::GetObserverTargetHandle()
{
	return *(HANDLE*)((DWORD)this + offsets.m_hObserverTarget);
}

CBaseCombatWeapon* CBaseEntity::GetWeapon( )
{
	HANDLE weaponData = *(HANDLE* )( ( DWORD )this + offsets.m_hActiveWeapon );
	return ( CBaseCombatWeapon* ) I::ClientEntList->GetClientEntityFromHandle( weaponData );
}

HANDLE CBaseCombatWeapon::GetOwnerHandle()
{
	return *(HANDLE*)((DWORD)this + offsets.m_hOwnerEntity);
}

DWORD CBaseEntity::GetActiveWeapon()
{
	return (DWORD)((uintptr_t)this + offsets.m_hActiveWeaponz);
}

ClientClass* CBaseEntity::GetClientClass()
{
	PVOID pNetworkable = ( PVOID )( ( DWORD )( this ) + 0x8 );
	typedef ClientClass*( __thiscall* OriginalFn )( PVOID );
	return U::GetVFunc<OriginalFn>( pNetworkable, 2 )( pNetworkable );
}

int CBaseEntity::GetCollisionGroup()
{
	return *( int* ) ( ( DWORD )this + offsets.m_CollisionGroup );
}

int CBaseEntity::GetBoneByName(const char* boneName)
{
	studiohdr_t* pStudioModel = I::ModelInfo->GetStudioModel(this->GetModel() );
	if (!pStudioModel)
		return -1;

	matrix3x4_t pBoneToWorldOut[128];
	if (!this->SetupBones(pBoneToWorldOut, 128, 256, 0))
		return -1;

	for (int i = 0; i < pStudioModel->numbones; i++)
	{
		mstudiobone_t *pBone = pStudioModel->pBone(i);
		if (!pBone)
			continue;

		if (pBone->pszName() && strcmp(pBone->pszName(), boneName) == 0)
			return i;
	}

	return -1;
}

int& CBaseCombatWeapon::GetWeaponID( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iWeaponID );
}

float& CBaseCombatWeapon::GetNextPrimaryAttack( )
{
	return *( float* ) ( ( DWORD )this + offsets.m_flNextPrimaryAttack );
}

float& CBaseCombatWeapon::GetAccuracyPenalty( )
{
	return *( float* ) ( ( DWORD )this + offsets.m_fAccuracyPenalty );
}

float& CBaseCombatWeapon::GetSpread()
{
	return *(float*)((DWORD)this + offsets.m_fSpread);
}

float& CBaseCombatWeapon::GetInaccuracy()
{
	return *(float*)((DWORD)this + offsets.m_fInaccuracy);
}

int& CBaseCombatWeapon::GetXUIDLow( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_OriginalOwnerXuidLow );
}

int& CBaseCombatWeapon::GetXUIDHigh( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_OriginalOwnerXuidHigh );
}

int& CBaseCombatWeapon::GetEntityQuality( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iEntityQuality );
}

int& CBaseCombatWeapon::GetAccountID( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iAccountID );
}

int& CBaseCombatWeapon::GetModelIndex()
{
	return *(int*)((DWORD)this + offsets.m_nModelIndex);
}

int& CBaseCombatWeapon::GetItemIDHigh( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iItemIDHigh );
}

int& CBaseCombatWeapon::GetItemIDLow()
{
	return *(int*)((DWORD)this + offsets.m_iItemIDLow);
}


int& CBaseCombatWeapon::GetItemDefinitionIndex( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_iItemDefinitionIndex );
}

int& CBaseCombatWeapon::GetFallbackPaintKit( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_nFallbackPaintKit );
}

int& CBaseCombatWeapon::GetFallbackStatTrak( )
{
	return *( int* ) ( ( DWORD )this + offsets.m_nFallbackStatTrak );
}

float& CBaseCombatWeapon::GetFallbackWear( )
{
	return *( float* ) ( ( DWORD )this + offsets.m_flFallbackWear );
}


HANDLE CBaseViewModel::GetOwnerz() {
	static uintptr_t m_hOwner = offsets.m_hOwner;
	return *reinterpret_cast<HANDLE*>(uintptr_t(this) + m_hOwner);
}

int CBaseViewModel::GetWeaponz() {
	static uintptr_t m_hWeapon = offsets.m_hWeapon;
	return *reinterpret_cast<int*>(uintptr_t(this) + m_hWeapon);
}

WeaponInfo_t* CBaseCombatWeapon::GetCSWpnData( )
{
	if( !this ) return nullptr;

	typedef WeaponInfo_t*( __thiscall* OriginalFn )( void* );
	return U::GetVFunc<OriginalFn>( this, 456 )( this );
}

bool CBaseCombatWeapon::IsEmpty()
{
	int clip = *( int* )( ( DWORD )this + offsets.m_iClip1 );
	return clip == 0;
}

int CBaseCombatWeapon::Clip()
{
	int clip = *(int*)((DWORD)this + offsets.m_iClip1);
	return clip;
}

bool CBaseCombatWeapon::IsReloading()
{
	return *( bool* )( ( DWORD )this + 0x3235 );
}

void CBaseCombatWeapon::UpdateAccuracyPenalty()
{
	typedef void( __thiscall *FunctionFn )( void* );
	reinterpret_cast<FunctionFn>( *reinterpret_cast<PDWORD>( *reinterpret_cast<PDWORD>( this ) + 0x748 ) )( ( void* )this );
}

float CBaseCombatWeapon::GetWeaponCone()
{
	if( !this )
		return 0.f;

	typedef float( __thiscall* OriginalFn )( void* );
	return U::GetVFunc<OriginalFn>( this, 478 )( this );
}

float CBaseCombatWeapon::GetWeaponSpread()
{
	if( !this )
		return 0.f;

	typedef float( __thiscall* OriginalFn )( void* );
	return U::GetVFunc<OriginalFn>( this, 479 )( this );
}

bool CBaseCombatWeapon::IsGun()
{
	if( !this )
		return false;

	int id = this->GetWeaponID();

	switch( id )
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
	case WEAPON_AK47:
	case WEAPON_AUG:
	case WEAPON_AWP:
	case WEAPON_FAMAS:
	case WEAPON_G3SG1:
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
	case WEAPON_XM1014:
	case WEAPON_BIZON:
	case WEAPON_MAG7:
	case WEAPON_NEGEV:
	case WEAPON_SAWEDOFF:
	case WEAPON_TEC9:
		return true;
	case WEAPON_TASER:
		return false;
	case WEAPON_HKP2000:
	case WEAPON_MP7:
	case WEAPON_MP9:
	case WEAPON_NOVA:
	case WEAPON_P250:
	case WEAPON_SCAR20:
	case WEAPON_SG556:
	case WEAPON_SSG08:
		return true;
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
		return false;
	case WEAPON_M4A1_SILENCER:
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return true;
	default:
		return false;
	}
}


std::string CBaseCombatWeapon::GetWeaponName()
{
	if( !this )
		return "";

	int id = this->GetWeaponID();

	switch( id )
	{
	case WEAPON_DEAGLE:
		return strenc( "Desert Eagle" );
	case WEAPON_ELITE:
		return strenc( "Dual Berettas" );
	case WEAPON_FIVESEVEN:
		return strenc( "Five-SeveN" );
	case WEAPON_GLOCK:
		return strenc( "Glock-18" );
	case WEAPON_AK47:
		return strenc( "AK-47" );
	case WEAPON_AUG:
		return strenc( "AUG" );
	case WEAPON_AWP:
		return strenc( "AWP" );
	case WEAPON_FAMAS:
		return strenc( "FAMAS" );
	case WEAPON_G3SG1:
		return strenc( "G3SG1" );
	case WEAPON_GALILAR:
		return strenc( "Galil AR" );
	case WEAPON_M249:
		return strenc( "M249" );
	case WEAPON_M4A1:
		return strenc( "M4A1-S" );
	case WEAPON_MAC10:
		return strenc( "MAC-10" );
	case WEAPON_P90:
		return strenc( "P90" );
	case WEAPON_UMP45:
		return strenc( "UMP-45" );
	case WEAPON_XM1014:
		return strenc( "XM1014" );
	case WEAPON_BIZON:
		return strenc( "PP-Bizon" );
	case WEAPON_MAG7:
		return strenc( "MAG-7" );
	case WEAPON_NEGEV:
		return strenc( "Negev" );
	case WEAPON_SAWEDOFF:
		return strenc( "Sawed-Off" );
	case WEAPON_TEC9:
		return strenc( "Tec-9" );
	case WEAPON_TASER:
		return strenc( "Taser" );
	case WEAPON_HKP2000:
		return strenc( "P2000" );
	case WEAPON_MP7:
		return strenc( "MP7" );
	case WEAPON_MP9:
		return strenc( "MP9" );
	case WEAPON_NOVA:
		return strenc( "Nova" );
	case WEAPON_P250:
		return strenc( "P250" );
	case WEAPON_SCAR20:
		return strenc( "SCAR-20" );
	case WEAPON_SG556:
		return strenc( "SG 553" );
	case WEAPON_SSG08:
		return strenc( "SSG 08" );
	case WEAPON_KNIFE:
		return strenc( "Knife" );
	case WEAPON_FLASHBANG:
		return strenc( "Flashbang" );
	case WEAPON_HEGRENADE:
		return strenc( "HE Grenade" );
	case WEAPON_SMOKEGRENADE:
		return strenc( "Smoke Grenade" );
	case WEAPON_MOLOTOV:
		return strenc( "Molotov" );
	case WEAPON_DECOY:
		return strenc( "Decoy" );
	case WEAPON_INCGRENADE:
		return strenc( "Incendiary Grenade" );
	case WEAPON_C4:
		return strenc( "C4" );
	case WEAPON_KNIFE_T:
		return strenc( "Knife" );
	case WEAPON_M4A1_SILENCER:
		return strenc( "M4A1-S" );
	case WEAPON_USP_SILENCER:
		return strenc( "USP-S" );
	case WEAPON_CZ75A:
		return strenc( "CZ75-Auto" );
	case WEAPON_REVOLVER:
		return strenc( "R8 Revolver" );
	default:
		return strenc( "Knife" );
	}

	return "";
}

bool CBaseCombatWeapon::IsSniper()
{
	if( !this )
		return false;

	switch( this->GetItemDefinitionIndex() )
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
	case WEAPON_AK47:
	case WEAPON_AUG:
		return false;
	case WEAPON_AWP:
		return true;
	case WEAPON_FAMAS:
		return false;
	case WEAPON_G3SG1:
		return true;
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
	case WEAPON_XM1014:
	case WEAPON_BIZON:
	case WEAPON_MAG7:
	case WEAPON_NEGEV:
	case WEAPON_SAWEDOFF:
	case WEAPON_TEC9:
	case WEAPON_TASER:
	case WEAPON_HKP2000:
	case WEAPON_MP7:
	case WEAPON_MP9:
	case WEAPON_NOVA:
	case WEAPON_P250:
		return false;
	case WEAPON_SCAR20:
		return true;
	case WEAPON_SG556:
		return false;
	case WEAPON_SSG08:
		return true;
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
	case WEAPON_M4A1_SILENCER:
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return false;
	default:
		return false;
	}
}

bool CBaseCombatWeapon::IsAWPorSSG()
{
	if (!this)
		return false;

	switch (this->GetItemDefinitionIndex())
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
	case WEAPON_AK47:
	case WEAPON_AUG:
		return false;
	case WEAPON_AWP:
		return true;
	case WEAPON_FAMAS:
		return false;
	case WEAPON_G3SG1:
		return false;
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
	case WEAPON_XM1014:
	case WEAPON_BIZON:
	case WEAPON_MAG7:
	case WEAPON_NEGEV:
	case WEAPON_SAWEDOFF:
	case WEAPON_TEC9:
	case WEAPON_TASER:
	case WEAPON_HKP2000:
	case WEAPON_MP7:
	case WEAPON_MP9:
	case WEAPON_NOVA:
	case WEAPON_P250:
		return false;
	case WEAPON_SCAR20:
		return false;
	case WEAPON_SG556:
		return false;
	case WEAPON_SSG08:
		return true;
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
	case WEAPON_M4A1_SILENCER:
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return false;
	default:
		return false;
	}
}

bool CBaseCombatWeapon::IsRifle()
{
	if (!this)
		return false;

	switch (this->GetItemDefinitionIndex())
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
		return false;
	case WEAPON_AK47:
	case WEAPON_AUG:
		return true;
	case WEAPON_AWP:
		return false;
	case WEAPON_FAMAS:
		return true;
	case WEAPON_G3SG1:
		return false;
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
		return true;
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
	case WEAPON_XM1014:
	case WEAPON_BIZON:
	case WEAPON_MAG7:
		return false;
	case WEAPON_NEGEV:
		return true;
	case WEAPON_SAWEDOFF:
		return false;
	case WEAPON_TEC9:
	case WEAPON_TASER:
	case WEAPON_HKP2000:
	case WEAPON_MP7:
	case WEAPON_MP9:
	case WEAPON_NOVA:
	case WEAPON_P250:
	case WEAPON_SCAR20:
		return false;
	case WEAPON_SG556:
		return true;
	case WEAPON_SSG08:
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
		return false;
	case WEAPON_M4A1_SILENCER:
		return true;
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return false;
	default:
		return false;
	}
}

bool CBaseCombatWeapon::IsSmg()
{
	if (!this)
		return false;

	switch (this->GetItemDefinitionIndex())
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
	case WEAPON_AK47:
	case WEAPON_AUG:
	case WEAPON_AWP:
	case WEAPON_FAMAS:
	case WEAPON_G3SG1:
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
		return false;
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
		return true;
	case WEAPON_XM1014:
		return false;
	case WEAPON_BIZON:
		return true;
	case WEAPON_MAG7:
	case WEAPON_NEGEV:
	case WEAPON_SAWEDOFF:
	case WEAPON_TEC9:
	case WEAPON_TASER:
	case WEAPON_HKP2000:
		return false;
	case WEAPON_MP7:
	case WEAPON_MP9:
		return true;
	case WEAPON_NOVA:
	case WEAPON_P250:
	case WEAPON_SCAR20:
	case WEAPON_SG556:
	case WEAPON_SSG08:
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
	case WEAPON_M4A1_SILENCER:
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return false;
	default:
		return false;
	}
}

bool CBaseCombatWeapon::IsShotgun()
{
	if (!this)
		return false;

	switch (this->GetItemDefinitionIndex())
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
	case WEAPON_AK47:
	case WEAPON_AUG:
	case WEAPON_AWP:
	case WEAPON_FAMAS:
	case WEAPON_G3SG1:
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
		return false;
	case WEAPON_XM1014:
		return true;
	case WEAPON_BIZON:
		return false;
	case WEAPON_MAG7:
		return true;
	case WEAPON_NEGEV:
		return false;
	case WEAPON_SAWEDOFF:
		return true;
	case WEAPON_TEC9:
	case WEAPON_TASER:
	case WEAPON_HKP2000:
	case WEAPON_MP7:
	case WEAPON_MP9:
		return false;
	case WEAPON_NOVA:
		return true;
	case WEAPON_P250:
	case WEAPON_SCAR20:
	case WEAPON_SG556:
	case WEAPON_SSG08:
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
	case WEAPON_M4A1_SILENCER:
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return false;
	default:
		return false;
	}
}

bool CBaseCombatWeapon::IsPistol()
{
	if (!this)
		return false;

	switch (this->GetItemDefinitionIndex())
	{
	case WEAPON_DEAGLE:
	case WEAPON_ELITE:
	case WEAPON_FIVESEVEN:
	case WEAPON_GLOCK:
		return true;
	case WEAPON_AK47:
	case WEAPON_AUG:
	case WEAPON_AWP:
	case WEAPON_FAMAS:
	case WEAPON_G3SG1:
	case WEAPON_GALILAR:
	case WEAPON_M249:
	case WEAPON_M4A1:
	case WEAPON_MAC10:
	case WEAPON_P90:
	case WEAPON_UMP45:
	case WEAPON_XM1014:
	case WEAPON_BIZON:
	case WEAPON_MAG7:
	case WEAPON_NEGEV:
	case WEAPON_SAWEDOFF:
		return false;
	case WEAPON_TEC9:
	case WEAPON_TASER:
	case WEAPON_HKP2000:
		return true;
	case WEAPON_MP7:
	case WEAPON_MP9:
	case WEAPON_NOVA:
		return false;
	case WEAPON_P250:
		return true;
	case WEAPON_SCAR20:
	case WEAPON_SG556:
	case WEAPON_SSG08:
	case WEAPON_KNIFE:
	case WEAPON_FLASHBANG:
	case WEAPON_HEGRENADE:
	case WEAPON_SMOKEGRENADE:
	case WEAPON_MOLOTOV:
	case WEAPON_DECOY:
	case WEAPON_INCGRENADE:
	case WEAPON_C4:
	case WEAPON_KNIFE_T:
	case WEAPON_M4A1_SILENCER:
		return false;
	case WEAPON_USP_SILENCER:
	case WEAPON_CZ75A:
	case WEAPON_REVOLVER:
		return true;
	default:
		return false;
	}
}
bool CBaseCombatWeapon::IsGrenade()
{
	if( !this )
		return false;
		
	switch ( this->GetItemDefinitionIndex() )
	{
		case WEAPON_SMOKEGRENADE:
		case WEAPON_HEGRENADE:
		case WEAPON_INCGRENADE:
		case WEAPON_FLASHBANG:
		case WEAPON_MOLOTOV:
		case WEAPON_DECOY:
			return true;
		default:
			return false;
	}
}

bool CBaseCombatWeapon::IsKnife()
{
	if (!this)
		return false;

	switch ( this->GetItemDefinitionIndex() )
	{
		case WEAPON_KNIFE:
		case WEAPON_KNIFE_T:
		case WEAPON_KNIFE_GUT:
		case WEAPON_KNIFE_FLIP:
		case WEAPON_KNIFE_BAYONET:
		case WEAPON_KNIFE_M9_BAYONET:
		case WEAPON_KNIFE_KARAMBIT:
		case WEAPON_KNIFE_TACTICAL:
		case WEAPON_KNIFE_BUTTERFLY:
		case WEAPON_KNIFE_SURVIVAL_BOWIE:
		case WEAPON_KNIFE_FALCHION:
		case WEAPON_KNIFE_PUSH:
			return true;
		default:
			return false;
	}
}

bool CBaseCombatWeapon::IsRevolver()
{
	if (!this)
		return false;

	switch (this->GetItemDefinitionIndex())
	{
	case WEAPON_REVOLVER:
		return true;
	default:
		return false;
	}
}