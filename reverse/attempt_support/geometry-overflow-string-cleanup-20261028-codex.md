# Geometry record overflow string cleanup

Inspected BFME 2 revision: `48da62f9b249333b5e5e454fefa4dfe98cc3bb30`.
BFME 1 reference: `e74410b3738a2bb75d626085d9ebfd3406a43ff7`, with the
2026-10-27 verified freshness receipt. Ordinary preview index: `41c28839bf`,
2026-10-28 11:08, retail-truth-4.

The default picker claimed Snapshot header adoption. LINK-098 and LINK-092
already establish why MoneyVectorPushBack.cpp cannot adopt the engine base:
its 59-byte row operates on the 36-byte geometry record. Current inspection
confirms the same eight preview blockers; that file and its queue remain
unchanged. Its actual copy and overflow providers already link. No new
application name, donor layout or Snapshot interface is inferred here.

The separately claimed overflow provider at 0x006BF5E0 used a BfmeTailBE
releaseBuffer linker alias for the record's owned string at +0x1C. It now
uses the shared AsciiString member and explicitly destroys that member
before releasing the buffer. The existing constructor-side record view
also uses AsciiString instead of void*. The nested scalar layout, copy and
fill workers, allocator and compiler flags are unchanged.

The normal byte gate preserves the complete 268-byte function. The two
original external bodies have identical bytes and relocation targets after
resolving the removed alias to its existing StringBase::releaseBuffer target.
No exclusive definition is added or removed. The header emits a five-byte
AsciiString destructor and a 30-byte scalar deleting helper; the latter is
not newly rowed or claimed as retail code. The ordinary preview keeps the
existing retail-selected destructor helpers. The undefined-name changes are
the direct releaseBuffer spelling and operator delete for that extra helper.
[Object comparison](geometry-overflow-string-object-20261028-codex.json).

Checks:

- Before/after ordinary previews over MoneyVectorPushBack, the overflow,
  construction workers, vector fill-insert, geometry bounds/parser and string
  copy providers retain five of six LINKS and 5,442 authored bytes. Money's
  eight blockers are unchanged. No census-linked gain is claimed.
- Normal build passes 1/1 function rows and all string, float and import
  checks; frozen-file and class checks pass. EH verification finds no EH
  data in this source. Strict provider preparation passes with a reusable
  receipt. Shadow data has zero findings; converged data has zero second
  names or unjudged rows.
- The owning hatch tool lowers alternatename occurrences from 2,919 to
  2,918, removing only this source's releaseBuffer alias key.

Remaining: reconcile Money's false container identity with the actual record
family and retire its queue entries through the owning tools. Construction
and fill-insert retain their separate copy-constructor aliases. No source
path, function ledger, pin or shared header is changed. Scratch logs and
objects are under build/geometry-overflow-cleanup/.

The outgoing staged-tree batch audit is INCONCLUSIVE: its index predates
this base and affected consumer Common/0CreateAHeroManager21FE49.cpp lacks
a current receipt. This does not establish full external consumer selection.
Carry the removed alias and added shared-header helpers into the next normal
census; no runtime or image-ownership result is claimed.
