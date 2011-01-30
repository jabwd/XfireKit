/*
 * XfireKit, awesome opensource xfire library
 * Version: a0.1
 * Copyright Oliver Ney & Antwan van Houdt 2010-2011,
 * All rights reserved
 */
 
#include <iostream>
#include <string>
 
#define DEBUG_LOGGING 0
#define XFIRE_PORT 25999
#define XFIRE_HOST "cs.xfire.com"

using namespace std;
 
typedef char 						XFInteger8;
typedef unsigned char 	XFUInteger8;

typedef unsigned short 	XFUInteger16;
typedef short						XFInteger16;
 
typedef unsigned int 		XFUInteger32;
typedef int							XFInteger32;

typedef unsigned long   XFUInteger64;
typedef long						XFInteger64;
 
/*
 * printf() but then disabled when debug logging is turned off
 */
void xfPrintf(const char *format,...);

/*
 * Byte swapping
 */
XFUInteger16 endianSwap(XFUInteger16 x);
XFUInteger32 endianSwap(XFUInteger32 x);
XFUInteger64 endianSwap(XFUInteger64 x);