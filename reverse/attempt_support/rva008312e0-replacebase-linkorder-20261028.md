# replaceBase 0x0002A610: the banked template trial verifies but cannot link in the current grouping

Inspected `5887b8bda4`, 2026-10-28, model=claude-opus-5-5, owner
`yasinschroeder-claudeb3`. Index `14dc3d2467` (2026-10-28 02:44). LINK-006
stays open. Nothing is landed; every trial was reverted.

## What was verified (target facts)

The [banked template trial](rva008312e0-replacebase-link-20261024/bfmeconv1464-template-trial.cpp.txt)
in `Code/GameEngine/Source/Common/BfmeConv1464.cpp` replaces the inline-asm
lift `BfmeStrV24::bfmeReplaceV24` with clean C++. It has a member-template
`replaceBase<char *>`, an inline `insertRange`, an inline `__copy_trivial`, and an
explicit instantiation.

- With the old row removed locally, `add_match.py
  '??$replaceBase@PAD@Rva008312E0String@@QAEAAV0@PAD000ABURva008312E0Tag@@@Z'
  0x0002A610 279 BfmeConv1464.cpp` verified OK, so all 279 bytes and relocations
  pass the byte gate.
- `Rva008312E0StringReplace.cpp` with `replaceBase` as the same member template
  (`_ForwardIter __m = __f;`) still passes 2/2. Its COMDAT then shares the
  name.

## Why it does not link (census rules, link_check against 14dc3d2467)

With both edits, `link_check.py` on both sources gives:

| Unit | Before | After | Findings |
| --- | ---: | ---: | --- |
| `Rva008312E0StringReplace.cpp` | 0 | 0 | duplicate `?insertRange@...`; selected `??$replaceBase@PAD@...` |
| `BfmeConv1464.cpp` | 274 | **0** | duplicate + comdat `?insertRange@...`; selected `??$replaceBase@PAD@...` |

1. **Selected replaceBase.** `link_census.link_order` places an object by its
   lowest matched RVA. `Rva008312E0StringReplace.cpp` holds 0x000284D0, so it
   precedes `BfmeConv1464.cpp` at 0x0002A610. The link therefore keeps
   StringReplace's frame-0x44 replaceBase copy, not retail's 0xd4 copy.
   Retail kept the 0xd4 copy, so retail's insertRange object and its 0x2AE50
   object cannot be one object. That object also needs replaceBase as a declined
   inline candidate (its 0x9c frame reserves replaceBase's slots, per the
   2026-10-24 trial (1)). It would therefore emit a 0x44 replaceBase copy and
   come first. This is a structural inference from link-order rules and frame
   evidence, not a TU assignment. The grouping of 0x000284D0 with 0x0002AE50 in
   one file is what blocks the unit. These are STLport header COMDAT rows, and
   `reverse/tu_map.csv` gives them no TU, so no admissible row move exists today.
2. **Duplicate insertRange.** The 0xd4 frame needs `insertRange` to be an
   inline candidate in BfmeConv1464. Its declined copy (863 B, frame 0xac) is
   then a SELECT_ANY COMDAT. StringReplace defines `insertRange` non-inline, which
   is an exclusive COMDAT, so link.exe would report LNK2005 and charge both
   objects. Making StringReplace's copy inline is the recorded 0x9c -> 0x104
   frame failure. Making it a member template would rename row 0x000284D0 and
   five callers (`BfmeConv1429/1439/1463/1485`, of which three are inline-asm lifts).

Landing the conversion now would lose BfmeConv1464's 274 census-linked bytes, so
it was not landed.

## Next check

- Find TU evidence for 0x000284D0 or 0x0002AE50 (tu_evidence lane). A row
  move needs an approved unit; this note does not supply one.
- Alternatively, retype the insertRange family as STLport's member template
  `insert<_ForwardIter>(iterator, _ForwardIter, _ForwardIter, const
  forward_iterator_tag &)`, so every copy is SELECT_ANY. Do it in its own commit,
  with the row retracted and re-added and the five callers updated. Then
  BfmeConv1464's conversion can link while it holds a different replaceBase
  name from StringReplace's pinned one. StringReplace itself stays blocked until
  the grouping is resolved.
