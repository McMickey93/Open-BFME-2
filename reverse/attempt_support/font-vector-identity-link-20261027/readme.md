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
