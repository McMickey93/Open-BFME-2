# DX8 renderer category-list identity

2026-10-28; inspected parent `5ca3063071`; claim owner
`yasinschroeder-codexb5`; source
`Code/Libraries/Source/WWVegas/WW3D2/dx8renderer.cpp`.

The default picker served the existing constructor-binding identity debt at
0x00144E90. This is placeholder/type cleanup, not a lost-row repair.

## Target facts and retained change

The existing `TextureCategoryListDtor.cpp` owns the complete destructor at
RVA 0x001446F0 and deleting destructor at 0x00144870. The renderer's donor
`dx8list.h` instead aliases `TextureCategoryList` to
`MultiListClass<DX8TextureCategoryClass>`. Its array construction/destruction
callbacks therefore name another destructor, despite targeting 0x001446F0.

Use a local `TextureCategoryList` declaration with the existing out-of-line
destructor. Preserve the donor's other list aliases and supply the corresponding
typed iterator and inline operations over `GenericMultiListClass`. No row,
address owner, shared header, source path, pin or register entry changes.
The adopted class name is the existing ledger owner's spelling; the donor
typedef alone does not establish a retail debug name or original source path.

The emitted constructor is 39 bytes. At RVA 0x00143D40 it matches every byte,
including its sole DIR32 relocation at +34: the vtable at RVA 0x007D34E4
(VA 0x00BD34E4) has one deleting-destructor slot targeting 0x00144870.
`RetailTruth._judge` with `_comdat_sections`' recursively attached definitions
returns `retail` for both constructor and vtable. Reproduce using the ordinary
verified renderer object, locate `??0TextureCategoryList@@QAE@XZ` in
`link_census._comdat_sections`, and judge it at 0x00143D40 against
`RetailTruth(link_census.ledger())`.

The renderer and destructor provider emit identical vtable and deleting-thunk
COMDAT fingerprints: `7c9119d401b1` (4 bytes) and `2510fe76eb8a` (30 bytes,
including padding), respectively. This proof does not rename or repoint the
existing `LogicalDecalClass` constructor row at 0x00143D40.

## Verification and limits

- Ordinary before check: renderer/provider/decalsys 89/89 rows exact. After:
  renderer 86/86 exact, including its 20 compiler-label funclet rows; the two
  providers are unchanged. EH verification: all five renderer graphs EXACT.
  Frozen-file checks pass before and after (86 rows, 12 unclaimed inline
  definitions; all defined functions already matched).
- Identity references: 174 total before and after; owner bindings 138 -> 145,
  wrong/unknown 9 -> 2. Seven destructor references now name their ledger owner,
  including three unwind rows. Two constructor callback references still report
  wrong/unknown: `allowed_symbols.Obj.body` does not attach the recursive
  vtable definition used by the successful proof above.
- `repair_queue.py retire identity` refuses and changes nothing: 87 ledger
  objects are missing, 21 participating providers lack current receipts, and
  the newly spelled constructor is still an unknown binding. All three existing
  source identity keys remain registered. No debt retirement is claimed.
- COMDAT comparison against the verified original object removes 12 template
  providers and adds 11 typed providers. Three retained COMDAT digests change
  (the base constructor/destructor and skin constructor), due to their list
  references. Existing matched bytes remain verified; external consumers of
  removed template providers need the outgoing audit and next census.
  The saved index has no `touches` consumer-name table, so it cannot establish
  complete external consumer closure for those removals.
- Paired ordinary previews against index `14dc3d2467` (2026-10-28 02:44)
  agree before/after: destructor provider LINKS 126 -> 126 authored bytes,
  decalsys LINKS 39 -> 39; renderer reports historical 7,683 -> 0 with unresolved
  `BFME2RenderObjInheritedDataView::Get_Inherited_Render_Data`. Its existing
  provider is in `rendobj.cpp`, which the preview cannot place in its underlying
  `73061d9452` census. Do not call this preview a new regression.

Remaining: teach the identity verifier to carry a proved local vtable definition
with its constructor, with regression coverage in a separate tooling change;
refresh the required objects before attempting registered retirement. Recheck
renderer closure and removed-provider consumers in the next normal census.
No new census, image-ownership or runtime result is claimed.
