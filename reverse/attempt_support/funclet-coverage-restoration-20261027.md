# Restore omitted funclet coverage

Verified against `611b24cb8ca5fdd9c311d10872cb05ce9da6336f` on 2026-10-27.

Snapshot-base adoption and funclet-repointing commits dropped 13 existing
cleanup rows, leaving 141 non-padding bytes unclaimed. The earlier
`ffde306e75` repointing batch also omitted the eight-byte action at `0x00793B03`.
The affected later commits are `50b7b29f94`, `b5ad8b612c`, `0dada5701d`,
`67a53654ed`, and `8846bc744a`.

Each restored row uses the current object's compiler-local label. The complete
matched parent EH graph is EXACT in `eh_verify`, which independently places the
label at its retail address. Each whole cleanup body also passes the ordinary
byte/relocation comparison without masking or unresolved calls. Parentage is
established by those graphs, rather than by neighboring addresses.

| Retail RVA | Raw bytes | Current label | Parent RVA |
|---|---:|---|---|
| `0x007634F7` | 11 | `$L5753` | `0x000E6AC0` |
| `0x00763502` | 11 | `$L5754` | `0x000E6AC0` |
| `0x0076350D` | 11 | `$L5755` | `0x000E6AC0` |
| `0x00763523` | 11 | `$L5757` | `0x000E6AC0` |
| `0x0076357E` | 11 | `$L5833` | `0x000E6C6F` |
| `0x00763589` | 11 | `$L5834` | `0x000E6C6F` |
| `0x00763594` | 11 | `$L5835` | `0x000E6C6F` |
| `0x0076359F` | 11 | `$L5836` | `0x000E6C6F` |
| `0x007635AA` | 11 | `$L5837` | `0x000E6C6F` |
| `0x0077D4DB` | 11 | `$L1278` | `0x00355B61` |
| `0x007881E6` | 11 | `$L5475` | `0x004398D8` |
| `0x0079121A` | 10 | `$L503` | `0x004D85B6` |
| `0x00792F90` | 11 | `$L3502` | `0x004F561D` |
| `0x00793B03` | 8 | `$L13877` | `0x004FE987` |

The first nine actions belong to `Rva000E6AC0Ctor.cpp`. The remaining parents
are in `Rva00355B61Ctor.cpp`, `Rva000D3FA0Destructor.cpp`, `TurretAICtor.cpp`,
`TunnelTrackerDtor.cpp`, and `StagingRoomGameInfo.cpp`, respectively. The ledger
retains their complete source paths and parent symbol names.

The GameSpy action at `0x00793B03` jumps to `0x0007FAB3`. Its existing emitted
`vector<BfmePod20>` destructor is a complete, unmasked 14-byte twin of the
existing `vector<int>` owner there, including the free relocation. Admit that
folded destructor row through `add_match.py --icf-owner` before restoring the
action. It adds zero unique bytes. `BfmePod20` remains the existing size-only
emitter view; this does not recover an original application-type name.

Admission and validation:

- `add_match.py --icf-owner` verifies the destructor fold and its unit.
- `add_match_batch.py` transactionally admits all 14 actions and verifies each
  of the six units: 93/93 function rows pass, including string, float and import
  reference checks.
- `eh_verify.py` across all six units reports 12 EXACT parent graphs, zero
  non-exact results, and zero missing objects.
- `progress.py HEAD` reports +149 byte-matched bytes and zero unclaimed bytes:
  7,978,500 / 7,978,500 non-padding text bytes represented. The 150 raw restored
  bytes contain one `0xCC` byte excluded by the headline's existing rule.

The ledger change is append-only: 14 cleanup rows plus the destructor fold.
Existing rows, game source, headers, pins, baselines and census rules are
unchanged. Linking figures remain those of the published census; this repair
does not record a new census or claim a measured linking gain.
