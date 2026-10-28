# BannerCarrierUpdate consolidation prerequisites, 2026-10-28

Inspected base: `309f097ad1`. Owner: `yasinschroeder-codex`.

The default picker claimed BannerCarrierUpdate.cpp and its eleven whole-file
satellites. The supported naming planner reports compiler-setting and private
view conflicts. Its donor paths are leads, not BFME 2 provenance proof. The
merge tool rebuilds the stale map in memory: 46 approved rows, twelve whole
sources, four mixed sources and no refused sources. No committed map was
regenerated. Baseline ordinary builds pass 32/32 code rows and one data row;
all twelve sources preview LINKS for 2,831 authored bytes against index
`14dc3d2467` (2026-10-28 02:44). These previews are not a new census.

The initial supported merge dry run accepts no donor. Private views disagree
on the BannerCarrierUpdate bases, Object fields, module-data class key and
members, and the morph-condition record. Rva00496D43Finish compiles but loses
bytes. The four mixed sources remain outside this merge; no manual split was
attempted. The supported view reconciliation dry run additionally identifies
an unterminated macro member in AIUpdateInterface and overlapping Object
fields. These are existing composition prerequisites, not lost matched rows.

## Destructor string-header prerequisite

Rva00496A63Dtor.cpp declared its own StringBase template and typedefed
AsciiString to it. That conflicts with the destination's shared string header.
The donor now includes the same ascii_string.h and removes the private template
and typedef. Its two existing string members and empty destructor body stay
unchanged. No new name or layout is inferred from a reference source.

Normal byte verification passes all three rows: the 53-byte destructor at
0x00496A63, its 8-byte unwind at 0x0078D16E and 10-byte EH handler at
0x0078D176. The verifier follows the renumbered compiler unwind label through
the parent's exact EH graph. Frozen-file and canonical-class checks pass;
data_check reports zero findings. The source has no entries in the header,
Microsoft-header, code-identity, data or hatch registers.

Object comparison shows no exclusive definitions removed or added. The
undefined call changes from the pinned StringBase destructor spelling to
StringBase<char>::releaseBuffer, verified at the same retail address by the
normal byte/relocation gate. The destructor COMDAT's name-based digest changes
accordingly. A 5-byte AsciiString destructor helper is emitted with digest
`d08bf29c9c2b`, identical to the destination's existing copy. It is not a new
COMDAT variant. Ordinary link preview preserves the donor's LINKS result and
63 authored bytes; the unwind row is not separately counted by that preview.
A strict reusable receipt was prepared through link_check --prepare-current.
No pins, hatches, ledger ownership changes or debt retirements accompany this
prerequisite repair.

The staged batch audit remains INCONCLUSIVE: the index predates the outgoing
base and lacks per-object consumer names. The current receipt resolves its
initial missing-receipt finding. The preview and identical existing helper
bound this repair's evidence; full consumer selection awaits the next normal
census. The next step is a supported merge after this prerequisite commit.
