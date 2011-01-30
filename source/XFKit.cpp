#include "XFKit.h"

 /*
  * printf() but then disabled when debug logging is turned off
  */
void xfPrintf(const char *format,...)
{
	#if DEBUG_LOGGING
	fprintf(stderr, "  XfireKit: ");
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	fprintf(stderr, "\n");
	fflush(stderr);
	#endif
} // xfPrintf();