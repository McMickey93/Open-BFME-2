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
