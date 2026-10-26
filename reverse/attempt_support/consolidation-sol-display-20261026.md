# W3DDisplayString prerequisite — Sol family B, 2026-10-26

Allocated destination: Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DDisplayString.cpp.
No consolidation or split applied. The existing GlobalLanguage data owner uses
the class tag; the word-wrap donor's struct tag generated a different external
symbol. Change only that local tag and retain its public view and layout.
This is a declaration correction, not a recovered class layout or new name.

Evidence and acceptance:

- Planner: `name_lane.py consolidate --under
  Code/GameEngineDevice/Source/W3DDevice/GameClient/ --out
  build/consolidation/display`, followed by its freshness check. The plan has
  36 approved rows, six donors and two mixed donors. The planner is evidence,
  not merge approval.
- Target data ledger: RVA 0x009FDC84 owns
  `?TheGlobalLanguageData@@3PAVGlobalLanguage@@A`. The donor's old symbol was
  `?TheGlobalLanguageData@@3PAUGlobalLanguage@@A`. No second definition added.
- Before/after `./build.sh` on W3DDisplayString.cpp and
  W3DDisplayStringWordWrap.cpp: 16/16 matched. Frozen-file checks pass.
- Scoped COFF comparison: all 30 external code/data providers (11 seed,
  19 donor) retain raw bytes, sizes, section flags and COMDAT selections.
  Exactly one DIR32 reference changes from the struct-tag name to the
  recorded class-tag owner. All other relocation targets and undefined
  reference sets remain equal; the seed object is unchanged. Reproduction:
  build/codexb-display-provider-proof.py, build/codexb-display-before.json
  and their .before.obj files.
- `data_check.py --converged` on both files: ten addresses, zero second
  names, zero unjudged references. Scoped code_identity_gate.check passes.
- `repair_queue.py retire data` for the donor retires exactly its one
  wrong-name key. Data debt -1; identity debt 0; hatches 0; file reduction 0;
  recovered bytes 0. No linked-byte or image-ownership claim.

Demonstrated unblock:

- Before `tu_skeleton.py --split W3DDisplayStringWordWrap.cpp --for
  W3DDisplayString.cpp --dry-run`: ten of eleven destination bodies carved;
  notifyTextChanged at 0x00106663 refused for this data-identity debt.
- After: all eleven bodies carved and refused_rows is empty. No copied data
  or hatch remains. Complete split still refused because residual inline
  helpers 0x00105D3B and 0x00105D96 stop being emitted without their callers.
  Preserve these rows and use the upstream split lane; no manual split.
- Receipts: build/codexb-display-before-split.txt and
  build/codexb-display-after-split.txt. No downstream Luna landing established.

Other allocated prerequisite checked: W3DRopeDrawCtor.cpp builds 1/1 exact,
but identity retirement refuses an unavailable user32 import-thunk object and
finds a current BfmePod16 _Vector_base constructor binding to 0x00211E58.
The registered SegInfo erase divergence is preserved. No source edit or debt
retirement; blocked evidence recorded through re_log.py, claim released.

Pre-publication tooling/path audit covers the inherited font recovery, Dogma
prerequisite and this declaration fix together: no moved or deleted source
paths. The inherited new font header's include consumer was already verified
with that recovery. This fix changes no includes, build inputs, active tools,
hooks, workflows or path registries. Historical EA paths remain unchanged.

Keep the word-wrap and handoff file claims until publication is confirmed.
The inspected destination was not edited and its file claim can be released.
