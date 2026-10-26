# GameSpyColor at RVA 0x009B9198: two names, and BFME2's table is 29 entries

Session: claude-opus-5-5 (agent K6), data-identity lane, 2026-10-26.

Served key: `AptOnlineCustomMatchCallbacks.cpp wrong-name
?TheRva00222A8BTarget@@3PAVRva00222A8BTarget@@A 0x009FE4CC`. The source
already binds `g_bfmeAptWindowManager`, so that key is stale, but
`repair_queue.py retire data` refuses it on a new finding in the same unit:
`wrong-name ?GameSpyColor@@3PAHA 0x009B9198`. Nothing was changed.

Why: `reverse/data_rows.csv` makes `?g_00DB9198@@3HA` (4 bytes, value -1,
`AptOnlineQuickMatchOptions.cpp`) the explicit owner of 0x009B9198. That
address is the start of the real `GameSpyColor` table (Chat.cpp), so every
unit that reads `GameSpyColor[...]` now counts as a wrong-name. The table
users that write `GameSpyColor` include BuddyDefs*.cpp, ChatWindowsOnline*.cpp,
WOLGameSetupMenu.cpp, WOLBuddyOverlay.cpp, GameSpyInfoAddChat.cpp and
AptOnlineCustomMatchCallbacks.cpp. `g_00DB9198` is also used by
AptOnlineCustomMatchMessageHandler.cpp and AptOnlineCustomMatchPlayerTooltip.cpp.

Retail evidence:

- The FieldParse table at 0x007E0428 (`GameSpyColorFieldParse`) has 29
  entries plus the NULL terminator, offsets 0x00..0x70. BFME2's enum
  therefore has 29 colours, not Zero Hour's 27 (`GSCOLOR_MAX` in
  reference/shims/peerdefs/GameNetwork/GameSpy/PeerDefs.h).
- Retail .data at 0x009B9198 (29 dwords): ffffffff ffffff00 ffffffff
  ff808000 ff808080 ff808080 ffff0000 ffff00ff ffff0080 80ff0080 ffff0000
  80808080 ffff0000 ffff8000 ffffff00 ff80ff00 ff0000ff ff00ffff ffff00ff
  ffff80ff ffff00ff ffff0080 ff00ff00 ffff0000 ffffff00 ffffffff ffffffff
  ffffff00 00000000. Chat.cpp's initializer is Zero Hour's 27 values and
  does not match from index 6 on.
- The ledger's unowned `g_00DB91A0`, `g_00DB91B0` and `g_00DB91B4` fall
  inside this 116-byte table (element aliases).

- The FieldParse key strings name the two new entries: index 9
  `OfflinePlayerBuddy` (after PlayerBuddy) and index 12
  `OfflinePlayerIgnored` (after PlayerIgnored); the other 27 keep Zero
  Hour's order. So BuddyDefsSendMessage.cpp's `GameSpyColor[22]` is
  ChatSelf in BFME2's numbering.

What converging takes (not done; too many files for one item): add the two
entries to BFME2's enum (29 values), give Chat.cpp retail's initializer, make a
116-byte `?GameSpyColor@@3PAHA` data row owned by Chat.cpp in place of the
`g_00DB9198` row, and repoint the `g_00DB9198` / `g_00DB91A0..B4` users
to `GameSpyColor[i]`. Changing the shim enum shifts every GSCOLOR_ constant
from PlayerSelf on, so each matched user of a named constant has to be rebuilt
and checked.
