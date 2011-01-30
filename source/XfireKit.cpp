#include "XfireKit.h"

XfireKit::uint32 ipFromString(const char *p_ip)
{
	return 0; // TBD
}

const char *stringFromIP(XfireKit::uint32 p_ip)
{
	return NULL;
}


/*
 * Byte swapping, it swaps Little to Big and Big to little
 */
XfireKit::uint16 endianSwap(XfireKit::uint16 p_x)
{
	return (p_x>>8)|(p_x<<8);
}

XfireKit::uint32 endianSwap(XfireKit::uint32 p_x)
{
	return (p_x>>24)|((p_x<<8) & 0x00FF0000)|((p_x>>8) & 0x0000FF00)|(p_x<<24);
}

XfireKit::uint64 endianSwap(XfireKit::uint64 p_x)
{
	return	(p_x>>56)									| 
					((p_x<<40) & 0x00FF000000000000)	|
					((p_x<<24) & 0x0000FF0000000000)	|
					((p_x<<8)  & 0x000000FF00000000)	|
					((p_x>>8)  & 0x00000000FF000000)	|
					((p_x>>24) & 0x0000000000FF0000)	|
					((p_x>>40) & 0x000000000000FF00)	|
					(p_x<<56);
}
// byte swapping
