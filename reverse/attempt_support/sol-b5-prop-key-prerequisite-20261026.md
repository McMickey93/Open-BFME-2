# PropDraw cached-key declaration prerequisite, 2026-10-26

Seat codexb5, family B repair shard 1/2. Runner allocation authorizes
Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DPropDraw.cpp.
The scoped Draw planner was read before the trial, then regenerated after the
final edit; its input/output currency check passes. Current tu_skeleton --plan
rebuilds the stale map in memory: 15 approved rows, four clean sources and three
mixed sources. No map, ledger, register or source path was changed.

The seed used Zero Hour's W3DPropDraw.h, which lacks BFME 2's already-rowed
rva000CEEE6 static method. Its declarations are now scoped to this TU with that
one method added; the original header's two includes, base classes, macros,
virtual methods, field types/order and access remain intact. This recovers no
name or layout. The module-data view is unchanged.

Before: ordinary --merge --dry-run accepts nothing. After: seed plus complete
W3DPropDrawPoolKey.cpp donor, seven rows, including the existing 69-byte method
at 0x000CEEE6 and its 10-byte handler at 0x00762717. This is a demonstrated
prerequisite unblock, not a merge or a confirmed Luna landing. Leave it to Luna.

Verification (ignored receipts/scripts: build/sol-b5-prop-*):

- ./build.sh on seed, module-data ctor and key donor: 9/9 exact, one string,
  one data row; final seed 5/5 exact. find_declared_unmatched passes all three
  before and after; the seed's three admitted markers are unchanged.
- Before/after allowed_symbols, link_census COMDAT facts and data_check object
  facts: all nine rows, 13 code references and every external definition,
  undefined symbol and data fact identical. Only compiler-local EH label
  ordinals are normalized. allowed_symbols CLI: zero wrong bindings.
- Ordinary dry-run accepts seven rows. Its cached Verifier.effective composition
  object supplies 51 external code definitions, no added/dropped definition,
  no new undefined symbol, no divergent scoped copy. All 12 row code bindings
  are identical. Fifty providers have identical upstream fingerprints and
  COMDAT facts. The remaining getClassMemoryPool provider has identical 69
  raw bytes and relocation offsets/types/targets except its compiler guard
  ordinal S18 -> S46. Both guard definitions are zero four-byte writable
  COMDATs with identical storage and selection; enclosing method identity is
  unchanged. No arbitrary symbol/name normalization was used.
- Eight composed data bindings agree except the existing cached-key guard's
  compiler ordinal S1 -> S47 at the same retail RVA 0x009EBBC4. Both definitions
  have the same zero four-byte data, flags, storage and COMDAT selection.
  Defined-data sets agree. The existing wrong-name data debt is preserved,
  not retired on the basis of this ordinal comparison.
- class_gate passes; EH EXACT 2/2, no baseline exceptions or missing objects.
  data_check: one existing finding, zero outside baseline. Neither changed
  seed nor the module-data ctor owns identity debt or header-queue entries.
  The untouched React donor retains its Coord3D header queue finding.
  check_csv and git diff --check pass.

## Withheld fog-field trial

Adding the constructor's existing m_distanceFog byte to the seed declaration
also admits the module-data ctor (nine composed rows), but that composition
introduces 9-byte BfmeModuleDataSnapshotBase/ModuleData constructor providers
and drops Snapshot providers. Those are real provider-identity changes, unlike
the guard ordinals above. The field addition was removed; no ctor donor edit
was retained. Verdict recorded via re_log.py at 0x000CEF2B. Preserve this
boundary when tackling its ModuleData/Snapshot ABI prerequisite. React still
rejects with C2011 Coord3D redefinition; its by-value lifetime/ABI work remains
separate. The three Common mixed sources belong to family A; none was claimed
or edited. MessageStream issue #116 remains outside this work.

## Batch audit and freshness

Audited origin/master..HEAD with the outgoing common-ancestor range plus the
staged seed/log/handoff; upstream-only changes are excluded. No pending source
moves, registry/build-input/path changes or active tool/hook/workflow consumers
need repointing. The two direct includes replace the same transitive includes
of the old header; all standalone object facts are preserved. Original EA paths
remain historical. Registers and source ownership stay unchanged.

Inherited f23698e816 is confirmed on origin/master; its seven remaining tree
claims were released. Official BFME 1 master was fetched: clean retained
001ccd8e2768 is 17 commits behind e71d1bbcdfea. Full cross-repository update
verification remains incomplete; no success receipt or pointer change was made.
No maintainer-only link, smoke or nightly runner was started.

Measurements: file reduction 0, identity debt retired 0, data debt retired 0,
recovered C++ bytes 0, census LINKED increase unmeasured. Hold the three source
file claims and this evidence claim until publication, then release them.
