// cl: /MD /D_STLP_USE_STATIC_LIB
// platformsdk
// stlport

#include <windows.h>
#include <stdlib.h>

typedef struct Rva0084DD20Locale
{
    unsigned long lcid;
} Rva0084DD20Locale;

#define BFME_LOCALE_SIGN(ADDR, FLAG)                                     \
int Rva##ADDR##Sign(Rva0084DD20Locale *locale)                           \
{                                                                       \
    char text[2];                                                       \
    GetLocaleInfoA(locale->lcid, FLAG, text, 2);                        \
    return atoi(text);                                                  \
}

BFME_LOCALE_SIGN(0084DD20, 0x52)
BFME_LOCALE_SIGN(0084DDD0, 0x53)
