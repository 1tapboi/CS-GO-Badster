#include "SDK.h"
#include "SkinChanger.h"
#include "Settings\Vars.h"

void KnifeApplyCallbk()
{
	static ConVar* Meme = I::Cvar->FindVar("cl_fullupdate");
	Meme->nFlags &= ~FCVAR_CHEAT;
	I::Engine->ClientCmd_Unrestricted("cl_fullupdate", 0);
}

void SkinChanger::FrameStageNotify(ClientFrameStage_t stage)
{
	if (stage == FRAME_NET_UPDATE_POSTDATAUPDATE_START)
	{
		CBaseEntity *pLocal = G::LocalPlayer;

		for (int i = I::ClientEntList->GetHighestEntityIndex(); i >= 0; --i)
		{
			CBaseEntity *pEntity = I::ClientEntList->GetClientEntity(i);

			if (pEntity)
			{
				ULONG hOwnerEntity = *(PULONG)((DWORD)pEntity + 0x148);

				CBaseEntity* pOwner = I::ClientEntList->GetClientEntityFromHandle((HANDLE)hOwnerEntity);

				if (pOwner)
				{
					if (pOwner == pLocal)
					{
						CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)pEntity;

						ClientClass *pClass = I::Client->GetAllClasses();

						if (Vars.Skins.SSEnabled)
						{
							int M41S = Vars.Skins.M41S;
							int fiveseven = Vars.Skins.fiveseven;
							int AUG = Vars.Skins.AUG;
							int Famas = Vars.Skins.Famas;
							int M4A4 = Vars.Skins.M4A4;
							int AK47 = Vars.Skins.AK47;
							int Berettas = Vars.Skins.BERETTAS;
							int AWP = Vars.Skins.AWP;
							int Glock = Vars.Skins.Glock;
							int USPS = Vars.Skins.USPS;
							int P2000 = Vars.Skins.P2000;
							int Magnum = Vars.Skins.Magnum;
							int Galil = Vars.Skins.Galil;
							int tec9 = Vars.Skins.tec9;
							int p250 = Vars.Skins.P250;
							int CZ75 = Vars.Skins.CZ75;
							int revolver = Vars.Skins.revolver;
							int mac10 = Vars.Skins.mac10;
							int mp7 = Vars.Skins.mp7;
							int mp9 = Vars.Skins.mp9;
							int p90 = Vars.Skins.p90;
							int ppbizon = Vars.Skins.ppbizon;
							int ump45 = Vars.Skins.ump45;
							int m249 = Vars.Skins.m249;
							int mag7 = Vars.Skins.mag7;
							int negev = Vars.Skins.negev;
							int nova = Vars.Skins.nova;
							int sawed = Vars.Skins.sawed;
							int xm1014 = Vars.Skins.xm1014;
							int sg = Vars.Skins.sg;
							int g3 = Vars.Skins.g3;
							int ssg = Vars.Skins.ssg;
							int scar = Vars.Skins.scar;
							int knife = Vars.Skins.knife;

							if (pWeapon->GetItemDefinitionIndex() == 60)
							{
								switch (M41S)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 430;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 77;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 254;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 189;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 301;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 217;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 257;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 321;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 326;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 360;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 383;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 440;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 445;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 497;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 16)
							{
								switch (M4A4)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 8;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 101;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 167;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 164;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 16;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 17;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 155;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 170;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 176;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 187;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 255;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 309;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 215;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 336;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 384;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 400;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 449;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 471;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 480;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 512;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 533;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 7)
							{
								switch (AK47)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 341;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 14;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 44;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 72;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 122;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 170;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 172;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 180;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 394;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 300;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 226;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 282;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 302;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 316;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 340;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 380;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 422;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 456;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 474;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 490;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 506;
									break;
								case 22:
									pWeapon->GetFallbackPaintKit() = 524;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 9)
							{
								switch (AWP)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 475;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 279;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 344;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 51;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 259;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 251;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 212;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 174;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 84;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 395;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 181;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 227;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 446;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 451;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 525;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 584;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 72;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 4)
							{
								switch (Glock)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 2;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 3;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 38;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 40;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 48;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 437;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 99;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 159;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 399;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 208;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 230;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 278;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 293;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 35;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 367;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 381;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 479;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 495;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 532;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 61)
							{
								switch (USPS)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 25;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 60;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 183;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 339;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 217;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 221;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 236;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 277;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 290;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 313;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 318;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 332;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 364;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 454;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 489;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 504;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 540;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 2)
							{
								switch (Berettas)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 28;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 36;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 43;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 46;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 47;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 153;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 190;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 248;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 249;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 220;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 396;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 261;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 276;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 307;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 330;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 447;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 450;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 491;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 528;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 1)
							{
								switch (Magnum)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 37;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 347;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 468;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 469;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 12;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 17;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 40;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 61;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 90;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 185;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 248;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 231;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 232;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 237;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 397;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 328;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 273;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 296;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 351;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 425;
									break;
								case 22:
									pWeapon->GetFallbackPaintKit() = 470;
									break;
								case 23:
									pWeapon->GetFallbackPaintKit() = 509;
									break;
								case 24:
									pWeapon->GetFallbackPaintKit() = 527;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 3)
							{
								switch (fiveseven)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 3;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 44;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 46;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 78;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 141;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 151;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 254;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 248;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 210;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 223;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 252;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 265;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 274;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 464;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 352;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 377;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 387;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 427;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 464;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 510;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 530;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 8)
							{
								switch (AUG)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 73;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 10;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 9;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 28;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 167;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 110;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 33;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 100;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 46;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 47;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 197;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 280;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 305;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 375;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 442;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 444;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 455;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 507;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 10)
							{
								switch (Famas)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 47;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 92;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 28;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 429;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 154;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 178;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 194;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 244;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 218;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 260;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 288;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 371;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 477;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 492;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 529;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 13)
							{
								switch (Galil)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 83;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 428;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 76;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 119;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 398;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 192;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 308;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 216;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 237;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 241;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 264;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 297;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 379;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 460;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 478;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 494;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 30)
							{
								switch (tec9)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 101;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 2;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 463;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 17;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 36;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 439;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 159;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 179;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 248;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 206;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 216;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 242;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 272;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 289;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 303;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 374;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 459;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 463;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 520;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 539;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 32)
							{
								switch (P2000)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 104;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 32;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 21;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 25;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 36;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 485;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 38;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 71;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 95;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 184;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 211;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 206;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 338;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 246;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 275;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 327;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 346;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 357;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 389;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 442;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 443;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 485;
									break;
								case 22:
									pWeapon->GetFallbackPaintKit() = 515;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 36)
							{
								switch (p250)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 102;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 34;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 162;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 15;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 164;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 77;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 99;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 168;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 258;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 207;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 219;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 404;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 230;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 271;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 295;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 464;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 358;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 373;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 388;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 426;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 466;
									break;
								case 22:
									pWeapon->GetFallbackPaintKit() = 467;
									break;
								case 23:
									pWeapon->GetFallbackPaintKit() = 501;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 63)
							{
								switch (CZ75)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 435;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 12;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 254;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 218;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 268;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 269;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 270;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 297;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 315;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 322;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 325;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 334;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 350;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 366;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 453;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 476;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 64)
							{
								switch (revolver)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 12;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 522;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 523;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 17)
							{
								switch (mac10)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 101;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 3;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 32;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 17;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 38;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 433;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 98;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 157;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 188;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 337;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 246;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 284;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 310;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 333;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 343;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 372;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 402;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 433;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 498;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 534;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 33)
							{
								switch (mp7)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 2;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 102;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 28;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 11;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 15;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 36;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 141;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 245;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 209;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 213;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 250;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 354;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 365;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 423;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 442;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 481;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 500;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 536;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 34)
							{
								switch (mp9)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 482;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 33;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 100;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 39;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 61;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 148;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 141;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 199;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 329;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 262;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 366;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 368;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 386;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 403;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 448;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 482;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 19)
							{
								switch (p90)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 342;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 20;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 100;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 67;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 111;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 124;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 156;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 234;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 169;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 175;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 182;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 244;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 228;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 283;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 311;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 335;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 359;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 486;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 516;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 26)
							{
								switch (ppbizon)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 13;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 164;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 25;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 70;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 148;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 149;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 159;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 171;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 203;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 224;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 236;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 267;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 306;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 323;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 349;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 376;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 457;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 459;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 508;
									break;
								case 22:
									pWeapon->GetFallbackPaintKit() = 526;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 26)
							{
								switch (ump45)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 37;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 15;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 17;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 436;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 70;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 93;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 169;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 175;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 193;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 392;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 281;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 333;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 362;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 441;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 488;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 14)
							{
								switch (m249)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 75;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 202;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 243;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 266;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 401;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 452;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 472;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 496;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 27)
							{
								switch (mag7)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 462;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 34;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 32;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 100;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 39;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 431;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 99;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 171;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 177;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 198;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 291;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 385;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 473;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 499;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 535;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 28)
							{
								switch (negev)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 28;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 432;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 157;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 201;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 240;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 285;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 298;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 317;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 355;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 369;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 483;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 514;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 35)
							{
								switch (nova)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 3;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 166;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 164;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 25;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 62;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 99;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 107;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 158;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 170;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 191;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 214;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 225;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 263;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 286;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 294;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 299;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 356;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 450;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 484;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 537;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 29)
							{
								switch (sawed)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 345;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 5;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 30;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 83;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 38;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 41;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 434;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 119;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 171;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 204;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 405;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 246;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 250;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 390;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 256;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 323;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 458;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 459;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 517;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 25)
							{
								switch (xm1014)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 166;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 238;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 42;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 96;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 95;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 135;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 151;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 169;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 205;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 240;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 251;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 393;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 320;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 314;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 348;
									break;
								case 18:
									pWeapon->GetFallbackPaintKit() = 370;
									break;
								case 19:
									pWeapon->GetFallbackPaintKit() = 407;
									break;
								case 20:
									pWeapon->GetFallbackPaintKit() = 505;
									break;
								case 21:
									pWeapon->GetFallbackPaintKit() = 521;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 39)
							{
								switch (sg)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 101;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 28;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 22;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 39;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 98;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 136;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 410;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 169;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 186;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 243;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 247;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 287;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 298;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 363;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 378;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 487;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 519;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 40)
							{
								switch (ssg)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 59;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 26;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 38;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 60;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 96;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 99;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 157;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 200;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 222;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 233;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 253;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 304;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 319;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 361;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 503;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 538;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 38)
							{
								switch (scar)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 165;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 100;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 46;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 70;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 116;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 157;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 196;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 232;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 391;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 298;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 312;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 406;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 453;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 502;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 518;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							else if (pWeapon->GetItemDefinitionIndex() == 11)
							{
								switch (g3)
								{
								case 0:
									pWeapon->GetFallbackPaintKit() = 8;
									break;
								case 1:
									pWeapon->GetFallbackPaintKit() = 6;
									break;
								case 2:
									pWeapon->GetFallbackPaintKit() = 27;
									break;
								case 3:
									pWeapon->GetFallbackPaintKit() = 46;
									break;
								case 4:
									pWeapon->GetFallbackPaintKit() = 72;
									break;
								case 5:
									pWeapon->GetFallbackPaintKit() = 74;
									break;
								case 6:
									pWeapon->GetFallbackPaintKit() = 147;
									break;
								case 7:
									pWeapon->GetFallbackPaintKit() = 235;
									break;
								case 8:
									pWeapon->GetFallbackPaintKit() = 170;
									break;
								case 9:
									pWeapon->GetFallbackPaintKit() = 195;
									break;
								case 10:
									pWeapon->GetFallbackPaintKit() = 229;
									break;
								case 11:
									pWeapon->GetFallbackPaintKit() = 294;
									break;
								case 12:
									pWeapon->GetFallbackPaintKit() = 465;
									break;
								case 13:
									pWeapon->GetFallbackPaintKit() = 464;
									break;
								case 14:
									pWeapon->GetFallbackPaintKit() = 382;
									break;
								case 15:
									pWeapon->GetFallbackPaintKit() = 438;
									break;
								case 16:
									pWeapon->GetFallbackPaintKit() = 465;
									break;
								case 17:
									pWeapon->GetFallbackPaintKit() = 493;
									break;
								}
								pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}





							/*if (pEntity->GetClientClass()->m_ClassID == 91)
							{




							pWeapon->GetItemDefinitionIndex() = 507;

							pWeapon->GetEntityQuality() = 3;

							pWeapon->GetFallbackPaintKit() = 38; // Fade
							pWeapon->GetFallbackWear() = Vars.Skins.Wear;
							}
							//pWeapon->GetItemIDHigh() = -1;
							pWeapon->GetItemIDHigh() = -1;


							HANDLE viewmodel_handle = G::LocalPlayer->GetViewModel();
							CBaseViewModel* viewmodel = (CBaseViewModel*)I::ClientEntList->GetClientEntityFromHandle(viewmodel_handle);
							// Convert the view model handle into an entity pointer.


							if (pWeapon->GetItemDefinitionIndex() == 42)
							{
							pWeapon->GetModelIndex() = I::ModelInfo->GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
							*viewmodel->GetModelIndex() = I::ModelInfo->GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
							}

							if (pWeapon->GetItemDefinitionIndex() == 59)
							{
							pWeapon->GetModelIndex() = I::ModelInfo->GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
							*viewmodel->GetModelIndex() = I::ModelInfo->GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
							}*/



							if (Vars.Skins.StatTrk > 0) {
								pWeapon->GetFallbackStatTrak() = Vars.Skins.StatTrk;
								pWeapon->GetEntityQuality() = 4;
							}


							player_info_t localplayer_info;

							if (I::Engine->GetPlayerInfo(I::Engine->GetLocalPlayer(), &localplayer_info))
								pWeapon->GetAccountID() = localplayer_info.xuidlow;
						}
					}
				}
			}
		}
	}
}