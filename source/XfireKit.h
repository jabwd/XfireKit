/*
 * XfireKit, awesome opensource xfire library
 * Version: a0.1
 * Copyright Oliver Ney & Antwan van Houdt 2010-2011,
 * All rights reserved
 */

#ifndef XK_HEADER_XFIRE_KIT
#define XK_HEADER_XFIRE_KIT

#ifdef _WIN32
#	ifdef XK_BUILDING
#		define XK_EXPORT __declspec(dllexport)
#	else
#		define XK_EXPORT __declspec(dllimport)
#	endif
#else
#	if __GNUC__ >= 4
#		define XK_EXPORT __attribute__((visibility("default")))
#	else
#		define XK_EXPORT
#	endif
#endif // _WIN32

// if turned to 1 XfireKit will log much more data for debugging purposes
// to the console
#ifndef XK_DEBUG_LOGGING
#	define XK_DEBUG_LOGGING	0
#endif // !XK_DEBUG_LOGGING

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
	 * printf() but then disabled when debug logging is turned off
	 */
#if XK_DEBUG_LOGGING
#	define XFError(msg, args)	fprintf(stderr, "XfireKit (Error): " msg, args)
#	define XFWarning(msg, args)	fprintf(stderr, "XfireKit (Warning): " msg, args)
#	define XFDebug(msg, args)	fprintf(stderr, "XfireKit (Debug): " msg, args)
#	define XFInfo(msg, args)	fprintf(stderr, "XfireKit: " msg, args)
#else
#	define XFError(msg, args)	do {} while(0)
#	define XFWarning(msg, args)	do {} while(0)
#	define XFDebug(msg, args)	do {} while(0)
#	define XFInfo(msg, args)	do {} while(0)
#endif // XK_DEBUG_LOGGING

	/*
	 * Bit shifting for creating network useable IP's,
	 * or creating human readable ip from an network ip
	 */
	XK_EXPORT uint32 ipFromString(const char *ip);
	XK_EXPORT const char *stringFromIP(uint32 ip);

	/*
	 * Byte swapping
	 */
	XK_EXPORT uint16 endianSwap(uint16 p_x);
	XK_EXPORT uint32 endianSwap(uint32 p_x);
	XK_EXPORT uint64 endianSwap(uint64 p_x);
}

#endif // XK_HEADER_XFIRE_KIT
