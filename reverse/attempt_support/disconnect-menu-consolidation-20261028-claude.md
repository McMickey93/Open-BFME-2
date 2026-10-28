# DisconnectMenu.cpp consolidation (2026-10-28, claude-opus-5-5)

TU: `Code/GameEngine/Source/GameClient/GUI/DisconnectMenu/DisconnectMenu.cpp`
(53 approved rows, `reverse/tu_map.csv`). Served by `tools/next_work.py --claim`.

## Landed

- Merge of 4 files (28 rows, `8f8329fa57` range): AptDisconnectScreen,
  AptDisconnectScreenShow, Rva00513040Finish, Rva00513138Listbox. The TU path is
  new; `--merge --dry-run` fails with FileNotFoundError until its directory
  exists (the real merge creates it), so create the directory first.
- `Rva00512CE9Kick.cpp` reconciled (TU class chain; `_bfme_AptGameWindow::m_274`
  protected; `sprintf` declared dllimport for retail's IAT call), then merged
  with `Rva0051318EVotes.cpp` (34 rows; Votes' `address_global`/`alternatename`
  hatch keys carried, totals kept).

## Outgoing in this batch

- `AptDisconnectScreenKick.cpp` reconciled: the TU's AptDisconnectScreen and
  GameTextInterface (fetch is vslot 15 in both spellings). The TU drops
  `/D_CRTIMP=` (its rows match either way); retail calls `atoi` through the IAT
  (`Kick` is 66 B with `call [imp]`, 65 B with a thunk call) and `_mbscpy`
  through the import thunk, kept by the donor's local `_CRTIMP` override around
  `<mbstring.h>`. 45/45 exact across TU and donor.

## Remaining prerequisites

- `AptDisconnectScreenKick.cpp` composes with the TU but LinkGuard refuses it:
  "a file without a census object would place the merged unit earlier in link
  order than the guard can judge". DisconnectMenu.obj is new, so rerun the dry
  run after a maintainer's ordinary scheduled census records it. Do not bypass
  the guard or start a measurement.
- `AptDisconnectScreenRva00513449.cpp`: the row is a real virtual
  (`?rva00513449@AptDisconnectScreen@@UAEHHII@Z`, vftable `0x00C65B6C` slot 2),
  but the TU's AptDisconnectScreen declares only its destructor virtual and spells
  slot 5 (`rva00512DB1`, `QAE`) as non-virtual, while the TU's constructor emits
  the vftable. Reconstruct the screen's vftable slots 0..5 (with the
  `_bfme_AptGameWindow` base's) from retail before adding the method; do not
  invent slot fillers.
- Mixed files still hold rows of this TU: AptLobbyScreenInitCallbacks.cpp,
  OpaqueScalarDeletingDtorsB11.cpp, AptHeroPowerText.cpp (split lane).

## Audits

- Deleted donor paths are referenced only by the TU's `// ---- from` provenance
  comments and by explanatory comments in CommandButtonIsReady.cpp and
  parseSpellIndex_Thunk(_Unresolved).cpp (historical, left).
- Pre-push `link_batch_audit.py`: INCONCLUSIVE (census index `14dc3d2467` lacks
  per-object consumer names). No linked-byte gain is claimed.
