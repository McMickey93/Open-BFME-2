# Debug dialog flag ownership trial

Inspected base: `24518199023328f79b82ec63d43da7192b38672d` (2026-10-28).
Preview index: `41c28839bf`, 2026-10-28 11:08. No source change retained.

## Target facts and scope

`Debug_CrashDone.cpp` defines a file-static flag whose stores resolve to RVA
0x009E089D. `Debug_AssertDone.cpp` defines the ledger's external owner
`?g_debugAssertDialogAnswered@@3_NA` at that address. CrashDone's duplicate-def
and wrong-name keys remain registered. The previous attempt at log entry 86763
already established that a plain external declaration changes store scheduling.
The current trial tests whether evaluating the formatting inputs first can
preserve the retail body while sharing the external owner.

For switch cases 5 and 7, retail reads the line into ECX and file/group into
EDX, pushes the formatting arguments, then stores the flag immediately before
`wsprintfA`. The line-first snapshot keeps the entire 1,132-byte boundary
and store position, but uses EAX instead of EDX for the file/group value:

| Body offset | Retail | Trial |
| --- | --- | --- |
| +0x21E, +0x26B | 50 (ModRM: load into EDX) | 40 (load into EAX) |
| +0x221, +0x26E | 52 (push EDX) | 50 (push EAX) |

The initial `re_log.py` partial record scored this four-byte residue 0.996.
The commit hook refused its generated `reverse/attempts/0x0003aed0.cpp` stash:
check_csv rejects a banked body when real matched C++ already owns its address.
The stash was deleted as directed and a blocked follow-up records that refusal.
Only the trial description is retained; no attempted source is published.

## Other tested configurations

- Reading file/group before line changes both load order and registers.
- A force-inline formatter with value arguments has the same four-byte residue
  as line-first locals.
- An aggregate location snapshot has the same four-byte residue.
- An assignment in the first formatting argument moves the flag store ahead of
  the field reads, reproducing the earlier scheduling problem.
- A restricted entry pointer is unsupported by VC7.1 (C4235); no such change
  remains in Code.

Every trial used `./build.sh`; no manual compiler call or cache override.
The original source was restored. Paired build of CrashDone and AssertDone
passes 2/2 rows, 25 literals, four empty strings and 32 imports. The initial
paired ordinary preview is LINKS for 1,131 + 947 authored bytes. The restored
source is identical to that initial input; data_check still finds exactly the
two existing keys, with none outside the baseline. No debt or linking gain is
claimed for this trial.

Next: reconcile these private Debug views for an approved shared TU, where one
internal flag could serve both methods, or find a clean C++ argument evaluation
shape that preserves the exact register allocation. Do not repeat these local
snapshot/helper trials unchanged. TU approval must be checked afresh; this
handoff grants no move approval.

## Default picker check

The initial pick was GameEngineInit.cpp at 0x001D9670. Its current ordinary
preview reports the existing AIBuilder Object-pointer vector-destructor
selected-copy blocker (LINK-132), plus unresolved
`?TheThreatFinderManager@@3PAVThreatFinderManager@@A` against this index.
No edit or new AIBuilder trial was made. The source's own preview scope is
9,424 authored bytes; no clearance is claimed. That file/RVA claim and the
CrashDone scope claim were released.
