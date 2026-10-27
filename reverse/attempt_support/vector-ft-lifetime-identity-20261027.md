# VectorClassBfmeThingFTResize callback identity

Inspected BFME 2 revision: `8d40677f30`; ordinary-preview index:
`bf3dd31211` (2026-10-27 00:39, retail-truth-4).

## Target facts

The 345-byte resize row at RVA `0x00155490` passes callback addresses to
both array-constructor paths: constructor `0x006CE7D0`, destructor
`0x00001DAC`. Array deletion uses the same destructor. The constructor is
nine bytes (`8b c1 c7 00 00 00 00 00 c3`): return this and clear its first
word. The five-byte destructor is a tail jump to `0x00176CB0`, already rowed
as `W3DRadarResetSurface::~W3DRadarResetSurface`. The thunk itself is already
rowed as `RenderSentenceGeometryView::~RenderSentenceGeometryView` in
Render2DSentenceClassRva00156540.cpp. Neither address needs a new owner or pin.

The previous empty local constructor was three bytes; its empty destructor
was one byte. The current identity scan found both callback bindings wrong,
although only the constructor was registered (one baseline key). The original
ordinary preview still reported LINKS, 345 authored bytes; that preview alone
did not certify callback identity.

## Repair and structural inference

Use the existing surface-holder view as the first member of the 36-byte
BfmeThingFT view. Its constructor clears the pointer, and member destruction
calls the rowed surface destructor, naturally producing the complete native
five-byte thunk. The remaining eight payload words retain their offsets.
This composes the observed lifetime; it does not recover the record's original
name. The BFME 1 comments in the existing source describe donor provenance,
not proof of a BFME 2 type name.

An ordinary inline holder constructor introduced an additional COMDAT whose
name lacks a retail placement and disagrees with the historical index's first
copy. The retained declaration uses the existing dllimport/forceinline holder
pattern from Render2DSentenceClassRva00156540.cpp, preventing that extra copy.
No callback pin, alias, ledger row or compiler flag changes.

## Verification

- Normal build: all three source rows exact, including both funclets resolved
  through the parent EH data; frozen-definition check clean.
- `eh_verify.py`: one EH graph EXACT, zero exceptions/baseline entries.
- `allowed_symbols.py --source`: 14 references, seven owners, six byte-and-
  relocation-proven folds, one EH reference, zero wrong bindings.
- `repair_queue.py retire identity SOURCE`: PASS, one key retired, zero still
  found. Four missing ledger objects were first refreshed through normal
  builds: AptMpGameRules.cpp, AptOnlineQuickMatch.cpp, AIUnitBuilder.cpp and
  W3DShadow.cpp, all 86 rows exact. No source changes in these providers.
- Final paired ordinary preview with W3DRadarResetSurface_destructor.cpp:
  both LINKS, preserving 345 + 26 = 371 authored bytes. This is unchanged
  preview coverage, not a new census result or an image-ownership receipt.
- `check_csv.py`: clean.

The single registered identity key is retired only through the owning tool.
No other BfmeThingFTResize keys remain. Further record/type naming is outside
this repair; no runtime or census gain is claimed.
