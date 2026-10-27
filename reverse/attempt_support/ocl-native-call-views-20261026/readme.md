# OCLSpecialPower: bind the existing native call views

Inspected tree: `eec2395dbd`. Published provider index: `5ce093a71a`,
2026-10-26 19:02. Changed source:
`Code/GameEngine/Source/GameLogic/Object/SpecialPower/OCLSpecialPower.cpp`.

The current-object batch confirmed three actual blockers: the imported
protected SpecialPowerModule destructor, a receiver-taking ring-search call,
and an extra FindPositionOptions constructor copy. The following existing
owners provide the required operations:

| Operation | Native owner |
| --- | --- |
| Public SpecialPowerModule destructor | 0x00493DEF, SpecialPowerModuleDtor_Unresolved.cpp |
| Static three-pointer ring search | 0x00285202, TerrainLogicFindPositionAround.cpp |
| 32-byte options default constructor | 0x0023C5D0, AIUpdateInterfacePrivateCommands.cpp |

Use the existing bfme2_specialpower_layout shim for the public base destructor.
Its 0x7C module-data base extent also agrees with OCLSpecialPowerModuleDataCtor.cpp.
Replace the donor PartitionManager include with the existing native
PartitionRangeQueryCallView.h, declare the same eight-word options layout
with its constructor out of line, and call the static search explicitly.
The 0x100 clear-cell flag retains its existing Zero Hour spelling and value.
No name, pin, row, baseline or shared header changes. The seven existing
unmatched OCL methods remain separate reconstruction debt.

The complete bounded build passes 110/110 function rows across eleven
OCL-family and provider sources; string, float, import and data checks pass.
All eleven EH graphs are EXACT. See [build.txt](build.txt) and [eh.json](eh.json).

The paired preview refreshes all eleven actual current objects at their
existing index positions. Only the OCL object changes between cases, using
the saved pre-edit object for the before case. OCL changes from two unresolved
names and one losing constructor copy to LINKS; every other cohort unit stays
LINKS. Linked authored bytes change from 11,869 to 11,909: a 40-byte gain.

[comparison.json](comparison.json) records the blockers, selections and hashes.
There are no new harmful COMDAT variants, no newly wrong selected provider,
and no indexed incoming edge from an outside provider to a removed definition.
The options constructor and floating-point constant retain other owners.
The only removed name without another owner is the old compiler-generated
local-static guard for OCL's memory-pool getter; its renumbered replacement
is emitted with the same owning getter. No unrelated source is edited.

These are bounded current-object previews against a historical outside-provider
index. They establish neither a new census headline nor runtime closure.
The next normal census must confirm the forty-byte gain.

The normal pre-commit checks passed. Their shadow identity scan reports one
compiler-array-constructor helper as divergent against its register. The saved
original and repaired objects both contain the same 34-byte helper, digest
`6246c280fc30`, and both receive the link truth verdict `retail`. The warning
predates this repair; no identity baseline entry was added.
