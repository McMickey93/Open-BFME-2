# SidesList translation-unit consolidation, 2026-10-27

Starting revision: `add01ad2ad`. Target: `Code/GameEngine/Source/GameLogic/Map/SidesList.cpp`.

## Placement and input scope

The supported `name_lane.py consolidate --under Code/GameEngine/Source/GameLogic/Map/` planner was regenerated before work. Its SidesList packet records the original path and structural leads; these are placement evidence, not independent BFME 2 source recovery. `tu_skeleton.py` rebuilt the stale committed TU map in memory, and only its approved, whole-file donor subset is eligible. No regenerated TU map is committed.

The BFME 1 freshness check fetched official upstream `a0940f921b5b8d9029fc922b8032abcf4e60d240` and found the clean verified checkout pinned at `4fa9d591641a743b86f2320343b7a276585b814b`. Another worker holds `file:reference/open-bfme-1`; the checkout, gitlink and freshness receipt were left unchanged. The composition uses those existing pinned inputs.

## Baseline checks

All 60 eligible sources pass declared-unmatched checks. `./build.sh` passes 194/194 function rows and all six data rows. EH verification reports 32/32 EXACT graphs. The data identity scan reports zero findings. All 60 sources preview link cleanly against index `bf3dd31211` (2026-10-27 00:39); the cohort preserves 11,480 authored bytes. These previews are not census measurements.

The code-identity baseline has 698 references: 556 owner, 59 alias, 32 EH, 32 fold, 15 divergent and four wrong. Six rows carry the existing wrong/divergent findings. No identity or data register keys belong to these 60 sources. The candidate set has one header-queue entry, four Microsoft-header queue entries and 21 hatch entries.

## Reproduction commands

- `python3 tools/find_declared_unmatched.py --fail --paths-from build/codex3-sideslist-sources.txt`
- `./build.sh` with the 60 paths from that list
- `python3 tools/link_check.py --paths-from build/codex3-sideslist-sources.txt`
- `python3 tools/eh_verify.py --sources-from build/codex3-sideslist-sources.txt`
- `python3 tools/allowed_symbols.py --source` with those 60 paths
- `python3 tools/data_check.py` with those 60 paths

The complete baseline row and reference lists are retained locally under `build/codex3-sideslist-before-*`. These ignored files are local diagnostics; the counts, scope and outcome here are the durable handoff.

## Application, comparisons and publication audit

No consolidation was applied. The exhaustive supported dry run was stopped after approximately 75 minutes when its captured source inputs had been superseded by the verified splitter header prerequisite in `d92ecc4707`. It produced no final accepted/rejected subset. Intermediate trial source markers are not accepted donors, and no merge or source-count reduction is claimed. Temporary Code sources were removed by the verifier's cleanup; the checkout is clean.

The completed prerequisite adopts canonical AsciiString in `Rva00194810Split_Rva0032abda.cpp`, preserves its 184-byte body, 10-byte handler and EXACT EH graph, and retires its header queue item and private-class exemption. See `sideslist-ascii-adoption-20261027-codex3.md` for the producer/consumer checks. The source's ten reference bindings have no wrong/divergent findings. Its accessor now uses the canonical public owner instead of the private folded spelling. The other existing identity findings above were not modified or retired.

No source paths changed, so no deleted-path consumer rewrites or protected-register transfers are needed. Only the header lane's accepted queue retirement and the shrink-only hatch update land with the prerequisite. The other header/MS-header queues and data/identity registers stay as inspected. The shared linking obstacle register records the consumer-specific clearance under LINK-099; it does not clear broader consolidation or census obstacles.

For the next consolidation attempt, regenerate the supported naming planner against the then-current inputs and let `tu_skeleton.py --merge` rebuild the TU map in memory. Run a fresh guarded merge; do not reuse this interrupted trial as an approval. Recheck every surviving source's rows, all EH graphs, provider/consumer bindings and protected queues, then perform the batch path-consumer audit and inspect the pre-push selected-provider/lost-byte report. The baseline cohort was already link clean, so merely grouping it cannot establish a LINKED gain. All 60 scope claims from this attempt were released.
