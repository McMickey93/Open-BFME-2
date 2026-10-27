# gen_uw provider attempt (2026-10-27, codex/gen-uw-provider-20261026 seat)

Status: blocked on census architecture, reverted. No gate code changed on master;
the tool edit (`e5dc4dd4ffb`) was reverted by `287d7f0f08e` on this branch and is
recorded here so the next lane does not rebuild it blind.

## What was tried

`tools/gen_uw.py land` gained a tree-wide scaffold provider: one generator-owned
TU `Code/gen_small/gen_uw_helpers.cpp` defining every scaffold-only name the
funclet files reference (`gen_uw_ext`, `gen_uw_sink`, per-target
`Gen_uw_*`/`Gen_uwm_*` ctor+dtor, `Gen_uws<n>_*` sized deletes, `Gen_uwt_*`/
`Gen_uwp_*` placement shapes, the `Gen_uw_new` family) with one honest
`absent-from-retail` marker per body. The intent: give the census a defining
object for each unresolved scaffold callee so the gen-uw funclet units link
instead of staying "undefined by design" (LINK-095).

## What the run showed (full gate, snapped back, nothing changed)

The run converted the 15 committed `uw_gen_*.cpp` files into 3 files of 1100/
1195/105 rows over 888 units plus the provider (933 scaffolds defined), landing
2400 of today's 2400 on-ladder rows (`classify`, post-pull census) and 572 pins.

The full gate came back 7 red and the run restored every ledger row, pin,
tombstone and owned source (`gen_uw: verification failed (exit 1) -- every
ledger row, pin, tombstone and owned source REVERTED`).

1. **Byte verification of funclet payloads tree-wide broke.** Five consumers
   kept retail bytes but the compiled copy zeroed one call:
   `??_GGen_uw_001212f0@@QAEPAXI@Z` (Rva00122190Delete.cpp), the
   `Rva00386374`/`Rva00386374Copy` pair, `??1Rva0055133F@@UAE@XZ`
   (BuddyThread.cpp), `?TearDownGameSpy@@YAXXZ` (PeerDefs.cpp) -- every one
   printed `unresolved call(s): <scaffold> (add to reverse/symbols.csv)`.
2. **Cause:** the pin writer rebuilds the gen-uw-pin note rows wholesale
   (`rewrite_lines(SYMBOLS, ... endswith(PIN_NOTE_BYTES))`, tools/gen_uw.py ~1317)
   from the current plan's targets only. Today's ladder holds 2400 rows / 572
   targeted pins while `reverse/symbols.csv` at HEAD carries 999 gen-uw-pin
   rows; the run's replacement dropped 427 pins that other reconstructions'
   payload bytes still call (e.g. `??1Gen_uwm_00610480@@QAE@XZ,0x00610480`, HEAD
   line 3837). `link_check.py`'s `resolves()` confirms the census resolves a
   callee through object-definition facts (mine/common/elsewhere/excused), not
   through pins; the pin is the byte-verification side's rel32 filler, so
   deleting it un-verifies the caller even though the provider defines the name.
3. **Source claims refused the provider file itself:**
   `gen_uw_helpers.cpp: ZERO matched rows -- source presence is not progress \\
   ... or park it in reverse/unclaimed_sources_whitelist.txt with a written
   reason`. AGENTS.md: the whitelist is "no remedy and only shrinks", so a
   zero-row provider TU is not landable as a Code/ source.

## Why the provider idea concedes to the register

docs/linking_obstacles.md LINK-095 states the lane's own target: the roster of
uw_gen files **never links by design**; the repair is per-funclet re-homing to
its matched parent's `$L` label (done for 44+36+66+42+133 funclets across 41
sources by ddb6835a35 / 14ea56bea7 / K7 r13/r14 on 2026-10-26), and the missing
element dtors get "named or rowed at the address retail's funclet jumps to"
(`tools/pin_admission.py --add`, or a real row). A defining provider TU is not
that mechanism.

Also relevant: the funclet ladder shrank from 3180 rows (pre-pull census) to
2400 rows / 22004 B (post-pull) because overnight published work renamed
`Gen_uw_*` scaffolds to real funclet rows at their parent homes
(`Unwind@00b989eb ... was gen_uw scaffold uw_007989eb`, reverse/functions.csv
line 88205). Any land run inherits today's 2400-row world automatically; the
previous 15-file layout and its 999 pins are artifacts of older states and must
be reconciled by land itself, not dropped silently.

## If a provider is ever revived

- The pin writer must union: carry every pre-existing gen-uw-pin row whose
  callee bytes are still referenced anywhere in the tree, and only add the
  plan's own pins. Never replace wholesale.
- The provider TU needs at least one census-visible anchor (matched row,
  address-owned body or an explicitly sanctioned park) to pass source claims;
  zero-row Code/ sources are refused by design.
- The funclet funclet payload rows that the run "tombstoned 12" for are the
  census's own shrinkage -- the writer must also propagate rename candidates
  (`Rva00122190Delete.cpp`, `BuddyThread.cpp` patterns) instead of leaving the
  old scaffold pins as the only callers.
