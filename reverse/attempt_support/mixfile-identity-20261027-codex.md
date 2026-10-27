# mixfile identity cleanup, 2026-10-27

Inspected BFME 2 revision `babdf751910f1545638d2ffbda7cfbcabe24cfc4`.
Scope: `Code/Libraries/Source/WWVegas/WWLib/mixfile.cpp` and the existing
`WWSaveLoad/VectorClassEnumValueResize.cpp` provider. Ordinary preview index:
`73061d9452`, published 2026-10-27 14:34, retail-truth-4.

The identity picker selected DynamicVectorClass's Clear at RVA 0x00156800.
The unchanged source passes all nine rows. After normally rebuilding the
stale `InlineDtorDeletingDtorsC01.cpp` provider (50/50 rows exact),
`repair_queue.py retire identity` removes six stale keys: the AddInfoStruct
constructor and destructor bindings in the vector constructor, and the
destructor callbacks in both Clear members, the vector destructor and its
scalar deleting destructor. The current identity scan proves these as folds
at 0x00154300 and 0x00001E13. No lifetime implementation changed here.

## Native resize binding

The remaining 47-byte DynamicVectorClass Resize at RVA 0x001567D0 calls the
384-byte native base resize at 0x00155690. That address is already owned by
`VectorClass<EnumParameterClass::_ENUM_VALUE>::Resize`. Both existing source
views describe eight-byte elements, with the surface pointer at +4 and the
same AddRef/Release copy operations. This is existing target layout and owner
evidence; it establishes no new original element name. In particular, the
Zero Hour AddInfoStruct and _ENUM_VALUE names are not independently recovered
BFME 2 record identities.

An inline explicit specialization of the dynamic resize retains its original
length/ActiveCount logic and calls the existing base owner through a cast
view. Declaration-only specializations of the opaque provider type's equality
and ID members prevent MSVC 7.1 from instantiating unrelated element operations.
The existing AddInfoStruct base Resize emission is preserved.

An initial specialization of the base Resize instead emitted a forwarding
COMDAT that made the ordinary preview fail on the selected copy. That trial
was replaced; no forwarding base body is retained. The final specialization
changes only the matched dynamic caller's binding.

## Verification and limits

- `./build.sh` passes all 11 rows across the caller and existing provider.
- `find_declared_unmatched.py` passes for mixfile.cpp.
- Comparison of the original and final objects finds the same 100 external
  definitions, with no addition or removal. All raw bytes, sizes and linkage
  stay identical. The only relocation change is the dynamic Resize's REL32
  at body offset 16, from the AddInfoStruct base spelling to the existing
  _ENUM_VALUE owner. All external data and all other provider bindings stay
  identical.
- `allowed_symbols.py --source` reports 30 references: 19 owner, eight fold,
  two EH and one wrong. The owning retirement tool removes the seventh key;
  one registered key remains.
- Paired ordinary previews retain 2/2 LINKS: mixfile.cpp 748 authored bytes
  and the base provider 394, totaling the same 1,142 bytes. This is debt
  retirement, with no new census-linked bytes or image-ownership claim.

The remaining key is the VectorClass<FileOffsetStruct> deleting destructor
at 0x00197410, whose element callback targets 0x00042FF8. Its StringClass-based
FileOffsetStruct destructor has the wrong extent for the native owner,
`NamedPivotMapClass::WeightInfoStruct::~WeightInfoStruct` (14 bytes, animobj.cpp).
The Zero Hour WeightInfoStruct owns a raw character array and deletes it;
the current FileOffsetStruct embeds a StringClass. A same-sized record is
insufficient to equate those lifetime contracts. Reconcile the element and its
emitted provider/consumer copies before retiring that key. No change to that
layout or destructor was attempted in this pass.

Carry the outgoing hook's batch-audit freshness result into the next normal
census. No maintainer-only measurement or runtime runner was started.
