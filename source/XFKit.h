/*
 * XfireKit, awesome opensource xfire library
 * Version: a0.1
 * Copyright Oliver Ney & Antwan van Houdt 2010-2011,
 * All rights reserved
 */
 
#include <iostream>
#include <string>
using namespace std;
 
#define DEBUG_LOGGING 0
 
typedef char 						XFInteger8;
typedef unsigned char 	XFUInteger8;

typedef unsigned short 	XFUInteger16;
typedef short						XFInteger16;
 
typedef unsigned int 		XFUInteger32;
typedef int							XFInteger32;
 
/*
 * printf() but then disabled when debug logging is turned off
 */
void xfPrintf(const char *format,...);