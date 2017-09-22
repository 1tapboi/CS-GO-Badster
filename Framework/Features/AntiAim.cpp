#include "../Cheat.h"

#define M_PHI		1.61803398874989484820

CAntiAim* AntiAim = new CAntiAim;

float Distance(Vector a, Vector b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

QAngle angle;

bool CAntiAim::GetBestHeadAngle(QAngle& angle)
{
	Vector position = G::LocalPlayer->GetEyePosition();

	float closest_distance = 100.0f;

	float radius = Vars.Ragebot.Antiaim.EdgeDistance + 0.1f;
	float step = M_PI * 2.0 / 8;

	for (float a = 0; a < (M_PI * 2.0); a += step)
	{
		Vector location(radius * cos(a) + position.x, radius * sin(a) + position.y, position.z);

		Ray_t ray;
		trace_t tr;
		ray.Init(position, location);
		CTraceFilter traceFilter;
		traceFilter.pSkip = G::LocalPlayer;
		I::EngineTrace->TraceRay(ray, 0x4600400B, &traceFilter, &tr);

		float distance = Distance(position, tr.endpos);

		if (distance < closest_distance)
		{
			closest_distance = distance;
			angle.y = RAD2DEG(a);
		}
	}

	return closest_distance < Vars.Ragebot.Antiaim.EdgeDistance;
}

bool CAntiAim::HasViableEnemy()
{
	for (int i = 1; i < I::Engine->GetMaxClients(); ++i)
	{
		CBaseEntity* entity = I::ClientEntList->GetClientEntity(i);

		if (!entity
			|| entity == G::LocalPlayer
			|| entity->GetDormant()
			|| !entity->GetAlive()
			|| entity->GetImmune())
			continue;

		if (Vars.Ragebot.FriendlyFire || entity->GetTeam() != G::LocalPlayer->GetTeam())
			return true;
	}

	return false;
}

void aimAtTarget()
{
	if( !G::LocalPlayer || !G::LocalPlayer->GetWeapon() || !G::LocalPlayer->GetWeapon()->GetCSWpnData() )
		return;

	Vector eye_position = G::LocalPlayer->GetEyePosition();

	float best_dist = G::LocalPlayer->GetWeapon()->GetCSWpnData()->m_flRange;

	CBaseEntity* target = I::ClientEntList->GetClientEntity( G::BestTarget );

	if( target == NULL )
		return;

	if( target == G::LocalPlayer )
		return;

	if( ( target->GetTeam() == G::LocalPlayer->GetTeam() ) || target->GetDormant() || !target->GetAlive() || target->GetHealth() <= 0 )
		return;

	Vector target_position = target->GetEyePosition();

	float temp_dist = eye_position.Dist( target_position );

	if( best_dist > temp_dist )
	{
		best_dist = temp_dist;
		angle = M::CalcAngle( eye_position, target_position );
	}
}

void DoAntiAimY(QAngle&  angle, bool bFlip)
{
	if (Vars.Ragebot.Antiaim.YawCustom)
	{
		angle.y = bFlip ? Vars.Ragebot.Antiaim.YCFake : Vars.Ragebot.Antiaim.YCReal;
		G::SendPacket = bFlip;
		Vars.Ragebot.Antiaim.FakeYaw = false;
	}
	else
	{
		if (Vars.Ragebot.Antiaim.FakeYaw)
		{
			int aa_type = bFlip ? Vars.Ragebot.Antiaim.YawReal : Vars.Ragebot.Antiaim.YawFake;

			static bool yFlip;
			yFlip = !yFlip;
			static float fYaw = 0.0f;
			double factor;
			static float trigger;
			float temp;
			float last;
			float faked;
			int jittertimer;
			int jitterang;
			int random;
			int maxJitter;

			if (aa_type == SPINBOT_CUSTOM_Y)
			{
				float CalculatedCurTime_1 = (I::Globals->curtime * (Vars.Ragebot.Antiaim.FakeSpinbotSpeed * 100));
				angle.y = CalculatedCurTime_1;
			}
			else if (aa_type == SPINBOT_SLOW_TYPE_FIRST)
			{
				factor = 360.0 / M_PHI;
				angle.y = fmodf(I::Globals->curtime * factor, 360.0);
			}
			else if (aa_type == SPINBOT_FAST_TYPE_FIRST)
			{
				factor = 360.0 / M_PHI;
				factor *= 25;
				angle.y = fmodf(I::Globals->curtime * factor, 360.0);
			}
			else if (aa_type == SPINBOT_SLOW_TYPE_SECOND)
			{
				float CalculatedCurTime = (I::Globals->curtime * 1000.0);
				angle.y = CalculatedCurTime;
			}
			else if (aa_type == SPINBOT_FAST_TYPE_SECOND)
			{
				float CalculatedCurTime_1 = (I::Globals->curtime * 5000.0);
				angle.y = CalculatedCurTime_1;
			}
			else if (aa_type == SPINBOT_SLOW_TYPE_THIRD)
			{
				jitterang += 5;
				angle.y = jitterang;
			}
			else if (aa_type == SPINBOT_FAST_TYPE_THIRD)
			{
				angle.y += jitterang;
				if (G::SendPacket)
					jitterang += 135;
			}
			else if (aa_type == JITTER_TYPE_FIRST)
			{
				yFlip ? angle.y -= 90.0f : angle.y -= 270.0f;
			}
			else if (aa_type == JITTER_TYPE_SECOND)
			{
				int v36 = G::UserCmd->command_number % 3;
				if (v36 == 1)
				{
					angle.y -= 160.0;
				}
				else if (v36 == 2)
				{
					angle.y -= 200.0;
				}
			}
			else if (aa_type == JITTER_TYPE_THIRD)
			{
				int temp = 120;
				if (jittertimer == 1)
					temp = -90;
				if (G::SendPacket)
				{
					if (jittertimer >= 1)
						jittertimer = -1;
					jittertimer++;
				}
				angle.y += temp;
			}
			else if (aa_type == JITTER_TYPE_FOURTH)
			{
				int temp = 157.5;
				if (jittertimer == 1)
					temp = -135;
				if (G::SendPacket)
				{
					if (jittertimer >= 1)
						jittertimer = -1;
					jittertimer++;
				}
				angle.y += temp;
			}
			else if (aa_type == JITTER_TYPE_FIFTH)
			{
				int temp = 90;
				if (jittertimer == 1)
					temp = 155;
				if (jittertimer >= 1)
					jittertimer = -1;
				jittertimer++;
				if (G::SendPacket)
					angle.y += temp;
				else
					angle.y += -temp;
			}
			else if (aa_type == JITTER_SYNCED)
			{
				int v36 = G::UserCmd->command_number % 3;
				angle.y = angle.y + 200.0;
			}
			else if (aa_type == JITTER_180)
			{
				yFlip ? angle.y += 180.f : angle.y += 180.0f;
			}
			else if (aa_type == JITTER_OPPOSING)
			{
				yFlip ? angle.y += 180.f : angle.y -= 180.0f;
			}
			else if (aa_type == BACK_JITTER)
			{
				angle.y -= 180;
				random = rand() % 100;
				maxJitter = rand() % (85 - 70 + 1) + 70;
				if (random < 35 + (rand() % 15))
					angle.y -= temp;
				else if (random < 85 + (rand() % 15))
					angle.y += temp;
			}
			else if (aa_type == JITTER_FORWARDS)
			{
				yFlip ? angle.y -= 180.f : angle.y += 180.0f;
			}
			else if (aa_type == JITTER_SIDEWAYS)
			{
				yFlip ? angle.y -= 89.f : angle.y += 89.0f;
			}
			else if (aa_type == STATIC_JITTER)
			{
				trigger += 15.0f;
				angle.y = trigger > 50.0f ? 150.0f : -150.0f;

				if (trigger > 100.0f)
					trigger = 0.0f;
			}
			else if (aa_type == STATIC_SMALL_JITTER)
			{
				trigger += 15.0f;
				angle.y = trigger > 50.0f ? -30.0f : 30.0f;

				if (trigger > 100.0f)
					trigger = 0.0f;
			}
			else if (aa_type == SIDE)
			{
				yFlip ? angle.y += 90.f : angle.y -= 90.0f;
			}
			else if (aa_type == SIDE_JITTER)
			{
				yFlip ? angle.y += 90.f : angle.y += 90.0f;
			}
			else if (aa_type == SIDE_BACKTRACK)
			{
				for (int nextTime = 0; nextTime <= 7; nextTime++) {
					switch (nextTime)
					{
					case 1:
						angle.y += 70;
						break;
					case 3:
						angle.y += 140;
						break;
					case 5:
						angle.y -= -70;
						break;
					case 7:
						angle.y -= -140;
						nextTime = 0;
						break;
					}
				}
			}
			else if (aa_type == SIDEWAYS_TYPE_FIRST)
			{
				yFlip ? angle.y += 90.f : angle.y -= 90.0f;
			}
			else if (aa_type == SIDEWAYS_TYPE_SECOND)
			{
				QAngle v37 = angle;
				angle.y = v37.y + 90.0;
			}
			else if (aa_type == SIDEWAYS_TYPE_THIRD)
			{
				int temp = 90;
				if (jittertimer == 1)
					temp = -90;
				if (G::SendPacket)
				{
					if (jittertimer >= 1)
						jittertimer = -1;
					jittertimer++;
				}
				angle.y += temp;
			}
			else if (aa_type == FAKE_SIDEWAYS_TYPE_FIRST)
			{
				QAngle v372 = angle;
				if (G::UserCmd->command_number % 2)
				{
					angle.y = v372.y + 90.0;
				}
				else
				{
					angle.y = v372.y - 90.0;
				}
			}
			else if (aa_type == FAKE_SIDEWAYS_TYPE_SECOND)
			{
				int temp;
				if (G::SendPacket)
					temp = 90;
				else
					temp = -150;
				angle.y += temp;
			}
			else if (aa_type == SIDEWAYS_180)
			{
				yFlip ? angle.y += 180.f : angle.y += 180.0f;
			}
			else if (aa_type == BACKWARDS_TYPE_SECOND)
			{
				QAngle OriginalY = angle;
				angle.y = angle.y + 180.0;
			}
			else if (aa_type == BACKWARDS_TYPE_THIRD)
			{
				if (G::SendPacket)
					angle.y += 180;
				else
				{
					int temp = last;
					bool ret = true;
					if (temp - angle.y > 180)
						temp -= 360;
					else if (temp - angle.y < -180)
						temp += 360;
					if (angle.y - temp < -3)
						faked = 90;
					else if (angle.y - temp > 3)
						faked = -90;
					else
						ret = false;
					if (ret)
						last = angle.y;
					angle.y += faked;
				}
			}
			else if (aa_type == FAKE_BACKWARDS)
			{
				if (!(G::UserCmd->command_number % 2))
				{
					QAngle OriginalY2 = angle;
					angle.y = OriginalY2.y + 180.0;
				}
			}
			else if (aa_type == FORWARDS_180)
			{
				yFlip ? angle.y += 180.f : angle.y += 180.0f;
			}
			else if (aa_type == FAKE_FORWARDS)
			{
				if (!(G::UserCmd->command_number % 2))
					angle.y = angle.y + 180.0;
			}
			else if (aa_type == ZERO_Y)
				angle.y -= 0;
			else if (aa_type == BACKWARDS_TYPE_FIRST)
				angle.y -= 180.0f;
			else if (aa_type == FORWARDS)
				angle.y -= 0.0f;
			else if (aa_type == SIDEWAYS_LEFT)
				angle.y += 90.0f;
			else if (aa_type == SIDEWAYS_RIGHT)
				angle.y -= 90.0f;
			else if (aa_type == STATICAA)
				angle.y = 0.0f;
		}
		else
		{
			static bool yFlip;
			yFlip = !yFlip;
			static float fYaw = 0.0f;
			double factor;
			static float trigger;
			float temp;
			float last;
			float faked;
			int jittertimer;
			int jitterang;
			int random;
			int maxJitter;

			int aa_type = Vars.Ragebot.Antiaim.YawReal;

			if (aa_type == SPINBOT_CUSTOM_Y)
			{
				float CalculatedCurTime_1 = (I::Globals->curtime * (Vars.Ragebot.Antiaim.FakeSpinbotSpeed * 100));
				angle.y = CalculatedCurTime_1;
			}
			else if (aa_type == SPINBOT_SLOW_TYPE_FIRST)
			{
				factor = 360.0 / M_PHI;
				angle.y = fmodf(I::Globals->curtime * factor, 360.0);
			}
			else if (aa_type == SPINBOT_FAST_TYPE_FIRST)
			{
				factor = 360.0 / M_PHI;
				factor *= 25;
				angle.y = fmodf(I::Globals->curtime * factor, 360.0);
			}
			else if (aa_type == SPINBOT_SLOW_TYPE_SECOND)
			{
				float CalculatedCurTime = (I::Globals->curtime * 1000.0);
				angle.y = CalculatedCurTime;
			}
			else if (aa_type == SPINBOT_FAST_TYPE_SECOND)
			{
				float CalculatedCurTime_1 = (I::Globals->curtime * 5000.0);
				angle.y = CalculatedCurTime_1;
			}
			else if (aa_type == SPINBOT_SLOW_TYPE_THIRD)
			{
				jitterang += 5;
				angle.y = jitterang;
			}
			else if (aa_type == SPINBOT_FAST_TYPE_THIRD)
			{
				angle.y += jitterang;
				if (G::SendPacket)
					jitterang += 135;
			}
			else if (aa_type == JITTER_TYPE_FIRST)
			{
				yFlip ? angle.y -= 90.0f : angle.y -= 270.0f;
			}
			else if (aa_type == JITTER_TYPE_SECOND)
			{
				int v36 = G::UserCmd->command_number % 3;
				if (v36 == 1)
				{
					angle.y -= 160.0;
				}
				else if (v36 == 2)
				{
					angle.y -= 200.0;
				}
			}
			else if (aa_type == JITTER_TYPE_THIRD)
			{
				int temp = 120;
				if (jittertimer == 1)
					temp = -90;
				if (G::SendPacket)
				{
					if (jittertimer >= 1)
						jittertimer = -1;
					jittertimer++;
				}
				angle.y += temp;
			}
			else if (aa_type == JITTER_TYPE_FOURTH)
			{
				int temp = 157.5;
				if (jittertimer == 1)
					temp = -135;
				if (G::SendPacket)
				{
					if (jittertimer >= 1)
						jittertimer = -1;
					jittertimer++;
				}
				angle.y += temp;
			}
			else if (aa_type == JITTER_TYPE_FIFTH)
			{
				int temp = 90;
				if (jittertimer == 1)
					temp = 155;
				if (jittertimer >= 1)
					jittertimer = -1;
				jittertimer++;
				if (G::SendPacket)
					angle.y += temp;
				else
					angle.y += -temp;
			}
			else if (aa_type == JITTER_SYNCED)
			{
				int v36 = G::UserCmd->command_number % 3;
				angle.y = angle.y + 200.0;
			}
			else if (aa_type == JITTER_180)
			{
				yFlip ? angle.y += 180.f : angle.y += 180.0f;
			}
			else if (aa_type == JITTER_OPPOSING)
			{
				yFlip ? angle.y += 180.f : angle.y -= 180.0f;
			}
			else if (aa_type == BACK_JITTER)
			{
				angle.y -= 180;
				random = rand() % 100;
				maxJitter = rand() % (85 - 70 + 1) + 70;
				if (random < 35 + (rand() % 15))
					angle.y -= temp;
				else if (random < 85 + (rand() % 15))
					angle.y += temp;
			}
			else if (aa_type == JITTER_FORWARDS)
			{
				yFlip ? angle.y -= 180.f : angle.y += 180.0f;
			}
			else if (aa_type == JITTER_SIDEWAYS)
			{
				yFlip ? angle.y -= 89.f : angle.y += 89.0f;
			}
			else if (aa_type == STATIC_JITTER)
			{
				trigger += 15.0f;
				angle.y = trigger > 50.0f ? 150.0f : -150.0f;

				if (trigger > 100.0f)
					trigger = 0.0f;
			}
			else if (aa_type == STATIC_SMALL_JITTER)
			{
				trigger += 15.0f;
				angle.y = trigger > 50.0f ? -30.0f : 30.0f;

				if (trigger > 100.0f)
					trigger = 0.0f;
			}
			else if (aa_type == SIDE)
			{
				yFlip ? angle.y += 90.f : angle.y -= 90.0f;
			}
			else if (aa_type == SIDE_JITTER)
			{
				yFlip ? angle.y += 90.f : angle.y += 90.0f;
			}
			else if (aa_type == SIDE_BACKTRACK)
			{
				for (int nextTime = 0; nextTime <= 7; nextTime++) {
					switch (nextTime)
					{
					case 1:
						angle.y += 70;
						break;
					case 3:
						angle.y += 140;
						break;
					case 5:
						angle.y -= -70;
						break;
					case 7:
						angle.y -= -140;
						nextTime = 0;
						break;
					}
				}
			}
			else if (aa_type == SIDEWAYS_TYPE_FIRST)
			{
				yFlip ? angle.y += 90.f : angle.y -= 90.0f;
			}
			else if (aa_type == SIDEWAYS_TYPE_SECOND)
			{
				QAngle v37 = angle;
				angle.y = v37.y + 90.0;
			}
			else if (aa_type == SIDEWAYS_TYPE_THIRD)
			{
				int temp = 90;
				if (jittertimer == 1)
					temp = -90;
				if (G::SendPacket)
				{
					if (jittertimer >= 1)
						jittertimer = -1;
					jittertimer++;
				}
				angle.y += temp;
			}
			else if (aa_type == FAKE_SIDEWAYS_TYPE_FIRST)
			{
				QAngle v372 = angle;
				if (G::UserCmd->command_number % 2)
				{
					angle.y = v372.y + 90.0;
				}
				else
				{
					angle.y = v372.y - 90.0;
				}
			}
			else if (aa_type == FAKE_SIDEWAYS_TYPE_SECOND)
			{
				int temp;
				if (G::SendPacket)
					temp = 90;
				else
					temp = -150;
				angle.y += temp;
			}
			else if (aa_type == SIDEWAYS_180)
			{
				yFlip ? angle.y += 180.f : angle.y += 180.0f;
			}
			else if (aa_type == BACKWARDS_TYPE_SECOND)
			{
				QAngle OriginalY = angle;
				angle.y = angle.y + 180.0;
			}
			else if (aa_type == BACKWARDS_TYPE_THIRD)
			{
				if (G::SendPacket)
					angle.y += 180;
				else
				{
					int temp = last;
					bool ret = true;
					if (temp - angle.y > 180)
						temp -= 360;
					else if (temp - angle.y < -180)
						temp += 360;
					if (angle.y - temp < -3)
						faked = 90;
					else if (angle.y - temp > 3)
						faked = -90;
					else
						ret = false;
					if (ret)
						last = angle.y;
					angle.y += faked;
				}
			}
			else if (aa_type == FAKE_BACKWARDS)
			{
				if (!(G::UserCmd->command_number % 2))
				{
					QAngle OriginalY2 = angle;
					angle.y = OriginalY2.y + 180.0;
				}
			}
			else if (aa_type == FORWARDS_180)
			{
				yFlip ? angle.y += 180.f : angle.y += 180.0f;
			}
			else if (aa_type == FAKE_FORWARDS)
			{
				if (!(G::UserCmd->command_number % 2))
					angle.y = angle.y + 180.0;
			}
			else if (aa_type == ZERO_Y)
				angle.y -= 0;
			else if (aa_type == BACKWARDS_TYPE_FIRST)
				angle.y -= 180.0f;
			else if (aa_type == FORWARDS)
				angle.y -= 0.0f;
			else if (aa_type == SIDEWAYS_LEFT)
				angle.y += 90.0f;
			else if (aa_type == SIDEWAYS_RIGHT)
				angle.y -= 90.0f;
			else if (aa_type == STATICAA)
				angle.y = 0.0f;
		}
	}
}

void DoAntiAimZ()
{
	QAngle angle = G::UserCmd->viewangles;
	int aaz_type = Vars.Ragebot.Antiaim.Zeta;

	if (aaz_type == SPINBOT_Z)
	{
		float CalculatedCurTime = (I::Globals->curtime * 1000.0);
		angle.z = CalculatedCurTime;
	}
	else if (aaz_type == JITTER_Z)
	{
		int v36 = G::UserCmd->command_number % 3;
		if (v36 == 1)
		{
			angle.z = angle.z - 160.0;
		}
		else if (v36 == 2)
		{
			angle.z = angle.z - 200.0;
		}
	}
	else if (aaz_type == SIDEWAYS_Z)
	{
		QAngle v372 = angle;
		if (G::UserCmd->command_number % 2)
		{
			angle.z = v372.z + 90.0;
		}
		else
		{
			angle.z = v372.z - 90.0;
		}
	}
}

void CAntiAim::Run()
{
	if (Vars.Ragebot.AimStep && G::Aimbotting)
		return;

	if (!Vars.Ragebot.Enabled)
		return;
	
	if (!G::LocalPlayer || !G::LocalPlayer->GetWeapon())
		return;
	
	QAngle oldAngle = G::UserCmd->viewangles;
	float oldForward = G::UserCmd->forwardmove;
	float oldSideMove = G::UserCmd->sidemove;

	if (G::UserCmd->buttons & IN_USE || G::UserCmd->buttons & IN_ATTACK || G::LocalPlayer->GetWeapon()->IsGrenade() )
		return;

	if (G::LocalPlayer->GetMoveType() == MOVETYPE_LADDER || G::LocalPlayer->GetMoveType() == MOVETYPE_NOCLIP)
		return;
		
	if (Vars.Ragebot.Antiaim.Knife && G::LocalPlayer->GetAlive() && G::LocalPlayer->GetWeapon()->IsKnife())
		return;

	if (Vars.Ragebot.Antiaim.NoEnemy && G::LocalPlayer->GetAlive() && !HasViableEnemy()) // 
		return;

	angle = G::UserCmd->viewangles;

	if (Vars.Ragebot.Antiaim.AtPlayer)
		aimAtTarget();
	
	QAngle edge_angle = angle;

	bool edging_head = Vars.Ragebot.Antiaim.Edge && GetBestHeadAngle(edge_angle);

	static bool bFlip;
	static float pDance = 0.0f;

	bFlip = !bFlip;

	if (Vars.Ragebot.Antiaim.YawReal)
	{
		DoAntiAimY(angle, bFlip);

		if (Vars.Ragebot.AntiUntrusted)
		angle.Clamp();

		G::SendPacket = bFlip;
		if (Vars.Ragebot.Antiaim.Edge && edging_head && !bFlip)
			angle.y = edge_angle.y;
	}

	if (Vars.Ragebot.Antiaim.Zeta && !Vars.Ragebot.AntiUntrusted)
		DoAntiAimZ();

	if (Vars.Ragebot.Antiaim.Pitch)
	{
		if (Vars.Ragebot.Antiaim.PitchCustom)
		{
				angle.x = bFlip ? Vars.Ragebot.Antiaim.PCFake : Vars.Ragebot.Antiaim.PCReal;
				G::SendPacket = bFlip;
		}
		else
		{
			int pitch_aa_type = Vars.Ragebot.Antiaim.Pitch;

			if (pitch_aa_type == STATIC_UP_TYPE_FIRST)
			    angle.x = 180.f;
			if (pitch_aa_type == STATIC_UP_TYPE_SECOND)
				angle.x = -180.f;
			if (pitch_aa_type == STATIC_UP_TYPE_THIRD)
				angle.x = bFlip ? 180.0f : 180.0f;
			if (pitch_aa_type == STATIC_UP_TYPE_FOURTH)
				angle.x = bFlip ? -180.0f : 180.0f;
			else if (pitch_aa_type == STATIC_DOWN_TYPE_FIRST)
				angle.x = 89.0f;
			else if (pitch_aa_type == STATIC_DOWN_TYPE_SECOND)
				angle.x = -89.0f;
			else if (pitch_aa_type == STATIC_DOWN_TYPE_THIRD)
				angle.x = 89.000000;
			else if (pitch_aa_type == EMOTION_TYPE_FIRST)
				angle.x = 89.f;
			else if (pitch_aa_type == EMOTION_TYPE_SECOND)
				angle.x = -89.f;
			else if (pitch_aa_type == EMOTION_TYPE_THIRD)
				angle.x = 89.000000;
			if (G::SendPacket)
				angle.x = -89.f;
			else if (pitch_aa_type == ZERO_X)
				angle.x = 1080.0;
			else if (pitch_aa_type == RELIANT)
				angle.x = 1080.0;
			else if (pitch_aa_type == DANCE_TYPE_FIRST)
			{
				pDance += 45.0f;
				if (pDance > 100)
					pDance = 0.0f;
				else if (pDance > 75.f)
					angle.x = -89.f;
				else if (pDance < 75.f)
					angle.x = 89.f;
			}
			else if (pitch_aa_type == FRONT)
				angle.x = 0.0f;
			else if (pitch_aa_type == STATIC_UP_FAKE_TYPE_FIRST)
			{
				angle.x = bFlip ? 89.0f : -89.0f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == STATIC_UP_FAKE_TYPE_SECOND)
			{
				angle.x = bFlip ? 991.0f : 991.0f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == STATIC_DOWN_FAKE_TYPE_FIRST)
			{
				angle.x = bFlip ? -89.0f : 89.0f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == STATIC_DOWN_FAKE_TYPE_SECOND)
			{
				angle.x = bFlip ? -180.f : 180.f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == STATIC_DOWN_FAKE_TYPE_THIRD)
			{
				angle.x = bFlip ? -179.998992f : -179.998992f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == STATIC_DOWN_FAKE_TYPE_FOURTH)
			{
				angle.x = bFlip ? 180.0f : -180.0f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == FAKE_ZERO_X)
			{
				angle.x = bFlip ? 1080.0f : 1080.0f / -1080.0f;
				G::SendPacket = bFlip;
			}
			else if (pitch_aa_type == SPINBOT)
			{
				float CalculatedCurTime = (I::Globals->curtime * 1000.0);
				angle.x = CalculatedCurTime;
			}
		}
	}

	bool should_clamp = true;
	
	if (Vars.Ragebot.Antiaim.AntiResolver)
	{
		static bool antiResolverFlip = false;
		CBaseEntity* localplayer;

		if (G::UserCmd->viewangles.y == *localplayer->GetLowerBodyYawTarget())
		{
			if (antiResolverFlip)
				G::UserCmd->viewangles.y += 60.f;
			else
				G::UserCmd->viewangles.y -= 60.f;

			antiResolverFlip = !antiResolverFlip;

			if (should_clamp)
			{
				M::NormalizeAngles(G::UserCmd->viewangles);
				M::ClampAngles(G::UserCmd->viewangles);
			}
		}

	}

	if (Vars.Ragebot.AntiUntrusted)
	{
		if (Vars.Ragebot.Antiaim.Pitch == STATIC_DOWN_TYPE_FIRST || Vars.Ragebot.Antiaim.Pitch == EMOTION_TYPE_FIRST || Vars.Ragebot.Antiaim.Pitch == FRONT || Vars.Ragebot.Antiaim.Pitch == DANCE_TYPE_FIRST)
		{

		}
		else
		{
			Vars.Ragebot.Antiaim.Pitch = NOANTIAIMPITCH;
		}

	}

	if (Vars.Ragebot.AntiUntrusted)
		angle.Clamp();

	G::UserCmd->viewangles = angle;

	M::CorrectMovement(oldAngle, G::UserCmd, oldForward, oldSideMove);	
}