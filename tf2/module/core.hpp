#pragma once

#include <Windows.h>

class C_Core {
public:
	void Load( );
	void Unload( );
};

inline C_Core g_Core { };