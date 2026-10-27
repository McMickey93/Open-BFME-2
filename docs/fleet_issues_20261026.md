# Issues seen by a local fleet, 2026-10-26

Findings from four local seats working the link, data-identity and names lanes
on 2026-10-26. Each item gives the cause, the evidence and a suggestion. The
`tools/tu_skeleton.py --merge` link check (LINK-042) is left out; a maintainer
confirmed it is being fixed.

## 1. Consumers rebound to ledger names that nothing defines

Two "bind the ledger's ..." commits respelled consumers to the data ledger's
heuristic name instead of the name a unit actually defines:

| Commit | Global | Ledger name | Defined name | Loss |
|---|---|---|---|---|
| 3a8ff9f8e0 | `TheSkirmishGameInfo` (0x00A02EF0), 23 units | `GameInfo *` (provisional) | `SkirmishGameInfo *` in SkirmishGameOptionsMenu.cpp, as in Zero Hour and BFME 1 `GameInfo.h` | 71,793 B; census 98.11% -> 97.47% |
| 397acb4f2e | `WW3D::IsCapturing` (0x009EC3D6), 5 units | public `@@2_NA` (unowned) | private `@@0_NA` in ww3d.cpp | 818 B |

Both are reverted (LINK-041, LINK-042).

Suggestion: before a data-identity rebind, require that some object defines
the ledger name (`link_index` "strong"). A provisional or unowned ledger name
is a heuristic, not proof.

## 2. Data ledger out of date or contradictory

`python3 tools/data_ledger.py --check` reports the committed ledger as stale.
Cases met today:

- **0x00A00950**: the verified owner row `reverse/data_rows.csv:108`
  (a4812fc7db) names `?MessageStreamSubsystem@@3PAVMessageStream@@A`. The
  `data_ledger.csv` column and Zero Hour say `TheMessageStream`, and 121 files
  use it (6 use MessageStreamSubsystem). data_check flags every
  TheMessageStream use as wrong-name. Which name is intended?
  Resolved 2026-10-27: `TheMessageStream` (ZH; the `"TheMessageStream"`
  initSubsystem literal; BFME 1 spells MessageStreamSubsystem only as a
  `#define` alias of it). The data row now names it; the one remaining
  MessageStreamSubsystem reader is AptCampaignMenuCallbacks.cpp, after which
  MessageStream.cpp's second definition goes.
- **0x00A04424**: the verified owner is `g_Va00E04424`
  (Rva007ABBB3CtorInits.cpp); `data_ledger.csv` names Rva007B6880Thunks.cpp.
- **0x00A01EDC / 0x00A030D8**: GameStateInit.cpp now spells
  `TheMineshaftPortalNetworkManager` / `TheGameStateMap`; the ledger still
  lists `g_Va00E01EDC` / `g_Va00E030D8` with that owner (stale since a rename).
- **0x009EC4A0/A4/A8**: the ledger names `?G00DEC4A0/A4/A8@@3HA`, which no
  object defines; `g_Va00DEC4A0/A4` (Rva00118990Init.obj) and `g_Va00DEC4A8`
  (Rva001188A0Reset.obj) are defined.
- **0x00A0BE00**: the ledger names the placeholder `?G00E0BE00@@3HA`
  (ConstGlobalGetters2.cpp). The real global is `static ciLocalIP` in the
  reconstructed GameSpy `chatSocket.c`, which a C file cannot extern under the
  C++ name.
- **0x009EE5D8**: `DX8Wrapper::render_state` (protected static, 656 B, defined
  in dx8wrapper.obj). The ledger also lists ScreenMaterial (0x009EE5DC) and
  BFME2CurrentTextures (0x009EE5E0) as separate owned globals inside it
  (= `render_state.material` / `.Textures`); ScreenCurrentShader (= `.shader`)
  depends on two alternatename hatches.
- **GameSpy pinger (0x00A0C0E8 ff.)**: `pingerMain.c` and the ledger owner
  `peer/peerPing.c` both define piPingerPingedParam, piActivePingList,
  piInitialized, piLastThinkTime, piNextID, piSettingData and piSocket as file
  statics, so nothing defines them externally. Needs an owner decision: which
  TU keeps external linkage, and PINGERBool vs GSIBool, uint16 vs unsigned short.

Suggestion: regenerate the ledger and settle 0x00A00950. Much of the
data-identity queue is blocked by these entries.

## 3. Retirements blocked by findings outside the baseline

`repair_queue.py retire data` refuses a whole file when data_check finds
anything outside the baseline, and many files carry such findings. Many debt
keys are already fixed in source (the file uses the ledger name and builds
byte-exact) but cannot be retired. Recurring blockers:

- `TheMessageStream` at 0x00A00950 (item 2), in 11 of the 329 debt files;
- function-local static guards (`?$S1@...`), e.g. Rva005F2FEFApt.cpp
  (0x00A068D8/E0), AptPalantirCallbacks.cpp, ScriptActions_rva003C31F3
  (0x00A02DD4);
- `GameSpyColor` (0x009B9198) in AptOnlineCustomMatchCallbacks.cpp;
- `g_currentAptOnlineCustomMatch` (0x00A063EC) in ColdGlobalDwordGetters;
- `_vtbl_00C4ED70` at 0x0084ED70 via alternatename in the ReplenishUnits and
  CommandButtonHunt ModuleData ctors.

These findings land unnoticed while data_check runs in shadow mode.
Suggestion: either baseline existing findings once, so retire judges only the
keys being retired, or let retire skip findings that predate the change.

## 4. Name lane

- Skips are not persisted: `name_lane.py next` keeps serving files a seat has
  already skipped, so the yield per brief drops toward zero after a few hours.
- When every seat runs under the same model label, the random queue rarely
  serves a file to the second seat it needs. Targeted `next --file` works
  around it.
- A vote cannot land a name that collides with a stand-in class in the same
  file, or that changes an operator or virtual signature (e.g.
  `BfmeThingQR::bfmeShowQR` = Zero Hour `Debug::operator<<(unsigned short)`,
  landed by hand as 7056bce950). Those need `rename.py` or a hand rename.

## 5. Tooling papercuts

- `claims.py release --landed` does not release `file:` claims; they must be
  released by path.
- A pre-push hook over ~46 sources takes about 9 minutes while master moves
  every ~2 minutes, so large pushes keep losing the ref race ("cannot lock
  ref"). Pushing one commit at a time works. A partial push
  (`git push origin HEAD~n:master`) is refused because the hook checks the
  working tree.
- `hatch_counters --update` has no path filter. Lowering one retired hatch
  rewrites the whole `reverse/hatch_baseline.tsv`; a test run removed 333 lines
  and recounted 14 (alternatename 3894 -> 3859, address_global 6393 -> 5739,
  present_unmatched 4043 -> 3980, pin 15638 -> 15633, pragma_optimize 2077 ->
  2062). Seats therefore leave "down to 0" entries in place; a maintainer
  refresh or a per-file option would record that progress.
- Shallow submodule updates add a new ~1 GB pack each time, and old pins stay
  reachable through the reflog. A checkout's `.git` grew to about 10 GB, of
  which 5.5 GB was in `.git/modules/reference/open-bfme-1`. `reflog expire` plus
  `gc --prune=now` in the submodule shrank that to about 160 MB.
