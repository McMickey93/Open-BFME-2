# Vector assignment at 0x0051F7AD: native provider bindings

Inspected 2026-10-27 at `ad2bb0370324ec4e35d23e554b3c255f809601f7`.
Ordinary-preview index: `bf3dd31211`, census 2026-10-27 00:39 UTC,
`retail-truth-4`. Claim: 0x0051F7AD and its source file.

## Target facts

`Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva0051F7AD.cpp` owns one
206-byte row, `vector<Rva0051F7ADRecord>::operator=`. The original source
already byte-matched. This is a link repair, not new coverage or a lost row.
There was no prior attempt-log verdict for this address; LINK-083 records the
earlier emission cleanup and the five native provider prerequisites.

Retail uses three pointers at offsets 0, 4 and 8 and a 12-byte element stride.
The direct calls in the complete 206-byte retail body are:

| Call RVA | Target RVA | Existing owner |
| --- | --- | --- |
| 0x0051F7EC | 0x004EE233 | `vector<ProductionPrerequisite::PrereqUnitRec>::_M_allocate_and_copy<PrereqUnitRec *>`, Thing/Rva004EE233AllocateCopy.cpp |
| 0x0051F7F5 | 0x004EE540 | `Rva004EE540::rva004EE540`, Common/Rva004EE540Clear.cpp |
| 0x0051F824 | 0x0051EC31 | `Rva0051EC31RangeForward`, WWLib/Rva0051EC31RangeForward.cpp |
| 0x0051F82D | 0x0052C37A | `Rva0052C37ADestroyRange`, Common/System/Rva0052BF33DestroyTagged.cpp |
| 0x0051F844 | 0x0051EC31 | `Rva0051EC31RangeForward`, same owner |
| 0x0051F862 | 0x004EE1E2 | `__uninitialized_copy<PrereqUnitRec *, PrereqUnitRec *>`, Common/RTS/ProductionPrerequisite.cpp |

These are RVA values; the disassembler displays VA = RVA + 0x00400000.
`retail_body.disasm(0x0051F7AD, 206)` supplies the direct-call facts.

## Source and structural evidence

STLport 4.5.3's `vendor/stlport/stl/_vector.c:90` supplies the assignment
algorithm: allocate and clear if capacity is insufficient; copy and destroy
the excess when the existing size suffices; otherwise copy existing elements
and construct the remainder. This identifies the operation shape, not a game
element name.

The landed BFME 2 `StlSweepR3Rva003F318C.cpp` repair provides the bounded local
vector-view pattern and the protected-member access pattern. The BFME 1
reference was inspected at `e74410b3738a2bb75d626085d9ebfd3406a43ff7`:
`game/Libraries/Source/WWVegas/WWLib/ProductionPrerequisitePrereqUnitRecAllocateAndCopyThunk.cpp`
also contains local vector declarations, but forwards to BFME 1 shim names.
Those shim names and addresses were not adopted. The BFME 1 file is reference
evidence, not a recovered BFME 2 source path.

The repair specializes only the existing assignment row and calls the five
BFME 2 owners under their current names. A derived view can name the protected
allocation member. Pointer conversions preserve the provider signatures;
the unused copy tag remains a fourth argument with the original stack shape.
The opaque record spelling is retained. Neither equal size nor sharing these
native callees proves that this element is `PrereqUnitRec`.

The resulting object references only the five native owner names above (six
call relocations). `allowed_symbols.py --source` reports six owner bindings,
zero wrong bindings. The unwanted record `_Construct`, destructor and
assignment references and the wrong `_Destroy`/`__uninitialized_copy` copies
are gone.

Six obsolete pins whose names contain `Rva0051F7ADRecord` are removed: the
five old helper spellings and their folded allocator pin at 0x00395928.
The pin hatch register is reduced by exactly six occurrences. There is no
new pin, alias, row, name, source move or exception to a gate. Declaration-only
suppressions in the callers remain unchanged and need no removed pin to build.

## Verification

The following nine sources were checked together, both before and after the
repair; the after run was repeated after removing the six pins:

```text
Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva0051F7AD.cpp
Code/GameEngine/Source/Common/Thing/Rva004EE233AllocateCopy.cpp
Code/GameEngine/Source/Common/Rva004EE540Clear.cpp
Code/Libraries/Source/WWVegas/WWLib/Rva0051EC31RangeForward.cpp
Code/GameEngine/Source/Common/System/Rva0052BF33DestroyTagged.cpp
Code/GameEngine/Source/Common/RTS/ProductionPrerequisite.cpp
Code/GameEngine/Source/Common/Rva0051F87BAssign.cpp
Code/Libraries/Source/WWVegas/WWLib/StlSweepW5Rva0051FC54AssignTwin.cpp
Code/GameEngine/Source/GameClient/GUI/GUICallbacks/Apt/AptTimeLineCollectPlayerData.cpp
```

- `./build.sh <nine sources>`: 41/41 rows exact; 11 string references,
  no float or import failures. All 12 renumbered funclet rows resolve through
  their parent's EH data.
- `eh_verify.py <nine sources>`: two EH graphs, both EXACT, no baseline use.
- `find_declared_unmatched.py <target>`: all defined functions already matched,
  before and after the change.
- `allowed_symbols.py --source <target>`: six references, all owner bindings;
  zero rows with a wrong binding.
- `pin_consistency.py --check`: no new, baselined or stale findings.
- `link_check.py --prepare-current <target>`: the one explicit provider is
  byte-verified with a strict reusable receipt; no census/index/status change.

Ordinary preview with all nine current objects:

| Unit | Before | After |
| --- | --- | --- |
| StlSweepR3Rva0051F7AD.cpp | U3 / L2 / S2, 0 bytes | LINKS, 206 bytes |
| Rva004EE233AllocateCopy.cpp | LINKS, 45 bytes | unchanged |
| Rva004EE540Clear.cpp | LINKS, 30 bytes | unchanged |
| Rva0051EC31RangeForward.cpp | LINKS, 29 bytes | unchanged |
| Rva0052BF33DestroyTagged.cpp | LINKS, 333 bytes | unchanged |
| ProductionPrerequisite.cpp | blocked, 0 bytes | same blockers |
| Rva0051F87BAssign.cpp | LINKS, 111 bytes | unchanged |
| StlSweepW5Rva0051FC54AssignTwin.cpp | LINKS, 111 bytes | unchanged |
| AptTimeLineCollectPlayerData.cpp | LINKS, 1,358 bytes | unchanged |

The preview changes from 7/9 to 8/9 clean units and from 2,017 to 2,223 authored
bytes. Raw local logs: `build/vector-51f7ad-before.log`,
`build/vector-51f7ad-after-pin-retirement.log`, `build/vector-51f7ad-build.log`,
`build/vector-51f7ad-eh.log`, `build/vector-51f7ad-identity.log` and
`build/vector-51f7ad-strict.log`.

## Remaining scope

The target's ordinary-preview blockers are cleared. The whole
ProductionPrerequisite TU retains its separate string, imported-allocator,
copy-construction and overflow conflicts; the exact 0x004EE1E2 row is usable
by this preview even though that source as a whole remains blocked. Its
downstream identity keys are unchanged. The forwarding provider also retains
its existing alias; this repair adds none. Element identity and retail TU
ownership remain cleanup work. Strict recursive closure and census
confirmation are not claimed. No headline linked-byte or image-ownership
measurement is recorded by this pass.
