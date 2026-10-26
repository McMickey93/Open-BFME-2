# tu_skeleton merged flag sets and bfmealloc C2950, 2026-10-26

Seat: yasinschroeder-claude3 (consolidation-prerequisite support).

## Target facts

- `reference/shims/bfmealloc/stl/_alloc.h` (and `bfmealloc_alloconly`) declares
  `_STLP_TEMPLATE_NULL class allocator<char>` (line 394) and, under
  `_STLP_USE_TEMPLATE_EXPORT`, `_STLP_EXPORT_TEMPLATE_CLASS allocator<char>;`
  (line 446). `/MD` without `_STLP_USE_STATIC_LIB` turns the export on, and cl
  refuses it: `C2950 '_STL::allocator<char>' : cannot explicitly instantiate an
  explicit specialization`. A three-line repro (`/MD`, the shim, `#include
  <vector>`) fails; the same with `/D_STLP_USE_STATIC_LIB` compiles.
- Of 3,946 `Code/` sources whose cl line names a bfmealloc include, 3,865 use
  `/MD`; 3,849 of those carry `/D_STLP_USE_STATIC_LIB`, and 16 carry neither the
  flag nor a source `#define` (inferred, not checked: they never reach `_alloc.h`).
- `tu_skeleton.py --merge` builds its trial flag sets from the donors' most
  common non-include flags plus the union of every donor's include dirs. A
  donor majority spelled `/MD` without the define then meets a bfmealloc dir
  from another donor, and every STL-including donor, often the seed, fails
  C2950 before its real diagnostics. A static scan of approved TUs with two or
  more donors found 74 where at least one of the top three trial sets has
  this shape.

## Repair

`stl_static()` adds `/D_STLP_USE_STATIC_LIB` (before the include dirs) to a
merged flag set that pairs `/MD` with a `bfmealloc*` include and lacks the
define; trial sets that become identical are tried once. The seed's own
fallback set (`own_k + own_incs`) is left exactly as the seed spells it.
Two unit tests (`StlStaticFlagTests`); `test_tu_skeleton.py` 55/55,
`test_gate_exploits.py` 58 passed / 1 skipped.

## Measured (`--merge TU --dry-run --no-claim`, before = HEAD tool, after = patched)

| TU | before | after |
|---|---|---|
| `DockUpdate/SupplyWarehouseDockUpdate.cpp` | blocked; seed fails C2950 + C2227 | blocked; seed fails only C2227/C3861 at line 293 (`getSupplyTruckAIInterface`) |
| `ProductionExitUpdate/SpawnPointProductionExitUpdate.cpp` | blocked; seed fails C2950 under all three donor sets | blocked; seed compiles under them but matches 0 rows (it needs its own `/FIzh_ascii.h` and ZH defines); its own set matches 1 row before and after |
| `W3DTreeBuffer.cpp` | accepts seed + `W3DTreeBufferRva000EA48D.cpp` | same |

This is a diagnostic repair: no accepted-donor gain, no regression in these
three, no merge, landing, linked-byte or debt claim. Handoffs that list
"allocator<char> specialization" or `_alloc.h(446) C2950` as a prerequisite
(TunnelTracker, SupplyWarehouseDockUpdate, SpawnPoint, shrub, device) should
rerun the dry run; what remains is their real class-composition error.

Not touched: the separate C2766 case (a donor's private
`namespace _STL { template<> class allocator<char> }` meeting the shim's own
specialization), which is per-donor view reconciliation, not a flag problem.

## Other findings this pass

- TunnelTracker.cpp: the current dry run accepts the seed plus
  `TunnelTrackerContain.cpp`, `Thing/TunnelTracker_isValidContainerFor.cpp` and
  `Thing/TunnelTracker.cpp` (best set already carries the define). The tool
  before the comment-chunking repair accepts the same set, so that unblock
  came from an earlier landed change, not this seat; the merge is left to the
  mechanical owners.
- 302 `*PoolKey.cpp` donors fail `C2039 'getModuleNameKey' : is not a member`
  against seed class views; `union_view` correctly never adds a virtual, so
  this is per-class declaration work (owned by the PoolKey seats), not a tool
  repair.
