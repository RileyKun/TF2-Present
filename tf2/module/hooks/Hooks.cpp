#include "Hooks.hpp"

// #include <memory>
#include "../tools/memory/memory.hpp"

void Hooks::Init( ) {

	MH_Initialize( );

	MH_CreateHook(
		M::VFunc.VFunc( g_Draw->Device_t, 17 ),
		&Hooked_Present,
		reinterpret_cast<void**>(&Original_Present)
	);

	MH_CreateHook(
		M::VFunc.VFunc( g_Draw->Device_t, 16 ),
		&Hooked_Reset,
		reinterpret_cast<void**>(&Original_Reset)
	);

	MH_EnableHook( MH_ALL_HOOKS );
}

void Hooks::Release( ) {
	MH_DisableHook( MH_ALL_HOOKS );
	MH_RemoveHook( MH_ALL_HOOKS );
	MH_Uninitialize( );
	return;
}

HRESULT __stdcall Hooks::Hooked_Present( IDirect3DDevice9* device, RECT* source, const RECT* destination, HWND window_override, const RGNDATA* dirty ) {
	g_Draw->OncePresent( );
	g_Draw->OnPresent( );
	return Original_Present( device, source, destination, window_override, dirty );
}

HRESULT __stdcall Hooks::Hooked_Reset( IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* params ) {
	g_Draw->OnReset( );
	const auto result = Original_Reset( device, params );
	return result;
}
