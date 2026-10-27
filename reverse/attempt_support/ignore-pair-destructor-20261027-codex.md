# Ignore-list pair destructor: exact fold still needs provider reconciliation

Inspected BFME 2 `6f3fa807a0021af812da87c775c9bd7abbb979c1`, ordinary
preview index `73061d9452` (2026-10-27 14:34, retail-truth-4). Selected source:
`Code/GameEngine/Source/Common/UserPreferencesDeferredIgnores.cpp`.
Related obstacles: LINK-064 and LINK-095. All source and ledger trials were
reverted. This handoff adds no coverage, linked bytes, pins or debt retirement.

## Target facts

Retail RVA 0x0029D7C2 is the complete eight-byte `add ecx,4; jmp`
`StringBase<char>::releaseBuffer` body, targeting RVA 0x00036410. Its existing
owner is `CameraMarker::~CameraMarker` in `CameraMarkerListFind.cpp`.
Retail funclet 0x0077FA71 is eight bytes: `lea ecx,[ebp-1Ch]; jmp 0x0029D7C2`.
The matched 132-byte `map<int,AsciiString>::operator[]` at 0x00385C19
constructs its pair temporary at that stack address. `eh_verify.py` binds its
two-state graph exactly, independently of the generated funclet row.

Current objects emit the same pair destructor spelling in exactly four
definition providers in this index. All four bodies are `83 c1 04 e9` followed
by a REL32 operand at offset four. Their relocation identities differ:

| Provider | Call target |
| --- | --- |
| Common/UserPreferencesDeferredIgnores.cpp | `StringBase<char>::releaseBuffer` |
| Common/Rva00566695Assign.cpp | `StringBase<char>::releaseBuffer` |
| GameClient/GUI/GUICallbacks/Menus/WOLBuddyOverlay.cpp | `AsciiString::~AsciiString` |
| GameNetwork/GameSpy/PeerDefs.cpp | `AsciiString::~AsciiString` |

The latter target is the separate five-byte thunk at RVA 0x0003640B. Equal
masked bytes therefore do not establish interchangeable link identities.
These object facts and the target EH graph support a genuine pair-destructor
fold; they do not identify either larger placeholder map's retail value type
or establish an original BFME 2 translation unit.

## Rejected trials and verification

1. `add_match.py --icf-owner '??1CameraMarker@@QAE@XZ'` admitted the existing
   compiler-emitted pair destructor at 0x0029D7C2. No source or pin changed.
   The normal byte build passed all 14 rows. Replacing `uw_0077fa71` with the
   parent's `$L6901` through `add_match.py --replace-rva` then passed 15/15,
   with the complete eight-byte cleanup and its relocation verified.
2. This removes the destructor conflict from the ignore and assign units, but
   adds that conflict to WOLBuddyOverlay and **regresses PeerDefs from LINKS
   (7,181 bytes) to blocked**. The ignore unit remains blocked on `_M_insert`
   and `getIgnores` selected-body identities. A unit-only preview misses the
   regression. Do not land the fold and funclet rows alone.
3. A plain explicit destructor-specialization declaration in the two thunk
   providers (`template <> pair<const int, AsciiString>::~pair();`) preserves
   all 151 rows across those units, but MSVC 7.1 still emits the implicit
   destructor with the thunk relocation. The four-provider preview remains
   regressed. This declaration is not a remedy; both additions were reverted.
4. Restoring all production sources and the ledger passes **164/164** rows
   across the three inspected consumer sources. The final paired preview
   restores PeerDefs to LINKS (7,181 bytes), the original ignore C3/S2, and
   the other two units' original blockers. CSV validation passes at 98,522
   function rows. During the trials all 33 EH graphs across the three
   consumers were EXACT, with no baseline or missing objects.

Raw native disassembly, before/trial/restored previews, restored build and EH
receipt: [receipts](ignore-pair-destructor-20261027-codex/).
The previews intentionally exit 1 for known blockers. They are predictions,
not a census or image-ownership measurement. No generated source was edited.

## Next boundary

Reconcile emission and references of the shared pair destructor across all
four providers before admitting the fold or moving this generated cleanup.
Preserve PeerDefs' linking status with a paired provider/consumer check.
The two thunk providers use `BFME_ASCII_DTOR_DECL`; changing that setting
globally was not attempted and could change many independently matched rows.
Do not add an alias, import indirection, wrapper or pin to hide the mismatch.

The wider ignore-family prerequisites remain: `getIgnores` calls native
tree copy 0x003B1EBB, already owned by the `Rva003B1EBBElement` tree, whereas
its current decorated constructor owns 0x0052D25D. Native insertion
0x00383BAC is rowed under an int/int identity. The historical fake
`map<int,AsciiString>` family is itself split: node factory 0x0050116B
reaches the 24-byte `Rva0050055D` holder, while clone 0x005041D8 reaches
the distinct seven-dword `Rva00064640Record28`. Keep the two families
separate; see `map-fake-family-split-20261024.md`.

Publication audit: the outgoing range through this handoff has no renamed,
removed or moved production source path, and this attempt leaves all ledger,
provider, register and generated-source ownership unchanged.
