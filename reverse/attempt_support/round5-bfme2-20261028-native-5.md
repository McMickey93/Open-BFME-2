# Radio-button renderer dependency cleanup, 2026-10-28

Continuation of the SAME selected W3DRadioButton.cpp task. The earlier floorf hypothesis was disproven by the native before.obj: no such external definition exists. That source-restored blocker was banked as 3cc5f325368845c44c0b93c2d08d0d2393976710 (native run 40754123096). The published d92e7e6635 census identifies the actual sole wrong_selected name as ??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z. This historical inspection is not a new link measurement.

Apply the existing horizontal-slider repair (docs/linking_obstacles.md, reverse/attempt_support/horizontal-slider-link-20261028-codex.md and its object receipt): W3DGadget.h pulls in W3DGameWindow.h and Render2DSentence.h, although these callbacks need only GameWindow. Include GameWindow.h directly. No shared header, compiler option, callback body, row, pin, address, owner or baseline changes. Unlike the slider, this file uses no WIN_DRAW_LINE_WIDTH macro, so no macro copy is necessary.

Require native proof of removal of exactly the unused PendingSurfaceStruct vector deleting destructor and vector-construction iterator, no incoming runtime reference to either, all retained external COMDAT fingerprints identical, all remaining definitions unchanged and no added undefined symbol or weak-binding change. Verify the current W3DComboBox.cpp provider too (matched 75-byte destructor row at 0x00002B6A), and prepare both current objects with the normal strict-receipt command. All three complete RadioButton bodies (274/472/495 bytes) must remain exact. Report ordinary before/after preview literally; no census, whole-image ownership, whole-game link or game test is inferred. The source snapshot now contains the published census commit, so --fetch-index can enforce its ancestry normally.

Native run: https://github.com/McMickey93/Open-BFME-2/actions/runs/40758245978

Original compiler and unchanged ordinary project gates; no new C++ bytes, census measurement or game test.

Outcome: blocked; game source restored.
Blocker: Every reviewed candidate failed byte or retained-COFF verification

Qualification observations:

```json
{
  "reference": {
    "pinned": "0424131c818fba6641613ef826222ecf30845025",
    "observed_upstream": "064ec9e008eb77bd0428d3eb51fe34fe60a9d302",
    "pointer_changed": false,
    "newer_head_qualified": false,
    "reused_published_verification": "reverse/attempt_support/bfme1-reference-0424131c-20261028-codex3"
  },
  "trials": [
    {
      "variant": "direct-window",
      "gate_exit": 2
    }
  ],
  "object_proof": null,
  "previews": [
    {
      "label": "before-link-preview",
      "exit_code": 1,
      "output": "link_check: no census index at build/link_census/link_index.pkl (never tracked).\n  download the last published census's:  python3 tools/link_check.py --fetch-index\n  build one (keep the tree still until it ends; rewrites reverse/link_status.csv):\n                            python3 tools/link_census.py --build --measure\n"
    }
  ],
  "census_download": null
}
```
