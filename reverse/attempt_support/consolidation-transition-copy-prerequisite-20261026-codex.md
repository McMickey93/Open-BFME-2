# TransitionDamageFX copy-forwarder prerequisite

Seat codex, family A shard 0/2, 2026-10-26. Runner allocation authorizes
`Code/GameEngine/Source/GameLogic/Object/Damage/TransitionDamageFX.cpp`;
both it and its Common copy donor were claimed. Inspected upstream 9e2d22764b,
stacking on TunnelTracker prerequisites c7adaf7e0f and 6bba851517.

## Concrete blocker and repair

The ordinary baseline trial accepts no merge. CopyRange fails C2011 because
it redeclares STLport's random_access_iterator_tag and defines another __copy
template beside the seed's real STLport header. It also carries an unnecessary
private 0x2C record declaration. The forwarder now includes the real iterator
tag and declares its existing out-of-line template provider. Its body and
noinline contract stay unchanged. The seed explicitly instantiates the real
50-byte __copy at 0x004BA2E9; the donor's duplicate was byte/relocation identical.
No compiler flags, pins, aliases, hatches, layouts or names were invented.

## Acceptance and binding evidence

- Before and after `./build.sh TU Code/GameEngine/Source/Common/Rva004BA324CopyRange.cpp`:
  **29/29 exact**, including eight existing alias rows. Six funclet pins pass,
  as do string/float/import checks. Both frozen checks and the class gate pass.
  Converged data: ten addresses, zero second names or unjudged rows. Standalone
  and composed `eh_verify.py` both report **EXACT 1**, no missing objects.
- Paired supported COFF readers show the standalone scope retains exactly
  **57 external code definitions**, identical fingerprints, sizes and COMDAT
  policies. The only removed duplicate is the seed-owned __copy; no unique
  provider is lost or changed. Undefined references after internal resolution
  agree. Data reference/definition facts agree. Allowed-symbol scans retain
  **46 owner references**, no added/removed fact. Existing seed AsciiString
  identity findings remain registered; no debt is retired.
- Ordinary `tu_skeleton.py --merge TU --dry-run` now accepts seed and copy
  donor: **21 non-alias rows / 1,261 existing bytes**. The same source scope's
  29 ledger rows include eight aliases / 76 bytes, not additional coverage.
  This unblocks one 29-byte donor for Luna; no actual merge was applied.
- Its ordinary object `build/tu_skeleton/2defa20dab6fc507.obj` has the same
  **57 external code definitions**, one data definition, all code fingerprints,
  sizes, COMDAT policies, normalized data facts and external references as the
  donor union. No missing/new/changed provider or changed binding.
- Raw trial directives omit the standalone fallback from the templated __copy
  name to the non-template __copy name. This is inactive: the templated source
  name is actually defined in both objects with identical fingerprint/size.
  No added alias or change to a used alias is present. The initial scratch
  comparison required identical directive sets; the detailed comparison records
  this difference explicitly rather than claiming identical directives.
- Strict `link_check.py --prepare-current --paths-from
  build/codex-session7-transition-copy-sources.txt` verifies both providers,
  29/29, with reusable receipts; scoped `--new-variants` passes. No census,
  ownership receipt, selected-provider gain or link-closure gain is claimed.

Scratch `build/codex-session7-transition-copy-*` retains before sources/objects,
builds, ordinary trials, provider/data/reference/composition proofs, standalone
and composed EH checks and strict receipts. Supported readers are from
allowed_symbols, data_check, link_check and tu_skeleton; no hand compile.
The scoped planner was regenerated at
`build/consolidation/transition-copy-session7` after the trial and its currency
check passes. Original-path evidence is a lead; current routing approves moves.

## Pending-batch audit and remaining prerequisites

Audited all pending paths from origin/master through the two TunnelTracker
prerequisites plus this staged source/doc change. No source is moved, renamed,
deleted or added; no protected register changes. Combined path/basename searches
cover active tools, hooks, workflows, includes, build inputs, registries and
documentation. The real STLport header already belongs to this source's
compile environment; no consumer needs repointing. Both provider and consumer
were verified together. Current owners, debt keys and historical EA paths stay
valid. File reduction, recovered bytes and identity debt retired are all zero.

Other ordinary trial rejections remain: Xfer has duplicate enum values and
receiver conflicts; Rva004B9DA9/ctor/dtor need compatible FDE/record members;
pool-key needs its receiver declaration; erase-range and ModuleData destructor
fail bytes; append/map-load retain allocator/linkage conflicts. Mixed donors
remain untouched. These are prerequisites, not missing coverage regressions.

The shared linking-obstacles document remains held by another worker (claim
refused twice during this session). Carry this supported 21-row acceptance and
the TunnelTracker 12-row acceptance into its next handoff. No maintainer-only
measurement or runner was started; inconclusive batch-audit inputs still await
the next normal census.

Keep these three file claims until publication is confirmed: TransitionDamageFX
seed, Common/Rva004BA324CopyRange.cpp and this handoff. Also retain the seven
TunnelTracker scopes and inherited writer handoff listed in the preceding
handoff. Release scopes after landing and settle RVAs with release --landed.
