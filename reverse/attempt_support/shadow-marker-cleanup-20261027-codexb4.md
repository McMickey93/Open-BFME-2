# Shadow manager stale exemption retirement

Inspected revision: `f732423015fbfd125b6e53802bc69775aac0f1e9`.
Source: `Code/GameEngineDevice/Source/W3DDevice/GameClient/Shadow/W3DVolumetricShadow.cpp`.
Published preview index: `bf3dd31211`, 2026-10-27 00:39, `retail-truth-4`.
The default picker claimed the complete source and resetSilhouette at
0x000F0832. Its historical selected-copy blocker is already repaired by
LINK-106: paired with the current BfmeDX8ThreadLock.cpp provider, the source
previews LINKS before this change (348 authored bytes; provider 247 bytes).
This is caller verification of the existing repair, not a new linking gain.

The two manager destructors at 0x000F2797 (60 bytes) and 0x000F2ECB
(143 bytes) already have matched rows in this source. Their old
present-unmatched comments are stale exemptions. Replace only these comments
and delete only their two keys from the shrink-only hatch register, retaining
unrelated allowances. No function, ledger row, global, pin, include, compiler
option or source path changes.

Before and after checks:

- `./build.sh` passes all four rows, 348 bytes, plus string, float and import checks.
- `find_declared_unmatched.py` passes; the two unclaimed-definition notes disappear.
- `eh_verify.py` reports the manager's one EXACT graph, no baseline exemption
  and no missing object.
- All 13 emitted COMDAT names, sizes and normalized byte/relocation digests
  are identical, including unrowed emissions. Whole object hashes differ;
  binary object identity is not claimed. [The comparison](shadow-marker-cleanup-20261027-codexb4.json)
  records both source/object hashes and the common COMDAT digests.
- The paired ordinary preview remains LINKS for both units with 348/247
  authored bytes. No census was run; strict closure and census confirmation
  remain unclaimed. LINK-008's include-inventory prerequisites remain separate.
- Shadow `data_check.py` retains two wrong-name findings for the existing
  g_00DEBE0C and g_00DEBE24 declarations. The declarations and relocation
  digests are unchanged; no data debt is retired here.

The hatch register loses exactly two present_unmatched keys. A whole-tree
report also has unrelated pre-existing lower counts; those keys are preserved.
