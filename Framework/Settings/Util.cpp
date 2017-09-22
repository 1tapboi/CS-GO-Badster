#include "../SDK.h"

MsgFn U::PrintMessage = ( MsgFn )GetProcAddress( GetModuleHandleA( charenc( "tier0.dll" ) ), charenc( "Msg" ) );
SendClanTagFn U::SendClanTag;
ServerRankRevealAllFn U::ServerRankRevealAllEx;
InitKeyValuesFn U::InitKeyValuesEx;
LoadFromBufferFn U::LoadFromBufferEx;
IsReadyFn U::IsReady;
CL_FullUpdate_t U::CL_FullUpdate = NULL;



void U::SetupInterfaces()
{
	I::Client			= U::CaptureInterface<IBaseClientDll>( strenc( "client.dll" ), strenc( "VClient018" ) );
	I::ClientMode		= **( IClientModeShared*** ) ( ( *( DWORD** ) I::Client )[10] + 0x5 );
	I::ClientEntList	= U::CaptureInterface<IClientEntityList>( strenc( "client.dll" ), strenc( "VClientEntityList003" ) );
	I::Cvar				= U::CaptureInterface<ICVar>( strenc( "vstdlib.dll" ), strenc( "VEngineCvar007" ) );
	I::Engine			= U::CaptureInterface<IEngineClient>( strenc( "engine.dll" ), strenc( "VEngineClient014" ) );
	I::EngineTrace		= U::CaptureInterface<IEngineTrace>( strenc( "engine.dll" ), strenc( "EngineTraceClient004" ) );
	I::InputSystem		= U::CaptureInterface<IInputSystem>( strenc( "inputsystem.dll" ), strenc( "InputSystemVersion001" ) );
	I::Globals			= **( IGlobalVarsBase*** ) ( ( *( DWORD** ) I::Client )[0] + 0x1B);
	I::Surface			= U::CaptureInterface<ISurface>( strenc( "vguimatsurface.dll" ), strenc( "VGUI_Surface031" ) );
	I::GameEvent		= U::CaptureInterface<IGameEventManager2>(strenc("engine.dll"), strenc("GAMEEVENTSMANAGER002"));
	I::VPanel			= U::CaptureInterface<IVPanel>( strenc( "vgui2.dll" ), strenc( "VGUI_Panel009" ) );
	I::RenderView		= U::CaptureInterface<IVRenderView>( strenc( "engine.dll" ), strenc( "VEngineRenderView014" ) );
	I::ModelRender		= U::CaptureInterface<IVModelRender>( strenc( "engine.dll" ), strenc( "VEngineModel016" ) );
	I::MaterialSystem	= U::CaptureInterface<IMaterialSystem>( strenc( "materialsystem.dll" ), strenc( "VMaterialSystem080" ) );
	I::ModelInfo		= U::CaptureInterface<IVModelInfo>( strenc( "engine.dll" ), strenc( "VModelInfoClient004" ) );
	I::GameMovement		= U::CaptureInterface<IGameMovement>( strenc( "client.dll" ), strenc( "GameMovement001" ) );
	I::Prediction		= U::CaptureInterface<IPrediction>( strenc( "client.dll" ), strenc( "VClientPrediction001" ) );
	I::Physprops		= U::CaptureInterface<IPhysicsSurfaceProps>( strenc( "vphysics.dll" ), strenc( "VPhysicsSurfaceProps001" ) );
	I::DebugOverlay		= U::CaptureInterface<IVDebugOverlay>( strenc( "engine.dll" ), strenc( "VDebugOverlay004" ) );
	I::StudioRender		= U::CaptureInterface<IStudioRender>( strenc( "studiorender.dll" ), strenc( "VStudioRender026" ) );
	I::MoveHelper 		= **(IMoveHelper***)(U::FindPattern("client.dll", "8B 0D ? ? ? ? 8B 46 08 68") + 2);
	I::Ceffect			= U::CaptureInterface<CEffects>(strenc("engine.dll"), strenc("VEngineEffects001"));
}


DWORD U::FindPattern( std::string moduleName, std::string pattern )
{
	const char* pat = pattern.c_str();
	DWORD firstMatch = 0;
	DWORD rangeStart = ( DWORD )GetModuleHandleA( moduleName.c_str() );
	MODULEINFO miModInfo; GetModuleInformation( GetCurrentProcess(), ( HMODULE )rangeStart, &miModInfo, sizeof( MODULEINFO ) );
	DWORD rangeEnd = rangeStart + miModInfo.SizeOfImage;
	for( DWORD pCur = rangeStart; pCur < rangeEnd; pCur++ )
	{
		if( !*pat )
			return firstMatch;

		if( *( PBYTE )pat == '\?' || *( BYTE* )pCur == getByte( pat ) )
		{
			if( !firstMatch )
				firstMatch = pCur;

			if( !pat[ 2 ] )
				return firstMatch;

			if( *( PWORD )pat == '\?\?' || *( PBYTE )pat != '\?' )
				pat += 3;

			else
				pat += 2;
		}
		else
		{
			pat = pattern.c_str();
			firstMatch = 0;
		}
	}
	return NULL;
}

inline bool U::Compare(const uint8_t* data, const uint8_t* pattern, const char* mask) {
	for (; *mask; ++mask, ++data, ++pattern)
		if (*mask == 'x' && *data != *pattern)
			return false;

	return (*mask) == 0;
}

DWORD_PTR U::FindPattern3(std::string strModuleName, PBYTE pbPattern, std::string strMask, DWORD_PTR nCodeBase, DWORD_PTR nSizeOfCode)
{
	BOOL bPatternDidMatch = FALSE;
	HMODULE hModule = GetModuleHandleA(strModuleName.c_str());

	if (!hModule)
		return 0;

	PIMAGE_DOS_HEADER pDsHeader = PIMAGE_DOS_HEADER(hModule);
	PIMAGE_NT_HEADERS pPeHeader = PIMAGE_NT_HEADERS(LONG(hModule) + pDsHeader->e_lfanew);
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pPeHeader->OptionalHeader;

	if (!nCodeBase)
		nCodeBase = (ULONG)hModule + pOptionalHeader->BaseOfCode;

	if (!nSizeOfCode)
		nSizeOfCode = pOptionalHeader->SizeOfCode;

	std::size_t nMaskSize = strMask.length();

	if (!nCodeBase || !nSizeOfCode || !nMaskSize)
		return 0;

	for (DWORD_PTR i = nCodeBase; i <= nCodeBase + nSizeOfCode; i++)
	{
		for (size_t t = 0; t < nMaskSize; t++)
		{
			if (*((PBYTE)i + t) == pbPattern[t] || strMask.c_str()[t] == '?')
				bPatternDidMatch = TRUE;

			else
			{
				bPatternDidMatch = FALSE;
				break;
			}
		}

		if (bPatternDidMatch)
			return i;
	}

	return 0;
}

uintptr_t U::FindPattern2(const char* module, const char* pattern_string, const char* mask) {
	MODULEINFO module_info = {};
	GetModuleInformation(GetCurrentProcess(), GetModuleHandleA(module), &module_info, sizeof MODULEINFO);

	uintptr_t module_start = uintptr_t(module_info.lpBaseOfDll);

	const uint8_t* pattern = reinterpret_cast<const uint8_t*>(pattern_string);

	for (size_t i = 0; i < module_info.SizeOfImage; i++)
		if (Compare(reinterpret_cast<uint8_t*>(module_start + i), pattern, mask))
			return module_start + i;

	return 0;
}
void U::StdReplaceStr(std::string& replaceIn, const std::string& replace, const std::string& replaceWith)
{
    size_t const span = replace.size();
    size_t const step = replaceWith.size(); 
    size_t index = 0;

    while (true)
    {
        index = replaceIn.find(replace, index);

        if (index == std::string::npos)
            break;

        replaceIn.replace(index, span, replaceWith);
        index += step;
    }
}

CBaseEntity* U::GetLocalPlayer( )
{
	return I::ClientEntList->GetClientEntity( I::Engine->GetLocalPlayer( ) );
}

CNetVarManager* U::NetVars = new CNetVarManager;

wchar_t* U::ConvertCharArrayToLPCWSTR( const char* charArray )
{
	wchar_t* wString = new wchar_t[ 4096 ];
	MultiByteToWideChar( CP_ACP, 0, charArray, -1, wString, 4096 );
	return wString;
}

void U::ClipTraceToPlayers(const Vector& vecAbsStart, const Vector& vecAbsEnd, unsigned int mask, ITraceFilter* filter, trace_t* tr)
{
	if ( !offsets.ClipTraceToPlayersFn )
		return;

	_asm
	{
			MOV		EAX, filter
			LEA		ECX, tr
			PUSH	ECX
			PUSH	EAX
			PUSH	mask
			LEA		EDX, vecAbsEnd
			LEA		ECX, vecAbsStart
			CALL	offsets.ClipTraceToPlayersFn
			ADD		ESP, 0xC
	}
}

void U::TraceLine( const Vector& vecAbsStart, const Vector& vecAbsEnd, unsigned int mask, CBaseEntity* ignore, trace_t* ptr )
{
	Ray_t ray;
	ray.Init( vecAbsStart, vecAbsEnd );
	CTraceFilter filter;
	filter.pSkip = ignore;

	I::EngineTrace->TraceRay( ray, mask, &filter, ptr );
}

void U::ServerRankRevealAll()
{
	static float fArray[ 3 ] = { 0.f, 0.f, 0.f };

	U::ServerRankRevealAllEx = ( ServerRankRevealAllFn )( offsets.ServerRankRevealAllEx );
	U::ServerRankRevealAllEx( fArray );
}

void U::InitKeyValues( KeyValues* pKeyValues, const char* name )
{
	U::InitKeyValuesEx = ( InitKeyValuesFn )( offsets.InitKeyValuesEx );
	U::InitKeyValuesEx( pKeyValues, name );
}

void U::LoadFromBuffer( KeyValues* pKeyValues, const char* resourceName, const char* pBuffer, void* pFileSystem, const char* pPathID, void* pfnEvaluateSymbolProc )
{
	U::LoadFromBufferEx = ( LoadFromBufferFn )( offsets.LoadFromBufferEx );
	U::LoadFromBufferEx( pKeyValues, resourceName, pBuffer, pFileSystem, pPathID, pfnEvaluateSymbolProc );
}

void U::SendPacket( byte toggle )
{
	*( byte* )( offsets.SendPacket ) = toggle;
}

float U::RandomFloat( float min, float max )
{
	assert( max > min );
	float random = ( ( float )rand() ) / ( float )RAND_MAX;
	float range = max - min;
	return ( random*range ) + min;
}

void U::SetupHooks()
{
	H::VPanel = new VTHook( ( DWORD** )I::VPanel );
	H::ClientMode = new VTHook( ( DWORD** )I::ClientMode );
	H::Client = new VTHook( ( DWORD** )I::Client );
	H::ModelRender = new VTHook( ( DWORD** )I::ModelRender );
	H::Surface = new VTHook( ( DWORD** )I::Surface );
	H::GameEvent = new VTHook((DWORD**)I::GameEvent);
	H::D3D9 = new VTHook( ( DWORD** )offsets.d3d9Device );

	oPaintTraverse = ( PaintTraverseFn )H::VPanel->HookFunction( ( DWORD )Hooks::PaintTraverse, 41 );
	oCreateMove = ( CreateMoveFn )H::ClientMode->HookFunction( ( DWORD )Hooks::CreateMove, 24 );
	oFireEventClientSide = (FireEventClientSideFn)H::GameEvent->HookFunction((DWORD)Hooks::hkFireEventClientSide, 9);
	oOverrideView = ( OverrideViewFn )H::ClientMode->HookFunction( ( DWORD )Hooks::OverrideView, 18 );
	oFrameStageNotify = ( FrameStageNotifyFn )H::Client->HookFunction( ( DWORD )Hooks::FrameStageNotify, 36 );
	oDrawModelExecute = ( DrawModelExecuteFn )H::ModelRender->HookFunction( ( DWORD )Hooks::DrawModelExecute, 21 );
	oPlaySound = ( PlaySoundFn )H::Surface->HookFunction( ( DWORD )Hooks::PlaySound_CSGO, 82 );
	oReset = ( ResetFn )H::D3D9->HookFunction( ( DWORD )Hooks::Reset, 16 );
	oEndScene = ( EndSceneFn )H::D3D9->HookFunction( ( DWORD )Hooks::EndScene, 41 );

	U::SendClanTag = (SendClanTagFn)U::FindPattern("engine.dll", "53 56 57 8B DA 8B F9 FF 15"); 
	U::CL_FullUpdate = (CL_FullUpdate_t)U::FindPattern2("engine.dll", "\x56\x8B\x35\x00\x00\x00\x00\x83\xBE\x6C", "xxx????xxx");
}

void U::SetupOffsets()
{
	U::NetVars->Initialize();
	Offsets::GrabOffsets();
}

void U::SetupTextures()
{
	visible_flat = I::MaterialSystem->CreateMaterial( true, false, false );
	visible_tex = I::MaterialSystem->CreateMaterial( false, false, false );
	hidden_flat = I::MaterialSystem->CreateMaterial( true, true, false );
	hidden_tex = I::MaterialSystem->CreateMaterial( false, true, false );
}

void U::Setup()
{
	U::SetupInterfaces();

	U::SetupOffsets();

	D::SetupFonts();

	U::SetupTextures();

	U::SetupHooks();

	Config->Load();

	if (lstrcmpA(I::Engine->GetProductVersionString(), CSGO_VERSION) != 0)
		E::Misc->Panic();
}

long U::GetEpochTime()
{
	auto duration = std::chrono::system_clock::now().time_since_epoch();

	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

ImColor U::GetRainbowColor(float speed)
{
	speed = 0.002f * speed;
	long now = U::GetEpochTime();
	float hue = (now % (int)(1.0f / speed)) * speed;

	return ImColor::HSV(hue, 1.0f, 1.0f);
}

Color U::GetHealthColor(int hp)
{
	return Color(
		min(510 * (100 - hp) / 100, 255),
		min(510 * hp / 100, 255),
		25
	);
}

Color U::GetHealthColor(CBaseEntity* player)
{
	return Color(
		min(510 * (100 - player->GetHealth()) / 100, 255),
		min(510 * player->GetHealth() / 100, 255),
		25
	);
}
