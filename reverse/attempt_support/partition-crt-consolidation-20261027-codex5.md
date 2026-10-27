# PartitionManager CRT prerequisite and consolidation handoff

Inspected revision: `13d42cdf4a`. Current-object preview index: `bf3dd31211`,
2026-10-27 00:39, retail-truth-4. No translation unit merge was applied.

## Landed prerequisite

The three converters now include the toolchain's `math.h` with `/MD` instead
of hand-declaring imported CRT functions. Each native callee was checked
independently against the target PE import directory:

| BFME 2 RVA | Size | Native call VA | IAT slot VA | Declared import |
|---|---:|---|---|---|
| 0x00739840 | 44 | 0x00B39851 | 0x00BBA570 | msvcr71.dll!floor |
| 0x00739870 | 44 | 0x00B39881 | 0x00BBA570 | msvcr71.dll!floor |
| 0x007398A0 | 41 | 0x00B398AE | 0x00BBA578 | msvcr71.dll!ceil |

These are target facts, independent of the BFME 1 addresses and provisional
class labels retained in the sources. The existing x87 conversions are intact.
The normal build verifies 3/3 bodies, 129 bytes, and all three named imports.
The frozen-file check passes. `ms_header_audit` reports all three files clean;
its scoped `refresh_queue` removes exactly their three ABI-conflict entries.
The current-object link preview remains 3/3 LINKS, 129 -> 129 bytes. This is
debt cleanup, with no census or ownership gain claimed.

## Merge remains blocked

The supported current-map dry run reproduces the earlier
`consolidation-shard1-20261027.md` result: no accepted donors. Before the trial,
all 37 rows and two data rows in the 18-source cohort passed the normal build.
The dry run used the original source snapshot, before the CRT prerequisite.
Changing those declarations does not resolve its reported blockers:

- The already-linking donors cannot inherit the seed's unresolved
  `ActionManager::canEnterObject`, `Pathfinder::clientSafeQuickDoesPathExist`
  and `AsciiString::freeBytes`; initializeArray also exposes `CDEArraySlot`.
- Rva00739AF0Siblings and Rva00739CA0 have empty flag overrides incompatible
  with the carried `-O2` override.
- PartitionData donors disagree with the seed on `maybePrepend`, `m_field14`,
  `makeDirty` and `friend_updateCellsTouched`; other failures are private
  `CellAndObjectIntersection::m_cell` and duplicate `AsciiString` definitions.
- The current standalone seed also retains LINK-088's selected `isDisguised`
  conflict and the selected `PartitionData::updateCellsTouched` conflict.

No source path, ledger owner, protected debt key or hatch count was moved.
Consequently there is no path-consumer migration to audit. The other 15 source
files and the five mixed files remain intact. Preserve the donors' linkability
while reconciling the seed's existing providers and private class declarations;
another unchanged merge trial is not a prerequisite repair.
