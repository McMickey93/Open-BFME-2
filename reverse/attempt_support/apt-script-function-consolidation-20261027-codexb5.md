# AptScriptFunction consolidation prerequisites, 2026-10-27

Inspected base: e8f2e5e746; constructor prerequisite: e2f2fb7be9.
Provider index: bf3dd31211, census 2026-10-27 00:39 UTC.
This pass makes no source-path move, new match, linked-byte or ownership claim.

The evidence planner was run under Code/Libraries/Source/Apt/AptObject/.
It preserves original retail assertion paths, donor hints and unresolved routes
separately. The committed TU map is stale; tu_skeleton rebuilds approval in
memory. Its current plan approves 47 rows for AptScriptFunction.cpp, leaves six
mixed donors intact, and considers four whole-file donors. No regenerated map
is committed.

## Verified prerequisite cleanup

AptScriptFunctionConstructors.cpp now spells the DefineFunction2 parameter
accesses directly. Its DF2_PARAM/undef pair previously left the macro undefined
when the composer hoisted preprocessing ahead of bodies. All 14 rows still
match, including the four parent EH graphs checked by the commit hook.

AptScriptFunctionBodies.cpp retained constructor-only views and inline helpers
after its constructors moved to AptScriptFunctionBodies_AptScriptFunctionBase.cpp.
Remove those unused definitions, their CHECK_AT/undef pair, one present-unmatched
marker and three constructor aliases. Keep gpObjectPrototype storage and the
SetupBeforeExecution global alias. The three removed alias routes still exist
in the base-constructor donor. No canonical class/header or name changes.

- build.sh: seven functions and one data row exact; four retail string refs.
- find_declared_unmatched.py: clean; the obsolete marker is gone.
- COFF before/after: all ten COMDAT copies retain their names, relocation-aware
  digests and extents; all five exclusive definitions, fourteen undefined
  externals and zero weak externals are identical.
- hatch_counters.py --update: alternatename 3755 -> 3752;
  present_unmatched 3803 -> 3802. No hatch admission or growth.
- repair_queue.py retire identity: one obsolete constructor key retired from
  this source; zero remaining. The first attempt refused missing ledger
  objects; build.sh refreshed the nine missing units (207/207 rows exact), then
  the unchanged owning-tool verdict passed. No check was weakened.
- The four current donors preview LINKS before and after, preserving 2,360
  authored bytes: Bodies 703, base-constructor donor 844, Constructors 700 and
  Rva00709C10Cluster.cpp 113. These predictions do not update census figures.

Scratch object and comparison evidence: build/apt-script-consolidation/.

## Remaining merge prerequisites

The final dry run accepts no donor. Bodies and Constructors now compile and
match in composition but LinkGuard refuses: a file without a census object
would place the merged unit earlier in link order than the guard can judge.
AptScriptFunction.cpp is absent from the index. Wait for a maintainer's ordinary
scheduled census to include it; do not bypass the guard or start a measurement.

The base-constructor donor still collides with the seed's three-argument
CHECK_AT through its four-argument CHECK_AT/undef pair. Reconcile that donor in
its own verified commit before merging. Rva00709C10Cluster.cpp still uses an
incompatible private Rva00709B80 view; the composition cannot declare its
rva00709D80 member. Reconcile the current AptScriptFunction.h contract and both
local GC-owner views without changing native field offsets or virtual slots.

Header and MS-header registers contain no entries for these five source paths.
No row/data ledger, approved routing or fold proof moves in this pass. Since no
path changes land, a tooling path compatibility audit is not needed for these
two prerequisite commits. The pre-push batch audit remains responsible for the
entire outgoing batch; stale index findings remain inconclusive until census.
