# FileSizeHelper: use the actual Windows SDK, 2026-10-28

Selected by `tools/ms_header_audit.py next --class drop-in-candidate`: `Code/stlport/FileSizeHelper.cpp`, two local API declarations (`GetFileSize`, `GetLastError`). The complete file owns one already matched 50-byte body, RVA 0x0001D240.

Replace those declarations and the private LARGE_INTEGER layout copy with `<windows.h>` and SDK `LARGE_INTEGER`, opting this TU into the vendored Platform SDK with the supported `// platformsdk` marker. Keep /MD, STLport selection, the low/high size query, last-error condition and truncated long result unchanged. No new function or layout assertion helper is introduced.

Native qualification is required before the scoped audit queue row can be retired. No new C++ bytes, measured link gain or full-game gate clearance is claimed.
