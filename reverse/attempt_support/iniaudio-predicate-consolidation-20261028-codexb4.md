# INIAudioEventInfo predicate consolidation prerequisite

Inspected base: `1312d710f1`. Target: the existing 79-byte predicate row at
`0x001D9A00`, initially owned by
`Code/GameEngine/Source/Common/Thing/Rva001D9A00Finish.cpp`.

The consolidation picker claimed INIAudioEventInfo.cpp and eleven whole-file
donors. The naming planner's INI packet and the supported TU plan were read;
the latter rebuilds the stale TU map in memory and approves this row for
INIAudioEventInfo.cpp. No donor name or layout recovery is claimed. The
previous consolidation handoff records this donor's private StringBase
declaration as a composition blocker.

## Declaration repair

Use the existing bfme2_ascii/string_base.h declaration instead of the donor's
private StringBase template, adding its include directory to this donor only.
The shared declaration already supplies the pointer-sized member and isEmpty
call used here. No shared header or function body changes.

Both original and repaired sources pass the ordinary `./build.sh` gate: 1/1
rows, 79 bytes, and all reference checks. The declaration scan passes before
and after. Object comparison with link_census's COFF helpers finds identical
external definitions, references, weak bindings, and external COMDAT digests
(bytes plus relocations):

- Definition: `?rva001D9A00@Rva001D9A00@@QAE_NXZ`, 79 bytes,
  digest `c890e4d1303a`.
- Reference: `?isEmpty@?$StringBase@D@@QBE_NXZ`.
- No weak external bindings.

The baseline link preview, index `41c28839bf`, reports LINKS for this donor
and the destination. These are predictions, not new census measurements.
No gate, code-identity, data or header register entry names this donor; no
debt retirement is claimed.

The baseline supported dry run reproduced StringBase redefinition for this
donor and accepted no merge. After the repair, `link_check.py --prepare-current`
byte-verifies 33/33 rows across donor and destination, one data row, and all
reference checks; both have strict reusable receipts. The first preparation
trial overlapped temporary consolidation sources and refused a moving input
inventory; the successful preparation ran after that dry run finished.
