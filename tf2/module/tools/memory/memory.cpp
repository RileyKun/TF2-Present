#include "memory.hpp"

#define IN_RANGE(x,a,b) (x >= a && x <= b)
#define GET_BITS(x) (IN_RANGE((x & (~0x20)),'A','F') ? ((x & (~0x20)) - 'A' + 0xA) : (IN_RANGE(x,'0','9') ? x - '0' : 0))
#define GET_BYTES(x) (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))

DWORD CPattern::FindPattern( DWORD address, DWORD length, LPCSTR pattern ) {
	auto pPattern = pattern;
	DWORD first_match = 0x0;
	const DWORD end = address + length - strlen( pattern );

	for ( auto current = address; current < end; current++ ) {
		if ( !pPattern ) {
			return first_match;
		}
		const auto cur_byte = *reinterpret_cast<const BYTE*>(current);
		const auto pattern_byte = *reinterpret_cast<const BYTE*>(pPattern);

		if ( pattern_byte == '\?' || cur_byte == GET_BYTES( pPattern ) ) {
			if ( !first_match ) {
				first_match = current;
			}
			if ( !pPattern[ 2 ] ) {
				return first_match;
			}

			pPattern += (pattern_byte == '\?\?' || pattern_byte != '\?') ? 3 : 2;
		}
		else {
			pPattern = pattern;
			first_match = 0x0;
		}
	}
	return 0x0;
}

DWORD CPattern::Find( LPCSTR module, LPCSTR pattern ) {
	const auto handle = reinterpret_cast<DWORD>(GetModuleHandleA( module ));
	if ( !handle ) {
		return 0x0;
	}
	const auto* nt_header = reinterpret_cast<IMAGE_NT_HEADERS*>(handle + reinterpret_cast<IMAGE_DOS_HEADER*>(handle)->e_lfanew);
	const auto o_header = &nt_header->OptionalHeader;
	
	return FindPattern( handle + o_header->BaseOfCode, o_header->SizeOfCode, pattern );
}
