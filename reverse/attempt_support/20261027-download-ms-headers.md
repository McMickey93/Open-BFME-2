# WWDownload Microsoft-header cleanup (2026-10-27)

Scope: Code/Libraries/Source/WWVegas/WWDownload/Download.cpp, selected by
`python tools/next_work.py --tier ms-headers`. One complete translation unit;
no function reconstruction, row changes, pin additions, or shared-header edits.

## Source and header evidence

The local declarations of S_OK, E_FAIL, timeGetTime, MulDiv, LPCSTR,
HRESULT, _mkdir, strncpy, and global operator delete duplicate Microsoft
SDK/CRT interfaces. Replace them with windows.h, mmsystem.h, direct.h,
and new; retain the existing string.h and sys/stat.h includes.

Keep the existing /DNDEBUG /MD /EHs-c- /Ob2 flags. The builder's existing
`// platformsdk` opt-in selects the original VC7.1 Platform SDK.
Without that opt-in, the builder's sweep retry selected its minimal
direct.h and emitted a direct _mkdir call rather than retail's DLL import.
That intermediate version was rejected (8/9 matched); it is not the banked
source. With the normal opt-in, the dependency manifest selects the
original SDK windows.h and mmsystem.h, VC7.1 direct.h, new, string.h and
sys/stat.h, with no reference/shims/sweep dependency.

The verified upstream reference remains
e74410b3738a2bb75d626085d9ebfd3406a43ff7. No reference gitlink is changed.
No donor implementation, class layout, or new function identity is inferred.

## Verification

Native Windows VC7.1 compiler through unmodified tools/build.py:

```
python tools/build.py Code/Libraries/Source/WWVegas/WWDownload/Download.cpp Code/Libraries/Source/WWVegas/WWLib/mem_ops.cpp
```

Before and after: 9/9 functions matched across two translation units;
2 data rows, 7 named imports, and 2 string literals verified.
This includes Download.cpp's five matched bodies and the four existing
allocation/deallocation providers in mem_ops.cpp. The _mkdir DLL import
and global operator delete binding remain byte-exact.

`tools/ms_header_audit.py show` reports Download.cpp clean;
`tools/ms_header_audit.py check` exits 0.
`tools/find_declared_unmatched.py` exits 0. Its existing absent-from-retail
inline retention anchor is unchanged, as are the provider's admitted markers.
The normal commit and official pre-push hooks are required for publication;
their logs accompany the native qualification run.

This removes nine local interface copies; it does not retire nine registered
debt keys. No debt register is edited. New C++ exact bytes: +0.
No census linking gain or runtime smoke result is claimed.

Agent-Authored: OpenAI Codex
