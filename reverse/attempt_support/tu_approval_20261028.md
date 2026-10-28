# TU approval: what blocks the 24,520 proposed rows (2026-10-28)

Seat halilkkaya-tua1, base `8113c47024`, map rebuilt in memory by
`tools/tu_map.py`'s `build()` from that tree (never written). All counts are
code rows.

## How a row becomes approved (tools/tu_map.py)

A row is approved only when its TU is *anchored* (its main address cluster holds
a row whose own F, Z, S or W evidence names that TU), the TU is *contiguous* (no
row that could be approved for another anchored TU sits inside its span), and the
row itself is assigned by F/Z/S/N/U (or C between two approved rows) without
contradicting its own F/Z/S. W (a WorldBuilder lead's `__FILE__` path) anchors
only when it names exactly the path the row's own N hint gives
(`dirname(source)/Class.cpp`), and never on a row whose name came from that lead
(`Wself`: notes cite WorldBuilder, or the class was taken from the lead).

Seat-level levers are therefore: a real name with a Zero Hour definition (Z/S), a
corrected identity for a row that breaks contiguity, and nothing else. F is fixed
by the retail image; W is fixed by `wb_name_leads.csv`; N follows our directory
layout, which `rename.py` cannot change (cross-directory moves are refused).

## Landed this pass

`f0747c9ba2` Correct the ScriptConditions destructor identity (was ~CDManager).
Retail facts: vftable 0x00835B38 is stored by the matched ??0ScriptConditions
0x003E5513; slot 9 is the matched ScriptConditions::reset 0x003E3C66; slot 0 is
0x003E5DCD, which calls 0x003E5525; 0x003E5525 stores 0x00C35B38, calls reset,
stores 0x00C35AE0 and calls ~SubsystemInterface. Retail CDManager uses vftable
0x00C3C5DC. Effect (rebuilt map): ScriptConditions.cpp 0 -> 254 approved rows
(`tu_skeleton.py --plan`: 254 rows, 93 donor files, 7 mixed, 0 refused);
AudioEventRTS.cpp 66 -> 0 and CDManager.cpp 3 -> 1 (below); net +186.
`link_check`: ScriptConditions_ctor.cpp LINKS, 18 -> 119 bytes. One
/alternatename hatch retired.

Knock-on to repair next: with the destructor gone, CDManager.cpp's main cluster
is `?getPath@CDDrive@@UAE?AVAsciiString@@XZ` at 0x002D9BA6 (Z=CDManager.cpp), a
27-byte by-value AsciiString getter of member +0x1C inside AudioEventRTS.cpp's
span (0x002D954D..0x002DA8AF). Target fact: no vftable or other absolute pointer
in the image references 0x006D9BA6, although the name is a virtual (UAE); its only
callers are 0x0059100A and 0x00591036 (direct calls). Its twin
`?getDiskName@CDDrive` 0x00564E28 (+0x18) is likewise unreferenced. Structural
inference: these are folded or header-inline getters placed by donor shape
("strict relocations from its own object"), not CDManager.cpp code. Proving the
real identity of 0x002D9BA6 restores AudioEventRTS's 66 rows.

## The blockers, by size

| Class | TUs | Rows | Why |
|---|---:|---:|---|
| unanchored, no W row at all | 1,164 | ~7,500 | BFME 2-only classes: no ZH definition, no retail `__FILE__`, no WB pairing |
| unanchored, W names another file | 161 | 4,454 | our N hint names a file that never existed (see below) |
| unanchored, W == TU but only on Wself rows | 98 | 3,261 | the rows were named from that very lead, so W may not corroborate them |
| unanchored, W basename == TU, directory differs | 119 | 3,199 | our tree put the sources in another directory than BFME 2's |
| unanchored, W == TU on rows without an N hint | 22 | 1,597 | free functions and nested-class methods give no N to corroborate |
| anchored but noncontiguous | 41 | 1,765 | another anchored TU's row inside the span |
| anchored, other proposed rows | 222 (all anchored TUs with any) | 2,755 | K rows (never approvable), funclets (P) of proposed parents, C runs bracketed by them (803), islands (10) |

(The 1,415 further noncontiguous rows belong to unanchored TUs and are counted
in the rows above.)

Examples: HordeContain.cpp (370 rows): WB says
`Object/Contain/HordeContain/HordeContain.cpp`, our sources sit in
`Object/Contain/`. StrategicInGameUI.cpp (388 rows): `StrategicInGameUI` is a
namespace spanning `StrategicInGameUIBuildQueueDetailsPanel.cpp`,
`...RegionDetailsTerritoryPage.cpp`, `...ArmyDetailsPanel.cpp` and more (WB
paths), so the class-name hint is wrong for every row. LivingWorldPlayer.cpp
(193 rows): every W row's notes cite the WB lead.

## Rule changes that would unlock the most (maintainer decision; not made)

Simulated by patching `tu_map.evidence_rows` in memory over the same tree:

- **W re-keys a matching basename (dirW).** When a row's W and N share the file
  name but not the directory, take W's path as the row's hint (BFME 2's own
  original path). +842 approved rows, 0 lost; HordeModelDraw +161, AptOnlineLogin
  +87, LivingWorldBattle +85, BannerUI +83. The merge would then write the TU at
  WB's original path.
- **W names a TU by itself (as S does).** +14,747 approved rows, 1,066 lost in
  shrinking TUs; TUs with approved rows 601 -> 1,046 (AptOnlineCustomMatch +319,
  LivingWorldAutoResolveBattle +194, AptSaveLoad +193, CreateAHero +183). W agrees
  with F on 170/170 rows today; a larger held-out test (W against Z/S where the
  tree was not reorganised, or against WB's own per-file function order) would be
  needed before trusting the callgraph pairing alone.
- Rejected: treating every compiler-generated copy constructor and every ??1
  without a ZH definition as a COMDAT (no Z/S) nets -18 (LANAPI +93,
  debug_debug +56, Scripts -38, part_buf -38); it has to be per case.

Two narrower tool limitations seen while checking single intruders:
`??0LANGameSlot@@QAE@ABV0@@Z` 0x0044B27F (an implicit copy constructor) takes
Z=LANGameInfo.cpp from ZH's *default* constructor, because ZH definitions are
keyed by (class, method) without the signature: +133 (LANAPI +97, LANGameInfo
+36) if it did not. `??0WindowTranslator@@QAE@XZ` 0x002390E8 is correctly named
(installs WindowTranslator's vftable) but sits in GameClient.cpp's span: ZH
defines it out of line in WindowXlat.cpp, BFME 2 evidently inlines it, and an F/Z
row is never an island: +162 for GameClient.cpp if header-inline-in-BFME 2 could
be expressed.

## Identity corrections a seat can still make (simulated payoff)

Single rows breaking an anchored TU's span, payoff if the row stops counting for
its current class (sim: row renamed to a classless placeholder):

| Row | Current name | Host TU | Payoff | Evidence status |
|---|---|---|---:|---|
| 0x004D7ADD | ?rva004D7ADD@TurretStateMachine@@QAE_NXZ | StateMachine + TurretAI | +124 | strong: see below |
| 0x0011E670 | ?Validate_Texture_Size@TextureLoader@@SAXAAI0@Z | dx8wrapper.cpp | +218 | open; donor-shape placement inside dx8wrapper's run |
| 0x0008E4EC / 0x0008E335 | ??1TerrainTracksRenderObjClass / ?updateScreenVB@W3DStatusCircle | W3DTerrainTracks / W3DStatusCircle interleave | +51 / +25 | masked-search placements |
| 0x00042100 | ??1W3DModuleFactory@@UAE@XZ | Win32GameEngine.cpp | +49 | name plausible; implicit dtor emitted with the inline createModuleFactory |
| 0x00719CC0 | ??1GridLinkClass@@UAE@XZ | aabox.cpp / gridcull.cpp | +49 | open |
| 0x002D7554 | ?parseAnim2DDefinition@INI@@SAXPAV1@@Z | Anim2D.cpp | +47 | name plausible; BFME 2 moved it next to Anim2D |
| 0x004A4DBE | ?doCollapseDoneStuff@StructureCollapseUpdate | Structure/RubbleRise interleave | +40 | masked-search placement |
| 0x0006E12F | ?Peek_Inner_Scale_Channel@RingRenderObjClass | W3DDynamicLight.cpp | +35 | weak: 7-byte accessor by masked search |
| 0x000CDFC8 | ?updateTreadPositions@W3DTankTruckDraw | W3DTankDraw.cpp | +32 | open |
| 0x004BD2F9 | ?xfer@HealCrateCollide | SalvageCrateCollide.cpp | +30 | vtable slot 3 of six CrateCollide vtables |
| 0x00605A7D | ?close@LocalFile / ?close@StreamingArchiveFile (fold) | LocalFile / StreamingArchiveFile | +27 | fold |

0x004D7ADD (target facts): `cmp [ecx+0x20],0 / jne / xor al,al / ret`, then
`call 0x004D7726`, null -> `mov al,1`, else `mov al,[eax+0x438] / and al,1`.
0x004D7726 reads the same +0x20 id and looks it up through TheGameLogic.
`StateMachineGoal.cpp`'s matched `internalSetGoalObject` writes the goal object's
id to StateMachine +0x20 (`m_goalObjectID`). Both addresses lie inside the
StateMachine.cpp run 0x004D7127..0x004D7B0F, just before
`StateMachine::defineState` 0x004D7B0F. Donor fact: ZH
`StateMachine::isGoalObjectDestroyed() const` is `if (m_goalObjectID == 0) return
false; return getGoalObject() == NULL;` (BFME 2 adds an effectively-dead bit test).
Inference: 0x004D7ADD is `?isGoalObjectDestroyed@StateMachine@@QBE_NXZ` and
0x004D7726 is `StateMachine::getGoalObject`, not TurretStateMachine methods.
Cost: the class and constness change is not a `rename.py` identifier rename; the
rows must be retracted and readmitted, and 12 caller units that call
`TurretStateMachine::rva004D7ADD` through private views
(`rg -l rva004D7ADD Code`) re-pointed at their StateMachine view in the same
change.

## Reproduce

    python3 tools/next_work.py --tier tu-approval --ranked
    python3 tools/tu_skeleton.py --plan Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptConditions.cpp

The simulations import `tools/tu_map.py` and replace one input in memory (a ledger
row's name, or `evidence_rows`' W/N/S fields); they never write `tu_map.csv`.

Addendum on 0x002D9BA6 (target facts): its caller 0x0059100A takes a
NetCommandMsg-like pointer, calls 0x002D9BA6 for a by-value AsciiString, reads
the string's 16-bit length at +4 and returns length + 0x13, then releases the
string (0x00036410): the shape of a NetPacket buffer-size helper for a
file-name command. Inference: 0x002D9BA6 is an identical-code fold whose kept
copy lies in AudioEventRTS.cpp's object (first in link order); the CDDrive name
is one donor-shape candidate among the folded getters, and its Z anchor does not
place the body.

## Unfinished at session end (2026-10-28, base `8d210eac0a`)

**0x002D9BA6 is AudioEventRTS::getAttackFilename (ready to do, not started).**
Target facts: `AudioEventRTSClassification.cpp`'s matched AudioEventRTS view
writes `m_attackName` at +0x1C and `m_decayName` at +0x20 (generatePlayInfo), and
its matched `?rva002DA867@AudioEventRTS` switches on the play portion: PP_Attack
calls 0x002D9BA6 (+0x1C getter), PP_Sound calls getFilename 0x002DA838, PP_Decay
calls 0x002D9BC1 (+0x20 getter). Retail order 0x002D9BA6, 0x002D9BC1, ...,
hasMoreLoops 0x002D9C07, isPositionalAudio 0x002D9C37 follows Zero Hour
AudioEventRTS.cpp's getAttackFilename, getDecayFilename, ..., hasMoreLoops,
isPositionalAudio. Donor fact: ZH `AsciiString AudioEventRTS::getAttackFilename()
const { return m_attackName; }` and `getDecayFilename` likewise. Inference: the
two bodies are `?getAttackFilename@AudioEventRTS@@QBE?AVAsciiString@@XZ` and
`?getDecayFilename@AudioEventRTS@@QBE?AVAsciiString@@XZ`, kept copies of
identical-code folds (NetPacket helpers and the symbols.csv pins
`getText1C`/`getText20@BFMENetGameSpyStatsAuthKeyCommandMsg` call the same
addresses).
Simulated payoff (rename 0x002D9BA6 only): +95 approved rows, AudioEventRTS.cpp
0 -> 67 and CDManager.cpp 1 -> 29, nothing lost.
Plan: define both getters in AudioEventRTSClassification.cpp and call them from
rva002DA867 directly. Admit getAttackFilename at 0x002D9BA6 with
`add_match.py --icf-owner '?getPath@CDDrive@@UAE?AVAsciiString@@XZ'`. Keep
`CDDrive::getPath` as the fold alias: about 25 call sites in NetPacket.cpp,
BFMEConnectionManager_sendGameSpyStatsAuthKey.cpp,
MilesAudioManagerGetAudioLengthMS.cpp and others call it by name. tu_map takes
the first ledger row per address, so the AudioEventRTS row must come before the
CDDrive row (move that line after the new row; no tombstone, because the same
(name, rva) stays). 0x002D9BC1 is optional: it is placeholder-named
(`Rva002D9BC1AsciiField::get`), so tu_map ignores it.

The other leads above (0x004D7ADD StateMachine, dx8wrapper, GameClient,
LANAPI/LANGameInfo) are unchanged and unclaimed.

## Session 2 (seat halilkkaya-tua2, base `1e9d0f5a75`): results

All counts are approved code rows from `tools/tu_map.py` `build()` run in
memory over the previous commit's ledger and over the working tree (never
written), cross-checked with `tu_skeleton.py --plan`. Total 42,810 -> 43,290
(+480) over six commits; link_check kept every touched unit's verdict.

| Commit | Rows | Approved | Notes |
|---|---|---:|---|
| `4b49a1d5d7` | 0x002D9BA6 `AudioEventRTS::getAttackFilename` (owner), `CDDrive::getPath` fold alias; 0x00564E28 `Rva00564E28AsciiField::get` (owner), `CDDrive::getDiskName` fold alias | +67 | AudioEventRTS.cpp 0 -> 67. The simulated "+95" was wrong: with getPath gone, CDManager.cpp's next cluster was getDiskName at 0x00564E28 and the map approved 28 LivingWorldCampaignAct rows for CDManager.cpp. 0x00564E28 is a +0x18 getter whose only caller is rva00564EC0@LivingWorldCampaignAct; fixing it keeps LivingWorldCampaignAct.cpp 28 -> 29 and CDManager.cpp 1 -> 0. |
| `2a31181a34` | 0x004D7ADD `StateMachine::isGoalObjectDestroyed` (retract + readmit, 12 caller units repointed) | +124 | StateMachine.cpp 0 -> 53, TurretAI.cpp 0 -> 71. All 13 units LINKS before and after. |
| `18aa80d3fd` | 0x0011E670 `DX8Wrapper::AdjustTextureSize` (owner), `TextureLoader::Validate_Texture_Size` fold alias | +218 | dx8wrapper.cpp 0 -> 219. Name from BFME 1 EA evidence for the same body at 0x009056F0 (file dxwrapper.cpp route wb1, name DXWrapper::AdjustTextureSize route chain/aligned). W3DShroud.cpp (claimed by halilkkaya-tu-s11b's merge) still calls the alias; repoint it and retire the alias row later. |
| `1711fdad14` | 0x00041AD4 `Win32Mouse::setPosition` (was DirectInputMouse; retract + readmit) | +16 | Slot 17 of ??_7Win32Mouse@@6B@ 0x007C2478 and ??_7W3DMouse@@6B@ 0x007C86D8; no DirectInputMouse vftable. Win32Mouse.cpp 0 -> 17. |
| `8f5546775f` | 0x004B901D `GrantUpgradeCreate::onCreate`, 0x004B9093 `GrantUpgradeCreate::onBuildComplete` (retract + readmit) | +25 | Slots 0/1 of the CreateModuleInterface vftable 0x00859428 that GrantUpgradeCreate's ctor stores at +0x10 (the old notes read SupplyWarehouseCreate's primary vftable past its end). GrantUpgradeCreate.cpp 0 -> 17, SupplyWarehouseCreate.cpp 0 -> 8; present_unmatched -3 (the duplicate ZH bodies in GrantUpgradeCreate.cpp). |
| `ea64f4542f` | 0x004BD2F9 `SalvageCrateCollide::xfer` (owner), `HealCrateCollide::xfer` fold alias | +30 | Slot 3 of six CrateCollide vtables (one identical-code fold); the kept copy lies in SalvageCrateCollide.cpp's run after the Salvage vtable's destructor 0x004BD207. SalvageCrateCollide.cpp 0 -> 20, HealCrateCollide.cpp 0 -> 10. |

Method notes for the next seat:

- Fold alias: `add_match.py NEW RVA SIZE SRC --icf-owner OLD` admits the real
  name beside the old one; `add_match.py OLD RVA SIZE SRC --replace-existing
  --icf-owner NEW --notes "...;icf-owner=NEW"` rewrites the old row after it.
  tu_map takes the first ledger row per address; link_census, allowed_symbols
  and dup_defs skip `icf-owner=` rows as identities. Use it only while other
  units still call the old spelling.
- Retract + readmit (class or constness change): drop the row by key with
  `ledger_io.rewrite`, `add_match.py` the new name, append a `Renamed to ...`
  tombstone to `reverse/deleted_rows.csv`, `re_log.py record OLD ... refuted`.
- Always rerun the in-memory map after a fix: a TU that loses its main cluster
  falls back to its next cluster, which may be another misnamed row
  (CDManager.cpp above).
- Always run link_check on the touched units: a placeholder that receives a
  real name can collide with an unmatched donor body of that name elsewhere
  (GrantUpgradeCreate.cpp above showed `duplicate`).
- Adding a function to a unit renumbers its funclets' `$L` labels; the gate
  verifies them past the renumbering (prints "verified past a renumbered $L
  label") and the commit passes, but the `object-symbol=$L<n>` notes of
  LivingWorldCampaignActOrders.cpp's and AudioEventRTSClassification.cpp's
  funclet rows are now stale spellings.

Checked and left alone:

- 0x004D7726 (`TurretStateMachine::getGoalObject`, really
  `StateMachine::getGoalObject`; pinned under that name, with an /alternatename
  in TurretAI_friendGetTurretTarget.cpp): +1 row only, and about 39 units
  spell the TurretStateMachine name, so an owner/alias swap would turn their
  relocation verdicts to unknown. 0x004D7735 (+0x34 lookup, no callers, no
  absolute pointer): identity unknown, +1.
- 0x002D9BC1 (`Rva002D9BC1AsciiField::get`, the +0x20 getter that is
  `AudioEventRTS::getDecayFilename`): placeholder, so tu_map ignores it;
  naming only, eight callers.
- GameClient.cpp (`??0WindowTranslator` 0x002390E8) and LANAPI.cpp
  (`??0LANGameSlot@@QAE@ABV0@@Z` 0x0044B27F): correct names that tu_map's rules
  place in another TU (header-inline in BFME 2; copy constructor keyed with the
  default constructor's Z). Same class of blocker: BoneFXDamage.cpp
  (`?GetSnapshotName@DamageModule@@MBEPBDXZ` 0x004B9735, an inline returning
  "DamageModule" emitted in BoneFXDamage's object). Tool/maintainer decisions.
- AIDock.cpp (67): the AIHarvestPrepareSiteState rows' hint merges into
  AIDock.cpp and the AIHarvest.cpp `__FILE__` row (0x00544C62) then breaks it;
  not a single-row fix.

Remaining single-intruder leads (in-memory map at `8f5546775f`): W3DTankDraw.cpp
+30 (`?updateTreadPositions@W3DTankTruckDraw` 0x000CDFC8), Win32GameEngine.cpp
+28 (`??1W3DModuleFactory` 0x00042100), Anim2D.cpp +46
(`?parseAnim2DDefinition@INI` 0x002D7554), W3DDynamicLight.cpp +23
(`?Peek_Inner_Scale_Channel@RingRenderObjClass` 0x0006E12F),
RubbleRiseUpdate.cpp +17 (`?doCollapseDoneStuff@StructureCollapseUpdate`
0x004A4DBE: only caller RubbleRiseUpdate::update 0x004A4F72; BFME 1's ILT-confirmed
name for the same role is `?doRubbleDoneStuff@RubbleRiseUpdate@@IAEXXZ`; its EH
handler and funclet rows must be renamed with it), W3DStatusCircle.cpp +15 / W3DTerrainTracks.cpp +10 (each other's
rows), StreamingArchiveFile.cpp +9 (`?close@LocalFile` 0x00605A7D), aabox.cpp
+7 (`??1GridLinkClass` 0x00719CC0).
