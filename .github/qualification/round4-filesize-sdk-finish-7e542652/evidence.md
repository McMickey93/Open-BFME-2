# FileSizeHelper: use the actual Windows SDK, 2026-10-28

Selected by `tools/ms_header_audit.py next --class drop-in-candidate`: `Code/stlport/FileSizeHelper.cpp`, two local API declarations (`GetFileSize`, `GetLastError`). The whole file owns one already matched 50-byte body at RVA 0x0001D240.

Replace the API declarations and private LARGE_INTEGER stand-in with `<windows.h>` and SDK `LARGE_INTEGER`, using the supported `// platformsdk` marker. Keep /MD, the low/high size query, last-error condition and truncated long result. Configure the SDK with WIN32_LEAN_AND_MEAN and remove this TU's unused `// stlport` include profile: the helper uses no STLport declaration.

The earlier unrestricted include trial (Windows run 40682600083) verifies the original and modified 50-byte body and both imports, but its COFF `.drectve` adds stlport_vc7.lib and two uuid.lib directives. It is not the landed source. The final variant must preserve all runtime sections, relocation targets, external symbols and linker directives before the scoped queue row can be retired.

No new C++ bytes, measured link gain or full-game link clearance is claimed.

The preceding fully qualified source commit 6661d06b798979bd317a9e36f67dcfdd95a47421 passed all required native hooks and its normal fork push. Its publication retry stopped when upstream refreshed the canonical BFME 1 reference. The continuation reviews the new published paired-reference receipts and rechecks the same SDK cleanup; it claims no additional reference or byte progress.

The same source was subsequently qualified and normally pushed as f9c8dadf1620fc12fdf0bc7059ba2c07f950c07e in Windows run 40718695340. A later normal rebase stopped on a queue-only conflict after upstream retired neighbouring Microsoft-header rows. The continuation permits only that exact conflict: it takes upstream's queue, asks ms_header_audit.refresh_queue to retire this file's row, asserts all unrelated rows are byte-for-byte preserved, and continues the normal Git rebase. Any source, reference or AGENTS conflict still stops for review.

Correction to the prior extra diagnostics: their exit code 2 came from unsupported BFME-1 CLI options accidentally passed to BFME-2 link_check.py. They were command-line usage failures and do not establish a link-preview result. The native body, import, runtime COFF comparisons and unmodified hooks were independently valid. This continuation uses the supported BFME-2 preview command and prepares current-provider receipts with --prepare-current. It does not change any verifier, authority, census definition or admission baseline.
