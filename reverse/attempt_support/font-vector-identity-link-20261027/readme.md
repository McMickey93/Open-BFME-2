# Font vector lifetime identity repair

Inspected BFME 2 revision: 5a987437d9f. Model: GPT-6.

The native FontCharsClass constructor at RVA 0x00157950 installs dynamic-vector
table VA 0x00BD3BE8 at member +0x10. Its unwind at 0x00767063 calls the
45-byte complete destructor at 0x00155330. That destructor installs base table
0x00BD3B98. The existing Rva00155940Element pointer specialization already
represents this pair in Rva00155940Vector.cpp and FontCharsClassDestructorBFME.cpp.
This is target ownership evidence; the original element class name remains unknown.

The separate VectorClass<FontCharsBuffer*> destructor at 0x00120FB0 instead
installs 0x00BD0D68. Assigning the FontCharsBuffer dynamic-vector destructor
to 0x00155330 therefore made the same base-vtable symbol resolve to two
different native addresses. A masked ICF match did not prove that identity.

The source now constructs the existing opaque pointer specialization. Explicit
instantiations retain the separately rowed FontCharsBuffer provider bodies.
No pin, global, shared header, compiler flag or source path changes. Existing
legacy FontCharsBuffer identities outside this lifetime edge are not resolved
by this bounded change.

## Reviewable withdrawal

The first commit withdraws the wrong dynamic-destructor row and its dependent
unwind admission, with tombstones. The original unique 45-byte extent remains
covered by the HLod row; the unwind's 11 bytes are deliberately withdrawn until
the next admission. The retained 12 rows and the data row pass the normal build;
frozen-definition preflight passes. Before the split, all 14 rows passed. The
trial preserves 12 rows and fails only because the old destructor symbol is gone
and the real destructor has not yet been admitted for the unwind relocation.

The follow-up must admit the actual existing Rva00155940Element dynamic
destructor as a whole-body ICF alias and readmit the parent-derived unwind.
Do not publish the temporary withdrawal by itself while that admission is viable.

## Linking scope

Before: constructor plus existing vector provider and font destructor all preview
LINKS, retaining 1477 authored nonpadding bytes against index 73061d9452
(2026-10-27 14:34). The printed historical 1432-to-1477 comparison predates
this repair and is not its gain. Post-admission verification is pending.
No new census-linked bytes, source-file recovery or runtime result is claimed.

## Verified readmission

The normal add_match path admits the existing opaque-pointer dynamic destructor
at 0x00155330 as a whole-body alias of the existing 45-byte extent, then the
actual compiler-emitted parent funclet $L3075 at 0x00767063. Both admissions
pass ordinary byte verification. All 14 rows and the data row are restored;
net unique matched-byte change is zero. The old wrong names remain tombstoned.
The withdrawal commit is 33382dfa51; its normal hooks passed 965/965 rows
across seven affected units and six EXACT EH graphs.

The official verify_dir32_consistency check on 25 current rows passes:
13 symbols, zero whitelisted and zero inconsistencies. This includes the
separate 0x00120FB0 base destructor and the 0x00155330 fold extent. The newly
admitted lifetime uses the BD3B98 specialization; the FontCharsBuffer base
symbol now has only its separately established BD0D68 operand in this scope.

All five ordinary previews pass together: constructor 850 bytes, opaque-vector
provider 240, FontChars destructor 387, render2dsentence 1249, hlod 15064.
The three-source before/after scope preserves exactly 1477 authored bytes.
The wider after scope retains 17790 bytes; its historical 17745-to-17790
printout is not an incremental gain from this repair. The same published index
73061d9452 is used throughout. No new census or runtime check was started.

This clears the proved two-address DIR32 lifetime conflict in the stated
25-row scope. Other legacy type names, the remaining global native-gate
conflicts, current census verification and the BFME 1 reference refresh remain
separate work. No new pins or baseline/whitelist entries were added.

## Publication gate limitation

The source repair and readmission landed as 8de0b1c21816f02f68da15c19db9f34bc2d75c9c
and f5a2184b8a73f0f1516231472b4f14f75d1627db. The normal pre-push byte
gate passes 78/78 rows across five sources and six EXACT EH graphs.
The batch linking-loss audit is explicitly UNVERIFIED: index 73061d9452
predates outgoing base 1bce3761a210a4c7adc9f9371831e7a4b0b58404 and lacks
per-object consumer names. It cannot establish whole-batch selected-provider
closure or absence of losses. Carry the five-source outgoing scope to the next
normal census with complete consumer metadata; the earlier scoped previews and
DIR32 result remain the limits of the repair evidence. No gate was bypassed.
