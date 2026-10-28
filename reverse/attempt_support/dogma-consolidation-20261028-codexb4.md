# DogmaAllocator consolidation, 2026-10-28 (codexb4)

Base: `284a099880`. The current Apt consolidation packet was read and passed
`name_lane.py consolidate --check build/consolidation` immediately before
application. The committed TU map is stale; `tu_skeleton.py` rebuilt approval
in memory. Only its mechanical source-column repoints are committed.

## Result and routing

The ordinary dry run and application accept DogmaAllocator.cpp,
DogmaPoolBytes.cpp and DogmaPoolFreeBlock.cpp: six existing matched rows in
one TU, two fewer source files. The latter two sources are absorbed through
`tu_skeleton.py --merge`. Their two data-ledger owners, one data row and the
freeBlock flag override travel to DogmaAllocator.cpp. No protected key is
retired. The override keeps `/MD` without `/O2`, preserving the out-of-line
free-list call when caller and callee share an object.

DogmaPoolAllocBlock.cpp remains a mixed satellite (three rows outside this
TU's current approval). No split, canonical class rename, pin or new hatch is
introduced. Retail's DogmaAllocator.cpp assertion paths provide target facts;
the existing APT Xbox name evidence for GetTotalBytesUsed remains donor
evidence, not a claim that an external source path is BFME 2's source.

## Verification and identity

All three original sources pass `find_declared_unmatched.py` and the baseline
build (6/6 rows, one data row, ten strings). The resulting TU and unchanged
allocation satellite pass `./build.sh` and strict `link_check.py
--prepare-current`: 11/11 rows, one data row, sixteen string references.
The destination's frozen-file check, check_csv, case-collision check, staged
TU ownership, shadow identity (six rows, no new findings), shadow data (zero
findings) and converged data (eleven addresses, zero second names) pass.

Before composition, the three verified objects and source/object SHA256s
were saved under `build/dogma-consolidation-codexb4/`. A raw COFF comparison
preserves the complete union of thirteen external providers. All twelve
original COMDAT copies have identical bytes, relocation offsets/types/target
names and selection policies in the composed object; the repeated identical
path literal now occupies one copy, leaving eleven COMDATs. Both callback
globals retain their zero-initialized eight-byte BSS section, offsets (0 and
4) and section flags. No old object has a weak external. The only removed
undefined names are the allocation callback and free-list push now defined
inside the same object. No new undefined name is emitted. The three remaining
external names are unchanged. No EH parent is present in the moved rows.

The merge tool refreshed header adoption and Microsoft-header queues.
Neither source has header/identity/data register debt; the Microsoft-header
scan is clean, and a second scoped refresh against a queue copy is identical.
The flag override and both existing data owners remain registered at the
destination. No debt is deleted by hand.

## Linking and outgoing path audit

The merge's link guard protects all three census-linked inputs. A paired
current-object preview against index `14dc3d2467` (2026-10-28 02:44) reports
LINKS for DogmaAllocator.cpp (468 authored bytes) and DogmaPoolAllocBlock.cpp
(495). This is retained coverage, not a linking gain: the absorbed rows now
contribute to the destination's preview. Census confirmation remains pending.

The staged-tree batch audit is **INCONCLUSIVE**: the index predates the
outgoing base and lacks per-object consumer names. It proves no broader
consumer clearance. Carry the changed source ownership and internalized
references into the next normal census. No maintainer-only runner was used.

The complete outgoing source-path batch is DogmaPoolBytes.cpp and
DogmaPoolFreeBlock.cpp into DogmaAllocator.cpp. A combined tracked-path and
basename search covers tools, hooks, workflows, build/configuration files,
includes and registries. No active tooling or include consumer needs repair.
Remaining mentions are merge provenance, comments in the unchanged allocation
satellite, historical attempt records and the last census's link_status.csv.
Those retain historical meaning. Both moved callbacks have current owners;
ledger/data/flag repoints accompany the move. No fold proof changes.

## Other served-unit recheck

The default picker first served StlSweepW4Rva00215949.cpp, already repaired by
the earlier record reconcile. Its three rows verify (one compiler funclet
label renumbering), and the current-object preview against `14dc3d2467`
reports LINKS for 274 authored bytes. No source change is needed. LINK-002
and its target checklist now reflect this limited recheck; the remaining
record families and census confirmation are still pending.
