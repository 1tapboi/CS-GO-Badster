#pragma once

struct GlowObject_t {
	CBaseEntity*	m_pEntity;
	Vector			m_vGlowColor;
	float			m_flGlowAlpha;
	unsigned char   junk[ 16 ];
	bool			m_bRenderWhenOccluded;
	bool			m_bRenderWhenUnoccluded;
	bool			m_bFullBloomRender;
	unsigned char   junk2[ 13 ];
};

class CVisuals
{
public:
	void Run( );
	void Watermark();
	void BombTimer(CBaseEntity * pEntity);
	void BulletTraceOverlay( CBaseEntity* entity, Color color );
	bool EntityIsInvalid( CBaseEntity* Entity );
	void DrawGlow();
	void SpectatorsTab();
private:
	bool InGame();
	
	CBaseEntity *BombCarrier;

	void PlayerESP( int index );
	void WorldESP( int index );
	void BulletTrace(CBaseEntity* entity, Color color);
	void RadarEntity(int index);
	void FOVCrosshair();
	void PlayerBox( float x, float y, float w, float h, Color clr );
	void HealthBar( Vector bot, Vector top, float health );
	void ArmorBar(Vector bot, Vector top, float armor);
	void Skeleton( CBaseEntity *Entity, Color color );
	void DrawHitbox( matrix3x4a_t* matrix, Vector bbmin, Vector bbmax, int bone, Color color );
	void Hitboxes( CBaseEntity *Entity, Color color );
	void DrawCrosshair( Color color );
	void Dlight();
};