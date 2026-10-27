/* cl: /DNDEBUG /MD */

/* Retail 0x008872B0 -- wchar skipWhitespace, sibling of
 * ?skipWhitespace@@YAPADPAD@Z at 0x00887260.
 *
 * File-static so MSVC uses its private EAX-incoming convention. Calling
 * through the genuine msvcr71 import pointer __imp__iswspace as a plain
 * extern function pointer (not a dllimport prototype) keeps the call as
 * `call dword ptr [__imp__iswspace]` -- the C++ / dllimport form hoists the
 * IAT into EDI and misses retail's aligned-loop shape. A defined global
 * named iswspace would clash with the real _iswspace (the CRT's, and the
 * msvcr71 thunk Msvcr71ImportThunks.cpp defines). */

extern int (__cdecl *_imp__iswspace)(unsigned short);

static unsigned short *skipWhitespace(unsigned short *p)
{
	while (*p && _imp__iswspace(*p))
		++p;
	return p;
}

/* Visible call site so the static keeps the EAX convention. Not claimed. */
unsigned short *skipWhitespace_keep(unsigned short *p)
{
	return skipWhitespace(p);
}
