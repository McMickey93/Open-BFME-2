// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// platformsdk
//
// ?isFileNewer@@YA_NABVAsciiString@@PBU_SYSTEMTIME@@@Z @ 0x0002C025 (155B)
// Free file-time check: empty name false; else _stat path and localtime of st_mtime,
// compare tm (year+1900 mon+1 mday hour min sec) against SYSTEMTIME words.
// Evidence: isEmpty row 0x1E2F; _stat/localtime IAT; g_Rva0107301CEmptyString for empty;
// 0x76c=1900; caller 0x2D327 in 0x2D2C1 prepFile. Prev INILineAccessors // cl: reused.

#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include "ascii_string.h"

bool isFileNewer(const AsciiString &filename, const SYSTEMTIME *st)
{
	if (filename.isEmpty())
		return false;
	else
	{
		const char *path = filename.str();
		struct _stat buf;
		_stat(path, &buf);
		struct tm *t = localtime(&buf.st_mtime);
		if (st->wYear < t->tm_year + 0x76C)
			return true;
		if (st->wYear > t->tm_year + 0x76C)
			return false;
		int mon = t->tm_mon + 1;
		if (st->wMonth < mon)
			return true;
		if (st->wMonth > mon)
			return false;
		// Retail reads the day from +4 (wDayOfWeek) rather than +6 (wDay); follow retail.
		if (st->wDayOfWeek < t->tm_mday)
			return true;
		if (st->wDayOfWeek > t->tm_mday)
			return false;
		if (st->wHour < t->tm_hour)
			return true;
		if (st->wHour > t->tm_hour)
			return false;
		if (st->wMinute < t->tm_min)
			return true;
		if (st->wMinute > t->tm_min)
			return false;
		unsigned char isNewer = (st->wSecond <= t->tm_sec);
		return isNewer;
	}
}
