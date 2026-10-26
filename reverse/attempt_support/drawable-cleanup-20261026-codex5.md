# Drawable cleanup and interrupted consolidation trial

2026-10-26, codex5; starting revision 00af29220b.

## Verified cleanup

- 9cdb5a55b5 removes three stale present-unmatched markers from
  Drawable_rva002736BA.cpp. Their helper bodies already have matched owners
  at 0x002736A8, 0x002D752D and 0x00270BA8. It also replaces the redundant
  address macro with a cast of the existing TheAnim2DCollection declaration.
  The parent and two EH rows pass ./build.sh (3/3); the renumbered EH label
  resolves through the verified parent data. Frozen-file and converged-data
  checks pass. Link preview retains 165 -> 165 bytes.
- 1d7beff73e replaces Drawable_rva00274176.cpp's ji_006291ae declaration and
  alternatename with the CRT memset declaration from string.h. The existing
  _memset pin and import thunk identify the same target; no pin was added.
  All seven rows pass ./build.sh and link preview retains 696 -> 696 bytes.
- 5b0577539b removes /Oy- and six redundant optimize pragmas from that same
  source. All seven rows still match, the frozen-file check passes, and link
  preview again retains 696 -> 696 bytes.

The hatch register shrinks by ten entries/counts in total: three stale
markers, one alternatename, and six optimization pragmas. Normal commit hooks
pass. No source paths or ledger rows moved; no new byte coverage, census gain,
or ownership receipt is claimed. The link previews use index d1f046749a.

## Consolidation handoff (LINK-017 / LINK-042)

The supported GameClient consolidation planner and Drawable.cpp merge plan
reported 388 approved rows across 149 donor scopes, including 21 mixed files.
The existing destination passes its frozen-file check and its baseline link
preview retains 369 -> 369 bytes. No merge was applied.

A supported tu_skeleton.py --merge ... --dry-run was started with current
splitter/flag-selection fixes, rather than repeating the unchanged historical
trial. The runner requested winddown after about eleven minutes. SIGINT
stopped the still-running dry run in its trial compiler loop; its temporary
source was removed by the tool's finally block. It emitted no completed
accepted/rejected donor report, so this run proves no composition blocker or
accepted donor set. The two cleanup sources changed after the dry run had
read its inputs: regenerate the planner and run a fresh supported trial before
applying any merge. Retain LINK-042's destination-link preservation check and
LINK-017's strict provider/consumer audit requirements.

The shared docs/linking_obstacles.md scope was claimed by another worker when
this handoff was written; it was left untouched. This file records the scoped
status pending integration into that shared register. No existing obstacle is
cleared by this interrupted trial.

## Reference freshness

The overdue BFME 1 check fetched official upstream fc68fb743ca37a276478479957821f662bcc2294.
The clean checkout and committed gitlink both remain at
de077dd5dd8339716a6abe453a1d81dfdf77e651. The reference scope was held by
yasinschroeder-codexb; no submodule update or successful freshness timestamp
was recorded by this seat. All cleanup verification used the pinned inputs.
