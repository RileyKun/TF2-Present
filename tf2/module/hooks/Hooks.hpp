#pragma once

#include "../tools/libs/minhook/MinHook.h"
#include "../tools/renderer/renderer.hpp"

namespace Hooks {
	void Init( );
	void Release( );

	HRESULT __stdcall Hooked_Present( IDirect3DDevice9* device, RECT* source, const RECT* destination, HWND window_override, const RGNDATA* dirty );
	inline decltype(&Hooked_Present) Original_Present = nullptr;

	HRESULT __stdcall Hooked_Reset( IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* params );
	inline decltype(&Hooked_Reset) Original_Reset = nullptr;
}