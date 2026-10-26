# Sol family-B prerequisite pass, 2026-10-26

Seat: codexb, allocated repair shard 0/2. Base inspected: c05991a3f7
(inherited W3DGameFont prerequisite recovery); upstream at initial pull
093a4702be. No merges, splits, renamed paths or recovered C++ bytes.

## DogmaAllocator: allocation callback binding repaired

Allocated destination: `Code/Libraries/Source/Apt/DogmaAllocator.cpp`.
Planner: `python3 tools/name_lane.py consolidate --under
Code/Libraries/Source/Apt/ --out build/consolidation/apt`; input check passed
before the original dry run. Original-path evidence is the target's literal
DogmaAllocator.cpp assertions, not a donor-path claim.

`DogmaPoolAllocBlock.cpp` previously referred to `g_00E17728` and supplied an
alternatename to `g_bfmeAptAllocAtE17728`. The data ledger records the latter as
the owner at RVA 0x00A17728 / VA 0x00E17728, defined by
`DogmaPoolFreeBlock.cpp`. The repair declares and uses that existing callback
with its existing function-pointer type and removes the alias. It introduces
no new name or data definition.

Acceptance:

- `./build.sh` over DogmaAllocator.cpp, DogmaPoolAllocBlock.cpp,
  DogmaPoolFreeBlock.cpp and DogmaPoolBytes.cpp: 11/11 matched, one data row,
  16 literal references; before and after builds pass.
- Frozen-file checks on the edited donor and destination pass.
- Scoped COFF proof using allowed_symbols.Obj and the census COMDAT reader:
  all 23 external code/data providers (7/9/6/1) retain raw bytes, section
  flags and COMDAT selections. All relocation targets and undefined reference
  sets are identical except exactly two DIR32 callback references now name
  the recorded owner directly. The other three objects are unchanged.
  Reproduction script and snapshots: build/codexb-dogma-provider-proof.py,
  build/codexb-dogma-before.json and corresponding .before.obj files.
- `data_check.py --converged` on those four sources: 10 addresses,
  no second names or unjudged rows. Scoped code_identity_gate.check:
  11 rows, no problems; the two code calls still bind to their original owners.
- `repair_queue.py retire data .../DogmaPoolAllocBlock.cpp` retires exactly one
  wrong-name key. `hatch_counters.py --update` verifies removal; only this
  donor's alias key is lowered in the committed register. Other stale register
  entries are preserved. Data debt -1, alternatename hatches -1;
  code-identity retirement 0, file reduction 0, recovered bytes 0.

Demonstrated prerequisite removal, not a completed split:

- Before: `tu_skeleton.py --split .../DogmaPoolAllocBlock.cpp --for
  .../DogmaAllocator.cpp --dry-run` refuses 0x006DB160 for data-identity debt
  and the remaining carve for copied hatch growth.
- After: both 0x006DB160 and 0x006DAFE0 are carved, refused_rows is empty,
  and no copied hatch/data definition remains. The tool still refuses the
  complete split because residual inline helper rows 0x006DADD0, 0x006DADF0,
  0x006DAE00 stop being emitted without the allocator callers. Preserve these
  rows; their routing/emission needs the upstream split lane. No manual split.
- Independent merge dry-run already accepts DogmaAllocator.cpp,
  DogmaPoolBytes.cpp and DogmaPoolFreeBlock.cpp (6 rows), transferring one
  flag override and two data-ledger entries. No composition applied: leave
  this candidate for Luna's full binding/selected-provider audit.

Audit before commit/publish: the entire outgoing commit range plus this fix
has no source-path deletion or move. The inherited added font header's sole
include consumer was verified in the font recovery handoff; Dogma changes no
includes, build inputs, tooling paths or registries of paths. Historical EA
strings remain unchanged. The pre-push link-batch report remains a shadow
receipt check; no new linked-byte or image-ownership claim is made.

Claims retained until publication: DogmaPoolAllocBlock.cpp and this handoff.
DogmaAllocator.cpp scope can be released after this prerequisite is committed
because its source was inspected only, not changed. Inherited font claims
remain listed in the font recovery handoff until publication is confirmed.

## Other allocated trials

W3DVideoBuffer: ordinary merge accepts no donors. Empty seed compiler override
loses Allocate/Ctor/State rows. Seed ZH VideoBuffer(enum Type),
RefCountClass::Dec_Total_Refs and SurfaceClass::Lock bindings fail the
census-linked guard; BFME constructor/state layout differs. Recorded through
re_log.py at 0x00072760; no edits, file claim released. Receipt:
build/codexb-video-before-trial.txt.

matpass: ordinary merge accepts no donors. Constructor private field names do
not agree with the seed's old ZH class, the destructor loses two rows and
Install_Materials one under the empty carried override, and setter/getter
lack baseline matches. Recorded through re_log.py at 0x0013EDD0; no edits,
file claim released. Receipt: build/codexb-matpass-before-trial.txt. Requires
owning-stage BFME class and flags reconciliation, not speculative member
renames.

Connection, FirewallHelper, Network and AptScriptColour have unchanged
recorded blockers in prior tracked consolidation handoffs; not rebuilt.
OBBox's mixed Matrix3DO1Inlines donor belongs to family A and is left for its
owner. Material/particle/motion plans were read only; no claims or edits.
