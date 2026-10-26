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
- **Stale vector-clear identity key retired (2026-10-27 integration):**
  [the overflow caller check](../reverse/attempt_support/vector-overflow-identity-retirement-20261026.md)
  revalidates the unchanged caller at 0x0048D48F in its current
  FlammableUpdate.cpp owner. Normal builds pass all 89 rows in the five-source
  cohort, including the owner's ten rows, and 38 rows in three refreshed
  providers. The owning retirement tool removes the obsolete 0x000C060A
  overflow-to-clear key; the separate push_back finding remains registered.
  Historical preview was already clean (178 -> 178 bytes). No application
  identity, new C++ conversion or census-linked-byte gain is claimed.
- **Narrow-string constructor debt follow-up (2026-10-26, `d76f1e9874`):**
  [The current-input retirement](../reverse/attempt_support/narrow-string-ctor-identity-retirement-20261026-codexb4.md)
  confirms the allocator and fill constructors already call the allocation
  owner recovered by `7a90bdc5bd`. All six rows (343 bytes) and both EH graphs
  remain exact. After normal refresh of 73 missing objects and one stale
  provider, the owning identity tool retires both stale allocation-binding
  keys with zero remaining findings in these sources. Both units are already
  census-linked; this retires debt and claims no new linking gain. Other
  string-family prerequisites remain open.
- **Hashtable prime-table identity follow-up (2026-10-26):**
  [The current-object proof](../reverse/attempt_support/hashtable-prime-table-identity-20261026-codexb4.md)
  verifies STLport's complete 112-byte prime table at RVA 0x007BD410 from
  the existing stlport_hashtable_asciistring.cpp definition. Its matched data
  row resolves the resize copy's three previously unplaced data relocations;
  the owning identity tool retires one key with zero remaining findings in
  that source. Both hashtable sources and DamageFX_hashtableResize.cpp already
  preview LINKS and are census-linked, so no linked-byte gain is claimed.
  RvaHashIndex00928620.cpp retains its separate identity key: the edge-map
  insertion's resize and pair-construction bindings need owner/type evidence.
  The handoff records the exact native targets and preserves this prerequisite.
- **StructureTopple identity follow-up (2026-10-26):**
  [The current-provider verification](../reverse/attempt_support/structure-topple-identity-retirement-20261026-codexb4.md)
  confirms the constructor already calls the rowed range-erase owner at
  0x003FA4DB. All five rows (307 bytes) and its EH graph remain exact.
  After normal verification of 239 participating providers (4,420 function
  rows), the owning identity tool retires its one stale key with zero
  remaining findings. This source is already census-linked; no linked-byte
  gain is claimed. The earlier forwarding casts and its separate header
  prerequisite remain unchanged.
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

**Status: Open. Updated: 2026-10-26; inspected revision: 896af216804e1f1e34de28bd318285fbbbfcc536.**

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

**Assigned-unit recheck (2026-10-26, inspected `896af216804e`):** the local d1f046749a index and current objects still block `AerialPathfinder.cpp`, `Rva0052CD81Finish.cpp`, `ProductionPrerequisiteAssign.cpp` and `ProductionPrerequisiteRecVectorInsertOverflow.cpp`. No source change is retained in these four. The Aerial native-list bank remains the prerequisite; its missing base spelling and imported allocator are additional current findings. SaveMapPreview's count-base and non-const uninitialized-copy names have only wrong indexed copies, so declaration-only suppression has no proven replacement. The prerequisite assignment still conflates vector<int> with the 177-byte nontrivial-element assignment at 0x0021C21B; the record assignment and PrereqUnitRec construction/overflow also retain wrong selected copies from the RTS provider. Preserve the earlier failed exception-contract trials. Next: reconcile native element identities, exact helper callees and folded-name admissions across the provider family. Raw current results and native references are in `build/link-worker-20261026-w2/all-cohort-before.log`, `all-cohort-after.log`, `native-rows.log` and `dependencies2.log`; the full handoff is `build/link-report.md`. Clearance and census confirmation remain pending.

#### Opaque STL linking subset, 2026-10-26

Evidence / affected units: inspected `896af216804e1f1e34de28bd318285fbbbfcc536` against index `d1f046749a` (`retail-truth-4`). The [worker handoff](../build/link-report.md) and its raw `build/w4-link-20261026/evidence.log` record the retail calls, current row homes and emitted helper relocations. These are existing mismatched type/provider identities, not established missing native bodies.

| Unit under `Code/Libraries/Source/WWVegas/WWLib/` | Native provider facts | Remaining prerequisite |
| --- | --- | --- |
| `StlSweepR3Rva002BFA86.cpp` | Erase calls bucket index 00223149 (PlayerXferStringMaps.cpp) and node deletion 002BF75A (Rva002BF75AFree.cpp). The node provider uses `pair<const AsciiString, TreeHintRef002BF0D6>`; the bucket helper calls ASCII hash 00055041. | Reconcile the rowed erase type and the actual key/value providers. The record hasher and destructor are unresolved only inside the wrong emitted helpers. |
| `StlSweepW4Rva00054EBE.cpp` | Find calls 00053FD2, 75 B, rowed as `Rva00053FD2::find` in HashRefIdFind53FD2.cpp; native reads a reference id at +8. | Recover the reference-key/hash/equality identity before normalizing row names. The provider's existing function-pointer ABI union must not be copied into a consumer. |
| `StlSweepW4Rva000E0225.cpp` | Find calls 000E01B0, 68 B, rowed as `Rva000E01B0::rva000E01B0` in Rva000E01B0HashFind.cpp; native hashes two key words with XOR. | Recover the two-word key/equality identity and reconcile the rowed provider. An int-key instantiation is insufficient. |
| `StlSweepW4Rva001DF2D3.cpp` | Destructor 001DDEC3 belongs to `Rva00414BDBElement`; overflow 001DF21C belongs to `vector<Rva001DF3F1Element>`; the rowed fill 001DE8E9 calls `Rva001DE727::operator=` at 001DE727. | Reconcile the 48-byte record across copy, assignment, destruction, fill and overflow. The recorded /Ob0 forced-forwarder failure was not retried. |
| `StlSweepW4Rva002F0B8A.cpp` | The 43-byte destructor calls 002EE9E0 (41 B) and 002EEA09 (20 B), rowed as `Rva002EB416` members in Rva002EE9E0Reset.cpp. Native base cleanup null-checks the header and returns it to a free list. | Restore the actual allocator/type contract and provider names. The emitted generic-allocator base cleanup and outlined-accessor clear remain wrong. |
| `StlSweepW4Rva002F0BB5.cpp` | The 43-byte destructor calls 002EEA1D (41 B) and 002EEA46 (20 B), rowed as `Rva002EB46E` members in Rva002EEA1DReset.cpp. | Same allocator/type prerequisite, preserving this family's distinct free list. |
| `StlSweepW4Rva003609F7.cpp` | Insert calls resize 0053F1EC (184 B, Armor.cpp and proven folded owners) and node creation 00360939 (40 B, DamageFX_hashtableNewNode.cpp). Native allocates 0x788 bytes, while the placeholder helper allocates 0x0C. | Reconcile the insertion row and callers to the actual `NameKeyType` and `DamageFX` identity. Do not extend DamageFXHashSubscript.cpp's existing container/pair reinterpretation. |

Completed: the two tree units now instantiate only their rowed `_Rb_tree` destructor instead of the whole map. This removes the unrelated `__imp_less<int>` dependency and comparison adapters. Each unit passes all three existing rows, declaration, EH and shadow data checks; parent EH data verifies the renumbered funclet without a ledger edit. StlportMapForwardersSeat8.cpp and both reset providers remain LINKS in the paired preview. The other five units above were inspected and left unchanged; each still builds exact.

Remaining / next check: perform coherent type/allocator and row-name reconciliation with the listed provider homes. Replacing a real member call with an address placeholder, adding an alias/pin, changing the ledger, or casting a container to another instantiation was outside this worker's permitted repair scope. All native direct callees listed above already have matched owners. No new match or pin with independent fold proof was established. Clearance remains pending for all seven units; the bounded emission cleanup does not clear their required COMDATs. Census confirmation is pending.

- **Bounded identity audit (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` retains the unchanged failures for `Rva00056da2Finish.cpp`, `StlSweepR3Rva00058A86.cpp`, `StlSweepR3Rva000AF1C2.cpp` and `StlSweepR3Rva00218FC2.cpp`. Native callees are respectively `0x000558AD` (the copy auxiliary, not uninitialized construction), `0x00057FC1` (the rowed pair-key hashtable clear), `0x000ADF1B` (a range-copy forwarder) and `0x00218E09`/`0x0021889A` (the GameFont sort family). Their emitting template identities disagree with the existing row owners. No suppressed unresolved helper, type-punned container, row rename or pin is retained. Next check: reconcile each native algorithm and element identity with those owners before changing emission. Clearance and census confirmation remain pending.

**2026-10-26 assigned-vector follow-up, inspected `896af216804e`:** current objects retain the selected-wrong `vector<BfmePod28>::_M_fill_insert` in `stlport_pod_noexc_deferred_copies.cpp`, blocking `stlport_pod28_vector_resize_value.cpp`. Retail resize 0x005849F4 calls 0x00584405, already rowed under `vector<Rva00584405Element>`. That owner calls 0x00583A1E (`Rva002337F0::set`, 49 B), 0x0058431D (`Rva0058431D::rva0058431D`, 189 B), and the existing typed copy/fill rows at 0x00583A4F, 0x00583B11, 0x00583B37 and 0x00583B54. This is an element/member/signature identity prerequisite across existing rows, not a missing body. The owner itself remains U1/L1/S1; the resize remains S1 in the 40-unit current-provider preview. No source trial repeated the earlier exception-contract or /Ob0 forwarding failures. Next: reconcile the 28-byte record and these already rowed helpers in the naming lane, then recheck both consumers and the deferred provider. Evidence: `build/link-worker-w5/retail-probe-final.log`, `before-extra-providers.log`, `after-cohort.log` and `build/link-report.md`. No clearance or census confirmation claimed.

#### Assigned W4 and W5 vector sweep, 2026-10-26

Status: Blocked on element and row-name reconciliation. Inspected revision: `58598f540fd3c84610304b3659ed382a4c05acca`; ordinary-preview index `d1f046749a`, rules `retail-truth-4`. The current 91-unit provider/consumer comparison in `build/c136-w4sweep/before-with-providers.log`, `before-narrow-consumers.log` and `after-narrow-consumers.log` preserves every previously clean result and adds no named blocker. `build/link-report.md` maps all assigned units, native calls, existing row homes and gate receipts.

Evidence / affected units: the unchanged W4 fill-insert units `000C225D`, `001524F9`, `0017422D`, `00215949`, `003F53DA` and `005205DA` use element names different from the rowed constructors, destructors, assignment and overflow workers their retail calls reach. In particular, `003F53DA` calls the now-rowed `ArmySummary` copy at 0x0040E96D and destructor at 0x0040E499; its element is not established by the generic 104-byte helper labels. W5 `001506BF`, `0015079D` and `0015087B` reach the three distinct polymorphic copy constructors at 0x0014F480, 0x0014F4A1 and 0x0014F4C2 and their rowed overflow owners, rather than their local two-word copy bodies. W5 `0039C415` reaches `Rva0039B893` at 0x0039B893 and the rowed 0x0039C1C3 worker; its additional 0x00587DCD row remains subject to the existing 0x00587C40 exception-contract bank.

Completed: all listed units were checked with their current native provider objects, and all assigned rows pass the normal byte gate. No vector source edit is retained. The recorded `/Ob0` forwarder, overflow-suppression and 0x00587C40 exception-contract failures were not repeated. Remaining / next check: reconcile each native element and its existing row owners together through the naming lane, then recheck the whole family. Preserve the three distinct 0x0014F4xx classes. No missing native match, admissible new fold pin or shared-header-only repair was established. Clearance and census confirmation remain pending.

#### Assigned R3 container identities, 2026-10-26

Status: Blocked on coherent element and row-name reconciliation. Inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`; ordinary-preview index `d1f046749a`, rules `retail-truth-4`. The current-provider checks and native REL32 evidence are in `build/c136-r3sweep/before-expanded-cohort.log`, `after-expanded-cohort.log`, `native-evidence-03.log` and `native-rows.json`; [the worker handoff](../build/link-report.md) maps the full scope and gates.

| Unit under `Code/Libraries/Source/WWVegas/WWLib/` | Existing native providers and prerequisite |
| --- | --- |
| `StlContainerRva0073E4C0.cpp` | Push-back calls `_Construct` at 0x0060C9D9 (23 B, several existing two-word owners) and `_M_push_back_aux_v` at 0x0073E290 (123 B, `deque<Gen_t_008fb570_p8pod>` in Rva008FB570DequePushBackAux.cpp). The sweep's nontrivial record and template names disagree with those providers. Recover one supported payload identity; do not copy the provider's existing pair reinterpretation into this consumer. |
| `StlSweepR3Rva00212A16.cpp` | Insert calls resize 0x00212858 (199 B, Rva00212858Resize.cpp), bucketIndex 0x00223149 (31 B, PlayerXferStringMaps.cpp) and node creation 0x00212354 (37 B, Rva00212354NewNode.cpp). The latter allocates a 12-byte node for an AsciiString-keyed pair; the sweep uses two one-byte records. Reconcile the actual key/value and row signatures first. |
| `StlSweepR3Rva00332613.cpp` | Introsort calls median 0x00331716 (53 B, `__median<int>`), copy 0x00331962 (37 B, `BfmeStringRecord00331962`), partition 0x00331D10 (87 B, `S4SortElem12`/`S4Cmp002E1690`) and partial-sort 0x0033254D (27 B, Rva0033254DPartial.cpp). The median fold and record/comparator identities need coherent ownership; retaining the copy alias alone cannot supply the missing record operators. |
| `StlSweepR3Rva00337D21.cpp` | Introsort calls median 0x00335CFD (94 B, Rva00335CFMedian.cpp), copy 0x003371B1 (67 B), partition 0x00337655 (101 B, `S4SortElem20`/`S4Cmp002EB8E0`) and partial-sort 0x00337C55 (27 B, `Rva003371B1`/`Rva00337C55Less`). This confirms the existing blocked attempt: retyping the element still requires the folded median/partition ownership to be resolved. |
| `StlSweepR3Rva003F318C.cpp` | Assignment reaches existing LivingWorldRegionConnection-family owners at 0x003F2CD6 (45 B), 0x00565A24 (30 B), 0x003F325A (29 B), 0x003F0CA1 (24 B) and 0x003F29D2 (38 B). The opaque nonpolymorphic record view does not establish those providers' polymorphic element contract. Reconcile the complete record and helper family before suppressing its destroy copy. |
| `stlport_vector_rva00587375_overflow.cpp` | The owner still reaches Construct 0x00587410 (18 B, Rva00587410Copy.cpp), range copy 0x00587599 (38 B) and fill 0x00587422 (37 B). The current fill-insert provider is included in the paired preview; its selected overflow copy and the Construct contract remain blockers. The existing failed `throw()` and extern-template controls were not repeated. |

Completed: native call/row diagnosis and current-provider verification; these six sources are unchanged. Every direct native REL32 target inspected has an existing matched row. No new missing match, admissible fold pin or shared-header-only repair was established. Remaining / next check: reconcile each supported native element, its helpers and all row names through the naming lane, then repeat the paired preview. Whole-unit clearance and census confirmation remain pending; this is not a census gain.

**GUI-package element check (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `EvaMessageVectorAssign.cpp` remains U2/L2/S2 with current record providers against index `d1f046749a`. Native assignment 0x001020BA reaches the `BfmeStringRecord00111ACF` helpers at 0x00101F5C, 0x00101ECF and 0x00101F89, while its other row at 0x003F6BDB reaches the Eva copy constructor through 0x003F62C8. The emitted assignment still combines these distinct element identities. The unresolved Eva destructor pin also names the 60-byte `BfmeStringRecord00111ACF` destructor at 0x003F60C8. No source or pin trial was made; reconcile the row and element families before changing emission. All seven assigned rows pass the ordinary byte gate. Raw native calls, exact-name pin/owner lookup and current-provider previews are in `build/c136-gui-w2/native-all.log`, `dependencies.log` and `final-all-with-providers.log`; `build/link-report.md` maps the receipts. Clearance and census confirmation remain pending.

**Assigned common-container audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`, retail-truth-4):** no source trial is retained for the two `R5VectorDtorEHFramedPolymorphic` units, `Rva00196D90MemberConstructor_Rva0032bde7.cpp`, `ProductionPrerequisite.cpp`, `CrateCreationEntryList.cpp` or `SaveMapPreviewCopy.cpp`. Current native calls and row homes are recorded in `build/link-worker-w6/row-reference-witnesses.log` and `native-rows.log`; their current provider comparison is `paired-before.log` / `paired-after.log`. The Gen003AA0D0 prerequisite remains the already documented nonvirtual Rva005DE5B5 family. The Gen00141A00 assignment reaches the existing 92-byte-element providers at 0x002D0EDC, 0x002D0D5E and 0x002CFB90. The Dict-record constructor reaches the BfmeE16 base at 0x00421D73, BfmeThingUBB at 0x00329DC2 and the existing Rva0032AD58Fill at 0x0032AD58; its local bodies disagree with those contracts. Crate's sort reaches the 264-byte-family list base at 0x00288978 and Rva00288874Record merge at 0x00288874, while its actual crate node uses an eight-byte entry. These are family identity/allocator prerequisites, not missing functions established by the unresolved spellings. The SaveMapPreview allocator/base and placeholder Snapshot destructor remain blocked. Preserve the prior exception-contract trials; reconcile the existing row families before changing emission. No clearance or census confirmation is claimed for these units. See `build/link-report.md` for each unit's current result.

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

- **ControlBarScheme manager prerequisite (2026-10-26):**
  [Canonical manager adoption](../reverse/attempt_support/consolidation-controlbar-manager-prerequisite-20261026-codex4.md)
  preserves all 14 seed/lookup/setter rows and their code/data facts; all 37
  affected names retain selected provider and verdict. Ordinary dry-run newly
  accepts lookup, both setters and manager constructor, with 26 rows / 2,130
  bytes across 13 files. This is not a superset of the prior 21 rows / 3,678
  bytes: scheme init now needs TheWindowManager's declaration and manager dtor
  fails bytes. The accepted composition equals the fresh standalone external
  symbol/COMDAT union and all row data bindings, with LinkGuard acceptance.
  List/StringBase, drawing declarations, constructor adoption and parse-table
  boundaries remain. No merge, debt retirement or census gain is claimed.

- **GameEngine consolidation provider boundary (2026-10-26):**
  [The banked declaration trial](../reverse/attempt_support/consolidation-gameengine-declarations-prerequisite-20261026-codex4.md)
  removes a redundant TheNetwork macro and declares the existing frame-period
  helper, clearing the seed's composition compile error with all five bodies
  and object facts unchanged. The census-linked guard then refuses unresolved
  BfmeClientFramesPerSecond. Published/local index both remain d1f046749a;
  the existing data-ledger owner is LivingWorldEyeTower.cpp. No provider was
  edited and the source trial was reverted. Resolve that binding/index boundary
  before repeating composition; no donor acceptance or linking gain claimed.

- **PlayerTemplate tree receiver prerequisite (2026-10-26):**
  [Shared receiver evidence](../reverse/attempt_support/consolidation-player-tree-prerequisite-20261026-codex4.md)
  clears the assignment donor's conflicting tree declarations. Ordinary dry-run
  now accepts the seed and assignment (21 existing rows / 1,837 bytes), versus
  none before. All 22 standalone rows across three consumers still match;
  code/data, COMDAT policies and bindings are unchanged, and the accepted
  composition equals the standalone symbol union. Both tree destructors still
  fail composition bytes; store/vector declarations, STL redefinitions and
  mixed donors remain. No merge, census gain or debt retirement is claimed.
  A subsequent [name-key declaration trial](../reverse/attempt_support/consolidation-player-key-prerequisite-20261026-codex4.md)
  preserves all standalone object facts but still rejects the lookup donor
  with an empty compile diagnostic. Its declarations were reverted; accepted
  donors remain the same pair. Investigate that compiler boundary before
  repeating the lookup trial.

- **BridgeBehavior die GameLogic prerequisite (2026-10-26):**
  [Canonical header adoption](../reverse/attempt_support/consolidation-bridge-die-gamelogic-prerequisite-20261026-codex4.md)
  retires one header-queue row. The 79-byte die body, code/data fingerprints,
  COMDAT policies and all references remain identical; no bindings change.
  The ordinary merge trial still has independent carried-flag, composition,
  Coord3D/Region3D and mixed-source prerequisites. No new merge acceptance,
  file reduction, identity retirement, census gain or Luna landing is claimed.

**Constructor identity audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`, ordinary-preview index `d1f046749a`):** `RegionDetailsStructuresIconCtor.cpp`, `ParticleModuleTemplateClones.cpp`, `T1Base005F3750Ctor.cpp`, `BuddyThread_Unresolved.cpp` and `native_network_BFMENetwork_Ctor.cpp` retain existing provider-name and class-contract prerequisites. Native constructor table references and Icon's actual EH actions are recorded in `build/c136-common2/bindings.log` and `provider-details.log`; existing row names, sizes and homes are mapped in `build/link-report.md`. Icon's primary deleting destructor reaches the rowed `Rva005E278E` family, and its three base cleanups reach 004E84A4, 005E211F and 00238D97. Buddy's five missing virtual names also reach existing entries, including the separately named Peer queue folds; the network state constructor reaches the existing narrow-string constructor at 00007850. These are identity/ABI leads, not newly missing bodies. No real call was replaced by an address placeholder and no pin or alias was added. Adding only the existing BFME allocator include directory to Buddy's command line failed with C2950 at `reference/shims/bfmealloc/stl/_alloc.h:446` (explicit instantiation of the explicit `allocator<char>` specialization); the line was reversed and its 15 rows verify again. Raw trial and restored results: `buddy-after.log`, `buddy-build.log`, `buddy-restored.log` and `buddy-restored-build.log` in the same evidence directory. Reconcile the named owners and the allocator header's existing specialization/import contract before retrying; no clearance or census confirmation is claimed for these units.

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
- **Current component-header integration (2026-10-26, base `e1cdb1014f`):**
  The [fresh receipt](../reverse/attempt_support/icoord2d-component-header-20261026.md#current-master-integration)
  verifies 1,939 rows and 27 data rows across 255 header dependents, plus the
  planning-controls file's current 18 rows and two exact EH graphs. Both
  changed objects preserve every non-debug byte and relocation target. Four
  shadow cleanup-identity findings in ThrowingNewHelpers retain their old
  bindings; they are not introduced or retired by this header adoption.
- **ICoord2D constructor-header prerequisite (2026-10-26):**
  [the evidenced component-constructor mode](../reverse/attempt_support/icoord2d-component-header-20261026.md)
  lets ThrowingNewHelpers.cpp use the canonical header while retaining its
  call to the real 18-byte constructor at 0x0007E523. All 31 consumer rows and
  eight EH graphs remain exact; complete non-debug COFF facts are unchanged.
  The owning acceptance retires one header-queue row. The default aggregate
  view remains selected elsewhere. Constructor mode must precede the first
  header inclusion and lasts for the whole TU; that remains a composition
  prerequisite. The final dependent gate passes 1,927 functions and 25 data
  rows across 252 sources. The second whole-file adoption in
  StrategicInGameUIPlanningPhaseBuildingSelectionCtor.cpp preserves all 17
  rows and two exact EH graphs, retiring its own queue item. Its unchanged
  TemplateCountKey allocator COMDATs still have two divergent-definition
  diagnostics in the shadow identity check; no clean-link verdict is claimed.
  A [separate coordinate-record adoption](../reverse/attempt_support/icoord2d-record-header-20261026.md)
  moves prefix clearing into the record's own initialization and uses both
  canonical coordinate headers: all four rows, two EH graphs and complete
  non-debug object facts are preserved, retiring one more queue row.
  Its [separate native free declaration](../reverse/attempt_support/icoord2d-record-free-header-20261026.md)
  retires the same file's remaining Microsoft-header item: four rows and
  two EH graphs stay exact, and the three changed external references bind
  to the same game allocator through the owner's existing alternate name.
  The ordinary preview against 47e030bafc retains LINKS, 258 to 258 bytes;
  final linker directives and every non-debug section byte are unchanged.
  The [empty-constructor view](../reverse/attempt_support/icoord2d-default-header-20261026.md)
  records native 47A6A9/3 and lets ButtonFlashTransitionUpdate.cpp adopt the
  same header: 3/3 rows (2,278 bytes), all 13 non-debug sections and all
  93 relocations remain exact, retiring its header-queue item. Ordinary
  aggregate users keep their existing type; mode selection remains a
  first-include prerequisite. The final dependent gate passes 1,955 functions
  and 25 data rows across 255 sources. A separate boolean-literal cleanup
  preserves the whole button-transition object and retires its remaining
  Microsoft-header item (two local macros). Horizontal-slider adoption then
  retains both callbacks (1,559 bytes) and its complete object, retiring one
  further header item. Control-bar adoption retains all 50 rows, seven EXACT
  EH graphs and complete object facts, including static initialization guards
  and by-value coordinate calls, retiring its queue item. Its six unchanged
  static-guard data-name diagnostics remain in shadow. Vertical-button
  adoption preserves both drawing and the native constructor owner (649
  bytes), with complete object equivalence, and retires its queue item.
  The [external-constructor view](../reverse/attempt_support/icoord2d-external-header-20261026.md)
  then lets GameClientDrawableTOC.cpp retain native array construction while
  adopting the same header: all 92 rows, eleven EXACT EH graphs and complete
  object facts remain unchanged; owning acceptance retires its queue item.
  The icoord.cpp base/operator item initially remained open. Its subsequent
  [arithmetic-owner adoption](../reverse/attempt_support/icoord-math-headers-20261026.md)
  supplies the existing methods through opt-in canonical declarations and
  retires its ICoord2D queue item. All nineteen rows and the complete object
  remain exact: 25 non-debug sections, 633 bytes and ten relocations.
  Ordinary preview retains LINKS 491 -> 491. The completed dependent gate
  passes 2,128 functions and 25 data rows across 260 sources. The following
  ICoord3D adoption also preserves all nineteen rows and the complete object,
  retiring that file's remaining header item. Its existing emission anchors
  and census confirmation remain open.
  Its shared-header gate passes 2,107 functions and 25 data rows across 259
  sources. A separate SDK-header adoption preserves the whole GameClient
  object, all 92 rows and eleven EXACT EH graphs while retiring its two
  private Windows declarations through the owning Microsoft-header scanner.
  GameClient's separate SubsystemInterface item still needs its fourteen
  virtual slots reconciled with the canonical base. Existing shadow identity
  and TheMessageStream data-name diagnostics remain unchanged.
  Publication preparation on bf438b551c preserves all five new coordinate
  consumer objects' source inputs and the contract/header after rebase;
  the seven-commit batch retires five header and two Microsoft-header items.
  The synchronized upstream BFME 1 pointer de077dd5dd still requires the
  outgoing publication gate at these inputs; no new census is asserted.
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
- **Publication-audit follow-up (2026-10-26, `f8aefae21a`):**
  [The bounded current-provider audit](../reverse/attempt_support/ini-publication-current-provider-audit-20261026.md)
  identifies two actual declaration mismatches: five public IsCapturing
  consumers versus the private ww3d.cpp definition, and 23 GameInfo-pointer
  consumers versus the SkirmishGameInfo-pointer definition. The current data
  ledger must be reconciled with each real owner; no second symbol is a fix.
  Other provisional disappeared-provider findings still require current
  replacement objects or a new census and are not cleared by these examples.
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

**Assigned subsystem/module recheck (2026-10-26, inspected `896af216804e`):** `WeaponStore.cpp`, `GameWindowDtor.cpp`, `SlowDeathBehavior.cpp` and `LockWeaponCreate.cpp` retain their blockers in the paired 78-unit ordinary preview against d1f046749a. No source trial is retained in these units. WeaponStore still needs one native subsystem/table identity shared with the 225-byte `Rva002CCD56` destructor and its rowed deleting destructor at 0x002CD5E0; the current `unused` slot points at that deleting destructor. GameWindow still needs the full 11-slot native table reconciliation already documented above, rather than matching an incomplete copy. SlowDeath's unresolved disabled-mask and CRC references come from unrowed port/header emission; its wrong applicability and pool copies remain. LockWeaponCreate's current table spelling `xfer` occupies the native slot that reaches the 0x00497805 load-post-process wrapper, so a same-address rename would assert the wrong interface. Its native create-interface slot 1 reaches 0x004B8CC9, currently rowed as `BfmeThing940G::bfmeGo940G` (21 bytes), a candidate for naming after interface proof. Next: reconcile the native interfaces and provider names before changing consumers. Raw evidence: `build/link-worker-20261026-w2/vtable-targets.log`, `dependencies2.log` and the paired cohort logs; details in `build/link-report.md`. No clearance or census claim.

**Assigned logic-unit audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `build/link-report.md` records all 26 assigned units and a paired current-provider preview against `d1f046749a` (`retail-truth-4`). The existing AutoHeal UpgradeMux references pass masks by value while the rowed `attemptUpgrade` takes a const reference; INI scanInt/scanReal are rowed as instance methods, Object::setProducer takes a non-const Object pointer, ParticleSystemManager::createParticleSystem returns a handle, and DISABLEDMASK storage is BitFlags<11> rather than the ports' BitFlags<13>. These are shared-declaration/ABI prerequisites, not proof of absent native bodies. LivingWorldLogicCtorBfme also projects its unresolved observer slots onto existing rows at 0x002B64C7, 0x002BA82B, 0x002BA3F2 and 0x002B2A95; its update slot reaches the nonvirtual-spelled 0x002BD9B4 row, and reset reaches 0x002B2535. Reconcile the shared observer contract and provider names before changing that table. No source trial is retained in these families. `build/c136-logic/native-references.log`, `providers.log`, `final-cohort-before.log` and `final-cohort-after.log` preserve the bindings and remaining blockers. No new missing match or admissible fold pin was established. Clearance and census confirmation remain pending.

**Assigned W3D dependency audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** current paired previews retain blockers in `W3DModelDraw.cpp`, `W3DTankTruckDraw.cpp`, `HeightMap.cpp`, `dynamesh.cpp`, `ringobj.cpp`, `sphereobj.cpp`, `texproject.cpp`, `tcbspline.cpp` and `twiddler.cpp`. Their initial unresolved names do not occur as direct relocations in the inspected matched code rows; the unresolved references come from unrowed port bodies, retained inline-emission context or emitted tables. This does not prove missing native bodies. Several matched constructors or virtual inlines are emitted only through that context, so removing whole ports without checking row emission is insufficient. `blocker-providers.json`, `native-refs.log` and the before/final paired previews in `build/link-worker-w5-c136/` retain the exact provider scope and blockers. `tcbspline.cpp` additionally emits a non-retail `VectorClass<TCBClass>::Resize`: its pin target `0x000F0BF1` is the existing `VectorClass<Vector3>::Resize` row in `vector_class_vector3_resize.cpp`, whose evidence identifies memberwise Vector3 assignment and nonthrowing array deletion. A cross-instantiation cast is not a repair. Next check: reconcile the shared TCB element contract and preserve its five rows, then check all emitters together; the shared-header change is outside this seat. The other units require their actual emitting class/header or native provider contracts before suppressing the port copies. No shared header, pin, marker spelling or row was changed, and no clearance is claimed for these units.

**Assigned virtual-table audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** `Rva001F4B01Ctor.cpp`, `Rva005BA1FDCtor.cpp`, `Rva005F422CDtor.cpp` and `RvaPayloadValueReturnsUnresolved.cpp` remain unchanged and blocked. `build/link-worker-w6/vtable-witnesses.log` reads each matched constructor/destructor's native DIR32 table and maps its emitted slots to current rows. Particle's nested binders already have real ResolveBindings rows, but its primary selector at 0x001F4A90 is still rowed with the incompatible nonvirtual `QAEXPBDHH` signature; declaration-only table suppression would not repair that contract. The online constructors give the same BaseVirt name two distinct native targets, 0x005BA272 and 0x005BA303, and need the actual hierarchy and deleting-destructor owners. The icon family needs the already rowed ArmyHeroIcon/vtordisp identities, rather than its placeholder override spellings. All three payload clone tables use the existing deleting body at 0x005FAA31, rowed under Rva004E84A4; their constructor units still emit incompatible short tables. No new match or independently proven fold pin was established. Next check: reconcile those row signatures and complete class/table identities across every emitter. Clearance and census confirmation remain pending.

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

**Assigned texture provider boundary (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** removing the unrowed loading, creation and invalidation ports from `texture.cpp` can preserve all existing matched rows and make that unit preview LINKS. The corrected candidate retains the existing `TextureBaseClass::Peek_D3D_Base_Texture`, string emptiness helper emission through `Save_Texture`, the DX8 error wrapper emission through `TextureClass::Get_D3D_Surface_Level`, and the native recoloring body with exact EH. However, the paired current-object preview makes previously linking `dx8wrapper.cpp` unresolved on `??0TextureClass@@QAE@IIW4WW3DFormat@@W4MipCountType@@W4PoolType@TextureBaseClass@@_N3@Z` and `??0ZTextureClass@@QAE@IIW4WW3DZFormat@@W4MipCountType@@W4PoolType@TextureBaseClass@@@Z`. The entire texture trial was reversed and the restored unit reverified. Do not repeat this removal until those constructor providers and native consumers are reconciled together. Raw evidence: `build/link-worker-w5-c136/texture-before-cohort.log`, `texture-surface-build.log`, `texture-surface-cohort.log`, `texture-restored-preview.log` and `texture-restored-build.log`. An earlier overbroad scripted trial failed its byte gate and is also fully reversed; its clean-looking preview is not evidence. No texture clearance or census gain is claimed.

**Assigned imported-source audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** `RTS/Player.cpp`, `ThingFactory.cpp`, `ThingTemplate.cpp` and `System/CDManager.cpp` remain unchanged and blocked in the current provider cohort. Their raw unresolved names and selected copies are in `build/link-worker-w6/paired-after.log`; `row-reference-witnesses.log` separates relocations in matched bodies from dependencies emitted only by unrowed donor bodies. ThingFactory's row at 0x0042816E reaches two narrow-string assignments at 0x000120C0, as the existing LINK-020 diagnosis records, not its declared prerequisite vectors. CDManager's destroyAllDrives pin reaches 0x003E3C66, already rowed as ScriptConditions::reset; replacing that real member call with a placeholder would conceal the owner problem. The Player and ThingTemplate units also retain imported STL references and incompatible canonical-provider copies. Next check: reconcile these existing owners and shared views while retaining the inline accessor rows and their consumers. No new native match or admissible fold pin is established by these donor-only references. Clearance and census confirmation remain pending.

### LINK-006: compiler emission and the selected copy still disagree with retail

**Status: Open. Updated: 2026-10-25.**

**DefaultDraw table follow-up (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `T1Base005F3750Ctor.cpp` still disagrees with the first `DefaultDrawModuleInfo` table in `FXParticleSystem.cpp`. The native table at RVA 0081BAC0 has four slots (003A7ABD, 000B3FD0, 003A6127 and 00306A9B); the current first emitter has three slots, and T1's four-slot copy puts its name getter in slot 1 instead of slot 2. `build/c136-common2/provider-details.log` records the raw retail words and both COFF relocation lists. Matching the first emitter's shorter table would retain a non-retail contract, so no such trial was made. Next: reconcile the actual Snapshot interface and all emitting views, retaining every row, then recheck the family. The T1 destructor identity prerequisite remains separate under LINK-004. Clearance and census confirmation remain pending.

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

- **Near-linking constructor scope (2026-10-26, inspected `896af216804e1f1e34de28bd318285fbbbfcc536`; index `d1f046749a`, retail-truth-4):** `BfmeConv881O1.cpp`, `RTS/PlayerRelationMapCtor.cpp`, `RTS/PlayerCtorBFME2.cpp`, `Rva00415704Ctor.cpp` and `StlSweepW4Rva001FEAB2.cpp` no longer replace three empty allocator/vector bodies with declaration-only specializations. The visible STLport bodies restore the native 64-byte hashtable-constructor shape instead of the former 77-byte shape. Removing only the allocator destructor declaration left 65 bytes; also revealing the vector constructor still left 65 bytes while its base stayed declaration-only. The complete change clears the corresponding ordinary-preview COMDAT/selected blockers. The sibling `StlSweepW4Rva001FEAB2.cpp` must change with PlayerCtor so their no-address copies agree; its 31-byte row remains exact and it still links. Raw paired previews, disassemblies, all six edited sources' byte/frozen/EH/data gates and the combined 149/149-row check are in `build/link-worker-w1/`; `build/link-report.md` maps each receipt. `comdat_verdicts.py` calls the resulting 64-byte copies `unknown`, so this is a cleared ordinary-preview blocker scope, not a full retail-body or census claim. Whole-unit blockers remain: two opaque XferSave element destructors, the PlayerRelationMap vtable, the 0x00415704 subsystem destructor, and PlayerCtor's existing UnitRevivalTracker/energy virtuals. Next check: reconcile those actual types and tables without restoring the three stale specializations. Census confirmation pending.

**Assigned split-name/provider recheck (2026-10-26, inspected `896af216804e`):** `Rva006C3CC0Cluster.cpp`, `Rva006DE1A0Finish.cpp`, `Rva006F84C0DeletingDtor.cpp`, `AptPlayerTooltipMap.cpp`, `GameWindowManager_registerTabList.cpp` and `StateMachineDefineState.cpp` remain blocked against d1f046749a with current providers. No source change is retained. The allocator destructor calls the five-byte 0x00034D00 thunk, whereas its declared GeneralAllocator destructor pin targets the 309-byte 0x00033D50 owner; the real destructor/thunk identities need reconciliation without replacing a real destructor call by a placeholder. The pooled deleting destructor reaches the existing 37-byte `Rva006F8460` destructor, but its local complete-destructor definition is wrong; a folded-name/provider decision is required. The Apt value constructor retains the prior 15-slot hierarchy and split-class naming prerequisite; AptPlayer also needs its actual heterogeneous member types, the 68-byte `DetailedArchivedDirectoryInfo` destructor at 0x00224252 instead of `Rva00224C95`, and a complete table contract. The registerTabList call targets 0x002C54EE while the current list<GameWindow*> assignment row names 0x0046F0C2; State's eight-byte map still shares a falsely identified 16-byte-value `_M_insert` row at 0x0053479F. These are naming/ownership prerequisites, not missing bodies proven by an unresolved spelling. Preserve the earlier failed trials. Next: resolve each native identity before suppressing a copy or requesting a fold pin. Raw evidence and exact row homes: `build/link-worker-20261026-w2/dependencies2.log`, `native-rows.log`, `provider-paths.log` and `build/link-report.md`. No clearance or census claim.

- **Current-input string audit (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` records fresh checks of both `Rva008312E0StringReplace.cpp` and `Rva008314E0StringReplace.cpp`, their BfmeConv providers, and all seven narrow forward-append emitters. The two replace units retain their four erase/replaceBase findings each; the documented frame and naming prerequisites are unchanged and were not retried. The append owner still emits its retail 254-byte body, while the first copy in `stlport_float_format.cpp` is an unproven 279-byte body; `urlBuilder.cpp` and `Rva001F9524Concat.cpp` remain blocked even when all seven current objects are supplied together. The recorded declaration and extern-template ICE trials were not repeated. Next check: establish an admissible retail copy or declaration strategy in the early emitter while preserving its rows, then recheck the entire seven-unit family. No string clearance or census gain is claimed.

**Waypoint-tree binding check (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `MapMetaDataCopyDeferred.cpp` remains L3/S3 against `d1f046749a` with the current `stlport_rb_tree_hint_00301883.cpp` provider. The emitted 165-byte tree copy constructor at 0x003025A5, 115-byte `_M_copy` at 0x00301F9B and 30-byte clone at 0x00301BBF have zero non-relocation byte differences. Their binding failures are concrete: the Coord3D clone pin names 0x00413E55 (also considered as 0x00013E55), whereas `_M_copy` calls 0x00301BBF; the node-creation pin names 0x0016D760, whereas the clone calls 0x003012CE; the header-base constructor pin names 0x0016D590, whereas the copy constructor calls 0x0030087C. The native clone and create operations already have the opaque-payload owners above. No pin, real type, row or shared header changed. Reconcile the typed owners and existing pins together; suppressing the only Coord3D-name definitions leaves no same-name provider. Raw byte/relocation diagnostics: `build/c136-gui-w2/map-native-targets.log`; all 21 assigned rows pass `final-assigned-build.log`. Clearance and census confirmation remain pending.

**Assigned record-family audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`, index `d1f046749a`):** no source edit is retained in EvacuateDamageCtorModuleFactoryBody.cpp or ObjectCreationList.cpp. The Evacuate constructor's native EH cleanup reaches the existing 25-byte `Rva004B96CC` destructor, but two other rowed lifetimes in that source call the nocase-string tree destructor at 0x0002CC38 and the hashtable destructor at 0x0002CCC3. A declaration-only suppression would have no exact-name provider and would conceal those incompatible type identities. ObjectCreationList's rowed Payload vector construction reaches the existing 0x004F6A52 assignment worker, while destruction reaches the existing 0x005F85C8 stride-eight range worker. These are naming/type reconciliation prerequisites; no container reinterpretation, new pin or row change was attempted. Raw native references, exact owner names and the paired provider preview are in `build/c136-logic/`; all assigned sources pass the combined 118-row byte gate. The families remain blocked; no census clearance is claimed.

**Assigned W3D unmatched-emission cleanup (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`, retail-truth-4):** `W3DRadar.cpp` drops eight unrowed donor methods and their private stealth helper, retaining every existing matched definition, the surface-value helper and the existing private-convention caller. No new body, pin, declaration spelling, shared header or ledger change is used. Radar is cleared in ordinary-preview scope; census confirmation pending. Raw baseline, paired current-object previews, matched-row checks, provider-removal audit and final gates are mapped by `build/link-report.md` under `build/link-worker-w5-c136/`. The retained Radar cleanup label is verified through its parent's exact EH graph after compiler renumbering. A separate w3d_dep scanner-removal trial was fully reversed after the wider current-provider check found a linking string-list consumer losing seven helpers (LINK-020); its smaller-scope LINKS result is not retained repair credit. The broader entry remains open; verify Radar in the next normal maintainer census.

**Assigned constructor/lifetime audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** current paired providers preserve the earlier PlayerCtorBFME2 hashtable repair. The unit still lacks its declared virtual UnitRevivalTracker destructor and three Rva002B0F3CEnergy virtuals. The existing UnitRevivalTrackerCtorBFME2 view has a single xfer slot and a nonvirtual vector lifetime; the constructor's energy table instead reaches the existing Energy::xfer at 0x004DF290, name getter at 0x002AA3AF and empty slot at 0x000B3FD0. Correcting those declarations requires the complete lifetime/table contract, not a new destructor match inferred from the unresolved name. `Rva006CBF40Deferred.cpp` retains its seven nonretail complete-destructor emitters: the native deleting rows reach 0x006D1090, 0x006D6340, 0x006D63C0, 0x006E96D0, 0x006EB6A0 and 0x006FE460 under other existing owners. Neither source was edited. Raw evidence: `build/link-worker-w6/row-reference-witnesses.log`, `vtable-witnesses.log` and `paired-after.log`. Next check: reconcile the actual bases/member lifetimes with those row owners; no new fold pin has been proven. Clearance and census confirmation remain pending for these units.

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
- **Quantizer endpoint layout cleared in the fixed comparison (2026-10-26,
  source base `0044debbb5`):** the
  [native layout proof](../reverse/attempt_support/vp6-quantizer-layout-link-20261026/readme.md)
  puts the existing 256-byte scan table directly after the correction array,
  preserving the biased correction+260 end comparison at BD8464. The final
  order keeps the scan table at its previous section offset 272 and its own
  biased end at 532, with unchanged contribution size and alignment. Normal
  controls pass the complete 945-byte parent, all 16 initializers and all 26
  native data references; the expanded two-body control also preserves the
  unchanged 185-byte quantize.cpp caller. The authoritative comparison
  `f012cbcc5e` to `d8d65b08cc` gains **1,538 placed closed-strict bytes** in
  VP6_init_quantizer (945), VP6_UpdateQC (93) and VP6_quantize_c (500), with
  zero losses. Exactly one of 23,460 canonical objects changes. Independent
  reconstruction reproduces all 98,202 rows and the 1,705,216-byte credit;
  25 roots are additionally re-proved. The process exits zero after 3,626
  seconds with no final drift or new unresolved references. The unchanged
  quantize.cpp caller loses its old backward-map failure but still has the
  forward-map failure on scan+260 toward the separate IdentityIndex owner;
  its actual witness is retained. No new name, pin, header or data value is
  introduced. This subset is cleared in the fixed comparison; whole-chain
  clearance and a current-master census remain pending (LINK-008/017).
- **LargeGroupAudio key-tree follow-up (2026-10-26, `e5c5a1787c`):**
  [the whole key-list repair](../reverse/attempt_support/largegroup-keylist-erase-link-20261026.md)
  preserves its 191-byte parent and verifies all 15 rows of the native erase
  provider. Calling that existing owner removes the nonretail COMDAT and
  wrong selected-copy blockers; current identity has four owner bindings and
  zero wrong bindings. Ordinary preview remains 0 -> 0 against `f995f30157`
  because `g_lgaKeyRecords` is unresolved. Its address has two separate
  four-byte definitions under other spellings, plus an initializer and cleanup
  that need one complete storage owner. Prove the extent and reconcile all
  consumers before clearing this additional storage subset; no census gain
  or register retirement is claimed.
- **Key-tree storage follow-up (2026-10-26, after `5611c263e4`):**
  [the six-source ownership repair](../reverse/attempt_support/largegroup-keylist-storage-link-20261026.md)
  replaces those split allocations with one verified twelve-byte backing store
  under the existing `g_lgaKeyRecords` identifier. The native initializer and
  cleanup use the same symbol as all readers. All 938 function rows, the 23
  existing data rows, the new data row and five EH graphs pass. The six-object
  ordinary preview is 5/6 clean, retaining 10,184 bytes and adding KeyList's
  191 authored bytes; AddKey retains an unrelated unresolved vector resize.
  The owning tool retires two data keys, and the hatch tool retires five
  address-global occurrences. Thunk retirement remains refused on other
  findings. This storage subset is cleared in the stated current-object
  scope; full convergence, strict closure and census confirmation are unclaimed.
- **Key insertion resize follow-up (2026-10-26, after `d453de7462`):**
  The same evidence records the direct native resize-owner call. AddKey's four
  rows (324 bytes), data row and two EH graphs remain exact; the final six-unit
  ordinary preview is 6/6 clean, 10,184 -> 10,689 authored bytes (505 gained).
  This clears the stated ordinary-preview cohort, not its strict or census
  status. Identity retirement still refuses a separate AsciiString-destructor
  binding in the static accessor; its existing identity key is retained.
- **Canonical string follow-up (2026-10-26, after `3a6521d528`):**
  AddKey now uses the registered BFME 2 string header. All four rows, its data
  row, two EH graphs and the six-unit ordinary preview are preserved. The
  owning tool removes its registered destructor-binding key and no longer
  finds the separate accessor-destructor issue. One insert-unique key at
  `0x003ED8B1` remains; no class-wide identity clearance is claimed.
- **Native insert follow-up (2026-10-26, after `97e5e68584`):**
  The same handoff proves the existing record-tree owner at `0x003ED8B1`
  and the caller's scalar offsets. AddKey now uses that specialization;
  its four rows, data row and two EH graphs remain exact. The owning tool
  retires its final identity key with zero remaining source findings. The
  six-unit ordinary preview remains 6/6 clean at 10,184 -> 10,689 bytes.
  No wider class identity, strict closure or census clearance is implied.
- **Stale streak-clear data keys (2026-10-26, `2edd747b85`):**
  [Whole-file verification](../reverse/attempt_support/streak-clear-data-retirement-20261026.md)
  confirms `Rva0012641FClear.cpp` already uses the two existing pointer globals
  since `0bb6eb81be`. Three wrapper/owner rows and both four-byte data rows
  pass; the owning tool retires two obsolete names with zero remaining source
  findings. The wrapper's ordinary preview remains 20 -> 20 bytes. This is
  stale debt retirement only, with no new binding or census gain. Upstream
  `462ffdd1f8` subsequently retired the same two keys; the rebase preserves its
  register and does not count this historical work again in the current PR.
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

- **Filter-root current-input audit (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` confirms `W3DShaderManagerScreenBWFilterInit.cpp` remains unresolved on `screenBWFilter` and `screenBWFilterDOT3`; native DIR32 operands select VA `0x00DB5B54` and `0x00DB5B5C`. `Rva000FDCD7Get.cpp` still selects VA `0x00DB5BD4` for `W3DFilters[9]`. The old 144-byte inferred interval beginning at `0x009B5B88` is not storage proof for that filter: the current data register owns only the four-byte swap counter at its start. No artificial storage or alias is introduced. Next check: independently bound and recover complete filter objects and their initialized vtables before registering their ownership. Clearance and census confirmation remain pending.

**Assigned table-data audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `Rva002D22CAInit.cpp` remains blocked by its seven existing address-named table declarations. The matched row's DIR32 references agree with `reverse/data_ledger.csv` at RVAs 0x009BC890, 0x009BC998, 0x009BC9C0, 0x009BCAC8, 0x009BCBAC, 0x009BCBC4 and 0x009BCBDC, but every ledger entry is unowned. `build/link-worker-w6/row-reference-witnesses.log` records the individual native references. No alternative existing global definer was found and no data definition or hatch was added. Next check: recover and admit those table owners through the data lane. Clearance and census confirmation remain pending.

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
- **Quantizer publication cohort (2026-10-26, first candidate `71b55f3f7a`):**
  [the retained normal-hook audit](../reverse/attempt_support/vp6-quantizer-layout-link-20261026/publication-audit.json)
  passes 39/39 bodies, 18 data rows, four exact EH graphs and converged-data
  enforcement across InitQuantizer.cpp, Eva.cpp, ThreadClassLifecycle.cpp and
  thread.cpp. The shadow batch comparison is inconclusive against index
  `d1f046749a`: its outgoing base was `ced3615d0f3`, and all four scoped
  objects lacked current strict receipts (first Eva). No selected-provider or
  current-master lost-byte verdict is claimed. Carry these exact four paths
  to the next normal census/current-index check. The independent immutable
  comparison proves the separate 1,538-byte gain with zero losses. The first
  push was rejected solely because master advanced; the existing commits are
  rebased and retried without repeating any match or full measurement.
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

- **Outgoing-batch audit follow-up (2026-10-26, published `0edae3a354`):**
  The new pre-push audit is [inconclusive for this batch](../reverse/attempt_support/material-collector-anchor-cleanup-20261026.md#publication-audit-qualification):
  its index `f995f30157` predates outgoing base `a5cb102c02`, and nine objects
  lack strict current receipts. Normal publication verification passes 47
  functions, one data row and nine EH graphs. Read-only witnesses for the
  material collector and the first reported upstream particle-update unit
  confirm ordinary cache validity but no strict include inventory. No selected
  provider or lost-byte verdict was reached. Carry the batch into the next
  census with current input proof and an appropriate comparison baseline;
  no regression, clearance, false reject or new linking gain is inferred.

- **INI publication follow-up (2026-10-26, published `7d17532afb`):**
  [The expanded batch audit](../reverse/attempt_support/ini-lookup-clean-throw-20261026.md#publication-audit-qualification)
  has strict reusable proofs for 135 explicitly prepared sources; the push
  hook verifies 1,375 functions, three data rows and 195 EXACT EH graphs over
  138 sources. Its only missing strict receipt is the additional Eva.cpp
  dependency. A focused supported preparation refuses unknown macro or
  parent-traversing include search roots. The index `763dc8759f` also predates
  outgoing base `0edae3a354`. No provider-change/lost-byte verdict, false reject
  or closure is inferred; complete include inventory and a suitable comparison
  baseline remain prerequisites.
  The subsequent `5994f7c59a` publication passes 85 functions and 12 EXACT EH
  graphs in three sources, but its audit reaches the same Eva.cpp prerequisite.
  The failed strict preparation is not relaunched without new include evidence.

- **Later bounded publication (`f8aefae21a`, 2026-10-26):**
  [All 54 changed objects have strict receipts](../reverse/attempt_support/ini-publication-current-provider-audit-20261026.md).
  The full normal gate passes 98,252 functions and 2,216 data rows, followed by
  116 EXACT EH graphs. This scope excludes Eva and does not clear its inventory
  prerequisite. The audit completes with 89 retired objects, 287 provisional
  disappeared-provider reports and 30 possible-loss lines against the older
  `763dc8759f` index. No aggregate loss, global clearance or census gain follows.

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
- **Completed (2026-10-26, agent b1):** a placeholder-to-placeholder pair needs no
  name decision. `Rva000647B5Ctor.cpp`'s ctor 0x000647B5 and the rowed dtor
  0x000647D4 store the same vptrs (0xBC5A5C/0xBC5A24; slot 0 is
  `??_GRva000647D4` 0x00064809), so the ctor class became `Rva000647D4` on
  `LocomotorDerivedDtors.cpp`'s view (two alternatenames dropped): link_check
  0 -> 25 B LINKS, factory 0x00042036 and the dtor unit still LINK. Two more
  pairs found, not applied: `WeaponStore` (ctor 0x002CC20E, table 0x00C02114,
  dtor `Rva002CCD56` 0x002CCD56; Weapon.cpp's present-unmatched `~WeaponStore`
  would also go; links 0 -> 47 B, patch kept outside the tree) needs the same
  placeholder-to-real admission as LINK-063; `Rva006DE1A0Finish.cpp` (table
  0x00CEB150 slot 14 is `??_GRva006DE2B0`) needs its four caller units and the
  `??3Rva006DE1A0` ICF pin moved. `T1Base_005F3750` is not a pair: its
  `??_G` 0x003AE8D5 is ICF-shared with a different class (table 0x00C1D55C).
- **Remaining / next check:** choose an admissible route. Preferred is an
  identity merge of the placeholder destructor class into the class the
  constructor/vtable prove, sharing one class view among every unit that emits
  the vtable; that is still blocked on `rename.py` support for a
  placeholder-to-real merge and on the class-view/COMDAT cases recorded in the
  handoff (GameLogic/SubsystemInterface slots, the ExperienceTrackerXfer vtable
  COMDAT, BaseHeightMapRenderObjClass and GlobalWeatherSystem split identities). Otherwise a maintainer decision is needed for
  a scoped admission path. Do not repeat the unchanged alias trial.
- **Clearance / census confirmation:** pending; no census change is claimed and
  the alias trial was not published.

**GlobalWeather current-owner audit (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `GlobalWeatherSystemCtorDeferred.cpp` still has four unresolved names. Native primary table RVA 0x0080C734 slot zero reaches deleting destructor 0x0031861B, which calls the complete 110-byte destructor at 0x00318637. Both, plus the secondary thunk at 0x00318613, now have rows in `Code/GameEngine/Source/Common/Rva00318637Dtor.cpp` under `Rva00318637`; this is an existing split identity, not a needed destructor match. The constructor's element callbacks reach the ten-byte `IPEnumeration` constructor at 0x00318329 and the counted-reference destructor at 0x0010F149. The native cleanup at 0x0077A838 destroys member +0x20 through 0x0048BA39 (the rowed AsciiString/StringBase cleanup). Preserve their distinct lifetimes and resolve the identities through the naming lane. No source change, alias trial or pin was made. Raw proof: `build/c136-logic/weather-native.log`, `weather-owners.log`, `native-references.log` and the full report. Clearance and census confirmation remain pending.

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

**InGameUI product table prerequisite (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** `Rva0008EF3FProductCtor_Unresolved.cpp` retains the undefined destructor and `InGameUI::slot11` through `slot59`. Native tables installed by its exact constructor are at VA `0x00BC7A88`, `0x00BC7A78` and `0x00BC7A64`. The primary table's slot 0 points to the rowed deleting destructor at RVA `0x0008F379`, named `Rva008F00D` in `Rva0008F00DDtor.cpp`; the secondary Snapshot table names the real InGameUI load/xfer methods and a separately named getter. The actual slot targets and current row homes are recorded in `build/link-worker-w5-c136/native-refs.log` and `native-target-owners.json`. These facts require a coherent class identity and table contract; declaring the non-pure slots pure would invent different tables. No class or member was renamed, no pin was added, and the unit remains blocked. Next check: reconcile the product, destructor and base interface views with all native slots before changing this constructor's declarations. Census confirmation is not claimed.

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
- **Approved-TU follow-up (2026-10-26, base `80732a72b7`):**
  [the INI consolidation](../reverse/attempt_support/ini-approved-consolidation-20261026.md)
  absorbs six whole donors and preserves 52 rows / 3,837 bytes in the TU.
  Two prerequisite commits remove one unused alias and one stale marker.
  The two-source comparison cohort retains eight EXACT EH graphs, zero wrong
  code bindings and zero data findings. Before composition, current ordinary
  preview against the newer `763dc8759f` index accepts all eight original files
  (3,894 authored bytes); this confirms inherited repairs, not a new gain.
  After composition, that preview retains six duplicate and four selected
  findings naming absorbed definitions. Post-merge closure is not claimed;
  twelve remaining whole donors need declaration/codegen reconciliation.
  The next [lookup-parser repair](../reverse/attempt_support/ini-lookup-clean-throw-20261026.md)
  replaces its artificial default exception/throw-info anchor with normal C++
  throws, preserving all 108 bytes and its clean 108-byte preview. A fresh
  approved composition at `468141e4c7` absorbs that donor unchanged: INI.cpp
  now verifies 53 rows / 3,945 bytes, with eight EXACT EH graphs and zero wrong
  bindings or data findings in the two-source cohort. Eleven donors remain
  blocked by declaration/view reconciliation. Ordinary preview now retains
  seven duplicate and five selected findings; the additional lookup owner is
  still the retired donor in the index. Post-merge closure remains unconfirmed.
  The transferred data catalogue retains its old unused throw-anchor spelling;
  this is a source-path transfer, not a new emitted anchor or ownership gain.
- **Publication proof (2026-10-26, `7d17532afb`):** the full normal gate passes
  all 98,252 function and 2,216 data rows. The bounded publication audit still
  stops on Eva.cpp's include-inventory prerequisite described in LINK-008;
  neither the seven-donor consolidation nor its stale-index diagnostics are
  upgraded to a full linking verdict.
- **Native integer-throw cleanup (2026-10-26, base `091dbc15da`):**
  [The byte parser](../reverse/attempt_support/ini-byte-parser-clean-throw-20261026.md)
  replaces its manual runtime call and zero-filled anchor with `throw ERROR_BUG`.
  All 62 body bytes, all 53 TU rows, the cohort's eight EH graphs and 178 code
  bindings remain verified. Retail and compiled exception metadata agree on
  a four-byte `int`. Ordinary preview retains the same seven duplicate/five
  selected old-index findings, with no new unresolved reference or linking
  gain claimed.
  A separate follow-up removes five duplicate macro/prototype occurrences;
  the owning Microsoft-header queue reduces INI's local count from 13 to eight,
  retaining its CRT conflict classification and all 53 matched rows.
  The next separate cleanup replaces TRUE/FALSE with C++ boolean literals and
  uses the existing standard NULL definition: eight local occurrences become
  five function declarations, with all 53 rows and seven TU EH graphs exact.
  The new full build against the maintainer's pinned BFME 1 `ff391a5e90`
  also passes all 98,252 function and 2,216 data rows; it does not resolve the
  strict batch-link inventory prerequisite or confirm a new census gain.
  A further verified declaration cleanup uses the already included `string.h`
  for `strlen`/`_strcmpi` and adds `stdio.h` for `sscanf`: five local prototypes
  become two (`_mbscpy`/`_mbscat`), retaining all 53 rows and seven EH graphs.
  [Standard multibyte declarations](../reverse/attempt_support/ini-multibyte-header-adoption-20261026.md)
  then replace the last two prototypes. Both readers' six native calls are
  verified against the named CRT import thunks; standard unsigned-character
  pointers and header-specific import configuration preserve all 53 rows,
  seven EH graphs and 168 code bindings. The owning scoped refresh removes
  INI.cpp's Microsoft-declaration queue item; the linking prerequisites remain.
- **Latest publication and rebase check (2026-10-26):**
  [The publication audit](../reverse/attempt_support/ini-publication-current-provider-audit-20261026.md)
  records full byte/data verification at `f8aefae21a` and the completed,
  explicitly provisional 54-object shadow audit. No INI.cpp-specific cause
  was found in its reported possible losses; this does not establish full
  linking closure. After rebasing onto `b85e569cee`, INI.cpp is unchanged from
  the published source and the nine-source reconciliation cohort passes
  1,014 functions, 24 data rows and twelve EXACT EH graphs.
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

- **OCL current-input audit (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` preserves the three unchanged OCL findings with current providers. The protected destructor and nonstatic `findPositionAround` references originate in the unmatched donor methods; the matched 42-byte constructor remains exact. The recovered finder at `0x00285202` is the static cdecl spelling in `TerrainLogicFindPositionAround.cpp`, and `SpecialPowerModuleDtor_Unresolved.cpp` supplies the public destructor. Adopting those contracts and the native `FindPositionOptions` layout requires reconciling the shared declarations; this seat changes no shared header or unmatched marker decoration. Next check: repair that header family and its consumers together. OCL clearance and census confirmation remain pending.

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

**Destructor specialization trial (2026-10-26, inspected `896af216804e`):** a TU-local `dllimport` plus `forceinline` specialization of the existing Vector3 destructor, retaining the header's qualified `Clear()` operation, does not suppress the losing deleting destructor and changes both `rva007B7280` and `rva007B7400`. The byte gate fails 2/6; the trial is fully reversed. The restored source passes 6/6 and retains its original single blocker with the current owner and sibling objects. Raw outputs: `build/link-worker-20261026-w2/vector-inline-preview.log`, `vector-inline-build.log`, `vector-restored-preview.log` and `vector-restored-build.log`. Do not repeat this specialization. The native table ownership or approved TU consolidation prerequisite above remains; census confirmation is pending.

- **Teardown and table audit (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` records two reverted `Rva007B73C0.cpp` trials. An extern-template destructor replaces the 59-byte teardown with an unresolved destructor jump; an inline-only imported specialization also changes the teardown and leaves the losing deleting destructor. Final byte verification restores the original 59-byte body and the original single COMDAT finding. The proposed vtable-ownership route has an additional prerequisite: the six native table slots at `0x007CEFAC` point to RVAs `0x000F1CF7`, `0x000F1C16`, `0x000F0BF1`, `0x000F0CD4`, `0x000F0DC5`, `0x000F0E20`. The current Vector3 table instead names its pointer-ID owner at `0x001298B0`, while native slot 5 is the 27-byte TCB-class pointer-ID row at `0x000F0E20`. A data row cannot simply assert that these bindings agree. Next check: reconcile the native class/fold identities and every table slot before admitting a full table owner. The constructor and resize providers still preview LINKS; the two teardown units remain blocked. Census confirmation remains pending.

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
- **Audio overlap reconciled (2026-10-26, base `e12e2545d9`):** the table above
  records the earlier independent repair. The retained audio implementation
  uses the verified 12-byte array owner in KeyList; sixteen native zero bytes
  did not establish a 16-byte tree layout. AddKey's native resize and insert
  calls are already repaired, as recorded in
  [the storage follow-up](../reverse/attempt_support/largegroup-keylist-storage-link-20261026.md).
  [Removing the now-unused pair-tree erase instantiation](../reverse/attempt_support/largegroup-unused-erase-provider-20261026.md)
  prevents its divergent pair destructor from overriding AddKey's cleanup.
  All 20 affected function rows, two data rows and two EH graphs pass; current
  consumer objects contain no reference to that alternative erase. The bounded
  seven-object preview restores AddKey's 314 bytes and passes 7/7 at
  10,874 -> 11,379 against index `763dc8759f`. No new census gain is claimed.
  These preview results overlap the independent resize repair above;
  they are not additive linked-byte gains.
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
- **Additional consumer (2026-10-26, `42e205255d`):**
  [audio key insertion](../reverse/attempt_support/audio-identity-funclet-refusal-20261026.md)
  passes all five rows and two EXACT EH graphs. Retirement still demands
  `$L4992`, while the verified parent places `$L5053` at 0x00773EC5. The
  relocation scanner repeats the literal lookup, so skipping the first refusal
  would conceal the cleanup call. Missing/stale providers remain independent
  prerequisites; seven real-COFF regression cases reproduce the verifier defect.
- **Verifier repair (2026-10-26):**
  [strict shared EH resolution](../reverse/attempt_support/identity-eh-retirement-verifier-20261026.md)
  preserves the logical row key while scanning the physical label's references;
  unproved labels refuse retirement and ordinary/full scans. After normal
  provider refresh, audio's two outgoing identity keys have a clean verdict;
  its complete 992-row scan checks 1,117 references with zero findings. This
  clears the audio verifier prerequisite, not the other source-specific repairs.
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
- **Independent identity attempt (2026-10-26, `a4cd5136e5`):**
  [the const-tree lookup handoff](../reverse/attempt_support/aiupdate-tree-find-identity-20261026.md)
  identifies unsigned retail comparisons at 0x00759410 versus the donor's
  signed 70-byte copy. An unsigned blend-tuned trial reproduces that helper's
  71 bytes but breaks the existing G7 vector-empty row; declaration-only and
  direct-owner return forms hit VC7.1 C1001. All trials are discarded. Restored
  source passes eight rows/241 B and its EXACT EH graph; the current-object
  preview against d1f046749a retains 17 U, six C, five S and zero linked bytes.
  The identity key and disputed routing remain open. No clearance is claimed.

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

- **Camera-shake bounded composition (2026-10-26, input `6db4bffb3e`):**
  [The consolidation audit](../reverse/attempt_support/camera-shake-consolidation-20261026-codexb4.md)
  records absorption of Rva00065E21Method.cpp into its approved camera-shake TU.
  All 27 rows across the three surviving units and five EH graphs remain exact;
  the destination has a strict current receipt and zero wrong code/data bindings.
  The plain preview against index `5ce093a71a` retains the deleted donor and
  reports a historical duplicate. The merge guard and a bounded in-memory
  comparison that removes that retired object clear all three current units,
  preserving 1,332 authored bytes. This clears this composition's ordinary
  bounded scope only; the index predates outgoing base `3389824a5a`, and exact-base
  batch closure and census confirmation remain pending. No new linking gain,
  debt retirement or image-ownership measurement is claimed.

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
- The codex4 prerequisite batch ending at `bca2dcdf04` published no source
  moves or composed objects. SlavedUpdateRepair.cpp's canonical GameLogic
  adoption preserves all 62 external code definitions, 52 undefined symbols
  and 71 code/data COMDATs against its original verified object. The push hook
  passed 60/60 rows across five affected sources, but its batch audit remained
  inconclusive: provider index `d1f046749a` did not match outgoing base
  `0dd5e48e6a`, and five source objects lacked current strict receipts (first
  Eva.cpp). No linked-byte increase or whole-image provider clearance is
  claimed. See the SlavedUpdate prerequisite handoff for unchanged merge and
  split blockers; all landed scope claims were released.
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

- **Assignment current-input audit (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` supersedes the earlier already-linking append observation for this fixed index: the seven current append emitters still block the two assigned consumers, as detailed in LINK-006. `RtcStack.cpp` retains the native-library duplicate; a noinline-inline trial previewed LINKS only because its matched symbol disappeared, so the failed byte check forced reversal. The final 90-byte row is exact and still duplicate-blocked. The `Weapon_getName_Thunk.cpp` native callee at `0x0028F940` is the existing `NetCommandMsg::getContentsAsAsciiString` row: it ignores `this` and constructs from the empty-string global, so changing a shared WeaponTemplate accessor to fit it would require first settling the wrapper identity. The Debug vtable and file-static latest-texture ownership prerequisites remain unchanged; no forbidden shared-header, row-move or pin trial was made. Next checks: resolve the CRT owner policy, establish the weapon-wrapper identity, reconcile Debug slots, and recover the texture thunk in its proper owning TU. No clearance or census gain is claimed for these units.

- **Current address-blocker clarification (2026-10-26, inspected `896af216804e1f1e34de28bd318285fbbbfcc536`; index `d1f046749a`):** the ordinary preview still reports A=1 for `ConstIntGetters2Addr.cpp` and A=1042 for `ConstIntGettersAddr.cpp`. The former's 0x00424F58 literal is inside a rowed string body and its meaning remains unasserted. The latter now contains large FieldParse/data initializers as well as getter immediates, so the earlier blanket false-positive explanation does not establish the meaning of its current findings. No literal, row or data ownership was changed. Raw before/after previews and the successful 149-row combined byte gate are in `build/link-worker-w1/`; classify actual datum ownership before changing these values or the heuristic. Clearance remains pending.

**2026-10-26 current-provider recheck, inspected `896af216804e`:** the d1f046749a index still reports one append COMDAT blocker for each of `StlportNarrowAppendCStr.cpp`, `stlport_float_format.cpp`, `stlport_narrow_ostringstream_dtor.cpp` and `stlport_narrow_stringbuf_overflow_setbuf.cpp` when the four are checked alone. Supplying current `stlport_narrow_string.cpp` and `stlport_narrow_string_append.cpp` in the same call makes all six LINKS. The former changed since the index and now emits the native const/mutable append bodies. This is inherited repair, verified without any string-source edit or repeated C1001 trial. Repeated 40-unit before/after previews preserve all four results; all assigned rows byte-verify. Raw evidence: `build/link-worker-w5/before-all.log`, `before-strings-current.log`, `before-cohort.log`, `after-cohort.log` and `all-assigned-build.log`. These four units are cleared in ordinary-preview scope; census confirmation pending. Their preview bytes are not new repair credit for this worker.

**W3D dependency scanner follow-up (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** the `ChunkLoadClass(FileClass*)` and six imported STL references in `w3d_dep.cpp` belong to its unrowed donor scanner. Removing that scanner preserves its equality row and previews LINKS, but the wider 618-unit current-provider check makes previously linking `stlport_list_string_erase_00424363.cpp` lose `_S_merge`, `_S_sort`, `_S_unique`, allocator-proxy `swap`, the string-list `_List_base` constructor/destructor and `_M_create_node`. The entire scanner-removal trial was reversed, and the restored consumer links again. Raw evidence: `build/link-worker-w5-c136/final-before-cohort.log`, `final-after-cohort.log`, `terminal-w3d-restored-preview.log`, `terminal-w3d-restored-build.log` and `terminal-after-cohort.log`. The earlier cached-object audit found no external reference only because that consumer object was stale; it does not override the freshly compiled result. Next check: recover those exact current string-list provider dependencies together before removing the donor scanner, potentially retaining the required existing primary-template instantiations explicitly. This seat stops on the demonstrated consumer regression. No w3d_dep edit, clearance or census gain is retained.

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
Status: Open. Updated: 2026-10-26; inspected revision: 896af21680.
Evidence / affected units: `Code/GameEngine/Source/GameLogic/System/LivingWorld/LivingWorldBuildingCtor.cpp`
(298 B) initially had three unresolved names on the earlier inputs (`link_check.py`, index 47e030bafc):
`??1LivingWorldBuilding@@UAE@XZ`, `?LoadPostProcess@LivingWorldBuilding@@UAEXXZ`, `??1Rva004E0790@@QAE@XZ`.
Target facts: retail ctor 0x004E119C stores vptrs 0x00C61618 (Snapshot) and 0x00C61610 (RegionTurnObserverView).
0x00C61618 slots: 0 = 0x004E0E5C (rowed `??_GRva004E0D67` in `OpaqueScalarDeletingDtorsB11.cpp`, which calls the
dtor 0x004E0D67, rowed `??1Rva004E0D67` in `Rva004E0D67Dtor.cpp`), 1 = 0x000B3FD0 (the shared empty `ret`),
2 = 0x004E0777 `GetSnapshotName`, 3 = 0x004E0E78 `DoXfer`. The ctor's +0x3C unwind funclet (0x0079198E) jumps to
0x002B2E8E, the ICF-folded holder dtor already rowed as `??1ArmySummaryEntryRef@@QAE@XZ` (fold-proof in
`Rva002B4076Dispatch.cpp`).
Completed: the constructor now stores the army holder as `ArmySummaryEntryRef`, whose existing 18-byte destructor at `0x002B2E8E` is defined by `Rva002B4076Dispatch.cpp`. Its setter keeps the existing `Rva004E0790` call view. All six constructor-unit rows remain exact, the complete EH graph is EXACT, and the current six-unit preview drops `??1Rva004E0790@@QAE@XZ` with no new finding. Raw before/after and gate outputs: `build/link-report.md` and `build/link-worker-20261026/`.
Remaining / next check: rename/reconcile the `Rva004E0D67` destructor and deleting-destructor owners to `LivingWorldBuilding` while preserving their full vtable bindings; admit the empty `LoadPostProcess` override at `0x000B3FD0` through the normal folded-row path. Both remaining names stay unresolved in the current preview. No row rename, new body or pin was attempted in this seat.
Clearance: holder destructor binding cleared in ordinary-preview scope; census confirmation pending. The complete constructor unit remains blocked on the two names above.
Census confirmation: not claimed.

Current destructor-side inspection (2026-10-26, revision `896af216804e1f1e34de28bd318285fbbbfcc536`; index `d1f046749a`): `Rva004E0D67Dtor.cpp` still has four unresolved virtual names. Its table at RVA 0x00861618 puts the name getter `LivingWorldBuilding::GetSnapshotName` (0x004E0777) where the private view spells `crc`, and `LivingWorldBuilding::DoXfer` (0x004E0E78) where it spells `xfer`. `Gen_uwm_004edfff::s0` also conflates the derived listener slot at 0x004E06B8 (`LivingWorldBuilding::BeginTurn`) and its base slot at 0x0050B238. These are signature/type conflicts, not requests for one same-signature alias. No source trial was made. Raw table-slot witnesses and row homes are in `build/link-worker-w1/native-witnesses.log`; the unchanged destructor unit passes the combined byte gate. The class/observer reconciliation above remains the prerequisite; no clearance or census change is claimed.

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

- **Current-input confirmation (2026-10-26, inspected `896af21680`, index `d1f046749a`):** `build/link-report.md` and `build/link-worker-20261026/` verifies both rows remain byte-exact and the original two opaque references plus losing/wrong-selected clear remain. The recorded declaration-only trial was not repeated because it leaves the clear name without a provider. Native `0x0002CCC3` still calls `0x002234FE`; recover the macro-table element identity and reconcile row owners before an emission change. Clearance and census confirmation remain pending.

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

**2026-10-26 bounded recheck, inspected `896af216804e`:** retail 0x00423EB0 still calls the 58-byte inner-deque destructor 0x00422D48 and 36-byte 40-byte-stride iterator increment 0x0042198C. With both current providers supplied, the sweep unit remains L2/S2, while `StlportNestedWordDeque.cpp` and `stlport_pod_deque_bodies.cpp` remain LINKS. No trial changed element/template names: they occur in the matched row name, so adopting the real nested-deque element requires naming-lane ledger changes outside this seat. Evidence: `build/link-worker-w5/retail-probe-final.log`, `before-extra-providers.log` and `after-cohort.log`. Remaining prerequisite and next useful check are unchanged; no clearance or census confirmation claimed.

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

**Current-provider recheck (2026-10-26, inspected `896af216804e`):** `BitFlagsClear.cpp`, `DumbProjectileBehavior.cpp`, `Player.cpp` and `WeaponSet.cpp` were checked together against d1f046749a. The row owner still loses its reset copy and sees a wrong selected clear copy. No new source trial or shared-header edit is applied. The previously documented include-order/shared-view prerequisite remains; a future repair must preserve every provider and consumer row. Raw evidence: `build/link-worker-20261026-w2/all-cohort-before.log`, `all-cohort-after.log` and `provider-paths.log`. No clearance or census claim.

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

**Assigned `_M_clear` recheck (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `StlSweepR3Rva000B0298.cpp` remains U5/L1/S1 with current providers. Its 30-byte row still calls 0x000AFF52, whose 25-byte owner remains spelled `__destroy_aux<Rva00111B25Record*>`; the second 0x000B0298 row in Rva000B0298Clear.cpp remains present. Both provider and duplicate owner preview LINKS. No source edit or repeat of the failed forced-inline forwarding recipe was made. Raw native evidence and paired previews are in `build/c136-r3sweep/`; `build/link-report.md` maps the receipts. Resolve the duplicate row and destroy signature together before the next repair; clearance and census confirmation remain pending.

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

**Assigned-family confirmation (2026-10-26, inspected `58598f540fd3c84610304b3659ed382a4c05acca`):** both `StlSweepW4Rva001EBEAB.cpp` and `StlSweepW4Rva002BC47D.cpp` remain U3/L1/S1 with current native providers against index `d1f046749a`. Their retail calls still reach the CarryoverUnit and split 52-byte-record owners documented above. No source change or repeat of the failed forwarder/overflow-suppression trials was made. `build/c136-w4sweep/native-evidence.log`, `provider-rows.json` and the paired ordinary-preview logs retain the native references and row homes; all their rows pass `final-all-assigned-build.log`. Next check remains coherent element/row reconciliation, including the real `CarryoverUnit` name where independently supported, rather than adding more same-address placeholder names. Clearance and census confirmation remain pending.

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
- **Recheck (2026-10-26, HEAD 8f71fe0657):** the census at 5ce093a71a still lists the 23
  units, but it predates the revert (f598ec4226 is not its ancestor; its tree still spells
  `extern GameInfo *TheSkirmishGameInfo;` in ten `Common/` units), so it is not evidence
  against the repair. No `Code/` declaration spells `GameInfo *` at HEAD, and
  `link_check.py` against that census previews `Rva005216A6.cpp` 0 -> 37 B and
  `SkirmishPreferences.cpp` 0 -> 2,175 B. The data-ledger step above is not a link
  prerequisite: `link_census.data_ledger()` reads `reverse/data_rows.csv`, which since
  e40a67706e holds the matched `?TheSkirmishGameInfo@@3PAVSkirmishGameInfo@@A` row at
  0x00E02EF0; `reverse/data_ledger.csv` is a derived register that needs every matched
  object built to regenerate (`data_ledger.py --check`: 1,037 sources without objects here).
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
- **Capture-owner ledger follow-up (2026-10-27, base `6f7952d716`):** the five
  consumer fixes are already upstream. The existing private one-byte owner is
  now recorded separately, with seven native DIR32 operands and the zero
  initializer verified. The current six-source cohort passes 31 function rows
  and five data rows. [Current evidence](../reverse/attempt_support/ww3d-capture-data-owner-20261026.md)
  preserves the historical preview separately; no new census gain is claimed.
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
  `__node_alloc::deallocate`, two losing COMDATs). Initial gaps: the split lane
  (covered by the follow-up below), merges in which no unit links, and changes
  to other units since the census.
- **Split protection (2026-10-26):** `tu_skeleton.py --split` now compares a
  freshly compiled original mixed file and existing destination against the
  residual/destination pair, at their actual post-carve link positions. The
  existing byte checks remain. New blockers, a clean destination inheriting
  donor debt, missing outside providers, changed alias routes, new outside
  duplicates/COMDAT losers and changed selected implementations refuse the
  candidate before application. Existing debt remains visible. Moved unknown
  copies require matching raw relocation context and stable outside referents;
  changed `/MAP` exceptions need measured evidence. Regression fixtures use
  real COFF readers and the census rules, including accepted cross-file calls,
  COMMON providers, unchanged debt and dry runs. The scope is the two affected
  compiled units plus the census's outside-provider evidence; changes elsewhere
  since that census remain a limitation. No game source or census was changed.
  Verification: 259 tests and 17 subtests passed, with one existing skip. One
  Windows CRLF-writing split-ledger fixture was deselected after reproducing
  its LF-refusal on the original HEAD tooling; ledger validation stays enforced.
- **Guard false reject (2026-10-27):** the PR115 INI merge preserves its existing
  21-byte `rts::equal_to<AsciiString>` copy and its precedence over ThingFactory,
  but the trial view forgets that ThingFactory already lost before the merge.
  [The pre-merge evidence](../reverse/attempt_support/ini-linkguard-premerge-baseline-20261027.md)
  distinguishes unchanged debt from newly broken outside units. A separate
  verifier repair and a fresh guard after rebase remain prerequisites; no
  source workaround, census gain or linking clearance is claimed.
  The separate verifier repair is now tested against authenticated old object
  bytes and the real before/after order: 228 tests and 11 subtests pass (one
  existing skip), and the bounded eight-object INI replay reports no problems.
  Missing raw proof, private/weak/alias context, a changed selected body or a
  newly referenced losing copy remain refused. The final guard after rebase
  and census confirmation are still pending.
- **Census confirmation:** awaiting the next census.


- **Bounded duplicate follow-up (2026-10-26, inspected `896af216804e1f1e34de28bd318285fbbbfcc536`; index `d1f046749a`):** `MultiplayerColorDefinitionCopy.cpp` still collides with MultiplayerSettings.cpp's implicit copy constructor. The explicit 79-byte body is retail-correct; the merged provider's implicit copy is not. No repeat of the failed flag trial and no source edit were made. Preventing that implicit copy requires the shared MultiplayerColorDefinition declaration to declare the out-of-line copy constructor, or the separately approved TU reconciliation; this seat forbids shared-shim edits and row moves. The raw index providers, ordinary previews and unchanged byte gate are in `build/link-worker-w1/`. No clearance claimed.

- **INI integration guard verified (2026-10-27, base `72327e6ccf`):**
  [the current integration receipt](../reverse/attempt_support/ini-publication-current-provider-audit-20261026.md)
  passes 57/57 current rows and the fresh eight-object pre-merge guard with
  authenticated census-object evidence, `problems: []`. Seven whole donors
  move 14 existing rows / 906 bytes. The outgoing path audit finds no active
  removed-path consumer, and the unrelated HeaderTemplate queue row is
  preserved. This clears this INI consolidation guard only; the broader
  obstacle, official census and runtime confirmation remain open.

### LINK-043: StlSweepR3Rva00406B1D instantiated stable_sort instead of emitting scalar deleting destructor
Status: Open for the extended family; original unit cleared. Updated: 2026-10-26; inspected revision: 896af216804e1f1e34de28bd318285fbbbfcc536.
Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva00406B1D.cpp`,
`reverse/link_status.csv` reported 4 unresolved blockers (`??0Rva00406B1DRecord@@QAE@ABU0@@Z`, `??1Rva00406B1DRecord@@QAE@XZ`, `??4Rva00406B1DRecord@@QAEAAU0@ABU0@@Z`, `??MRva00406B1DRecord@@QBE_NABU0@@Z`).
Completed: Retail 0x00406B1D (28 B) is the scalar deleting destructor `??_GRva00406B1DRecord@@QAEPAXI@Z` calling ~Rva00215E42 at 0x004059AC. Replaced `stable_sort` template instantiation with direct delete anchor calling rowed dtor provider `??1Rva00215E42@@UAE@XZ` via `/alternatename`, resolving all 4 unresolved symbols.
Remaining / next check: none for the original unit (inspected b06312df51); the extended family below still needs three destructor identities reconciled.
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

#### Six deleting-destructor instantiations, 2026-10-26

Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva{00551B02,005838DC,005AFEDB,005CE7CE,005DA663,005E96DC}.cpp`, one existing 28-byte scalar deleting-destructor row each. Current retail disassembly and emitted-helper references are in the [worker handoff](../build/link-report.md) and `build/w4-link-20261026/evidence.log`; ordinary previews use published index `d1f046749a`, rules `retail-truth-4`.

Completed: replace each unrelated `stable_sort` instantiation with scalar `_STL::_Destroy<Record>`. MSVC emits the same deleting destructor from the existing declared destructor. No handwritten function, anchor or new alias is needed. The unused min/max adapters and optimization pragmas disappear. All six rows pass `build.sh`, declaration, EH and shadow data checks. Units `005CE7CE`, `005DA663` and `005E96DC` now report LINKS in the combined current-input preview. Their existing bindings to `FamilyDeletingDtors_muse-06-5E8EA9.cpp` (005E8F6A), `Disp0DwordImmSetters.cpp` (005970E6) and `Rva005E9625Dtor.cpp` (005E9625) are unchanged; all three providers remain LINKS.

Remaining / next check: `00551B02`, `005838DC` and `005AFEDB` each retain only their record destructor as unresolved. Their retail calls already target rowed destructors: `GameSpyBuddyMessageQueue` at 00551988 (126 B, BuddyThread_Unresolved.cpp), `Rva005838B5` at 005838F8 (59 B, Rva00587F69Dtor.cpp), and `Rva005AFE3F` at 005AFE3F (71 B, Rva005AFE3FDtor.cpp). Reconcile the deleting-destructor row's class and virtual contract with its provider rather than adding an alias. The GameSpy class has a real-name lead; the other application class names remain unknown. Row renames were unavailable to this worker. BuddyThread_Unresolved.cpp retains its pre-existing deque blockers; the other two provider units remain LINKS.

Clearance: `005CE7CE`, `005DA663` and `005E96DC` are cleared in ordinary-preview scope; census confirmation pending. The other three units remain blocked. Across the full paired worker scope, no previously clean unit becomes blocked and no compared unit gains a named blocker; raw before/after outputs are retained with the handoff. This does not clear the broader identity or whole-game linking scope.

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

**2026-10-26 current-provider follow-up, inspected `896af216804e`:** the assigned insertion-sort unit remains U2/S1 when checked alongside current `S4StlSortHelpers.cpp`; the helper unit still selects its nonretail linear-insert copy. Retail 0x00337555 calls the 67-byte record copy 0x003371B1 and 85-byte linear insert 0x00337424, both already rowed under the placeholder names recorded above. Its unresolved `BfmeSortElem20Tail` members come from the implicit local element copies, not separate calls in the matched 46-byte loop. Dropping those copies without reconciling the existing S4 users would remove their provider. No source edit or additional pin was attempted. Evidence: `build/link-worker-w5/retail-probe-final.log`, `index-probe.log`, `before-extra-providers.log` and `after-cohort.log`. Next: the existing cross-unit element/member identity reconciliation, preserving all consumers. No clearance or census confirmation claimed.

**Final-insertion helper repaired (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; ordinary-preview index `d1f046749a`, retail-truth-4):** `S4StlSortHelpers.cpp` now instantiates only its rowed final-insertion dispatcher, keeps its original `-GX-` flag and declares insertion sort without a body. Existing `stlport_introsort_loop_s4sortelem20.cpp` explicitly instantiates insertion sort using its unchanged EH-enabled flags, correct element lifetime and const-reference comparator. The consumer view uses canonical AsciiString storage, a byte flag and opaque three-pointer tail, with copy construction/destruction and nonthrowing assignment declared out of line. This removes unrelated wrappers and replaces the three selected-wrong insertion helpers with retail copies from the existing provider. `build/link-worker-w6/s4-verdicts.log` proves the final dispatcher, insertion sort, linear insert, unguarded sort, unguarded linear insert and comparator retail across the two objects. An intermediate flag-omission trial was rejected; `flag-directives.log` verifies that both retained sources preserve every original code-generation flag. All assigned and changed-provider rows byte-verify; declaration, EH, shadow data, CSV and pin checks pass. Paired current-object previews in `paired-before.log` / `paired-after.log` include every assigned unit, named provider and S4 consumer; `cohort-comparison.json` verifies completeness, no new named blocker and no lost linking unit. The helper unit is cleared in ordinary-preview scope; census confirmation pending. The insertion-loop provider still has the two BfmeSortElem20Tail lifetime references, so the broader element-name reconciliation remains open. Next check: reconcile that tail's actual vector copy/destructor owners without reviving the now-correct helper copies. Full receipts: `build/link-report.md`.

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
- **Prior pin follow-up:** the `insert` pin's `fold-proof=` names `Credits.cpp`,
  whose copy no longer equals retail; `stlport_list_int_insert.cpp` now proves it. The
  pin was left as is (pin edits go through `tools/pin_admission.py`).
- **Wrapper cleanup (2026-10-26, inspected `c254d71bb8`):**
  [paired verification](../reverse/attempt_support/credits-delete-wrapper-cleanup-20261026.md)
  removes the unused `famgenDelete005B72E7` wrapper and its unmatched hatch.
  `addText` still emits the matched deleting destructor. All 31 byte-checked
  functions, the data row and five EH graphs remain exact; the frozen-file and
  shadow data checks pass. With published index `5ce093a71a` (19:02), both
  before and after preview LINKS for Credits (3,053 authored bytes) and its
  insertion provider (62 bytes). This retires one hatch and confirms the earlier
  repair; it adds no linking gain. A bounded preparation accepts Credits' strict
  reusable input receipt, without claiming dependency closure. The stale pin
  proof above and confirmation in the next normal census remain follow-ups.
- **Pin follow-up closed (2026-10-26):** the same
  [evidence](../reverse/attempt_support/credits-delete-wrapper-cleanup-20261026.md#redundant-insertion-pin-follow-up)
  confirms that the exact insertion name already has its 37-byte matched row
  in `stlport_list_int_insert.cpp`. Removed its redundant pin and lowered that
  address's pin hatch count 14 -> 13. Both whole units pass 36/36 byte checks
  without the pin; pin consistency and CSV validation pass, and both still
  preview LINKS. This retires one further hatch, with no new linking gain.
- **Remaining / next check:** confirm the repaired two-unit scope in the next
  normal census; the stale insertion-pin proof no longer needs repair.
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
Status: Open (11 retired, leads below). Updated: 2026-10-26; inspected revision: b1071e9a26; index d1f046749a.
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
- 0x0020F0B8 `StlSweepW5Rva0020F0B8.cpp` (owner `ParticleSystemDebugDisplay.cpp`, pair<AsciiString, int>
  ctor; ICF aliases in `Rva002214A6Dtor.cpp`, `ParticleSystemManagerRva001FCF11.cpp`) c1775868b0; its
  element copy-ctor pin dropped.
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
- 0x00217607 `GameFont.cpp` `Rva004738A0::set` (BFME 1 donor, unused in the unit): the STLport pair
  ctor in `Rva005C6CCC.cpp` links; ready to retire, but GameFont.cpp was edited on master (6db0d6d013).
- Now both copies link (other agents' LINK-035 repairs on master), so these are no longer over-claims
  but a which-name decision: 0x0052BBD7 (10c7278d38), 0x00587752 (282446c955), 0x005F9813 (16e13794ee),
  0x004F7D7F (392f9f6fe0).
- Naming decisions (the non-linking copy carries the better name): 0x005481F9
  `ObjectOrderQueue::setPatrolStartOrder` in `ObjectOrderQueue.cpp` vs linking `Rva00548117::rva005481F9`
  (`Rva005481F9.cpp`); 0x0048C7BF address-named `Rva0048C7BF` copy in `FlammableUpdate.cpp` vs linking
  `FlammableUpdate::rva0048C7BF` (`FlammableUpdateRva0048C7BF.cpp`) is ready to retire, but
  FlammableUpdate.cpp was just consolidated on master (f41e95506b).
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

**Generated unwind duplicate cleanup (2026-10-26, inspected `39e752ed5b`):**
Retired `uw_gen_009.cpp`'s four 14-byte copies at 0x007A7724/32/40/4E.
The existing AssetManagerImplCtor.cpp rows from `f943117658` retain each exact
range; the current constructor and its full EH graph verify EXACT, and all
12 surviving rows pass. The strict-current parent preview remains LINKS
against index `5ce093a71a`. Tombstones and evidence are in
`reverse/attempt_support/uw009-parent-repoints-20261026.md`; LINK-095 records
the broader generated-harness cleanup and remaining blockers. No census gain
is claimed.

**Assigned retired-unit recheck (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `StlSweepR3Rva004F715B.cpp` is absent and has no current row; its retirement is recorded in `reverse/deleted_rows.csv`. The surviving `stlport_pop_heap_rva004f7e61.cpp` remains byte-exact and LINKS in the paired current-provider preview. The two hashtable over-claims at 0x001DE3E3 and 0x001FDEBC remain; their bounded emission cleanup is recorded under LINK-066 and does not settle ownership. Evidence: `build/c136-r3sweep/before-retired-004f715b.log`, `native-evidence-03.log`, `after-expanded-cohort.log` and `final-assigned-build.log`. No new retirement or census gain is claimed; the next check is the normal ownership/naming decision for the surviving duplicates.

**GUI-package recheck (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`):** `Rva00576DF1Ctor.cpp` is absent; current history records its retirement as `febea697c2a`. The surviving `Rva00576C4BDtor.cpp` remains LINKS and passes all 25 byte rows. The two remaining constructor views now bind their 0x005CD7DA cleanup directly to that owner's existing `Wrap2000576C4B` destructor, clearing that record subset as detailed in LINK-085. The duplicate planning constructor and its three unique EH rows remain untouched. Approved ownership and coherent class naming are still prerequisites for retiring that duplicate; no row move or retirement was attempted here. Raw receipts: `build/c136-gui-w2/expanded-before.log`, `expanded-after.log`, `final-provider-build.log` and `build/link-report.md`. Census confirmation remains pending.

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
Status: Open. Updated: 2026-10-26; inspected revision: 2a45addda1806342ac5c52757f63be902dcd428e.
Evidence / affected units: `SplineCameraParseINIBlock.cpp` (0x004E3300, 130 B) declares a private `Rva003BA660Record`, so its ctor, tree dtor, field table and append stay unresolved. Retail 0x004E3300 (target facts): ctor 0x004E32D5 `??0Rva004E32F2@@QAE@XZ`, `INI::initFromINI` 0x0002DE78 with the table at RVA 0x00861FB8, append 0x00566D7B `?rva00566D7B@Rva00566D7B@@QAEXABVRva004E32F2@@@Z`, then the inlined virtual dtor: vftable 0x00861F68 (slot 0 = `??_G` 0x004E37B3) and the tree dtor 0x002B80CE (`~_Rb_tree<int, pair<const int, AsciiString> >`), while the ctor binds the map<int, BfmePod24> ctor 0x005011C1 by `/alternatename` (`Rva004E32D5Ctor.cpp`). The table holds three 16-byte FieldParse entries (strings 0x008618F8, 0x008618D0, 0x00861F6C; parsers 0x0002F0F7, 0x0002E850, 0x00503FD1 with userData 0x008E148C; offsets 4, 8, 0) plus a null terminator.
Completed (2026-10-26): SplineCameraParseINIBlock.cpp now includes the existing `reference/shims/iniexception/Common/INIException.h` instead of its reversed-field, destructor-free private exception view. This agrees with INIExceptionCtor.cpp and INI_initFromINIMulti.cpp. The paired current-provider preview removes `__TI1?AVINIException@@` and preserves both providers as LINKS; the parser remains U4. Both source rows and its EH graph verify exactly, with zero shadow-data findings. Raw evidence: `build/c136-logic/spline-paired-before.log`, `spline-paired-after.log`, `spline-build.log`, `spline-eh-final.log`, and `build/link-report.md`.
Remaining / next check: row the table as data, give the record the Rva004E32F2 identity with one tree type for ctor and dtor, and settle where `??_7Rva004E32F2@@6B@` and `??_G` are emitted (`Rva004E32F2Dtor.cpp` carries an inline anchor for them) before the parse unit inlines that dtor.
Clearance: the INIException metadata subset is cleared in ordinary-preview scope; census confirmation pending. The record, append and data-table prerequisites remain open. The existing data ledger marks the table at 0x00861FB8 unowned; its provisional extent is not a newly verified table definition.
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

### LINK-070: stlport_float_format keeps its own 279-byte narrow forward-iterator append

**Current-provider confirmation (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`):** the coordinated Rva003A6F70 copy/destructor retyping described above is already present at this HEAD. Supplying current `stlport_pod_noexc_deferred_copies.cpp` and `System/Rva0056616BCopy.cpp` makes `Rva0056616BCopyDeferred.cpp` LINKS without a source edit in this run. Its standalone preview still lacks the newer provider names in the published index. Both paired current-provider previews retain this result, and the normal assigned-source byte gate passes. This consumer is cleared in ordinary-preview scope; census confirmation pending. This is inherited repair, not new source credit for this worker, and does not clear the provider's independent blockers. Raw receipts: `build/link-worker-w6/paired-before.log`, `paired-after.log` and `all-assigned-build.log`. Next check: confirm the consumer in the next ordinary census.

### LINK-091: stlport_float_format keeps its own 279-byte narrow forward-iterator append

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

### LINK-071: STLport facet virtuals rowed under placeholder names (RTTI vftable slots)

**Status: Open. Updated: 2026-10-26; inspected revision: 13cb4119f9.**

- **Evidence / scope:** `tools/vtable_slots.py _STL` names every STLport vftable by RTTI.
  Slots 4 and 5 of `numpunct<char>` (0x007BBB78) hold 0x00017A40 / 0x00017AA0 and of
  `numpunct<wchar_t>` (0x007BBB94) 0x00017B00 / 0x00017B30: `do_truename` / `do_falsename`.
  They are rowed as `?init@Rva00017A40StringInit@@...` (and siblings) in
  `stlport_narrow_string_range_ctors.cpp` and `Rva00017B00StringInit.cpp`, reading
  address-named 12-byte globals (0x009DEEF0..0x009DEF38, `g_Va00DDEF08` and the like in
  `Rva007AB8D0StringInits.cpp` / `Rva007B6880Thunks.cpp`). `stlport_numpunct_virtuals.cpp`
  (44 B, 4 rows) defines the real `do_truename` / `do_falsename`, unrowed, and does not link:
  its `_M_truename` / `_M_falsename` statics of both specializations are unresolved.
  Same slot test also shows the wide `moneypunct` string getters (0x00019D90, slots 4-6 of
  0x007BC868 / 0x007BC894) rowed as the placeholder `?init@Rva00019D90StringInit@@QAEPAXPAX@Z`
  in `Code/GameEngine/Source/Common/Rva00017B00StringInit.cpp`.
- **Completed:** the same shape for slot 0 of `basic_ios<wchar_t>` (0x007BBCFC):
  437bc30603 repointed 0x00013490 from `??_GRva00013490Element` to
  `??_G?$basic_ios@GV?$char_traits@G@_STL@@@_STL@@UAEPAXI@Z` in `stlport_wide_ios.cpp`
  (link_check 296 -> 326 B) and removed the never-linking split unit.
  ea8aaf453c renamed `collate<char>` slot 2 (0x00017890, vftable 0x007BBB50) from
  `?init@Rva00017890StringInit@@` to `?do_transform@?$collate@D@_STL@@MBE...PBD0@Z` in place in
  `stlport_narrow_string_range_ctors.cpp` and removed the two `/alternatename` hatches that bound
  the real name to the placeholder (`stlport_classic_locale.cpp`,
  `stlport_locale_facet_subclass_dtors.cpp`); 5/5 units still LINK, bytes unchanged.
  cf40575e42 renamed 0x00019D30 (slot 3 of `moneypunct<char,true>` 0x007BC810; the same body
  fills slots 3-6 of both narrow moneypuncts and slot 3 of both wide ones) from
  `?init@Rva00019D30StringInit@@` to `?do_grouping@?$moneypunct@D$00@_STL@@MBE...XZ`; the
  moneypunct ctor/dtor units drop that name's hatch and point the other nine folded names at
  it instead of the placeholder. 5/5 units still LINK, bytes unchanged. Those nine hatches stay
  until the folded aliases get their own rows (one body per name would emit unrowed EH
  handlers/funclets).
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

### LINK-072: Zero Hour port units for module classes BFME 2 never had

**Status: Open (3 units repaired). Updated: 2026-10-26.**

**Status: Open (6 units repaired). Updated: 2026-10-26.**

**Status: Open (3 units repaired; inline-only units parked). Updated: 2026-10-26.**

- **Evidence / scope:** several `Code/` units are verbatim Zero Hour ports of
  module classes that retail BFME 2 does not contain. Test, per class: game.dat
  (`baselines/bfme2/workshop-vanilla-1.06/files/game.dat`, `strings` ASCII and
  UTF-16) has no module-name string for it (the factory's name table, e.g.
  around `SlavedUpdate`, `BezierProjectileBehavior`, lists every registered
  module), and `reverse/functions.csv` has no row for any of its methods. The
  port's bodies are then all `present-unmatched` nonmatching reconstructions
  whose references are the unit's only link blockers; the unit's few rows are
  generic inlines a masked search placed there.
- **Completed:** MobMemberSlavedUpdate.cpp (01564e4a01, 0 -> 8 B),
  EMPUpdate.cpp (0a575d1548, 0 -> 13 B, also LeafletDropBehavior),
  HackInternetAIUpdate.cpp (e0cbcdaa47, 0 -> 10 B): ZH bodies dropped, the
  rowed inline kept by explicit instantiation (template) or a pointer anchor
  (TU-local const at /O1; extern const at the default -O2, which drops an
  unused TU-local one). 61 present-unmatched hatches removed. All LINK in
  preview.
  StickyBombUpdate.cpp (ac1b73589c, 0 -> 36 B; the two rowed accessors are
  ordinary out-of-line definitions), ParkingPlaceBehavior.cpp (191cb9df0a,
  0 -> 38 B), AnimationSteeringUpdate.cpp (9cae72c749, 0 -> 14 B): same
  test, ZH bodies dropped, template rows emitted by explicit instantiation
  of the single member. Zero Hour's header declares
  `ParkingPlaceBehavior::RunwayInfo` private and cl 7.1 refuses to name it
  in an explicit instantiation (C2248), so that unit declares only the
  element (36 bytes; the byte-exact strides confirm it). 50 more
  present-unmatched hatches (and one `#pragma optimize`) removed. All LINK
  in preview.
- **Remaining / next check:** same test passes for SpectreGunshipUpdate,
  RailedTransportDockUpdate, DeliverPayloadAIUpdate, JetAIUpdate,
  FlightDeckBehavior, DumbProjectileBehavior, HelicopterSlowDeathUpdate and
  HordeUpdate (no
  module-name string), but check each unit's rows first: several carry ZH
  class names on retail bodies (`SpectreGunshipUpdate::setLogicalStatus`,
  `StickyBombUpdate::set/getTargetObject`, `RailedTransportDockUpdate`
  getters, `RunwayInfo` vector helpers), which need an honest name/home
  before the class can go. HelicopterSlowDeathUpdate's only row is the
  virtual inline `SlowDeathBehavior::isDieApplicable` (0x0045D49E): a
  pointer-to-member of a virtual yields a vcall thunk, not the body, so it
  needs another emission route (parked; see the rehome trial below). AIUpdate.cpp's present-unmatched
  `AIUpdateInterface::privateHackInternet` (no "HackInternetAIUpdate" NAMEKEY
  string in game.dat) now leaves `HackInternetAIUpdate::hackInternet`
  unresolved; that unit did not link before either.
- **Non-hatch emission routes for the inline-only units (2026-10-26):**
  - HelicopterSlowDeathUpdate: the row's approved unit (tu_map) is
    `Behavior/SlowDeathBehavior.cpp`, which already emits
    `SlowDeathBehavior::isDieApplicable` through SlowDeathBehavior's vftable
    (its dtor), but with the ZH UpdateModule layout (`[ecx-0x18]/[ecx-0x1C]`
    against retail `[ecx-0x1C]/[ecx-0x20]`). Adding `/Ireference/shims/dockupdate`
    (retail's extra UpdateModule dword) and `/O1` byte-matches it, but moves the
    unit's two masked-search rows `PhysicsBehavior::setExtraBounciness` /
    `setExtraFriction` (0x000EFB3E/0x000EFB5A) from +0x74/+0x78 to +0x78/+0x7C.
    Those rows are displaced COMDATs with no approved home, so they block the
    rehome; settle their identity/home first (re_log db1eba0fb4).
  - JetAIUpdate: `Matrix3D::Matrix3D(bool)` (0x0004C91A) sits inside
    W3DGameClient.cpp's approved cluster but is itself only `proposed` to a
    non-existent `AIUpdate/Matrix3D.cpp`; a ctor cannot be pointer-anchored, and
    `reference/shims/bfme_matrix3d_bool_link` keeps every other consumer inline
    so JetAIUpdate.cpp is its sole emitter. Parked until the address gets an
    approved unit.
  - DumbProjectileBehavior: `UpdateModule::getUpdatePhase` (0x0022C4CB, the
    ICF-shared PUSH 2/POP EAX/RET slot) is a displaced COMDAT with no approved
    unit (3092d4a84c moved it here); `sqr<float>` alone could stay by explicit
    instantiation. Parked with the getUpdatePhase home.
  - Also failing test 4 (other units need the class's symbols):
    DeliverPayloadAIUpdate (ObjectCreationList.cpp's DeliverPayloadNugget uses
    `DeliverPayloadData::getFieldParse` and the AI update), StickyBombUpdate
    (AISpecialPowerPickers.cpp calls the rowed set/getTargetObject).
    SpectreGunshipUpdate's only row `setLogicalStatus` is protected (`IAE`), so
    a file-scope pointer anchor cannot reach it once the ZH callers go.

  unresolved; that unit did not link before either. Why the rest are
  not one-step (K9, 2026-10-26): HordeUpdate (`isTrueHordeMember`),
  DumbProjectileBehavior (`UpdateModule::getUpdatePhase`), FlightDeckBehavior
  (`ExitInterface::getNaturalRallyPoint`) and RailedTransportDockUpdate
  (`getRailedTransportDockUpdateInterface`, `DockUpdate::setDockOpen`) keep
  virtual inlines, the HelicopterSlowDeathUpdate case; JetAIUpdate's only
  row is the inline `Matrix3D(bool)` ctor (0x0004C91A, whose other emitters
  keep it inline by shim), and no pointer can anchor a ctor;
  SpectreGunshipUpdate's `setLogicalStatus` is a protected inline, so a
  namespace-scope pointer anchor is refused; DeliverPayloadAIUpdate (row:
  `WeaponTemplate::getProjectileExhaust`, anchorable) is the `fold-proof=`
  source of the `Locomotor::setUltraAccurate` / `setAllowInvalidPosition`
  fold pins in `reverse/symbols.csv`, which its ZH bodies instantiate, so
  those pins need another proving source (pin admission) before the
  bodies can go. W3DTankTruckDraw.cpp also fails the string test, but
  retail rows its methods under that class in sibling units
  (W3DTankTruckDrawTossEmitters.cpp, ...CreateEmitters.cpp), so it is not
  this case.

- **Checked, not removable as-is (2026-10-26, K5, index d1f046749a, no source change):**
  - `ObjectCreationList.cpp` (1,427 B, 8 blockers): `DeliverPayloadNugget`
    is ZH-only (no `DeliverPayload` string in game.dat; retail's table at
    0x007E07F0 lacks it) and its `parsePayload` is the unit's static
    `INI::scanInt` caller, but its three `vector<Payload>` rows (0x005F8653
    `_M_clear`, 0x005F8752 `_M_insert_overflow`, 0x005F8855 `push_back`,
    no TU approval) are a masked-search misnaming: retail 0x005F8752 calls
    0x004F6A88/0x004F6A52/0x004F6AAE (`Rva004C5DD0Set.cpp`, an 8-byte
    two-ref-counted-pointer element), which is why `_Construct`/`_Destroy<Payload>`
    lose as "not retail's body". Those rows need an honest element type and
    home before the nugget can go. The `setProducer(const Object *)` U
    blocker is the unfinished ZH-spelling pass from 83a5361fc7 (29 files).
  - `DieModule.cpp` (13 B): its unrowed ZH `crc`/`xfer`/`loadPostProcess`
    and `DieMuxData::getFieldParse` are the only providers of names that
    linked units reference (DieModule vftables in CreateObjectDie,
    SpecialPowerCompletionDie, FXListDie; `buildFieldParse` in ModuleFactory,
    InstantDeathBehavior, about 2.7 KB linked). Dropping them would lose
    those units; the static `INI::scanIndexList` blocker comes from
    `ObjectStatusMaskType::parseFromINI` in that table.
  - `light.cpp` (6 B): the row `LightPersistFactoryClass::Chunk_ID`
    (0x00615B60, `mov eax,0x10001; ret`) is in no retail vftable, so retail
    has no such factory; the virtual inline cannot be kept emitted without
    the ZH factory instance (same vcall-thunk limit as HelicopterSlowDeath).
  - `HordeUpdate.cpp` (14 B): its row 0x0049001F is pointed to from retail
    .rdata 0x0084D054, inside a run of code pointers (a vftable), so a
    retail class owns it; name/home first.
  - `BridgeScaffoldBehavior.cpp` already links in a current preview (952 B);
    its census `UpdateModule::loadPostProcess` blocker is stale.

**Assigned inline-unit recheck (2026-10-26, inspected `2a45addda1806342ac5c52757f63be902dcd428e`, index `d1f046749a`):** HackInternetAIUpdate.cpp and EMPUpdate.cpp already report LINKS in the initial 26-unit preview and retain that result in the paired current-provider preview. Their ten and thirteen authored bytes are inherited repairs, not new gains from this worker. The other assigned inline-only ZH units retain the emission, identity and approved-home prerequisites above; no anchor, row move, new body or repeated rehome trial was added. Raw evidence: `build/c136-logic/before.log`, `final-cohort-before.log`, `final-cohort-after.log` and `all-assigned-build.log`. These two units are cleared in ordinary-preview scope; census confirmation pending.

- **Census confirmation:** pending for all three units.

  b313329af6 renamed the four numpunct slot rows in place to the real `do_truename` /
  `do_falsename` names (narrow pair in `stlport_narrow_string_range_ctors.cpp`, wide pair in
  `Rva00017B00StringInit.cpp`, which drops `/EHs-c-` so `return <static>;` emits retail's
  return-value flag), still reading the existing address-named storage, and removed the
  unrowed duplicates from `stlport_numpunct_virtuals.cpp`: that unit now LINKS (0 -> 44 B).
  The data-lane rename of the statics was not needed for the link.
  620cbe78fd did the same for 0x00019D90 (slot 4 of `moneypunct<wchar_t,true>` 0x007BC868;
  slots 4-6 of both wide moneypuncts): now `?do_curr_symbol@?$moneypunct@G$00@_STL@@...XZ` in
  `Rva00017B00StringInit.cpp`; its own hatch dropped, the other five retargeted. 6/6 LINK.
  Note: link_check without the edited partners in the set uses stale index objects and
  reports spurious duplicates / unresolveds; check these units together.
  13cb4119f9 named the `_Messages` pair (vftable 0x007BC8D4, `.?AV_Messages@_STL@@`): slot 1
  0x0001A090 is `do_get(..., const wstring&)` and slot 2 0x0001A060 `do_get(..., const string&)`
  (reverse declaration order). They were the BFME 1 donor shells `?bfmeGoDQE` / `?bfmeGoDQD` in
  `BfmeConv760.cpp` / `BfmeConv759.cpp`; both now define the real `return __dfault;` in place.
  Four hatches removed (two `do_get` lines in `stlport_messages_dtors.cpp`, the `bfmeCallDQD` /
  `bfmeCallDQE` copy-ctor aliases in `stlport_{narrow,wide}_string_copy_ctor.cpp`) and the two
  placeholder symbol aliases dropped. 6/6 units still LINK, bytes unchanged.
  After this, every RTTI vftable slot outside `ctype` holds a real STLport name or a known
  fold (`do_close` / `Prepare_LOD`, `do_always_noconv` / `_AptValidate`, `showmanyc` /
  `GetNativeHashVirtual`): `tools/vtable_slots.py` lists no other placeholder. Retail is `/GR-`,
  so no engine, W3D or Apt class has an RTTI vftable; this method does not reach them.
- **Remaining / next check:** (0) `ctype` range virtuals: slots 5/7 of `ctype<char>` (0x007BC3E4)
  hold 0x00016C20 / 0x00016C60 (`do_widen` / `do_narrow` range forms) and slots 1/5/7/9/11 of
  `ctype<wchar_t>` (0x007BBAD0) hold 0x00016D00..0x00016E60 (`do_is` / `do_toupper` /
  `do_tolower` / `do_widen` / `do_narrow` range forms), all rowed as the BFME 1 donor names
  `T2NarrowCtype::*Range` / `T2WideCtype::*Range` in `T2CtypeTableFacets.cpp`. The natural owners
  are `stlport_narrow_ctype_virtuals.cpp` (which already defines the two narrow range forms
  unrowed, with `memcpy` bodies that do not match retail's `if (high != low) memmove`) and
  `stlport_wide_ctype_virtuals.cpp` (single-character forms only; addresses interleave).
  Moving the seven rows there removes ten hatches (five each in `stlport_classic_locale.cpp`
  and `stlport_locale_facet_subclass_dtors.cpp`). Not attempted: `T2CtypeTableFacets.cpp` was
  LOCKED by K6. (1) Give the 12-byte statics their STLport names (`_M_truename` / `_M_falsename`,
  monetary.cpp's file-static empty strings) through the data lane; `data_check` (shadow)
  already flags `g_009DEEF0Static` and siblings as duplicate-def / wrong-name. (2) The nine
  narrow and five wide moneypunct alias hatches (per unit) need alias rows to go.
- **Census confirmation:** awaiting the next census for 437bc30603 and b313329af6.

### LINK-064: placeholder element names that hide the retail element of three STL families

**Status: Open. Updated: 2026-10-26; inspected revision: d0d3b5054d, index d1f046749a.**

- **Evidence / scope:** retail call chains name the element of three families
  differently from their rows. Read with `tools/retail_body.py` callers/disasm.
  - **`vector<ProductionPrerequisite::PrereqUnitRec>`**
    (`ProductionPrerequisiteRecVectorInsertOverflow.cpp`, 183 B): the overflow
    0x004F5165 and push_back 0x004F5243 call `_Construct` 0x002CF99D. That body
    calls copy ctor 0x002CF5B1, whose only caller is 0x002CF99D. Both are rowed
    as `BfmeStringRecord002CF5B1` in `StringRecordCopyBFME2.cpp`. The helpers
    0x004F5097 and 0x004F50BD are also rowed under that name, so it is the real
    PrereqUnitRec: two words, then an AsciiString. The ZH view conflates this
    element with another 12-byte record. `ProductionPrerequisite.cpp` rows
    `__uninitialized_copy`/`__uninitialized_fill_n<PrereqUnitRec>` at
    0x004EE1E2/0x004EE20B. Those bodies call 0x004EE1A9, a word-field copy
    rowed as `PerTurnStats` in `V3PolyCopyCtors.cpp`. The symbols.csv pin
    `??0PrereqUnitRec@ProductionPrerequisite@@QAE@ABU01@@Z -> 0x004EE1A9`
    carries the same conflation. That ZH-flagged TU also emits an EH-enabled
    `_M_insert_overflow` (267 B) and an 18 B `_Construct`. It is first in link
    order, so its wrong copies are selected.
  - **`map<int, AsciiString>` in `Rva00566695Assign.cpp`** (179 B): the node
    that clone_node 0x005041D8 allocates through 0x005041B6 is 0x2C bytes
    (`push 0x2c`). That holds a 0x1C value, not `pair<const int, AsciiString>`
    (0x8). The rowed `_Construct` 0x00500CFE calls pair copy 0x00500839, rowed
    `pair<const int, Rva0050055D>` in `StlSweepW4Rva00500839.cpp`. That calls
    0x0050055D, a two-tree copy. The symbols.csv pin
    `??0?$pair@$$CBHVAsciiString@@@_STL@@QAE@ABU01@@Z -> 0x00500839` and the
    whole `map<int, AsciiString>` row family behind 0x00566695 are therefore a
    placeholder value type. It is shared with the genuine ignore-list
    `map<int, AsciiString>` (`UserPreferencesDeferredIgnores.cpp`, `PeerDefs.cpp`,
    `WOLBuddyOverlay.cpp`).
  - **`vector<Rva00584405Element>`** (`StlSweepW4Rva00584405.cpp`, 225 B):
    retail overflow 0x0058431D and copy worker 0x00583B11 construct through
    0x00583A72. 0x00583A1E is an assignment (`mov eax, ecx ... ret 4`, rowed
    `Rva002337F0::set`), not the copy ctor its pin claims. The 28 B element is
    four dwords, a byte at +0x10, then dwords at +0x14/+0x18. Its family is
    split across `Rva002337F0`, `BfmeStringRecord00111ACF` and
    `Rva00584405Element` rows.
- **Completed:** diagnosis only. No source or row was changed.
- **Remaining / next check:** each repair is a family rename, not a unit-local
  change. Retype the rows and callers together under one element and drop the
  wrong pins. Keep the genuine `map<int, AsciiString>` ignore family separate.
  For PrereqUnitRec, first rename the 0x004EE1E2/0x004EE20B rows and their
  0x004EE1A9 element away from `PrereqUnitRec`. Then the 0x002CF5B1 family can
  take the real name, and `ProductionPrerequisite.cpp` can stop emitting its
  overflow and `_Construct`. Related: the `vector<BfmePod32>` copy 0x0052C823
  (`Rva0056616BCopyDeferred.cpp`, 517 B) reaches 0x0052C27E, rowed
  `__uninitialized_copy<Rva003A6F70*>`, so its element is `Rva003A6F70`
  (LINK-002). Its provider file `stlport_pod_noexc_deferred_copies.cpp` was
  being repaired by another worker (98e2e4d836, Pod28 sibling) and was left
  alone.
- **Clearance:** none.
- **Census confirmation:** not applicable.

### LINK-084: audio lookup emits an unrowed owner and an untyped tree-worker trampoline
Status: Cleared in ordinary-preview scope; census confirmation pending. Updated: 2026-10-26; inspected revision: 896af216804e1f1e34de28bd318285fbbbfcc536.
Evidence / affected units: `Audio/AudioManagerAdjustPriorityAndVolume.cpp` owns the 33-byte lookup at 0x00059238 and two five-byte destructor forwarders. The lookup's REL32 at +0xE targets the existing 78-byte `AsciiString` tree worker at 0x001F8437; its `pair<const AsciiString,int>` and `pair<const AsciiString,float>` rows are in `GameClient/System/ParticleSystemDebugDisplay.cpp`, while `OptionPreferences_mapFind.cpp` supplies the existing string/string spelling. Its former setter references were emitted only by an unrowed owner body, whose prior 0x000592B3 placement is explicitly refuted in `reverse/re_attempts.log`.
Completed: use the vendored `_Rb_tree<AsciiString,pair<const AsciiString,int>,...>` directly at +0x1B8; its lookup and iterator access inline into the existing 33-byte row. The existing integer ABI parameter is treated as the native pointer to its `AsciiString` key. Define the rowed lookup out of class so it remains emitted without the unrowed owner. Remove that owner, its setter declarations and the function/member-pointer union. Retain both existing destructor-forwarder rows. Only the STLport and canonical AsciiString include paths are added; no code-generation flags, shared headers, pins or ledger entries change.
Verification: `build/link-worker-w1/audio-before.log` reports three unresolved names and two linking providers; `audio-after.log` reports all three units LINKS. `audio-build.log` and `final-7-build.log` both pass 3/3 matched rows, and `final-7-frozen.log`, `final-7-eh.log` and `final-7-data.log` pass. `final-link-with-audio.log` rechecks every assigned unit and inspected provider together against index d1f046749a (2026-10-26 13:18 UTC, retail-truth-4). Full receipts and exact paths are in `build/link-report.md`.
Remaining / next check: the integer public signature still records the old opaque key ABI; a future naming/identity pass can correct its source signature with its callers and ledger under the normal rename rules. This does not block the verified current call binding. Confirm the unit in the next normal maintainer census.
Clearance: cleared in ordinary-preview scope; census confirmation pending.
Census confirmation: pending; no headline change claimed.

### LINK-066: an entire hashtable instantiation adds allocator dependencies to one row

Status: Cleared in ordinary-preview scope; census confirmation pending. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected unit: `Code/GameEngine/Source/Common/System/XferBlockWriter_rva009D86E0_Rva0060CB97.cpp`, the 21-byte `_M_bkt_num_key(key, count)` row. The whole-class hashtable instantiation emits unrowed operations that reference undefined `__node_alloc<false,0>::_M_allocate` and `_M_deallocate`.
Completed: explicitly instantiate only the existing member from the same STLport primary definition. The matched row is unchanged, and the unit now LINKS. The removed selected copies have no external referrers in the index reference graph; the paired 78-unit preview introduces no blocker. Raw proof: `build/link-worker-20261026-w2/xfer-member-build2.log`, `removed-selected-consumers.log`, `paired-comparison.log` and `all-cohort-after.log`.
Remaining / next check: confirm this unit and the removed-provider scope in the next scheduled census. The build, frozen-file, EH and data checks pass; CSV and pin consistency pass. Full local receipt: `build/link-report.md`.
Clearance: cleared in ordinary-preview scope; census confirmation pending. No census headline change is claimed.

#### Assignment-only R3 hashtables, 2026-10-26

Status: the unrelated equality-dependency scope is cleared in ordinary-preview scope; census confirmation pending. Both whole units remain blocked on native helper identities. Inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`; index `d1f046749a`, `retail-truth-4`.

Evidence / affected units: `StlSweepR3Rva001DE3E3.cpp` and `StlSweepR3Rva001FDEBC.cpp` each instantiated the entire hashtable for one assignment row. Completed: instantiate only the existing `operator=` from the unchanged STLport `_hashtable.h` definition, retaining its required `clear` and `_M_copy_from` bodies. Remove the unused local unsigned-max definition and its optimization pragmas. No replacement helper, renamed class, body-suppression declaration, ledger edit or new hatch is introduced.

Verification: both assignment rows remain exact and their equality-only unresolved names disappear. The expanded paired preview preserves every previously linking unit and adds no blocker. The complete removed-definition/reference audit finds no retained caller without a provider. Raw proof: `build/c136-r3sweep/before-expanded-cohort.log`, `after-expanded-cohort.log`, `expanded-provider-audit.log` and the `final-*` gate logs mapped by `build/link-report.md`. Declaration, EH, shadow-data, CSV and pin checks pass.

Remaining / next check: both units retain unresolved record copy/destructor names and wrong selected `clear`/`_M_copy_from` copies. Native `clear` is 0x003A2A41 in Rva003A2A41Clear.cpp; the copy workers are 0x001DDCC5 in StlSweepR3Rva001DDCC5.cpp and 0x001FDC0F in PlayerTemplate.cpp, under different record names. All three native providers and Eva.cpp are included in the current-object comparison. Reconcile those key/value identities and the duplicate assignment rows (LINK-060) together. Whole-unit clearance remains pending; the ordinary-preview cleanup changes no census headline.

### LINK-067: an ATL cache initializer retains BFME 1 callback and storage names

Status: Cleared in ordinary-preview scope; data-owner reconciliation remains. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected unit: `Code/GameEngine/Source/Common/StaticInit/Rva00C6E31EInitializers.cpp`, 25 bytes at 0x007B556E. Native instructions zero 16 bytes at VA 0x00E09E50 and register 0x007B9B0A. `atlimage.cpp` already defines the 16-byte `ATL::CImage::s_cache`; `Rva007B6A00AtexitThunks.cpp` already defines the cleanup, which jumps to the rowed cache destructor at 0x00628BC5.
Completed: bind the initializer to those existing names, preserving the private nested cache type and all 25 bytes. All three units LINKS; both providers retain their previous results. Raw evidence: `build/link-worker-20261026-w2/native-initializer.log`, `static-providers-before.log`, `static-cache-preview.log` and `static-cache-build.log`.
Remaining / next check: reconcile the stale four-byte `g_Va00E09E50` data row with the actual 16-byte ATL owner. The shadow data checker exits zero but reports the real `s_cache` spelling as one new `wrong-name` finding because the four-byte data row overrides the provisional data ledger. No data register or owner definition is edited here. All required hard checks pass; see `build/link-report.md` and `final-data-Rva00C6E31EInitializers.log` in the same evidence directory.
Clearance: cleared in ordinary-preview scope; census confirmation pending. This is no data-debt retirement or image-ownership claim.

### LINK-068: removing DieModule's unrowed field parser removes a live provider

Status: Blocked on field-parser consumer/provider reconciliation. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected units: `DieModule.cpp` retains undefined `BitFlags<45>::s_bitNameList` and `INI::scanIndexList` through the unrowed port's parsing code. `InstantDeathBehavior.cpp` currently LINKS by referencing that port's static `DieMuxData::getFieldParse`.
Completed: both a minimal bitset-only cleanup and a narrower removal of the port's field-parser definition were tried and fully reversed. The narrow trial makes DieModule preview clean but stops emitting its matched `_Base_bitset<2>::_S_maskbit` row and makes InstantDeathBehavior unresolved. The restored source passes 1/1 and restores that consumer's 34-byte LINKS result. Raw evidence: `build/link-worker-20261026-w2/die-consumers-before2.log`, `die-parser-preview2.log`, `die-parser-build.log`, `die-restored-preview.log` and `die-restored-build.log`.
Remaining / next check: reconcile the native field-parser provider and all actual callers together before removing the port; retain explicit ownership of the bitset row. This seat stops on the demonstrated linking-consumer regression and retains no DieModule edit.
Clearance: pending. Census confirmation: not claimed.

### LINK-052: dispatch-shaped wrappers were misidentified as uninitialized fill

Status: Open. Updated: 2026-10-26; inspected revision: 896af216804e1f1e34de28bd318285fbbbfcc536.

Evidence / affected units: `Code/Libraries/Source/WWVegas/WWLib/StlSweepR3Rva{005243FA,00569450,005AE78A}.cpp`, one 27-byte `uninitialized_fill_n` row each, compared with published index `d1f046749a` (`retail-truth-4`). The [worker handoff](../build/link-report.md) and `build/w4-link-20261026/evidence.log` retain retail wrapper/helper disassembly and the emitted one-byte fill-loop copies. Equal wrapper bytes do not establish the inferred STL algorithm or record identity.

Completed: instantiate only each rowed dispatch wrapper instead of the unrelated `stable_sort`. This removes its unresolved record comparator and the unused min/max/optimization adapters. All three rows pass byte, declaration, EH and shadow data checks. The existing native helper providers remain LINKS in the paired preview. No row, alias, pin, compiler flag or shared header changed.

Remaining / next check: `005243FA` calls 0052408B (179 B, `Rva0052408BFind` in stlport_hero_integer_vector_tree.cpp), which scans 8-byte int/StringBase records with the rowed predicate 00523EFF. `00569450` calls 00569109 (29 B, `Rva00569109RangeForward` in Rva00569109RangeForward.cpp); the same wrapper address also has a 27-byte row named `rva00569450` in Rva00569450Forward.cpp. `005AE78A` calls 005AE6F8 (107 B, `rva005AE6F8` in Rva005AE6F8Find.cpp), an unrolled 8-byte slot scan. Reconcile actual operation, argument types and overlapping ownership before renaming these wrapper/helper relationships. Suppressing an emitted helper alone leaves no same-name provider; substituting an address-named call for a real algorithm name is not a faithful repair. No new native match or fold pin was established.

Clearance: pending for all three units; each retains its required helper as both comdat and selected findings. The comparator cleanup is verified but does not clear linking.

Census confirmation: awaiting; no census claim.

### LINK-053: unmatched light persistence factory instantiates missing donor interfaces
Status: Cleared in ordinary-preview scope; census confirmation pending. Updated: 2026-10-26; inspected revision: 896af21680.
Evidence / affected units: `Code/Libraries/Source/WWVegas/WW3D2/light.cpp`; unresolved `PersistFactoryClass` constructor/destructor and `SaveLoadSystemClass::Register_Pointer`; current index `d1f046749a`. Raw evidence: `build/link-report.md` and `build/link-worker-20261026/`.
Completed: removed the unrowed Light factory instance, its Load/Save bodies and the unmatched `LightClass::Get_Factory` accessor. The existing `LightPersistFactoryClass::Chunk_ID` definition remains under its own name as an ordinary out-of-class member and byte-matches all six retail bytes. Three present-unmatched markers disappear. No row, pin, alias, storage substitute or code-generation flag changes.
Verification: final build verifies 40/40 rows across all 20 assigned units; changed-source frozen, EH, data, ledger and pin checks pass. The final expanded ordinary preview reports light LINKS; the 46-unit before/after intersection gains no blocker. Exact-name source search and all available cached census objects find no other light-factory consumer; 517 indexed object files are absent locally, so this is bounded evidence, not whole-game closure.
Remaining / next check: carry the removed-provider audit and the retained six-byte accessor into the next scheduled census; missing cached objects prevent a complete object-level consumer claim.
Clearance: cleared in ordinary-preview scope; census confirmation pending.
Census confirmation: awaiting the next normal census; no headline change claimed.


### LINK-054: pair sweep units instantiate unrelated whole containers

Status: Open (partial emission repair verified). Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected units: `StlSweepW4Rva004157BB.cpp`, `StlSweepW4Rva00540053.cpp` and `StlSweepW5Rva002CEFAA.cpp`, each with one rowed pair constructor, instantiate an entire hash_map or map. Raw before/after source-object inventories and the 40-unit preview are in `build/link-worker-w5/`; the full local handoff is `build/link-report.md`.
Completed: explicitly instantiate only each rowed pair constructor from the unchanged STLport `_pair.h`. All three rows remain exact; unused unresolved names fall from U4/U4/U3 to U1/U1/U1. The object inventories remove 373 distinct unrelated function names. The index reference graph has no retained node referencing the 362 names without alternate providers. The other 11 have alternate providers; two first-provider changes retain the identical retail-proven digests in current TeamFactory providers. The paired 40-unit previews keep the same 26 LINKS units and introduce no blocker. Frozen-file, EH, data, CSV and pin checks pass; all 53 assigned rows pass the ordinary byte gate.
Remaining / next check: each pair still calls an undefined placeholder element copy name. Retail destinations already have rows: 0x0041573F is `Rva0041573F` copy construction (67 B, `Rva0041573FCopy.cpp`); 0x0053FFCE is `Render2DSentenceClass::SentenceDataStruct::operator=` (61 B, `render2dsentence.cpp`); 0x000366F0 is `StringBase<char>::set` (132 B, `StringBaseNarrowCopySet.cpp`). Reconcile the pair/element operation identities and existing owners through the naming lane. In particular, assignment callees must not be renamed as constructors merely to satisfy the current sweep labels. The row names and pins are unchanged here.
Clearance: only the unused-emission subset is cleared in ordinary-preview scope; the three units remain blocked. Census confirmation pending.
Census confirmation: not claimed.

#### Additional constructor-only sweep cleanup, 2026-10-26

Status: Open; unused-emission subset cleared in ordinary-preview scope; census confirmation pending. Inspected revision: `58598f540fd3c84610304b3659ed382a4c05acca`; index `d1f046749a`, rules `retail-truth-4`.

Evidence / affected units: `StlSweepW4Rva0033A7DC.cpp`, `StlSweepW4Rva0056DDF5.cpp`, `StlSweepW4Rva004DA329.cpp` and `StlSweepW4Rva00501B33.cpp`. Completed: instantiate only the two rowed `pair` constructors and the default/copy `set` constructors from the unchanged STLport headers. All five rows remain exact. The paired preview changes the four units from U5/U5/U3-L1-S1/U3-L1-S1 to U1/U1/U1-L1-S1/U2-L1-S1 respectively. Object inventories remove 389 distinct emitted names without adding any definition. The index reference-edge audit finds no retained external referrer for the 383 names without alternate providers; the other six have alternatives, and no selected first provider changes. The same 70 of 91 current units preview LINKS before and after, including `StlportElementCopyCtorsW3G15.cpp` and `PickAndPlayUnitVoiceResponse.cpp`; no compared unit gains a named blocker. Raw inventories, reference audit, comparisons and all passing byte/declaration/EH/shadow-data/CSV/pin checks are under `build/c136-w4sweep/`, mapped by `build/link-report.md`.

Remaining / next check: the pair constructors call 0x002CF0F0 (`BfmeFixedStorage002CF0F0`, 24 bytes, FixedStorageCopyBFME2.cpp) and 0x00037050 (the private `StringBase<unsigned short>` copy, 66 bytes, StringBaseWideCopyCtor.cpp). Reconcile each key's actual identity and pair row with those existing owners; the earlier 0x0033A7DC wrapper failure was not repeated. The default set calls the rowed 51-byte `Rva004D9B18` constructor at 0x004D9B18, whose allocator/type contract still differs. The copy set's tree calls the 36-byte proxy constructor at 0x004FF55E and 115-byte tree-copy worker at 0x0050146E, which operates on 92-byte values rather than its eight-byte placeholder. The residual element destructors/comparators are emitted dependencies, not independently established missing native bodies. All four units remain blocked; naming/receiver/allocator reconciliation precedes another emission trial. No row, pin, alias, code-generation flag or shared header was changed.

Clearance: only the removed unrelated emissions are cleared in ordinary-preview scope; census confirmation pending. No whole-unit link or census gain is claimed.

### LINK-055: map and set sweep wrappers bind differently named existing tree workers

Status: Blocked on row and receiver identity reconciliation. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected units: `StlSweepW4Rva00464431.cpp` and `StlSweepW6Rva0016DEC0.cpp`. Raw retail calls and current-provider previews: `build/link-worker-w5/retail-probe-final.log`, `before-extra-providers.log` and `after-cohort.log`.
Completed: diagnosis only. The 29-byte map wrapper calls 0x00463E4D, already rowed as the 294-byte `Rva00463782::rva00463E4D` in `Rva00463E4DHintInsert.cpp`. The 21-byte set wrapper calls 0x0016D6A0, already rowed as the 108-byte `_Rb_tree<Gen_p12pod,pair<const Gen_p12pod,int>>::_M_find<Gen_p12pod>` in `RvaTreeFindGenP12pod00927790.cpp`. Both actual providers LINKS; the sweep units each retain U1/L1/S1. The latter provider compares three integer fields, which does not establish the sweep's string-containing record identity.
Remaining / next check: reconcile the existing row names, operation and receiver layouts through the naming lane before suppressing template bodies. Declaring the current pinned names alone cannot supply a provider; casting containers to other instantiations is not a repair. No source trial was applied and no missing match is claimed.
Clearance: pending.
Census confirmation: not claimed.

### LINK-056: pointer-copy sweep spelling selects memmove for a native string-copy wrapper

Status: Blocked on template identity reconciliation. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected units: `StlSweepW5Rva004F6FE1.cpp`; native 27-byte wrapper calls 0x004F6D2E. This address is the 29-byte `__copy_backward_ptrs<TreeHintRef00217D4C*,TreeHintRef00217D4C*>(...,__false_type const&)` row in `Rva004F6D2ECopyBackward.cpp`. Raw evidence: `build/link-worker-w5/retail-probe-final.log`, `before-extra-providers.log` and `after-cohort.log`; the earlier AsciiString identity lead is in re_attempts.log at 0x004F6D4B.
Completed: diagnosis only. The real worker LINKS in the paired preview. The assigned unit retains L1/S1 because its pointer-to-pointer `__true_type` specialization emits the trivial memmove path. No source edit or repeated AsciiString row admission was attempted.
Remaining / next check: reconcile the wrapper's existing template row with the nontrivial string element family, keeping the one-name/one-address distinction from the older AsciiString copy_backward attempt at 0x000B6631. Do not suppress the only current-name provider or reinterpret another instantiation to call the worker.
Clearance: pending.
Census confirmation: not claimed.

### LINK-057: valarray sweep copy reaches a record assignment instead of a gslice copy

Status: Blocked on row identity reconciliation. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected units: `stlport_valarray_int.cpp`, row 0x000B68F0 (27 B), named `gslice_array<int>` copy construction. Retail calls 0x000B43E5, the 47-byte `BfmeRecord000B43E5::operator=` in `Rva000B43E5Assign.cpp`. That worker copies three scalar dwords, a byte at +0x0C and a string at +0x10 through `StringBase<char>::set`; the native wrapper then copies +0x14. STLport gslice instead contains two owned valarrays.
Completed: diagnosis only. Supplying the actual assignment provider leaves the sweep at U1/L2/S1 while the provider LINKS. No valarray or shared-header trial was applied. Raw evidence: `build/link-worker-w5/retail-probe-final.log`, `before-extra-providers.log` and `after-cohort.log`.
Remaining / next check: identify and rename the wrapper and record operation together, including `StlHelperRva000B978A.cpp`, whose existing alias binds the sweep name. The exception/bad_alloc emissions are consequences of whole-valarray instantiation; removing those emissions alone cannot correct the gslice body identity. No new body or pin is supported by this call site.
Clearance: pending.
Census confirmation: not claimed.

### LINK-058: narrow istream find_if sweep row calls a record-construction worker

Status: Blocked on row identity reconciliation. Updated: 2026-10-26; inspected revision: `896af216804e`.
Evidence / affected units: `stlport_narrow_istream.cpp`, whose 30-byte `find_if` row at 0x006BE980 pushes an empty tag and calls 0x006BE8C0. The destination is the 115-byte `bfmeFillBE` in `Rva006BE840Construction.cpp`, which constructs 36-byte records with a string at +0x1C and flags at +0x20/+0x21. Raw evidence: `build/link-worker-w5/retail-probe-final.log`, `before-extra-providers.log` and `after-cohort.log`.
Completed: diagnosis only. The actual worker LINKS; the istream unit still has U1/L1/S1. The four other rows are small constructor/accessor shapes and do not prove the distant fill wrapper's find_if identity. The unresolved `ctype<char>::scan_not` comes from other emitted istream operations, with no corresponding reference in these five matched bodies. No missing retail address is inferred for that unused dependency.
Remaining / next check: recover the construction wrapper's real template/type spelling, preserving its four argument slots and the already rowed worker, then narrow the unrelated istream instantiation without losing any of the other four rows or their consumers. No new function body, shared-header change or pin was attempted.
Clearance: pending.
Census confirmation: not claimed.

### LINK-065: Zero Hour port units still define ZH bodies that BFME 2 rows elsewhere or lacks

**Status: Repair landed / awaiting census (DamageFX.cpp). Updated: 2026-10-26; inspected revision: 6533919013.**

- **Evidence / affected units:** `Code/GameEngine/Source/Common/DamageFX.cpp` (126 B, 3 rows: the
  DamageFX hashtable `clear`, `DFX::DFX`, `DFX::clear`) was ported verbatim from Zero Hour. Its
  unrowed ZH bodies held it out: `parseCommonStuff` and the four `DamageFX::parse*` (duplicates of
  rows in `DamageFXParseCommon.cpp`, calling static `INI::scanReal`/`scanIndexList` and
  `BitFlags<38>::s_bitNameList`, which BFME 2 does not provide), the veterancy-indexed
  `getDamageFXThrottleTime`/`getDamageFXList`/`doDamageFX` (BFME 2's versions take no veterancy and
  are rowed as 0x003605D5, 0x003605E3, 0x003608DF; unresolved `Object::getVeterancyLevel`), a
  wrong_selected `DamageFXStore::findDamageFX` (retail's symbol 0x00360966 is the
  `ArmorStore::findArmorTemplate` body) and its own `~hashtable` copy. Same cause as mesh.cpp's
  b57c128806 repair.
- **Completed:** 6533919013 removes those bodies (with four present-unmatched markers) and makes the
  hashtable destructor declaration-only so the retail /GX copy 0x0016DEE0 is kept. 3/3 rows exact;
  link_check (index d1f046749a) LINKS 0 -> 126 B; DamageFXParseCommon, Rva0033962FFinish,
  ArmorStoreCtor, Rva0016DEE0Cluster, ActiveBody, DamageFXRva003605AF, DamageFXHashSubscript,
  DamageFX_pairConstruct, DamageFX_hashtableNewNode and GameEngineInit still link.
  WW3D/WWLib ports, same test (2026-10-26, K1): `WW3D2/decalsys.cpp` (042fe08592, 0 -> 39 B)
  and `WWLib/wwfont.cpp` (2b3be7808e, 0 -> 33 B). Each carried one row (an empty
  `LogicalDecalClass` ctor; the header inline `TPoint2D<int>(int,int)`) beside Zero Hour bodies
  with no row anywhere in functions.csv (DecalSystemClass/DecalGeneratorClass/pool methods;
  WWFontClass) whose callees (ProjectorClass, `MatrixMapperClass::Set_Texture_Transform(Matrix4,float)`;
  `TRect<int>` members) have no BFME 2 provider. The link index showed no other object referencing
  a symbol only those units defined, so the bodies, their `??_H` anchors and `#pragma optimize`
  blocks went (39 present-unmatched markers, 6 pragma lines). `texproject.cpp` is the same case
  (one row, inline `MaterialPassClass::Set_Cull_Volume` 0x003B23A5, extern pointer anchor
  byte-verified 1/1 and LINKS 0 -> 10 B in preview) but is file-claimed by another seat; left for them.
- **Assault transport port cleanup (2026-10-26, parent `8738ddb103`):**
  [the paired current-object check](../reverse/attempt_support/assault-transport-port-cleanup-20261026.md)
  removes ten obsolete unrowed definitions from `AssaultTransportAIUpdate.cpp`,
  the unrelated free sleep helper and the unused array anchor. Both retained
  rows remain exact (75 bytes); ten unmatched exemptions and two optimization
  occurrences retire through the hatch tool. The unit loses its two command
  COMDAT blockers and previews LINKS, 0 -> 75 bytes against index `5ce093a71a`.
  Eight adjacent units remain LINKS in the paired ten-object preview.
  `Rva0026E836Derived.cpp` retains its three unresolved secondary-interface
  methods and two address findings in both cases. Scope cleared: this port
  unit's ordinary preview only; wider closure and census confirmation pending.
- **W3DDisplayString seed prerequisite (2026-10-26, inspected `71f28db691`):**
  [the native-layout handoff](../reverse/attempt_support/w3d-displaystring-consolidation-20261026.md)
  replaces its BFME 1 include stack with BFME 2 declarations before consolidation.
  The seed's three rows remain exact and ordinary preview preserves its existing
  146 authored bytes; no new conflicting COMDAT is emitted. All six candidates
  already preview LINKS for 1,577 authored bytes. The initial merge failed on
  incompatible string/class declarations, not missing rows. Constructor/destructor
  field/virtual names remain a separate reconciliation prerequisite; no linking
  gain or census confirmation is claimed.
- **Remaining / next check:** other ZH-port units (header comment "Ported verbatim from the
  Generals Zero Hour reference") whose U blockers are ZH-only callees: list each defined body,
  check whether its BFME 2 counterpart is rowed under another name or absent, and drop the ZH copy
  rather than providing the ZH callee. `hatch_baseline.tsv` can be tightened for the four removed
  DamageFX.cpp markers with `hatch_counters.py --update`.
- **Clearance:** current-object preview of DamageFX.cpp only.
- **Census confirmation:** awaiting.

### LINK-083: `StlSweepR3` units instantiate a whole algorithm or container over an opaque record whose retail callees are rowed under another type

**Status: Repair landed / awaiting census (7 units); family Open. Updated: 2026-10-26; inspected revision: bf8a1b680e parent d2bfe4bfad; index 5ce093a71a.**

- **Evidence / scope:** a `StlSweepR3Rva<rva>.cpp` unit holds one STLport row over an address-named
  record (`Rva<rva>Record`) and writes `template class` / `template void` instantiations to emit it.
  That emits every member and helper over the opaque record: the record's ctor/dtor/operator=/
  operator</operator==/hash are unresolved, and the emitted helpers (pinned in `symbols.csv` to
  retail addresses) are not retail's bodies. Retail's callees are already rowed, but under another
  type (the record's real element, or a placeholder method), so the names never line up.
- **Repair recipe:** define only the row as an explicit specialization (STLport 4.5.3's body)
  that calls the rowed callees by their own types (`reinterpret_cast` / pointer casts, as in
  LINK-035), then `template X::member();` where cl 7.1 would not emit it otherwise. Drop the pins
  for helpers the unit no longer emits and the `max<unsigned>` `#pragma optimize` block.
- **Completed (agent K9):**
  - 4ca752a55e `StlSweepR3Rva00218FC2.cpp` (`sort`, 67 B): calls 0x00218E09
    `__introsort_loop<Rva00218E09Record*, ..., less<>>` and 0x0021889A `Rva0021889AFinalSort`, both
    rowed in `GameFont.cpp`; 2 pins dropped. link_check with GameFont.cpp and MixFileCreatorParse.cpp:
    0 -> 67 B, partners link.
  - d5855a74e9 `StlSweepR3Rva00058A86.cpp` and `StlSweepR3Rva0002CCC3.cpp` (hash-set dtors, 57 + 67 B):
    call 0x00057FC1 (`clear` of the pair-keyed table over `Rva00057FC1Record`) and 0x002234FE
    (`clear` of `hash_map<AsciiString, AsciiString, rts::hash>`, INIMacroTable.cpp); 2 pins dropped.
    0 -> 124 B, and `AudioManagerAdjustPriorityAndVolume.cpp` (calls the 0x00058A86 dtor) 0 -> 43 B.
  - f29627cb3f `StlSweepR3Rva002BFA86.cpp` (`erase(const_iterator)`, 80 B): calls 0x00223149
    `Rva000427195::bucketIndex` and 0x002BF75A `Rva002BF75A::rva002BF75A`; 2 pins dropped; 0 -> 80 B.
    The same commit removes the unused `max<unsigned>` pragma blocks from 00058A86 and 0002CCC3.
  - Each `./build.sh` exact; RvaPairCopyCallFamily.cpp, PlayerXferStringMaps.cpp,
    Rva002BF75AFree.cpp, StlSweepR3Rva0002CD71.cpp, StlSweepR3Rva00057FC1.cpp, INIMacroTable.cpp
    still link. Preview total 0 -> 314 B; `hatch_counters.py --update` not run (9 pragma lines down).
  - 6edfe79e8d `StlSweepR3Rva003F318C.cpp` (`vector::operator=`, 206 B, LivingWorldRegionConnection
    elements): calls 0x003F2CD6 `vector<BfmeStringRecord000B9534>::_M_allocate_and_copy<LivingWorldRegionConnection*>`
    (protected: reached through a derived view), 0x00565A24 `ConnectionVec::Rva00565A24_ScrapStorage`,
    0x003F325A `Rva003F325ACopy`, 0x003F0CA1 `Rva003F0CA1_DestroyRange`, 0x003F29D2 `Rva003F29D2_CopyRange`
    (the two copy rows through tag-taking casts: retail pushes a fourth tag argument); 6 pins dropped.
    0 -> 206 B. Calling a declared-only explicit specialization of the real `<vector>` member template
    `_M_allocate_and_copy` ICEs cl 7.1 (C1001, P2 main.c:148) from any context (derived view, template
    view, own member, pointer-to-member), so the unit spells a minimal `_STL::vector` shape instead of
    including `<vector>` (Rva00569F0CAssign.cpp precedent); same bytes.
  - 827dd7e8a1 `StlSweepR3Rva00332613.cpp` and bf8a1b680e `StlSweepR3Rva00337D21.cpp` (`__introsort_loop`,
    135 B each): call 0x00331716 `__median<int, less<int>>` / 0x00335CFD `Rva00335CFMedian` (comparator
    as a fourth argument through a cast), the pivot copy ctors 0x00331962 `BfmeStringRecord00331962` /
    0x003371B1 `Rva003371B1`, 0x00331D10 / 0x00337655 `__unguarded_partition<S4SortElem12/20*>` (cast so
    the by-value pivot parameter is the copy ctor's record) and 0x0033254D `Rva0033254DPartial` /
    0x00337C55 `partial_sort<Rva003371B1*, Rva00337C55Less>`. The pivot record needs a destructor in
    scope (inline, or declared when rowed: 0x003372B7 `??1Rva003371B1`) or the `mov [ebp+0Ch],esp` EH
    spill of the argument slot disappears. Each drops a copy-ctor `/alternatename`, a `max<unsigned>`
    `#pragma optimize` block and 5 pins; 0 -> 135 B each. The five callees were already rowed, so no
    renames were needed.
  - Each `./build.sh` exact; provider units (Rva003F3F27.cpp, Rva003F2CD6.cpp,
    LivingWorldRegionConnectionHelpers.cpp, Rva003F325ACopy.cpp, stlport_int_algorithm_bodies.cpp,
    StringRecordCopyBFME2.cpp, stlport_introsort_loop_s4sortelem12_002e1b60.cpp, Rva0033254DPartial.cpp,
    stlport_sort_s4sortelem20.cpp, Rva00335CFMedian.cpp, Rva003371B1Copy.cpp, Rva003371B1Dtor.cpp,
    stlport_unguarded_partition_s4sortelem20.cpp, stlport_partial_sort_rva00337c55.cpp) still link.
    Preview total for the family now 0 -> 790 B.
- **Remaining, same shape (inspected 2026-10-26, no edit):** `StlSweepR3Rva0051F7AD.cpp` (operator=
  over 12-byte `ProductionPrerequisite::PrereqUnitRec`; callees 0x004EE233, 0x004EE540, 0x0051EC31,
  0x0052C37A, 0x004EE1E2 all rowed; draft follows the 003F318C shape) and `StlSweepR3Rva003F40EF.cpp`
  are file-claimed by another seat (StarkillerHDX, link seat w6). `StlSweepR3Rva00627B10.cpp`
  (`__make_heap`) likewise claimed. `StlSweepR3Rva00212A16.cpp` (hashtable resize/insert, 68 B) not
  yet inspected. `StlSweepR3Rva000B0298.cpp` is a different cause: 0x000B0298 carries two rows
  (`?rva000B0298@Rva000B0298@@QAEXXZ` in Rva000B0298Clear.cpp, which VectorOverflowRva000B059B.cpp
  calls, and this unit's `vector<Rva000B0298Record>::_M_clear`, which nothing calls); a duplicate-row
  question (LINK-060), not this recipe.
- **Related leads not done:** `Rva008312E0StringReplace.cpp` / `Rva008314E0StringReplace.cpp`
  (/Od /Ob1) emit `erase`/`replaceBase` COMDATs that retail calls out of line at 0x00012150
  (`basic_string<char>::erase`) and 0x0002A610 / 0x0002A730 (`BfmeStrV24::bfmeReplaceV24`, last
  parameter spelled `int` where the caller passes a tag reference). Calling those rows by type means
  stubbing `basic_string<char>` in a unit that stubs its own STL; frame-slot effects under /Ob1 untested.
- **Census confirmation:** awaiting the next census.

### LINK-069: the four-byte merge sweep combines a string buffer with opaque record helpers

Status: Blocked on algorithm, element and provider-name reconciliation. Updated: 2026-10-26; inspected revision: `58598f540fd3c84610304b3659ed382a4c05acca`.

Evidence / affected unit: `StlSweepW4Rva004F8C16.cpp`, all three rows byte-exact against the current inputs. Retail's 131-byte wrapper calls 0x004F77AD (51-byte temporary initializer) and 0x004F77E0 (33-byte destructor), rowed as `Rva004F60AA` members in Rva004F60AAInit.cpp; it calls 0x004F840B (303-byte `__merge_without_buffer<TreeHintRef00217D4C,...>`, PAUTreeHintRef00217D4CRva004F9565.cpp) and 0x004F853A (279-byte `__merge_adaptive<AsciiString,...>`, stlport_stable_sort_asciistring_o1.cpp). The sweep's distinct `Rva004F8C16Element` names leave U4/L3/S3. Raw retail references and existing row homes: `build/c136-w4sweep/native-evidence.log` and `provider-rows.json`; current-provider before/after previews and full gates are mapped in `build/link-report.md`.

Completed: diagnosis and unchanged byte verification only. No source trial repeated the documented TreeHintRef/AsciiString helper-spelling conflict or copied the existing providers' incompatible function-pointer adapters. Remaining / next check: reconcile the native string/owning-handle element, buffer operations, comparator and the already rowed algorithms together. Suppressing the sole current-name copies would leave unresolved names; changing the wrapper's template spelling requires ledger work outside this seat. No missing native body, independently proven new fold pin or shared-header change is established by these calls.

Clearance: pending. Census confirmation: not claimed.

### LINK-085: GUI phase constructors emit a forwarding record destructor instead of its native owner

Status: Open; record subset cleared in ordinary-preview scope; census confirmation pending. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.

Evidence / affected units: `GameClient/GUI/Rva0057621ACtor.cpp` and `Rva005776A7Ctor.cpp` use the same 16-byte record as `Common/Rva00576C4BDtor.cpp`. Retail cleanup entries 0x0079B3ED and 0x0079B6D6 call 0x005CD7DA directly. That complete 39-byte destructor is already rowed as `??1Wrap2000576C4B@@QAE@XZ`; it checks byte +0xC, resolves pointer +4 and invokes slots 6 and 1. The old holder emits a forwarding destructor and references the undefined `??1Rva005CD7BD`.

Completed: bind both existing record members to that rowed destructor with a declaration, retaining their inline construction and layout. All 10 constructor-unit rows and both EH graphs remain exact; frozen-file and shadow data checks pass with zero data findings. Each constructor loses U1/L1/S1. The paired 37-unit preview preserves all 28 LINKS units and adds no named blocker; the final 39-unit current-provider preview has 30 LINKS units, including both added unchanged hero providers. Raw receipts and the complete scope are in `build/c136-gui-w2/` and `build/link-report.md`.

Remaining / next check: planning remains U10/L2 and retreat remains U4/L1. Their primary native translator tables have 26 slots, while the private `Gen_uwm_00429191` and `Rva005776A7Interface` views omit the actual translator/destructor contract. Planning's secondary base is five pure-call slots, and its derived table contains five rowed adjustors; replacing only the base declaration would leave derived overrides unresolved. Reconcile the full interfaces with `UserInputTranslator`, the named phase units and the already linking destructor owners. The retreat destructor is already rowed as `Rva005770F7`; its owning-pointer cleanup is the 30-byte method at 0x0057702E. Planning's listener/base/owned-pointer cleanup spellings and duplicate constructor ownership also remain. No new function body, pin, marker, row or compiler flag was added.

Clearance: only the shared record binding is cleared in ordinary-preview scope; census confirmation pending. Neither assigned constructor now LINKS. Census confirmation: not claimed.

### LINK-086: ArmyHeroIcon constructors and lifetime owners disagree on class and virtual signatures

Status: Blocked on class and table reconciliation. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.

Evidence / affected units: `LivingWorld/InGameUI/ArmyHeroIconCtor.cpp` remains U10 and `Rva005E39F3Ctor.cpp` remains U7 against index `d1f046749a`, with current `Rva005F4179Dtor.cpp`, `Rva005F422CDtor.cpp`, `StrategicInGameUIArmyHeroIcon.cpp` and `StrategicInGameUIArmyUnitIcon.cpp`. Native tables 0x00879448, 0x00879468, 0x00877C50 and 0x00877C74 each have eight slots. The 40-byte hero destructor at 0x005F422C and 44-byte details destructor at 0x005E3A76 are already rowed under those address-derived class names. The real hero clip factory at 0x005F43B4 returns `HeroClipReference` from `AptMovieClipFrame *`; the second constructor unit declares a void return from `ArmyHeroIconMovieClip *`. Its slot-3 return type also differs from the rowed `TreeHintRef00217D4C` result.

Completed: diagnosis only; all 12 assigned rows pass the byte gate. The full table-slot/owner evidence and provider previews are in `build/c136-gui-w2/native-tables.log`, `native-all.log`, `final-all-with-providers.log` and `build/link-report.md`. The anonymous `HeroDetailsPortion` emission requires the same details owner, rather than another local implementation.

Remaining / next check: reconcile the destructor owner to `StrategicInGameUI::ArmyHeroIcon` and share the full eight-slot ABI across its lifetime, constructor and derived details views. Base slot 3 reaches the existing 18-byte empty-help row 0x001524CA; slot 4 reaches 0x005F41AF; slots 6 and 7 reach 0x005F3FF4 and 0x005F3F6B. Details slots 1, 5, 6 and 7 reach the already rowed forwarders 0x005E3D84, 0x005E5237, 0x005E4663 and 0x005E3ECB. Preserve hidden-result signatures and vtordisp thunks. Replacing real member calls with these placeholder names or changing ledger identities was unavailable in this seat, so no partial table trial was retained.

Clearance: pending. Census confirmation: not claimed.

### LINK-087: ControlBar tooltip adapter slots belong to several existing row identities

Status: Blocked on adapter identity and virtual signature reconciliation. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.

Evidence / affected unit: `GUI/ControlBar/ControlBarRva004C1B60_Rva00405DBC.cpp` remains U5 against `d1f046749a` with all five current slot providers. The matched 129-byte method at 0x00405DBC stores native table VA 0x00C38970, rather than the stale donor address in its comment. Its slots after the deleting destructor are 0x00405D7C (64-byte `Rva00405B60::clone` returning `auto_ptr<BfmeThingGX>`), 0x004059BE (17-byte `Rva004C1160::get`), 0x00405E3D (3287-byte `OldSchoolHelpBoxContentSource::createContent` returning a counted help result), 0x004059CF (30-byte comparator) and 0x004059F6 (38-byte ID getter). The private view declares all five as `void()`.

Completed: diagnosis only; all four assigned rows pass the byte gate. Every listed slot already has an owner, and every inspected provider remains LINKS. Raw evidence: `build/c136-gui-w2/native-all.log`, `native-tables.log`, `final-all-with-providers.log` and `build/link-report.md`.

Remaining / next check: reconcile the adapter constructor row and these five method owners to the native tooltip content-source class and signatures together. Changing only method labels cannot bind these different class/signature names. No new native match or independent fold pin is established. Clearance: pending. Census confirmation: not claimed.

### LINK-073: LivingWorldManager constructor uses opaque names for existing container and lifetime owners

Status: Blocked on constructor-class and member-type reconciliation. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.

Evidence / affected unit: `LivingWorld/LivingWorldManagerCtor.cpp` remains U5 against `d1f046749a`. Native calls reach the existing 31-byte `hash_map<int,Rva00213E11Element>` constructor at 0x00213E11 and 25-byte map constructor at 0x0033C432; the private member types instead reference `Rva002130CA`, `Rva00212379` and `Rva00211FA3` constructors. Its 0x0076DE66 cleanup reaches the seven-byte 0x00210CC5 setter under a destructor spelling. Native primary table slot 0 reaches the deleting destructor whose 691-byte lifetime owner is already `LivingWorldManager` at 0x00214405, while the constructor row retains `Rva0022B12DSubsystem`.

Completed: diagnosis only; all 19 assigned rows pass the byte gate. The named lifetime owner, both container providers and the setter provider remain LINKS in the same current-provider preview. Raw native calls and pin/owner lookups are in `build/c136-gui-w2/native-all.log`, `dependencies.log` and `final-all-with-providers.log`.

Remaining / next check: rename/reconcile the existing constructor row to `LivingWorldManager`, establish the actual container member types with their destructor owners, and reconcile the listener lifetime with the existing setter owner. Existing pins do not supply definitions to the census; adding another pin cannot resolve these names. No missing native body is established. Clearance: pending. Census confirmation: not claimed.

### LINK-088: PartitionManager keeps the wrong isDisguised copy before its exact owner
Status: Blocked on shared declaration/emission reconciliation. Updated: 2026-10-26; inspected revision: 2a45addda1806342ac5c52757f63be902dcd428e.
Evidence / affected units: `PartitionManager.cpp`, `StealthUpdate.cpp` and `WeaponSet.cpp` select `?isDisguised@StealthUpdate@@QBE_NXZ` from PartitionManager. The rowed owner at 0x0004D65B in StealthUpdate.cpp emits retail's nine-byte body; the first copy uses the older UpdateModule layout and a different instruction shape. All six sources spelling the member were checked together.
Completed: a trial of the existing `/Ireference/shims/dockupdate` include directory keeps all four verified PartitionManager rows exact and corrects the field placement, but leaves the selected-copy blocker. The unit's existing optimization context still emits a different body. The trial was reversed by removing only that include-directory edit; the restored byte gate and six-source preview reproduce the baseline. All three already-linking consumers stay LINKS throughout. Raw logs: `build/c136-logic/stealth-before.log`, `stealth-after-trial.log`, `partition-build-trial.log`, `stealth-restored.log` and `partition-restored-build.log`.
Remaining / next check: reconcile the shared StealthUpdate declaration so this early emitter can bind the existing exact owner without emitting its stale copy, while preserving other inline uses and every caller row. A shared-header edit, an optimization-flag change and a renamed helper were outside this seat. Do not repeat the include-directory-only trial.
Clearance: pending; no production source change is retained for this cause.
Census confirmation: pending; no gain claimed.

### LINK-089: SupplyTruckAIUpdateCtor's private interface slots disagree with native callbacks
Status: Blocked on interface and provider-name reconciliation. Updated: 2026-10-26; inspected revision: 2a45addda1806342ac5c52757f63be902dcd428e.
Evidence / affected units: `SupplyTruckAIUpdateCtor.cpp` remains U9 against index `d1f046749a`. Its constructor and destructor anchor the interface table at RVA 0x00852F38. Projecting the current private declaration onto that native table maps its gainOneBox slot to the rowed loseOneBox worker at 0x004A6E8E and its getActionDelayForDock slot to the unrelated byte setter at 0x00210CD3. The SupplyTruckStateMachine owner already records later native interface offsets for the force-state accessors. Equal calling-sequence sizes do not establish the current slot names or signatures.
Completed: every assigned row passes the combined byte gate, and the current native row providers were included in the paired preview. No source or ledger change was attempted. `build/c136-logic/native-references.log` labels table projections separately from direct calls and lists the exact row names and homes; `weather-native.log` also preserves the raw native table bytes.
Remaining / next check: recover the complete interface order and argument types, then reconcile the existing rowed workers and folded getters under supported real names. Do not bind these current slots to address placeholders or propose pins from the mismatched projection alone.
Clearance: pending.
Census confirmation: pending; no gain claimed.

### LINK-090: the terrain bib wrapper calls a row identified as LinearCampaign

Status: Blocked on wrapper identity. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.
Evidence / affected unit: `Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DTerrainVisual.cpp`, the existing 13-byte `removeAllBibs` row at RVA `0x001EC981`. Its REL32 at offset `+0x8` targets RVA `0x001EC3B5`, which is already the 648-byte `LinearCampaign::onCurrentMissionWon` row in `Code/GameEngine/Source/GameLogic/System/LinearCampaign/LinearCampaignOnMissionWon.cpp`. That row's evidence identifies the WorldBuilder campaign twin, carry-over units and player upgrades. Raw native relocation and row evidence: `build/link-worker-w5-c136/native-refs.log` and `native-target-owners.json`.
Completed: inspected the current wrapper object and native destination without editing either unit. The unresolved `BaseHeightMapRenderObjClass::removeAllTerrainBibs` spelling is not evidence of an unimplemented body at this target.
Remaining / next check: establish the wrapper's actual campaign receiver and purpose before any row/name correction. Do not bind this terrain method to the existing campaign spelling merely because the call bytes agree. The separate water-transform row and the unit's unrowed terrain ports do not settle that identity.
Clearance: pending. Census confirmation: not claimed.

### LINK-092: the Money vector row actually copies a different 36-byte record
Status: Open. Updated: 2026-10-26; inspected revision: 2a45addda1806342ac5c52757f63be902dcd428e.
Evidence / affected units: `MoneyVectorPushBack.cpp` reaches 0x00063BE4 and 0x006BF5E0. Their current owners are BfmeStringRecord00063BE4's copy constructor in `StringRecordCopyBFME2.cpp` and BfmeVecBE's overflow in `Rva006BF5E0Overflow.cpp`. The native call offsets, complete owner extents and current names are in `build/link-worker-w6/row-reference-witnesses.log`; `paired-before.log` and `paired-after.log` include both current providers.
Completed: diagnosis only; no source edit. The record copy is seven dwords, an AsciiString and two bytes, as its retail-proven owner records. It is not the engine's small Money value. Including the canonical Money header would therefore replace this false view with a different native type and break the row.
Remaining / next check: reconcile the vector row and its consumers onto the existing 36-byte record family through the naming lane, preserving the real Money users separately. The three unresolved Money virtuals come only from the wrong whole-vector instantiation; they do not establish missing native Money methods. No new match or independently proven fold pin was established.
Clearance: pending.

### LINK-093: stale callee views and superseded unrowed reconstructions

Status: Open for the units; six unresolved-name repairs cleared in ordinary-preview scope. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.
Evidence / affected units: `Code/GameEngine/Source/Common/VslotSmallBodiesAG_Rva00131CF2.cpp` and `Code/Libraries/Source/WWVegas/WWLib/Rva0020EE29Clear.cpp`. Current retail call targets, source owners and ordinary previews against index `d1f046749a` (`retail-truth-4`) are retained in `build/c136-common2/`; the full mapping is in `build/link-report.md`.
Completed: the Vslot unit uses the rowed integer predicate at 005D4E6F while preserving its native low-byte test, and uses `Rva00328A83PtrChaseField::get` for the pointer-valued dword at 00328A83. Its unresolved names decrease from ten to eight with all eleven rows exact. The clear unit uses the existing `Rva003EF14A::rva003EF1B8` and `Rva003F3F27::rva003F3F27` declarations. Two unused, unrowed reconstructions and their `present-unmatched` markers are removed: 0020F685 already belongs to Rva002B7B71DeleteAll.cpp and 00210F09 to Rva00210F09Delete.cpp. Its unresolved names decrease from twenty-three to nineteen, with all fifteen rows exact. No row, pin, real name, shared header or code-generation flag changes.
Verification: paired previews over 48 Vslot-related units and 66 clear-related units add no named blocker and preserve every previously clean unit (`vslot-scope-before.log`, `vslot-scope-after.log`, `clear-bounded-before.log`, `clear-bounded-after.log`, `comparison.log`). `LivingWorldManager_SetUpRegionEffectsManager.cpp` is absent from the published index; its one row verifies and its current COFF references neither removed definition (`unpreviewable-build.log`, `provider-details.log`). The two edited units pass byte, declaration, EH and shadow data checks; CSV and pin consistency checks pass. Raw final receipts are listed in the handoff.
Remaining / next check: the Vslot unit retains two empty-fold provider names, three unowned field tables, and bool/thiscall spelling prerequisites at 00130FCE, 003FF145 and 0023C7F5. The clear unit retains nineteen unresolved names and its existing hash-table `_M_find` COMDAT conflict. Reconcile those actual owners, container identities and incoming-register contracts rather than introducing another alias. Both whole units remain blocked.
Clearance: the six named unresolved blockers are cleared in ordinary-preview scope; census confirmation pending. No newly linking assigned unit or headline gain is claimed.
Census confirmation: pending.

### LINK-096: consolidation guard retains a private constant after its seed references change

Status: Blocked on a separate LinkGuard verifier repair. Updated: 2026-10-26; inspected revision: `71f28db691`.
Evidence / affected units: [W3DDisplayString native-layout handoff](../reverse/attempt_support/w3d-displaystring-consolidation-20261026.md), provider index `5ce093a71a` (2026-10-26 19:02).
Completed: the seed's BFME 1 includes are replaced by BFME 2 declarations; all three rows byte-verify, data_check has no findings, code identity has two owner references and no wrong bindings, and ordinary preview preserves 146 authored bytes with no new conflicting COMDAT. The supported merge still refuses the seed because its private str_RV empty-character COMDAT disappears. Its only discardable-COMDAT index edge is from the removed str_RV helper, itself unreferenced; the old getWidth root reference is rewritten to the canonical shim constant at the same retail address. The guard retains the historical aggregate reference set. No merge or guard workaround was applied; re_log records the false rejection.
Remaining / next check: authenticate per-object roots, reproduce and repair the retained-reference analysis in a separate verifier commit with regression/exploit tests, then retry the supported merge. Constructor/destructor declaration reconciliation remains independently necessary.
Recovery publication audit (2026-10-27): the outgoing dry-run gate passes 72/72 function rows, three data rows and nine EXACT EH graphs across five sources. The shadow link batch comparison is inconclusive: the index predates the outgoing base and five objects lack current receipts (first Credits.cpp). No selected-provider or lost-byte verdict is available; carry this input-freshness scope into the next census.
Clearance: only the seed prerequisite's ordinary-preview scope; consolidation remains blocked.
Census confirmation: not claimed; all six original units already preview link cleanly.

### LINK-094: GUI helper cleanup would remove live unrowed providers

Status: Blocked on provider ownership and existing row placement. Updated: 2026-10-26; inspected revision: `2a45addda1806342ac5c52757f63be902dcd428e`.
Evidence / affected units: `OptionsMenu.cpp`, `WOLGameSetupMenu.cpp`, `OptionPreferences_getLANIPAddress.cpp` and `LanGameOptionsMenu.cpp`, checked against ordinary-preview index `d1f046749a`. Raw trial sources, COFF dependency audits and previews are retained in `build/c136-common2/`; `build/link-report.md` maps the files.
Completed: both cleanup trials were fully reversed. Retaining OptionsMenu's existing slider helper as ordinary C++ preserves its 27-byte row and previews LINKS, but removes the sole `EnumeratedIP::getIPstring` provider used by the currently linking OptionPreferences_getLANIPAddress.cpp. Retaining WOL's existing combo-box helper preserves its 23-byte row but introduces a duplicate of that helper and removes the sole `gameAcceptTooltip` provider used by LAN options. The COFF audits identify these consumers; their scans also report missing cached objects, so no complete whole-tree dependency claim is made. All assigned rows pass again with both original files restored.
Remaining / next check: establish explicit ownership and correct native names for the retained inline providers, and the proper home/emission policy of the gadget helpers, before pruning the imported menu code. Do not repeat the whole-port removal or retain a helper through a dummy call/data anchor. The remaining LAN and InGameUI port/header dependencies are listed in the handoff, without a claim that they need new matches.
Clearance: pending; no source edit retained for these menus.
Census confirmation: not claimed.

### LINK-080: a folded getter whose only providers were Zero Hour inline copies
Status: Repaired for `Weapon_getName_Thunk.cpp`. Updated: 2026-10-26; inspected revision: df9e34ca31.
Evidence / affected units: retail 0x0028F940 (28 B) is `WeaponTemplate::getName`, called by `Weapon::getName` (0x0028F95C). Its body returns `AsciiString::TheEmptyString`; /OPT:ICF folded it with `NetCommandMsg::getContentsAsAsciiString`, so it has no row of its own and was only a symbols.csv pin with no fold-proof. Nothing defined the name except Zero Hour's `GameLogic/Weapon.h` inline `return m_name;`, emitted by `Weapon.cpp`, `DumbProjectileBehavior.cpp` and `DeliverPayloadAIUpdate.cpp` (all "wrong"), so the link kept a non-retail copy.
Completed: df9e34ca31. The thunk unit's WeaponTemplate view defines getName with the retail body and the pin is re-admitted with `fold-proof=` naming it. New TU-scoped shim `reference/shims/weapon_outofline/GameLogic/Weapon.h` (Zero Hour's header, getName declaration only) is put ahead of `zh_outofline` in the three units. It is a separate directory because `AssistedTargetingUpdate.cpp` lists `zh_outofline` ahead of `update_modules_bfme2`, whose own Weapon.h it needs. build.sh 207/207 rows over the 47 zh_outofline units; link_check: `Weapon_getName_Thunk.cpp` 0 -> 26 B, nothing dropped.
Remaining / next check: the same pattern may hold for other Zero Hour inline getters whose retail body is a release-build stub folded elsewhere. Note: the build object store restored a stale object after the new shim directory shadowed a header (its receipt does not see a newly shadowing file); rebuild such changes with `BFME_OBJSTORE=off` after deleting the units' `.deps.json` sidecars.
Clearance: preview (link_check on current objects). Census confirmation: pending.

### LINK-095: generated EH funclets whose parent TU emits an unpinned or wrong dtor callee
Status: Open. Updated: 2026-10-26; inspected revision: the 44-funclet repoint commit.
Evidence / affected units: `Code/gen_small/uw_gen_*.cpp` never links (its
`gen_uw_ext`/`gen_uw_sink` are undefined by design), so each funclet must move
to its matched parent's `$L` label. In `uw_gen_003.cpp`, all 69 funclets have a
parent whose EH graph is EXACT and an emitted label that matches retail with
relocations masked. Unmasked, 25 fail the byte verify. In 23, the parent TU's
inline element dtor has no pin or row, e.g. `??1WeightedModel@@QAE@XZ`,
`??1ObjectTOCEntry@@QAE@XZ`, `??1crateCreationEntry@@QAE@XZ`,
`??1QuantityModifier@@QAE@XZ`, the `pair<const AsciiString, TreeHintPayload*>`
family and placeholder `??1Rva*` elements. In 2 (`Rva00426F17Xfer.cpp`,
`Rva0042700FParse.cpp`), the dtor resolves to a different body than retail's
rel32. The names are in the `blocked` rows of `reverse/re_attempts.log`.
Completed: "Repoint 44 uw_gen_003 funclets to their EXACT EH parents" moved the 44 verified funclets (414/414 across 41
sources, EH verify EXACT 84) and left the 25 in `uw_gen_003.cpp` unchanged.
Remaining / next check: name or row each missing element dtor at the address
retail's funclet jumps to (`tools/pin_admission.py --add`, or a real row). For
the two wrong-callee units, align the element type with retail's dtor. Then
re-run the repoint with an unmasked `./build.sh` before staging. A relocation-
masked sweep alone over-reports.
Clearance: pending.
Census confirmation: awaiting.

**uw_gen_009 parent ownership cleanup (2026-10-26):**

Status: Open, partially cleaned. Updated: 2026-10-26; inspected revision: `39e752ed5b`; census index `5ce093a71a` (2026-10-26 19:02).

Evidence / affected unit: `Code/gen_small/uw_gen_009.cpp` has 113 unresolved
`Gen_uw*`, `gen_uw_ext` and `gen_uw_sink` names in the current-object preview.
Its source is generator-owned. Retail FuncInfo/unwind maps identify parent
candidates, but an EXACT EH graph masks external relocation sites and does not
by itself establish the destructor callee identity. Detailed target facts and
verification are in `reverse/attempt_support/uw009-parent-repoints-20261026.md`.

Completed: four eight-byte water parameter cleanups now use their matched
WaterRenderObjClass parents. Their two emitted handle destructors were admitted
as complete byte-and-relocation twins of the existing 0x005F8F96 owner, without
new pins or source changes. Four redundant asset-manager scaffold rows were
removed in favor of existing C++ owners (LINK-060). Generated ownership falls
from 181 rows / 1,733 bytes to 173 / 1,645; byte coverage is preserved. Water's
21 rows and assetmanager's 12 rows pass, with six EXACT parent EH graphs and
strict-current receipts. Both parents remain LINKS in the paired preview.

Remaining / next check: the harness still has 113 unresolved names. Six trial
repoints from Rva000C38F8Ctor.cpp were reverted because their
`vector<PlayerAITypeEntry>` destructor is unresolved; retail calls the existing
`vector<AsciiString>` destructor at 0x0002CC70. Establish the element cleanup
identity before retrying those six rows; do not infer a destructor fold from
the common vector constructor. Repoint other generated rows only after both
parent EH placement and complete resolved funclet bytes pass. The initial
0x0075C9DA lead was left untouched because its candidate parent files were held.

Clearance: only the four water row bindings and four redundant asset-manager
claims are resolved; whole-unit closure remains open. Census confirmation:
awaiting measurement; no headline gain claimed.

### LINK-096: placeholder `Rva0015E640` hid `SimpleDynVecClass<Vector3>` from its copy-ctor consumers
Status: Repair landed / awaiting verification for the WW3D2 subset; Blocked for
`V3PolyDeferredCopyCtors2.cpp`. Updated: 2026-10-26; inspected revision: `7e7a10015d`
(index 2026-10-26 19:02 at `5ce093a71a`).
Evidence / affected units: the copy ctor 0x0015E640 and implicit assignment
0x0015E670 were rowed as `Rva0015E640`, whose private vptr classes left
`??1Rva0015E640Base`/`??1Rva0015E640` unresolved in
`V3PolyDeferredCopyCtors2.cpp`, `Rva001684D6Copy.cpp` and `Rva001684D6Assign.cpp`.
The body installs vtables 0x007C6F44/0x007C6F50, whose slots are the rowed
`SimpleVecClass<Vector3>`/`SimpleDynVecClass<Vector3>` deleting dtors and `Resize`
(target fact). The 39-byte copy ctor at 0x00741BF0, formerly rowed as the Vector3
instance, installs 0x007D71C8/0x007D71D4, the Vector4 vtables (slots 0x1A7FF0,
0x1AC6C0). It is `SimpleDynVecClass<Vector4>`'s and is emitted by `streak.cpp`.
Completed: the consumers use the real `SimpleDynVecClass<Vector3>`. segline.cpp owns
0x0015E640/0x0015E670 under the real names; the placeholder rows have tombstones.
0x00741BF0 is rowed as the Vector4 copy ctor. All 30 sources using the template
pass (675/675 rows). Without the `SimpleVecClass<Vector3>`/`SimpleDynVecClass<Vector3>`
lines, the DIR32 consistency check passes over the same rows, so the whitelist
drops both. Preview: `Rva001684D6Copy.cpp`, `Rva001684D6Assign.cpp`, `segline.cpp`
and `streak.cpp` link (LINKED 9,905 -> 9,944).
Remaining / next check: `V3PolyDeferredCopyCtors2.cpp` still lacks
`??1Rva0028C62B@@UAE@XZ` and `??1Rva0028F68F@@UAE@XZ` (DamageInfo class
reconciliation, LINK-004). `reverse/data_ledger.csv` still lists the old vtable
alias names until it is next regenerated.
Clearance: pending.
Census confirmation: awaiting the next census.

### LINK-066: legacy Zero Hour `GameWindowManager` bodies kept `GameWindowManager.cpp` from linking
Status: Repair landed / awaiting verification. Updated: 2026-10-26; inspected revision:
`9f685c7696` (index 2026-10-26 19:02 at `5ce093a71a`).
Evidence / affected units: `Code/GameEngine/Source/GameClient/GUI/GameWindowManager.cpp`
owns two rows, `PassSelectedButtonsToParentSystem` (0x002C0978) and
`PassMessagesToParentSystem` (0x002C09DF). It also carried 23 verbatim Zero Hour
member bodies (ctor, dtor, the `gogoGadget*` builders, `winCreate`, `initTestGUI`, ...)
under `present-unmatched` markers. They emitted the class vtable and referenced
`GameWinDefault*`, `winDrawImage`, `winFillRect`, `winOpenRect`, `winDrawLine`,
`winFontHeight`, `winFormatText`, `winIsDigit/Ascii/AlNum`, `winCreateFromScript`,
`GameWindow::winSetOwner` and `GameWindow::winGetTooltipFunc`. None of these resolves
under a real name today, and the unit selected the wrong `registerTabList`. The
retail `W3DGameWindowManager` vtable 0x007C7C90 has no `winIsDigit/Ascii/AlNum`
slots (target fact). Slots 66-69 are the placeholders `Rva00314AE0`, `Rva00314B28`,
`Rva00314B75` and `Rva00314BC9` (`GameWindowRva00314AE0.cpp`); by Zero Hour
`GameWindowGlobal.cpp` shape they are probably `winDrawImage`, `winFillRect`,
`winOpenRect` and `winDrawLine`. Slot 73 (`Rva00314C93`, `VslotSmallBodiesB.cpp`)
is probably `winFormatText` (structural inference, a naming lead).
Completed: deleted the unmatched bodies, their markers and `testGrab`. Rowed owners got
pointer comments (`winCreate` in `GameWindowManager_dumpWindow.cpp`, and
`gogoGadgetListBox`/`ComboBox`/`TextEntry` in their own units). Also dropped the
`??_H` anchor block: the unit still emits `??_H@YGXPAXIHP6EPAX0@Z@Z`, byte-identical
to retail 0x00001423 (34 bytes compared). 25 hatches retired (23 `present_unmatched`,
2 `pragma_optimize`). Both rows pass `./build.sh`, and `find_declared_unmatched.py`
is clean. Preview: LINKS, LINKED 0 -> 151.
Remaining / next check: rename the four vtable-slot placeholders above once their
bodies are checked against Zero Hour.
Clearance: pending.
Census confirmation: awaiting the next census.
