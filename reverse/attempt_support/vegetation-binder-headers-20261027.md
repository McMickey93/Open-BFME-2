# Vegetation binder Microsoft-header cleanup, 2026-10-27

Input revision: `a933bfc43a`; claim owner: `yasinschroeder-codexb`.
The Microsoft-header picker claimed
`Code/GameEngine/Source/Common/Rva000E6387VegetationBinderDtor.cpp`.
Its six local Microsoft names were `_strcmpi`, `floor`, `memset`, `BOOL`,
`FALSE` and `TRUE`. Replace them with `<windows.h>`, `<string.h>` and
`<math.h>`, using the existing per-source `// platformsdk` opt-in.

The original floor declaration accepted double. The real C++ header also
provides a float overload; accepting that overload changes SSE scheduling in
the 289-byte sway callback and fails its ordinary byte gate. An explicit
double argument preserves the original overload and all native instructions.
No trial body remains. No shared header, pin, function row or hatch changes.

Verification of the final source:

- Ordinary `./build.sh`: 9/9 rows exact; four strings, one float literal and
  two imports verify. Both renumbered cleanup labels resolve through their
  existing parents' EH data without changing ledger notes.
- `eh_verify.py`: EXACT 2; no missing objects or failures.
- `find_declared_unmatched.py`: all defined functions already matched.
- `data_check.py`: zero findings.
- Saved ordinary before/after objects have the same 24 external COMDAT names,
  sizes and byte-plus-named-relocation digests, with no additions or removals.
- `ms_header_audit.py`: zero local Microsoft names. Its scoped `refresh_queue`
  removes this file's six-definition queue row and preserves unrelated rows.
- Ordinary `link_check.py`: LINKS, 788 -> 788 authored bytes against index
  `bf3dd31211` (2026-10-27 00:39). No census or ownership gain is claimed.

## Historical linking lead checked before selecting cleanup

The default picker initially served OCLSpecialPower's constructor 0x004C30D8.
LINK-014 already records its repair at `eec2395dbd`. At the input revision,
the normal constructor build still passes 1/1 rows. Ordinary current-object
preview with SpecialPowerModuleDtor_Unresolved.cpp,
TerrainLogicFindPositionAround.cpp and AIUpdateInterfacePrivateCommands.cpp
reports LINKS for all four (40, 222, 1,068 and 8,722 authored bytes).
This confirms the inherited bounded repair; it adds no new gain. Its seven
unmatched donor methods and census confirmation remain separate work.

The shared obstacle register could not be claimed because another worker
holds it. Carry this recheck into LINK-014 when that claim clears. The OCL
body and file claims were released without editing its source.

## Outgoing path-consumer audit

The cleanup changes no source paths or path consumers. Rechecked the complete
outgoing range from origin/master through `a933bfc43a`: its only source-path
change is the previously audited ToppleUpdatePoolKey.cpp absorption. The
existing final audit in `topple-pool-consolidation-20261027.md` remains
applicable; another search of tools, hooks and workflows finds no active
consumer of that deleted donor. The broad Update-directory hits are tests
for other sources or synthetic paths. Historical census and attempt records
remain intentionally unchanged. The normal pre-push batch audit still owns
its selected-provider, lost-byte and input-freshness verdict.

## Recovery reconciliation

Upstream commit `336d80a1acc8497af0a53fead38e8b5ca944e402` independently
lands this same header cleanup and explicit `floor(double)` selection. Recovery
keeps that upstream implementation, including its include placement and queue
retirement. Only this historical scoped verification handoff is retained from
the overlapping local commit. Upstream also retired the LocaleUnshiftStrwcmp
and ShroudManager queue entries; recovery does not restore those stale rows.
