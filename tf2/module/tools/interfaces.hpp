#pragma once

#include <Windows.h>

#include <d3d9.h>

class CSignature {
	DWORD m_Address = 0;
	LPCSTR m_Module = nullptr;
	LPCSTR m_Pattern = nullptr;
	int m_Offset = 0;

	void Find( );

public:
	CSignature( LPCSTR szModule, LPCSTR szPattern, int offset = 0 )
		: m_Module( szModule ), m_Pattern( szPattern ), m_Offset( offset ) {
	}

	// Return the address
	DWORD operator()( ) {
		if ( m_Address == 0 ) { Find( ); }
		return m_Address;
	}

	template <typename T> T As( ) { return reinterpret_cast<T>(this->operator()( )); }
};

namespace I {
	inline IDirect3DDevice9* D3DDevice = nullptr;
}

class C_Interfaces {
public:
	void Init( );
};
inline C_Interfaces g_Interfaces { };

#define MAKE_SIGNATURE(name, module, pattern, offset) inline CSignature name{ module, pattern, offset }