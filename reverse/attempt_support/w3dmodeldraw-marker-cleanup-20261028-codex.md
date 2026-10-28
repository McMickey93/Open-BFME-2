# W3DModelDraw release marker cleanup, 2026-10-28

Inspected BFME 2 revision: `679dc61cf0`. Source:
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DModelDraw.cpp`.
Ordinary preview index: `14dc3d2467`, 2026-10-28 02:44 UTC.

## Retained change and evidence

Five LogClass definitions (constructor, destructor, log, dumpMatrix3D and
dumpReal) are inside `DEBUG_CRC && (_DEBUG || _INTERNAL)`. The normal release
object emits none of their names. Correct their retail-present exemptions to
`absent-from-retail`, with the release exclusion documented at the guard.
Remove the second identical W3DAnimationInfo assignment exemption; the single
real assignment keeps its existing exemption. The hatch register shrinks by six
occurrences, through five deleted keys and one count reduced from two to one.
This is exemption cleanup, not recovered C++ or new matched bytes.

Both normal `./build.sh` runs pass all six rows (198 bytes), string, float and
import reference checks. The final frozen-file check passes. Read-only COFF
comparison using `link_census._comdat_sections` and `object_facts` proves all
1,209 named COMDAT byte/relocation digests unchanged, as well as the sets of
67 strong definitions and 109 undefined externals. Both objects have no weak
externals or COMMON definitions. No provider or consumer binding is changed.
Scratch comparison: `build/w3dmodeldraw-cleanup-codex/object-comparison.json`.

## Reverted optimization-anchor trial

The VCI and WeightInfo anchors were removed together as a bounded check for
obsolete optimization hatches. All six rows stayed exact, but eight emitted
COMDATs changed. The vector constructor iterator changed from 34 to 50 bytes
and WeightInfo's vector deleting destructor from 81 to 92 bytes. Six unrowed
port bodies also changed: adjustAnimation, clientOnly_getRenderObjBoundBox,
handleWeaponFireFX, recalcBonesForClientParticleSystems,
updateBonesForClientParticleSystems and validateCachedBones. Restore both
anchors and their existing pragmas. No trial code or pin changes are retained.

## Remaining linking work

The original and final ordinary previews both remain blocked, with 13 unresolved
names, five COMDAT losers and three wrong-selected definitions, and zero
predicted linked bytes for this source. The census checklist's 12 unresolved
names is historical; it is not a current result.

Unresolved families include RenderObjClass/Drawable/ParticleSystem interfaces,
DrawModule CRC, W3DDisplay's asset manager, BitFlags name storage, and three INI
scanners. Current scanInt, scanReal and scanIndexList owners are nonstatic
members; the port refers to static spellings. A pin cannot repair that ABI.
The animation `_Construct` and vector overflow, and the BitFlags `__copy`
helper have pins but no matching-name code rows; declaring the wrong copies
away alone does not establish a correct native provider. Reconcile those
native contracts and emitting headers before another removal trial. Do not
remove the whole port: its six matched rows still depend on emission context.
No strict closed-world link, new census gain or runtime result is claimed.
