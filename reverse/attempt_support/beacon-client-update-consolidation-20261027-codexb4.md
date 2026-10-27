# BeaconClientUpdate consolidation

Inspected `7e46850c88`, 2026-10-27, seat codexb4. The default picker
claimed the destination and four clean donors. BFME 1 reference verification
is dated 2026-10-26 and remains fresh.

## Routing and initial blockers

`name_lane.py consolidate --under Code/GameEngine/Source/GameClient/Drawable/Update/`
records WorldBuilder, Zero Hour and BFME 1 EA original-path hints for
BeaconClientUpdate.cpp. These are routing evidence, not a new source/name proof.
The committed TU map is stale; `tu_skeleton.py` rebuilds the current approval
map in memory and approves 19 rows. ConstIntGetters4.cpp and
ModuleDataBuildFieldParse.cpp remain mixed and are never split by this merge.

The initial supported dry run accepts no donor: the receiver prefix header
has no constructor or xfer member, the module-data constructor declares private
m_i08/m_i0C rather than the existing consumer fields, and the guard clearer
fails the composed byte check. All 17 current rows in the five claimed sources
verify normally; the destination has four EXACT EH graphs. All five ordinary
previews LINKS against bf3dd31211 (2026-10-27 00:39, retail-truth-4).

## Verified declaration prerequisite

CleanupHazardUpdateCtor.cpp now exposes the same unsigned fields at +8 and
+12 already read by BeaconClientUpdate.cpp: framesBetweenRadarPulses and
radarPulseDuration. The constructor still initializes 30 and 15; the vptr,
unused +4 word and empty destructor are preserved. This reconciles existing
views of the same data class without claiming its complete native interface.

`./build.sh CleanupHazardUpdateCtor.cpp` verifies the sole 23-byte row;
find_declared_unmatched reports all definitions matched (the existing counted
marker covers the empty destructor). Ordinary preview retains LINKS, 23 bytes.
A fresh supported merge dry run accepts the destination plus this donor:
14 rows, current census-linked units protected by LinkGuard. The receiver
constructor, xfer and guard-clearer donors remain rejected. This is a compiler
and link-guard verdict, not census progress.

## Remaining prerequisites

- Reconcile BeaconClientUpdateView.h's accessed prefix with the native
  constructor and ObjectModule xfer contracts before moving those donors.
- Resolve the standalone 0x007904F3 guard clearer against the parent getter's
  exact EH graph. It still defines g_Va00E04338, so the getter's registered
  data finding is not merely an index spelling refresh and is retained.
- Keep mixed donors and all protected keys until their normal owning tools
  approve a separate change. No runtime or image-ownership result is claimed.

## Recovery reconciliation (2026-10-28)

Upstream `d1ad85b05a` supplied shared receiver/module-data declarations;
`4b5c353408` merged the ctor plus the other clean donors into the approved
BeaconClientUpdate.cpp. The guard clearer was retired by `e58affe130`.
Keep those changes, which supersede the remaining prerequisites listed above.
Do not restore the deleted constructor donor or older private class views.
This handoff retains the original experiment and checks as historical evidence.
