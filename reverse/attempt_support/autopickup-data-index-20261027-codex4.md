# AutoPickUpUpdate local-static data index prerequisite

Inspected BFME 2 `e0b5fd882a`, 2026-10-27. The default picker claimed
`file:Code/GameEngine/Source/GameLogic/Object/Update/AutoPickUpUpdatePoolKey.cpp`.
No source, data owner, index or debt-register change is retained for this lead.

The existing source defines the 69-byte `getModuleNameKey` at RVA 0x00495CEC,
its 13-byte unwind funclet at 0x0078CFF3 and 10-byte handler at 0x0078D000.
`find_declared_unmatched.py` is clean, and `build.compile_is_current` proves
the existing object current for its source and headers. The function was
renamed by `788ce59b66`; this is already recovered C++, not an uncovered body.

The committed derived `reverse/data_ledger.csv` still records the function's
old `rva000495CEC` scope for the local key at RVA 0x00A03A50. For its guard at
0x00A03A54 it selects `?g_Va00E03A54@@3IA` from the deleted
`Code/GameEngine/Source/Common/GlobalFlagClearers_E03Axx.cpp`, and lists the
old compiler guard spelling as an alternative. Neither that source nor a
current Code/shim spelling of `g_Va00E03A54` exists.

The current object instead binds these two names:

```text
0x00A03A50 ?TheAutoPickUpUpdatePoolKey@?1??getModuleNameKey@AutoPickUpUpdate@@UBE?AW4NameKeyType@@XZ@4W43@A
0x00A03A54 ?$S1@?1??getModuleNameKey@AutoPickUpUpdate@@UBE?AW4NameKeyType@@XZ@4IA
```

`data_check.py` finds both as wrong-name against the stale index. The baseline
holds only the guard's old spelling. `repair_queue.py retire data SOURCE`
therefore correctly refuses both new findings and writes nothing; a rename
alone cannot retire this key.

A read-only `data_ledger.py --out
build/codex4-reference-20261027/data-ledger-current.csv` regenerates both
addresses with exactly the current object names, the existing getter source
as owner, four-byte upper bounds, one definition each, and respectively two
and four reference sites. Running `data_check.findings` on the same current
source facts with this scratch index returns no findings. The scan reports
1,657 missing matched-source objects elsewhere; it is diagnostic evidence,
not a complete current-object census or authority to replace unrelated rows.

The shared index claim is held by `yasinschroeder-codexb` for the analogous
UpgradeDie local-key/guard refresh, so this seat does not edit it. Next:
coordinate the generated refresh through that owner, recheck these two rows
against complete current inputs, build this source, and run the owning
`repair_queue.py retire data` command. Keep source/row coverage and compiler
guard semantics intact. Do not add a second extern global or replace the
compiler's guard with a hand-written initialization protocol. No debt or
headline gain is claimed by this handoff.

Reference freshness was checked before this work: official BFME 1 master is
`a0940f921b5b8d9029fc922b8032abcf4e60d240`, while the verified committed
pointer remains `4fa9d591641a743b86f2320343b7a276585b814b`. The reference claim
is held by `yasinschroeder-codex`. This seat preserves the clean verified
checkout and does not advance its gitlink or stamp freshness success.
