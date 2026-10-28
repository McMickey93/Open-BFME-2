# FileSizeHelper: use the actual Windows SDK, 2026-10-28

Selected by `tools/ms_header_audit.py next --class drop-in-candidate`: `Code/stlport/FileSizeHelper.cpp`, two local API declarations (`GetFileSize`, `GetLastError`). The whole file owns one already matched 50-byte body at RVA 0x0001D240.

Replace the API declarations and private LARGE_INTEGER stand-in with `<windows.h>` and SDK `LARGE_INTEGER`, using the supported `// platformsdk` marker. Keep /MD, the low/high size query, last-error condition and truncated long result. Configure the SDK with WIN32_LEAN_AND_MEAN and remove this TU's unused `// stlport` include profile: the helper uses no STLport declaration.

The earlier unrestricted include trial (Windows run 40682600083) verifies the original and modified 50-byte body and both imports, but its COFF `.drectve` adds stlport_vc7.lib and two uuid.lib directives. It is not the landed source. The final variant must preserve all runtime sections, relocation targets, external symbols and linker directives before the scoped queue row can be retired.

No new C++ bytes, measured link gain or full-game link clearance is claimed.

The preceding fully qualified source commit 6661d06b798979bd317a9e36f67dcfdd95a47421 passed all required native hooks and its normal fork push. Its publication retry stopped when upstream refreshed the canonical BFME 1 reference. The continuation reviews the new published paired-reference receipts and rechecks the same SDK cleanup; it claims no additional reference or byte progress.
