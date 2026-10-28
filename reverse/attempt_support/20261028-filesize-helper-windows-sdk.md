# FileSizeHelper: use the actual Windows SDK, 2026-10-28

Selected by `tools/ms_header_audit.py next --class drop-in-candidate`: `Code/stlport/FileSizeHelper.cpp`, two local API declarations (`GetFileSize`, `GetLastError`). The whole file owns one already matched 50-byte body at RVA 0x0001D240.

Replace the API declarations and private LARGE_INTEGER stand-in with `<windows.h>` and SDK `LARGE_INTEGER`, using the supported `// platformsdk` marker. Keep /MD, the low/high size query, last-error condition and truncated long result. Configure the SDK with WIN32_LEAN_AND_MEAN and remove this TU's unused `// stlport` include profile: the helper uses no STLport declaration.

The earlier unrestricted include trial (Windows run 40682600083) verifies the original and modified 50-byte body and both imports, but its COFF `.drectve` adds stlport_vc7.lib and two uuid.lib directives. It is not the landed source. The final variant must preserve all runtime sections, relocation targets, external symbols and linker directives before the scoped queue row can be retired.

No new C++ bytes, measured link gain or full-game link clearance is claimed.

The preceding fully qualified source commit 6661d06b798979bd317a9e36f67dcfdd95a47421 passed all required native hooks and its normal fork push. Its publication retry stopped when upstream refreshed the canonical BFME 1 reference. The continuation reviews the new published paired-reference receipts and rechecks the same SDK cleanup; it claims no additional reference or byte progress.

## Native qualification receipts

Original and updated source each verify the existing 50-byte body at RVA 0x0001D240 with the unmodified original-compiler driver.
Runtime COFF sections, relocation targets, external definitions and undefined symbols are identical. EH verification passes.
The normal compiler dependency receipt records the vendored Vc7/PlatformSDK/Include/windows.h.
The owning Microsoft-header audit classifies the updated file as clean; its scoped refresh removes only this file's two-definition queue row.
Canonical inputs: 0424131c818fba6641613ef826222ecf30845025. Fetched official BFME 1 master: 0bc92206d6e52c296b44aded69d3e94e44a43e2f.
The canonical pointer was already refreshed and fully verified upstream in commit 67587ea6ec644ca847cf1cf77cd6f3bcba6401a6; both full old/new gates and the donor scan pass in its tracked receipts. This SDK task reuses that verification within 72 hours, with the earlier canonical-commit timestamp 2026-10-28T11:20:47Z.
No reference pointer is advanced and no qualification of the newer fetched HEAD is claimed. The independently published reference update is not counted as this contribution.
The published census index is fetched before the paired checks. Census-backed link previews: original exit 2, SDK exit 2. Preview scope is recorded in the native logs; no full-game or census gain is claimed.

Windows evidence: https://github.com/McMickey93/Open-BFME-2/actions/runs/40718695340
