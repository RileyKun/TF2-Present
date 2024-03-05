#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class C_Render {
public:
	void OncePresent( );
	void OnReset( );
	void OnPresent( );


	void String( int x, int y, D3DCOLOR pColor, ID3DXFont* pFont, bool outlined, char* input, ... );

	IDirect3DDevice9* Device_t = nullptr;
	ID3DXFont* Font_1 = nullptr;
	ID3DXFont* Font_2 = nullptr;
	ID3DXFont* Font_3 = nullptr;
	HRESULT hr = 0;

	bool HasInit = false;
};

inline C_Render* g_Draw = new C_Render;