#pragma once

	enum MoveType_t
{
	MOVETYPE_NONE = 0,
	MOVETYPE_ISOMETRIC,
	MOVETYPE_WALK,
	MOVETYPE_STEP,
	MOVETYPE_FLY,
	MOVETYPE_FLYGRAVITY,
	MOVETYPE_VPHYSICS,
	MOVETYPE_PUSH,
	MOVETYPE_NOCLIP,
	MOVETYPE_LADDER,
	MOVETYPE_OBSERVER,
	MOVETYPE_CUSTOM,
	MOVETYPE_LAST = MOVETYPE_CUSTOM,
	MOVETYPE_MAX_BITS = 4
};

class CBaseCombatWeapon;
class CBaseEntity
{
public:
	char				__pad[0x64];
	int					index;
	int					GetIndex();
	int					GetHealth();
	int					GetTeam();
	int					GetFlags();
	int					GetTickBase();
	int					GetShotsFired();
	int iShotsFired(int i);
	int					GetMoveType();
	int*					GetModelIndex();
	int					GetHitboxSet();
	int					GetUserID();
	int					GetArmor();
	int	*				GetCompetitiveRanking();
	int					GetCollisionGroup();
	int					PhysicsSolidMaskForEntity();
	int					GetOwner();
	DWORD				GetOwnerHandler();
	int					GetGlowIndex();
	int					GetBoneByName(const char* boneName);
	bool				GetAlive();
	HANDLE				GetViewModel();
	bool				GetDormant();
	bool				GetImmune();
	bool				IsEnemy();
	bool				IsVisible(int bone);
	bool				IsVisible(Vector vecAbsStart, Vector vecAbsEnd, CBaseEntity* pLocal, CBaseEntity* pBaseEnt, bool smokeCheck = true);
	bool				LineGoesThroughSmoke(Vector pos1, Vector pos2);
	bool				m_visible;
	bool				IsBroken();
	bool				IsScoped();
	bool				HasHelmet();
	bool				IsFlashed();
	int GetPlayerC4();
	bool				IsTargetingLocal();
	float				GetFlashDuration();
	float				GetBombTimer();
	QAngle				GetViewPunch();
	QAngle				GetPunch();
	QAngle				GetEyeAngles();
	QAngle* 			GetHeadRotation();
	float* 				GetLowerBodyYawTarget();
	Vector				GetOrigin();
	Vector				GetEyePosition();
	Vector				GetBonePositionz(int iBone);
	Vector				GetBonePosition(int iBone);
	bool				SetupBones(matrix3x4_t *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime);
	Vector				GetVelocity();
	Vector				GetPredicted(Vector p0);
	ICollideable*		GetCollideable();
	player_info_t		GetPlayerInfo();
	model_t*			GetModel();
	std::string			GetName();
	std::string			GetSteamID();
	std::string			GetLastPlace();
	int&				GetXUIDLow();
	int&				GetXUIDHigh();
	CBaseCombatWeapon*	GetWeapon();
	DWORD GetActiveWeapon();
	ClientClass*		GetClientClass();
	HANDLE				GetObserverTargetHandle();
	DWORD GetObserverTargetHandleD();
	float				GetFlashBangTime();
};

/* TGF
class CHudTexture
{
public:
char type[64]; //0x0000
char subtype[64]; //0x0040
char unknowndata00[2]; //0x0080
char charinFont; //0x0082
char unknowndata01[1]; //0x0083
};//Size=0x00AC*/

// AYY struct
struct CHudTexture
{
	char	szShortName[64];	//0x0000
	char	szTextureFile[64];	//0x0040
	bool	bRenderUsingFont;	//0x0080
	bool	bPrecached;			//0x0081
	char	cCharacterInFont;	//0x0082
	BYTE	pad_0x0083;			//0x0083
	int		hFont;				//0x0084
	int		iTextureId;			//0x0088
	float	afTexCoords[4];		//0x008C
	int		iPosX[4];			//0x009C
}; //Size=0x00AC

class WeaponInfo_t
{
public:
	char _0x0000[2048];
	__int32 m_iAmmoType; //0x07B0 
	char _0x0804[52];
	__int32 m_iWeaponType; //0x0838 
	__int32 m_iTeam; //0x083C 
	__int32 m_iWeaponId; //0x0840 
	BYTE m_IsFullAuto; //0x0844
	char _0x0845[3];
	float m_flHeatPerShot; //0x0848 
	__int32 m_iWeaponPrice; //0x084C 
	float m_flArmorRatio; //0x0850 
	float m_flMaxPlayerSpeed; //0x0854 
	float m_flMaxPlayerSpeedAlt; //0x0858 
	__int32 m_iCrosshairMinDistance; //0x085C 
	__int32 m_iCrosshairDeltaDistance; //0x0860 
	float m_flPenetration; //0x0864 
	__int32 m_iDamage; //0x0868 
	float m_flRange; //0x086C 
	float m_flRangeModifier; //0x0870 
	__int32 m_iBullets; //0x0874 
	float m_flCycleTime; //0x0878 
	float m_flCycleTimeAlt; //0x087C 
	char _0x0880[416];
	float m_flSpread; //0x0A20 
	float m_flSpreadAlt; //0x0A24 
	float m_flInaccuracyCrouch; //0x09D8 
	float m_flInaccuracyCrouchAlt; //0x09DC 
	float m_flInaccuracyStand; //0x09E0 
	float m_flInaccuracyStandAlt; //0x09E4 
	float m_flInaccuracyJump; //0x09E8 
	float m_flInaccuracyJumpAlt; //0x09EC 
	float m_flInaccuracyLand; //0x09F0 
	float m_flInaccuracyLandAlt; //0x09F4 
	float m_flInaccuracyLadder; //0x09F8 
	float m_flInaccuracyLadderAlt; //0x09FC 
	float m_flInaccuracyFire; //0x0A00 
	float m_flInaccuracyFireAlt; //0x0A04 
	float m_flInaccuracyMove; //0x0A08 
	float m_flInaccuracyMoveAlt; //0x0A0C 
	float m_flRecoveryTimeStand; //0x0A10 
	float m_flRecoveryTimeCrouch; //0x0A14 
	float m_flInaccuracyReload; //0x0A18 
	float m_flInaccuracyAltSwitch; //0x0A1C 
	float m_flRecoilAngle; //0x0A20 
	float m_flRecoilAngleAlt; //0x0A24 
	float m_flRecoilAngleVariance; //0x0A28 
	float m_flRecoilAngleVarianceAlt; //0x0A2C 
	float m_flRecoilMagnitude; //0x0A30 
	float m_flRecoilMagnitudeAlt; //0x0A34 
	float m_flRecoilMagnitudeVariance; //0x0A38 
	float m_flRecoilMagnitudeVarianceAlt; //0x0A3C 
	__int32 m_iRecoilSeed; //0x0A40 
	float m_flFlinchVelocityModifierLarge; //0x0A44 
	float m_flFlinchVelocityModifierSmall; //0x0A48 
	float m_flTimeToIdle; //0x0A4C 
	float m_flIdleInterval; //0x0A50 
};

class CBaseViewModel : public CBaseEntity {
public:
	HANDLE GetOwnerz();
	int GetWeaponz();
};

class CBaseCombatWeapon
{
public:
	char			__pad[0x64];
	int				index;
	int&			GetWeaponID();
	float&			GetNextPrimaryAttack();
	float&			GetAccuracyPenalty();
	float& GetSpread();
	float& GetInaccuracy();
	HANDLE			GetOwnerHandle();
	int&			GetXUIDLow();
	int&			GetXUIDHigh();
	int&			GetEntityQuality();
	int&			GetAccountID();
	int & GetModelIndex();
	int&			GetItemIDHigh();
	int & GetItemIDLow();
	int&			GetItemDefinitionIndex();
	int&			GetFallbackPaintKit();
	int * GetFallbackPaintKitz();
	int&			GetFallbackStatTrak();
	float&			GetFallbackWear();
	bool			IsEmpty();
	int				Clip();
	bool			IsReloading();
	void			UpdateAccuracyPenalty();
	float			GetWeaponSpread();
	float			GetWeaponCone();
	WeaponInfo_t*	GetCSWpnData();
	bool			IsGun();
	bool			IsSniper();
	bool IsRifle();
	bool IsSmg();
	bool IsShotgun();
	bool IsPistol();
	bool IsAWPorSSG();
	bool			IsGrenade();
	std::string		GetWeaponName();
	bool			IsKnife();
	bool IsRevolver();
};