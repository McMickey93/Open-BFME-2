# INIAudioEventInfo predicate consolidation prerequisite

Inspected base: `1312d710f1`. Target: the existing 79-byte predicate row at
`0x001D9A00`, initially owned by
`Code/GameEngine/Source/Common/Thing/Rva001D9A00Finish.cpp`.

The consolidation picker claimed INIAudioEventInfo.cpp and eleven whole-file
donors. The naming planner's INI packet and the supported TU plan were read;
the latter rebuilds the stale TU map in memory and approves this row for
INIAudioEventInfo.cpp. No donor name or layout recovery is claimed. The
previous consolidation handoff records this donor's private StringBase
declaration as a composition blocker.

## Declaration repair

Use the existing bfme2_ascii/string_base.h declaration instead of the donor's
private StringBase template, adding its include directory to this donor only.
The shared declaration already supplies the pointer-sized member and isEmpty
call used here. No shared header or function body changes.

Both original and repaired sources pass the ordinary `./build.sh` gate: 1/1
rows, 79 bytes, and all reference checks. The declaration scan passes before
and after. Object comparison with link_census's COFF helpers finds identical
external definitions, references, weak bindings, and external COMDAT digests
(bytes plus relocations):

- Definition: `?rva001D9A00@Rva001D9A00@@QAE_NXZ`, 79 bytes,
  digest `c890e4d1303a`.
- Reference: `?isEmpty@?$StringBase@D@@QBE_NXZ`.
- No weak external bindings.

The baseline link preview, index `41c28839bf`, reports LINKS for this donor
and the destination. These are predictions, not new census measurements.
No gate, code-identity, data or header register entry names this donor; no
debt retirement is claimed.

The baseline supported dry run reproduced StringBase redefinition for this
donor and accepted no merge. After the repair, `link_check.py --prepare-current`
byte-verifies 33/33 rows across donor and destination, one data row, and all
reference checks; both have strict reusable receipts. The first preparation
trial overlapped temporary consolidation sources and refused a moving input
inventory; the successful preparation ran after that dry run finished.

## Supported composition

A fresh supported dry run accepts only the destination and the repaired
predicate donor: 33 matched rows. Its census link guard passes with index
`41c28839bf`. The naming planner was regenerated after the prerequisite's
publication rebase; its currency check passes before the applying merge.

Ten whole-file donors remain blocked: eight by the private-view/template
compile errors recorded by the earlier constructor handoff, and two by byte
differences (tailrecord allocate/copy and StlSweepW6). Twenty-three mixed files
remain outside this merge. These are existing cleanup prerequisites.

The index identifies MilesAudioMultisound.cpp as the predicate's direct
consumer. It and the previous handoff's MilesAudioManager.cpp and
Rva00433390Ctor.cpp pass ordinary byte gates together: 400/400 rows, with all
string, floating-point and import reference checks passing.

The applying merge accepts the same pair and removes one source file. It
repoints only the predicate's functions.csv source cell and its existing
tu_map.csv source cell; the approval route and evidence are unchanged. The
tool refreshes the canonical-header and Microsoft-header queues, with no
delta. Neither input has protected-register debt or hatches to transfer.

The written destination and three consumers pass `--prepare-current`:
433/433 rows, one data row, 33 string references, 41 floating literals and
106 import references. Six destination EH graphs are EXACT. Shadow data has
zero findings; converged data has no second name or unjudged row across eleven
addresses. Declaration, CSV and whitespace checks pass.

The composition retains the inputs' union of external object facts:
173 definitions, 43 external references after internal definitions
are removed, 170 byte-and-relocation COMDAT digests, and one weak binding.
The predicate's new object home therefore preserves its provider body and
callee binding; no external provider is added or removed by composition.

## Outgoing path audit

The outgoing range from origin/master `840db2d676` has one source-path change,
the predicate absorption. The earlier queued ScriptGroup cleanup changes no
paths. The combined repository search covers the removed basename and its
directory, including tools, hooks, workflows, includes, build configuration,
ledgers, debt registers, header queues and fold proofs. No active consumer
requires rewriting. The remaining removed-path mentions are the destination's
provenance comment, this handoff, and historical link_status.csv. Other
Common/Thing paths and the tool fixture referencing Thing.cpp remain valid.

## Link limits and handoff

The final ordinary preview reports LINKS for the destination (2,075 authored
bytes), MilesAudioMultisound.cpp (3,268), and Rva00433390Ctor.cpp (47).
MilesAudioManager.cpp remains unresolved on
`?bfmeTakeEC@BfmeThingEC@@QAEHPAH@Z`. The ledger's existing 38-byte row lives
in MemoryReadFile.cpp following consolidation commit `9ba5d271f8`; neither
audio input defines this name. Preparing that provider passes 2/2 rows and
all reference checks. The ordinary five-source preview refuses MemoryReadFile
because this census has not measured its new path. No index update or census
run was attempted. This broader closure remains a measurement prerequisite.

The staged-tree outgoing audit includes the entire pending batch from
origin/master `840db2d676`, with five strict prepared audio/provider sources.
It returns INCONCLUSIVE: the index at `41c28839bf` predates the base, and
the earlier queued ScriptGroup cleanup's affected consumer
`Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp` lacks a current
receipt. This retains that earlier handoff's limitation. The predicate's
apply-time link guard and unchanged external object facts provide scoped
composition evidence, not full batch or census clearance. Carry the moved
predicate, earlier moved constructor and affected consumers into the next
scheduled census. No linked-byte or image-ownership gain is claimed.
