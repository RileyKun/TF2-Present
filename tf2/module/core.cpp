#include "core.hpp"
#include "tools/interfaces.hpp"
#include "hooks/Hooks.hpp"

void C_Core::Load( ) {
	g_Interfaces.Init( );

	g_Draw->Device_t = I::D3DDevice;

	Hooks::Init( );
}

void C_Core::Unload( ) {
	Hooks::Release( );

	g_Draw->OnReset( );
	g_Draw->Device_t = nullptr;

	return;
}
