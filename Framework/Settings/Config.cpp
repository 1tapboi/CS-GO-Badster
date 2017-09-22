#include "../Cheat.h"

inline char* strcats(char* s1, char* s2)
{
	std::string ss1(s1);
	std::string ss2(s2);
	std::string Buff = ss1 + ss2;
	char *Buffer = _strdup(Buff.c_str());
	return Buffer;
}

void CConfig::Setup()
{
	SetupValue(Vars.Ragebot.AntiUntrusted, false, strenc("Ragebot"), strenc("Anti-Untrusted"));
	SetupValue(Vars.Ragebot.Enabled, false, strenc("Ragebot"), strenc("Enabled"));
	SetupValue(Vars.Ragebot.OnKey, false, strenc("Ragebot"), strenc("On Key"));
	SetupValue(Vars.Ragebot.AutoFire, false, strenc("Ragebot"), strenc("Auto Fire"));
	SetupValue(Vars.Ragebot.Silent, true, strenc("Ragebot"), strenc("Silent"));
	SetupValue(Vars.Ragebot.AimStep, false, strenc("Ragebot"), strenc("Aim Step Enabled"));
	SetupValue(Vars.Ragebot.Key, 0, strenc("Ragebot"), strenc("Key"));
	SetupValue(Vars.Ragebot.FOV, 180.f, strenc("Ragebot"), strenc("FOV"));
	SetupValue(Vars.Ragebot.RCS, 0, strenc("Ragebot"), strenc("No Recoil Type"));
	SetupValue(Vars.Ragebot.RCShow, 0.f, strenc("Ragebot"), strenc("No Recoil Amount"));
	SetupValue(Vars.Ragebot.AimStepAmount, 15.f, strenc("Ragebot"), strenc("AimStep Angel Tick Amount"));
	SetupValue(Vars.Ragebot.FriendlyFire, false, strenc("Ragebot"), strenc("Friendly Fire"));
	SetupValue(Vars.Ragebot.AutoWall, true, strenc("Ragebot"), strenc("Auto Wall"));
	SetupValue(Vars.Ragebot.Hitscan, true, strenc("Ragebot"), strenc("Hitscan"));
	SetupValue(Vars.Ragebot.Hitbox, 6, strenc("Ragebot"), strenc("Hitbox"));
	SetupValue(Vars.Ragebot.Mode, 0, strenc("Ragebot"), strenc("Mode"));
	SetupValue(Vars.Ragebot.AutoWallAmount, 10.f, strenc("Ragebot"), strenc("Auto Wall Damage Amount"));
	SetupValue(Vars.Ragebot.HitscanHitbox, false, strenc("Ragebot"), strenc("Hitscan Low (Bone)"));
	SetupValue(Vars.Ragebot.HitscanAll, false, strenc("Ragebot"), strenc("Hitscan Low (Body)"));
	SetupValue(Vars.Ragebot.HitscanHeadshot, false, strenc("Ragebot"), strenc("Hitscan High (Headshot)"));
	SetupValue(Vars.Ragebot.Hitchance, false, strenc("Ragebot"), strenc("Hitchance"));
	SetupValue(Vars.Ragebot.HitchanceAmount, 50.f, strenc("Ragebot"), strenc("Hitchance Amount"));
	SetupValue(Vars.Ragebot.AutoCrouch, false, strenc("Ragebot"), strenc("Auto Crouch"));
	SetupValue(Vars.Ragebot.AutoStop, false, strenc("Ragebot"), strenc("Auto Stop"));
	SetupValue(Vars.Ragebot.AutoScope, false, strenc("Ragebot"), strenc("Auto Scope"));
	SetupValue(Vars.Ragebot.AutoStopCanShoot, false, strenc("Ragebot"), strenc("Auto Stop Can Shoot"));
	SetupValue(Vars.Ragebot.AutoStopFast, false, strenc("Ragebot"), strenc("Fast Auto Stop"));
	SetupValue(Vars.Ragebot.ShootWhenStopped, false, strenc("Ragebot"), strenc("Shoot When Stopped"));
	SetupValue(Vars.Ragebot.Antiaim.Enabled, false, strenc("Ragebot"), strenc("Anti-Aim On"));
	SetupValue(Vars.Ragebot.Antiaim.AtPlayer, false, strenc("Ragebot"), strenc("At Target"));
	SetupValue(Vars.Ragebot.Antiaim.FakeYaw, false, strenc("Ragebot"), strenc("Fake Y"));
	SetupValue(Vars.Ragebot.Antiaim.Resolver, false, strenc("Ragebot"), strenc("Resolver"));
	SetupValue(Vars.Ragebot.Antiaim.PositionAdjusment, false, strenc("Ragebot"), strenc("Position Adjustment"));
	SetupValue(Vars.Ragebot.Antiaim.YawReal, 0, strenc("Ragebot"), strenc("Y"));
	SetupValue(Vars.Ragebot.Antiaim.YawFake, 0, strenc("Ragebot"), strenc("Y Fake"));
	//SetupValue(Vars.Ragebot.Antiaim.Zeta, 0, strenc("Ragebot"), strenc("Zeta"));
	SetupValue(Vars.Ragebot.Antiaim.CustomJitter, false, strenc("Ragebot"), strenc("Custom Jitter"));
	SetupValue(Vars.Ragebot.Antiaim.PitchCustom, false, strenc("Ragebot"), strenc("Custom P"));
	SetupValue(Vars.Ragebot.Antiaim.PCReal, 0.f, strenc("Ragebot"), strenc("Custom Jitter P"));
	SetupValue(Vars.Ragebot.Antiaim.PCFake, 0.f, strenc("Ragebot"), strenc("Custom Jitter P Fake"));
	SetupValue(Vars.Ragebot.Antiaim.PitchCustom, false, strenc("Ragebot"), strenc("Custom Y"));
	SetupValue(Vars.Ragebot.Antiaim.YCReal, 0.f, strenc("Ragebot"), strenc("Custom Jitter Y"));
	SetupValue(Vars.Ragebot.Antiaim.YCFake, 0.f, strenc("Ragebot"), strenc("Custom Jitter Y Fake"));
	SetupValue(Vars.Ragebot.Antiaim.AntiResolver, false, strenc("Ragebot"), strenc("Anti-Resolver"));
	SetupValue(Vars.Ragebot.Antiaim.WallDetection, false, strenc("Ragebot"), strenc("Wall Detection"));
	SetupValue(Vars.Ragebot.Antiaim.Edge, false, strenc("Ragebot"), strenc("Edge"));
	SetupValue(Vars.Ragebot.Antiaim.EdgeDistance, 12, strenc("Ragebot"), strenc("Edge Distance"));
	SetupValue(Vars.Ragebot.Antiaim.SpinbotSpeed, 12, strenc("Ragebot"), strenc("Spinbot Speed"));
	SetupValue(Vars.Ragebot.Antiaim.FakeSpinbotSpeed, 12, strenc("Ragebot"), strenc("Fake Spinbot Speed"));
	SetupValue(Vars.Ragebot.Antiaim.Knife, false, strenc("Ragebot"), strenc("Anti-Aim Knife"));
	SetupValue(Vars.Ragebot.Antiaim.NoEnemy, false, strenc("Ragebot"), strenc("Anti-Aim No Enemy"));
	SetupValue(Vars.Ragebot.bones[0], false, strenc("Ragebot"), strenc("HitscanBones1"));
	SetupValue(Vars.Ragebot.bones[1], false, strenc("Ragebot"), strenc("HitscanBones2"));
	SetupValue(Vars.Ragebot.bones[2], false, strenc("Ragebot"), strenc("HitscanBones3"));
	SetupValue(Vars.Ragebot.bones[3], false, strenc("Ragebot"), strenc("HitscanBones4"));
	SetupValue(Vars.Ragebot.bones[4], false, strenc("Ragebot"), strenc("HitscanBones5"));
	SetupValue(Vars.Ragebot.bones[5], false, strenc("Ragebot"), strenc("HitscanBones6"));

		SetupValue(Vars.Legitbot.Aimbot.Enabled, false, strenc("Legitbot"), strenc("Enabled"));
		SetupValue(Vars.Legitbot.Aimbot.AlwaysOn, false, strenc("Legitbot"), strenc("Ignore Key"));
		SetupValue(Vars.Legitbot.Aimbot.OnKey, false, strenc("Legitbot"), strenc("Aim on Key"));
		SetupValue(Vars.Legitbot.Aimbot.FriendlyFire, false, strenc("Legitbot"), strenc("Friendly Fire"));
		SetupValue(Vars.Legitbot.Aimbot.KillStop, false, strenc("Legitbot"), strenc("Kill Stop"));
		SetupValue(Vars.Legitbot.Aimbot.KillStopDelay, false, strenc("Legitbot"), strenc("Kill Stop Delay"));
		SetupValue(Vars.Legitbot.Aimbot.KillStopDelayA, false, strenc("Legitbot"), strenc("Kill Stop Delay Amount"));
		SetupValue(Vars.Legitbot.Aimbot.FlashCkeck, false, strenc("Legitbot"), strenc("Flash Ckeck"));
		SetupValue(Vars.Legitbot.Aimbot.SmokeCheck, false, strenc("Legitbot"), strenc("Smoke Check"));
		SetupValue(Vars.Legitbot.Aimbot.Key, 0, strenc("Legitbot"), strenc("Key"));

		SetupValue(Vars.Legitbot.pistols.FOV, 10.f, strenc("Legitbot"), strenc("pistols.FOV"));
		SetupValue(Vars.Legitbot.pistols.Speed, 5.f, strenc("Legitbot"), strenc("pistols.Smooth"));
		SetupValue(Vars.Legitbot.pistols.Delay, 500.f, strenc("Legitbot"), strenc("pistols.Delay"));
		SetupValue(Vars.Legitbot.pistols.Hitbox, 6, strenc("Legitbot"), strenc("pistols.Hitbox"));
		SetupValue(Vars.Legitbot.pistols.RCSEnabled, true, strenc("Legitbot"), strenc("pistols.RCSEnabled"));
		SetupValue(Vars.Legitbot.pistols.RCSAmountX, 100.f, strenc("Legitbot"), strenc("pistols.RCSAmountX"));
		SetupValue(Vars.Legitbot.pistols.RCSAmountY, 100.f, strenc("Legitbot"), strenc("pistols.RCSAmountY"));

		SetupValue(Vars.Legitbot.rifles.FOV, 10.f, strenc("Legitbot"), strenc("rifles.FOV"));
		SetupValue(Vars.Legitbot.rifles.Speed, 5.f, strenc("Legitbot"), strenc("rifles.Smooth"));
		SetupValue(Vars.Legitbot.rifles.Delay, 500.f, strenc("Legitbot"), strenc("rifles.Delay"));
		SetupValue(Vars.Legitbot.rifles.Time, 5.f, strenc("Legitbot"), strenc("rifles.Time"));
		SetupValue(Vars.Legitbot.rifles.Hitbox, 6, strenc("Legitbot"), strenc("rifles.Hitbox"));
		SetupValue(Vars.Legitbot.rifles.Nearest, false, strenc("Legitbot"), strenc("rifles.Nearest"));
		SetupValue(Vars.Legitbot.rifles.RCSEnabled, true, strenc("Legitbot"), strenc("rifles.RCSEnabled"));
		SetupValue(Vars.Legitbot.rifles.RCSAmountX, 100.f, strenc("Legitbot"), strenc("rifles.RCSAmountX"));
		SetupValue(Vars.Legitbot.rifles.RCSAmountY, 100.f, strenc("Legitbot"), strenc("rifles.RCSAmountY"));

		SetupValue(Vars.Legitbot.smg.FOV, 10.f, strenc("Legitbot"), strenc("smg.FOV"));
		SetupValue(Vars.Legitbot.smg.Speed, 5.f, strenc("Legitbot"), strenc("smg.Smooth"));
		SetupValue(Vars.Legitbot.smg.Delay, 500.f, strenc("Legitbot"), strenc("smg.Delay"));
		SetupValue(Vars.Legitbot.smg.Time, 5.f, strenc("Legitbot"), strenc("smg.Time"));
		SetupValue(Vars.Legitbot.smg.Hitbox, 6, strenc("Legitbot"), strenc("smg.Hitbox"));
		SetupValue(Vars.Legitbot.smg.Nearest, false, strenc("Legitbot"), strenc("smg.Nearest"));
		SetupValue(Vars.Legitbot.smg.RCSEnabled, true, strenc("Legitbot"), strenc("smg.RCSEnabled"));
		SetupValue(Vars.Legitbot.smg.RCSAmountX, 100.f, strenc("Legitbot"), strenc("smg.RCSAmountX"));
		SetupValue(Vars.Legitbot.smg.RCSAmountY, 100.f, strenc("Legitbot"), strenc("smg.RCSAmountY"));

		SetupValue(Vars.Legitbot.shotguns.FOV, 10.f, strenc("Legitbot"), strenc("shotguns.FOV"));
		SetupValue(Vars.Legitbot.shotguns.Speed, 5.f, strenc("Legitbot"), strenc("shotguns.Smooth"));
		SetupValue(Vars.Legitbot.shotguns.Delay, 500.f, strenc("Legitbot"), strenc("shotguns.Delay"));
		SetupValue(Vars.Legitbot.shotguns.Hitbox, 6, strenc("Legitbot"), strenc("shotguns.Hitbox"));

		SetupValue(Vars.Legitbot.snipers.FOV, 10.f, strenc("Legitbot"), strenc("snipers.FOV"));
		SetupValue(Vars.Legitbot.snipers.Speed, 5.f, strenc("Legitbot"), strenc("snipers.Smooth"));
		SetupValue(Vars.Legitbot.snipers.Delay, 500.f, strenc("Legitbot"), strenc("snipers.Delay"));
		SetupValue(Vars.Legitbot.snipers.Hitbox, 6, strenc("Legitbot"), strenc("snipers.Hitbox"));
		SetupValue(Vars.Legitbot.snipers.StopZoom, false, strenc("Legitbot"), strenc("snipers.StopZoom"));
		SetupValue(Vars.Legitbot.snipers.FastZoom, false, strenc("Legitbot"), strenc("snipers.FastZoom"));
		SetupValue(Vars.Legitbot.snipers.FOVZoom, 12, strenc("Legitbot"), strenc("snipers.FOVZoom"));

	SetupValue(Vars.Legitbot.Triggerbot.Enabled, false, strenc("Triggerbot"), strenc("Enabled"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Friendly, false, strenc("Triggerbot"), strenc("Triggerbot on Key"));
	SetupValue(Vars.Legitbot.Triggerbot.AutoFire, false, strenc("Triggerbot"), strenc("Auto Fire"));
	SetupValue(Vars.Legitbot.Triggerbot.AutoWall, false, strenc("Triggerbot"), strenc("Auto Wall"));
	SetupValue(Vars.Legitbot.Triggerbot.HitChance, false, strenc("Triggerbot"), strenc("Hitchance"));
	SetupValue(Vars.Legitbot.Triggerbot.Key, 0, strenc("Triggerbot"), strenc("Key"));
	SetupValue(Vars.Legitbot.Triggerbot.HitChanceAmount, 60.f, strenc("Triggerbot"), strenc("Hitchance Amount"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Friendly, false, strenc("Triggerbot"), strenc("Triggerbot On Teammates"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Head, false, strenc("Triggerbot"), strenc("Triggerbot On Head"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Chest, false, strenc("Triggerbot"), strenc("Triggerbot On Chest"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Stomach, false, strenc("Triggerbot"), strenc("Triggerbot On Stomach"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Arms, false, strenc("Triggerbot"), strenc("Triggerbot On Arm"));
	SetupValue(Vars.Legitbot.Triggerbot.Filter.Legs, false, strenc("Triggerbot"), strenc("Triggerbot On Leg"));

	SetupValue(Vars.Visuals.Watermark, false, strenc("Visuals"), strenc("Watermark On"));
	SetupValue(Vars.Visuals.Enabled, true, strenc("Visuals"), strenc("Enabled"));
	SetupValue(Vars.Visuals.Box2D, true, strenc("Visuals"), strenc("Flat 2D"));
	SetupValue(Vars.Visuals.Box3D, true, strenc("Visuals"), strenc("Box 3D"));
	SetupValue(Vars.Visuals.Skeleton, false, strenc("Visuals"), strenc("Skeleton"));
	SetupValue(Vars.Visuals.Tracers, true, strenc("Visuals"), strenc("Tracers"));
	SetupValue(Vars.Visuals.FOVCircle, true, strenc("Visuals"), strenc("FOV Circle"));
	SetupValue(Vars.Visuals.BulletTrace, true, strenc("Visuals"), strenc("Bullet Tracers"));
	SetupValue(Vars.Visuals.SpectatorsTab, true, strenc("Visuals"), strenc("Spectators Tab"));
	//SetupValue(Vars.Visuals.RemovalsWeapon, true, strenc("Visuals"), strenc("No Weapon"));
	SetupValue(Vars.Visuals.RemovalsHands, true, strenc("Visuals"), strenc("No Hands"));
	SetupValue(Vars.Visuals.RemovalsFlash, true, strenc("Visuals"), strenc("No Flash"));
	//SetupValue(Vars.Visuals.RemovalsSmoke, true, strenc("Visuals"), strenc("No Smoke"));
	SetupValue(Vars.Visuals.BulletTraceLength, 200.f, strenc("Visuals"), strenc("Bullet Tracers Tracers Length"));
	SetupValue(Vars.Visuals.InfoName, true, strenc("Visuals"), strenc("Info Name"));
	SetupValue(Vars.Visuals.InfoHealth, true, strenc("Visuals"), strenc("Info Health"));
	SetupValue(Vars.Visuals.InfoArmor, true, strenc("Visuals"), strenc("Info Armor"));
	SetupValue(Vars.Visuals.InfoWeapon, true, strenc("Visuals"), strenc("Info Weapon"));
	SetupValue(Vars.Visuals.InfoFlashed, true, strenc("Visuals"), strenc("Info Flashed"));

	SetupValue(Vars.Visuals.Filter.Friendlies, true, strenc("Visuals"), strenc("ESP Show Teammates"));
	SetupValue(Vars.Visuals.Filter.Weapons, true, strenc("Visuals"), strenc("ESP Show Weapons"));
	SetupValue(Vars.Visuals.Filter.Decoy, true, strenc("Visuals"), strenc("ESP Show Decoy"));
	SetupValue(Vars.Visuals.Filter.C4, true, strenc("Visuals"), strenc("ESP Show Bomb"));

	SetupValue(Vars.Visuals.Chams.Enabled, true, strenc("Visuals"), strenc("Chams"));
	SetupValue(Vars.Visuals.colorsV, true, strenc("Visuals"), strenc("ColorsV"));
	SetupValue(Vars.Visuals.colorsNV, true, strenc("Visuals"), strenc("ColorsNV"));
	SetupValue(Vars.Visuals.colV.r, true, strenc("Visuals"), strenc("ColorsVr"));
	SetupValue(Vars.Visuals.colV.g, true, strenc("Visuals"), strenc("ColorsVg"));
	SetupValue(Vars.Visuals.colV.b, true, strenc("Visuals"), strenc("ColorsVb"));
	SetupValue(Vars.Visuals.colNV.r, true, strenc("Visuals"), strenc("ColorsNVr"));
	SetupValue(Vars.Visuals.colNV.g, true, strenc("Visuals"), strenc("ColorsNVg"));
	SetupValue(Vars.Visuals.colNV.b, true, strenc("Visuals"), strenc("ColorsNVb"));

	SetupValue(Vars.Visuals.colorsV2D, true, strenc("Visuals"), strenc("ColorsV"));
	SetupValue(Vars.Visuals.colorsNV2D, true, strenc("Visuals"), strenc("ColorsNV"));
	SetupValue(Vars.Visuals.colV2D.r, true, strenc("Visuals"), strenc("ColorsVr"));
	SetupValue(Vars.Visuals.colV2D.g, true, strenc("Visuals"), strenc("ColorsVg"));
	SetupValue(Vars.Visuals.colV2D.b, true, strenc("Visuals"), strenc("ColorsVb"));
	SetupValue(Vars.Visuals.colNV2D.r, true, strenc("Visuals"), strenc("ColorsNVr"));
	SetupValue(Vars.Visuals.colNV2D.g, true, strenc("Visuals"), strenc("ColorsNVg"));
	SetupValue(Vars.Visuals.colNV2D.b, true, strenc("Visuals"), strenc("ColorsNVb"));

	SetupValue(Vars.Visuals.Dlight, true, strenc("Visuals"), strenc("Dlight"));
	SetupValue(Vars.Visuals.RadiusDlight, true, strenc("Visuals"), strenc("Dlight Radius"));
	SetupValue(Vars.Visuals.collight.r, true, strenc("Visuals"), strenc("collightR"));
	SetupValue(Vars.Visuals.collight.g, true, strenc("Visuals"), strenc("collightG"));
	SetupValue(Vars.Visuals.collight.b, true, strenc("Visuals"), strenc("collightB"));
	SetupValue(Vars.Visuals.collightt, true, strenc("Visuals"), strenc("collightt"));


	SetupValue(Vars.Visuals.Chams.XQZ, true, strenc("Visuals"), strenc("Chams XQZ"));
	SetupValue(Vars.Visuals.Chams.Hands, true, strenc("Visuals"), strenc("Chams Hands"));
	SetupValue(Vars.Visuals.Chams.WireframeHands, true, strenc("Visuals"), strenc("Hands Wireframe"));
	SetupValue(Vars.Visuals.Chams.RainbowHands, true, strenc("Visuals"), strenc("Hands Rainbow"));
	SetupValue(Vars.Visuals.Chams.Mode, 0, strenc("Visuals"), strenc("Chams Mode"));
	SetupValue(Vars.Visuals.Chams.RainbowTime, 12, strenc("Visuals"), strenc("Rainbow Amount"));
	SetupValue(Vars.Visuals.Radar.Enabled, true, strenc("Visuals"), strenc("Radar Enabled"));
	SetupValue(Vars.Visuals.Radar.X, 500, strenc("Visuals"), strenc("Radar X Amount"));
	SetupValue(Vars.Visuals.Radar.Y, 500, strenc("Visuals"), strenc("Radar Y Amount"));
	SetupValue(Vars.Visuals.Radar.Range, 12, strenc("Visuals"), strenc("Radar Range Amount"));
	SetupValue(Vars.Visuals.Radar.Size, 100, strenc("Visuals"), strenc("Radar Size Amount"));

	SetupValue(Vars.Visuals.CrosshairEnabled, true, strenc("Visuals"), strenc("Crosshair"));
	SetupValue(Vars.Visuals.CrosshairType, true, strenc("Visuals"), strenc("Crosshair Type"));
	SetupValue(Vars.Visuals.CrosshairStyle, 0, strenc("Visuals"), strenc("Crosshair Style"));
	SetupValue(Vars.Visuals.RemovalsVisualRecoil, true, strenc("Visuals"), strenc("No Visual Recoil"));

	SetupValue(Vars.Misc.AutoPistol, true, strenc("Misc"), strenc("Auto Pistol"));
	SetupValue(Vars.Misc.Bunnyhop, true, strenc("Misc"), strenc("Bunnyhop"));
	SetupValue(Vars.Misc.Autostrafe, false, strenc("Misc"), strenc("Autostrafe"));
	SetupValue(Vars.Misc.AutostrafeTypes, 0, strenc("Misc"), strenc("Autostrafe Type"));
	SetupValue(Vars.Misc.EdgeJump, false, strenc("Misc"), strenc("Edge Jump"));
	SetupValue(Vars.Misc.FOV, 0, strenc("Misc"), strenc("FOV Amount"));
	SetupValue(Vars.Misc.FakeLag, 0, strenc("Misc"), strenc("FakeLag Amount"));
	SetupValue(Vars.Misc.AdaptiveFakeLag, false, strenc("Misc"), strenc("Adaptive FakeLag"));
	SetupValue(Vars.Misc.AirStuck, false, strenc("Misc"), strenc("AirStuck"));
	SetupValue(Vars.Misc.AirStuckKey, 0, strenc("Misc"), strenc("AirStuck Key"));
	SetupValue(Vars.Misc.AutoAccept, true, strenc("Misc"), strenc("Auto Accept"));
	SetupValue(Vars.Misc.Ranks, true, strenc("Misc"), strenc("Ranks"));
	SetupValue(Vars.Misc.IgnoreScope, false, strenc("Misc"), strenc("Ignore Scope"));
	SetupValue(Vars.Misc.AirStuck, false, strenc("Misc"), strenc("Lag Exploit"));

	SetupValue(Vars.Misc.ClantagChanger.enabled, false, strenc("Misc"), strenc("Clan Tag Enabled"));
	SetupValue(Vars.Misc.ClantagChanger.animation, false, strenc("Misc"), strenc("Clan Tag Animation"));
	SetupValue(Vars.Misc.ClantagChanger.animation_speed, 650, strenc("Misc"), strenc("Clan Tag Animation Speed"));
	SetupValue(Vars.Misc.ClantagChanger.type, STATICCT, strenc("Misc"), strenc("Clan Tag] Type"));
	Vars.Misc.ClantagChanger.value = strdup("BADSTER.XYZ");
	Vars.Misc.NameChangerenabled = false;
	SetupValue(Vars.Misc.NameChangerseparator_animation, false, strenc("Misc"), strenc("Nickname Animation"));

	SetupValue(Vars.Misc.HeadshotSay, true, strenc("Misc"), strenc("Chat Spam On"));
	SetupValue(Vars.Misc.HeadshotSay, true, strenc("Misc"), strenc("Chat Spam Location Spam"));
	SetupValue(Vars.Misc.HeadshotSay, true, strenc("Misc"), strenc("Chat Spam Location Spam Enemies Only"));
	SetupValue(Vars.Misc.HeadshotSay, true, strenc("Misc"), strenc("Chat Spam Location Spam Team Chat Only"));
	SetupValue(Vars.Misc.HeadshotSay, true, strenc("Misc"), strenc("Chat Spam Headshot"));
	//SetupValue(Vars.Misc.RefundSay, true, strenc("Misc"), strenc("Chat Spam Refund"));
	SetupValue(Vars.Misc.BombInfoChat, true, strenc("Misc"), strenc("Chat Spam Bomb Info"));
}

void CConfig::SetupValue( int &value, int def, std::string category, std::string name )
{
	value = def;
	ints.push_back( new ConfigValue<int>( category, name, &value ) );
}

void CConfig::SetupValue( float &value, float def, std::string category, std::string name )
{
	value = def;
	floats.push_back( new ConfigValue<float>( category, name, &value ) );
}

void CConfig::SetupValue( bool &value, bool def, std::string category, std::string name )
{
	value = def;
	bools.push_back( new ConfigValue<bool>( category, name, &value ) );
}

void CConfig::Save()
{
	static TCHAR path[ MAX_PATH ];
	std::string folder, file;

	if( SUCCEEDED( SHGetFolderPath( NULL, CSIDL_APPDATA, NULL, 0, path ) ) )
	{
		char szCmd[256];
		sprintf(szCmd, "\\BADSTER\\%s.ini", Vars.Misc.configname);

		folder = std::string( path ) + strenc( "\\BADSTER\\" );
		file = std::string(path) + szCmd;
	}

	CreateDirectory( folder.c_str(), NULL );

	for ( auto value : ints )
		WritePrivateProfileString( value->category.c_str(), value->name.c_str(), std::to_string( *value->value ).c_str(), file.c_str() );

	for ( auto value : floats )
		WritePrivateProfileString( value->category.c_str(), value->name.c_str(), std::to_string( *value->value ).c_str(), file.c_str() );

	for ( auto value : bools )
		WritePrivateProfileString( value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str() );
}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if ( SUCCEEDED( SHGetFolderPath( NULL, CSIDL_APPDATA, NULL, 0, path ) ) )
	{
		char szCmd[256];
		sprintf(szCmd, "\\BADSTER\\%s.ini", Vars.Misc.configname);

		folder = std::string(path) + strenc("\\BADSTER\\");
		file = std::string(path) + szCmd;
	}

	CreateDirectory( folder.c_str(), NULL );

	char value_l[32] = { '\0' };

	for ( auto value : ints )
	{
		GetPrivateProfileString( value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str() );
		*value->value = atoi( value_l );
	}

	for ( auto value : floats )
	{
		GetPrivateProfileString( value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str() );
		*value->value = atof( value_l );
	}

	for ( auto value : bools )
	{
		GetPrivateProfileString( value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str() );
		*value->value = !strcmp( value_l, "true" );
	}
}

CConfig* Config = new CConfig();
Variables Vars;