# ControlBar consolidation, 2026-10-27

Scope claimed by yasinschroeder-codex at adbfff5a89. The default picker chose
Code/GameEngine/Source/GameClient/GUI/ControlBar/ControlBar.cpp.
The merger rebuilt the stale committed TU map in memory: 161 approved rows,
50 clean donor sources and nine mixed sources; mixed sources stay intact.
The naming planner catalogs original-path evidence and conflicts; it does not
independently approve a routing choice. No TU map regeneration is staged.

## Baseline checks

check_csv passes. All 50 sources pass declared-unmatched (existing notes in
ControlBar_Rva0031B99A.cpp and stlport_copy_ptrs_scalar8.cpp remain).
Normal ./build.sh over the 50 donors passes 140/140 functions, three data
rows, 27 funclet pins, one STLport ctor fold, strings, floats and imports.
Original objects were retained under build/controlbar-before, with external
COMDAT digests and unresolved names for the composition audit.

Ordinary link_check uses the 2026-10-27 14:34 index at 73061d9452:
49/50 sources LINKS, 12,285 -> 12,266 authored bytes. The preexisting seed
reports 17 duplicate providers against objects already absorbed into it,
including the deleted ControlBarInit.cpp census object (init provider).
This is a baseline index limitation, not evidence of a new linking loss.
The merger uses its normal LinkGuard, which filters removed census sources.
Only a census can establish new headline LINKED figures.

## Declaration prerequisites observed

The seed leaves +0x24..+0x44 and +0xA8..+0xDC as padding. Small standalone
donors name fields inside those ranges (commandButtons at +0x2C and special
power parent at +0xD8). Other donors spell the same offsets differently
from the seed (window at +0xA4, flag at +0x278, marker coordinates at
+0x280/+0x284). This is structural evidence for reconciliation work, not
proof of a canonical field name. The merger adds safe method declarations
but never adds data members or virtual functions from another private view.
No such declaration repair has been applied in this pass.

## Normal dry run and verified prerequisite

The normal --merge ControlBar.cpp --dry-run takes about 37 minutes and accepts
no pair before this prerequisite. Forty-five donors fail compilation (private
views, declaration ordering, incompatible STLport copies), W5Rva0031B9EB loses
bytes, and two byte-matching donors fail link protection. Rva0031B4D6Load and
Rva0031BF1BRemove move a unit without a census object earlier than the guard
can judge; the latter also changes another unit's node-allocator deallocate
copy. These refusals are not evidence of an observed retail linking loss.
GlobalFlagClearers_E01Dxx is the other byte failure. No source, ledger, debt,
hatch or TU-map change was applied by that dry run.

A focused diagnostic using the merger's own compose/Verifier confirms the
clearer cause: all 44 seed rows match, but all seven clearers become an
in-place DWORD AND followed by a load. Retail instead loads EAX, masks AL
and stores EAX (13 bytes each). Its dominant seed region uses /O1 /G7 SSE.
A qualified read in each existing clearer retains the load-mask-store shape
both standalone and under the merged region. This is the measured source
adaptation described in docs/recipes.md (qualify individual reads); it does
not recover or claim the original globals' qualifiers.

After that prerequisite, normal ./build.sh on the donor verifies all seven
functions and its data row. Declared-unmatched passes. All seven external
code providers retain their original digest and size; the entire external
symbol name/value/section/storage table is identical to the retained original
object. No helper, undefined symbol, data definition, alias or pin is added.
Ordinary link_check retains LINKS 91 -> 91 authored bytes against 73061d9452.
The focused diagnostic composition now matches 51/51 seed-plus-clearer rows,
and normal LinkGuard.prepare plus judge return no obstacle for that pair.
This diagnostic writes no source or ledger and is not an applied merge.

The initial full dry-run rejections are retained in the adjacent TSV. They
predate the qualified-read prerequisite; do not treat its former clearer
byte refusal as current. Other standalone donors remained untouched at this prerequisite stage. Normal
merger application was the next step; mixed sources are not split by hand.
The prerequisite alone claimed no linked-byte, ownership or source-file gain.


## Applied merge and audit

Prerequisite commit: 50bf968e01. Each clearer binds its address-named global
once through a local reference, so the qualified read adds no hatch occurrence.
The normal merger then accepts precisely ControlBar.cpp and the clearer donor:
51 matched rows, seven code-row repoints, one data-row repoint and one source
file removed. All 48 other donor refusals are identical to the initial TSV;
the nine mixed sources remain intact. No rejected donor was forced through.

Normal ./build.sh on the written TU verifies 51/51 functions, one data row,
22 renumbered funclet pins through parent EH data, 37 string literals and two
empty-string references. Declared-unmatched and check_csv pass. Comparison with
the retained premerge objects preserves all 74 external COMDAT providers
(digest, size and selection), all three ordinary data definitions and their
bytes/layout, all 71 unresolved external names and the absence of weak aliases.
The merger's full link guard accepts the pair.

Ordinary link_check still cannot give a clean result against 73061d9452:
its duplicate list grows from 17 to 27 solely because the census still includes
the removed clearer object's seven functions and three data symbols. The
merged file owns 4,565 bytes, versus the seed's 4,474 plus the clearers' 91.
This stale-object preview is not new census evidence or a claimed link gain.
The next census must confirm this merge and the seed's older absorbed owners.

The three data-ledger owner cells and three hatch keys (counts 5/5/3) follow
the donor into the TU. No identity/data debt-register key applies to either
file. The header queue has no affected entry; the merger refreshes the Microsoft
header queue, preserving its three existing unknown findings (row order only).
The committed TU map changes only seven source cells: approvals come from the
fresh in-memory map, and no regenerated assignments or confidence are staged.
Fold proofs and other active path columns have no remaining donor reference.

The merger's owning hatch_counters --update also prunes inherited stale keys
outside this scope: 14 alternatename occurrences across six Upgrade sources
and three address-global occurrences in Common/Rva00789900Init.cpp. Each source
is byte-for-byte unchanged from HEAD, and hatch_counters.scan on its HEAD text
already counts zero for the removed key. Those 17 inventory corrections are
not hatch removals implemented by this merge; the clearers' counts stay equal.
No register was hand-edited and no escape hatch was added.

The full outgoing-path audit uses merge base
743e3157581be2ce924c0f55022205ef7af5d3d0 through 50bf968e01 plus this staged
merge, after fetching origin/master at 8ec7ab3413. The only removed source in
that range is the clearer donor. Combined full-path/basename search covers
tools, hooks, workflows, source/header includes, shims, configs, registries and
docs. No active consumer needs an edit. The three remaining mentions are the
TU's absorbed-source provenance comment, the historical census link_status
row and the initial-rejection TSV. They intentionally retain the old path.

progress.py reports SOURCE FILES 22,451 (-1), TU-APPROVED 10,846 (+0), and
BYTE-MATCHED 100%. Census LINKED/LINKING and image ownership are not remeasured.
Remaining work is the private-declaration/STL reconciliation described above,
plus census confirmation. No nightly, link_cycle or smoke runner was invoked.
