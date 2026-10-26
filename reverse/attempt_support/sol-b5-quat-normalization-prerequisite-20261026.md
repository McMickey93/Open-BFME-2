# Quaternion normalization prerequisite, Sol B5, 2026-10-26

Target: `Code/Libraries/Source/WWVegas/WWMath/quat.cpp`.
Allocated family B shard 1/2; queue lists this unheld TU. Normal file claims
cover the destination and all four donors. No merge or routing edit applied.
The parent-directory name_lane consolidation planner was reviewed and refreshed.

## Repair and measured scope

The ordinary guarded dry-run accepted the seed, bfme2_quaternion_nlerp.cpp
and slerp_setup.cpp (19 rows), but rejected QuaternionRandomize.cpp because
the included Quaternion declaration has no normalizeForRandomize member.
The private member existed only to inline the normalization into Randomize.
Expand that same C++ directly into Randomize and remove the member declaration,
out-of-line definition and its present-unmatched exemption. Its existing 217
bytes remain exact. Target XYZW stores and the rowed Normalize method establish
the layout; no complete donor layout or original helper identity is asserted.

Fresh ordinary `tu_skeleton.py --merge .../quat.cpp --dry-run` now accepts
those same three sources plus QuaternionRandomize.cpp: 20 rows, one additional
existing 217-byte donor body. This is a demonstrated declaration unblock,
not a Luna landing, merge, recovered bytes or linked-byte gain.

## Checks and provider evidence

- `./build.sh quat.cpp QuaternionRandomize.cpp`: 18/18 exact, 52 float literals,
  one import; separate companion build: 2/2 exact. All paths above share the
  WWMath parent. `find_declared_unmatched.py` passes for the changed donor/seed.
- `allowed_symbols.py --source` on seed/donor: six references, zero wrong
  bindings. Code identity staged check: one row, zero new findings, shadow mode.
- `data_check.py`: zero findings; `--converged`: ten addresses, zero second
  names or unjudged rows. Class gate and Microsoft header check pass.
- Before/after object facts from upstream allowed_symbols, link_census and
  data_check agree for all bindings, data, undefined names, external code bytes,
  relocations, COMDAT selections and flags, except removal of the unused private
  helper definition. A source/control/ledger search finds no remaining caller
  or declaration of that helper. No code/data identity register key is retired.
- Scoped composed object: eight code references unchanged; 41 selected-provider
  facts unchanged using upstream Identity/link_order; data binding/definition
  unions equal; no dropped definitions or new undefined names. No hand compile
  through build.compile_source or maintainer-only link runner was used.

Observer scripts/objects/receipts live under ignored `build/sol-b5-quat-*`.
The private helper removal accounts for the only standalone object difference.
The hatch tool's global update also proposed unrelated stale-key shrinkage;
retain only this repair's one removed exemption. Other baseline entries remain
as committed. Hatch baseline header permits shrink-only deletions, reverified
by the staged gate. Gate/data/identity/header registers otherwise unchanged.

## Remaining composition prerequisites

The composed object emits a 50-byte compiler vector-constructor iterator where
the standalone seed/slerp objects emit the retail 34-byte iterator. This exact
same changed COMDAT fact exists in the BEFORE 19-row composition and AFTER
20-row composition; this repair does not introduce it. Current selected-provider
facts remain unchanged and the ordinary census link guard accepts the subset,
but leave this emission discrepancy for a separate prerequisite before landing
an actual merge. No correct-emission or full link-closure claim is made.

quat_BuildMatrix4.cpp remains rejected as `no baseline match` under the carried
SSE2 override; its source explicitly documents matching only with SSE. Do not
weaken flags, drop rows or re-add optimization hatches to force it into this TU.
The four-source accepted subset is left for Luna subject to provider-emission
reconciliation and its normal full acceptance checks.

## Batch audit and handoff

At inspection `origin/master` equals `bf442a3f7b`. The complete outgoing batch
plus staged repair contains no source-path moves, ledger repoints or changed
active path consumers. Active tools/hooks/workflows/includes/build inputs and
registries require no path repair; original EA paths remain intact. CSV and
diff whitespace checks pass. Planner refreshed after the scoped baseline update.

Inherited Bridge/PropDraw prerequisite commits were confirmed upstream and all
eight inherited file claims released, plus `claims.py release --landed`.
No new inherited recovery work is attributed to this trial.
Official BFME1 was fetched during pull: upstream 89abf6447dcf26092986ecca11444770a004e3ee;
retained clean verified input remains 001ccd8e27686e9887235b62ff797627f2dde7f5.
Full reference-update verification remains outstanding; no freshness success
receipt or reference advance is claimed.

File reduction 0; code-identity debt retired 0; recovered C++ bytes 0;
present-unmatched hatches removed 1. Keep the changed donor and evidence claims
until publication; release unused destination/companion claims on handoff.
