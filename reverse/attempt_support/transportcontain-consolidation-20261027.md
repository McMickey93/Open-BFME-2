# TransportContain consolidation, 2026-10-27

Scope: `Code/GameEngine/Source/GameLogic/Object/Contain/TransportContain.cpp`.
Inspected seed `ae7b59bf7b`; census index `bf3dd31211`, 2026-10-27 00:39.
Claims were obtained by the default picker and the supported merge tool.

## Target evidence and applied change

Retail constructor 0x00468559 stores primary vtable VA 0x00C44278 at
0x00468590. Slot 4 of table RVA 0x00844278 contains VA 0x00867EE1,
the existing `TransportContain::getModuleNameKey` row at RVA 0x00467EE1.
The prerequisite replaces the seed's anonymous slot-4 declaration with that
row's real signature. These are target-image facts, not donor layout claims.

The consolidation planner was regenerated after the prerequisite and its
`--check build/consolidation` passed before composition. Its stale committed
TU-map inputs were not treated as approval: `tu_skeleton` rebuilt assignments
in memory. Only the approved getter's existing map source cell was repointed;
no regenerated map is committed. The guarded merge absorbed the pool-key donor
and its three rows (getter, EH handler and guard rollback funclet). It retained
all 23 seed rows. No source was manually concatenated and no rejected body was
left in Code.

## Verification and protected ownership

- Before: `./build.sh` verifies 23/23; ordinary `link_check` reports LINKS,
  2,455 -> 2,455 B, with the old LINK-031 module-data ctor duplicate absent.
- After: `./build.sh` verifies 26/26, `find_declared_unmatched.py` reports all
  defined functions matched, and `check_csv.py` passes (98,276 function rows).
  `eh_verify.py` reports four EXACT graphs. Renumbered funclet labels retain
  their parent-proven native locations.
- `tu_skeleton`'s link guard compares the original donor/seed providers with
  the merged provider and checks other units' affected selected copies. The
  final composition passes; every candidate donor was census-linked.
- The ordinary after preview reports duplicate/selected for the getter,
  2,455 -> 0 B (merged unit's own count 2,534 B). The unchanged census index
  still contains the deleted donor. This is recorded in LINK-031; it is not
  reported as a census regression or clearance. A fresh measured index is
  still needed. No nightly, link cycle, boot or game smoke was started.
- The single data-baseline key transfers to the seed unchanged. Both data
  ledger path references transfer, with existing names retained. No code
  identity key belonged to the absorbed donor; the seed's unreferenced
  `Object::clearCondition` divergent copy remains the pre-existing shadow
  diagnostic. Hatch counts are unchanged. No debt retirement is claimed.
- The data shadow check reports two wrong-name findings for the real getter's
  local key (0x00A0365C) and guard (0x00A03660), while the data ledger and carried
  baseline retain the old `rva000467EE1` spelling. The original donor already
  spelled the real getter and local key identically; its cached parent object
  reports the same two findings. Do not hand-delete the carried key or add
  baseline entries. Reconcile the data identity and use `repair_queue.py retire
  data` on a fresh clean verdict in a separate commit.
- `tu_skeleton.refresh_reports` finds no affected header-adoption entry and
  refreshes the MS-header row. Its conflicting allocator ABI warning remains
  semantically unchanged. The existing row position is retained to avoid
  conflicts with concurrent queue appends; no queue-content change is landed.

## Tooling compatibility audit

Audited fetched origin `9d6c94a6fe` through local HEAD `ae7b59bf7b` plus the
staged consolidation. One removed path:
`Code/GameEngine/Source/GameLogic/Object/Contain/TransportContainPoolKey.cpp`,
whose owner is now `TransportContain.cpp` in the same directory.

Searched tracked index contents with the combined old full path and basename,
then reviewed containment-directory and pool-key matches in tools, tests,
hooks, workflows, build.sh and the Doxygen source registry. No active tool,
include, build consumer or Doxygen input names the removed donor. Generic
source discovery still sees the destination in the unchanged directory.
The merge repoints functions, data paths and the map source cell. Protected
registers and queues point to the current owner. Remaining exact old-path
mentions are the seed's provenance comment, historical re_attempts.log and
reverse/deleted_rows.csv evidence, and measured reverse/link_status.csv.
These retain history rather than being rewritten as current measurements.
HordeTransportContainPoolKey matches are distinct live sources, not stale
references. This handoff and LINK-031 intentionally name the absorbed donor.

Local raw receipts: build/codexb-transport-{dry-run,merge}.log,
build/codexb-transport-{prerequisite,merged}-{build,link}.log,
build/codexb-transport-path-audit.log. They are scratch evidence, not progress.

## Remaining whole-file prerequisites

The following thirteen donors remain unchanged. Compiler diagnostics below
are the supported merge tool's final verdict, not claims that their original
standalone reconstructions fail. Reconcile each class view in an ordinary
byte-verified prerequisite commit before another guarded merge.

- `TransportContainXfer.cpp`: seed lacks xfer; OpenContain access also conflicts.
- `stlport_rb_tree_insert_unique_nocase.cpp`: reference headers redefine the private Coord3D view (and further declarations conflict).
- `slot38Rva00466EDEFarm.cpp`: OpenContain view lacks onRemoving.
- `TransportContain_createPayload.cpp`: merged view lacks m_4/m_8.
- `TransportContainRiders.cpp`: Object view lacks m_contain/getContainedItem declarations.
- `TransportContainRiders_Rva0046740C.cpp`: Object view lacks m_contain/getContainedItem declarations.
- `TransportContainOnContaining.cpp`: ObjectStatusTypes and dependent declarations are unavailable.
- `Rva00467DE6PayloadParse.cpp`: duplicate incompatible _STL::list views.
- `TransportContainDtor.cpp`: merged bytes differ; isolate the destructor ABI/codegen change before moving it.
- `TransportContainUpdateUpgradeCreationTriggers.cpp`: duplicate incompatible _STL::allocator views.
- `TransportContainModuleDataDtor.cpp`: Rva00467FCC element type dependencies are unavailable.
- `TransportContainCtor.cpp`: OpenContain view lacks onRemoving.
- `Rva00468908Parse.cpp`: element type dependencies are unavailable in the merged view.
