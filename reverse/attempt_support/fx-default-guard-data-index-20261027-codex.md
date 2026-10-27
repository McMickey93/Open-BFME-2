# FX particle default-module guard index retirement

Inspected at `38e60a3ba930`, 2026-10-27, seat codex.

The default picker claimed `FXParticleSystemDefaults.cpp` for the static guard
at RVA 0x00A02958. Its twelve registered data findings have the same stale
ownership cause. Commit `1302228d15` retired ten standalone guard clearers in
`GlobalFlagClearers_E02Axx.cpp`; `dfba21be9a` retired the other two in
`GlobalFlagClearers_E028xx.cpp`. Their matched parents already own the emitted
rollback funclets, with tombstones in `reverse/deleted_rows.csv`. The old
external guard names have no remaining Code, tools, hook or workflow consumer.
The prior blocked attempt in `reverse/re_attempts.log` identified this index
problem; no source reconstruction or new guard name is needed.

`python3 tools/data_ledger.py --out build/codex-fx-default-data-ledger.csv`
generated 34,362 addresses and reported two missing matched objects elsewhere
in the tree. Only the following twelve complete, unmodified generated rows are
adopted. Each names the current compiler-owned guard in the claimed source,
has status owned, one definition and four relocation sites. No selected
address has an explicit data_rows or converged owner. Four-byte generated
index bounds remain unchanged and are not independent storage-extent proof.
This scoped refresh does not claim whole-index freshness.

| Category | DefaultModuleKey guard RVA | DefaultModuleName guard RVA |
| --- | --- | --- |
| 0 | 0x00A02A1C | 0x00A02A28 |
| 1 | 0x00A029F0 | 0x00A029FC |
| 2 | 0x00A02A74 | 0x00A02A80 |
| 3 | 0x00A02A48 | 0x00A02A54 |
| 6 | 0x00A0294C | 0x00A02958 |
| 7 | 0x00A02AA0 | 0x00A02AAC |

Verification:

- `find_declared_unmatched.py` passes; the normal build verifies all 72
  function rows, twelve literals and twelve empty-string references using
  current dependency receipts. Float and import checks pass.
- `eh_verify.py` reports twelve EXACT parent graphs, no nonexact parent and
  no missing object, including the rowed guard rollbacks.
- Enforced `data_check.py` changes from twelve registered findings to zero.
  Converged checking covers ten protected addresses with zero second names
  and zero unjudged rows.
- `repair_queue.py retire data` independently retires all twelve source keys,
  with zero remaining findings. It performs every baseline removal.
- Before and after ordinary link previews against index `73061d9452`
  (2026-10-27 14:34 UTC) retain LINKS and 1,900 authored bytes.
- `check_csv.py` and `git diff --check` pass.

The source, compiled object, function rows, pins and protected global names
are unchanged. This clears the source's registered data-identity debt under
LINK-007; broader storage closure and census confirmation remain open. No new
census-linked bytes or image-ownership gain is claimed.
