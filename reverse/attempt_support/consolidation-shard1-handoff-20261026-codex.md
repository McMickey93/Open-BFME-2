# Consolidation shard 1 handoff — 2026-10-26

## Completed mechanical merges

- `Science.cpp`: three accepted unchanged donors, 14 matched rows; build, frozen-file check, CSV and allowed-symbol checks passed. See `consolidation-science-merge-20261026-codex.md`.
- `SupplyWarehouseCripplingBehavior.cpp`: two accepted unchanged donors, 3 matched rows; build, frozen-file check, CSV and allowed-symbol checks passed. Shadow data/code identity findings remain open. Prescribed `repair_queue.py retire data` refused because it found three new shadow `wrong-name` findings. See `consolidation-supply-warehouse-merge-20261026-codex.md`.
- `SupplyCenterCreate.cpp`: one unchanged donor accepted, 3 rows including its compiler EH row; build, frozen-file check, CSV and allowed-symbol checks passed. Two shadow data `wrong-name` findings remain open; code identity reported no new finding.

The combined active-path consumer search for the absorbed donors in those three merges found no references under `tools/`, `.githooks/`, `.github/` or `Code/`; historical ledger entries remain. The outgoing `link_batch_audit.py` still needs to compare the composed providers/consumers before publication.

## Rejected candidates

- `Code/Tools/WW3D/pluglib/matrix4.cpp`: allocated and planner-valid, but the dry run aborted before donor acceptance with `FileNotFoundError` creating `Code/Tools/WW3D/pluglib/.matrix4.fee4166dfd935a4c.tu_skeleton.cpp`; the destination directory is absent. No source or ledger edit was made.
- `LocomotorSetUpgrade.cpp`: no accepted donors. The constructor and implementation donors fail compilation because `getModuleNameKey` is not declared as a member of `LocomotorSetUpgrade`.
- `RadarUpgrade.cpp`: no accepted donors. Pool-key donor fails because `getModuleNameKey` is not declared on `RadarUpgrade` (C2039/C2270); implementation donor has C2143/C2501 around `Rva004B46F9::Object`.
- `DeletionUpdate.cpp`: no accepted donors. Sleep-delay donor fails with duplicate `GameLogic` class C2011; pool-key donor lacks `rva00048838B` on `DeletionUpdate` (C2039); Xfer donor lacks `Xfer::Version1` (C2039), with first-use `Xfer` adoption indicated.

These are unchanged blockers for Sol; no repair, identity retirement, or tool change was attempted. The mixed donors were left untouched.

## VeterancyCrateCollide follow-up

- Merged the unchanged `Rva004BCF92.cpp` helper; nine matched rows remain in the approved TU. Build byte verification passed 9/9, including four funclet pins whose compiler labels renumbered; `find_declared_unmatched.py`, CSV, and allowed-symbol checks passed (30 refs, 0 wrong bindings). Staged data and code-identity gates reported no findings.
- The ctor donor remains rejected with C2511: `VeterancyCrateCollide(Thing *, const ModuleData *)` is not declared; the pool-key donor remains rejected with C2039: `getModuleNameKey` is not a member of `VeterancyCrateCollide`. Both stay untouched for Sol.

## Final batch audit and additional rejected candidates

- Outgoing path-consumer search across `tools/`, `.githooks/`, `.github/` and `Code/` found no active references to absorbed donor paths. The outgoing `link_batch_audit.py` was run for base `f4ec351d97abc6bbd58f1473e1157b5a44684724` and tip `6716deeb10628457add29f54211f6a33e3ef6c6e`. It is inconclusive: its census index is at `bcb191bfeb`, before the outgoing base, and `VeterancyCrateCollide.cpp` has no current object receipt. Treat reported since-index changes as provisional; no link-cycle or census claim is made.
- `AutoFindHealingUpdate.cpp`: no donor accepted; ctor donor fails C2039 because `getModuleNameKey` is not a member.
- `UpgradeDie.cpp`: no donor accepted; `DieModule` is undefined and member initialization is invalid.
- `QueueProductionExitUpdate.cpp`: no donor accepted. Exact dry-run blockers include `BitFlags` `NUMBITS` template mismatch (C3855), duplicate `Xfer`/`Coord3D` declarations (C2011), missing `rva0004A00C2` (C2039), undeclared `m_secondary20` (C2065), and exit-position/query/set/notify donors that collide on `Coord3D`. No rejected donor was modified.
