# OneRingPenalty module-data declaration prerequisite (2026-10-26, codex4)

Target: `Code/GameEngine/Source/GameLogic/Object/Update/OneRingPenaltyUpdate.cpp`.
Inherited four scope claims were renewed before work; runner allocation
`consolidation_queue.py --check-tu` authorized this destination. The Update
`name_lane.py consolidate` packet was reviewed and its fingerprint check passed
before editing. This is a declaration prerequisite, not a merge or new recovery.

## Verified improvement

The seed described the +0x08 member as AsciiString and exposed the spawn-helper
fields. The ctor donor independently described it as a private raw pointer.
A shared local view now preserves the explicit vtable word, the existing scalar
offsets and the +0x20 holder representation. The AsciiString default constructor
replaces the explicit null assignment with identical retail constructor bytes.
Retail ctor 0x004999F1 establishes stores; the existing verified destructor
0x00499A16 establishes string destruction and the +0x20 ref-counted holder.
This view deliberately does not model the separate virtual destructor/base.
No donor source, EA path string, row owner, pin or register key moved.

A scoped trial using the original texts and current routing through
`tu_skeleton._merge(..., dry_run=True, texts=originals)` refuses the two-source
composition: private access to m_specialObjectName. After this change the normal
`python3 tools/tu_skeleton.py --merge <target> --dry-run` accepts the seed and
OneRingPenaltyUpdateModuleDataCtor.cpp, all five rows. This demonstrates one
new compatible donor; it does not claim a Luna landing or header adoption.

## Verification and bindings

- `./build.sh <target> <ctor>` before and after: 5/5 exact; one literal and one
  float reference verified. `find_declared_unmatched.py` on both: clean.
- `class_gate.py` on both sources and the header: clean; `git diff --check`: clean.
- `allowed_symbols.py --source <target> <ctor>`: 14 references, 11 owners,
  two aliases, one EH, zero wrong bindings.
- `data_check.py --converged <target> <ctor>`: two sources, ten addresses,
  zero second symbols and zero unjudged findings. `eh_verify.py` verifies the
  single EH row EXACT, with no missing/not-exact/baseline case.
- `./build.sh Code/Libraries/Source/WWVegas/WWLib/ascii_string.cpp
  Code/Libraries/Source/WWVegas/WWLib/StringBaseWideReleaseBuffer.cpp`: 22/22
  exact, six import references verified.
- Fresh scoped objects compiled outside build/match using
  `build.try_compile_source(..., inventory=True)` for both consumers and both
  string providers; all four pass `compile_is_current(..., strict=True)`.
  Ordinary build objects were not manually compiled or overwritten.
- Scoped object comparison (`build/codex4-onering-proof.py`): every existing
  code definition/digest/size/exclusivity and external data definition remains
  unchanged. New AsciiString ctor/dtor copies exactly match the verified
  ascii_string.cpp provider (ANY COMDAT selection 2). The composed object
  `build/tu_skeleton/b5068f2fd740070a.obj` equals the standalone union: ten code
  definitions, two external data definitions, 27 unresolved references. All
  five rows preserve their DIR32 bindings before/after and in composition.
- `build/codex4-onering-provider-proof.py` compares scoped overlays with fresh
  provider objects: selections for the module-data constructor, AsciiString
  ctor/dtor and releaseBuffer are unchanged. The new destructor copy has full
  RetailTruth byte/relocation verdict `retail`. The existing releaseBuffer
  provider has verdict `unknown` in this narrow identity scope, not `wrong`;
  its unchanged selection and 22-row provider byte build are recorded separately.
  The saved census baseline is provisional, not a fresh linked-byte receipt.
  No new linked coverage or complete global identity proof is claimed.

## Remaining prerequisites and accounting

Coord3D remains in the seed's existing header queue; dry-run still prints
`adopt_first: Coord3D`. Keep that key and use header_adopt_lane's acceptance
path before landing the eventual merge. Other donors still fail on missing
receiver members, Object/Thing views or destructor byte composition. The current
trial lists three mixed donors and does not authorize manually splitting them.
No data/code-identity keys exist for these two files; none were retired.
The destructor's different Snapshot/base representation remains untouched.

Path-consumer audit at base 4be7761855: no unpublished local commits and no
source moves/deletions. Searches across tools, hooks, workflows, Code and the
identity/header registers found exactly two consumers of the new local header;
both were verified together. Existing source-path mentions, original EA paths,
ledger owners and Coord3D queue entry remain valid. Incoming remote commits are
not part of this local prerequisite batch. No TU map or baseline was regenerated.

Accounting: five existing matched rows preserved; recovered bytes +0; source
file reduction 0; one shared local header added; identity debt retired 0.

The RiderChangeContain broad trial was stopped without edits after finding the
existing handoff documenting its unchanged Xfer/AsciiString and containment ABI
blockers. The redundant five-minute probe is recorded through re_log.py; do not
repeat it until those prerequisites change.
