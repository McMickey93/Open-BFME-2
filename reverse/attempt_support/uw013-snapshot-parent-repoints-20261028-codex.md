# Four generated Snapshot cleanups restored to their parents

Inspected BFME 2 revision: `73c0328c5d` (2026-10-28). Published index:
`73061d9452`, 2026-10-27 14:34. BFME 1 freshness receipt remains current;
this repair uses BFME 2 retail and existing C++ only.

## Target facts and placement

Retail FuncInfo unwind state 0 names each eight-byte cleanup below.
`eh_verify.verified_funclet_locations` maps each current compiler label through
its parent relocation graph; every cited graph is EXACT. Placement is from
retail EH data, not neighboring addresses or equal cleanup bytes.

| Cleanup RVA | FuncInfo RVA | Parent source basename | Parent RVA | Current label |
| --- | --- | --- | --- | --- |
| 0x0075B560 | 0x008FD120 | ParticleSystemInfoDestructor.cpp | 0x0000240E | `$L1219` |
| 0x0075E4FF | 0x009009D4 | W3DGhostObjectScene.cpp | 0x00063861 | `$L3166` |
| 0x00781D2B | 0x0092CC98 | LifeEventModuleInfoDtor.cpp | 0x003A9F8A | `$L407` |
| 0x00783B20 | 0x0092FBFC | LivingWorldRegionConnectionDtor.cpp | 0x003F2517 | `$L1261` |

The first two instructions are `mov ecx,[ebp-0x10]; jmp destructor`.
Each complete retail body jumps to Snapshot::~Snapshot at RVA 0x0049B47C.
The parent sources already use the canonical Snapshot definition, so this
previous missing-callee prerequisite no longer needs a new fold, pin or source
change. `add_match.py --replace-rva` verifies complete bytes and resolved
relocations for each replacement. W3D and LifeEvent share retail graphs with
other parents; the selected current labels belong to the explicitly recorded
parent, avoiding any claim that one identical body proves unique ownership.

## Verification

Before replacement, the four parent sources pass 59/59 function rows and
11 EXACT EH graphs. Ordinary previews report LINKS for all four, covering
4,110 authored nonpadding bytes (85 + 3,908 + 48 + 69).
Each supported replacement is separately verified by add_match. The final
five-source build passes 197/197 rows (63 parent rows and 134 remaining
generated rows), with 11 EXACT EH graphs. Declaration checks report every
defined function matched; check_csv passes 98,941 functions, 9,420 symbols and
2,201 data rows. Paired ordinary previews retain all four LINKS and the same
4,110 authored bytes. Strict batch/census confirmation remains unclaimed.

All four addresses retain exactly one matched owner and the same extent.
Generated uw_gen_013.cpp source is untouched. Its registered rows fall from
138 / 1,254 bytes to 134 / 1,222 bytes; these 32 bytes now use real parent
lifetimes. This is placeholder ownership cleanup. Census-linked coverage,
image ownership and whole generated-unit closure are not newly measured.

## Compatibility and debt audit

The batch moves four ledger bindings without moving, deleting or renaming a
source file. Searches of tools/, .githooks/ and .github/ find no hard-coded
references to these four generated row names or affected parent source paths.
All source paths remain valid; source includes, doxygen inputs and provider
file paths need no update. The row-specific generated object-symbol notes
are replaced through add_match's supported scaffold path.

None of the parent sources has registered code-identity or data-identity debt.
There are no affected header_queue entries. LivingWorldRegionConnectionDtor's
existing ms-header free:abi entry and W3DGhostObjectScene's four alternatename
keys remain unchanged. No protected register is retired or transferred.
The old generated source remains in all registries and retains its orphaned
harness code, as required. Existing renumbered W3D funclet labels are verified
by the parent's EH data; this batch does not rename those separate rows.

## Remaining prerequisites

LINK-095 remains open for the other 134 generated rows. Earlier unmasked
failures remain useful leads, but must be rechecked after landed class/header
repairs. Resolve each retail destructor target and prove parent EH placement
before repointing. No harness implementation can supply whole-unit link closure.
