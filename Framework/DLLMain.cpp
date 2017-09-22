#include "Cheat.h"

#include <wininet.h>
#include <cstring>
#include <windows.h>
#include <iostream>
#include <urlmon.h>
#include <ctype.h>

#pragma comment(lib,"wininet.lib")
#pragma comment(lib, "urlmon.lib")

DWORD dwInitAddress;

void CheatThread()
{
	U::Setup();
		if (lstrcmpA(I::Engine->GetProductVersionString(), CSGO_VERSION) != 0)
		 E::Misc->Panic();
}

void main()
{

}

void debagl()
{
	AllocConsole();
	freopen("CONOUT$", "wb", stdout);
	freopen("CONOUT$", "wb", stderr);
	freopen("CONIN$", "rb", stdin);
	SetConsoleTitle("medPIDOR");	
}

DWORD WINAPI DllMain( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	debagl();

	switch( dwReason )
	{
	case DLL_PROCESS_ATTACH:
	{

		while( !( G::Window = FindWindowA( charenc( "Valve001" ), NULL ) ) ) Sleep( 200 );

		Hooks::oldWindowProc = ( WNDPROC )SetWindowLongPtr( G::Window, GWL_WNDPROC, ( LONG_PTR )Hooks::WndProc );

		CreateThread( NULL, NULL, ( LPTHREAD_START_ROUTINE )CheatThread, NULL, NULL, NULL );

		G::Dll = hDll;

		return TRUE;
	}
	case DLL_PROCESS_DETACH:
	{
		ExitProcess(0);
		return TRUE;
	}

	return FALSE;
	}
}