#include "interfaces.hpp"

#include "memory/memory.hpp"

void CSignature::Find( ) {
	m_Address = M::Pattern.Find( m_Module, m_Pattern );

	m_Address += m_Offset;
}

namespace S {
	MAKE_SIGNATURE( D3DDevice, "shaderapidx9.dll", "75 22 A1", 0x3 );
}

void C_Interfaces::Init( ) {
	I::D3DDevice = **S::D3DDevice.As<IDirect3DDevice9***>( );
}