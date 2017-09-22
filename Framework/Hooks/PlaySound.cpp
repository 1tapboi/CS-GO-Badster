#include "../Cheat.h"

PlaySoundFn oPlaySound;
void __stdcall Hooks::PlaySound_CSGO( const char* fileName )
{
	oPlaySound( fileName );

	if (!Vars.Misc.AutoAccept || I::Engine->IsInGame()) return;

	if (!strcmp(fileName, "weapons/hegrenade/beep.wav")) {

		U::IsReady = (IsReadyFn)((DWORD)U::FindPattern(charenc("client.dll"), charenc("55 8B EC 83 E4 F8 83 EC 08 56 8B 35 ?? ?? ?? ?? 57 8B 8E")));
		U::IsReady();

		FLASHWINFO fi;
		fi.cbSize = sizeof(FLASHWINFO);
		fi.hwnd = G::Window;
		fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
		fi.uCount = 0;
		fi.dwTimeout = 0;
		FlashWindowEx(&fi);
	}
}