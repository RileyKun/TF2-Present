#pragma once

#include <Windows.h>

class CPattern {
public:
	DWORD FindPattern( DWORD address, DWORD length, LPCSTR pattern );
	DWORD Find( LPCSTR module, LPCSTR pattern );
};

class CVFunc {
public:
	constexpr void* VFunc( void* thisptr, size_t index ) noexcept {
		return (*static_cast<void***>(thisptr))[ index ];
	}
};

namespace M {
	inline CPattern Pattern { };
	inline CVFunc VFunc { };
}