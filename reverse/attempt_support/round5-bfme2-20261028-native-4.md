# Radio-button unused floorf emitter cleanup, 2026-10-28

Selected by the normal linking picker: W3DRadioButton.cpp, three existing rows (274/472/495 bytes). Apply the already recorded LINK-132/LINK-133 math-header pattern only if native object evidence confirms an unused external _floorf copy. The retail owner is the 18-byte row at 0x0004D649 in TerrainLogicAmbientColorRva0027DA6A.cpp. Keep every complete existing function body; compare retained external COMDAT bytes, relocation fingerprints, definitions, weak bindings and runtime incoming references. No current whole-game or census-link result is implied by the scoped preview.

Native run: https://github.com/McMickey93/Open-BFME-2/actions/runs/40754123096

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
      "variant": "static-floor",
      "gate_exit": 0,
      "structural_refusal": "The selected external copy is absent before the trial"
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
