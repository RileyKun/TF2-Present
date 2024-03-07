#include "module/core.hpp"

DWORD WINAPI EntryPoint( LPVOID reserved ) {

	while ( !GetModuleHandleA( "mss32.dll" ) )
		Sleep( 50 );

	g_Core.Load( );

	while ( !GetAsyncKeyState( VK_F6 ) )
		Sleep( 50 );

	g_Core.Unload( );

	FreeLibraryAndExitThread( static_cast<HMODULE>(reserved), 0 );
}

INT WINAPI DllMain( HMODULE instance, DWORD reason, LPVOID reserved ) {
	if ( reason == DLL_PROCESS_ATTACH ) {
		//DisableThreadLibraryCalls( instance );

		if ( auto thread = CreateThread( 0, 0, EntryPoint, reserved, 0, 0 ) ) {
			CloseHandle( thread );
		}
	}
	return 1;
}
