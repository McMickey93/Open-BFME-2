# Linking obstacle register

Required reading before selecting linking work; required updates with repairs
and attempt handoffs, and before ending a linking pass. Workflow:
[linking.md](linking.md#shared-obstacle-register). This is a shared handoff,
not an authoritative progress counter. Claim work through the normal claim tool.

Read the [linking target checklist](linking_targets.md) alongside this register
when selecting work. Update affected target rows with results, evidence and
remaining dependencies in the repair or handoff commit.

## Maintaining this register

- Update only the entries your evidence affects. Record the date, source revision,
  affected symbols/units, work completed, verification result, remaining blockers
  and next useful check. Link a repair commit or tracked attempt evidence. For
  previews, identify the index revision, current-input checks and measured scope;
  put detailed receipts in the repair's normal evidence location.
- Reuse an existing ID for the same cause; give a new cause the next unused
  `LINK-NNN` ID. If a broad entry is only partly repaired, keep it open and list
  the repaired subset or split off a narrower entry. Do not mark a whole family
  cleared because one consumer links.
- Use **Open** for an unresolved lead, **Blocked** with a named prerequisite,
  **Repair landed / awaiting verification** for an unconfirmed repair, and
  **Cleared** only with verification of the stated scope against current inputs.
  State separately whether a later census confirms it. A preview clearance does
  not change the headline; a source edit or provider's existence alone is not
  proof that its consumers now link.
- Keep cleared entries and their evidence. Reopen an entry with the new failing
  revision and evidence if it regresses. Preserve other agents' updates when
  rebasing. Do not repeat an unchanged failed trial without new evidence or a
  resolved prerequisite.

For a new entry, use this shape:

```text
### LINK-NNN: concrete cause and affected scope
Status: Open. Updated: YYYY-MM-DD; inspected revision: <SHA>.
Evidence / affected units: <symbols, files, tracked evidence, index revision>.
Completed: <repair or attempt, commit and measured result, or none yet>.
Remaining / next check: <specific dependency and how to verify it>.
Clearance: <scope, current-input verification and evidence, or pending>.
Census confirmation: <published measurement revision, or awaiting / not claimed>.
```

## Baseline for the initial entries

Seeded on **2026-10-25** from the investigation at `76efac458e`.
The historical census measured `d2636bb381` at **2026-10-25 09:42 UTC**;
its status was published by `b78c9ed16e`. It records **7,343,016 / 7,512,658
executable-game bytes (97.7419%)**, leaving 169,642 bytes and 385 blocked units.
Use the published status: the status file inside the measured commit itself
describes the preceding census.

The official provider index inspected had provider facts updated to `51fde01dff`
at **2026-10-25 13:53 UTC**, but retained the 09:42 census's blocker lists.
Index SHA-256:
`7225d4beb4d607e264bb010fef0dc8fdcb36d15b684d16fc7e654ee776a037ed`.
Thus the counts below are historical leads, not freshly measured failures on
master. Recheck current inputs before choosing work. The register's initial
entries claim no new census or current-master compile result.

Start by verifying landed repairs, then reconcile container identities and
shared headers/providers in coherent batches. Do not total overlapping units,
authored-byte previews or commit-title gains into a projected headline.

## Obstacles and handoffs

### LINK-001: landed repairs still appear in the historical census

**Status: Repair landed / awaiting verification. Updated: 2026-10-25.**

- **Evidence / scope:** the deleting destructor
  `??_EWeightInfoStruct@NamedPivotMapClass@@QAEPAXI@Z` blocked 34 graphics units;
  it was the sole blocker in 30, holding 45,189 authored nonpadding bytes
  (about 45 KB). The inspected provider index now has 33 retail-correct copies
  with identical digests. Provider evidence alone does not remeasure consumers.
- **Verified graphics subset (2026-10-25, `91fe970939`):**
  [the bounded verification](../reverse/attempt_support/weightinfo-verification-20261025/readme.md)
  passes 404/404 matched rows across all 34 units. Current-object inspection
  confirms 33 retail-correct copies and a correct selected body; W3DScene
  intentionally stopped emitting the incorrect copy. No destructor blocker
  remains in these 34 objects. The ordinary preview links all 30 historical
  sole-blocker units, covering **45,204 authored nonpadding bytes**. The other
  four retain unrelated dependencies, listed in that evidence. This graphics
  subset is **cleared in the bounded ordinary-preview scope**; census and
  closed-strict confirmation remain unclaimed. Strict receipt prerequisites
  found during verification are tracked separately as LINK-008.
- **Completed:** `51fde01dff` removed W3DScene's nonretail emission; its source
  was unchanged at investigation time. The earlier graphics gains overlap.
  Other landed repairs also have scoped evidence:
  [PlayerTemplate bucket copy](../reverse/attempt_support/object476-copy-link-20261025/readme.md),
  [record helpers](../reverse/attempt_support/asciistring-record-link-20261025/readme.md)
  and [narrow strings](../reverse/attempt_support/narrow-string-selective-link-20261025.md).
  Several historical `_Destroy` names already resolve to defined providers.
- **Remaining / next check:** check the next normal maintainer census for the
  verified graphics subset. Verify the other landed repair families' current
  consumers and providers before attempting another repair.
  Do not reopen a repaired name solely because `link_rank.py` still lists it.
- **Range-worker current-input check (2026-10-25, after `e302344089`):**
  [the paired range-worker proof](../reverse/attempt_support/range-destroy-link-20261025/readme.md)
  verifies 71/71 rows, 7 EXACT exception graphs and three strict receipts.
  The provider and both deferred-vector consumer files already preview cleanly
  with current alias handling, despite the historical unresolved names. One
  real whole-body C++ instantiation replaces its old alias and retires one
  hatch key; the paired before/after preview preserves all 2,978 authored
  bytes and claims no new linking gain. The other alias remains debt.
- **Stale string identity keys retired (2026-10-26, `fce2c6327a`):**
  [the forward-range caller check](../reverse/attempt_support/string-range-identity-retirement-20261026.md)
  confirms BfmeConv1486.cpp, BfmeConv1428.cpp and BfmeConv1438.cpp already bind
  the recovered insertion owner. All three whole callers remain exact
  (285, 42 and 47 bytes). After normal refresh of two newly consolidated
  upstream objects, the owning identity tool retires three stale keys, with
  zero remaining findings for each source. These callers are already
  census-linked; their existing code and the provider's separate closure
  work are unchanged. No C++ conversion or new linked-byte gain is claimed.
- **Window video follow-up (2026-10-26, `9e1ca7f93f`):**
  [the verified marker cleanup](../reverse/attempt_support/window-video-debt-cleanup-20261026.md)
  retires 15 stale unmatched exemptions; all 38 rows (2,155 bytes) and seven
  EH graphs remain exact. Current INI/lower-bound providers make the unchanged
  window bodies preview LINKS for 2,116 authored bytes. This confirms earlier
  repairs, not a new linking gain; the joint command retains INI's separate
  historical-index blockers. Four identity keys remain, with the narrow EH
  retirement discrepancy tracked in LINK-061.
- **Clearance / census confirmation:** graphics ordinary-preview scope cleared
  at the revision above; other families and census confirmation remain pending.
  Keep individual repair previews separate from later census confirmation.
- **Consolidation outgoing-batch audit (2026-10-26, `a590d451c6`):** the
  outgoing source diff contains 42 paths. `tools/link_batch_audit.py --base
  origin/master --tip HEAD` is inconclusive: its provider index is at
  `763dc8759f`, not outgoing base `d831bc2403`, and 26 changed source objects
  lack current receipts (first:
  `Code/GameEngine/Source/Common/ExperienceLevelSystem.cpp`). It returned
  before selected-provider, consumer-binding or lost-byte comparison. Separately,
  the RadarUpdate and staged HordeTransportContain composition rows passed
  byte and EH checks; the staged data check reported zero findings. Code
  identity remains shadow and reported eight new unreferenced `alternatename`
  findings in the Horde TU. These checks do not establish link bindings. Carry
  the batch to the next current census; do not claim provider changes, losses
  or clearance from this preview.
- **Sol prerequisite freshness handoff (2026-10-26, `73ffc391c4`):**
  [Radar, particle-bone and unit-crate receiver evidence](../reverse/attempt_support/consolidation-sol-prerequisites-20261026-codex.md)
  preserves matched bytes and existing object/binding facts; the outgoing gate
  passed 39 rows and eight EXACT EH graphs across eight sources. The new batch
  audit is **inconclusive**, not a clearance: provider index `51fde01dff` predates
  outgoing base `6cdb77c875`, and all eight objects lack accepted strict-current
  receipts (first: AnimatedParticleSysBoneClientUpdate.cpp). It returned before
  selected-provider/lost-byte analysis. No lost bytes were measured. Next check:
  claim the affected sources and use supported bounded `link_check.py
  --prepare-current` to establish strict receipts, diagnose any inventory
  refusals along LINK-008, then carry confirmation into the next normal census.
  No maintainer-only measurement or repeated batch audit was started here.

### LINK-002: distinct container element identities and exception contracts

**Status: Open. Updated: 2026-10-25.**

- **Evidence / scope:** equal-sized `BfmePod28` / `BfmePod32` views conflate
  native types with different constructors and copy operations. The
  [element-split handoff](../reverse/attempt_support/pod-element-split-20261023/readme.md)
  names the provider and consumers: the vector at `0x00541434` calls copy helper
  `0x005411C8`, while its current spelling resolves to `0x00215F38`; the vector
  at `0x0052C823` calls `0x0052C27E`, not `0x00421D28`.
- **Completed / failed trials:** the
  [vector exception-contract bank](../reverse/attempt_support/vector-587c40-construct-link-20261025/readme.md)
  shows that a throwing copy declaration preserves the 189-byte parent but emits
  the wrong helper; `throw()` fixes that helper while breaking the parent.
  Suppressing the control overflow definition also broke another matched row.
  These trials were restored; they are not repairs.
- **Remaining / next check:** reconcile element identity, native callees,
  ownership, shared declarations and EH contracts together. Verify every
  affected provider, consumer and emitted copy. Size equality and a renamed
  template do not prove a shared native type. Clearance and census confirmation
  remain pending.
- **AerialPathfinder concrete candidate (2026-10-25, `27b23d675b`):**
  [the native-list bank](../reverse/attempt_support/aerial-native-list-link-20261025/readme.md)
  identifies a conflation between the constructor's `BfmePod8` destructor pin
  at 002FECBC and this family's actual cleanup at 004EC395. Private adoption
  of the canonical subsystem base and the target query's polygon/height entry
  preserves the 75/59/28-byte parent/wrapper bodies and both exact EH graphs.
  No production repair was applied: required helper addresses 0014F3C4 and
  004EC395 were reserved by other workers. Resume through normal folded-body
  admission and current-input provider/consumer gates when claims permit;
  preserve the shared pin and do not equate unrelated equal-sized records.

### LINK-003: residual Zero Hour memory-pool interfaces

**Status: Open. Updated: 2026-10-25.**

- **Evidence / scope:** historical blockers include `MemoryPool::freeBlock`
  in 21 units and `allocateBlockImplementation` in 15; these sets overlap and
  predate later repairs. The inspected provider index has neither operation.
- **Completed:** `d7d2a0c653` changed the sweep `GameMemory.h` to BFME 2's native
  virtual destruction / global delete and global allocation contract. BFME 1
  and ZH interfaces remain reference leads, not proof of BFME 2 behavior.
- **Remaining / next check:** find residual imported declarations and callers,
  prove their native BFME 2 contracts, and repair the class/header family.
  [Scripts.cpp's handoff](../reverse/attempt_support/network-byte-setter-astra-s2-20261023/readme.md)
  records pool calls alongside ScriptGroup/OrCondition, signed-byte and parser
  ABI blockers. Removing a pool call does not clear those other dependencies.
  Verify the affected consumers together; clearance and census confirmation
  remain pending.

### LINK-004: missing or incompatible shared providers and declarations

**Status: Open. Updated: 2026-10-26.**

- **AITNGuard scan prerequisite (2026-10-26):**
  [the shared Object receiver](../reverse/attempt_support/consolidation-guard-scan-prerequisite-20261026-codex.md)
  makes the seed and scan donor compose: six existing rows / 595 bytes,
  previously none accepted. Both strict current objects preserve code/data,
  COMDAT policies and provider/consumer facts; exact EH placement resolves
  renumbered cleanup labels without altering the ledger or identity checker.
  Eight other donors still need state-machine/body/AI-data declarations.
  A forward-declaration-only StateMachine trial admitted no further donors:
  its callers require the full receiver declaration. The trial was reverted
  and its exact compile boundary is recorded in the handoff and attempt log.
  A standalone-inline ordering follow-up retained all six exact rows but the
  frozen-file check refused its newly exposed unrowed helper; it was restored
  before any further composition trial. Full receiver reconciliation remains.
  No merge, debt retirement, census gain or later Luna landing is claimed.
- **DefaultProductionExitUpdate Xfer prerequisite (2026-10-26):**
  [canonical operand adoption](../reverse/attempt_support/consolidation-default-exit-xfer-prerequisite-20261026-codex.md)
  retires one header-queue row while preserving all three matched rows, the
  exact EH graph, 37 code definitions, 42 non-debug sections and every
  code/data reference fact. No provider or consumer binding changes.
  Composition still accepts no donors: pool/constructor members and legacy
  Coord3D/Xfer definitions remain incompatible. No merge unblock, identity
  retirement, census gain or later Luna landing is claimed.
- **SupplyWarehouseDockUpdate Xfer prerequisite (2026-10-26):**
  [Canonical integer transfer](../reverse/attempt_support/consolidation-supplywarehouse-xfer-prerequisite-20261026-codex.md)
  retires one header-queue row with 4/4 seed/donor rows exact and identical
  emitted code/data, COMDAT policies and reference facts. No binding changes.
  Composition still accepts no merge: allocator specialization, supply-truck
  receiver and pool-member declarations remain prerequisites. Mixed donors
  are untouched; no identity retirement, census gain or Luna landing claimed.
- **WeaponBonusUpgrade receiver prerequisite (2026-10-26):**
  [The shared partial receiver](../reverse/attempt_support/consolidation-weaponbonus-view-prerequisite-20261026-codex.md)
  makes the constructor compose with the pool-key donor: ordinary dry-run now
  accepts both direct donors / three existing rows, versus only the pool key.
  All three rows and the EH graph are exact; both full non-debug objects,
  COMDAT policies and data/reference facts are unchanged. Two mixed donors
  and existing vtable/data identity debt remain. No merge, debt retirement,
  census gain or later Luna landing is claimed.
- **StatusBitsUpgrade receiver prerequisite (2026-10-26):**
  [The shared partial receiver](../reverse/attempt_support/consolidation-statusbits-receiver-20261026-codex.md)
  makes the pool-key and apply/remove donors compose: four existing rows / 185
  bytes versus only the two pool rows. Both strict current objects and the
  four-definition composition retain code/data identity, COMDAT policies and
  all ten reference facts. Constructor/vtable and mixed-source prerequisites
  remain. No merge, identity retirement, file reduction or census gain claimed.
- **GameMemory guarded-helper prerequisite (2026-10-26):**
  [The shared HeapTable view](../reverse/attempt_support/consolidation-gamememory-guard-prerequisite-20261026-codex.md)
  clears the AddHeap helper's C2011 refusal. Ordinary composition now accepts
  all five direct donors / six existing rows / 279 bytes, versus five rows.
  Both edited objects are unchanged; the six-definition composition preserves
  COMDAT/data identity and verifies the resolver's internal data-pointer binding.
  Mixed/vendored rows, cross-family donor coordination and the active memory
  inventory update remain for a future merge. No merge, debt retirement, file
  reduction or census gain is claimed.
- **BridgeTower interface trial (2026-10-26):**
  [The restored partial-view trial](../reverse/attempt_support/consolidation-bridgetower-interface-prerequisite-20261026-codex.md)
  preserves the 54-byte interface body and removes two unused private helper
  definitions without changing retained sections or bindings. The full ordinary
  dry run finds the seed/interface candidate but refuses its final retry with
  stale cached diagnostics, reproducing the FireSpread/DebugIOCon verifier
  defect. The source is restored and the false reject logged; fix the cache
  separately before retrying. No accepted merge or source repair is claimed.
- **BridgeTower interface retry (2026-10-26):** after the separate verifier
  cache fix, the ordinary dry run accepts seed plus interface donor (6 rows,
  266 bytes). Both providers pass strict preparation and 6/6 byte checks;
  composition preserves 69 code/558 data definitions, COMDATs, aliases and
  external bindings. This clears the interface private-helper/layout prerequisite
  only; pool, Xfer, damage/healing and mixed-source blockers remain. The donor
  stays separate for Luna; no measured linking gain or debt retirement is claimed.
  See `reverse/attempt_support/consolidation-bridgetower-interface-prerequisite-20261026-codex.md`.
- **Consolidation diagnostic-cache prerequisite (2026-10-26):**
  [The separate verifier repair](../reverse/attempt_support/consolidation-verifier-cache-prerequisite-20261026-codex.md)
  restores each cached compile's own diagnostics and clears stale errors after
  success. Three new tests fail before the fix and pass afterward; the existing
  merge and closed exploit checks still pass. This addresses the shared
  BridgeTower/FireSpread/DebugIOCon retry defect without changing byte acceptance.
  Their source trials still require ordinary verification and binding checks;
  no downstream landing, linked-byte gain or debt retirement is claimed here.
- **TunnelTracker contain-list prerequisite (2026-10-26):**
  [The shared receiver/environment repair](../reverse/attempt_support/consolidation-tunneltracker-contain-prerequisite-20261026-codex.md)
  clears the contain-list refusal: ordinary composition now accepts seed plus
  donor, nine existing rows / 611 bytes, versus no accepted group. Both current
  objects and all thirteen composed code definitions retain bytes, COMDAT
  choices and data/reference facts. Other receiver/list/save-load prerequisites
  and Xfer identity debt remain; no merge or later Luna landing is claimed.
  The full header hook passes 36/36 rows. Its shadow getBodyModule divergence
  is the existing cross-owner +0x254 versus +0x194 receiver discrepancy:
  preserved/current contain objects both emit the same seven-byte +0x254
  provider. No new provider, changed binding or identity retirement is claimed;
  the scoped receipt and earlier TunnelContain owner handoff record the boundary.
  The preceding six-commit batch landed at 0b692726c4 with 40/40 push-hook rows
  exact. Its link audit remains inconclusive: index 763dc8759f predates outgoing
  base dd4a917878 and Eva.cpp lacks a current audit receipt. Carry the batch
  into the next normal census; no link or ownership gain is claimed.
  The recovered five-commit batch through 66ad9c43ca also landed with 40/40
  push-hook rows exact and five EXACT EH graphs. Its audit remains inconclusive:
  index 763dc8759f predates outgoing base 462ffdd1f8 and Eva.cpp lacks a current
  audit receipt. This is a receipt/freshness limitation, not a verified link
  gain or proof of a newly lost byte; carry it into the next normal census.
- **FireSpreadUpdate declaration trial (2026-10-26):**
  [The blocked prerequisite handoff](../reverse/attempt_support/consolidation-firespread-prerequisite-20261026-codex.md)
  preserves 11/11 baseline rows. A minimal declaration trial kept every object
  and binding fact but exposed stale diagnostics on cached compiler failures
  in tu_skeleton's final recheck. The broader include variant accepted six rows
  but changed a static guard name outside the data baseline. Both experiments
  were restored, the false reject was logged and source claims released. No
  source repair, merge unblock, debt retirement or census gain is claimed.
- **FireWeaponWhenDamaged ctor/dtor prerequisite (2026-10-26):** a scoped
  measured declaration view makes the ordinary dry run accept four rows / 838
  bytes versus none. Both standalone objects and all 34 binding facts are
  unchanged; scratch composition preserves six code/six data definitions and
  every COMDAT/vtable binding. See consolidation-fireweapondamaged-prerequisite-
  20261026-codex.md. Pool/update/xfer methods, mixed donors and the Libraries
  allocator-specialization provider remain prerequisites. No merge, debt
  retirement or measured linking gain is claimed.
- **UpdateModule current-verifier follow-up (2026-10-26):** ordinary dry run now
  accepts seed/xfer (two rows / 116 bytes); scoped build, strict receipts and COFF
  composition checks preserve three external definitions and all bindings/data.
  No source edit or merge is needed; mixed wake-frame split hatch growth remains.
  See consolidation-updatemodule-prerequisite-20261026-codex.md. HealContain's
  pool/xfer still need explicit-vptr versus virtual-receiver reconciliation;
  see consolidation-healcontain-prerequisite-20261026-codex.md. No measured gain.
- **FireSpreadUpdate minimal retry (2026-10-26):** the separate cache fix permits
  the ordinary seed/pool dry run to accept six rows / 286 bytes after a
  TU-scoped declaration view adds the existing pool member. All five standalone
  objects and 31 binding facts are unchanged; 11/11 rows and three EH graphs
  pass. Composition preserves 56 code/547 external data definitions and all
  external bindings, but renumbers two local static guards. Their independent
  storage/parent/retail addresses are verified; existing data debt is preserved.
  Guard identity/transfer remains an actual-merge prerequisite alongside the
  other receiver/Coord3D/PartitionManager/mixed-source blockers. See the same
  handoff for exact checks. No merge, debt retirement or measured gain claimed.

- **HeaderTemplate provider inspection (2026-10-26):**
  [The scoped inspection](../reverse/attempt_support/consolidation-headertemplate-pushfront-prerequisite-20261026-codex.md)
  confirms 3/3 exact creation rows but an incorrect typed node-provider chain:
  26-byte SGI node allocation versus retail's 29-byte BFME allocator path.
  Retirement additionally needs 93 missing ledger objects and resolution of a
  renumbered cleanup label in the identity checker. Source and debt are intact;
  the blocked source claim was released. No composition trial was repeated.
- **Science purchase-cost header prerequisite (2026-10-26):**
  [canonical GameLogic adoption](../reverse/attempt_support/consolidation-science-cost-prerequisite-20261026-codex.md)
  preserves the 86-byte cost donor and retires one header-queue row through
  acceptance. Complete before/after object and reference facts are identical.
  Current full composition refuses the final set with allocator/vector
  redefinitions, superseding the historical 13-row acceptance. Cost fields,
  STL/flag reconciliation and mixed donors remain; no full merge unblock,
  identity debt retirement or census gain is claimed.
- **Keyboard declaration prerequisites (2026-10-26):**
  [the shared receiver repair](../reverse/attempt_support/consolidation-keyboard-resync-prerequisite-20261026-codex.md)
  first made the seed and 166-byte resync donor compose (13 existing rows).
  [The key definitions/repeat follow-up](../reverse/attempt_support/consolidation-keyboard-keydefs-prerequisite-20261026-codex.md)
  additionally accepts the 8,023-byte initializer and 111-byte repeat checker:
  four sources, 15 existing rows. Strict current objects preserve executable/data
  sections, COMDAT policies, batch aliases and code/data reference facts.
  Init/update virtual declarations, vector/allocator conflicts and two mixed
  donors remain. No merge, identity debt retirement, linked-byte gain or later
  Luna landing is claimed.
- **RepairDock transfer prerequisite (2026-10-26):**
  [the scoped receiver repair](../reverse/attempt_support/consolidation-repairdock-xfer-prerequisite-20261026-codex.md)
  shares the pool-key and transfer receiver. Normal composition now accepts
  four donors, five rows / 203 bytes instead of three donors / 137 bytes.
  Strict-current edited objects preserve all non-debug sections and code/data
  reference facts; provider candidates and bindings are unchanged. Constructor
  C2511, action C2039 and both mixed donors remain. No merge, debt retirement,
  linked-byte gain or census confirmation is claimed.
- **SpecialPowerCreate declaration prerequisite (2026-10-26):**
  [the bounded pool/callback repair](../reverse/attempt_support/consolidation-specialpowercreate-view-20261026-codex.md)
  shares the existing measured callback receiver with the pool-key consumer.
  Both strict-current objects retain every non-debug section, definition and
  code/data reference fact. Normal composition now accepts both donors, three
  rows / 136 bytes instead of only the pool's two rows / 79 bytes. This is a
  demonstrated prerequisite unblock; no merge or later Luna landing is claimed.
  The constructor still fails C2511, both mixed donors stay behind, and the
  pool's data register entries remain. No census or linked-byte gain is claimed.
- **Sway declaration prerequisite (2026-10-26):**
  [the scoped receiver and identity evidence](../reverse/attempt_support/consolidation-sway-receiver-20261026-codex.md)
  reconciles the seed, pool-key and transfer receivers. Ordinary composition now
  accepts all three sources (6 rows / 1,218 bytes), while the constructor still
  lacks a compatible declaration and the mixed getter stays behind. This is a
  demonstrated prerequisite unblock; no merge or later Luna landing is claimed.
  The separate visibility cleanup removes Sway's divergent seven-byte
  `Drawable::isVisible` COMDAT and preserves every retained section and code/data
  reference fact. The selected GameLogicInit copy remains the same. Identity
  register retirement is zero; scoped current-provider verification and its
  limits are recorded in the handoff. No census or linked-byte gain is claimed.
- **Evidence / scope:** recurring historical names include `AudioEventRTS`
  destruction, assignment and `setObjectID`; `UpdateModule::crc`;
  `DamageInfo` / `DamageInfoInput` / `DamageInfoOutput` transfer methods;
  `INI::scanIndexList`; `ParticleSystemManager::createParticleSystem`;
  `Object::setProducer` / `setStatus`; and `DISABLEDMASK_NONE`.
- **Completed:** the initial `link_rank.py --owner-gaps --top 12 --near 3`
  inspection found 23 unresolved names with matched-address candidates. This
  is an ownership lead, not a repair or identity proof.
- **Verified special-power subset (2026-10-25, inspected `777d0ff0aa`):**
  [current verification](../reverse/attempt_support/specialpower-dtor-verification-20261025/readme.md)
  confirms upstream `bcac7d81eb` removed the protected/public destructor
  mismatch for CashHack and Defector. Normal gates pass 14/14 rows across the
  two callers and two provider units, with 2/2 EH graphs EXACT; all four units
  have strict current receipts. Against index `51fde01dff` (13:53 UTC), with
  all four requested objects current, both callers preview cleanly for their
  already-counted 422 bytes. This binding/ordinary-preview subset is cleared;
  no new headline gain or census confirmation is claimed.
- **Historical special-power prerequisite:** the actual destructor's unit
  `SpecialPowerModuleDtor_Unresolved.cpp` still conflicts on the two
  BehaviorModule vtables and the SpecialPowerModule vtable (three first-copy
  COMDAT findings). Reconcile those native class/table definitions before
  claiming the family's closed-strict or executable closure; the scoped
  evidence above records the exact names. The broader entry remains open.
- **Follow-up verification (2026-10-25, after `aa31e9bac4`):** the dtor and its
  14 public-spelling consumers now preview cleanly (1,434 B). The constructor
  and WeaponMode consumer also need their local `BehaviorModule` destructor
  declared protected to bind the existing providers. Both corrected views
  byte-verify with exact EH; the constructor previews 340 B and WeaponMode
  retains its previously linked 112 B. See the LINK-014 follow-up below.
- **Native-interface/debt follow-up (2026-10-25, after `17d211067f`):**
  [the bounded zero-slot repair and ABI handoff](../reverse/attempt_support/behavior-zero-slot-hatch-20261025/readme.md)
  replaces one linker alias with a real, whole-body-verified C++ zero-result
  slot and consistent declarations in the constructor/companion units.
  All 9 rows, 3 EH graphs and 3 strict receipts pass; the enforced hatch
  register retires one alias. The 624 already-linked cohort bytes are kept,
  with the same three remaining provider-table conflicts. No new headline
  gain or family clearance is claimed. Native table inspection also shows
  that the indexed ZH-shaped 14/34-slot bases are not the retail contract:
  the primary native base has 12 slots, and the secondary run/signatures
  require reconciliation, including the class-contract queue's final slot.
  Use the handoff's exact table anchors before adopting shared declarations.
- **`AudioEventRTS` destruction/assignment subset (2026-10-25, inspected
  `b620cdb046`):**
  - The shared names are two pins:
    `??1AudioEventRTS@@UAE@XZ` -> `0x004EC395` (the folded STLport
    `_List_base` destructor) and `??4AudioEventRTS@@QAEAAV0@ABV0@@Z` ->
    `0x000366F0` (`StringBase<char>::set`).
  - `tools/name_dependents.py` finds 17 units, compiled against Zero Hour
    headers, whose objects reference them. Trial: drop both pins and build
    all 17. 15 units stay exact; exactly 2 rows fail:
    - `??4DynamicAudioEventRTS@@QAEAAV0@ABV0@@Z` (`0x00200BC0`, 25 B,
      `ThingFactory.cpp`). Retail copies only a `StringBase<char>` at +4 via
      `StringBase::set`, so this body is not an `AudioEventRTS` assignment.
      The masked-search placement is no identity proof.
    - `??1?$pair@VAsciiString@@VAudioEventRTS@@@_STL@@QAE@XZ` (`0x002A12E1`,
      `ThingTemplate.cpp`). Retail destroys `second` at +4 through the folded
      list destructor `0x004EC395`, then `first` through
      `StringBase<char>::~StringBase` (`0x00036410`), so the BFME 2 map value
      is not a 0x88 event.
  - These two pins block naming the canonical 0x88 class
    (`BfmeAudioEventPrefix136`, `Code/GameEngine/Include/Common/BfmeAudioEventPrefix136.h`)
    `AudioEventRTS`. The retail `AudioEventRTS.cpp` `__FILE__` string is
    referenced at `0x002D9ADC`, inside that class's translation unit
    (`0x002D94CE..0x002DAB18`). With the rename, its virtual destructor
    (`0x002D9A43`) would share a mangled name with the pin at `0x004EC395`.
    `pin_consistency` refuses that, and the link would select one body for
    both.
  - **Next check:** re-identify the two rows' real BFME 2 types (a
    {+0, `StringBase<char>` +4} class with assignment; a map value whose
    destructor folds with the list base). Retype them so they call those
    callees by their own names, then drop both pins. Re-run the 17-unit
    trial before the canonical rename.
- **GameWindow table prerequisite (2026-10-25, inspected `a0af8f5cb1`):**
  retail's table at RVA `0x0080BBCC` has 11 slots and ends at `0x0080BBF8`,
  the separately identified `Rva0031455E` table. `GameWindow.cpp` declares
  12 virtuals, including `winSetFont`; `GameWindowDtor.cpp` declares two,
  including a virtual `winDrawBorder` whose existing row is nonvirtual.
  The historical 249-byte dtor preview remains blocked. The next repair
  should reconcile both views with the native 11-slot table and its callees,
  then verify the table owner, parent bodies and consumers together.
  [Native slot evidence](../reverse/attempt_support/link-regression-clusters-20261025.md#gamewindow-native-table-prerequisite).
  No GameWindow source trial was applied during this follow-up.
- **INI bucket initializer repaired (2026-10-25, control `349db6dc10`):**
  [the scoped provider repair](../reverse/attempt_support/ini-bucket-provider-link-20261025/readme.md)
  makes INI emit the retail 59-byte initializer at `0x00148DDF` and applies its
  prime-search configuration before the relevant include. INI's wrong-binding
  count falls from one to zero. All 203 cohort rows and 13 EH graphs pass;
  the bounded ownership diagnostic clears INI's 2,989 authored bytes. Existing
  provider debt is recorded in the handoff. This subset is cleared in the
  scoped diagnostic; global closure and census confirmation remain pending.
- **INI repair's AI consumer checked (2026-10-26, `d7fa8a31bf`):**
  [the current-provider check](../reverse/attempt_support/ai-constructor-current-provider-20261026.md)
  verifies Rva00598E85Ctor.cpp's four rows and its INI/lower-bound providers
  (46 rows, six EXACT EH graphs). Index `f995f30157` still selects INI's old
  prime-search copy; including current INI makes the unchanged AI unit preview
  LINKS for 177 authored bytes. This confirms existing repair `0c7ebc35a7`,
  with no new source edit or census gain. INI's own ownership-overlay blockers
  remain outside this AI-only clearance; await the next census for confirmation.
- **GameLogic lookup header subset (2026-10-26, `8da4ac24ce`):**
  [the AITarget, indexed getter and audio owner adoptions](../reverse/attempt_support/gamelogic-lookup-header-adoption-20261026.md)
  replace private GameLogic/ObjectID declarations with the registered header.
  All eleven function rows and the data row remain exact, with one EXACT EH graph
  and unchanged 762-byte combined ordinary link-preview scope. The owning
  acceptance tool retires three header-queue rows; the shared header is unchanged.
  These already-linked consumers gain no census bytes. Other consumers and
  full class-layout reconciliation remain open.
- **AI Xfer header subset (2026-10-26, `a1ee5c1f39`):**
  [the flank-route, AIUpgrade and harvest-state adoptions](../reverse/attempt_support/ai-xfer-header-adoption-20261026.md)
  replace private Xfer declarations with the registered header. Seven function
  rows (772 bytes), the 68-byte state table and one EH graph remain exact.
  The route and harvest-state ordinary preview stays 518 -> 518 bytes against
  index `f995f30157`. A local operand-declaration include also preserves the
  supported 10-row flank TU merge dry-run, with no rejected donors; no merge
  was applied.
  AIUpgrade's two rows (254 bytes) and one EH graph also stay exact, but that
  source is absent from the index and has no ordinary-preview verdict. The
  owning acceptance tool retires three header-queue rows. Other Xfer consumers and
  class-wide closure remain open; no new census or matched-byte gain is claimed.
- **Vector Xfer header subset (2026-10-26, `6a57c22ccc`):**
  [the vector-transfer adoption](../reverse/attempt_support/vector-xfer-header-adoption-20261026.md)
  replaces the private classes in Rva003F2394Xfer.cpp, Rva0040E19DXfer.cpp and
  Rva004FACD0Xfer.cpp with the canonical Xfer header. All three complete
  204-byte bodies stay exact; the combined ordinary preview remains 612 -> 612.
  The owning tool retires three queue rows. A local operand include preserves
  declaration order and the temporary string-pointer lifetime needed for retail
  stack reuse. Shared headers and existing vector/exception identities are unchanged.
  Other Xfer consumers and class-wide closure remain open.
- **Update-module Xfer header subset (2026-10-26, `9e1ca7f93f`):**
  [the StealthUpdate, DeletionUpdate and crushing-notification adoptions](../reverse/attempt_support/update-xfer-header-adoption-20261026.md)
  replace private Xfer declarations with the canonical header and a local
  operand-declaration include. Four rows (524 bytes) and the StealthUpdate EH
  graph remain exact; the combined ordinary preview retains 521 authored bytes against
  `f995f30157`. The owning acceptance tool retires three queue rows. The Version storage,
  transfer order, native callees and existing alias remain unchanged.
  Other consumers and class-wide closure remain open; no new census gain is claimed.
- **Skirmish pointer owner repaired (2026-10-26, base `c63ad61ed9`):**
  [The verified four-byte owner](../reverse/attempt_support/skirmish-game-info-data-owner-20261026.md)
  reconciles 24 declarations in 23 consumers with the existing menu definition.
  The cohort passes 729 functions, 13 data rows and 100 EXACT EH graphs; one
  unused declaration's removal preserves another 39 rows and four EH graphs.
  Full non-debug COFF comparison proves no code/exception change beyond the
  intended data-symbol binding. The 24-unit ordinary preview improves from
  0/24 to 22/24, restoring 64,163 already-censused authored bytes against
  `763dc8759f`. Recorder's consolidation diagnostics and the menu owner's
  other dependencies remain. Existing shadow data/identity findings are
  retained and qualified in the handoff. No new census or full-image claim.
- **Remaining / next check:** resolve the real existing owner, parameter types,
  ABI and data ownership from native references; reconcile canonical headers
  with implementations and consumers as a batch. Verify all affected rows and
  selected definitions. Do not add a duplicate identity, stub or escape hatch
  to satisfy an old spelling. Clearance and census confirmation remain pending.

### LINK-005: units blocked by several incompatible dependencies

**Status: Open. Updated: 2026-10-25.**

- **Evidence / scope:** the historical blocker lists contain ConnectionManager
  (51 names), particle-module copy constructors (28), MapUtil (26), `texture.cpp`
  (21) and `ww3d.cpp` (20). These counts overlap the causes above and are not
  counts of independent missing implementations.
- **Completed:** the initial investigation grouped these as coordinated repair
  families; it made no source repairs or current-object measurements.
- **Remaining / next check:** refresh each unit's actual blockers, then reconcile
  shared string/map/vector views, destructors/vtables, signatures and graphics
  interfaces. Track resolved subsets and remaining names here or in a linked
  family handoff. A repaired dependency is partial progress until all blockers
  in the stated unit scope are checked. Clearance and census confirmation
  remain pending.

### LINK-006: compiler emission and the selected copy still disagree with retail

**Status: Open. Updated: 2026-10-25.**

- **Polygon renderer consolidation subset (2026-10-26, inspected cdf6e90a59):**
  [the scoped provider prerequisite](../reverse/attempt_support/sol-b5-polygon-provider-20261026.md)
  found a 9/9-byte-exact merge changing the earliest scoped vector-constructor
  helper from 34 to 50 bytes. Keeping the existing optimization anchor in the
  TU's first include preserves the original 34-byte helper during composition.
  All nine rows, 12 selected scoped definitions/COMDAT flags, 18 references and
  five data bindings verify. The prerequisite is verified; the two-donor merge
  is left to Luna. Global selection and census confirmation are unclaimed.

- **Evidence / scope:** string erase/replace helpers and Render2D container
  destruction can resolve a symbol while retaining an incorrect selected body.
  Read the [prior linking handoff](../reverse/attempt_support/link-seat-20261025-final.md)
  and its referenced string/compiler banks before trying another emission shape.
  The vector parent/helper contract in LINK-002 is another concrete example.
- **Completed:** selective emission has repaired some other families, recorded
  under LINK-001; it does not establish a fix for these remaining cases.
- **FX-list constructor subset cleared in ordinary preview (2026-10-25,
  after `feb95824fa`):**
  [the full dependency proof](../reverse/attempt_support/fxlist-constructor-link-20261025/readme.md)
  restores allocator/forwarder visibility and replaces the sibling's wrong
  bucket-count emission with the retail copy. Normal gates prove the complete
  48/59/64-byte helpers, 19/19 cohort rows, four exact EH graphs and four strict
  current receipts. All four current units preview cleanly against index
  `51fde01dff`; the store constructor's 109 authored bytes are now included in
  that bounded clean scope. The paired evidence distinguishes actual source
  repair from alias-driven uncertainty in the old control. The broader
  value-layout and string/container entries remain open; census and executable
  closure are unclaimed.
- **Final FX-list provider scope:** the same proof also removes the constructor
  unit's wrong clear copy in favor of the existing 73-byte owner at 0060CFB6.
  Expanded verification passes 26 rows across five sources, four exact EH
  graphs, five strict receipts and zero new identity findings. FXList.cpp's
  clear operation is verified, while its whole 620-byte unit still has separate
  particle/terrain/drawable bindings, two nugget tables and list-lifetime
  blockers, detailed in the proof. Only the original four-unit ordinary-preview
  scope is cleared; the broader entry remains open.
- **Remaining / next check:** prove the native provider and inspect all emitted
  symbols, relocations, parent extents and EH graphs with current inputs. Merely
  suppressing a helper or changing an exception declaration can break a matched
  parent. Clearance and census confirmation remain pending for this scope.

- **FX-list obsolete-emission subset (2026-10-25, inspected `9edfc2834c`):**
  [the bounded cleanup and identity handoff](../reverse/attempt_support/fxlist-obsolete-emissions-20261025/readme.md)
  removes unused Zero Hour callbacks and retains the bone-position method out
  of line. All seven existing bodies and all their relocations are unchanged;
  normal byte/data gates and a strict current receipt pass. Against the fixed
  `ef9c691284` index, the obsolete drawable call and bone-position table conflict
  disappear. The 620-byte unit still does not link; no census gain is claimed.
  The two remaining list pins target StringBase operations (000365F0 and
  00036E70), and the 0052BD3A copy installs the existing one-string C61A20 table.
  Declaration-only suppression introduces unresolved references, so the next
  step is a coherent ownership/provider/consumer correction, preserving coverage.
  The separate particle table and legacy particle/terrain calls remain open.
  A supported identity-retirement attempt refused missing/stale provider evidence;
  no baseline was changed.

- **Map-metadata selected-copy subset (2026-10-25, inspected `d4cd9b535c`):**
  [the read-only cache-reference repair](../reverse/attempt_support/map-metadata-borrow-link-20261025/readme.md)
  stops SkirmishGameOptionsMenu.cpp from instantiating its shorter Zero Hour
  metadata copy and related tree-copy operations. Native positioning helpers
  independently show that the borrowed metadata and coordinates are read-only.
  Normal gates pass 56 rows across six current sources, 13 exact EH graphs and
  six strict receipts with independently checked object hashes. A fixed-facts
  paired ordinary preview clears four caller units (2,295 authored nonpadding
  bytes). This bounded subset awaits census confirmation; the legacy menu's
  other dependencies and MapMetaDataCopyDeferred's waypoint-tree identity/provider
  conflicts remain open. No whole-family or executable closure is claimed.

- **Decal unmatched-emission subset (2026-10-25):**
  The native check of `decalmsh.cpp` retains all six existing exact rows
  (326 bytes) while removing 18 explicitly unmatched Zero Hour function
  definitions. Five Texture-pointer vector members are emitted explicitly;
  the existing count getter keeps its directly proven receiver-field load,
  with no new vtable definition. The six unresolved legacy renderer calls
  disappear. Normal byte verification passes 6/6 before and after.
  Against the fixed `f995f30157` index (2026-10-25 21:36), the bounded ordinary
  preview changes this unit from blocked to clean (0 -> 326 authored bytes).
  No new C++ exact bytes, census headline or closed-strict result is claimed.
  Verification is the isolated native fork workflow; canonical class
  registration, data ownership, source claims and the actual file lease are
  checked before editing. The broader compiler/provider entry remains open.

  Removed hatch occurrences: 22; registered debt retired: 0. Unrelated register keys are preserved.

  Source blobs: original `11adf762e6f6e2a8296465286d1bb96364c58a02`, repaired `23f5050ee6df39dd0d5846c45f16427e153cc6a7`.
  Existing rows retained without ledger edits:

  | RVA | Bytes | Symbol |
  | --- | ---: | --- |
  | `0x00143E90` | 129 | `?Resize@?$SimpleVecClass@PAVTextureClass@@@@UAE_NH@Z` |
  | `0x00143F20` | 55 | `?Uninitialised_Grow@?$SimpleVecClass@PAVTextureClass@@@@UAE_NH@Z` |
  | `0x005508E9` | 7 | `?Decal_Count@RigidDecalMeshClass@@UAEHXZ` |
  | `0x00144910` | 40 | `?Resize@?$SimpleDynVecClass@PAVTextureClass@@@@UAE_NH@Z` |
  | `0x00144020` | 39 | `??0?$SimpleVecClass@PAVTextureClass@@@@QAE@H@Z` |
  | `0x001448D0` | 56 | `??0?$SimpleDynVecClass@PAVTextureClass@@@@QAE@H@Z` |

  Provider audit retains every mapped symbol through an equivalent or retail-correct provider; no linker alias is removed.
  Native receipt: https://github.com/McMickey93/Open-BFME-2/actions/runs/40240437884.

### LINK-007: incomplete data ownership beyond clean symbol resolution

**Status: Open; scoped storage repairs verified. Updated: 2026-10-26.**

- **Texture-statistics scalar subset (2026-10-26, control `d831bc24031`):**
  [The scoped ownership repair](../reverse/attempt_support/texture-statistics-data-20261026-bce2/readme.md)
  binds recording mode and seven reporting counters to their existing
  `statistics.cpp` owners, retiring sixteen data-register keys through the
  owning tool. All 51 cohort rows, four EH graphs and three strict preparation
  receipts pass; all 79 emitted code definitions retain their bytes and code
  references. Both consumers keep their 1,780 ordinary-preview bytes against
  index `47e030bafc`; the provider's existing findings are unchanged. The
  reporting-mode extern trial changed scheduling and was restored. Current-frame
  counters need the claimed reset provider; vector/handle/string storage needs
  full extent and initializer/teardown reconciliation. No family closure,
  census gain or image-ownership receipt is claimed; LINK-017 still applies.
  Its normal push gate also passes the automatically included Eva dependent
  (45/45 rows, seven EXACT EH graphs). The batch audit is inconclusive on the
  older index and Eva's missing strict receipt; bounded preparation refuses
  Eva's macro/parent-traversing include inventory, the LINK-008 prerequisite.
  No verifier or include-path change is made in this scalar repair.

- **Evidence / scope:** the [linking handoff](../reverse/attempt_support/link-seat-20261025-final.md)
  identifies missing shader/filter root objects and the unowned 52-byte
  ScreenBWFilter group at `0x009B5B54`. Complete native objects and vtables are
  prerequisites; a symbol alone does not prove their storage or relocations.
- **Completed:** the [VP6 storage repair](../reverse/attempt_support/vp6-idct-storage-link-20261025/readme.md)
  proves the table's 548-byte allocation and records a fixed-comparison
  **17,413-byte placed closed-strict gain**. Those units already counted as
  linked in the headline. This is scoped closure evidence, not a new headline
  measurement of master; follow that lane's clean-room rules.
- **Filter adjacency repaired (2026-10-25):** the
  [modifier/pointer ownership proof](../reverse/attempt_support/vp6-filter-adjacency-link-20261025/readme.md)
  preserves native `g_bfmeDeringModifiers+0x100 == g_bfmeFilterLimit` in one
  verified 260-byte owner. The six-unit control passes 13/13 bodies (5,862
  bytes); all 13 affected data relocations keep their native targets. The
  authoritative fixed comparison `026edbcbcc` to `a7637e3b22` changes exactly
  four of 23,460 canonical objects and gains **2,369 placed closed-strict
  bytes** in seven rows, with no losses. All seven former unit failures are
  self-strict; six are also closed-strict, together with the FilterBlock2d
  caller. The independent closure report reproduces all 98,202 status rows.
  This is scoped closure evidence, not a new census headline.
- **Scaler coefficients repaired (2026-10-25, inspected `d0c913e6dde`):**
  [the six-scaler ownership repair](../reverse/attempt_support/vp6-scale-tables-link-20261025/readme.md)
  gives the five shared native coefficient addresses one owner each instead of
  22 private copies. Normal controls pass 6/6 bodies (1,739 bytes), all five
  eight-byte data owners and all 64 native DIR32 targets. The authoritative
  fixed comparison `a7637e3b22` to `7124e772c5` gains **1,739 placed
  closed-strict bytes** in the six scalers, with zero losses. All five datum
  nodes pass; exactly five of 23,460 canonical objects change. Independent
  reconstruction reproduces all 98,202 status rows and the 1,700,931-byte
  credit. This scoped
  scaler repair is **cleared in the fixed comparison**; no current census
  headline change is claimed. Native alignment padding remains unowned.
- **Generic filter scratch cleared in the fixed comparison (2026-10-26,
  source base `684d224e847`):**
  [the scratch ownership proof](../reverse/attempt_support/vp6-filter-scratch-link-20261025/readme.md)
  replaces two four-byte scalar claims with the independently bounded
  352-byte buffer at DFDA58; its second-pass row is buffer+32, not a second
  datum. All 5 control bodies (821 bytes), the complete data owner and all
  6 native DIR32 targets pass. A plain zero-based eight-column loop preserves
  native pointer induction after the correct array declaration. The authoritative
  comparison `7124e772c5` to `f012cbcc5e` gains **2,747 placed closed-strict
  bytes** in five rows, with zero losses. It clears both bilinear bodies, their
  two filter callers and the unchanged debug row's scratch/counter forward-map
  conflict. Exactly two of 23,460 canonical objects change. Independent closure
  reconstruction reproduces all 98,202 rows and the 1,703,678-byte credit.
  The interrupted first run was preserved; the resumed process exits zero after
  2,992 seconds with no final drift or new unresolved references. Publication
  controls also pass against the rebased reference inputs. This is scoped closure
  evidence, not a new current-master census headline.
- **Remaining / next check:** shader/filter root-object ownership remains
  open. The [current witnesses](../reverse/attempt_support/vp6-filter-scratch-link-20261025/remaining-witnesses.json)
  show InitPostProcessing, PostProcMachineSpecificConfig and
  UtilMachineSpecificConfig still closure-blocked through GetProcessorFlags and
  CpuProbe_VendorSse2: the selected `__except_handler3` import twin lacks a
  confirmed map/object definition. UtilMachineSpecificConfig's previous scratch
  witness is cleared. Prove the selected import provider and remaining native
  storage relationships; do not retry the cleared
  coefficient or filter-pointer splits. Verify storage
  extents, initial bytes, relocations and dependent closure through the existing
  gates. Family clearance and later census confirmation remain pending.
  Preserve the no-stubs/no-`/FORCE` runtime exit requirements.

### LINK-008: include inventories prevent strict reusable graphics receipts

**Status: Blocked on complete include inventories. Updated: 2026-10-26.**

- **Evidence / scope:** [graphics verification at `91fe970939`](../reverse/attempt_support/weightinfo-verification-20261025/readme.md)
  ran the normal gates successfully for 34 units, but its initial 17-unit
  `--prepare-current` run refused strict reuse. W3DShadowTextureCtor,
  W3DDebrisDraw, W3DDebrisDrawLegacy and W3DVolumetricShadow reported macro or
  parent-traversing include roots, or headers outside inventoried search roots.
- **Completed:** all 34 ordinary byte/receipt checks pass; 13 objects also have
  strict reusable receipts. The other 17 units were checked through the ordinary
  path; no claim is made that all of them are uncacheable. The refusal is retained
  in the evidence, and no gate was relaxed. LINK-001's destructor preview result
  does not establish strict closure.
- **Non-graphics publication control (2026-10-26, source `cc68e92bcd`,
  evidence `b3bd2d6351`):** the
  [VP6 scratch publication audit](../reverse/attempt_support/vp6-filter-scratch-link-20261025/publication-audit.json)
  passes all 32 ordinary rows across the two repaired units and the conservatively
  included `Eva.cpp` control, one complete data owner, four exact EH graphs and
  converged-data enforcement. The mandatory batch audit is nevertheless
  inconclusive: index `47e030bafc` predates outgoing base `6e852991684`, and
  `Eva.cpp` lacks a current strict reusable receipt. No selected-provider or
  lost-byte verdict against current master follows from that audit. The separate
  immutable fixed comparison proves the scoped 2,747-byte gain with zero losses;
  it does not supply a current-master census. Carry this cohort to the next
  normal census and inventory Eva's include graph before strict reuse.
- **Remaining / next check:** prove and make the actual include graph
  inventoryable under the existing gates, then repeat bounded strict preparation
  for all affected providers/consumers. A needed verifier repair follows the
  separate false-reject workflow. Do not substitute ordinary receipts for strict
  witnesses. Clearance and closed-strict confirmation remain pending; no census
  change is claimed for this inventory work.

- **Full publication (`98500fc347`, 2026-10-26):** the next normal push passes
  all 98,252 function rows, 2,218 data rows, reference checks and the no-op
  image. Its final EH audit retains 24 registered exceptions beside 11,876
  EXACT graphs. Converged-data enforcement passes for 22,962 sources with no
  second names or unjudged rows. The shadow link audit does not finish within
  the hook's limit and still compares against an older census index; it gives
  no new provider-change/lost-byte verdict. Prior strict-input prerequisites
  remain unclosed. [Receipt and follow-up](../reverse/attempt_support/skirmish-game-info-data-owner-20261026.md#publication-and-following-file-cleanup).

### LINK-009: split-identity destructors; the alias route needs an admission path

**Status: Blocked on an identity merge or a maintainer admission decision.
Updated: 2026-10-25; inspected revision: `4e835ab16a6`.**

- **Evidence / scope:** constructors matched under one class name whose retail
  destructor is matched under a second, address-derived name, so the unit's
  `??1X` stays unresolved. Six units are affected, 661 authored bytes:
  GameSpyInfoCtor.cpp 280 B (`??1GameSpyInfo`), ExperienceTrackerAutoResolve.cpp
  113 B, Rva0022BD9ASubsystem.cpp 67 B, Rva0022C0CDSubsystemCtor.cpp 81 B,
  Rva0022BE0FSubsystemCtor.cpp 65 B and Rva0022BD25SubsystemCtor.cpp 55 B.
  Retail proves each pair: the unit's constructor installs a vtable whose slot 0
  deleting destructor calls the matched body, and two pairs are additionally
  anchored by address adjacency (`0x0041EFFF` + 67 = `0x0041F042`;
  `0x0041F913` + 55 = `0x0041F94A`). Banked detail and the per-class table:
  [split-identity handoff](../reverse/attempt_support/split-identity-dtors-20261024/readme.md).
- **Completed:** a full-form `/alternatename` trial on all six units re-verified
  28/28 rows and linked `LINKED 0 -> 661` bytes at census index 2026-10-24 10:28
  (`2fbdec0868`). It was reverted: the current rules forbid adding
  `/alternatename` by hand, hatch counts may rise only through an admitted tool,
  and the counter's own `--allow`/`--admit` is hand-adding. No admission tool
  covers this hatch, so the evidence is preserved as an attempt, not a repair.
- **Remaining / next check:** choose an admissible route. Preferred is an
  identity merge of the placeholder destructor class into the class the
  constructor/vtable prove, sharing one class view among every unit that emits
  the vtable; that is still blocked on `rename.py` support for a
  placeholder-to-real merge and on the class-view/COMDAT cases recorded in the
  handoff (GameLogic/SubsystemInterface slots, the ExperienceTrackerXfer vtable
  COMDAT, BaseHeightMapRenderObjClass and GlobalWeatherSystem whose rowed names
  are deleting destructors only). Otherwise a maintainer decision is needed for
  a scoped admission path. Do not repeat the unchanged alias trial.
- **Clearance / census confirmation:** pending; no census change is claimed and
  the alias trial was not published.

### LINK-010: folded STL table bases need the actual native predecessor

**Status: Blocked on supported native data-placement / ownership reconciliation.
Updated: 2026-10-25; inspected revision: `4f111811802`.**

- **Evidence / scope:** [the signed-reference handoff](../reverse/attempt_support/stl-tenscale-predecessor-link-20261025/readme.md)
  proves the full 640-byte tenpow and 160-byte twoexp arrays in
  `stlport_stl_atod.cpp`, all six native DIR32 references, and a normal 5/5
  body control. A read-only replay of `a7637e3b22` re-proves inputs and
  reproduces all 98,202 status rows and the fixed-comparison credit.
- **Completed:** the cause is narrowed beyond symbol visibility. Tenpow's
  folded -4/-8 references precede its own COFF contribution and collide with
  Initialize_get_float's digits literal in the measured image. Retail instead
  reaches the end/padding of the canonical `__hex_char_table_hi` at VA BBC910,
  owned by `stlport_write_integer_backward.cpp`. Twoexp's -2 reference already
  has a valid named predecessor and passes the existing before-symbol rule.
  Game source is unchanged; no new credit is claimed.
- **Remaining / next check:** reconcile real native data placement and the
  existing hex-table owner without duplicating or over-sizing that datum.
  Establish a fresh approved TU/ownership plan before any consolidation; the
  inspected committed map supplies no approved merge for these two units.
  Verify both predecessor and array, other consumers, and one-to-one maps.
  Do not repeat visibility-only or expression changes, add an artificial
  prefix, or weaken the check. Clearance and census confirmation are pending.

### LINK-011: provisional base classes and vtable mismatches in GameEngine subsystems and triggers

**Status: Repair landed / awaiting verification. Updated: 2026-10-25.**

- **Evidence / scope:** several GameEngine units used provisional `Rva...Base` classes
  that declared non-pure virtual functions (`unused()`, `~Class()`) without definitions,
  causing unresolvable vtable and destructor symbol references. In `PolygonTriggerCtor.cpp`,
  a secondary base declared `secondarySlot()` non-pure while `Rva002E3EB8Permuted` declared
  it pure virtual `slot() = 0`. In `Rva003BBAF0Ctor_Rva003FD199.cpp`, `BfmeBaseVNH` vtable
  `??_7BfmeBaseVNH@@6B@` was referenced without being defined. Total scope: 297 authored bytes
  across 4 units.
- **Completed:**
  - `SpecialPowerStore.cpp` (37 B): adopted canonical `SubsystemInterface` directly.
  - `EmotionSystem.cpp` (59 B): adopted canonical `SubsystemInterface` directly.
  - `PolygonTriggerCtor.cpp` (157 B): replaced ad-hoc secondary base with `Rva002E3EB8Base`
    declaring pure virtual `slot() = 0`.
  - `Rva003BBAF0Ctor_Rva003FD199.cpp` (44 B): defined `BfmeBaseVNH` vtable symbol.
  - Verification: `./build.sh` byte-matches all 4 units (5/5 rows); `tools/link_check.py`
    confirms all 4 link cleanly (`LINKED 0 -> 297` bytes).
- **Remaining / next check:** await confirmation in the maintainer's next link census run.
- **Clearance / census confirmation:** cleared in ordinary-preview scope; census confirmation pending.
- **Recorder `Rva0037BBED` (2026-10-26):** `Rva0037BCC4DeferredCtorCRC.cpp` (157 B) lost
  `??_7Rva0037BBED@@6B@` to the 1-slot copies in `OpaqueScalarDeletingDtorsB07.cpp` and
  `Rva0037BBEDDtor.cpp`; all three now declare retail slots 0..1 (dtor, `init` at 0x0037B326).
  Its CRC-queue calls bind to the ledger's ICF owners `FXList::addFXNugget` (0x0037D097) and
  `FXList::rva0037BD64` through casts. `link_check.py`: 3 of 3 link, `LINKED 1,017 -> 1,174`.
  Retail vtable 0x00C18828 has 14 slots, slots 2..13 folded foreign bodies; no copy reproduces
  them yet. Census confirmation pending.

### LINK-012: shattersystem.cpp's Zero Hour WW3D2 views emit divergent shared COMDATs

**Status: Open (partial repair landed). Updated: 2026-10-25; inspected revision: 70d32d864.**

- **Evidence / scope:** `Code/Libraries/Source/WWVegas/WW3D2/shattersystem.cpp` compiles
  against Zero Hour's `WWLib/Vector.H`, `WW3D2/matinfo.h` and the `meshmatdesclayout`
  shim, and emitted a 75-byte `DynamicVectorClass<VertexMaterialClass*>::Add` while
  retail's folded owner (0x001A3A60, 77 B) is what the six BFME 1-header units emit.
  The census (ef9c691284) kept shattersystem's copy, so every user of that `Add` failed
  `wrong_selected`: MeshLoadContextAddLegacyMaterial.cpp (2,714 B),
  MaterialCollectorDestructor.cpp (1,588 B), MaterialCollectorCollectMaterials.cpp
  (1,489 B), MeshModelReadVertexMaterials.cpp (270 B) and meshmdlio.cpp (352 B).
- **Completed:** shattersystem.cpp declares the `Add` specialization decl-only (before
  matinfo.h, whose inline `Add_Vertex_Material` instantiates it), so it emits no copy.
  `./build.sh` 1/1; `tools/link_check.py` with shattersystem.cpp and each consumer:
  all five consumers LINK (0 -> 6,413 B predicted).
- **Remaining / next check:** shattersystem.cpp still emits non-retail
  `MaterialInfoClass::Add_Vertex_Material` (out-of-line `Add` call where retail 0x00189670
  inlines BFME's `Add`) and `MeshMatDescClass::Peek_Single_Material` (material array at
  +0xA8 in the `meshmatdesclayout` view; retail 0x002C8ECF reads +0xA4). Those keep
  dynamesh.cpp (owner of both rows) and shattersystem.cpp itself from linking. The two
  `Add` bodies are textually identical, so the difference is the views' class layouts:
  reconcile shattersystem.cpp onto the BFME 1 WWLib/WW3D2 headers dynamesh.cpp uses,
  checking its 0x00074643 `Matrix3D::Scale` row.
- **Clearance:** preview scope only (current objects for the listed units).
- **Census confirmation:** awaiting the next census.

- **Mesh material I/O follow-up (2026-10-25, inspected `d7fa8a31bf3`):**
  [the bounded cleanup and provider control](../reverse/attempt_support/meshmdlio-hatch-cleanup-20261025-bce2/readme.md)
  confirms meshmdlio's eleven rows remain exact (352 bytes). Against the
  `f995f30157` index, checking the current shattersystem object alongside it
  clears the historical Add blocker before and after the cleanup. This is
  inherited repair, not new linking credit. The file's obsolete construction
  anchor and stale matched-destructor annotation are removed, retiring three
  hatch occurrences through the register tool. The RefCount optimization is
  retained after an independent removal trial changed Add_Ref's emission.
  Shattersystem's seven current unresolved/COMDAT/selected findings are
  unchanged and recorded in the evidence. Only this consumer's ordinary
  preview scope is cleared; family closure and census confirmation remain open.

- **Material collector follow-up (2026-10-26, inspected `a91e877b4d`):**
  [Whole-file cleanup and paired provider checks](../reverse/attempt_support/material-collector-anchor-cleanup-20261026.md)
  preserve all eight rows (1,506 bytes) and one EXACT EH graph. With the
  current shattersystem object, the consumer previews clean for 1,489 authored
  bytes before and after removing its unused construction anchor. Its three
  unreferenced diagnostics and the provider's seven blockers are unchanged.
  The owning hatch tool retires two optimization occurrences. This is new
  hatch retirement plus confirmation of inherited repair, not new linking
  credit or broader closure; census confirmation remains pending.
  A separately verified follow-up replaces its local array-delete declaration
  with the toolchain `<new>` header, using the donor's existing allocation
  guard to avoid duplicate placement bodies. All eight rows, the EH graph
  and the paired preview stay exact/unchanged; the Microsoft-header scan
  reports zero local definitions or declarations.

### LINK-013: INI consolidation made a non-retail `set<AsciiString, BfmeStringNoCaseLess>::insert_unique` the kept copy

**Status: Cleared in the eight-unit ordinary preview; census pending. Updated: 2026-10-25; inspected revision: aa31e9bac4.**

- **Evidence / scope:** the census at f995f30157 lost the six units that call
  `_Rb_tree<AsciiString, …, BfmeStringNoCaseLess>::insert_unique` (row 0x0002C908, 153 B,
  owner `stlport_nocase_asciistring_set_insert.cpp`) to `wrong_selected`. Its index holds
  five copies:
  - non-retail (digest c5d4a74a154c): `INI.cpp` (object 576, first in link order since
    the INI merge) and `SidesListDataChunks.cpp` (object 2445)
  - retail (digest 46fbdb7211c9): `stlport_nocase_asciistring_set_insert.cpp`,
    `stlport_nocase_asciistring_set_touch.cpp` and `stlport_rb_tree_insert_unique_nocase.cpp`

  Before the merge a retail copy came first, so SidesList's copy was latent.
- **Completed:** both units declare the `insert_unique` specialization decl-only, so they
  emit no copy and bind the kept retail one. `./build.sh`: INI.cpp 39/39,
  SidesListDataChunks.cpp 91/91. `tools/link_check.py` against the f995f30157 index:
  - now LINK (0 -> 8,773 B predicted): SidesListDataChunks.cpp 6,726 B,
    Rva006047F3Family.cpp 1,659 B, the three WWLib owner units 388 B
  - INI.cpp itself still fails in that preview, on duplicate INI members (`~INI`,
    `INI::scanInt`, …) from `INI_ctor.obj` and `INI_scanInt.obj`. Those units were merged
    into INI.cpp after f995f30157, so these duplicates are stale-index artifacts, not this
    repair.
- **Historical guarded-input check (2026-10-26, `9e1ca7f93f`):**
  [the guarded INI check](../reverse/attempt_support/ini-current-ledger-prerequisites-20261026.md)
  preserves all 39 rows (3,039 bytes) and five EXACT EH graphs. The published
  index remains `f995f30157`; ordinary preview retains 11 duplicate and eight
  selected findings. The supported current-ledger preview refuses before its
  link verdict because 11,481 providers lack current compiler evidence. This
  count is a strict currency prerequisite, not byte mismatches or a new source
  regression. No source edit, new linked-byte gain or false reject is claimed.
- **Current-provider verification:** the LINK-014 follow-up checks all eight
  insert_unique / _M_find units together and previews all 11,872 B clean,
  including INI.cpp. The historical duplicate-index and __lower_bound
  prerequisites below are cleared in that bounded check.
- **Historical remaining / next check:** the next census confirms the six units. INI.cpp's own link
  also depends on the separate `__lower_bound` provider repair.
- **Clearance:** preview scope only (five of six units against the f995f30157 index).
- **Census confirmation:** awaiting the next census.

### LINK-014: the census at f995f30157's other lost units (htree, SpecialPower, FX, BfmeE8, INI _M_find, BfmeConv499)

**Status: Open (partial repair landed). Updated: 2026-10-26; inspected revision: 65972bab0b.**

- **Evidence / scope:** 22 units linked in the census at ef9c691284 but not at f995f30157,
  for causes other than LINK-013 and the INI `__lower_bound` copy. Found by diffing
  `reverse/link_status.csv` (f995f30157 vs 763dc8759f) and reading the f995f30157
  index's blockers.
- **Completed** (each `./build.sh`-exact and previewed with `tools/link_check.py` against
  the f995f30157 index):

  | Unit(s) | Cause | Repair | Preview |
  |---|---|---|---|
  | `htree.cpp` | Merge af2f149baa dropped `/O1 /DNDEBUG`, so four unrowed Zero Hour definitions (`Create_Interpolated` ×2, `Create_Morphed`, `Vector3::Lerp`) called `_assert`, which retail does not import. | `/DNDEBUG` restored (35306cabab). | 0 -> 2,175 B |
  | 14 special-power ports | My landing of 83b2c3fa65 respelled `~SpecialPowerModule` protected after bcac7d81eb had bound the ports to the public spelling. | Public spelling restored (74fdf83172). | 0 -> 1,212 B |
  | `FXParticleSystemDefaultTemplateDtor.cpp` | My c81e10ce9d anchor made `FXParticleSystem.cpp` emit copies of the `DefaultModuleTemplate<2>/<3>` and Ortho dtors ahead of the owner. | Dtors declared in its views (d4fa3d06f2). | 0 -> 64 B |
  | Two `stlport_vector_e8_*` units | Once 289c748fb3 rowed `vector<BfmeE8>::_M_fill_insert`, their whole-class instantiations were non-retail copies first in link order. | Member declared decl-only; `__copy_backward` instantiated explicitly (1f6a6430ad). | 43/43 BfmeE8 users link, +950 B |
  | `_M_find` owner, `StlSweepR3Rva0002CB7D.cpp` | `INI.cpp`'s `_M_find<AsciiString>` called `vector<void*>::operator[] const` out of line. | Accessor forced inline as the owner does; copy now equals retail (f37ca79179). | +110 B |
  | `BfmeConv499.cpp` | 51cc7ed5dc dropped the alias for placeholder `bfmeDoBNH`. | Builds its handle base in place from `TextureAsset::Get`; orphaned pin dropped (65972bab0b). | 0 -> 27 B |

- **Ctor vtable reconciled (2026-10-26):** the ctor and dtor private views now
  declare the same named interface slots: `onSpecialPowerCreation` at slot 7,
  `pauseCountdown` at slot 9 and `startPowerRecharge` at slot 15. Both views now
  bind the same external definitions; this removes the ctor's pure slot 7 and
  the dtor's pure slots 9/15. `./build.sh` passes 7/7 rows across the two
  sources; `tools/link_check.py` against the 763dc8759f check index now links
  `SpecialPowerModuleCtor.cpp` for its 340 bytes (0 -> 340 B).
- **Dtor unit and 14 ports reconciled (2026-10-26):** the minimal
  `BehaviorModule` view in `SpecialPowerModuleDtor_Unresolved.cpp` shared the
  canonical class name, so it emitted two non-retail
  `??_7BehaviorModule@@6B...` COMDATs. Renaming that local, layout-only view
  `BehaviorModuleView` stops those false table owners without changing the
  `SpecialPowerModule` vtable or dtor bytes. `./build.sh` passes 5/5 rows;
  `tools/link_check.py` links the dtor unit for 222 B and all 14
  `??1SpecialPowerModule@@UAE@XZ` consumers for 1,212 B (0 -> 1,434 B).
- **Remaining / next check:** `OCLSpecialPower.cpp` still fails on its private
  protected dtor spelling, an unresolved `PartitionManager::findPositionAround`
  and a `FindPositionOptions` constructor copy. It was not one of the 14
  public-spelling ports.
- **Clearance:** preview scope only (the units listed above and the 14 ports).
- **Census confirmation:** awaiting the next census.

#### Current-provider follow-up, 2026-10-25

The [39-source verification](../reverse/attempt_support/link-regression-clusters-20261025.md)
at `aa31e9bac4` plus the two consumer access corrections confirms the six
historical regression clusters in ordinary preview. All eight AsciiString
units link (11,872 B), as do htree (2,175 B), all three E8 owners (928 B),
the FX template destructor (64 B), and BfmeConv499 (27 B). These are inherited
repairs verified together, rather than additional changes made by this pass.

The expanded check exposed two consumers of the public `BehaviorModule`
destructor formerly emitted by the minimal SpecialPower view:
`SpecialPowerModuleCtor.cpp` and `WeaponModeSpecialPowerUpdateCtorThunk.cpp`.
Their local views now declare that destructor protected, matching the 16
existing indexed providers. Normal verification passes 6/6 rows across both
consumers and a provider, with both consumer EH graphs EXACT. The constructor
links for 340 B; WeaponMode keeps its census-linked 112 B. No forwarding
implementation or new alias is retained.

The recorded combined result at that base is 32/39 clean units; six independent
candidates and the broader DumbProjectile provider unit were blocked as detailed
in the evidence. Concurrent upstream repairs in LINK-015 and LINK-016 supersede
the VectorClass<Vector3> and XferSave residuals from that snapshot.
OCL's protected SpecialPower destructor, findPositionAround and
FindPositionOptions remain open. Float-format's attempted active append
declaration triggers VC7.1 C1001; its alternate syntax fails C2768/C2244/C1506.
An `extern template` declaration of the same member (the MSVC C4231 extension),
tried in `urlBuilder.cpp` on 2026-10-26, also ends in C1001 (`_string.h(573)`); restored.
Both float trials were restored. Broader family closure and census
confirmation remain pending.

### LINK-015: naming `VectorClass<Vector3>`'s deleting destructor proved the consumers' inlined copies wrong

**Status: Census-confirmed for the four repaired units; two teardown units remain blocked. Updated: 2026-10-26; inspected revision: c01848c0b1.**

- **Evidence / scope:** 4e0bfa8260 named retail 0x000F1CF7 as
  `??_G?$VectorClass@VVector3@@@@UAEPAXI@Z` (34 B: vptr store, call to the kept
  `Clear` 0x000F0CD4, `pop ecx` after `operator delete`) and rowed it in
  `vector_class_vector3_ctor.cpp`. Once it had a retail address, the seven other
  copies were proven wrong: they inline `Clear` (/O2), and the /G7 ones clean up with
  `add esp, 4`. The first in link order, `collect.cpp`'s, was the one kept, so the
  census at ef9c691284 lost `pointgr.cpp`, `PointGroupClassRva0017A890.cpp`,
  `DX8SkinClearVisibleList.cpp`, `Rva007B7280Siblings.cpp` and `Rva007B73C0.cpp`,
  all linked at d2636bb381 (`reverse/link_status.csv` history). The owner's copy is
  only `unknown`, never `retail`: its DIR32 to `??_7?$VectorClass@VVector3@@@@6B@`
  (0x007CEFAC) has no data row, so no proven copy lets the wrong ones stand
  (retail-truth-3).
- **Completed:** `collect.cpp`, `mesh.cpp`, `DX8SkinClearVisibleList.cpp`,
  `PointGroupClassRva0017A890.cpp` and `pointgr.cpp` declare
  `~VectorClass<Vector3>` decl-only, so cl synthesizes neither `??_G` nor the
  `VectorClass<Vector3>` vtable there. Declaring `Clear` decl-only instead is not
  enough: the /G7 units still differ (`add esp, 4`), and `pointgr.cpp`'s
  `Rva00912CF0` inlines `Clear` as retail does. `pointgr.cpp` explicitly
  instantiates the virtuals the vtables used to bring: its rowed `ID(T const *)`
  (0x001298B0, /G7, retail-proven, now the first copy) and `ID(T const &)` and
  `operator==`, which the other units only declare. `vector_class_vector3_ctor.cpp`
  declares `ID(T const *)` decl-only: its non-/G7 copy (wrong) would otherwise be
  the first. `./build.sh`: 90/90 rows exact across the six sources.
  `tools/link_check.py` against the 763dc8759f index with all nine current objects
  (including `FXShaderRendererSkin.cpp`): `PointGroupClassRva0017A890.cpp`
  0 -> 11,964 B, `pointgr.cpp` 0 -> 10,565 B, `DX8SkinClearVisibleList.cpp`
  0 -> 1,613 B, `vector_class_vector3_ctor.cpp` 0 -> 194 B (+24,336 B);
  `FXShaderRendererSkin.cpp` keeps 937 B; `collect.cpp` and `mesh.cpp` keep only
  their earlier, unrelated blockers.
- **Remaining / next check:** `Rva007B7280Siblings.cpp` (353 B) and
  `Rva007B73C0.cpp` (59 B). Retail's teardowns inline both the destructor and
  `Clear`, so these /O2 units must keep both inlinable, and cl synthesizes their
  own inlined `??_G`, which loses while no copy is proven. Either a verified home
  for the 0x007CEFAC vtable that proves the owner's copy retail (retail-truth-3
  then lets the wrong copies stand), or consolidating the teardowns back into
  their retail TU, `pointgr.cpp`, would clear them. No source trial; no hatch
  (`#pragma optimize`) considered.
- **Clearance:** preview scope (the units above) on current objects.
- **Census confirmation:** the census at d1f046749a (2026-10-26 13:18) links
  `pointgr.cpp`, `PointGroupClassRva0017A890.cpp`, `DX8SkinClearVisibleList.cpp` and
  `vector_class_vector3_ctor.cpp`; `Rva007B7280Siblings.cpp` and `Rva007B73C0.cpp` still
  lose one COMDAT each, as expected.

### LINK-016: folded bodies whose consumers declare them decl-only, with no provider

**Status: Repair landed / awaiting verification. Updated: 2026-10-26; inspected revision: 856b8bc032.**

- **Evidence / scope:** in the census at 763dc8759f, several units were
  unresolved only on an STL member or a global that they declare (decl-only, to
  avoid a non-retail COMDAT) but that no object defines under that name: retail
  ICF-folded the body under another instantiation's row. Found with
  `tools/link_rank.py --near 1 --json` (units whose only blockers are `U`) and
  each name's `reverse/symbols.csv` address.
- **Completed** (each `./build.sh`-exact; previewed with `tools/link_check.py`
  against the 763dc8759f index, passing the provider and its consumers together):

  | Unresolved name | Retail body | Provider (its flags already emit that shape) | Preview |
  |---|---|---|---|
  | `g_lgaKeyRecords` (0x00A02E50; it also carried two address names) | 16 B tree, ctor 0x007AF8CD | `Rva007B6880Thunks.cpp`: one zero-filled definition through an opaque tree view; Count, Merge and the initializer bind it (25f107697e) | unresolved gone from both LargeGroupAudio units |
  | key-tree `erase(iterator)` (`LargeGroupAudioKeyList.cpp`'s /O1 /Oy- copy was selected) | 0x00056BC3 | `stlport_asciistring_set_base.cpp` (3a828f7bea) | KeyList 0 -> 191 B |
  | `hashtable<pair<const int, Rva0060CF76Element>>::_M_initialize_buckets` | 0x00148DDF | `SelectionIDMap.cpp` (e80fae26b7) | XferSave.cpp 0 -> 1,060 B |
  | `_String_base<char>::_M_throw_out_of_range` | 0x00023A40 (empty /Od body) | `stlport_vector_voidptr_alloc.cpp` (357c8c8a3e) | four narrow-string units 0 -> 904 B |
  | `_Destroy<Rva002BBB96Element *>` | 0x002BB6A5 (BfmeAssignRecord52 loop) | `stlport_asciistring_record_bodies.cpp` (57b0571b72) | the two Deferred units 0 -> 2,925 B |
  | `/alternatename` onto an undefined `__copy<BfmeAssignRecord28 *>` | 0x003F6477 | the rowed `__copy<Rva003F6477Element *>` called directly; two hatches removed (856b8bc032) | VectorRangeEraseRva003F6975.cpp 0 -> 80 B |

- **2026-10-26:** `LargeGroupAudioKeyMapBfmeAddKey.cpp` needed
  `vector<void*>::resize` (0x000E6D39). Its `_M_fill_insert` callee is
  0x00233A5A while `vector<void*>::_M_fill_insert` is rowed at 0x00029CA0, so a
  plain instantiation would bind the wrong callee; the unit now calls the rowed
  owner `vector<Drawable*>::resize` (`DrawableVectorResize.cpp`) through a cast.
  `link_check.py` with `Rva007B6880Thunks.cpp` and `DrawableVectorResize.cpp`:
  0 -> 314 B.
- **Remaining / next check:** Many `U` entries in the 763dc8759f index are stale: check
  with the defining unit's current object before working one (e.g.
  `~SpecialPowerModule` already resolves).
- **Clearance:** preview scope only (the units listed).
- **Census confirmation:** awaiting the next census.

### LINK-061: identity retirement does not resolve verified renumbered EH labels

**Status: Blocked on verifier reconciliation and current providers. Updated: 2026-10-26;
inspected revision: `2f9834aa34`.**

- **Evidence / scope:** [the DX8 retirement refusal](../reverse/attempt_support/dx8-identity-funclet-refusal-20261026.md)
  records 13 identity keys in dx8wrapper.cpp. Normal verification passes 228
  functions, 13 data rows and 21 EXACT EH graphs, including 72 renumbered funclets.
- **Completed:** no source or register edit. Retirement correctly refuses four
  stale providers and separately rejects old funclet labels already resolved by
  the byte gate. The latter is recorded as a false reject, not a debt repair.
- **Remaining / next check:** reconcile the retirement tool with verified parent
  EH resolution in a separate tooling change, refresh providers, then repair and
  judge the descriptor/vector bindings. Do not hand-change pins or labels.
- **Additional consumer (2026-10-26, `9e1ca7f93f`):**
  [window video's current check](../reverse/attempt_support/window-video-debt-cleanup-20261026.md)
  reproduces the same literal-label refusal for four funclets whose parents
  pass all seven EH graphs. Five other retirement findings are not classified
  as false rejects. No identity key is removed; the separate 15-marker hatch
  cleanup preserves every matched byte.
- **Clearance / census confirmation:** none claimed.

### LINK-062: AIUpdate TU span combines weak propagation and disputed placement

**Status: Blocked on independent routing evidence and classification review.
Updated: 2026-10-26; inspected revision: `766153ce00`.**

- **Evidence / scope:** [the current-input routing handoff](../reverse/attempt_support/aiupdate-tu-approval-20261026/readme.md)
  separates 299 proposed rows from the seed's eight verified rows (241 bytes,
  one EXACT EH graph). The official plan has zero approved rows and one mixed
  file. No source, name, register or map was changed.
- **Completed:** six distant K-only assignments explain the broad span;
  the nonvirtual inline getter at 0x0026FF1E also extends it past Upgrade.cpp.
  A read-only diagnostic using the mapper's actual anchored roots still finds
  DisplayStringManager::link at 0x00262027 as a blocker after narrowing those
  bounds. Its WorldBuilder seed is not independent identity proof.
- **Remaining / next check:** prove that row's retail identity/ICF/placement,
  review weak propagation and inline classification separately, and retain
  genuine cross-TU anchors. The seed also retains its mixed rows and ordinary
  link blockers (17 unresolved, six COMDAT, five selected against f995f30157).
- **Clearance / census confirmation:** none. Neither a false reject nor a new
  matched, linked or debt-retirement gain is claimed.

## Investigation-specific validation limitation

The initial investigation preserved a pre-existing BFME 1 checkout at
`f5140c1cff6a58e16276fd6de6788186286953d4`, while BFME 2 pinned
`0bf534ea7ccde110c456edb9cd2dd5dae823c953`. Fetching the provider index succeeded,
but normal object import refused that mismatch. No check was bypassed and no
fresh local compile-based preview was claimed. This is a local input limitation,
not evidence that other agents or the whole repository are blocked. Use a
consistent verified checkout before taking new compile-based measurements.

The graphics follow-up above used a separate checkout with the pinned reference
and completed ordinary compile-based verification. The original checkout was
preserved; its mismatch did not block that isolated check. LINK-008 records the
separate strict receipt limitation encountered there.

### LINK-017: stale link index lacks strict receipts for pending consolidation providers

**Status: Open. Updated: 2026-10-26; inspected revision: 377ffd1724.**

- **Evidence / scope:** outgoing `NetCommandRef.cpp`, `AptValueGCAllocator.cpp`
  and a mechanical MessageStream trial. `tools/link_check.py --fetch-index`
  fetched 763dc8759f, older than the outgoing base. The scoped
  `tools/link_batch_audit.py` reported an inconclusive baseline and two changed
  source objects without current receipts (first MessageStream.cpp).
  `tools/link_check.py --prepare-current` refused NetCommandRef.cpp as not an
  owned current Code provider. A later `dx8vertexbuffer.cpp` trial (four
  accepted donors, nine rows) also built and passed ledger, ownership and
  converged-data checks, but its scoped audit remained inconclusive at base
  `0b692726c4e`: index `47e030bafc` still represented census base
  `763dc8759f` and reported 55 source objects without current receipts. A
  subsequent `link_check.py --fetch-index` imported 22,673 objects but left the
  available index at `47e030bafc`; current `origin/master` later advanced to
  `c511118e28`, so the provider/consumer comparison remains unverified.
  `link_check.py --fetch-index` still returns `47e030bafc`. A fresh audit of the
  pending RepairDockUpdate range marks its base inconclusive and reports 181
  retired objects with provisional provider-disappeared findings. The newer
  index does not yet verify that range.
  The 2026-10-26 AptRenderingContext trial added a current destination and
  refreshed strict receipts for its outgoing RepairDockUpdate composition and
  ConstIntGetters4 split. Its scoped audit still used index 763dc8759f, reported
  232 retired objects and provisional provider-disappeared findings, and marked
  the baseline inconclusive against current `origin/master`. The changed
  provider/consumer comparison remains unverified; the Apt trial was restored.
  A later HighlanderBody merge/split trial refreshed all four outgoing objects,
  but the audit against the same index still reported an inconclusive baseline,
  264 retired objects and provisional provider-disappeared findings. That trial
  also remains restored; no changed binding is verified from this index.
  On 2026-10-26, the RandomSoundSelectorClientBehavior TU trial accepted its
  five rows and passed its byte build, frozen-file, ledger, identity, data,
  ownership and class checks. `link_check.py --prepare-current` produced a
  strict current receipt for the merged TU. Its scoped `link_batch_audit.py`
  against outgoing base `eeee783b2fa447d3dd4566274c7811690f594f9c` still used
  provider index `47e030bafc` (census base `763dc8759f`), reported 206 retired
  objects and 1,080 provisional provider-disappeared findings, and marked the
  base inconclusive. No changed provider/consumer binding is verified for this
  composition; the trial was restored after preserving its patch and audit in
  `build/consolidation/randomsound/`.
- A `GameMemory.cpp` merge trial accepted four donors and byte-built 5/5 rows;
  its staged code-identity/data checks reported one shadow identity finding
  and zero data findings. The scoped audit against current `origin/master`
  remained inconclusive: the index is still `47e030bafc`, and the merged
  `GameMemory.cpp` has no current link receipt. The trial was restored. Its
  accepted donor set, staged patch and exact audit result are preserved under
  `build/consolidation/gamememory/`; `Rva000308E0AddHeap.cpp` was rejected for
  a duplicate `MemoryPool::HeapTable`.
- For `AptScriptColour.cpp`, the whole-file dry run accepted no donors. Two
  mixed-file split dry runs carved matched rows and compiled beside the TU, but
  remain blocked on the same provider/consumer audit. The
  `AptFactoryConstructors.cpp` split was refused because copying its helpers
  would grow an escape-hatch count.
- A `GameWindowGlobal.cpp` merge trial accepted `GameWindowManager_winFindImage.cpp`
  unchanged, preserved five matched rows and passed its byte build, frozen-file,
  ledger, ownership, identity, data and staged new-variant checks. The required
  provider/consumer audit against outgoing base `7d964ea623` was inconclusive:
  index `47e030bafc` (2026-10-26 08:28) predates that base, reports 207 retired
  objects and 207 provisional provider-disappeared findings, and only one
  current object was available. The merge was restored after preserving its
  scoped evidence in `reverse/attempt_support/consolidation-mechanical-20261026.md`;
  no changed binding or source-file reduction is claimed.
- DetachableRiderUpdate and TileData accepted-donor trials also passed their
  local byte/ownership checks but were restored after the same provider audit
  remained stale or inconclusive. TransportAIUpdate's accepted donor built, but
  its staged identity gate found a new divergent `getContain` name and the
  available census omitted the destination; it too was restored. Their exact
  results are in the same consolidation handoff.
- **Completed:** MessageStream's byte build, frozen-file, ledger, data,
  ownership and new-variant checks passed; the mechanical trial was restored
  because provider/consumer comparison remained incomplete. See
  `reverse/attempt_support/consolidation-run-20261026.md`.
- **2026-10-26 codex4 prerequisite recovery:** inherited local LifetimeUpdate and
  LargeGroupAudioUpdate declaration repairs retain their scoped COFF
  proofs: Lifetime accepts six rows / 329 existing bytes, LargeGroup accepts
  ten / 155. No merge or source-path move is applied. At base `aa404c29b6`,
  `link_check.py --fetch-index` still supplies `47e030bafc`; the full changed-header
  closure audit reports an inconclusive baseline and 1,137 objects without
  current strict link receipts. This does not establish a selected-provider
  regression or clearance. The standalone/composed definition, selection and
  reference comparisons are recorded in
  `reverse/attempt_support/consolidation-prerequisite-recovery-20261026-codex4.md`.
  Preserve this batch's census confirmation as pending; do not repeat its
  unchanged receiver/base ABI blockers or run maintainer-only measurements.
  Recovery follow-up withdrew the shared GameLogic Hulk accessor/header adoption:
  the required push dry run reproduced PlaceEventTranslator 0x0043218A's
  build/builder stack-home swap. Restoring the original header with a local field
  view passes both units (7/7 functions); the header queue debt is restored.
  Three local prerequisite repairs remain; original adoption evidence is banked.
- **Remaining / next check:** after the next published census/index supplies
  current receipts, rerun `link_batch_audit.py` for these exact source paths
  and `Code/Libraries/Source/WWVegas/WW3D2/dx8vertexbuffer.cpp`,
  `Code/GameEngine/Source/Common/System/GameMemory.cpp`, and
  `Code/Libraries/Source/Apt/AptObject/AptScriptColour.cpp`; inspect
  selected-provider changes and affected consumers.
- **Clearance:** none; no provider or consumer change is claimed verified.
- **Census confirmation:** awaiting a current index and next census.

### LINK-018: canonical `Coord3D` member growth blocks header-adoption until dependents are recomputed

**Status: Open. Updated: 2026-10-26; inspected revision: 5dcf22e436c (2026-10-25 trials).**

- **Evidence / scope:** retiring coord3d_crossproduct.cpp's private
  class Coord3D : Coord3DBase view for the canonical Lib/Coord3D.h +
  Lib/Coord3DBase.h pair byte-matches the 97B body (1/1) once CrossProduct
  is declared in the canonical header, but the declaration alone regresses the
  unrelated dependent Player::initFromDict 0x002AFCDF (2,762 B): without it
  the unit is 31/31, with it uild.py's funclet identity check reports
  $L10490 does not hold this funclet while $L10524 and $L10523 match
  equally. An unrelated probe member (int ProbeMember0001(int) const) fails
  identically and deterministically with BFME_OBJSTORE=off, so ANY member
  growth of the canonical class perturbs that dependent's compiled EH funclet
  layout. The trial reverted
  (
everse/re_attempts.log, 2026-10-26 retraction and blocked entries); the
  ledger row keeps the V class-key spelling of its private-view unit and
  
everse/header_queue.tsv keeps the row.
- **Remaining / next check:** member additions to Coord3D.h ship only
  together with a dependent recompute (the precedent header extensions
  24ef6a5e83 and 505f43a1c73 landed with their own dependent work). For
  the Coord3D queue (13 private-body units and 42 view users in
  
everse/header_queue.tsv), inventory a dependent set that reproduces
  PlayerInitFromDict.cpp 31/31 with the grown header before publishing any
  new member; the coord3d_crossproduct.cpp adoption resumes then. Related
  view-shape blocks: TeamPrototypeMoveTeamTo.cpp (inlined user copy-ctor
  by-value staging) and AISpecialPowerPickers.cpp (array-of-Coord3D EH
  unwind registration) are recorded in 
everse/re_attempts.log.
- **Clearance:** none; no header or dependent change is claimed verified.
- **Census confirmation:** n/a (adoption lane; surfaced via the scoped header
  gate, not the link census).

#### Region3D adoption: separate Coord3D class-key/provider prerequisite

- **2026-10-26, inspected `c973319b7d3`:** the Region3D queue serves
  `WWMath/region.cpp` with a canonical/private Coord3D redefinition. The
  supported, non-applying Coord3D header trial (`--sample 1 --seed 17`) selects
  this file and fails its 47-byte Region3D debug streamer at `0x0000517C`.
  Canonical `struct Coord3D` emits two undefined U-form streamer calls; retail
  calls `0x000050BA`, owned by the V-form provider in `WWMath/coord3d.cpp`.
  A scoped consumer ledger rename cannot migrate that separate provider.
- **Remaining:** reconcile canonical Coord3D adoption across the provider and
  callers, preserving constructor behavior and verifying dependent rows. This
  class-key binding prerequisite is distinct from the member-growth/EH failure
  above. No alias, pin or shared-header growth was applied.
- **Preservation:** the tool restored source/ledger; normal build passes 45/45
  rows and seven string references. Current link preview retains 1,287 bytes
  against census `d1f046749a`; no clearance, queue retirement or census gain.
  Evidence: `reverse/attempt_support/region3d-header-prerequisite-20261026-bce2/`.

### LINK-019: `Rva0039B893` vtable mismatch across copy-ctor and default-ctor units blocks `ScoreKeeperPerFrameStatsDefaultResizeDeferred.cpp` linking

**Status: Cleared. Updated: 2026-10-26; inspected revision: d831bc24031.**

- **Evidence / scope:** `Code/GameEngine/Source/Common/RTS/ScoreKeeperPerFrameStatsDefaultResizeDeferred.cpp`
  failed link_check with unresolved virtual symbols `loadPostProcess`, `crc`, `xfer` and COMDAT
  vtable divergence for `??_7Rva0039B893@@6B@`. The class declared virtual methods from Snapshot without
  bodies, differing from the single virtual destructor emitted by earlier link-order unit `V3PolyCopyCtors.cpp`.
- **Completed:** Reconciled `Rva0039B893` declaration in `ScoreKeeperPerFrameStatsDefaultResizeDeferred.cpp`
  to match `V3PolyCopyCtors.cpp` with `virtual ~Rva0039B893()`, eliminating pure virtual unresolved references
  and COMDAT vtable conflict.
- **Clearance:** `tools/link_check.py Code/GameEngine/Source/Common/RTS/ScoreKeeperPerFrameStatsDefaultResizeDeferred.cpp`
  reports: LINKS (0 -> 66 bytes). Full 2/2 matched rows preserved.
- **Census confirmation:** awaiting the next census.


### LINK-020: single-blocker census units (32 units, 2026-10-26 pass)
Status: Open. Updated: 2026-10-26; inspected revision: 655f117955; census 2026-10-26 08:28 at 47e030bafc.
Evidence / affected units: `link_rank.py --json` listed 32 census units with exactly one blocker
(14 U, 8 L, 6 S, 3 A, 1 D). Two seats rechecked every one with `link_check.py --fetch-index` and
`--refresh`. Neither committed a change.
Completed:
- Already link on current master (the census entry is stale; verified with `--refresh`, no edit):
  `XferSave.cpp` (1,060 B), `VectorRangeEraseRva003F6975.cpp` (80 B), `stlport_float_format.cpp`,
  `stlport_narrow_stringbuf_overflow_setbuf.cpp`, `stlport_narrow_ostringstream_dtor.cpp` (429 B),
  `urlBuilder.cpp` (868 B), `StlportNarrowAppendCStr.cpp` (58 B), `Rva001F9524Concat.cpp` (160 B).
- A trial declare-only `basic_string::append<const char*>` specialization in the STLport narrow-string
  units hit C1001 at `_string.h(573)`. It was reverted, and those units link without it.
Remaining / next check (each needs a decision, a row or a shared change; none is unit-local):
- `_String_base<char>::_M_throw_out_of_range` (U in `stlport_narrow_string_copy`, `_substring_ctor`,
  `_erase_count`, `_substr`): cleared upstream by 1e45b8be0f, which supplies the body from
  `stlport_vector_voidptr_alloc.cpp`. All four units LINK when `link_check.py` is run together with that
  provider (LINKED 0 -> 904 B). Run alone, a stale provider object still reports them as unresolved.
- `_Destroy<Rva002BBB96Element*>` and `_Destroy<Rva004758F4Element*>` (U in
  `StlportVectorDtorDeferred.cpp` and `StlportVectorClearRva00475F2A.cpp`): pins only (0x002BB6A5,
  0x00470398); the owners are `__destroy_aux` rows with a two-argument push. This needs a `_Destroy`
  owner row or a caller rewrite.
- `vector<PrereqUnitRec>::operator=` (U in `StlSweepW5Rva0042830DAssignTwin.cpp`): a wrong premise.
  Retail 0x0042816E calls 0x000120C0 twice, the rowed 41 B narrow `basic_string::operator=`, so the
  element holds two strings, not vectors. The twin now uses two `basic_string<char>` members and LINKS
  (0 -> 33 B). `ThingFactory.cpp`'s `ProductionPrerequisite::operator=` row at the same address still
  declares the vector layout; reconcile that view separately.
- `AcademyStats::recordSpecialPowerUsed` (U in `SpecialPowerModule.cpp`): the call comes from the
  present-unmatched ZH `initiateIntentToDoSpecialPower`. Retail's 0x004946F3 makes no AcademyStats call,
  so there is no retail body to recover. Find a retail caller of the stat, or drop the ZH call from the
  unmatched body.
- `g_00DB5BD4` (U in `Rva000FDCD7Get.cpp`): lies inside the 144-byte data row `g_00DB5B88`
  (0x9B5B88..0x9B5C18). This needs a data-ledger split.
- `latest_texture` (U in `DebugStatisticsTextureShutdown.cpp`): a file-static in
  `DebugStatisticsRecordTexture.cpp`; the thunk belongs in that TU (consolidation).
- `@_RTC_CheckStackVars@8` (D in `RtcStack.cpp`): also defined by the vendored msvc71crt lib. This needs
  an owner decision.
- `ChunkLoadClass(FileClass*)` (U in `w3d_dep.cpp`): retail's constructor takes `BFMEChunkInput*`
  (row 0x00614EF0). The unit also has six unresolved `__imp_` STL names.
- `BridgeScaffoldBehavior.cpp`: the unresolved `UpdateModule::loadPostProcess` is gone on current
  inputs, but duplicate-definition blockers (ctor, `update`, `xfer`, interface getter) remain.
- `??_7Debug@@6B@` (L in `DebugDestructorThunk.cpp`): retail has 37 slots with `??_GDebug` at slot 16;
  the shared `reference/shims/debugvtable` emits 35. A shared Debug view must shift the later slots
  (already recorded three times in `re_attempts.log`).
- `??_7GameWindow@@6B@` (L in `GameWindowDtor.cpp`): the 0x0080BBCC table is shared with
  `BfmeAptScreenBase`. This needs a class-view reconcile.
- `VectorClass<Vector3>` deleting destructor (S in `vector_class_vector3_ctor.cpp`): see LINK-015.
- `PartitionData::updateCellsTouched` (S): the kept body is a 426 B SSE method, but retail 0x73AD90 is
  a 1,158 B x87 body. Resolved in `PartitionData_friendUpdateCellsTouched.cpp` via native `ShroudManager::Data::UpdateCellsTouched` (LINK-037).
- `WeaponTemplate::getName` (S in `Weapon_getName_Thunk.cpp`): an ICF alias at 0x28F940, shared with
  `NetCommandMsg::getContentsAsAsciiString`. This needs an owner decision.
- Pod28/Pod32 vector copy and `_M_fill_insert` (S in `Rva00541913CopyCtor.cpp`,
  `Rva0056616BCopyDeferred.cpp`, `stlport_pod28_vector_resize_value.cpp`): see
  `reverse/attempt_support/pod-copy-link-20261024/readme.md`.
- `ConstIntGettersAddr.cpp` and `ConstIntGetters2Addr.cpp` (A): the flagged values are returned
  constants, not addresses; there is no global to bind. This looks like a heuristic false positive.
Clearance: the 8 already-linking units preview LINKS against index 47e030bafc with current objects.
Census confirmation: awaiting the next census.


### LINK-021: W3DRopeDraw ctor linked against non-retail headers emitting conflicting COMDATs and unresolved references
Status: Cleared. Updated: 2026-10-26; inspected revision: 692d9a3158.
Evidence / affected units: `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DRopeDrawCtor.cpp`,
`reverse/link_status.csv` reported 3 blockers (1 unresolved, 2 COMDAT collisions).
Completed: Replaced non-retail BFME1 sweep headers with verified minimal class kit matching `W3DRopeDrawDtor.cpp`.
Remaining / next check: None.
Clearance: `tools/link_check.py Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DRopeDrawCtor.cpp`
reports: LINKS (0 -> 164 bytes). Exact 1/1 byte match preserved.
Census confirmation: awaiting the next census.


### LINK-022: placeholder BfmeConv1879 unlinked due to 5 unresolved placeholder symbol declarations
Status: Cleared. Updated: 2026-10-26; inspected revision: 38777f70d4.
Evidence / affected units: `Code/GameEngine/Source/Common/BfmeConv1879.cpp`,
`reverse/link_status.csv` reported 5 unresolved blockers (`??0BfmeBase0ZL@@QAE@PAV0@@Z`, `??0BfmeMidZL@@QAE@PAV0@@Z`, `_bfmeVft0ZL`, `_bfmeVft1ZL`, `_bfmeVft2ZL`).
Completed: Replaced placeholder symbols with real rowed base copy ctors `??0Rva0055BCD2@@QAE@ABV0@@Z` at `0x003ADDCD` and `??0Rva0055B32B@@QAE@ABV0@@Z` at `0x003ADCC7`, data row `g_00C1D11C` at `0x0081D11C`, global `s_slot3E4first` at `0x0081C780`, and string literal `"HZz"` at `0x0081D10C`.
Remaining / next check: None.
Clearance: `tools/link_check.py Code/GameEngine/Source/Common/BfmeConv1879.cpp`
reports: LINKS (0 -> 82 bytes). Exact 1/1 byte match preserved.
Census confirmation: awaiting the next census.

### LINK-023: `HAnimClass` views disagree on the vtable layout (`hcanim.cpp` vs `bfmehrawanim`)

(Filed as LINK-020 in its `reverse/re_attempts.log` entry for 0x0018D2A0; renumbered on rebase.)

**Status: Open (partial repair landed). Updated: 2026-10-26; inspected revision: 60517e12b1.**

- **Evidence / scope:** `Code/Libraries/Source/WWVegas/WW3D2/HRawLoadW3D_Unresolved.cpp`
  (149 B, `HRawAnimClass` ctor 0x0018D2A0) lost `??_7HAnimClass@@6BRefCountClass@@@` to
  `hcanim.cpp` and `??_7HRawAnimClass@@6BRefCountClass@@@` to `hrawanim.cpp`. The two winning
  copies come from incompatible `HAnimClass` views: `hcanim.cpp` reads BFME 1's
  `game/.../WW3D2/hanim.h` (23 slots, with `Get_Translation/Get_Orientation(int,float)`,
  `_bfme_hanim_fade`, `_bfme_hanim_v21`), `hrawanim.cpp` reads `reference/shims/bfmehrawanim/hanim.h`
  (21 slots; `HRawAnimClass` appends `Get_VisibilityF` as slot 21). A unit that constructs
  `HRawAnimClass` emits both vtables, so no local view can agree with both owners.
- **Retail (target facts, read from 0x007D5CB8 / 0x007D5D20 / 0x007D5D88, 23 slots each):**
  0 Delete_This, 1 deleting dtor, 2 `Get_Name` (lea +10), 3 dword +40 (name key), 4 lea +30
  (hierarchy name), 5 +44 frames, 6 +4C rate, 7 `Get_Total_Time`, 8 `Get_Translation(Vector3&,..)`,
  9 `Get_Orientation(Quaternion&,..)`, 10 `Get_Transform`, 11 `Get_Visibility`, 12 fade
  (`Get_VisibilityF` / `_bfme_hanim_fade`), 13 +48 `Get_Num_Pivots`, 14 `Is_Node_Motion_Present`,
  15..19 `Has_*`, 20 `Has_VisibilityF` (base returns true), 21 `Class_ID`, 22 pure (raw 0x0018E6F0,
  compressed 0x0018FB70). Neither view has this layout; retail's HRaw ctor stores no `HAnimClass` vptr.
- **Completed:** the unit's `HRawAnimClass` view declares `Get_VisibilityF` as `hrawanim.h` does;
  its HRaw vtable copy now has `hrawanim.obj`'s digest. `./build.sh` 1/1. Tried
  `__declspec(novtable)` on its `HAnimClass` view: the vtable goes but an out-of-line
  `??0HAnimClass@@QAE@XZ` copy then differs from retail's, so reverted.
- **Remaining / next check:** reconcile `HAnimClass` (and the HRaw/HCompressed overrides) to the
  retail layout above in one shared view for `hcanim.cpp`, `hrawanim.cpp`, `htree.cpp`,
  `HRawLoadW3D*.cpp`, re-verifying every virtual-call offset in their matched bodies.

### LINK-024: `LivingWorldBuildingCtor.cpp` needs placeholder `Rva004E0D67` named `LivingWorldBuilding`
Status: Open. Updated: 2026-10-26; inspected revision: d40f06e91c.
Evidence / affected units: `Code/GameEngine/Source/GameLogic/System/LivingWorld/LivingWorldBuildingCtor.cpp`
(298 B) has three unresolved names on current inputs (`link_check.py`, index 47e030bafc):
`??1LivingWorldBuilding@@UAE@XZ`, `?LoadPostProcess@LivingWorldBuilding@@UAEXXZ`, `??1Rva004E0790@@QAE@XZ`.
Target facts: retail ctor 0x004E119C stores vptrs 0x00C61618 (Snapshot) and 0x00C61610 (RegionTurnObserverView).
0x00C61618 slots: 0 = 0x004E0E5C (rowed `??_GRva004E0D67` in `OpaqueScalarDeletingDtorsB11.cpp`, which calls the
dtor 0x004E0D67, rowed `??1Rva004E0D67` in `Rva004E0D67Dtor.cpp`), 1 = 0x000B3FD0 (the shared empty `ret`),
2 = 0x004E0777 `GetSnapshotName`, 3 = 0x004E0E78 `DoXfer`. The ctor's +0x3C unwind funclet (0x0079198E) jumps to
0x002B2E8E, the ICF-folded holder dtor already rowed as `??1ArmySummaryEntryRef@@QAE@XZ` (fold-proof in
`Rva002B4076Dispatch.cpp`).
Completed: none (investigation only).
Remaining / next check: rename class `Rva004E0D67` to `LivingWorldBuilding` (dtor row and the B11 `??_G` row;
drop the `??1Rva004E0D67` pin), reconciling B11's one-slot `EmitVtableTag` view with the ctor TU's vtables;
give `LoadPostProcess` its empty body or a fold-proof row at 0x000B3FD0 (precedent: `SpawnArmy::loadPostProcess`);
respell the ctor's `Rva004E0790` holder dtor to `ArmySummaryEntryRef` (or rename the class). Then
`link_check.py` the ctor with `Rva004E0D67Dtor.cpp` and `OpaqueScalarDeletingDtorsB11.cpp`.
Clearance: pending.
Census confirmation: not claimed.

### LINK-025: `StlSweepR3Rva0002CCC3.cpp`'s opaque hashtable record needs the macro table's real type
Status: Blocked (identity prerequisite). Updated: 2026-10-26; inspected revision: 308a442bae.
Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva0002CCC3.cpp` (67 B): unresolved
`Rva0002CCC3Record` `operator==` and `hash::operator()`, plus a wrong-selected `clear`. Retail 0x0002CCC3 calls the
folded `clear` 0x002234FE, whose node deleter is the `pair<const AsciiString,AsciiString>` `_M_delete_node`
0x0002C9A6; its callers are 0x0002CD71 and 0x0002CD7B (INIMacroTable's dtor per the re_attempts.log 0x0002CD7B entry).
Completed: trial (reverted, logged in re_attempts.log): instantiating only `~hashtable` with a declaration-only `clear`
builds 2/2 exact and drops the opaque references, but the pinned `clear` name stays unresolved.
Remaining / next check: name the macro table's hash_map type (it differs from 0x002236B9's
`rts::hash<AsciiString>` instance) and respell the record in this unit; `INIMacroTable.cpp` was file-claimed by
another seat on 2026-10-26.
Clearance: pending.
Census confirmation: not claimed.

### LINK-026: a unit owns a Zero Hour field-parse table whose parsers BFME 2 rows under other names

**Status: Repair landed / awaiting census. Updated: 2026-10-26; inspected revision: 9f93879fe9.**

- **Evidence / affected units:** `ControlBarScheme_trolBarScheme_QAEXPAVControlBarSchemeAnimation_Z.cpp`
  (18 B, `ControlBarScheme::updateAnim`) owns `ControlBarSchemeManager::m_controlBarSchemeFieldParseTable`
  (data_ledger 0x0080CD88) but defined it from Zero Hour, so it referenced
  `ControlBarSchemeManager::parseImagePart/parseAnimatingPart`, which nothing defines. Retail's table
  (read from game.dat) points ImagePart at 0x00320158 and AnimatingPart at 0x003201A9, rowed as the
  placeholders `Rva00320158Parse` / `Rva003201A9Parse`; it also has BFME's ButtonBorderAlteredColor
  entry and different offsets from the Zero Hour `offsetof` values.
- **Completed:** b749c0bf05 writes retail's 68 entries (parsers by their rowed names, retail offsets).
  link_check (index 47e030bafc): the unit LINKS 0 -> 18 B; `ControlBarRva00320158.cpp`,
  `ControlBarRva003201A9.cpp`, `ConstIntGetters5Addr.cpp` and the newControlBarScheme unit still link.
- **Remaining / next check:** the same cause may sit in other Zero Hour-donor units whose owned
  table names an unrowed parser (`link_rank.py --near` U names `?parse*`): read the retail table and
  bind its entries to the rowed owners. Naming the two factories `parseImagePart`/`parseAnimatingPart`
  needs a signature change, which `rename.py` refuses; leave it to the naming lane.
- **Clearance:** current-object preview of this one unit only.
- **Census confirmation:** awaiting.

### LINK-027: `StlSweepW5Rva00423EB0.cpp` destroys the nested word deque under a placeholder element

**Status: Open. Updated: 2026-10-26; inspected revision: 9f93879fe9.**

- **Evidence / affected units:** `StlSweepW5Rva00423EB0.cpp` (33 B, `__destroy_aux` 0x00423EB0)
  loses `??1Rva00423EB0Element@@QAE@XZ` and `_Deque_iterator_base<Rva00423EB0Element>::_M_increment`
  (census: not retail's body, wrong selected). Its element is a one-`wstring` placeholder, but its
  symbols.csv pins already say what retail calls: the element dtor is 0x00422D48, rowed as
  `??1?$deque@UBfmeWordValue4@@...` (`StlportNestedWordDeque.cpp`), and the iterator step is 0x0042198C,
  rowed as `_Deque_iterator_base<BfmePod40>::_M_increment` (40 B = sizeof the inner deque). Its only
  retail caller is 0x004244E2 inside `__destroy<Rva004244C1Element>` 0x004244C1
  (`StlSweepW5Rva004244C1.cpp`, links today through its own pin). So 0x00423EB0 is
  `__destroy_aux<_Deque_iterator<deque<BfmeWordValue4>>>`, the outer-deque teardown of the
  `StlportNestedWordDeque*.cpp` family.
- **Completed:** none; diagnosis only (no source trial).
- **Remaining / next check:** respell both StlSweepW5 units over the real `InnerDeque` element
  (`add_match.py ... --replace-rva`, or rehome into the family's approved unit per tu_map), build them,
  then decide whether 0x0042198C's `BfmePod40` row is the same `deque<BfmeWordValue4>` iterator.
  Verify with `link_check` on both StlSweepW5 units plus `StlportNestedWordDeque.cpp`.
- **Clearance:** pending.
- **Census confirmation:** not claimed.

### LINK-028: module ctor units whose private ZH-shaped view emits vftable COMDATs a ZH port also emits

**Status: Open (one unit repaired). Updated: 2026-10-26; inspected revision: `9f93879fe9`.**

- **Evidence / affected units:** `StealthUpdateCtor.cpp` (208 B) declared a ZH-shaped
  `ObjectModule`/`BehaviorModule`/`UpdateModule` chain, so its `??_7StealthUpdate@@6B@`,
  `6BObjectModule@@@` and `6BBehaviorModuleInterface@@@` copies (one slot each) lost to
  `StealthUpdate.cpp`'s full ZH copies (no retail address, first in link order). Its dtor
  `??1StealthUpdate` was unresolved because the retail dtor 0x00373CB1 was rowed as the
  placeholder `Rva00373CB1` in `Code/GameEngine/Source/Common/Rva0024A797Derived.cpp`, the
  flattened `UpdateModule, MiBase1, <X>_B2` family of opaque module destructors.
- **Completed (`895c0f21ef`):** renamed `Rva00373CB1` to `StealthUpdate` (ctor and dtor store
  the same vftables 0x00817F20/0x007EFF90/0x00817F14; slot 0 is the deleting dtor 0x00373F3D),
  and gave the ctor unit the Derived unit's flattened hierarchy with the two interface bases
  `__declspec(novtable)` (retail stores only the three StealthUpdate vftables). `./build.sh`
  2/2 and 60/60; current-object `link_check` 0 -> 208 B, with Derived, FriendNew, Xfer and
  Logic still linking. Census confirmation pending.
- **Remaining / next check:** other classes in `Rva0024A797Derived.cpp` (placeholder dtors
  whose `f2` alternatename names the module's `update`, e.g. LifetimeUpdate, FloatUpdate,
  HijackerUpdate) may have ctor units with the same split; a scan of the 08:28 index found no
  such unresolved `??1<Name>` blocker for those names, so check each ctor unit's blockers
  before working it. The vftable copies stay one-slot views of retail's full tables.
- **Clearance:** scope `StealthUpdateCtor.cpp` only, current-object preview at `895c0f21ef`.
- **Census confirmation:** awaiting.

### LINK-030: ZH-header units emit a wrong `BitFlags<116>::clear` ahead of the rowed copy

Status: Open. Updated: 2026-10-26; inspected revision: 9f93879fe9 (index 47e030bafc).
Evidence / affected units: `BitFlagsClear.cpp` (14 B, row 0x00666E80) fails `selected` on
`?clear@?$BitFlags@$0HE@@@QAEXXZ`. The index has four copies: `DumbProjectileBehavior.cpp`,
`Player.cpp` and `WeaponSet.cpp` (all `wrong`, first in link order) and `BitFlagsClear.cpp`
(`retail`). The wrong copies are `jmp ?reset@?$bitset@$0HE@@_STL@@...`, whose reset calls
`memset`; retail's is four inline dword stores.
Completed: trial (reverted, no commit) of a decl-only `template <> void BitFlags<116>::clear();`
in `WeaponSet.cpp`: after `PreRTS.h` it hits C2908 (already instantiated: ZH `KindOf.h`'s
inline `CLEAR_KINDOFMASK`/`SET_ALL_KINDOFMASK_BITS` call `clear()`, and `DisabledTypes.h`,
`ObjectStatusTypes.h` do the same); placed before `PreRTS.h` with `Lib/Basetype.h`,
`Common/STLTypedefs.h` and `Common/BitFlags.h`, it fails C2084 (`<new>` placement new/delete
defined twice).
Remaining / next check: the declaration must land between `BitFlags.h` and `KindOf.h` inside
`PreRTS.h`, i.e. a TU-scoped shim of the sweep `PreRTS.h` (or a shared decision for all three
units), then re-verify each unit's rowed callers still call 0x00666E80.
Clearance: pending.
Census confirmation: not claimed.

### LINK-031: `TransportContain.cpp` predicts a duplicate module-data ctor after its merge

Status: Open. Updated: 2026-10-26; inspected revision: a3e207d553 (index 47e030bafc).
Evidence / affected units: `link_check TransportContain.cpp` (with or without
`ContainModuleDeletingDtors.cpp`) reports "does not link", LINKED 1,921 -> 0 B:
`duplicate` + `selected` on `??0TransportContainModuleData@@QAE@XZ` (row 0x00468301).
The current tree has one real definition (TransportContain.cpp; the other textual hit,
ContainModuleDeletingDtors.cpp, is the `EmitVtableTag` overload). The merge d8f97282ee
(absorbed `TransportContainModuleDataCtor.cpp`) landed after the index commit, so the
index most likely still holds the deleted donor's object, which link_check cannot retract.
Identical result before and after 18cd9f0976 (KINDOFMASK_NONE rebinding), so that change
is not the cause.
Completed: diagnosis only.
Remaining / next check: rerun `link_check TransportContain.cpp` against the next census;
if the duplicate persists, find the second definer in the census objects.
Clearance: pending.
Census confirmation: not claimed.

### LINK-035: `StlSweepR3` vector-destructor units instantiated the whole `vector<RecordN>`
Status: Open (6 of 7 repaired). Updated: 2026-10-26; inspected revision: 018ace6021; index d1f046749a.
Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva<rva>.cpp` units holding one
63 B STLport `vector<RvaNRecord>` destructor (or `_M_clear`) row. Each wrote `template class
_STL::vector<RvaNRecord>;`, which emits every member: the record's ctor/copy/assign/dtor and `_Construct`
were unresolved, and its own `_Destroy<RvaNRecord *>` copy was not retail's body (the name is only pinned).
Retail's destructor calls an out-of-line two-argument range destroy.
Completed (each in its own commit, `./build.sh` exact, partners still link):
- 0x004F7D7F (61b147288f), 0x005F9813 (1a419a0c1d), 0x00577EB2 (02b625c1f2), 0x005E2857 (1f0a322ceb):
  callee 0x005F97BC, rowed `_Destroy<TreeHintRef00217D4C *>` (StlportVectorEraseRangeFamily.cpp).
- 0x0022DCDA (79e9273e2d): callee 0x0022D941, rowed `?Rva0022D941Destroy@@YAXPAURva0022CD2A@@0@Z`.
- Recipe: instantiate only `~vector`, as an explicit specialization whose body calls the rowed callee
  through `reinterpret_cast` (as `BattlePromptConstructorLifetimes.cpp` does), followed by
  `template _STL::vector<RvaNRecord>::~vector();` so cl 7.1 emits the otherwise unreferenced specialization.
  This also drops the three `#pragma optimize` lines per unit; `hatch_counters.py --update` has not
  been run to tighten the register. A forced-inline forwarding `_Destroy` specialization was tried
  first: it loads both bounds into registers before the EH state store, so the bytes differ.
- link_check: 0 -> 324 B over the five units.
- 0x00214B22 (c9700d27ca): retail 0x00214B09 is called with two pushed arguments by 0x00214B22 and
  0x004043AE (capstone over game.dat), so its row was respelled from 3-argument `__destroy_aux` to
  `??$_Destroy@PAVRva00214ADC@@@_STL@@YAXPAVRva00214ADC@@0@Z` (explicit instantiation in
  `stlport_vector_rva00214adc_destroy.cpp`, still exact; the one consumer spelling, the erase forwarder in
  `StlportVectorEraseRangeDeferred.cpp`, respelled with it). Then the recipe: link_check 0 -> 73 B; the
  provider, `StlportVectorEraseRangeDeferred.cpp` and the two 0x00214ADC units still link.
Remaining / next check:
- `StlSweepR3Rva000B0298.cpp` (`_M_clear`, 30 B, callee 0x000AFF52): 0x000AFF52 is likewise a
  two-argument `_Destroy` rowed as `__destroy_aux<Rva00111B25Record *>` (StlSweepW5Rva000AFF52.cpp), and
  respells the same way. But 0x000B0298 itself carries TWO matched rows: this unit's `_M_clear` and
  `?rva000B0298@Rva000B0298@@QAEXXZ` (`Code/GameEngine/Source/GameClient/Rva000B0298Clear.cpp`, a
  frameless twin over `EvaMessageInfo` calling `_Destroy<EvaMessageInfo *>`). The pin
  `?_M_clear@?$vector@UEvaMessageInfo@@...` at 0x000B0298 and the EH twin 0x000B0254
  `~vector<EvaMessageInfo>` suggest the real identity is `vector<EvaMessageInfo>::_M_clear`. Resolve
  the over-claim first (keep one row; retire the other through `deleted_rows.csv`), then link the
  survivor; do not just apply the recipe to the duplicate row.
- The `_Destroy<RvaNRecord *>` pins in `reverse/symbols.csv` for the six repaired units (incl.
  `_Destroy<Rva00214B22Record *>` at 0x00214B09) look unreferenced now; check every object before dropping them through the register's path.
Clearance: the five units preview LINKS against index 47e030bafc with current objects; 0x00214B22 previews
LINKS against index d1f046749a with current objects. Census confirmation: awaiting.


### LINK-036: StlportVectorEraseRangeDeferred historical blockers resolved by landed providers
Status: Cleared. Updated: 2026-10-26; inspected revision: 6fced2088a.
Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlportVectorEraseRangeDeferred.cpp`,
`reverse/link_status.csv` reported unresolved blockers from census `2026-10-25 13:53 at 51fde01dff`.
Completed: Verified unit against current objects; external callee dependencies have landed on master.
Remaining / next check: None.
Clearance: `tools/link_check.py Code/Libraries/Source/WWVegas/WWLib/StlportVectorEraseRangeDeferred.cpp`
reports: LINKS (0 -> 2,464 bytes). Full 59/59 matched rows verified.
Census confirmation: awaiting the next census.


### LINK-037: PartitionData_friendUpdateCellsTouched linked against stale ZH updateCellsTouched instead of native ShroudManager::Data provider
Status: Cleared. Updated: 2026-10-26; inspected revision: 7e7941d0cb.
Evidence / affected units: `Code/GameEngine/Source/GameLogic/Object/PartitionData_friendUpdateCellsTouched.cpp`,
`reverse/link_status.csv` reported wrong_selected 1 for `?updateCellsTouched@PartitionData@@AAEXXZ`.
Completed: In retail, tail call at 0x0073B250 jumps directly to 0x0073AD90 (`ShroudManager::Data::UpdateCellsTouched`).
Updated unit to call `((ShroudManager::Data *)this)->UpdateCellsTouched()` instead of unmatching legacy ZH method.
Remaining / next check: None.
Clearance: `tools/link_check.py Code/GameEngine/Source/GameLogic/Object/PartitionData_friendUpdateCellsTouched.cpp`
reports: LINKS (0 -> 37 bytes). Exact 1/1 byte match preserved.
Census confirmation: awaiting the next census.

### LINK-040: the 172-byte `CarryoverUnit` vector is spelled as five element types
Status: Open. Updated: 2026-10-26; inspected revision: 10621f1b34.
Evidence / affected units: `StlSweepW4Rva001EBEAB.cpp` (`vector<Rva001EBEABElement>::_M_fill_insert`,
0x001EBEAB, 307 B with funclets) fails on unresolved element ctor/dtor/`operator=` and a non-retail
`_M_insert_overflow<Rva001EBEABElement>`. Retail 0x001EBEAB calls (target facts): 0x001EB79E
`??0CarryoverUnit@@QAE@ABV0@@Z`, 0x0037DEE4 `??1CarryoverUnit@@UAE@XZ`, 0x001EB84E
`fill<BfmeAssignRecord172>`, 0x001EB831 `__copy_backward_ptrs<Rva001EB831Element>`, 0x001EBA30 and
0x001EBAB4 (`BfmePod172` helpers) and 0x001EBD3B `vector<BfmePod172>::_M_insert_overflow`. So one
native element (the virtual-dtor `CarryoverUnit`, 0xAC bytes) is rowed as `CarryoverUnit`,
`BfmeAssignRecord172` (incl. `operator=` 0x001EB20E, vector dtor/erase/reserve/clear),
`BfmePod172`, `Rva001EB831Element`, `Rva001EB86EElement` and `Rva001EBEABElement`.
`re_attempts.log` 0x001EC9BD already notes the BfmeAssignRecord172 / Rva001EBEABElement split.
Completed: none (no edit; diagnosis only).
Remaining / next check: one `vector<CarryoverUnit>` family rename across the rows above and their
units (about 20 rows, 12 files, incl. `LinearCampaignCarryoverInsert.cpp`, `Rva001EC9BDResize.cpp`,
`StlportVectorClearForwarders.cpp`), with a shared `CarryoverUnit` view; check each renamed body
still byte-matches and that the POD-named helpers really are the same instantiation, not ICF folds.
Clearance: pending.
Census confirmation: not claimed.

Sibling family, same cause (K10, 2026-10-26, inspected revision 7790bd44c7): the 52-byte
`BfmeAssignRecord52` vector. `StlSweepW4Rva002BC47D.cpp` (`vector<Rva002BC47DElement>::_M_fill_insert`
0x002BC47D plus `Rva002BC8C9Vector::resize`, 382 B) fails on unresolved `Rva002BC47DElement`
copy ctor/dtor/`operator=` and a non-retail `_M_insert_overflow<Rva002BC47DElement>`. Retail
0x002BC47D calls (target facts): 0x002B90D6 copy ctor (rowed `??0Rva002B91EDElement@@QAE@ABU0@@Z`,
pinned again as `??0Rva002BC47DElement@@QAE@ABU0@@Z`), 0x002BADB2 / 0x002BADD8 / 0x002BBC7A
(`uninitialized_copy` / `uninitialized_fill_n` / `_M_insert_overflow` over `Rva002BBC7ARecord`,
`VectorOverflowRva002BBC7A.cpp`), 0x002B913D / 0x002B915A (`__copy_backward_ptrs` / `fill` over
`BfmeAssignRecord52`) and 0x002B707E `??1BfmeAssignRecord52@@QAE@XZ`. One element is spelled
`BfmeAssignRecord52`, `Rva002BC47DElement`, `Rva002BBC7ARecord`, `Rva002B91EDElement` (and
`Rva002B91BBElement` op= ICF row). `tools/rename.py class --name Rva002BC47DElement --new
BfmeAssignRecord52 --dry-run` refuses: BfmeAssignRecord52 is itself a placeholder, so the family
needs a real element name (or a sanctioned merge path) first. No edit made.

### LINK-041: 23 units lost `TheSkirmishGameInfo` after their declarations were respelled `GameInfo *`

**Status: Repair landed, awaiting census. Updated: 2026-10-26; inspected revision: 35efd22768.**

- **Evidence / scope:** the census at d1f046749a (97.47 %, after 98.11 % at 47e030bafc)
  lost 33 units. 23 of them (71,793 B, led by `GameLogicInit.cpp` 28,160 B and
  `GameEngineInit.cpp` 9,424 B) have one unresolved name,
  `?TheSkirmishGameInfo@@3PAVGameInfo@@A`. 3a8ff9f8e0 respelled their declarations
  `extern GameInfo *TheSkirmishGameInfo;` to match the data ledger's provisional name for
  0x00A02EF0, but the only definition is `SkirmishGameInfo *TheSkirmishGameInfo` in
  `SkirmishGameOptionsMenu.cpp` (`?TheSkirmishGameInfo@@3PAVSkirmishGameInfo@@A`), the type
  Zero Hour's and BFME 1's `GameInfo.h` declare.
- **Completed:** 3a8ff9f8e0 reverted (`Recorder.cpp` by hand, since files were merged into it
  afterwards). `./build.sh` 728/728 rows across the 23 units; `tools/link_check.py` against
  the d1f046749a index: 23/23 link, 0 -> 71,793 B.
- **Remaining / next check:** the ledger row at 0x00A02EF0 is derived and provisional (it
  lists both spellings); regenerate it with `tools/data_ledger.py` so it names the defined
  `SkirmishGameInfo *` spelling, rather than respelling consumers to its current name. The
  census's other 10 lost units (3,997 B: `GameFont.cpp` 1,758 B, `statistics.cpp` 986 B, five
  `WW3D*` units, `CrateSystem.cpp`, `MultiplayerSettings.cpp`,
  `MultiplayerColorDefinitionCopy.cpp`, `GapBodiesGE41_Rva00118610.cpp`) have other causes
  and were not investigated here.
- **Census confirmation:** awaiting the next census.

### LINK-042: the census at d1f046749a's other 10 lost units (IsCapturing respelling and four TU merges)

**Status: Open (partial repair landed). Updated: 2026-10-26; inspected revision: e9bab0ff07.**

- **Evidence / scope:** the units besides LINK-041's 23 that linked in the census at
  47e030bafc (or were linked before their merge) and not at d1f046749a, 3,997 B in all.
  Blockers read with `tools/link_check.py --census-only`; causes traced to the commits below.
- **Completed:** 397acb4f2e moved `IsCapturing` under `public:` in five WW3D class views to
  match the ledger's unowned `?IsCapturing@WW3D@@2_NA`, but `ww3d.cpp` defines it private
  (`?IsCapturing@WW3D@@0_NA`). Reverted ("Revert 397acb4f2e"): `WW3DBeginRenderBFME2.cpp`,
  `WW3DStartMovieCapture.cpp`, `WW3DShutdownRenderDevice.cpp`, `WW3DStopMovieCapture.cpp`,
  `GapBodiesGE41_Rva00118610.cpp`; `./build.sh` 8/8, preview 0 -> 818 B.
- **Remaining** (all four came from `tools/tu_skeleton.py --merge`, which accepts a donor and
  chooses the `// cl:` line by matched rows only, not by whether the target still links):
  - `GameFont.cpp` (1,758 B), bdf96f6de4: absorbed `StlSweepR3Rva00218E09.cpp`, which never
    linked (3 unresolved `Rva00218E09Record` members, pinned non-retail `__median` /
    `__unguarded_partition` copies). Next: give the record its real type (the copy ctor is
    already bound to `MixFileCreator::FileInfoStruct`'s) so its members resolve.
    **Repaired 2026-10-26 (b5c5d490a1, agent K9):** the record now carries
    `FileInfoStruct`'s 16-byte layout (CRC, Offset, Size, `AsciiString` Filename) with an
    inline signed-CRC `operator<` (the compare the rowed partition 0x00217AB0 does). The
    implicit dtor and copy-assign are inline, so the three unresolved members disappear,
    and the emitted `__median` / `__unguarded_partition` copies are retail's.
    `./build.sh` 26/26; `tools/link_check.py` (d1f046749a index): `GameFont.cpp`
    0 -> 1,758 B; `MixFileCreatorFileInfoStructAssign.cpp`, `stlport_int_algorithm_bodies.cpp`
    stay linked. The copy ctor still binds through the file's existing `/alternatename`
    (renaming the record to `MixFileCreator::FileInfoStruct` would retire it; not done).
  - `statistics.cpp` (986 B), 01a7f0d9ba: absorbed `Rva001296F0Destroy.cpp`, which never
    linked (`extern "C" textureStatisticsString`, while the string is a file static in
    `DebugStatisticsRecordTextureEnd.cpp`; non-retail `??1Rva001880D0Dtor` copy).
    **Repair landed / awaiting census (2026-10-26, K5, 320523b560):** the body now forwards
    the ledger's `texture_statistics_string` (defined in this file, 0x009EE91C) to the
    0x001880D0 row `Rva001880D0StringCleanupForward::cleanup`; `./build.sh` 33/33,
    `link_check statistics.cpp wwstring_free_string.cpp dx8wrapper.cpp ww3d.cpp` predicts
    0 -> 986 B, partners unchanged (index d1f046749a). Census confirmation: awaiting.
  - `CrateSystem.cpp` (259 B), aab36803a7: the donors were `/O1 /G6 /D_STLP_NO_EXCEPTIONS`;
    under the TU's flags the emitted `list<Rva0035CBB2Element>::insert` (pinned 0x0035CB8D)
    is not retail's. Declaring it only leaves it unresolved (a pin does not satisfy the
    census), so the copy itself has to match.
    **Repaired 2026-10-26 (aa04b88683, agent K9):** 0x0035CB8D is the matched row
    `list<crateCreationEntry>::insert`, so the two absorbed rows (0x0035CBB2
    `_M_insert_dispatch`, 0x0035CC18 range `insert`) are `list<crateCreationEntry>` members.
    Instantiated over `crateCreationEntry` instead of `Rva0035CBB2Element`/`Rva0035CC18Element`,
    the TU emits retail's insert copy; the two `symbols.csv` pins that bound the placeholder
    callees were dropped. `./build.sh` 5/5; `tools/link_check.py` (d1f046749a index):
    `CrateSystem.cpp` 0 -> 259 B, `CrateCreationEntryListInsert.cpp` stays linked.
  - `MultiplayerSettings.cpp` (97 B) and `MultiplayerColorDefinitionCopy.cpp` (79 B),
    b93c4b507b: the merge dropped `/FIzh_ascii.h /DNDEBUG /DWIN32 /D_WINDOWS
    /D_STLP_USE_MALLOC /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE` (unresolved
    `AsciiString::freeBytes`, non-retail `~MultiplayerColorDefinition`), and the absorbed
    `pair` copy (0x00380DA3) now emits the implicit `MultiplayerColorDefinition` copy ctor,
    which clashes with `MultiplayerColorDefinitionCopy.cpp`'s. Restoring the flags fixes the
    first two blockers but fails the `pair` row (it inlines the copy ctor); tu_map already
    places 0x00380D30 in this TU, so merging `MultiplayerColorDefinitionCopy.cpp` here is
    the likely fix.
    **Repaired 2026-10-26 (c923d4c567, agent K9):** restored the dropped flags and replaced
    the ZH header include with a TU-local copy of its view whose `MultiplayerColorDefinition`
    declares (does not define) its copy ctor, so the `pair` row calls 0x00380D30 out of line
    and nothing re-emits it; no merge needed. `./build.sh` 2/2; `tools/link_check.py` on the
    d1f046749a index: `MultiplayerSettings.cpp` 0 -> 97 B, `MultiplayerColorDefinitionCopy.cpp`
    0 -> 79 B. Census confirmation pending.
- **Process note:** before applying a merge, `tools/link_check.py` the target TU and refuse
  the merge when a target that linked stops linking.
- **Guard (2026-10-26, 40bf8d4d7a, 1d3eaaf01f, 01e0e3a952):** `tu_skeleton.py --merge` now
  does this itself (`LinkGuard`). When the target or a donor links at the census, every
  candidate text is judged as one object against the census index (`link_check
  check_object` and `new_variants`, the absorbed units removed). A donor that would leave a
  linked unit not linking is rejected; a merge it cannot judge (no index, a linked unit
  missing from it, a link position it cannot model) is blocked. Dry run on real data:
  `W3DRopeDraw.cpp` refuses the never-linked `W3DRopeDrawCtor.cpp` (unresolved
  `__node_alloc::deallocate`, two losing COMDATs). Not covered: the split lane, merges in
  which no unit links, and changes to other units since the census.
- **Census confirmation:** awaiting the next census.


### LINK-043: StlSweepR3Rva00406B1D instantiated stable_sort instead of emitting scalar deleting destructor
Status: Cleared. Updated: 2026-10-26; inspected revision: b06312df51.
Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva00406B1D.cpp`,
`reverse/link_status.csv` reported 4 unresolved blockers (`??0Rva00406B1DRecord@@QAE@ABU0@@Z`, `??1Rva00406B1DRecord@@QAE@XZ`, `??4Rva00406B1DRecord@@QAEAAU0@ABU0@@Z`, `??MRva00406B1DRecord@@QBE_NABU0@@Z`).
Completed: Retail 0x00406B1D (28 B) is the scalar deleting destructor `??_GRva00406B1DRecord@@QAEPAXI@Z` calling ~Rva00215E42 at 0x004059AC. Replaced `stable_sort` template instantiation with direct delete anchor calling rowed dtor provider `??1Rva00215E42@@UAE@XZ` via `/alternatename`, resolving all 4 unresolved symbols.
Remaining / next check: None.
Clearance: `tools/link_check.py Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva00406B1D.cpp`
reports: LINKS (0 -> 28 bytes). Exact 1/1 byte match preserved.
Census confirmation: awaiting the next census.
Same cause, more units (2026-10-26, K5): nine more `StlSweepR3Rva<rva>.cpp` units that instantiated
`stable_sort` over a 1-byte record only to emit the 28 B non-virtual `??_G...Record` now use a plain
delete site (the `StlSweepR3Rva0046AA69.cpp` form), keeping each file's existing destructor
`/alternatename` and retiring its three `#pragma optimize` lines: 005CE7CE, 005E96DC, 00406CB7,
0044BE1D, 00482A4D, 0052BBD7, 00587752, 005DA663, 0042D4EB. 0042D4EB's binding also named a
placeholder since renamed (`??1Rva005794ED@@UAE@XZ` -> `??1EndTurnButtonImpl@StrategicHUD@@QAE@XZ`)
and now names the current symbol; that record is very likely `StrategicHUD::EndTurnButtonImpl` itself
(naming-lane follow-up, would drop the alternatename). Each 1/1 exact and `link_check` LINKS (0 -> 28 B).
Still open in this family, no hatch added: 00551B02, 005838DC and 005AFEDB have no destructor binding.
Retail calls rowed virtual destructors (`??1GameSpyBuddyMessageQueue@@UAE@XZ` 0x00551988,
`??1Rva005838B5@@UAE@XZ` 0x005838F8, `??1Rva005AFE3F@@UAE@XZ` 0x005AFE3F), so these rows are probably
those classes' virtual `??_G...@@UAEPAXI@Z` (same 28 B shape); next check: each class's vtable slot 0,
then rename the row and emit it from the class's own unit.

Same shape, still open (K10, 2026-10-26, inspected revision 7790bd44c7):
`StlSweepR3Rva0052BBD7.cpp` (row `??_GRva0052BBD7Record@@QAEPAXI@Z` 0x0052BBD7, 28 B) instantiates
`stable_sort` and fails on unresolved `Rva0052BBD7Record` copy ctor, `operator=` and `operator<`;
its dtor is already bound by an `/alternatename` to `?rva004E366E@Rva004E366E@@QAEXXZ` (0x004E366E,
"vector erase plus free clear", rowed as a plain method). Trial: replacing the instantiation with an
inline `delete p` helper emits no `??_G` (1/1 FAIL, symbol not found), reverted. The LINK-043 route
(non-inline anchor plus `/alternatename`) adds hatches, so it was not repeated. Hatch-free route:
name 0x004E366E as the real class's destructor (`??1<Class>`) and give the record that class, then
find what emits a non-virtual `??_G` without an invented anchor. Status for this unit: Open.

### LINK-044: NetPacket private views and remaining list-copy identity

**Status: Open. Updated: 2026-10-26.**

- **Evidence / scope:** the family-B Sol handoff
  [records the NetPacket prerequisite batch](../reverse/attempt_support/consolidation-sol-codexb-session-20261026-1415.md).
  Inherited argument/reference declarations and the new repeat-dispatch types
  and four wrapper casts preserve standalone code/data providers, relocations,
  COMDAT rules and references. The ordinary composition trial now accepts
  thirteen sources / 185 rows, with all 65 EH parents EXACT. This is bounded
  composition evidence, not a new link or census result.
- **Completed:** the inherited recovery raises the compatible subset from
  174 to 180 rows; new work raises it to 185. The one suppressed unrowed
  getCommand duplicate has an identical, earlier unchanged ConnectionManager
  provider; the composed object has no reference requiring that duplicate.
  No other provider loss or changed binding is accepted. No merge is applied.
- **Further completed:** the separately verified
  [progress-view prerequisite](../reverse/attempt_support/netpacket-progress-prerequisite-20261026.md)
  admits three more existing serializers (531 retail bytes). The ordinary
  trial grows from thirteen sources / 185 rows to sixteen / 188; eighteen
  standalone provider/context objects remain identical and all 65 composed
  EH parents are EXACT. No merge or measured linked-byte gain is claimed.
- **Remaining / next check:** two wrapper views disagree on fields; NetPacketO1
  duplicates BaseType coordinates; two helpers retain declaration/compile
  boundaries. The [Unicode-helper trial](../reverse/attempt_support/netpacket-unicode-view-prerequisite-20261026.md)
  preserves standalone bytes but still cannot compose: the longest view emits
  a 211-byte EH body instead of retail's 188-byte body under the carried flags.
  That trial is reverted; the sixteen-source subset remains verified. Five
  mixed donors remain untouched. Independently,
  ConstructBigCommandPacketList still has the existing shadow list-copy
  identity finding targeting 0x00594689. No identity key was retired. Leave
  the verified compatible subset for Luna and repair the remaining views in
  their own claimed prerequisites. Review the publisher's outgoing batch
  audit when the shared slot permits publication and carry census confirmation
  into the next normal measurement. Recovery dry-run at d76d8d4b8a passed
  218/218 rows and 69/69 EH checks; the batch audit is inconclusive because
  its index is at 763dc8759f (outgoing base df25e102ce) and the affected
  Eva.cpp object lacks a current receipt. The retained bounded COFF comparison
  does not resolve that full-index freshness gap; next census confirmation
  remains required. No selected-provider or linked-byte gain is claimed.
- **Clearance:** only the stated declaration/composition blockers are cleared
  in the ordinary trial. No downstream Luna landing is claimed.
- **Census confirmation:** pending; the batch does not change census history.

### LINK-045: S4SortElem20 element members exist only as private COMDATs under a placeholder name
Status: Open. Updated: 2026-10-26; inspected revision: 25f8ba858f (index d1f046749a).
Evidence / affected units: the 20-byte S4 sort element is rowed under two
placeholder class names: copy ctor `??0Rva003371B1@@QAE@ABV0@@Z` 0x003371B1
(Rva003371B1Copy.cpp), dtor `??1Rva003371B1@@QAE@XZ` 0x003372B7
(Rva003371B1Dtor.cpp), assignment `??0Rva002E9E70@@QAE@ABV0@@Z` 0x003372EC
(Rva002E9E70Copy.cpp, named as a copy ctor but called as the assignment by
swap 0x003373D9); its unguarded linear insert 0x00337424 is rowed as
`?Rva00337424Insert@@...` (Rva00337424Insert.cpp). The STLport sort units name
the element `S4SortElem20` and reach those bodies through symbols.csv pins,
which the link does not use: `??0`/`??1S4SortElem20` resolve only through the
implicit COMDAT copies in stlport_unguarded_insertion_sort_s4sortelem20.cpp
(census provenance `unknown`), whose bodies still call the undefined
placeholder `BfmeSortElem20Tail` ctor/dtor. That unit itself fails on those
two names and on `__unguarded_linear_insert<S4SortElem20 *...>` (kept copy is
S4StlSortHelpers.cpp's, not retail's).
Completed: 797d6cd0f5 linked stlport_introsort_loop_s4sortelem20.cpp (+90 B,
link_check vs d1f046749a; all 8 S4SortElem20 units checked, none drops): its
tail assignment now calls the rowed vector<Rva00332217Record>::operator=
(0x332217) and the element ctor/dtor are declared out of line.
Remaining / next check: one element type and name for 0x3371B1 / 0x3372B7 /
0x3372EC / 0x337424 (rename the Rva003371B1 / Rva002E9E70 rows, or respell
the S4SortElem20 users onto them) so one unit defines each member; then drop
the insertion-sort unit's implicit copies and recheck it with
S4StlSortHelpers.cpp, partition and introsort units together.
Clearance: pending.
Census confirmation: awaiting.

### LINK-046: unrowed lookup-table manager port blocks the matched accessor

Status: Cleared for the current-input unit preview. Updated: 2026-10-26;
inspected revision: 78413ee546.

- **Evidence / scope:** `Code/Libraries/Source/WWVegas/WWMath/lookuptable.cpp`,
  one 24-byte Peek_Head row at 0x00141120; [repair and consumer audit](../reverse/attempt_support/lookuptable-port-removal-20261026-codex5.md).
  The Zero Hour manager port emits two unresolved providers and two wrong
  COMDATs. Its additional functions and storage have no matched ledger owners
  or current Code consumers. This is removal of an existing unverified port,
  not new byte coverage or a source-path recovery.
- **Completed:** explicitly instantiate the matched header member and remove
  the port, nine present-unmatched markers and six optimization hatches.
  Build passes 1/1 exact; strict reusable receipt passes; link preview against
  index d1f046749a predicts 0 -> 24 bytes. WWMathInit.cpp passes 3/3 exact and
  retains its 388-byte link preview in the paired check.
- **Remaining / next check:** confirm the removed-provider scope and the unit
  in the next scheduled census. Thirty removed definitions have no alternate
  indexed provider, but no undefined consumer references were found in 23,766
  other cached build objects; historical object-store hits belong to older
  versions of this same source. The outgoing audit's older baseline and 183
  unrelated ledger-retired objects make its since-index findings provisional.
  No unrelated obstacle or whole-game closure is cleared.
- **Clearance:** the four local preview blockers are cleared with current
  source receipts; all matched coverage is preserved.
- **Census confirmation:** awaiting the next census; no headline gain claimed.

### LINK-047: `Credits.cpp`'s `list<CreditsLine *>::insert` copy inlines the bfmelist node creator

**Status: Repair landed / awaiting census. Updated: 2026-10-26; inspected revision: c01848c0b1.**

- **Evidence / scope:** `Credits.cpp` (3,053 B) did not link: its
  `list<CreditsLine *>::insert`, the only copy, is not retail's. Retail folds every
  four-byte-element `list<T *>::insert` into 0x005925E2 (37 B), which calls
  `_M_create_node` 0xB6447; `Credits.cpp` builds `insert` with the bfmelist shim's
  inlined node creator. Two earlier attempts (`reverse/re_attempts.log`, 0x005B78A4 and
  0x005B72A5) declared `insert` decl-only in `Credits.cpp`, which re-allocates registers
  in `addText`/`update`, since `push_back` inlines `insert` there. The census's
  `famgenDelete005B72E7` duplicate is a stale-index artifact: its donor,
  `FamilyDeletingDtors_muse-08-5B7352.cpp`, was merged into `Credits.cpp` by 800def3e22,
  after the census commit.
- **Completed:** `Credits.cpp` is unchanged. `stlport_list_int_insert.cpp`, link position
  1104 against `Credits.obj`'s 19770, instantiates `list<CreditsLine *>::insert` beside
  its `list<int>` owner row, with `_M_create_node` declared only so it calls
  `Credits.cpp`'s retail-proven copy, as the `SuperweaponInfo` twin units do. Its body
  is byte-identical to the `list<int>` row, and the existing pins place both names, so
  the first copy is proven retail and `Credits.cpp`'s copy no longer loses
  (retail-truth-3). Added as an ICF-twin row (`add_match.py --icf-owner`); `./build.sh`
  5/5. `tools/link_check.py` on a local `--update-index` index at c01848c0b1 (stale
  donor dropped): `Credits.cpp` 0 -> 3,053 B, `stlport_list_int_insert.cpp` keeps its
  62 B. Without the provider instantiation, the same index still reports the `insert`
  comdat and selected blockers.
- **Remaining / next check:** the `insert` pin's `fold-proof=` names `Credits.cpp`,
  whose copy no longer equals retail; `stlport_list_int_insert.cpp` now proves it. The
  pin was left as is (pin edits go through `tools/pin_admission.py`).
- **Clearance:** preview scope (the two units above) on a HEAD-updated index.
- **Census confirmation:** awaiting the next census.


### LINK-048: StlSweepW4Rva002F0B8A callees clear() and ~_Rb_tree_base() rowed under placeholder names
Status: Open. Updated: 2026-10-26; inspected revision: cc8e3e767b (index d1f046749a).
Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepW4Rva002F0B8A.cpp`,
retail 0x002F0B8A (43 B) is `_Rb_tree<int, pair<const int, Rva002F0B8AElement>...>::~_Rb_tree()`.
Completed: Eliminated non-retail COMDAT copies of `clear()` and `~_Rb_tree_base()`, unresolved `__imp_??R?$less@H@_STL@@QBE_NABH0@Z`, and wrong selected definitions by selectively instantiating `~_Rb_tree()` while explicitly specializing declarations for `clear()` and `~_Rb_tree_base() throw()`. Updated funclet pin object-symbol to current `$L4142`. Exact 3/3 byte match preserved.
Remaining / next check: The two callees `0x002EE9E0` and `0x002EEA09` are rowed under placeholder names `?rva002EE9E0@Rva002EB416@@QAEXXZ` and `?rva002EEA09@Rva002EB416@@QAEXXZ` in `Code/Libraries/Source/WWVegas/WWLib/Rva002EE9E0Reset.cpp` (and pinned in `symbols.csv`, which the plain link does not use). Resolving requires renaming the rowed providers to their template names or TU consolidation into retail `AIPathfind.cpp`.
Clearance: Wrong COMDATs and imports cleared; remaining blockers isolated to provider naming.
Census confirmation: awaiting next census.

### LINK-060: one address rowed twice; the non-linking copy is an over-claim
Status: Open (7 retired, leads below). Updated: 2026-10-26; inspected revision: e9bab0ff07; index d1f046749a.

### LINK-046: one address rowed twice; the non-linking copy is an over-claim
Status: Open (10 retired, leads below). Updated: 2026-10-26; inspected revision: b57c128806; index d1f046749a.
Evidence / affected units: a scan of `reverse/functions.csv` for `matched` rows sharing a `target_rva`
(notes without alias/ICF/fold/dup-of/object-symbol) against `reverse/link_status.csv` finds addresses
where one row's unit links and a second row's unit never did. The second row is usually an older
address-named view, a BFME 1 donor port or an StlSweepR3 sweep instantiation.
Completed (each `./build.sh` exact on the surviving owner, link_check LINKS for it, row recorded in
`reverse/deleted_rows.csv`, re_log `converted`):
- 0x00576DF1 `Rva00576DF1Ctor.cpp` (owner `Rva00576C4BDtor.cpp`, Impl ctor) 9caa4cbd11.
- 0x0006047C `Rva0006047CSeq.cpp` (owner `MilesAudioManager.cpp`) dd45d8c862; its two
  `g_Va00BBAB74/78` address globals are gone (`hatch_counters.py --update` not run).
- 0x004C121B `BfmeConv892_Rva004C121B.cpp` (owner `SymbioticStructuresBodySlots.cpp`) 93ba3a07a8;
  its `reverse/header_queue.tsv` GameLogic key now names a deleted source.
- 0x000AF1C2, 0x005243FA, 0x00569450 (2360ac3cf8) and 0x005AE78A (476ee27be8): StlSweepR3
  `uninitialized_fill_n` units (stable_sort over a 1-byte record, `#pragma optimize`); their
  `__uninitialized_fill_n` pins, named only by those units, were dropped.
- 0x00331578 `Rva00331578` copy in `ThingTemplate.cpp` (owner `RadiusDecalTemplateAssign.cpp`, typed
  layout agrees with rowed assign 0x00330CDD and ctor 0x00330E5D) b84b538a13; ThingTemplate.cpp 20/20.
- 0x00502645 `StlSweepR3Rva00502645.cpp` (owner `StlportIntMapInsertFamily.cpp`) eab974b6f3 and
  0x004F715B `StlSweepR3Rva004F715B.cpp` (owner `stlport_pop_heap_rva004f7e61.cpp`) 3e5be5935c; the
  pins only they named were dropped.
Remaining / next check:
- 0x0057621A `Rva0057621ACtor.cpp` (4 rows): owner `Rva00575F38Dtor.cpp` rows the Impl ctor and
  funclets $L1049..$L1055, but `__ehhandler` 0x0079B403 and funclets 0x0079B3ED/0x0079B3F8 are rowed
  only in the address-named unit; rehome them (tu_map has no approved unit for them) before retiring.
  Tried 2026-10-26 (reverted): the owner object emits `__ehhandler$??0Impl@...` (row exact at
  0x0079B403) and `$L1057` (exact at 0x0079B3F8), but `$L1056` at 0x0079B3ED jumps to
  `??1Rva005CD7DA@@QAE@XZ`, the owner's inline +0x30 record dtor, which has no row; retail jumps to the
  39B body at 0x005CD7DA. That body has three spellings (`?rva005CD7DA@Rva005CD7DA` in
  `Rva005CD7DAMethod.cpp`, gen-alias `??1Wrap2000576C4B` in `Rva00576C4BDtor.cpp`, pin
  `??1Rva005CD7BDHolder`); it is most likely `??1Rva005CD7BD` (ctor 0x005CD7BD sits just before).
  Naming decision first, then respell the users and rehome all three EH rows together.
- 0x0052BBD7 `StlSweepR3Rva0052BBD7.cpp`: owner `FamilyDeletingDtors11.cpp` (`??_GRva004E364F`) links;
  ready to retire like 0x004F715B, but the unit was locked by another agent this round.
- 0x00217607 `GameFont.cpp` `Rva004738A0::set` (BFME 1 donor, unused in the unit): the STLport pair
  ctor in `Rva005C6CCC.cpp` links; ready to retire, but GameFont.cpp was locked by another agent.
- Not over-claims (genuine ICF folds of distinct functions; add a fold note, do not retire):
  0x001F81BF (ten default vector-holder ctors), 0x00313840 and 0x003140A4 (7B getters).
- StlSweepR3 copies that now also link (LINK-035 repairs) duplicate placeholder rows:
  0x00577EB2 (`RvaVectorDtorFamily.cpp`), 0x0022DCDA (`Rva0022DCDADtor.cpp`); also unlinked
  0x000B0298, 0x001DE3E3, 0x001FDEBC. Decide which row keeps
  the address (the STL spelling may be the better name; respell callers) before dropping one.
- Multi-row units holding a second copy: DozerAIUpdate.cpp (0x00488C48, 0x0048AEC6, 0x00489DE3,
  0x00489E2E; DozerAIUpdate.cpp was edited on master in the last 6 hours, and tu_map approves it as
  0x00488C48's home), WOLBuddyOverlay.cpp (0x002B70B3), R5VectorDtorEHFramedPolymorphic.cpp (0x002D0F65), ProductionPrerequisiteAssign.cpp
  (0x00564CD4, 0x00565668, emitted COMDATs; its real blockers are op= copies).
Clearance: the surviving owners link in preview (link_check against index d1f046749a); the retired
units held 0 census-linked bytes, so no headline change is claimed.
Census confirmation: not claimed.

### LINK-049: map<unsigned, WeaponTemplateSetHead> insert family rowed on an int-key placeholder and a private tree view
Status: Repair landed, awaiting census. Updated: 2026-10-26; inspected revision: a8fa0b2df4.
Evidence / affected units: `StlSweepW4Rva00464431.cpp` (0x00464431, 29 B) was rowed as
`map<int, Rva00464431Element>::insert` and failed on an unresolved element copy ctor and a
non-retail local `insert_unique` COMDAT. Target facts: its only caller 0x00464923 compares the key
with jae and memsets a 0x4C-byte value (already spelled `map<unsigned, WeaponTemplateSetHead>`
there and pinned in symbols.csv); 0x00464431 calls 0x00463E4D, whose chain 0x0046383F and
0x004637B7 was rowed as `Rva00463782::rva*` view members.
Completed: the four bodies are now the `_Rb_tree<unsigned, pair<const unsigned,
WeaponTemplateSetHead> >` members they are: `map::insert` and both `insert_unique`s from the
template, `_M_insert` as an explicit specialization keeping the rowed create provider; the caller
takes `map::insert` decl-only. Two dead pins retracted. A pointer-to-member cast in place of a direct
call changed MSVC's tail merging in the 294-byte hinted insert (300 B), so convert by renaming the
callee rather than casting to it.
Remaining / next check: 0x004634BA (`Rva004634BACreate`) and 0x00462D83 (`_Construct<Rva0046267A>`)
are still the placeholder spelling of this tree's `_M_create_node` and element construct.
Clearance: `tools/link_check.py` on the five units: LINKS (661 -> 690 bytes), 5/5 rows exact.
Census confirmation: awaiting the next census.

### LINK-050: SplineCameraParseINIBlock record is Rva004E32F2, whose vftable and FieldParse table are unrowed
Status: Open. Updated: 2026-10-26; inspected revision: c9c4584d48.
Evidence / affected units: `SplineCameraParseINIBlock.cpp` (0x004E3300, 130 B) declares a private
`Rva003BA660Record`, so its ctor, tree dtor, field table and append stay unresolved. Retail 0x004E3300
(target facts): ctor 0x004E32D5 `??0Rva004E32F2@@QAE@XZ`, `INI::initFromINI` 0x0002DE78 with the table
at RVA 0x00861FB8, append 0x00566D7B `?rva00566D7B@Rva00566D7B@@QAEXABVRva004E32F2@@@Z`, then the
inlined virtual dtor: vftable 0x00861F68 (slot 0 = `??_G` 0x004E37B3) and the tree dtor 0x002B80CE
(`~_Rb_tree<int, pair<const int, AsciiString> >`), while the ctor binds the map<int, BfmePod24> ctor 0x005011C1
by `/alternatename` (`Rva004E32D5Ctor.cpp`). The table holds three 16-byte FieldParse entries (strings
0x008618F8, 0x008618D0, 0x00861F6C; parsers 0x0002F0F7, 0x0002E850, 0x00503FD1 with userData 0x008E148C;
offsets 4, 8, 0) plus a null terminator.
Completed: none (diagnosis only).
Remaining / next check: row the table as data, give the record the Rva004E32F2 identity with one
tree type for ctor and dtor, and settle where `??_7Rva004E32F2@@6B@` and `??_G` are emitted
(`Rva004E32F2Dtor.cpp` carries an inline anchor for them) before the parse unit inlines that dtor.
Clearance: pending.
Census confirmation: not claimed.

### LINK-051: the 0x0052C823 vector copy and 0x0052CD03 vector dtor are Rva003A6F70's, rowed as BfmePod32's
Status: Open. Updated: 2026-10-26; inspected revision: c9c4584d48.
Evidence / affected units: `Rva0056616BCopyDeferred.cpp` (0x0052D555, wrong_selected 1) and
`stlport_pod_noexc_deferred_copies.cpp` (selected 4). Target facts: the copy ctor 0x0052C823 calls
0x0052C27E, which constructs through `_Construct<Rva003A6F70>` 0x0052BD04 (copy ctor 0x0052BB34);
the `BfmePod32` loop 0x00421D28 calls a different `_Construct` (0x00421D16, copy ctor 0x0042183F), so
the two are distinct element types, not an ICF fold. The dtor 0x0052CD03 calls `_Destroy<Rva003A6F70*>`
0x0052C3BF. Yet `vector<BfmePod32>`'s copy ctor is rowed at 0x0052C823, its dtor at 0x0052CD03, and
`__uninitialized_copy<const BfmePod32*>` is both rowed at 0x00421D28 and pinned at 0x0052C27E: the
census resolves the copy ctor's call to the row and judges the kept copy wrong.
Completed: an attempt (patch kept outside the tree) retyped 0x0052C823 to `vector<Rva003A6F70>` with
ICF-alias rows for its get_allocator 0x0021983A, alloc_proxy ctor 0x0014F3C4, `_Vector_base` ctor
0x0052BCAB and const `__uninitialized_copy` 0x0052C27E (provider 9/9 exact), and dropped the wrong
pin. Reverted, because the consumer's EH cleanup funclet `uw_0079729c` then needs
`~vector<Rva003A6F70>` at 0x0052CD03, and forwarding the copy through placement new adds two EH
states (340 B vs 333 B).
Remaining / next check: retype 0x0052CD03 (`Rva0056616BCopy.cpp`, an EH-framed 63 B dtor with its
funclets) together with 0x0052C823, then point `Rva0056616BCopyDeferred.cpp`'s `m_54` at
`vector<Rva003A6F70>`; re-check the BfmePod28 `selected` names in the same provider the same way.
Clearance: pending.
Census confirmation: not claimed.

### LINK-045: stlport_float_format keeps its own 279-byte narrow forward-iterator append

Status: Open. Updated: 2026-10-26; inspected revision: 9e70605d3f; census 2026-10-26 13:18 at d1f046749a.
Evidence / affected units: `??$append@PBD@...forward_iterator_tag...` has seven census copies. The first
in link order is `stlport_float_format.obj` (rows 0x15E80/0x160D0 put it at index 102), an unknown
279 B copy; retail's 254 B body (0x0001B3E0) comes later from `stlport_narrow_string_append.obj`
(index 322). That holds out `stlport_float_format.cpp` (2,619 B), `StlportNarrowAppendCStr.cpp`
(58 B), `urlBuilder.cpp` (868 B), `Rva001F9524Concat.cpp` (160 B),
`stlport_narrow_stringbuf_overflow_setbuf.cpp` and `stlport_narrow_ostringstream_dtor.cpp`. This
contradicts LINK-020's "already link" list for those units. The `PAD` twin is not a blocker
(`stlport_narrow_string.obj`, retail, is first).
Completed: the float_format decl-only lines from 2c405b7793/7fdf7a74b3 sat in the HP-UX
`#else` arm and never compiled; removed in 6ae74e4d53 (object COMDATs unchanged, 23/23 rows).
Tried and failed (re_log 0x0001B3E0 blocked): a live decl-only `append<const char*>` specialization
(either live spot, with `__declspec(noinline)`, with the `PAD` twin) and an explicit inline
`_M_append_dispatch<const char*>` specialization calling it all hit C1001 (P2 main.c 148) under
the region's -O2. The unit must emit `_M_append_dispatch<const char*>` (its 0x15E80 row), so the
decl-only pattern that works in units emitting no dispatch does not apply here.
Remaining / next check: retail 0x1B3E0 lies inside float_format's own run (0x1B010..0x1BBD0), so
retail's copy was float_format's. The fix is float_format emitting the retail-shaped body: approve
the TU for 0x1B3E0 (tu_map only proposes `_STL.cpp`), then move the 254 B row and its source shape
into that unit, or find the STLport 4.6 `append` shape that compiles to 254 B.
Clearance: none.
Census confirmation: n/a.

### LINK-045: STLport facet virtuals rowed under placeholder names (numpunct truename/falsename)

**Status: Open. Updated: 2026-10-26; inspected revision: d1f046749a.**

- **Evidence / scope:** `tools/vtable_slots.py _STL` names every STLport vftable by RTTI.
  Slots 4 and 5 of `numpunct<char>` (0x007BBB78) hold 0x00017A40 / 0x00017AA0 and of
  `numpunct<wchar_t>` (0x007BBB94) 0x00017B00 / 0x00017B30: `do_truename` / `do_falsename`.
  They are rowed as `?init@Rva00017A40StringInit@@...` (and siblings) in
  `stlport_narrow_string_range_ctors.cpp` and `Rva00017B00StringInit.cpp`, reading
  address-named 12-byte globals (0x009DEEF0..0x009DEF38, `g_Va00DDEF08` and the like in
  `Rva007AB8D0StringInits.cpp` / `Rva007B6880Thunks.cpp`). `stlport_numpunct_virtuals.cpp`
  (44 B, 4 rows) defines the real `do_truename` / `do_falsename`, unrowed, and does not link:
  its `_M_truename` / `_M_falsename` statics of both specializations are unresolved.
  Same slot test also shows `collate<char>` slot 2 (0x00017890) and `moneypunct` slots 3-6
  (0x00019D30, 0x00019D90) rowed as `Rva...StringInit` placeholders.
- **Completed:** the same shape for slot 0 of `basic_ios<wchar_t>` (0x007BBCFC):
  437bc30603 repointed 0x00013490 from `??_GRva00013490Element` to
  `??_G?$basic_ios@GV?$char_traits@G@_STL@@@_STL@@UAEPAXI@Z` in `stlport_wide_ios.cpp`
  (link_check 296 -> 326 B) and removed the never-linking split unit.
- **Remaining / next check:** give the six 12-byte strings their STLport names
  (`?_M_truename@?$numpunct@D@_STL@@1V?$basic_string@...@2@A` etc.) through
  `tools/name_globals.py` / the data lane, then repoint the four slot rows to the real
  `do_truename` / `do_falsename` names and check `stlport_numpunct_virtuals.cpp` against
  them. Needs claims on both placeholder units and the data owners.
- **Census confirmation:** awaiting the next census for 437bc30603.

### LINK-063: `Scripts.cpp` needs `OrCondition`'s destructor, which is rowed under the placeholder `Rva003B262E`

**Status: Blocked on a name decision (`rename.py` refuses; no canonical evidence). Updated: 2026-10-26; inspected revision: 319adf8b41.**

- **Evidence / scope:** `Scripts.cpp` (512 B) has two blockers: unresolved
  `??1OrCondition@@MAE@XZ`, and an `??_7OrCondition@@6B@` copy that differs from
  `OrConditionCtor.cpp`'s, the first in link order. Retail's table 0x0081F3F4 has one
  slot, the 28-byte deleting dtor 0x003B331E, which calls the 68-byte dtor 0x003B262E.
  Both are matched in `Rva003B262EFinish.cpp` as `??_GRva003B262E@@MAEPAXI@Z` /
  `??1Rva003B262E@@MAE@XZ` (tier `address`/placeholder). The rowed `??0OrCondition`
  (0x003B238A) installs that table; the dtor body is Zero Hour's
  `OrCondition::~OrCondition` (`Scripts.cpp:1352`) without memory pools.
  `OrConditionCtor.cpp` spells the dtor public (`UAE`) and reaches the placeholder
  through `/alternatename:??1OrCondition@@UAE@XZ=??1Rva003B262E@@MAE@XZ`, a counted
  hatch. The three units' deleting-dtor bodies are already byte-identical (retail's
  28 B), and `??_E` is a weak alias of `??_G` in each.
- **Planned fix (not applied):** rename `Rva003B262E` to `OrCondition`; spell
  `OrConditionCtor.cpp`'s dtor protected and drop its alias. All three vtable copies
  would then name `??_EOrCondition@@MAEPAXI@Z`, and `Scripts.cpp` would resolve its dtor.
- **Why it is blocked:** `rename.py class` refuses any new name that already appears in
  the tree (`OrCondition already appears in ...`), whatever the basis, and so does
  the inferred lane's `apply`, which lands through it. A hand rename needs evidence
  that would pass as canonical. `canonical:zh` fails: a full `zh_sweep` (918 objects)
  places no ZH `??1OrCondition@@MAE@XZ` (130 B, pool-based) and the 30-byte ZH
  `??_G` has no needle. `canonical:bfme1` fails: `bfme1_sweep.py scan` has no placement
  for either body. The constructor-to-vtable link is a `vtable-slot` hint
  (`docs/naming.md`), and `??0OrCondition` is itself unverified in `name_tiers.csv`.
- **Remaining / next check:** a maintainer decision: either `rename.py` admits a
  rename into an existing class name when the old class is a placeholder whose rows
  are that class's own table entries, or a class-reconciliation commit adopts one
  `OrCondition` view and moves both rows. No source was changed.
- **Clearance:** none.
- **Census confirmation:** not claimed.
