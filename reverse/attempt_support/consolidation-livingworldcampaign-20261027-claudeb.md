# LivingWorldCampaign.cpp consolidation: 3 donors absorbed, 13 left (claudeb, 2026-10-27)

Landed: "LivingWorldCampaign: reconcile three donor views with the seed" and
"Merge 4 files into LivingWorldCampaign.cpp" (41 rows, 41/41 byte-verified).
The absorbed donors are FindRecord (0x0052C7A2), Rva0052C06CGet and
AdjustStartingPositionForScenario (0x0052BAC1). The seed now carries their
views: the `Rva0052BFE1Records` union over the 184-byte records at +0x0C, the
`Rva00564DF2NameView` record view, and `Sub0052BAC1 *m_1C` with
`Res004FCA0C`.

These are the rejections from the final `--merge` (build log, not committed):

- **ctor (Common/LivingWorldCampaign.cpp), dtor (Common/Rva0052CFB1Dtor.cpp),
  xfer (Common/LivingWorldCampaign_xfer.cpp)**: these donors declare a
  polymorphic, Snapshot-derived `LivingWorldCampaign` (vtable 0x00868780) with
  members m_04..m_4e. They also declare the vector types `Rva0052CA2D` and
  `Rva0052CA6C`, whose dtors 0x0052CA2D and 0x0052CA6C are rowed in
  Common/RvaVectorDtorFamily.cpp. The seed's `LivingWorldCampaign` view is
  non-polymorphic, and its methods use a different member spelling (`pad1c`,
  `m_1C`). Prerequisite: give the seed the real Snapshot-derived class layout
  and rebuild its 41 rows against it. Only then can these three bodies apply
  unchanged. xfer also carries a present-unmatched `loadPostProcess`.
- **AddPlayer**: redefines `StringBase`, and its players vector is
  `_STL::vector<Rva002E0A0A>`. It needs the same class unification.
- **Rva0052D116Overflow**: the dry run gave an empty compile message. Not
  investigated.
- **WWLib STL donors** (Rva002E0A0AUninitCopy, Rva002E0A0AFillN,
  Rva003A6360UninitCopy, Rva003A6F70UninitCopy, Rva004E18A2UninitCopy,
  Rva0052C867Copy, Rva0052C8ABCopy): these define a private
  `_STL::__false_type`/allocator. The retail bodies have no EH frame, while the
  seed's real STLport `_STLP_TRY` would add one. Each composed TU also failed
  at the seed's `LivingWorldCampaign *` declarations (C2143/C2501), which the
  donor-local prefix shadows.
- **Rva0052CD81Finish**: refused by link_guard.

No edits beyond the two commits above. The tu_skeleton claims settle when the
rows land.
