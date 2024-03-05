#include "renderer.hpp"

void C_Render::OncePresent( ) {
	if ( HasInit ) {
		return;
	}
	hr = D3DXCreateFontA(
		Device_t,
		24, 0,
		FW_DONTCARE,
		0, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		NONANTIALIASED_QUALITY,
		DEFAULT_PITCH,
		"Fixedsys",
		&Font_1
	);
	D3DXCreateFontA(
		Device_t,
		22, 0,
		FW_NORMAL,
		0, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		NONANTIALIASED_QUALITY,
		DEFAULT_PITCH,
		"Calibri",
		&Font_2
	);
	D3DXCreateFontA(
		Device_t,
		24, 0,
		FW_DONTCARE,
		0, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		DEFAULT_PITCH,
		"Segoe UI",
		&Font_3
	);
	HasInit = true;
}

void C_Render::OnReset( ) {
	g_Draw->Font_1->Release( );
	g_Draw->Font_2->Release( );
	g_Draw->Font_3->Release( );
	g_Draw->Font_1 = nullptr;
	g_Draw->Font_2 = nullptr;
	g_Draw->Font_3 = nullptr;
	HasInit = false;
}

void C_Render::OnPresent( ) {
	g_Draw->String( 20, 15, D3DCOLOR_RGBA( 255, 255, 255, 255 ), g_Draw->Font_1, true, R"(Hello from DirectX!)" );
	g_Draw->String( 20, 45, D3DCOLOR_RGBA( 255, 255, 255, 255 ), g_Draw->Font_2, true, R"(Here is text in a different font!)" );
	g_Draw->String( 20, 75, D3DCOLOR_RGBA( 255, 255, 255, 255 ), g_Draw->Font_3, false, R"(And here's an anti-aliased font!)" );
}

void C_Render::String( int x, int y, D3DCOLOR pColor, ID3DXFont* pFont, bool outlined, char* input, ... ) {
	if ( SUCCEEDED( hr ) ) {
		va_list args = nullptr;
		char pBuffer[ 256 ];

		va_start( args, input );
		wsprintf( pBuffer, input, args );
		va_end( args );

		RECT size = { 0, 0, 0, 0 };
		if ( outlined ) {
			size.left = x - 1;
			size.top = y;
			pFont->DrawTextA( NULL, pBuffer, strlen( pBuffer ), &size, DT_NOCLIP, D3DCOLOR_RGBA( 0, 0, 0, 255 ) );
			size.left = x + 1;
			size.top = y;
			pFont->DrawTextA( NULL, pBuffer, strlen( pBuffer ), &size, DT_NOCLIP, D3DCOLOR_RGBA( 0, 0, 0, 255 ) );
			size.left = x;
			size.top = y - 1;
			pFont->DrawTextA( NULL, pBuffer, strlen( pBuffer ), &size, DT_NOCLIP, D3DCOLOR_RGBA( 0, 0, 0, 255 ) );
			size.left = x;
			size.top = y + 1;
			pFont->DrawTextA( NULL, pBuffer, strlen( pBuffer ), &size, DT_NOCLIP, D3DCOLOR_RGBA( 0, 0, 0, 255 ) );
		}
		size.left = x;
		size.top = y;
		pFont->DrawTextA( NULL, pBuffer, strlen( pBuffer ), &size, DT_NOCLIP, pColor );
	}
}