# GameClient color-data prerequisite — Sol family B, 2026-10-26

Allocated target: Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DGameClient.cpp.
The old full status-circle header supplies only setColor to this unit. Replace
that include with the static interface actually used, binding its dirty byte
to the existing g_trackDirty owner at 0x009E207C and its diffuse member to the
existing public-tag owner at 0x009B45C8. No instance layout, new global, name
vote or source move is introduced. class_views.py finds four existing local
status-circle views and no registered canonical header.

Checks and provenance:

- Fresh `name_lane.py consolidate --under
  Code/GameEngineDevice/Source/W3DDevice/GameClient/ --out
  build/consolidation/gameclient`, followed by `--check`: inputs agree.
  Original-path evidence, alternatives, private declarations, flags, registers
  and mixed routing reviewed. Current `tu_skeleton.py --plan` has 19 approved
  rows, five donor files and six mixed files. No TU map committed.
- Before and after `./build.sh` on this source: 5/5 exact, including the
  31-byte setColor row at 0x0004C41F and its 33-byte setTeamColor caller at
  0x0004C8BC. One compiler float verifies; literal/import checks pass.
  `find_declared_unmatched.py` passes before and after. Remove the two stale
  addScorch/createRayEffectByTemplate present-unmatched markers because those
  bodies already have verified rows; no new row or recovered bytes claimed.
- All 57 external code/data providers keep identical bytes, sizes, section
  flags and COMDAT selections. Exactly four DIR32 references change: each of
  setColor/setTeamColor directly names the dirty-byte and public diffuse
  owners. Undefined references change by precisely those two substitutions.
  All other bindings and providers are unchanged. Reproduction:
  build/codexb-gameclient-provider-proof.py, its before.json and .before.obj.
- Scoped `code_identity_gate.check` has two pre-existing shadow findings:
  createGameDisplay binds W3DDisplay's constructor to 0x00104EBF, and the
  Vector3 copy constructor is divergent. Running the supported check against
  the saved before object and current object produces identical findings and
  all five rows' code-reference keys. Reproduction:
  build/codexb-gameclient-identity-proof.py. No identity key retired or added.
- Initial `repair_queue.py retire data` correctly refused an additional old
  protected-tag diffuse reference. Correcting that declaration to its recorded
  public owner preserves every provider while fixing the second data binding.
  The subsequent retirement passes: exactly one registered wrong-name key
  removed, none still found. `data_check.py --converged`: ten addresses,
  zero second names or unjudged rows.
- `hatch_counters.py --update` verifies removal of this alias and two stale
  markers; retain all unrelated register entries. Data debt -1; aliases -1;
  stale present-unmatched -2; identity retirement 0; file reduction 0;
  recovered bytes 0. No downstream merge acceptance or Luna landing claimed.

Remaining prerequisites: the target still has mixed/unplaced rows, independent
private GameClient declarations, differing compiler flags and the unchanged
code-identity findings above. Foreign Common/GameClient donors are left to
assigned owners. Do not repeat unchanged composition blockers or treat this
owner-binding repair as class-layout recovery.

## Other allocated investigation

W3DTerrainBackground: 61 approved rows, 24 donors and two mixed files. The
seed owns three rows with no approved placement, so inspecting its split
summary does not authorize moving them. The ordinary read-only merge dry-run
completed over 100 trial objects and reached fallback seed flag combinations,
but did not produce a final verdict within approximately 15 minutes. It was
interrupted rather than spending the remaining session on failed compositions.
No merge acceptance or technical refusal is inferred. The temporary source was
removed, the compiler exited and the scope claim was released. The interrupted
receipt is build/codexb-terrain-before-trial.txt; the plan and split summary are
build/codexb-terrain-plan.txt and build/codexb-terrain-seed-split.txt. Avoid a
blind repeat of the expensive whole-file trial; investigate a concrete private
view/include prerequisite first. Planner scans during the trial correctly
refused transient Code directory changes; regenerate after the trial ends.

meshmdlio: read-only plan has 116 rows, 19 donors and 14 mixed files. No local
data key offers a bounded repair; the broad Rva00170C0Siblings donor carries
foreign rows and identity findings. AptValueVector: six approved rows, three
donors, with a Common donor and unplaced seed rows. Neither scope was claimed
or edited. Other unchanged allocated blockers are in the Dogma/display/caps
handoffs from this batch. The MessageStream decision remains with issue #116.

## Publication and handoff

The audit covers the entire pending font, Dogma, word-wrap, caps and GameClient
batch plus this staged edit. There are no moved/deleted source paths. The sole
added source header is the inherited font header, whose only include consumer
was verified in its recovery handoff. GameClient removes one include; all 57
emitted providers and their bindings were compared as above. No active tool,
hook, workflow, build-input or path-registry consumer needs repointing, and
historical EA paths remain unchanged. The scoped before/after object proofs
cover authored changes; the next census must confirm aggregate linking and
ownership. No maintainer-only link cycle or smoke/nightly command was run.

Claims for every changed source/header and its handoff remain held until the
batch is published. Font, Dogma, word-wrap and caps claims are listed in their
respective handoffs; add this source and this handoff. If publication defers,
release these file scopes only after landing is confirmed, then settle RVA
claims with claims.py release --landed. The terrain claim is already released.
