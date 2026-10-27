# W3DSmudge ReAcquireResources consolidation

Seat: codex5; starting tree 51d6830ba1; 2026-10-27.

## Prerequisite reconciliation

The default picker claimed W3DSmudge.cpp, W3DSmudgeManager_ReAcquireResources.cpp
and W3DSmudge_copyRect.cpp. The current BFME 1 freshness receipt was checked.
The GameClient name_lane consolidation report was regenerated after source
changes. Its donor/original-path leads do not independently prove a retail
source path; destination approval comes from tu_skeleton's rebuilt current map.
Four mixed files remain satellites, not split candidates in this pass.

Initially the ordinary dry run rejected ReAcquireResources for bytes and
copyRect for the already recorded D3D8/D3D9 header conflict. The former has two
separate causes. The donor's temporary wrapper inherited the seed's unrelated
SurfaceClass layout, and the seed's qualified WW3D2/dx8indexbuffer.h bypassed
its existing BFME indexbuffercount include directory. Composition consequently
called the unprovided unsigned-short-count constructor instead of the rowed
unsigned-count constructor. A read-only Verifier pair trial isolated that exact
unresolved relocation at body offset 101; no new body or pin was needed.

The wrapper now independently owns one pointer, matching the existing
W3DGetBackBufferSurface.cpp and W3DRadarResetSurface_destructor.cpp target
reconstructions. The Get_Description call keeps its existing SurfaceClass call
view through a cast. This describes a call ABI, not a proven engine inheritance
or recovered donor layout. The seed explicitly includes the existing BFME
index-buffer shim by relative path. Both units use that shim's void unlock
interface; the pre-existing alternate name in BfmeDX8ThreadLock.cpp resolves it
to the retail bool-returning function. No header, alias, pin or hatch is added.

Verification before merging:

- Ordinary ./build.sh: 15/15 exact rows; all four renumbered unwind labels are
  placed by exact parent EH data. eh_verify: three EXACT graphs.
- Declared-unmatched, class gate and shadow data checks pass (zero data findings).
- Object comparison covers all 550 seed and four donor external definitions:
  identical bodies, extents, relocation referents, section flags and COMDAT
  selections after normalizing only the established void-to-bool unlock alias.
  Both undefined-name sets are identical under that same normalization.
- The ordinary dry run now accepts seed plus ReAcquireResources, 15 rows.
  copyRect still fails at IDirect3DSurface9; four mixed files remain untouched.
- Joint current-object link preview of all three Smudge units and the current
  BfmeDX8ThreadLock/Check providers: 5/5 LINKS. The older bf3dd31211 index alone
  retains LINK-106's stale thread-lock provider. This confirms the existing
  repair and proves the unlock alias in this scope; it is no census gain.

Scratch receipts: build/codex5-smudge/{pair.log,pair-shim.log,prereq-build.txt,
compare-prereq.py,compare-prereq.txt,prereq-dry-run.txt,prereq-link.txt,
prereq-variants.txt}. Trials used tu_skeleton.Verifier, never a manual shared
match-cache compile. Source/header paths are unchanged in this prerequisite
commit; active consumers need no repointing. Code/data/header registers contain
no key for either edited source. No debt retirement or newly authored bytes
are claimed by the prerequisite.
