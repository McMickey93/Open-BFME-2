# ShareExperienceBehavior update composition

Inspected base: `76c011c831`. Preview index: `c8734bec0c`, 2026-10-28 10:03.

The default picker claimed the destination and five clean donors. The evidence
planner records a WorldBuilder path for ShareExperienceBehavior.cpp; this is
path evidence, not a retail BFME 2 assertion. The merge tool rebuilds the stale
TU map in memory and approves 21 rows. Three mixed sources remain satellites.

The initial dry run accepts only the falloff source. The private-view tool
refuses the differing base clauses and the module-data filter's int/class
disagreement. It applies no changes. The remaining donors need explicit
declaration and layout reconciliation, not mechanical union of their views.

The falloff source's existing +0x10 interface now declares the already-rowed
update method at slot zero. The update donor documents retail entry 0x0047FF6B
in that slot. Compiler layout places both views' update interface at +0x10;
the falloff view retains its +0x20 experience interface and slot 11 callback.
The complete-object views still differ and are not claimed fully recovered.
This declaration enables composition of the update body, which uses no fields
or other virtual methods of its receiver. No row or pin is renamed.

Prerequisite verification:

- `./build.sh` verifies all ten rows in the falloff and update sources; the
  six unwind rows resolve through the matched parent's EH graph after compiler
  label renumbering. One string and three float literals verify.
- All 28 external COMDAT byte/relocation digests of the falloff object remain
  identical, as do all 59 external definition/reference entries.
- Frozen-file checks pass. Before/after ordinary previews both report 2/2
  LINKS, preserving 696 authored bytes. This is not a census gain.

Remaining prerequisites: the pool key needs a coherent primary interface;
the constructor needs compatible base declarations; the module-data destructor
needs its constructor and filter/base lifetime contract in the destination.
The mixed field-parser, module-data constructor and grandchildren files stay
outside this merge attempt.

A preceding picker candidate, WorldHeightMapGetTerrainNameAt.cpp at 0x000AEC4E,
already previewed LINKS for 224 authored bytes against index 14dc3d2467. Its
frozen-file check passed, no source changed, and its claim was released.
