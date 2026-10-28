# BaseHeightMap placement prerequisites and optimization cleanup

Inspected base `c58504c47d`, 2026-10-28; BFME 1 reference
`7c48cfd16763638cdd7440ecd74466631e977b9f`. The default picker claimed
`file:Code/GameEngineDevice/Source/W3DDevice/GameClient/BaseHeightMap.cpp`
for 15 proposed code rows in nine sources. The destination does not exist.

The supported GameClient consolidation planner identifies 36 local fragments,
but flags private-class, compiler-setting and routing prerequisites. Its grouping
is an investigation lead, not approval. `tu_skeleton.py --plan` rebuilds the
stale map in memory and reports 186 approved rows, 50 donor files and 13 mixed
files. A separate current-input in-memory map build confirms that all 15 served
code rows remain proposed, plus the data item at `0x007C5CFC`.

The missing brackets are:

- `Rva000664F4`: `0x000664F4`, `0x0006657B`, `0x0006658C`, with eight
  intervening getter/sampler rows relying on their proposed placement.
- `Rva0006653B`: `0x0006AA45`, followed by proposed `0x0006AB49` and
  `0x0006AB98`.
- `Rva000677CAHost`: `0x0006DC8E`; its sibling `0x000677CA` is already
  approved through contiguity, which does not prove the class's original name.

Target facts: these are existing matched C++ owners, not missing bodies. The
first class has fields at +0x1948, +0x37E4/+0x37E8 and several buffer forwards.
The normal routine calls the existing 16-bit sample owner four times. The
195-byte update body reads map dimensions, resizes a bit vector and calls the
54-byte corner predicate. None of these layout facts independently proves an
original class name or TU.

Donor facts: Zero Hour's BaseHeightMap.cpp defines
`BaseHeightMapRenderObjClass::updateViewImpassableAreas` at line 1715 under
`reference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Source/W3DDevice/GameClient/`.
It is a semantic lead, with different slope preparation and predicate spelling.
The name-evidence run has no canonical candidate for these placeholder classes:
the local ZH same-body cache is absent, and the available BFME 1 cache supplies
no proof for them. The WorldBuilder lead at `0x0006DC8E` is unnamed with score
3; `0x0006AA45` points only to a vector3.h call. No identity promotion or move
is justified here. Resume with a supported naming witness for the bracket owners,
then rebuild the map; do not approve them by adjacency or donor resemblance.

## Completed cleanup

`Common/Rva000677CAHostRva0006DC8E.cpp` no longer forces `/Oy-` or switches
optimization around `<vector>`. Ordinary `/O1` preserves both complete rows
(`0x000677CA`, 54 bytes; `0x0006DC8E`, 195 bytes) and the two previously
pragma-dependent STL copies. This retires two `pragma_optimize` occurrences.

The object retains all nine external COMDAT names and identical exclusive
definition, undefined-external and weak-alias sets. Five COMDAT fingerprints
are unchanged. Four unused const-bit-iterator wrappers lose their frame-pointer
overhead and no longer produce the ordinary preview's codegen diagnostics;
their original names are unchanged. This is not a claim of new retail identities.
The before/after hashes and changed fingerprints are in the adjacent
[object receipt](baseheightmap-approval-cleanup-20261028-codexb.json).

Verification: `./build.sh` passes 2/2 rows; the frozen-file check passes before
and after; `link_check.py --prepare-current` writes a strict reusable receipt;
the ordinary preview retains LINKS for 249 authored bytes at index `41c28839bf`.
The staged hatch check credits 1946 -> 1944 optimization occurrences.

The outgoing batch audit is INCONCLUSIVE: the index predates the base and
affected consumer `Common/0CreateAHeroManager21FE49.cpp` lacks a current receipt.
Carry the changed copies and their consumers into the next normal census.
Full consumer selection, new census-linked bytes, TU approval, source-file
reduction and runtime results are not claimed.
