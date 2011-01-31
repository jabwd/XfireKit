#include "XfireKit.h"

namespace XfireKit
{
	uint32 ipFromString(const char *ip)
	{
		return 0; // TBD
	}

	const char *stringFromIP(uint32 ip)
	{
		return NULL;
	}


	/*
	 * Byte swapping, it swaps Little to Big and Big to little
	 */
	uint16 endianSwap(uint16 x)
	{
		return (x>>8)|(x<<8);
	}

	uint32 endianSwap(uint32 x)
	{
		return (x>>24)|((x<<8) & 0x00FF0000)|((x>>8) & 0x0000FF00)|(x<<24);
	}

	uint64 endianSwap(uint64 x)
	{
		return	(x>>56)	|
				((x<<40) & 0x00FF000000000000)	|
				((x<<24) & 0x0000FF0000000000)	|
				((x<<8)  & 0x000000FF00000000)	|
				((x>>8)  & 0x00000000FF000000)	|
				((x>>24) & 0x0000000000FF0000)	|
				((x>>40) & 0x000000000000FF00)	|
				(x<<56);
	}
	// byte swapping
}
