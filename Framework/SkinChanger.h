#pragma once

#include "SDK.h"
#include "../Framework/Settings/Util.h"
//#include "../settings.h"

//extern ForceFullUpdateFn ForceFullUpdate;
//extern GetClientStateFn GetClientState;

namespace SkinChanger
{
	extern bool ForceFullUpdate;

	void FrameStageNotify(ClientFrameStage_t stage);
};

extern RecvVarProxyFn fnSequenceProxyFn;