# GameInfo map-metadata declaration-order prerequisite

2026-10-26, codexb5 / Sol medium, Family B shard 1/2. Target:
`Code/GameEngine/Source/GameNetwork/GameInfo.cpp`. The runner `--check-tu`
authorized this destination. Scoped GameNetwork planner original-path evidence,
alternatives and mixed-donor prerequisites were reviewed; routing and composition
are decided independently by tu_skeleton. No merge or split is applied here.

## Concrete blocker and minimal repair

The current normal merge trial accepts ten files / 49 rows. In addition to the
previously recorded constructor/reset and destructor lifetime-view blockers,
GameInfoSetMapSize.cpp is rejected because the composed MapMetaData declaration
precedes the Int and UnsignedInt typedefs: C2146/C2501 at m_numPlayers and m_CRC.
This is an existing-placeholder cleanup prerequisite, not a lost retail row.

In that donor's MapMetaData view, spell these two fields `int` and `unsigned int`,
respectively, exactly the types of its existing typedefs. No new class, field,
name, layout, global, alias, pin, function body or compiler flag is introduced.
The class no longer depends on unrelated typedef placement during composition.

## Standalone acceptance evidence

- `./build.sh` on the eleven relevant standalone sources: 52/52 exact,
  nine literals, one import. Edited donor separately: 3/3 exact.
- `tools/find_declared_unmatched.py`, `tools/class_gate.py` and
  `tools/ms_header_audit.py check` pass on the edited donor. The seed's existing
  unclaimed definition is untouched; this repair does not edit the seed.
- `tools/eh_verify.py` across those sources: ten EXACT parents, zero missing
  or nonexact. `tools/data_check.py --converged`: ten addresses, zero second
  definitions or unjudged rows.
- Fresh scoped supported object facts compare before/after: all 52 rows and
  134 references (114 owner, ten alias, ten EH) are unchanged. External code
  definitions/digests, undefined names, COMDAT rules, data definitions and data
  bindings are identical. Local funclet label ordinals use the build's existing
  located-funclet mapping. Adjacent JSON retains the receipts.

## Composition verification and demonstrated unblock

Normal upstream composition now accepts eleven files / **52 rows**, preserving
all ten previously accepted files / 49 rows and adding the map-size donor's
three rows. Both unchanged lifetime-view rejects remain. The final trial is
reverified under the carried flags; it has 73 external code definitions, no
changed or dropped definitions/COMDAT rules, no new undefined names, no divergent
standalone provider copies, and identical data definitions/bindings. Global
selection of all 73 touched names is unchanged. The composed object also passes
`eh_verify.verify_row`: ten EXACT parents, no nonexact result. This is a demonstrated normal
dry-run unblock; no downstream Luna landing is claimed.

The first scratch aggregate reference scan reported 134 standalone versus
135 composed references. Investigated Unwind@00b849a6: its verified parent EH
maps the standalone label to $L1250, while the ledger hint is $L1246. Updating
several old-name aliases at once let aliases overwrite each other. A per-row
`build.located_funclet` mapping, restored after each supported scan, proves
**135 before / 135 after references**, with zero removed or added binding.
The apparent extra reference is the existing AsciiString destructor target
0x0048BA39, not a new call. The adjacent JSON explicitly retains the incomplete
initial snapshots and the corrected complete comparison rather than treating
an incomplete scan as a pass.

The scoped planner was regenerated after all trials and rebasing completed;
its currency check passes. No gate implementation was edited. Scratch proof
scripts and receipts are under build/sol-b5-gameinfo-*.

## Ownership and remaining prerequisites

No code/data identity, header, Microsoft-header or hatch debt key is retired.
The edited donor and seed have no path-keyed finding in the inspected registers.
Existing unrelated MapMetaData identity findings in Common and GameClient stay
with their owners. No source is deleted or moved and no ledger is repointed.
The twelve mixed donors remain untouched; Common donors belong to Family A.

Constructor/reset needs the complete named member and base/lifetime view;
the destructor similarly needs the owned +C8 pointer, Version and string
members plus canonical Snapshot lifetime. Those are separate dependencies and
are not addressed by this declaration-order repair. Leave compatible clean
donors for Luna after the provider checks below establish the safe scope.

Prepublication tooling audit includes all pending commits and this staged edit.
All pending source changes are in place; attempt evidence is the only new path
category. No include, build input, registry, hook/workflow path consumer or
historical EA path needs repointing. Protected keys retain current ownership.
No regenerated TU map, manual split, gate exception or new hatch is staged.

File reduction: zero. Debt retired: zero. Recovered C++ bytes: zero. No census,
linked-byte gain, NOT OURS improvement or confirmed Luna landing is claimed.
