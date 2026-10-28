# Radio-button renderer dependency cleanup, 2026-10-28

Continuation of the SAME selected W3DRadioButton.cpp task. The earlier floorf hypothesis was disproven by the native before.obj: no such external definition exists. That source-restored blocker was banked as 3cc5f325368845c44c0b93c2d08d0d2393976710 (native run 40754123096). The published d92e7e6635 census identifies the actual sole wrong_selected name as ??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z. This historical inspection is not a new link measurement.

Apply the existing horizontal-slider repair (docs/linking_obstacles.md, reverse/attempt_support/horizontal-slider-link-20261028-codex.md and its object receipt): W3DGadget.h pulls in W3DGameWindow.h and Render2DSentence.h, although these callbacks need only GameWindow. Include GameWindow.h directly. No shared header, compiler option, callback body, row, pin, address, owner or baseline changes. Preserve the existing WIN_DRAW_LINE_WIDTH (1.0f) definition locally, exactly as in the donor header and the earlier slider fix. The first direct-header trial in native run 40758245978 omitted this required macro and was rejected by the original compiler; its source was restored. That earlier no-macro assumption was incorrect. The full candidate now retains the constant and every original function body.

Require native proof of removal of exactly the unused PendingSurfaceStruct vector deleting destructor and vector-construction iterator, no incoming runtime reference to either, all retained external COMDAT fingerprints identical, all remaining definitions unchanged and no added undefined symbol or weak-binding change. Verify the current W3DComboBox.cpp provider too (matched 75-byte destructor row at 0x00002B6A), and prepare both current objects with the normal strict-receipt command. All three complete RadioButton bodies (274/472/495 bytes) must remain exact. Report ordinary before/after preview literally; no census, whole-image ownership, whole-game link or game test is inferred. The source snapshot now contains the published census commit, so --fetch-index can enforce its ancestry normally.

The prior published-index fetch was correctly refused because a depth-256 checkout lacked the census ancestor: d92e7e6635 is 530 commits behind the reviewed base e103586cd8. This follow-up fetches the full source history and uses the unchanged normal --fetch-index ancestry check. No authority or tool check is edited.

The macro-missing trial was banked with normal native commit/pre-push/push as c4371a779bc5d7970761c482dd1d0e1c21626bcd, without a source change. This follow-up uses the newer reviewed official base 696149099cdd2684fb438e6c4da1b35ebeca67c0; AGENTS.md and the selected complete source blob are unchanged.

Run 40760121489 did not reach native source qualification before its broad fetch-depth=0 checkout was superseded. No official claim was bridged for that run. The replacement serially cancels that exact own fork run and waits for completion before beginning source checkout. A SHA-pinned depth-1024 source fetch includes the reviewed census ancestor without fetching unrelated branch histories; the ordinary index ancestry check remains unchanged.

Completion of the SAME qualified task after run 40761356772: native original/modified byte gates and all 47 retained external COMDAT fingerprints passed, and ordinary preview changed from the sole selected-renderer blocker to LINKS for 1,237 authored bytes. Native pre-commit produced e6245ac596a25d364003aa4eb02468981269e9ed, retained as a bundle, but rebase stopped on docs/linking_obstacles.md before pre-push or source publication. The prior worker finished and released its exact official leases. This final trial rechecks the same complete source against the current official base and handles only independent documentation append conflicts: preserve every upstream byte and add only this commit's standalone new RadioButton paragraph. Any source, register, baseline, hook or other conflict is refused. The unchanged ordinary source and push gates still decide publication.

Native run: https://github.com/McMickey93/Open-BFME-2/actions/runs/40764318874

Original compiler and unchanged ordinary project gates; no new C++ bytes, census measurement or game test.

Outcome: reviewed binding/emitter repair verified; affected source rows remain exact.

Qualification observations:

```json
{
  "reference": {
    "pinned": "0424131c818fba6641613ef826222ecf30845025",
    "observed_upstream": "9ce59816c7bcfcdbde742e847e1791d3a322d1a8",
    "pointer_changed": false,
    "newer_head_qualified": false,
    "reused_published_verification": "reverse/attempt_support/bfme1-reference-0424131c-20261028-codex3"
  },
  "trials": [
    {
      "variant": "direct-window-width",
      "gate_exit": 0,
      "coff_proof": {
        "removed_unused_externals": [
          "??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z",
          "??_H@YGXPAXIHP6EPAX0@Z@Z"
        ],
        "retained_external_comdats": 47,
        "retained_external_comdat_fingerprints_identical": true,
        "no_incoming_runtime_reference": true,
        "external_definitions_removed": [
          "??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z",
          "??_H@YGXPAXIHP6EPAX0@Z@Z"
        ],
        "undefined_removed": [
          "??1PendingSurfaceStruct@Render2DSentenceClass@@QAE@XZ",
          "??3@YAXPAX@Z",
          "??_M@YGXPAXIHP6EX0@Z@Z",
          "??_V@YAXPAX@Z"
        ],
        "undefined_added": [],
        "weak_bindings_unchanged": true
      }
    }
  ],
  "object_proof": {
    "removed_unused_externals": [
      "??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z",
      "??_H@YGXPAXIHP6EPAX0@Z@Z"
    ],
    "retained_external_comdats": 47,
    "retained_external_comdat_fingerprints_identical": true,
    "no_incoming_runtime_reference": true,
    "external_definitions_removed": [
      "??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z",
      "??_H@YGXPAXIHP6EPAX0@Z@Z"
    ],
    "undefined_removed": [
      "??1PendingSurfaceStruct@Render2DSentenceClass@@QAE@XZ",
      "??3@YAXPAX@Z",
      "??_M@YGXPAXIHP6EX0@Z@Z",
      "??_V@YAXPAX@Z"
    ],
    "undefined_added": [],
    "weak_bindings_unchanged": true
  },
  "previews": [
    {
      "label": "before-link-preview",
      "exit_code": 1,
      "output": "Compile: 0 of 1 TU(s) (deps-cache: 1 current)\nCode/GameEngineDevice/Source/W3DDevice/GameClient/GUI/Gadget/W3DRadioButton.cpp: does not link  LINKED 0 -> 0 bytes (census 2026-10-28 15:58 at d92e7e6635; file's own bytes 1,237)\n  selected    ??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z  (the definition the link keeps is not retail's)\nlink_check: 0 of 1 link cleanly; LINKED 0 -> 0 bytes (6.7s)\n"
    },
    {
      "label": "after-link-preview",
      "exit_code": 0,
      "output": "Compile: 0 of 1 TU(s) (deps-cache: 1 current)\nCode/GameEngineDevice/Source/W3DDevice/GameClient/GUI/Gadget/W3DRadioButton.cpp: LINKS  LINKED 0 -> 1,237 bytes (census 2026-10-28 15:58 at d92e7e6635; file's own bytes 1,237)\nlink_check: 1 of 1 link cleanly; LINKED 0 -> 1,237 bytes (6.7s)\n"
    }
  ],
  "census_download": null
}
```
