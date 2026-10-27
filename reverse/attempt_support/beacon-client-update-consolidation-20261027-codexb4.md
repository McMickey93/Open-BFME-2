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

## Historical saved merge (superseded by upstream)

The following receipts describe the preserved pre-rebase experiment.
They do not replace the current upstream composition described above.

## Applied subset and verification

After prerequisite commit `46e96d6de7`, reran the naming planner against the
changed inputs. The supported applying merger accepts exactly the destination
and CleanupHazardUpdateCtor.cpp, deletes the latter, and repoints the constructor
row at 0x004C964C. Only that row's source cell changes in functions.csv and
in the existing tu_map.csv; no regenerated map is committed. The destination
has 14 rows; the four surviving files keep all 17 original scoped rows.

- The merger's LinkGuard passes with all five census-linked original inputs
  protected, including external providers, selected COMDATs and binding context.
- Normal scoped build: 17/17 rows, one data row, three literals and three float
  references verified. Five compiler labels resolve through exact parent EH
  data. The destination has four EXACT EH graphs after compilation.
- `link_check.py --prepare-current` repeats the normal 14-row destination byte
  gate and writes its strict reusable receipt without modifying the census.
- allowed_symbols: 53 references, 41 owner, four EH, four alias, four fold;
  zero wrong bindings. Staged TU ownership, declared-body and CSV checks pass.
- Converged data: ten addresses checked, zero second names or unjudged rows.
  Shadow data retains the same existing getter key/guard wrong-name facts at
  0x00A04334/38 documented in the 2026-10-26 receiver handoff. The old baseline
  key stays registered. There is no donor data/code-identity key to transfer.
- Header and Microsoft-header queues have no entries for either input. The
  merger refreshes destination header reporting through its owning APIs.
- The owning hatch tool transfers the one existing empty-destructor marker.
  Its whole-tree update also drops stale permissions for 14 alternatenames
  already removed from Upgrade sources and three address-global occurrences
  already removed from Rva00789900Init.cpp. No source hatch is added; this
  tightens the register to the existing tree. The merge trailer covers this
  tool-owned register update.

## Outgoing path-consumer audit

The unpublished range starts at common base `8e3640cb05`; the audit includes
all earlier queued commits through `46e96d6de7` and this staged merge. There
is exactly one removed or renamed source in that complete batch:
CleanupHazardUpdateCtor.cpp -> BeaconClientUpdate.cpp. Other outgoing source
changes are edits at retained paths. No directory moves occur.

Searched the full old path and basename through source, reverse registers,
tools, hooks, workflows and documentation. Seven mentions remain: historical
link status, destination provenance, the original factory-evidence comment in
CleanupHazardUpdateFriendNew.cpp, prior attempt evidence, and this pass's
handoffs. None is an active include, build input or path consumer. Preserve
these history references. No tooling consumer requires a change. Active
function/map/hatch ownership now resolves to the surviving destination;
data and code-identity registers retain their existing owner paths.

The ordinary preview retains the census's deleted donor and reports duplicate
constructor/destructor definitions and a constructor selected-copy mismatch
after composition. The apply-time guard evaluates the actual donor removal
with the destination. Carry this index freshness limit and the pending
runtime/census confirmation into the next scheduled census.
