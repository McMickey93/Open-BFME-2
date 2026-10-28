# GameLOD port seed cleanup, 2026-10-28

Scope: `Code/GameEngine/Source/Common/GameLOD.cpp`, claimed as a file.
Parent: `3215f31ebe`. This is source cleanup, not new matching, a TU merge,
or a census linking gain. No source path or ledger identity changes.

## Evidence and change

The Common consolidation planner's GameLOD packet has 19 donor candidates,
49 approved rows and five mixed files. Its original-path evidence and private
declaration/flag blockers were read before the trial. An ordinary full merge
dry-run spent over eight minutes testing combinations and was interrupted;
it produced no final acceptance result and no merge was applied. The seed's
obsolete port bodies are a smaller independently verifiable prerequisite.

Remove thirteen unrowed definitions and their existing present-unmatched
markers: StaticGameLODInfo and DynamicGameLODInfo constructors;
GameLODManager::newBenchProfile, refreshCustomStaticLODLevel,
getStaticGameLODLevelName, setStaticLODLevel, applyStaticLODLevel,
findDynamicLODLevel, setDynamicLODLevel, applyDynamicLODLevel,
getRecommendedTextureReduction, getLevelTextureReduction and didMemPass.
These use the port's class surface/layout, not the native owners' contracts.
Remove two now-unused private views and replace the unused Shell method
declaration with a forward declaration. Keep TheShell and TheGameLODManager.

Target facts: native allocation is rowed at 0x0020200D, static setting at
0x00202739, static application at 0x002022E9, dynamic lookup at 0x00202613,
dynamic setting at 0x0020276C and dynamic application at 0x00202633, under
their existing placeholder/view owners. Their offsets and strides differ
from the port declarations. This correspondence does not establish new
names or approve class layouts. No native owner is renamed or replaced.
The historical uncertainty over the 0x00202C30 getter is unchanged.

Retain INI::parseStaticGameLODLevel and its existing exemption: the retained
BFME static field table references it. Its exact target contract and the
remaining private class/string declarations need separate reconciliation.
Keep all seven matched bodies, tables, compiler flags and global providers.

## Verification and bounds

Evidence prefix: `build/gamelod-seed-cleanup/` (scratch, not tracked).

- Frozen-file checks before/after: seven matched bodies remain; unclaimed
  definitions fall from fourteen to one, all covered by existing exemptions.
- `./build.sh` passes GameLOD 7/7 (572 bytes) and current OptionsMenu 1/1
  (27 bytes), including string/import/reference checks. Strict
  `link_check.py --prepare-current` produces reusable receipts for both, 8/8.
- Final object comparison: all 95 shared COMDAT providers are identical,
  no new definitions, unchanged COMMON providers and alternate directives.
  Removed external definitions are precisely the thirteen bodies and the
  now-unused 1.0f constant, which has many other indexed providers.
- The index's reference edges contain no outside caller of the thirteen
  removed names. A scan of 22,654 indexed cache paths finds one old
  OptionsMenu object referencing three names. Its current source has already
  removed those callbacks; its rebuilt, byte-verified object references none.
  One indexed cache object is missing and 17,357 differ from indexed digests;
  this scan is corroboration, not a complete current-image closure proof.
- Code identity: 33 references, zero wrong bindings. Enforced data check:
  zero findings. Converged check: ten addresses, zero second names/unjudged.
- Ordinary preview against index 73061d9452 (2026-10-27 14:34): GameLOD
  LINKS 572 -> 572 bytes before/after; current OptionsMenu also LINKS.
  Thus the prior Shell::showShellMap obstacle is absent in this preview;
  that method is now rowed at 0x0035C194. No linking increase is claimed.

The fetched index lacks `touches` and current per-object reference provenance.
The outgoing consumer audit therefore remains inconclusive under LINK-017;
strict receipts for two explicit providers do not repair that index schema.
Carry removed-provider closure into the next normal census. No nightly,
link-cycle or smoke runner was started.

`hatch_counters.py --update` refuses two pre-existing alternatename occurrence
keys in WWLib/StlVectorRva0021582C.cpp (_Construct and _Destroy). No admission
or register edit is made. Thirteen source exemptions disappear, but the
register remains loose until that unrelated growth is resolved and the
supported shrink can run. No registered debt retirement is claimed.

The remaining consolidation prerequisites include private GameLODManager,
CpuType/GlobalData and string declarations, donor compiler flags and the
static parser/table contract. No claim of full TU admission or fewer source
files follows from this cleanup.
