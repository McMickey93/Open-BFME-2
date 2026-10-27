# TU evidence: 0x0058AE1E / 0x0058AE36 / 0x0058AE53 (claudeb, 2026-10-27)

Picker item: three unmapped code rows between AISPecialPower.cpp (0x0058ADD0,
F-approved) and AIDifficulty.cpp (0x0058AEBC, F-approved):

- 0x0058AE1E `?Rva0058AE1EHasVictim@@YG_NPAVObject@@@Z` (24 B, Common/Rva0058AE1E.cpp)
- 0x0058AE36 `??_GRva0058AD7A@@UAEPAXI@Z` (29 B, Common/Rva0058AD7ABase.cpp)
- 0x0058AE53 `?rva0058AE53@Rva0058AE53@@QAEXPAVXfer@@@Z` (99 B, Common/Rva00380200Getter.cpp)

Target facts (retail image):

- Vtable at RVA 0x0087091C (28 B, 7 slots; data_xrefs callers: ctor 0x0058AD4D
  and dtor 0x0058AD7A): 0 = ??_G 0x0058AE36, 1 = 0x0058AE53 (Xfer), 2 =
  0x0058AD9F, 3 = 0x000910FB (shared ICF body), 4 = `__purecall`, 5 =
  0x0058AD81, 6 = `__purecall`.
- The next .rdata item, RVA 0x00870938 (112 B), is the AISPecialPower.cpp
  `__FILE__` literal, read only by 0x0058ADD0. 0x0058ADD0 calls vtable slot 6.
- Ctor 0x0058AD4D layout: +04 int arg, +0C = 0, +10/+14 floats, +18/+19/+1A
  bytes, size 0x1C. The Xfer at 0x0058AE53 serializes +0C/+10/+14/+18, so it
  serializes the same object.

Structural inference: one polymorphic class whose vtable lies in the
AISPecialPower.cpp .rdata run. The three rows are its ??_G, its Xfer, and one
free helper placed between that unit's methods and AIDifficulty.cpp. This is
consistent with all three belonging to AISpecialPower.cpp. It is not an
approval signal.

Hints only (not evidence of names): reverse/wb_name_leads.csv gives 0x0058AE1E
as `AISpecialPower::isInCombat` (score 2). It also gives 0x0058AE53 and
0x0058AD9F as vtable leads (score 3).

Not done: no rename (inferred names need the two-agent name lane, and
`name_lane.py next` serves no keys for these files). No row move (no approved
TU; `tu_evidence.py --source` produces no proposal for any of the five source
files). Next step: a promoted V/R signal from the vtable/`__FILE__` adjacency,
or a two-worker class name. Then move the rows into AISPecialPower.cpp.
