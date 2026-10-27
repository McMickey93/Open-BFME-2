# vector<ArmySummary> fill-insert link repair (StlSweepW4Rva003F53DA.cpp), blocked at commit

Seat halilkkaya-lk3, 2026-10-28, base `54c263ce1f`, index `73061d9452`.
Patch: `vector-armysummary-fill-insert-20261028-lk3.diff` (apply on that base).

## Target facts
- 0x003F53DA (258 B) copies its value through the ArmySummary copy ctor 0x0040E96D and
  destroys it through ~ArmySummary 0x0040E499; its fill 0x003F4146 assigns through
  ArmySummary::operator= 0x0040EAED; 0x003F5724 tail-jumps it (STLport `insert(pos, n, x)`).
- It calls the overflow 0x003B9184 and the fill_n wrapper 0x003F4163; the loop 0x003B8B05
  places elements through _Construct 0x003B8AD8 (the ArmySummary copy). All are rowed over
  BfmePod104 / BfmeAssignRecord104 / Rva003F53DAElement spellings: one vector<ArmySummary>.

## What the patch does (all rows exact, link_check verified)
- Respells 0x003F53DA, 0x003F5724, 0x003B9184 (StlportVectorInsertOverflowFamily.cpp) and
  0x003B8B05/0x003F4163 (StlSweepW5Rva003B8B05.cpp) to their vector<ArmySummary> names; the
  providers bind the BfmePod104-rowed _Construct and allocate through forceinline forwarders;
  Rva003F5A06Resize.cpp calls the new fill-insert name.
- `./build.sh` 63/63 + 2/2 exact. link_check: StlSweepW4Rva003F53DA.cpp 0 -> 263 B; a 20-unit
  cohort (providers, the claimed stlport_pod_vector_bodies.cpp, LivingWorldBattle, ArmySummary
  units) still LINKS; no census-unlinked unit loses.

## Why it was not committed
pin_admission refuses the three Rva003F53DAElement helper pins renamed in place to
ArmySummary names (0x003F417E `__uninitialized_copy`, 0x003F447F `__copy_backward_ptrs`,
0x003F4146 `fill`): their owners' BfmePod104 / BfmeAssignRecord104 template names count as
real names ("rename the owner instead of stacking a second name"). Next step: respell those
three owner rows too (0x003F447F in StlSweepW5Rva003F447F.cpp and 0x003F4146 in
stlport_asciistring_record_bodies.cpp have no other referencers in the census graph; the
0x003F417E row is the const variant used by `_M_allocate_and_copy` 0x003F41F0 and the vector
copy ctor 0x003F4B89, so its non-const ArmySummary name needs a fold-proof pin or both
respelled), then drop the pins. Tombstones for the five respelled rows are needed.

## Reusable compiler facts
1. If the overflow (or any callee given a `__false_type` tag) is only declared, cl 7.1
   zero-fills the tag temporary and re-colours the `__n`/`__x` spill slots of
   `_M_fill_insert`; the fill-insert bytes depend on seeing the overflow body. This is the
   W4/W5 "spill-slot wall" noted in LINK-083.
2. Forwarding a tagged helper through a forceinline wrapper lets /O2 inline its loop; only
   tag-free callees (`_Construct`, `allocate`, `_M_clear`) can be forwarded that way.
3. The sweep unit's own /Ob0 overflow copy stays non-retail but no longer blocks once the
   provider supplies the retail-proven copy under the same name (retail-truth-3); declaring
   the proxy `allocate` keeps one copy of that unaddressed helper across both units.
