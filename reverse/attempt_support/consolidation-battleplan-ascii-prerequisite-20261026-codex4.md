# BattlePlanUpdate canonical-string prerequisite, 2026-10-26, codex4

Allocated family A shard 1/2 destination:
`Code/GameEngine/Source/GameLogic/Object/Update/BattlePlanUpdate.cpp`.
Current Update planner regenerated and its currency check passed before editing.
Its packet records same-name ZH placement hints, incomplete/mixed routing,
private declarations and flags/includes to reconcile; those hints do not prove
an original retail filename. Normal `tu_skeleton.py --plan` rebuilt stale routing
in memory: 22 approved rows, ten donors, five mixed sources, zero refused rows.
No map, source path or function-ledger change is made here.

## Repair and acceptance

BattlePlanUpdateModuleDataCtor.cpp carried a private one-pointer AsciiString
and a counted class-gate exception. Its registered header-adoption queue row
reported a byte failure. It now includes the canonical BFME2 AsciiString header.
Retail's constructor has no EH registration/unwind cleanup; `/GX-` keeps that
shape when the canonical strings have nontrivial destructors. The existing
`BFME_ASCII_DTOR_DECL` header switch uses the outlined destructor declaration
and avoids emitting an unused local inline destructor/provider. No new macro
branch, header change, optimizer pragma or escape hatch was added.

`python3 tools/header_adopt_lane.py accept --class AsciiString
Code/GameEngine/Source/GameLogic/Object/Update/BattlePlanUpdateModuleDataCtor.cpp`
passes and retired its one registered queue row. The stale class-gate exception
is removed; `hatch_counters.py --update` generated the shrink. Only this target's
one-key decrease is retained; unrelated pre-existing baseline slack is left
alone. This is one header prerequisite and one hatch removed, not new recovered
bytes or a completed receiver-layout reconciliation.

## Verification and provider/consumer evidence

- Before and final `./build.sh` for the constructor: 1/1 exact, 153 existing
  retail bytes, with one float literal verified and no import/string failures.
- `find_declared_unmatched.py` passes. `allowed_symbols.py --source`: two
  owner references, zero wrong bindings. Ordinary `data_check.py`: zero findings;
  `--converged`: ten addresses, zero second names/unjudged rows. `eh_verify.py`:
  zero applicable EH rows or missing objects. `check_csv.py` passes.
- Using upstream `allowed_symbols._object_defs`, `data_check.object_facts` and
  COFF COMDAT helpers, the saved before object and final object compare exactly:
  three code definitions with identical digests/sizes/exclusivity, all three
  COMDAT selections, two external data definitions including their relocation
  fingerprints, all undefined references and the constructor's data bindings.
  No selected provider can change through this source's definition set; no new
  consumer edge or binding is introduced. This comparison uses current scoped
  objects, not an older census as proof of composition or linking.
- An intermediate default-header trial emitted a retail-proven AsciiString
  destructor and a releaseBuffer dependency. It was replaced by the header's
  declaration-only mode; neither extra symbol survives in the final object.
  A diagnostic on the old, stale releaseBuffer object was inconclusive; no
  cross-family provider repair or naming decision is claimed or attempted.
- No code/data-identity keys exist for this donor, none are retired. The header
  queue shrinks through its acceptance path; no Microsoft-header row exists.
  Existing code/data bindings and protected function rows are preserved.

Receipts: build/codex4-battle-ascii-{before,decl}-build.txt,
build/codex4-battle-ascii-{before,decl}.json (identical), saved before object and
build/codex4-battle-ascii-final-proof.txt. Normal before/final dry-runs are in
build/codex4-battle-ascii-{before,final}-trial.txt.

## Composition and remaining prerequisites

The before dry-run accepts no pair and explicitly lists this donor's
`adopt_first: AsciiString` prerequisite. The final trial removes `adopt_first: AsciiString` but still accepts no pair.
The module-data trial first fails on declaration order around
BattlePlanUpdate::getBattlePlanUpdateModuleData; other donors retain missing
BattlePlanStatus, receiver destructor/constructor, getModuleNameKey,
onObjectCreated and Object::Player declarations, plus Xfer template/includes.
Header adoption does not establish those receiver layouts. Leave future
compatible merges to Luna; no downstream landing or linked-byte increase is
claimed.

## Publication audit

The complete unpublished source batch plus this staged repair contains no
source path moves/deletions or ledger repoints. The upstream branch advanced
while claims were in use, so raw origin/master..HEAD also shows incoming split
and merge deltas; `git log origin/master..HEAD` and the merge-base-to-HEAD diff
identify the actual outgoing prerequisite. Combined path search across tools,
hooks, workflows, Code includes, build inputs and source registries finds the
two intended Prone header consumers and BattlePlanUpdate's historical unmerged
row comment. Both Prone consumers were verified together in the prior commit;
this constructor's canonical header include is direct and verified here.
Receipt: build/codex4-battle-ascii-path-audit.txt. No active path consumer needs
repointing; historical EA paths remain intact.

Measurements for this prerequisite: zero recovered C++ bytes, zero files
removed/added, one header-queue row retired, one class-gate hatch removed, zero
code/data identity keys retired. Keep the two BattlePlan file claims until
confirmed publication; the prior Prone commit's four scope claims also remain
pending if the runner holds this batch.
