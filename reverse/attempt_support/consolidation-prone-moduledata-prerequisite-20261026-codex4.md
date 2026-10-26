# ProneUpdate module-data prerequisite, 2026-10-26, codex4

Allocated family A shard 1/2 destination:
`Code/GameEngine/Source/GameLogic/Object/Update/ProneUpdate.cpp`.
The scoped Update planner and currency check passed before editing. Its packet
records donor-path hints, duplicate private declarations, flags, includes,
internal helpers and mixed rows; it does not prove a retail filename. The
normal plan rebuilds stale routing in memory: nine approved rows, four donor
files and two mixed files. No source or ledger moves in this prerequisite.

## Repair and demonstrated unblock

The normal before dry-run accepted no pair. Composition with the module-data
constructor failed because its private declaration replaced the update's
accessed-prefix declaration, including declaration ordering and access errors.
Both sources now include ProneUpdateModuleDataView.h. This retains the
constructor's explicit vtable word at +0, untouched word at +4 and float ratio
at +8; the update replaces eight bytes of padding with the existing words.
Only the accessed prefix is shared; no new primary/secondary receiver layout,
vtable identity, ownership or donor provenance is inferred.

After, `python3 tools/tu_skeleton.py --merge
Code/GameEngine/Source/GameLogic/Object/Update/ProneUpdate.cpp --dry-run`
accepts the seed and ProneUpdateModuleDataCtor.cpp: five rows / 189 existing
retail bytes, versus no accepted pair before. This is a demonstrated prerequisite
unblock, not a confirmed downstream Luna landing. Leave that merge to Luna.
Remaining rejections: pool-key member absent from the receiver view; receiver
constructor/base declaration and ABI composition. Two mixed donors remain.

## Verification and bindings

- Before/after `./build.sh` on both sources: 5/5 exact; one float literal and
  all applicable import/string checks pass. Both sources pass
  `tools/find_declared_unmatched.py`; `tools/check_csv.py` and diff whitespace
  checks pass. `eh_verify.py` finds no applicable EH rows or missing objects.
- Standalone complete code-definition fingerprints, sizes, exclusivity,
  undefined references and per-row data facts compare equal in
  build/codex4-prone-data-{before,after}.json. Saved before objects and
  build/codex4-prone-data-proof.py also compare external data definitions and
  actual COMDAT selections before/after, all equal.
- The actual composed object build/tu_skeleton/146d952a59183afb.obj has exactly
  the standalone union: eleven code definitions, one external data definition,
  four unresolved names, with identical fingerprints, sizes, exclusivity and
  all eleven COMDAT selections. All five rows retain identical DIR32 data
  bindings: only the constructor's folded vtable alias at 0x0084ED70 and
  float literal at 0x007BB8D8. No provider, selected COMDAT, undefined name or
  consumer binding changes in either standalone object or the trial. These
  scoped checks use upstream allowed_symbols/data_check/COFF helpers; no census
  or maintainer-only runner was invoked.
- `allowed_symbols.py --source` for the pair: six owner references, zero wrong
  code bindings. `data_check.py --converged` for the pair: two sources, ten
  converged addresses, zero second names/unjudged rows. Ordinary shadow data
  checking retains the constructor's existing _vtbl_00C4ED70 wrong-name finding;
  sharing a declaration does not prove a new vtable name. No data/code-identity
  register keys exist for these two sources; none are retired or transferred.
- Header and Microsoft-header queues contain no rows for the pair; no queue
  entry is removed. The constructor's counted alias remains in its original
  source; no hatch or protected baseline is edited. A future merge must carry
  it through the normal tool path and use its printed transfer trailer.

Receipts: build/codex4-prone-{before-trial,data-after-trial}.txt,
build/codex4-prone-data-{before,after}-build.txt and the proof files above.

## Publication compatibility audit

Audit covers origin/master..HEAD plus this staged prerequisite and blocked
attempt record. No source path is moved/deleted/renamed and no ledger is
repointed. Combined search of tools, hooks, workflows, source/header includes,
build inputs and source registries found only the two intended includes of the
new header; both consumers verified together. Receipt:
build/codex4-prone-data-path-audit.txt. No active consumer needs repointing;
historical EA strings and protected registers stay intact. Keep the four file/
class claims until publication; release scope claims after confirmed landing.

Measurements: zero recovered C++ bytes, zero files removed (one private header
added), zero code/data identity or header debt retired.

## Other allocated triage and rejected trial

- DemoTrapUpdate: missing getModuleNameKey declaration blocks its pool-key
  donor. A declaration-only trial accepted the pair and byte-matched, but the
  seed update view is secondary-this (module/object accesses at -0x0C/-0x08)
  while the constructor demonstrates a distinct primary receiver and three
  vtables. Adding a virtual method to the secondary view does not establish its
  actual slot or reconcile that ABI. Reverted the complete trial; recorded
  blocked evidence for 0x00495935 through re_log.py and released both file
  claims. Do not repeat the declaration-only workaround. Receipts:
  build/codex4-demotrap-{new-before,key-after-trial}.txt.
- SupplyWarehouseCripplingBehavior: unchanged trial accepts pool/module-data
  pair (three rows) but rejects primary constructor with missing member/receiver
  declarations. No edits or claims; leave compatible donors to Luna.
  Receipt: build/codex4-supplycripple-before-trial.txt.
- OneRingPenaltyUpdate: unchanged normal trial accepts no pair. Module-data
  constructor's private raw-pointer fields conflict with the seed's AsciiString
  view; the destructor loses bytes; remaining donors need primary/secondary
  receiver/base declarations, and Coord3D header adoption is requested by the
  tool. No edits or claims. Receipt: build/codex4-onering-data-before-trial.txt.
- FloatUpdate: reviewed existing recorded trial and current source; missing
  static pool member and module-data explicit-vtable versus inherited class
  remain. No unchanged build repeated, no edits or claims.

TheMessageStream naming decision (#116) remains maintainer-owned and untouched.
