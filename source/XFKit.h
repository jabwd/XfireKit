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
#define DEBUG_LOGGING 0
#define XFIRE_PORT 25999
#define XFIRE_HOST "cs.xfire.com"

using namespace std;
 
/*
 * Our personal types
 */
typedef unsigned char 	uint8;
typedef char 						int8;

typedef unsigned short 	uint16;
typedef short						int16;
 
typedef unsigned int 		uint32;
typedef int							int32;

typedef unsigned long   uint64;
typedef long						int64;
 
/*
 * printf() but then disabled when debug logging is turned off
 */
void xfPrintf(const char *format,...);

/*
 * Bit shifting for creating network useable IP's,
 * or creating human readable ip from an network ip
 */
uint32 ipFromString(const char *ip);
const char *stringFromIP(uint32 ip);

/*
 * Byte swapping
 */
uint16 endianSwap(uint16 x);
uint32 endianSwap(uint32 x);
uint64 endianSwap(uint64 x);