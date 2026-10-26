# BFME 1 reference freshness, 2026-10-26 (codexb)

Mandatory freshness maintenance while recovering the inherited family B
prerequisite batch; this is not an independent BFME 1 work lane.

The previous freshness receipt is 2026-10-23 15:58 UTC at verified/upstream
96c88c73a5cd1a58fc2f8db691beea50acd996db. At session start BFME 2 already pins
de077dd5dd8339716a6abe453a1d81dfdf77e651. Its detached submodule checkout is
clean and agrees with that pin; no unpublished or dirty reference work is
discarded. Official Open-BFME/Open-BFME-1 master was fetched and independently
confirmed by ls-remote as 001ccd8e27686e9887235b62ff797627f2dde7f5.

The fixed old/new comparison uses BFME 2 revision 179de3e004 and unchanged game
sources. The upstream difference has 109 tracked paths, including 77 game
source files. It changes no inputs/, headers, inline/include files, toolchain
settings or reference layout. The existing game/ and inputs/reference/ resolver
remains applicable. Scanning 24,378 cached dependency receipts finds zero
intersections with those changed game sources; compiled objects remain subject
to the build tool's dependency-currency checks.

## Verification receipts

The initial old-pointer full check passed all 98,271 function rows and literal,
float, import, DIR32, pin and module checks, then a concurrently running
tu_skeleton dry-run removed a temporary source while source-ownership scanning
was reading it. This was a verification race introduced by this seat, not a
retail mismatch. The trial was allowed to finish and the full gate was restarted
without concurrent source trials. No failing run is counted as successful.

Scratch evidence is build/codexb-freshness-20261026-{inputs,
dependency-intersections}.json and the old/new full-gate logs. Freshness is not
stamped until verification completes. This maintenance claims no recovered
bytes, file reduction, identity retirement or census gain.

The clean old-pointer retry (`./build.sh`, logged as
build/codexb-freshness-20261026-old-retry-full.txt) exits zero: all 98,271
function rows, 2,216 data rows, references, ownership checks and no-op patch
pass. The new-pointer comparison uses exactly the same BFME 2 game inputs:
Code tree cff2d4c831896032fec373b50a40dc64f9c13be0 and function-ledger blob
66ad10d7cc7b842597e3664a878b6663053c7ad9. The clean official reference is
advanced in place and its gitlink staged before the build, so the normal
reference-pin guard remains active.

## Refreshed derived evidence

`python3 tools/bfme1_sweep.py scan --min-size 16` exits zero against 001ccd8e:
5,536 unique placements, 5,528 independently matched exact boundaries, zero
free placements and 617 near misses. The new scratch match.json SHA256 is
91730d534eba251d10ce1b3a2ea0c8140b6790a1c1ede186185e542f7b18e1dc;
build/bfme1_sweep/codexb-20261026-inputs.json records its donor revision and
command. The old scratch result is preserved separately, not used as current
evidence. No compile trial involving changed BFME 1 sources is reused.

Regenerated the GameNetwork evidence planner at
build/consolidation/codexb-reference001ccd8e. Its normal --check passes.
The NetPacket composition itself is independent of changed BFME 1 source
inputs; its recovered 16-source/188-row dry-run and provider/EH proof remain
recorded in netpacket-progress-prerequisite-20261026.md. No merge is applied.

## Verified result

The new-pointer `./build.sh` run, captured in
build/codexb-freshness-20261026-new-full.txt, exits zero with FULL GATE: OK.
Both comparisons pass 98,271/98,271 functions across 22,805 sources, 2,216 data
rows, 31,537 literals plus 2,257 empty-string references, 9,116 float references,
6,419 imports, DIR32 consistency, pin/module/source ownership and the no-op
patch. Neither run has a residual failure or update regression. The new run
finds all 22,804 compiled function providers current. CSV integrity passes.

Only after that result is the ignored freshness receipt updated to verified
and upstream 001ccd8e. The update moves no production source path and requires
no tooling, include, build-input or source-registry repointing. Existing debt
keys, approved routing and historical EA paths remain unchanged. Publication
retains the normal pre-commit and pre-push checks, including the full gate
required by the reference-pointer change.

After rebasing the inherited commits onto origin/master 0be605a714, the complete
outgoing range plus staged reference/evidence changes was audited together.
Three production files are edited in place; none moves, is removed or is
absorbed. Combined old-path/basename searches across active tools, hooks,
workflows, includes, build/configuration inputs and registries find only the
expected current ledgers, TU placeholder comments and historical evidence.
There is no affected consumer to repoint. The final eighteen-source NetPacket
build passes 227/227 rows; strict current receipts, frozen-file checks and the
standalone/composed provider and 65-parent EH proofs pass again. The existing
list-copy identity finding and full-index freshness gap remain open; no
measured linking or identity-debt improvement is attributed to this update.
