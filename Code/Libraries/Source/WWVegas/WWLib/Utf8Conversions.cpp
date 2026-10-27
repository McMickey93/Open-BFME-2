// cl: /DNDEBUG /MD
// platformsdk
// Win32 conversion-wrapper family used by BFME1 UnicodeString/GameSpy code.
// BFME2 retail uses CP_UTF8 (65001), not the system ANSI code page.
// Descriptive function names; ABI and complete bodies independently audited
// from exported String translate callers plus named PE imports.
#include <windows.h>

typedef unsigned short Wide;
int BFME2Utf8ToWide(const char* source,int count,Wide* output,int capacity) {
    return MultiByteToWideChar(65001,0,source,count,output,capacity);
}
int BFME2WideToUtf8(const Wide* source,int count,char* output,int capacity) {
    return WideCharToMultiByte(65001,0,source,count,output,capacity,0,0);
}
int multiByteToWideChar(const char* source,int count,Wide* output,int capacity) {
    return MultiByteToWideChar(0,0,source,count,output,capacity);
}
int wideCharToMultiByte(const Wide* source,int count,char* output,int capacity) {
    return WideCharToMultiByte(0,0,source,count,output,capacity,0,0);
}
