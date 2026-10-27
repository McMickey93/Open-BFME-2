# W3DDisplayString native-layout consolidation

Inspected source revision: `71f28db691` (2026-10-26). The picker claimed
`W3DDisplayString.cpp` and its five whole-file donors. The in-memory current
TU map approves the destination; WordWrap and VslotSmallBodiesV are mixed
files and are excluded. `name_lane.py consolidate --under
Code/GameEngineDevice/Source/W3DDevice/GameClient/` supplied the original-path
packet. No donor name or layout is inferred solely from that path evidence.

## Seed prerequisite

The initial supported merge dry run accepts no donor: the seed's BFME 1
include stack redefines UnicodeString/AsciiString against the BFME 2 shims,
and the surviving class views lack donor fields. All six original objects
already pass 24/24 byte rows and ordinary preview LINKS (1,577 authored
nonpadding bytes), using the index dated 2026-10-26 19:02 at `5ce093a71a`.
This is cleanup of existing coverage, not lost-row repair or new linking gain.

The seed now uses TU-local BFME 2 declarations consistent with the existing
draw and compute-extents views and the canonical UnicodeString shim.
Retail disassembly independently confirms renderer +0x14, font +0x4C within
the renderer (getWidth at 0x0010657E), and the centered-wrap byte +0x88
(helper at 0x00105D63). The two authored method bodies retain their control
flow and the helper retains its full 25-byte match. No pin or alias is added.

Validation: `./build.sh W3DDisplayString.cpp` passes 3/3 rows;
`find_declared_unmatched.py` passes; ordinary `link_check.py` preserves
146 authored bytes and `--new-variants` reports no new conflicting COMDAT.
The objects emit no vftable in this seed-only change. No registered data
owner or address-global is introduced.

Object inspection: the obsolete PendingSurfaceStruct deleting destructor
and vector-constructor helper disappear; both have other retail-correct
providers in the inspected census index. Its unique UnicodeString peek_RV
and str_RV helpers have no incoming reference in that index; the removed
UnicodeString::validate is also unreferenced there. The canonical string
shim supplies StringBase inline helpers instead. getWidth's raw digest
changes with its private empty-character symbol spelling, while its fully
resolved retail bytes remain exact. The removed private zero-character
COMDAT has exactly one incoming discardable-COMDAT index edge: the
unreferenced str_RV helper. The original getWidth also references it from
its retained section (a root, not an edge in this index); that relocation
now names the canonical StringBase zero-character symbol instead. Its
Get_Char_Spacing call keeps exactly the same symbol. The old constant is
replaced by the canonical StringBase one. These are bounded index
facts, not proof of a new current census or ownership receipt. A binary
fixed-string scan of all current `build/match` objects after the rewrite
finds no remaining occurrence of the old private constant name; this covers
the existing local object cache, not an authenticated new whole-tree census.

## Merge refusal and handoff

The second supported dry run still accepts no donors: LinkGuard refuses the
seed itself under every flag set, saying it no longer defines
`?TheNullChr@?1??str_RV@UnicodeString@@QBEPBGXZ@4GB`, which the census still
references. The index's only incoming discardable-COMDAT edge to that private data
symbol is `?str_RV@UnicodeString@@QBEPBGXZ`; that helper itself has no
incoming census reference. The original getWidth root also references it,
but the replacement getWidth references the canonical shim's constant at
the same retail address and still byte-verifies. The guard retains the
historical aggregate reference set when it replaces the seed. This appears
to be a conservative false rejection of rewritten roots and removed inline
machinery; ordinary preview and row checks show no regression. The
`re_log.py` false-reject record points here. The check was not changed or
worked around, and no merge was applied.

Next tooling task: reproduce this case, authenticate per-object roots and distinguish retained consumers from
rewritten roots and references inside removed, unreferenced providers,
and fix/test LinkGuard in a separate verifier commit. All existing exploit
tests must remain refused. Then retry the supported merge, retaining only
byte- and link-verified donors. Constructor/destructor views also disagree
with the draw/compute declarations on field and virtual names; the merged
trials reported missing constructor/members and getText return-type conflicts.
Reconcile these independently before merging; no alias or additional vtable
name is admitted to bridge them here.

Final prerequisite validation also reports data_check 0 findings and code
identity 2 owner references, 0 wrong-binding rows. The six sources are
unchanged in path and row ownership, so no consolidation path, debt, header
queue or provider transfer was applied. No generated map was committed.

## Preparation recovery

The retained stash `c425e2e28237d24d7b96819c4b357200a0751869` restores
this seed prerequisite, both existing attempt-log records and the obstacle
handoff. The two preceding Credits cleanup commits rebase cleanly onto
current upstream. The index-preserving stash apply refused the relocated
attempt-log context without changing the checkout; ordinary stash apply
then reconciled both append-only logs cleanly. The source matches the
saved stash exactly. No saved untracked files were present, and all four
saved paths are retained. The original stash and preparation backup ref
remain available.

Recovery validation: the seed still passes all three byte rows and the
frozen-file check, and the ledger passes `check_csv.py`. The consolidation
refusal above is historical evidence from the saved attempt; recovery does
not retry the merge or change its guard. No source path or row owner moves.

The recovery batch's pre-push dry run passes 72/72 function rows, three data
rows and nine EXACT EH graphs across five verified sources. Its shadow link
batch audit stops at input freshness: the published index is older than the
outgoing base, and five source objects lack current receipts (first:
`Code/GameEngine/Source/GameClient/Credits.cpp`). It produces no selected-provider
or lost-byte verdict. Carry that scope into the next census rather than
claiming current census closure. The earlier dry-run transfer was rejected
because upstream moved; the rebased dry run passes. The runner publisher repeats
the gate after any further rebase.
