#pragma once

class cVisuals
{
public:
	bool	Watermark;
	bool 	Enabled;
	bool 	Box2D;
	bool    Box3D;
	bool    FOVCircle;
	bool	Skeleton;
	bool    Tracers;
	bool    BulletTrace;
	float   BulletTraceLength;
	bool	SpectatorsTab;
	bool	CrosshairEnabled;
	bool	CrosshairType;
	int		CrosshairStyle;
	int		RadiusDlight;
	bool	Dlight;

	struct
	{

		bool Friendlies;
		bool Weapons;
		bool Decoy;
		bool C4;
	} Filter;

	struct
	{
		bool	Enabled;
		int 	Mode;
		bool	XQZ;
		bool	Hands;
		bool	Wireframe;
		bool	RainbowHands;
		float 	RainbowTime;
		bool	WireframeHands;
		bool	WireframeHandsZ;
	} Chams;

	struct
	{
		bool Enabled;
		int X;
		int Y;
		int Range;
		int Size;
	} Radar;
	
	struct
	{
		int r;
		int g;
		int b;
	} colV;

	struct
	{
		int r;
		int g;
		int b;
	} colNV;

	struct
	{
		int r;
		int g;
		int b;
	} colV2D;

	struct
	{
		int r;
		int g;
		int b;
	} colNV2D;

	struct
	{
		int r;
		int g;
		int b;
	} collight;

	int		collightt;
	int		colorsV;
	int		colorsNV;
	int		colorsV2D;
	int		colorsNV2D;
	bool 	InfoName;
	bool 	InfoHealth;
	bool	InfoArmor;
	bool 	InfoWeapon;
	bool	InfoFlashed;

	bool	RemovalsWeapon;
	bool	RemovalsHands;
	bool	RemovalsVisualRecoil;
	bool	RemovalsFlash;
	bool	RemovalsSmoke;
};

class cSkins
{
public:
	bool	SSEnabled;
	float	Wear;
	int		StatTrk;

	int 	AK47;
	int		fiveseven;
	int		BERETTAS;
	int 	M4A4;
	int 	M41S;
	int 	AWP;
	int 	Glock;
	int 	USPS;
	int 	Magnum;
	int		AUG;
	int		Famas;
	int		Galil;
	int		tec9;
	int		P2000;
	int		P250;
	int		CZ75;
	int		revolver;
	int		mac10;
	int		mp9;
	int		mp7;
	int		p90;
	int		ppbizon;
	int		ump45;
	int		m249;
	int		mag7;
	int		negev;
	int		nova;
	int		sawed;
	int		xm1014;
	int		sg;
	int		g3;
	int		scar;
	int		ssg;
	int		knife;
};

class cMenu
{
public:
	bool	Opened = false;
	bool	Ragebot = false;
	bool	Legitbot = false;
	bool	Visual = false;
	bool	Misc = false;
};

class cMisc
{
public:
	int		FOV;
	int		FakeLag;
	bool    AdaptiveFakeLag;
	bool    AutoPistol;
	bool 	Bunnyhop;
	bool 	Autostrafe;
	int 	AutostrafeTypes;
	bool 	Silent;
	bool 	EdgeJump;
	int     ColourNickname;
	//bool    NameSteal;
	//bool    NameStealSelf;
	//float   NameStealDelay = 1.f;

	bool	ChatSpam;
	float   ChatSpamDelay = 0.5f;
	char    ChatSpamMode[128] = "BADSTER.XYZ - OWNS ME AND ALL!";
	bool    LocationSpam;
	bool    LocationSpamEnemies;
	bool    LocationSpamChat;
	bool    HeadshotSay;
	bool    RefundSay;
	bool    BombInfoChat;

	char    configname[128] = "Default";

	bool	AutoAccept;
	bool	Ranks;
	bool	IgnoreScope;
	bool	AirStuck;
	int		AirStuckKey;
	bool	LagExploit;
	bool    Unload;

	struct
	{
		bool enabled;
		char* value = "BADSTER.XYZ";
		bool animation;
		int animation_speed;
		int type;
	} ClantagChanger;

	bool NameChangerenabled;
	int NameChangerseparator_animation;
};

class cRagebot
{
public:
	bool	AntiUntrusted;
	bool 	Enabled;
	bool 	FriendlyFire;
	bool 	OnKey;
	bool 	AutoFire;
	bool 	Silent;
	bool	AimStep;
	bool 	AutoWall;
	bool	Hitscan;
	bool 	Hitchance;
	float 	FOV;
	int		Hitbox;
	int 	Mode;
	int 	Key;
	int		RCS;
	float	RCShow;
	bool	HitscanAll;
	bool	HitscanHitbox;
	bool    HitscanHeadshot;
	float	AimStepAmount;
	float	AutoWallAmount;
	float	HitchanceAmount;
	bool 	AutoCrouch;
	bool 	AutoStop;
	bool    AutoScope;
	bool 	AutoStopFast;
	bool 	AutoStopCanShoot;
	bool	ShootWhenStopped;
	bool    bones[6] = { false, false, false, false, false, false };

	struct
	{
		bool	Enabled;
		bool    AtPlayer;
		bool    FakeYaw;
		int		Pitch;
		int		YawReal;
		int		YawFake;
		int     Zeta;
		float   PCReal;
		float   PCFake;
		float   YCFake;
		float   YCReal;
		bool    YawCustom;
		bool    PitchCustom;
		int     SpinbotSpeed;
		int     FakeSpinbotSpeed;
		bool	Resolver;
		bool	AntiResolver;
		bool	CustomJitter;
		bool	PositionAdjusment;
		bool	WallDetection;
		bool	Edge;
		int	    EdgeDistance;
		bool	Knife;
		bool	NoEnemy;
	} Antiaim;
};

class cLegitBot
{
public:
	struct
	{
		bool 	Enabled;
		bool	FriendlyFire;
		bool	KillStop;
		bool 	AlwaysOn;
		bool	OnKey;
		int 	Key;
		int     Group;
		bool	FlashCkeck;
		bool	SmokeCheck;
		bool	KillStopDelay;
		float	KillStopDelayA;
		bool	psalo;
	} Aimbot;

	struct
	{
		bool 	Enabled;
		float 	FOV;
		float	Speed;
		float	Delay;
		bool 	pSilent;
		bool    Silent;
		int 	Hitbox;
		bool 	RCSEnabled;
		float   RCSAmountX;
		float   RCSAmountY;
	} pistols;

	struct
	{
		bool 	Enabled;
		float 	FOV;
		float	Speed;
		float   Delay;
		float	Time;
		bool 	pSilent;
		bool    Silent;
		int 	Hitbox;
		bool	Nearest;
		bool 	RCSEnabled;
		float   RCSAmountX;
		float   RCSAmountY;
	} rifles;

	struct
	{
		bool 	Enabled;
		float 	FOV;
		float	Speed;
		float   Delay;
		bool 	pSilent;
		bool    Silent;
		int 	Hitbox;
		bool	Nearest;
		bool	StopZoom;
		bool	FastZoom;
		float   FOVZoom;
		float   RCSAmountX;
		float   RCSAmountY;
	} snipers;

	struct
	{
		bool 	Enabled;
		float 	FOV;
		float	Speed;
		float   Delay;
		float	Time;
		bool 	pSilent;
		bool    Silent;
		int 	Hitbox;
		bool	Nearest;
		bool 	RCSEnabled;
		float   RCSAmountX;
		float   RCSAmountY;
	} smg;

	struct
	{
		bool 	Enabled;
		float 	FOV;
		float	Speed;
		float   Delay;
		bool 	pSilent;
		bool    Silent;
		int 	Hitbox;
		float   RCSAmountX;
		float   RCSAmountY;
	} shotguns;

	struct
	{
		bool	Enabled;
		bool	AutoFire;
		bool    AutoWall;
		bool 	HitChance;
		float	HitChanceAmount;
		int		Key;


		struct
		{
			bool Friendly;
			bool Head;
			bool Chest;
			bool Stomach;
			bool Arms;
			bool Legs;
		} Filter;

	} Triggerbot;

};

class Variables
{
public:
	cRagebot Ragebot;
	cVisuals Visuals;
	cMisc Misc;
	cLegitBot Legitbot;
	cSkins Skins;
	cMenu Menu;

	int wpn;

	Variables()
	{
		wpn = -1;
	}

	int Bomber;
	int Hostage;
	int Defuser;
	bool Bomb;

	float g_fMColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float g_fBColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float g_fTColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
};

extern Variables Vars;