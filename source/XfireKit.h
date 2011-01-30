/*
 * XfireKit, awesome opensource xfire library
 * Version: a0.1
 * Copyright Oliver Ney & Antwan van Houdt 2010-2011,
 * All rights reserved
 */
 
#include <iostream>
#include <string>
 
// if turned to 1 XfireKit will log much more data for debugging purposes
// to the console
#define DEBUG_LOGGING	0
#define XFIRE_PORT		25999
#define XFIRE_HOST		"cs.xfire.com"

namespace XfireKit
{
 
	/*
	 * Our personal types
	 */
	typedef unsigned char	uint8;
	typedef char 			int8;
	typedef unsigned short	uint16;
	typedef short			int16;
	typedef unsigned int	uint32;
	typedef int				int32;
	typedef unsigned long	uint64;
	typedef long			int64;
	
	/*
	 * Bit shifting for creating network useable IP's,
	 * or creating human readable ip from an network ip
	 */
	uint32		ipFromString(const char *p_ip);
	const char	*stringFromIP(uint32 p_ip);
	
	/*
	 * Byte swapping
	 */
	uint16 endianSwap(uint16 p_x);
	uint32 endianSwap(uint32 p_x);
	uint64 endianSwap(uint64 p_x);

}
