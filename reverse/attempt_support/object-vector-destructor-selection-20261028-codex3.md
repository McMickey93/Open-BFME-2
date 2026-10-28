# Object-pointer vector destructor selection: blocked attempt

2026-10-28; control `3bb77a8a89`; owner `yasinschroeder-codex3`.
Ordinary-preview index `54b83e4f69` (2026-10-28 09:35), retail-truth-4.
No source change, new row, pin, alias or hatch is retained.

## Target facts and existing owners

The default claimed link pick was SplitHordeSpecialPower::doSpecialPower,
0x004C861E, 123 bytes, in
`Code/GameEngine/Source/GameLogic/Object/SpecialPower/SplitHordeSpecialPower_doSpecialPower.cpp`.
Its three rows byte-match. Ordinary preview rejects the selected destructor
`??1?$vector@PAVObject@@V?$allocator@PAVObject@@@_STL@@@_STL@@QAE@XZ`.

The index's earliest definition is in
`Code/GameEngine/Source/GameLogic/SkirmishAI/AIBuilder.cpp` (position 1996):
14 bytes, digest `40c8cdf2d9e5`, verdict `wrong`. Later retail definitions
already exist in GenericObjectCreationNuggetReallyCreate.cpp (position 2737)
and GenericObjectCreationNuggetWaypointPick.cpp (2738). This is an existing
provider-selection obstacle, not a lost row or missing destructor recovery.

The matched destructor owner at 0x001F22A3 is
`Code/GameEngine/Source/GameLogic/Object/GenericObjectCreationNuggetWaypointPick.cpp`.
Retail's five-byte vector destructor jumps to the 43-byte `_Vector_base`
destructor at 0x001F1609. Their normalized object digests are respectively
`857bdaa39a22` and `9603c5bad87f`.

AIBuilder::checkForNewUpgrades, 0x004ECA01, 280 bytes, uses a local
`vector<Object *>`. Its normal cleanup inlines the null check/deallocation,
whereas unwind 0x007928AC is `lea ecx,[ebp-20h]` followed by a jump to
0x001F22A3. The existing local import/forceinline specialization suppresses
the non-retail base destructor; it leaves a non-retail vector destructor.
These are target/object observations. No donor path or recovered class layout
is inferred from the same template name.

## Rejected clean-C++ trials

Each trial started from the current AIBuilder source, used `./build.sh`, and
was reverted. No hand compilation through `build.compile_source` was used.

| Trial in AIBuilder | Byte verification | Rejection |
| --- | --- | --- |
| Add import/forceinline vector destructor containing `_Destroy` | 28/29 | Normal body remains exact; unwind 0x007928AC no longer resolves to its verified compiler label. |
| Declare vector destructor without a body | 28/29 | Normal cleanup becomes an out-of-line call and changes the parent body; unwind remains compatible. |
| Add import/inline vector destructor without forceinline | 27/29 | Parent and unwind change; imported call appears. |
| Replace the base suppression with the existing provider's allocator destructor bookkeeping and switch `/EHsc` to `/EHs` | 26/29 | Parent and both upgrade-check unwind rows change. |
| Keep `/EHsc`, use that allocator destructor, and declare the base allocator constructor without a body | 28/29 | Both standalone destructors become retail-correct, but allocator EH state and normal cleanup change the parent. |

The last trial replaced the original base import/forceinline specialization
with these declarations (rejected evidence, not a proposed fix):

```cpp
namespace _STL {
enum { _STLP_LEAKS_CHECK = 0 };
template <> allocator<Object *>::~allocator() _STLP_NOTHROW {
    if (_STLP_LEAKS_CHECK) free(this);
}
template <> _Vector_base<Object *, allocator<Object *> >::_Vector_base(
    const allocator<Object *> &);
}
```

The existing waypoint provider's allocator-model comments already distinguish
its EH configuration from the native copy-constructor configuration. Merely
transplanting that model does not preserve AIBuilder's parent. A useful next
hypothesis must account jointly for the normal inline cleanup, the out-of-line
unwind target, and allocator temporary lifetime. Repeating destructor-only
suppression or the table's configurations adds no new evidence.

## Restored verification and remaining scope

After restoring AIBuilder exactly to the control revision:

- `./build.sh` on AIBuilder.cpp, SplitHordeSpecialPower_doSpecialPower.cpp and
  GenericObjectCreationNuggetWaypointPick.cpp: 42/42 rows, two string literals
  and two float literals pass.
- `tools/eh_verify.py` on those three sources: seven EXACT, zero missing or
  non-exact graphs. Both edited/planned sources pass declared-unmatched checks.
- AIBuilder's external COMDAT digests/verdicts, definitions, undefined symbols
  and weak aliases equal the saved pre-trial `link_check.object_facts` result.
- The 18 current source paths in the index's destructor `touches` cohort were
  previewed before and after restoration: 0/18 link cleanly in both runs;
  blocker output is identical apart from elapsed time. Those previews are not
  byte verification of all 18 sources. Other container operations and unrelated
  prerequisites remain in the cohort.

No selected-provider clearance, census improvement, debt retirement, runtime
result or image-ownership result is claimed. Carry this provider/cohort into
the next normal census after a source repair; do not reorder providers or add
a selection exception to hide the mismatch.

The overdue BFME 1 reference check fetched official upstream: the clean pinned
checkout is `e74410b3738a2bb75d626085d9ebfd3406a43ff7`, while upstream master
is `adf77bcb429fe6a7db211bfb2806e69a31f667ca`. The upstream delta has no header
changes. The reference-update scope claim is held by another worker, so no
submodule update, full reference verification or freshness-marker success was
recorded here. This remains a separate freshness prerequisite.
