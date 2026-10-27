# W3DVolumetricShadowV2 TU approval prerequisites

Inspected BFME 2 revision: `62898e64c391d346e06e0f5a55bf61c85e12befd`.
Reference revision: `e74410b3738a2bb75d626085d9ebfd3406a43ff7`.
This is placement investigation, with no source, name, ledger or map change.

The default picker served the TU
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Shadow/W3DVolumetricShadowV2.cpp`
as 29 proposed rows in 14 files (21 noncontiguous, eight unanchored).
The supported `tu_skeleton.py --plan` rebuilds the stale map in memory and
reports **zero approved rows**, one donor, no mixed or refused donors.
An independent call to `tu_map.build(tu_map.Layout(Path.cwd()))` gives 32
proposed entries for this destination, including data and compiler machinery;
this count is a different scope from the picker's code-row count.

## Target facts

The current code assignments at 0x00107046 and 0x00107421..0x0010837F remain
proposed and noncontiguous. The intervening entries below are independently
anchored to `W3DProjectedShadow.cpp` by the current names and Zero Hour tree:

| RVA | Current row | Fresh map signal |
| --- | --- | --- |
| 0x0010713A | W3DProjectedShadowManager::rva0010713A | S, approved |
| 0x00107152 | deleting-destructor body | C, approved |
| 0x0010716D | W3DProjectedShadowManager::ReAcquireResources | Z/S, approved |
| 0x001072C9 | W3DProjectedShadowManager::rva001072C9 | S, approved |

The DX8Wrapper::Set_World_Identity body at 0x0010737E is **displaced** in
the fresh map; it is not an approved competing anchor here.

WorldBuilder's file leads at 0x00107D8A, 0x00107E76 and 0x0010811E
name W3DVolumetricShadowV2.cpp, but `tu_map.wb_self` returns true for all
three: their names/notes already took that lead. They cannot independently
anchor their own naming hint. The lead at 0x00107F8B is not self-derived,
but its own N hint names W3DVolumetricShadowManagerV2.cpp instead. The
0x00106CF0 and 0x00107961 leads reach placeholder classes with no N hint.
The global W precision gate passes; these local corroboration restrictions
still apply. No target __FILE__ reference was found by the scoped planner.

## Donor facts and limits

BFME 1's `targets/game/reverse/ea_evidence.csv` records its own
W3DVolumetricShadowV2.cpp run, including LockVBandIB at 0x007C1430,
FlushVBandIB at 0x007C1BF0, UpdateAndRender at 0x007C2A00,
UpdateAndRenderZfail at 0x007C2B50 and RenderShadowsNoInitialFill at
0x007C2CD0. These are BFME 1 addresses and file evidence, not BFME 2
placement or permission to rename a BFME 2 owner. The existing BFME 1
same-body cache supplies no record for BFME 2 0x0010713A, 0x0010716D,
0x001072C9 or 0x00107046.

The source comment in W3DProjectedShadowManagerReAcquire.cpp says the
BFME 1 owner name was used for the target's two-buffer view. Whether that
owner is really the V2 buffer manager is an identity lead, not a proven
rename. The converged global TheW3DProjectedShadowManager and all actual
projected-shadow owners must be preserved while investigating it.

## Verification and next work

`./build.sh` on the unchanged seed passes both rows (236 + 277 bytes),
with string, float and import reference checks passing.
`find_declared_unmatched.py` reports no frozen definitions.
The naming planner lists ten selected sources, 5,175 unique bytes and
38 static blockers; no group is statically clear. Besides placement,
private class declarations, differing compiler settings and the existing
constructor assembly prerequisite remain. The earlier constructor-sqrt
handoff must be read before repeating that trial.

First prove the buffer-owner identities against BFME 2 callers, native
storage and reference bodies, then use the naming tools for any supported
correction. Separately obtain an independent target-backed anchor for V2;
reusing a WorldBuilder-derived name to corroborate itself cannot do that.
Rebuild the map in memory and rerun the supported plan before any merge.
No TU approval, file reduction, linking improvement or coverage gain is
claimed by this investigation.
