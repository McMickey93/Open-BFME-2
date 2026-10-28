# ModuleInfo nugget helper placement

Inspected BFME 2 revision: b523dbd44c. Reference checkout: 7c48cfd1.
The default picker claimed the three-source run at 0x002CEFAA..0x002CF0BE.

Target facts:

- 0x002CEFAA, 35 bytes: the pair copy constructor in
  `Code/Libraries/Source/WWVegas/WWLib/StlSweepW5Rva002CEFAA.cpp`.
- 0x002CEFCD, 57 bytes: Nugget assignment in
  `Code/GameEngine/Source/Common/Thing/ModuleInfoNuggetAssign.cpp`.
- 0x002CF0BE, 50 bytes: the five-argument copy worker in
  `Code/GameEngine/Source/Common/Thing/ModuleInfoNuggetCopyPtrs.cpp`.
- The current ledger already owns all three bodies. The committed TU map has
  no assignment for any of them. `tu_evidence.py --source` produces no evidence
  row for each source. Searches of string_xrefs.tsv, data_xrefs.tsv and
  wb_name_leads.csv find no entry at these three addresses.
- The fresh supported consolidation packet for StlSweepW5Rva002CEFAA.cpp marks
  placement unresolved, with no alternatives or placement evidence. It also
  flags macro/pragma context and internal linkage for a future composition.
- The picker's lower bracket is only a K proposal at 0x002CEF9B; the upper
  bracket at 0x002CF0F0 is an N proposal for a different unit. Neither supports
  placing this run in ThingTemplate.cpp.

Reference facts, not BFME 2 placement proof:

- Zero Hour's GeneralsMD/Code/GameEngine/Include/Common/ThingTemplate.h,
  lines 250-275, declares ModuleInfo::Nugget in a header, with three Bool
  members and an inline constructor. It supplies no out-of-line assignment
  definition anchoring the target's emitting TU.
- BFME 1's game/GameEngine/Source/Common/Thing/ThingTemplate.cpp, lines
  435-450, contains the two-Bool Rva0013E5D0Nugget reconstruction. Its layout
  explains the existing assignment model; this external source path does not
  prove the original BFME 2 TU.

Result: placement remains blocked on an independent retail anchor or a newly
supported layout bracket. Do not merge these helpers based on their class name
or the external reconstruction's path. No source, identity, extent, pin or TU
map changes were made. The frozen-file check passes for all three sources;
check_csv passes. No compile, linking or coverage improvement is claimed.
