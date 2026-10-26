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
