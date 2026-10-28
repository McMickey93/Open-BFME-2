# AIBuilder Object-pointer vector append context

2026-10-28, inspected d6a91b0f7e6; preview index 41c28839bf (11:08).
The picker served HordeContainIface11CSlots.cpp at 0x00468AEC and claimed
its file. The complete file passes 165 rows. Its current ordinary preview
has exactly three selected-copy blockers: vector<Object*> destructor,
push_back and _M_insert_overflow, all selected from AIBuilder.cpp. This is
existing provider debt, not an unrowed body. No source edit is retained.

AIBuilder was unclaimed and was separately claimed before investigation.
The earlier destructor trials are in object-vector-destructor-selection-
20261028-codex3.md. They were not repeated. This pass tests the separate
append/overflow compiler context against AIBuilder's 29-row control.

## Target facts and trials

The existing append owner is RVA 0x001F211B, 58 bytes, in
StlportVectorPushBackSiblings.cpp. Its overflow owner is 0x001F2155,
147 bytes, in StlportVectorObjectPtrInsertOverflow.cpp. AIBuilder's copies
are respectively 49 and 140 bytes and are proven wrong by RetailTruth.
The parent checkForNewUpgrades at 0x004ECA01 calls append out of line.
The source template definition nevertheless affects the parent's generated
register use and cleanup. No donor class identity is inferred from these facts.

All configurations use normal build.sh; no manual build.compile_source call.

| Trial | Result | Boundary |
| --- | --- | --- |
| Import/forceinline append and declaration-only overflow | 28/29 | Inlines the append where retail calls it; changes the parent body. |
| Declaration-only append | 28/29 | Call remains; second loop and final cleanup stop retaining the original start pointer in edi. |
| extern-template append | 28/29 | Same parent loop/cleanup change as the declaration-only form. |
| Declaration-only overflow, original append visible | 28/29 | Parent still changes; retaining append alone does not preserve the needed compiler context. |
| Original source with /Oy- | Aborted verification | Changes moneySaverUpdate and makes unRegisterProducedObject exceed its row extent; not a unit-wide flag repair. |

The inline template's alias/escape information is a structural explanation
for the retained start pointer, not independently proven compiler internals.
A future repair must preserve the parent and its cleanup together with
the native operation providers. Destructor/allocator lifetime remains the
separate documented prerequisite. No provider order, pin, alias, pragma
optimization or selection exception was introduced.

## Restoration

Both sources are restored byte-for-byte. The complete restored build passes
194/194 rows, ten strings plus two empty references and fifty float literals.
All seventeen EH graphs are EXACT. AIBuilder's 89 normalized row-reference
records equal the saved control; all COMDAT digests/verdicts, external
definitions, undefined names and weak aliases equal the original object facts.
The served unit still has the three selected-copy blockers; no linking gain,
debt retirement, source conversion, census result or runtime result is claimed.

Raw trial and restored checks are retained here. Original objects and full
source controls remain scratch under build/resume-eh-local/turn83; they are
not new source providers. Scope claims are released after banking this handoff.
