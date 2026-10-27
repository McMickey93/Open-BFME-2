# Shader filter storage and stale data debt

Date: 2026-10-27. Control: c5dc2d6968. Ordinary-preview index:
73061d9452 (2026-10-27 14:34 UTC). Scope: W3DShaderManager.cpp,
W3DShaderManagerShutdown.cpp and W3DShaderManagerStartRenderToTexture.cpp
under Code/GameEngineDevice/Source/W3DDevice/GameClient/.

## Target facts and change

The merged manager TU defined both `g_00DE1F5C` and
`W3DShaderManager::m_currentFilter` for retail RVA 0x009E1F5C. Its two
free helpers used the former; the constructor and other two consumers used
the latter. The explicit data row still assigned the anonymous definition.
The selection helper writes its index on success; the dispatch helper clears
the slot when its filter is null. The native constructor and shutdown clear
the same four-byte slot. The next member starts at RVA 0x009E1F60.

Both helpers now use the existing class static, with friend declarations
preserving its protected linkage. The redundant definition is removed and
the existing four-byte data row transfers to that static. This reconciles an
existing name; it does not establish a new original identifier from donor
evidence. No donor source was required for this repair.

Read-only comparison of retail operands and current COFF DIR32 relocations
finds all six references to VA 0x00DE1F5C bound to
`?m_currentFilter@W3DShaderManager@@1HA`:

| Row RVA | Offset of operand |
| --- | --- |
| 0x00075480 (constructor) | +11 |
| 0x000756BF (selection) | +40 |
| 0x000756F1 (dispatch) | +43 |
| 0x0007684A (shutdown) | +24 |
| 0x00075BD8 (startRenderToTexture) | +108, +311 |

The manager object defines one class static and no `g_00DE1F5C` symbol.

## Index and register

`tools/data_ledger.py --out build/codex-shader-data/data-ledger-after.csv`
generated the scratch index after the repair (34,386 addresses; one unrelated
missing matched object). Only its exact rows at 0x009E1F24 and 0x009E1F5C
are adopted into the committed index. They record the current shader-table
provider and the single filter-state owner. This is a scoped refresh, not
a claim that the whole index is fresh or all shader data is converged.
W3DShaders at 0x009E1F24 still has two definitions and remains provisional.

`tools/repair_queue.py retire data` independently retires ten stale keys for
shutdown and one for the manager, with zero remaining findings. This resolves
the earlier shutdown retirement blocker recorded in re_attempts.log: the
real shader table and class static now have current provider evidence.

## Verification and remaining work

- `./build.sh` on all three sources: 23/23 rows match; five data rows,
  three strings, two floats and sixteen named imports verify.
- Frozen-file checks pass for all three sources. `eh_verify.py` reports
  four EXACT parents and no baseline or nonexact parents.
- `data_check.py --enforce` on all three: zero findings, zero outside baseline.
  `--converged`: ten protected addresses, zero second names or unjudged refs.
- Ordinary previews preserve LINKS for shutdown (367 authored bytes) and
  startRenderToTexture (378 authored bytes).

The manager preview still fails on duplicate Select, Dispatch, Check and
Get helpers plus duplicate/wrong-selected `g_Va001FDE58`. Their deleted
donor objects remain in the published index after merge 909ee98e53, the
existing LINK-122 limitation. The duplicate/wrong-selected `g_00DE1F5C`
finding present before this repair is gone. The manager preview is still
inconclusive; carry it into the next normal maintainer census after stale
objects are removed. No census-linked-byte or image-ownership gain is claimed.
