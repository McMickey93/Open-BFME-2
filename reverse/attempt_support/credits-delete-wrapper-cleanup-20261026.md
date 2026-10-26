# Credits delete-wrapper cleanup, 2026-10-26

Inspected BFME 2 revision: `c254d71bb8d3e3257015c9ae2597c8013e021836`.
Scope claimed through the default picker: `0x005B72A5` and
`file:Code/GameEngine/Source/GameClient/Credits.cpp`.

The picker served the historical Credits linking failure. Prior attempts and
LINK-047 establish that the list insertion repair already landed. The initial
local index (2026-10-26 13:18, `d1f046749a`) still reported a duplicate
`famgenDelete005B72E7`, whose donor source was previously absorbed into Credits.
This was a stale-index lead, not a lost matched body.

Removed the unrowed `famgenDelete005B72E7` wrapper and its `present-unmatched`
exemption. `CreditsManager::addText` already deletes the same `Rva005B72E7`
view; the compiler still emits the matched deleting destructor at `0x005B7352`.
No source or shim refers to the removed wrapper. No ledger row, source path,
pin or class identity changed. Removed exactly its hatch-register line:
`present_unmatched` total 4,043 -> 4,042.

Paired verification uses the fetched published index, 2026-10-26 19:02,
`5ce093a71a`, SHA-256
`9259010fbce4dce6a86fd7ea9ead6042f64a87a9f95efe967902188a539a4583`.
The before check temporarily restores the committed source, verifies it, and
restores the cleanup in a finally block. Both previews include the unchanged
`Code/Libraries/Source/WWVegas/WWLib/stlport_list_int_insert.cpp` provider.

- Before and after: `./build.sh Credits.cpp` passes 31/31 functions, its data
  row, two string literals and two compiler float literals.
- Before and after: both units preview LINKS, Credits 3,053 authored bytes and
  the insertion provider 62 bytes. The reported historical 0 -> 3,053 is already
  present before this cleanup; this change adds zero preview-linked bytes.
- Final EH verification: five EXACT graphs, zero failures or baseline entries.
- Final frozen-file check: all defined functions are already matched.
- Final shadow data check: zero findings.
- Supported `link_check.py --prepare-current Credits.cpp` accepts one strict
  reusable receipt with all ordinary byte gates passing. It changes no census,
  index or status, and does not establish strict closure of the dependency graph.
- CSV validation and `git diff --check` pass.

Local raw logs: `build/credits-wrapper-cleanup/{before,after}-{build,link}.log`
and `after-{eh,data,frozen}.log`.

The outgoing audit must distinguish the intentional removal of this unused,
unrowed wrapper from losing a retail provider. The published index predates the
outgoing base; any since-index provider changes are provisional. Census
confirmation remains pending. The wrapper cleanup leaves the separate stale
`insert` fold-proof annotation unchanged; the follow-up below retires it.

## Redundant insertion pin follow-up

Claimed `0x005925E2` and its insertion-provider file lock before removing the
pin. The exact same decorated `list<CreditsLine *>::insert` name already has
its matched 37-byte row at `0x005925E2` in `stlport_list_int_insert.cpp`. Thus
the row supplies the binding, and the pin adds no address or identity evidence.
Removed only that pin, whose fold-proof still named Credits' nonretail inline
copy, and lowered its address's hatch count from 14 to 13. No pin is added or
renamed. This closes the separate pin-proof follow-up from the original repair.

Without the pin, the combined Credits/provider build passes 36/36 functions,
the data row and all literal checks. Pin consistency passes (zero baseline,
new or stale findings), and CSV validation passes with one fewer symbol row.
The same two-unit link preview still returns LINKS for 3,053 + 62 authored
bytes. This is a second hatch retired, with zero new preview-linked bytes.
