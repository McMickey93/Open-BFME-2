# String replacement erase binding repair

Inspected `8a9e65cafec135dd3cb53aa58bd7ea301d82b596`, 2026-10-27,
model=gpt-6.1, owner=yasinschroeder-codexb4. LINK-006 remains open.

The existing matched replacement callers at `0x0002AE50` and `0x0002B050`
call retail's `basic_string<char>::erase` at `0x00012150`. Their private
`Rva008312E0String` / `Rva008314E0String` erase spellings instead selected
non-retail bodies. The real erase row already belongs to
`Code/Libraries/Source/WWVegas/WWLib/stlport_basic_ios_init.cpp`.

The first repair applies the successful erase-only shape banked in
[the prior handoff](rva008312e0-replacebase-link-20261024/handoff.md).
The sibling uses the same structure: a TU-local explicit specialization of
`_STL::basic_string<char, char_traits<char>, allocator<char> >` owns the visible
erase/move helpers and three storage pointers; the existing neutral range view
derives from it. This preserves the compiler's inline analysis while binding
calls to the existing real name. This is a scoped view, not recovery of the
complete original class definition or original source placement.

## Verification

`./build.sh` passes 21/21 rows across both edited sources, the erase provider,
and `BfmeConv1461.cpp` (the sibling insertion owner). Frozen-file checks pass
before and after. EH verification passes the provider's one exact EH graph.
Pin consistency and `check_csv.py` pass. No function row changes.

Raw parent bytes are identical before and after; the only changed relocation
in each replacement body is type 20 (`REL32`) to the existing basic_string
erase name:

| Body RVA | Extent | Changed relocation offset |
| --- | ---: | ---: |
| `0x0002AE50` | 511 | 187 |
| `0x0002B050` | 501 | 180 |
| `0x000284D0` insertion | 848 | none; all relocations identical |

Current compiled object definitions and undefined-reference sets contain neither
old erase spelling. Their two pins are deleted, and `hatch_counters.py --update`
lowers the address's pin count from six to four (total pins 15,313 to 15,311).
`repair_queue.py retire identity` independently accepts one erased binding key
per edited source, leaving each source's replaceBase key in the register.
Its prerequisite refresh passes 358/358 rows across 26 sources, including the first
replacement view and its participating providers (the sibling is separately
verified again after its edit).

Against the fixed census index `bf3dd31211`, 2026-10-27 00:39,
retail-truth-4, ordinary paired previews reduce each replacement unit from four
findings to two: only replaceBase COMDAT/selected findings remain. The unchanged
erase provider retains LINKS, 427 -> 427 authored bytes. Both callers retain
LINKED 0 -> 0; no census linking gain or executable closure is claimed.

Object SHA-256 receipts (before -> after):

- Rva008312E0StringReplace:
  `1c3892cabcfd010b936d0f98823267adf56918111ef1e13ec64d5f4f762628aa`
  -> `5613d37e5fcf16b942947e7ee17f465d7968f9b02ea9c3a94f950cc5328d26a6`.
- Rva008314E0StringReplace:
  `c73674aad61aafeaf61a5348e1ff726c9af17a40e4ec4aaf31225508bacec7cb`
  -> `1f1306f2388b3ec0e7cd5c6beed5f7696eb186a1419f55ae41d3f6d0cea60625`.
- Unchanged erase provider:
  `d4ea28090304df724feefe183e21f32bb22f04ddbeb84a5529d72ed9e6b2ac2c`.

## Remaining prerequisite

The neutral replaceBase helpers still disagree with the selected retail bodies
at `0x0002A610` and `0x0002A730`. Preserve the prior frame-analysis and template
trials. The first address already has the real non-placeholder
`BfmeStrV24::bfmeReplaceV24` row in `BfmeConv1464.cpp`; a changed member-template
signature needs an admissible owner/row transition before replacing that lift.
Do not add a second name or another alias. Next: settle that ownership transition,
verify the banked template trial's relocations and all affected caller frames,
then recheck both caller/provider families with current objects. The sibling's
replaceBase requires its own evidence; this repair does not establish it.
