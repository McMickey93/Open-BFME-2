# BFME 1 reference freshness: native comparison, 2026-10-27

The prior verified BFME 1 pointer is `e74410b3738a2bb75d626085d9ebfd3406a43ff7`.
The reviewed upstream pointer is `eb60756a8aa6ba1648edd234b16bcc778fcbbe7b`.
The full old/new comparison uses one fixed BFME 2 revision; publication rebases and runs the normal gates again.

The previous peer reservation has gone. The project claim protocol's file scope was
rechecked in both namespaces, reserved under a fresh lease, and passed its conflict check.
The optional machine identifier is omitted from public claim metadata.

## Input review

Upstream changes 31 game source files, with no header changes and no layout migration.
The four source-specific flag-line differences are:
- `Common/Bfme/Rva00C6DB80StaticInit.cpp`: `/O2 /MD` becomes `/EHsc`.
- New `Common/RTS/Team_notifyTeamOfObjectDeath.cpp`: its own NDEBUG/Windows/CRT/EH/STL and WWLib include flags.
- Removed `Object/Contain/GarrisonContain_xfer_Thunk.cpp`: its former NDEBUG/CRT/EH flags disappear with the donor.
- New `W3DViewRva00743CE0.cpp`: its own root include and NDEBUG/Windows/CRT/EH flags.

These are donor settings, not new BFME 2 compiler overrides. No target layouts,
offsets, function bodies, flags, verifier or baseline are edited. All six current
reference directories resolve to the existing `game/`, `inputs/` and
`targets/game/reverse/` layout. The sole changed nested input is the BFME 2
reference gitlink; it is deliberately not initialized, avoiding reference recursion.

A local full-gate attempt stopped before completing the byte comparison because
Windows refused to launch a legacy compiler with WinError 623 (system DLL relocation).
It is not a successful verification. The independent native Windows runner below
performs both complete checks with the original compiler and unmodified build driver.

A fresh runner starts without earlier donor compile trials. A successful refresh
also regenerates the project donor sweep and records its exact input revisions.
No old trial is represented as current. A failed check keeps the canonical pointer
and records the blocker; it never writes a success stamp.

## Native Windows qualification

Mode: **blocked-reference-handoff**. Both complete byte checks use the unmodified driver and original compiler.
Both runs use BFME 2 revision a32b57717fbed592c703a13bfd0661cf9a28a94e with valid dependency caches.
Original input exit: **1**. Updated input exit: **1**. Donor sweep exit: **None**.

### Original reference

Full log SHA-256: 540c589894c3d19289b310ba49080d08be24d6b86c18ccf4d6f4298d432af9d3.

~~~text
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Functions: OK 98941/98941 matched across 22295 source file(s)
String-ref verify: OK (31537 literals + 2254 empty-string refs verified, 0 baselined, 0 unverified/skipped)
Float-ref verify: OK (9117 compiler literals verified)
Import-ref verify: OK (6425 named imports verified)
DIR32 consistency: FAIL 4 NEW inconsistent symbol(s) (candidate hidden bug — same symbol, multiple addresses)
Pin consistency: OK (5 multi-pinned symbols of 10523; 0 baselined, 0 new, 0 stale)
Data rows: OK (2203 row(s) byte-verified)
FULL GATE: FAIL — 1 red: dir32 consistency
DIR32 consistency: FAIL 4 NEW inconsistent symbol(s) (candidate hidden bug — same symbol, multiple addresses)
FULL GATE: FAIL — 1 red: dir32 consistency
~~~

### Updated reference

Full log SHA-256: 332dfac09a092731a865eb70c10bae590674c0c52345b5fb3c35ed91acf4310c.

~~~text
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Compile: 0 of 1 TU(s) (deps-cache: 1 current)
Functions: OK 98941/98941 matched across 22295 source file(s)
String-ref verify: OK (31537 literals + 2254 empty-string refs verified, 0 baselined, 0 unverified/skipped)
Float-ref verify: OK (9117 compiler literals verified)
Import-ref verify: OK (6425 named imports verified)
DIR32 consistency: FAIL 4 NEW inconsistent symbol(s) (candidate hidden bug — same symbol, multiple addresses)
Pin consistency: OK (5 multi-pinned symbols of 10523; 0 baselined, 0 new, 0 stale)
Data rows: OK (2203 row(s) byte-verified)
FULL GATE: FAIL — 1 red: dir32 consistency
DIR32 consistency: FAIL 4 NEW inconsistent symbol(s) (candidate hidden bug — same symbol, multiple addresses)
FULL GATE: FAIL — 1 red: dir32 consistency
~~~

Failure-line comparison: 2 common, 0 old-only, 0 new-only. Full line sets are retained in the comparison receipt.

The update is blocked by the recorded full-gate result. The canonical pointer is kept; no successful freshness stamp is written. Resolve these checks before retrying the reference refresh.
No new C++ body, byte coverage, linked bytes or source-recovery gain is claimed.

Native logs and comparison receipt: https://github.com/McMickey93/Open-BFME-2/actions/runs/40579777763
