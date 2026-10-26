# W3DGameFont cache declarations, 2026-10-26 (codexb)

Allocated family B shard 0/2 destination:
`Code/GameEngineDevice/Source/W3DDevice/GameClient/GUI/W3DGameFont.cpp`.
Parent inspected: `c326db5466`. Runner `--check-tu` authorizes this destination.
The current GUI naming planner records ZH/same-name and contiguous-range hints,
not recovered BFME2 source paths. `tu_skeleton.py --plan` rebuilds the stale
routing map in memory: 17 approved rows, four ordinary sources, one mixed
WWLib container source. No TU map, row ownership, merge or split is changed.

## Verified prerequisite

The ordinary dry-run previously rejected W3DFontCharsCache.cpp because the
seed's donor header declared only three-argument, integer-point-size font
methods. A signature-only local copy exposed two further target mismatches:
that donor class allocates 0x468 bytes through its pool allocation operator;
the rowed retail worker at 0x0009017D allocates 0x464 through ordinary new.

The seed now includes a local rendering declaration closure, based on the
existing ZH Render2DSentence sweep header at BFME1 revision
001ccd8e27686e9887235b62ff797627f2dde7f5. Its FontCharsClass view uses the
observed four arguments (float point size), ordinary allocation, refcount
at +4, alternate font at +8, and total size 0x464. A compile-time size check
protects that boundary. Other private fields are opaque. RefCountClass
inheritance is a structural view supported by the existing release/refcount
operations; it does not claim recovery of BFME2's original header. Rendering
declarations are retained to preserve the seed's existing compiler providers.
The cache helper name and data owner remain unchanged.

Acceptance evidence:

- Before: `./build.sh` over W3DGameFont, W3DFontCharsCache,
  W3DFontLibraryDestructor and W3DFontLibraryLoadFontData (full GUI paths)
  passes 15/15 matched rows, the data row, literal and empty-string checks.
- After: the complete four-source build passes 15/15 ledger rows, its data row,
  one literal and one empty-string reference. Seed/cache alone passes 11/11.
  All four source objects have identical external providers before/after.
- `find_declared_unmatched.py` over all four: all definitions already matched
  (the destructor/loader retain their existing unclaimed-definition notices).
- `data_check.py` seed/cache: zero findings; `--converged`: ten addresses,
  zero second names or unjudged rows.
- Scoped `code_identity_gate.check` over all four: shadow, 15 rows,
  26 findings, zero outside the current baseline. Registers and findings are
  retained; no identity debt is retired.
- `link_check.py --new-variants --staged-peers --shadow` seed/cache passes.
- `link_check.py --prepare-current` seed/cache: two explicit providers byte
  verified with strict reusable receipts; no census/index/status change and
  no claim of LINK closure. The first preparation ran alongside temporary
  composition sources and correctly refused moving inputs; the clean retry
  passes after those trials finish.
- `class_gate.py` local header, CSV and case checks pass.
- Refreshed GUI planner and `name_lane.py consolidate --check
  build/consolidation/font`: snapshot inputs and outputs agree.

`build/codexb-font-before.json` names preserved baseline objects.
`build/codexb-font-provider-proof.py` uses allowed_symbols Obj/body and census
COMDAT selection APIs, including normalized local relocation referents.
The 11 seed, 19 cache, four destructor and three loader external code/data
providers are identical in bytes, relocations, section flags, COMDAT selection
and undefined names. Thus the published prerequisite changes no selected
provider or consumer binding, including consumers outside this TU.

## Composition boundary: do not merge yet

`tu_skeleton.py --merge <destination> --dry-run` now accepts the seed and cache
and reports nine approved rows; the destructor and loader remain rejected.
The scoped upstream Verifier composition of seed/cache matches all nine
approved row addresses, including both EH rows; the cache parent EH graph is
EXACT. This clears the method/size/allocation compile and byte prerequisite.
The standalone two-source build also checks the two existing alias rows.

The complete composition audit still finds a changed shared provider:
`??1?$SimpleDynVecClass@PAVFontCharsClass@@@@UAE@XZ` changes from a 69-byte
body with __EH_prolog, __except_list and an EH cleanup to a 35-byte body without
that cleanup. Both use the same vtable, array-delete and base-destructor names,
and COMDAT selection 2, but they are different providers. No provider is lost;
all other existing providers are exact. The composition also emits the
four-byte const RefCountClass::Add_Ref helper (`ff 41 04 c3`); it introduces no
undefined name. These facts do not authorize changed provider selection.

The Code and BFME1 simplevec templates differ only in whitespace. Moving the
seed's simplevec include before stdlib/new in a scratch compiler trial did
not restore the EH provider. That hypothesis is exhausted. The original
69-byte provider remains in the production cache object. A future prerequisite
must prove the target exception/deallocation contract and verify the resulting
provider plus affected consumers. Do not treat matching row bytes or an old
census as that proof. The composed trial remains unpublished.

The destructor donor still has private SimpleVecClass/SimpleDynVecClass and
W3DFontLibrary conflicts. The loader still has incompatible GameFont fields
and ABI declarations. Four mixed WWLib rows remain with their current owner.
No unchanged blocked donor was edited. No maintainer-only link cycle, smoke
test or nightly measurement was run.

## Audit and measurements

There are no outgoing commits preceding this repair. Pending paths are one
in-place source include edit, its new local header, this evidence and the
append-only attempt log. No source is moved/deleted and no ledger or protected
register changes. The new quoted include resolves beside the seed; active
tools, hooks, workflows, includes and build inputs require no repointing.
Historical EA paths and old evidence remain intact. Header and Microsoft
queues have no entry for the four font sources. Data and code debt ownership,
existing aliases, fold proofs and compiler flags are retained.

File reduction: zero. Debt retired: zero. Recovered/authored C++ bytes: zero.
This is a verified declaration prerequisite with an explicitly unresolved
provider boundary, not a confirmed Luna merge or census improvement.

Receipts: `build/codexb-font-{before,after}-build.txt`,
`build/codexb-font-{before,after,fixed}-trial.txt`,
`build/codexb-font-{composition,order}-diagnose.txt`,
`build/codexb-font-provider-proof.txt`, `build/codexb-font-identity.json`,
`build/codexb-font-after-link.txt`, `build/codexb-font-final-build.txt`,
`build/codexb-font-current-receipts.txt`. Keep the seed/header/evidence claims until
publication is confirmed; release unchanged donor claims after the trial.

## Inherited publication recovery

Revalidated on 2026-10-26 against upstream `093a4702be`: the four-source
`./build.sh` passes 15/15 rows and its data/string checks with current receipts;
the seed frozen-source check passes. Re-running
`python3 build/codexb-font-provider-proof.py` confirms all 37 standalone external
providers and their bindings are still unchanged. The retained composition
trial still demonstrates the same unresolved SimpleDynVec destructor boundary;
no new composition or merge is attempted. CSV and `git diff --check` pass.
The complete inherited outgoing range contains no path moves/deletions or
protected-register changes. The sole new-header include still resolves beside
the seed; no active tool, hook, workflow or build input requires repointing.
The three existing file claims remain held pending publication.
