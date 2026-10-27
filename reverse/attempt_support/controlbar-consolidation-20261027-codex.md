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
byte refusal as current. Other standalone donors remain untouched. Normal
merger application is the next step; mixed sources are not split by hand.
No measured linked-byte, ownership or source-file gain is claimed here.
