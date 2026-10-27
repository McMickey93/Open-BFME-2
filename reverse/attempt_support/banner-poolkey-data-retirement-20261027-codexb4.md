# AllowBannerSpawnUpgrade local storage index repair

Inspected at `dbce5d0f8e6124bc9bba8176206577808ca4824d`, 2026-10-27,
seat codexb4.

The data picker claimed AllowBannerSpawnUpgradePoolKey.cpp for its registered
guard spelling at RVA 0x00A03F3C. The first supported retirement refused without
changing the register: the current object names both key and guard under
getModuleNameKey, while the index still names rva004B8520 and the former
external g_Va00E03F3C.

Commit `8ca40fecae` renamed the getter; `5bfb5b3ad2` retired the standalone
guard clearer in favor of the parent's compiler-emitted rollback at 0x0078F17C.
GlobalFlagClearers_E03Fxx.cpp now defines only g_Va00E03FC8. The native key and
guard addresses, function ownership and source code are unchanged here.

`python3 tools/data_ledger.py --out build/codexb4-banner-data-ledger-20261027.csv`
generates 34,410 addresses and reports one matched source without an object.
Only its exact generated rows for 0x00A03F38 and 0x00A03F3C are copied into
the committed index; unrelated generated inventory is excluded. Both are
four-byte owned globals in AllowBannerSpawnUpgradePoolKey.cpp, each with one
definition and respectively two and four matched relocation references.

Validation:

- Normal `./build.sh` verifies all four rows and the name literal.
- `eh_verify.py` reports one EXACT graph, none baselined or missing.
- `find_declared_unmatched.py` reports all definitions already matched.
- `data_check.py` reports zero findings. Its enforced converged check covers
  ten addresses with zero second names or unjudged rows.
- `repair_queue.py retire data` passes, removing one registered key with
  zero remaining source findings. Only this tool removes the baseline line.
- Ordinary `link_check.py` preserves LINKS, 113 -> 113 authored bytes, against
  index bf3dd31211 (2026-10-27 00:39, retail-truth-4).
- `check_csv.py` and `git diff --check` pass.

The initial default link draw served Rva00081F03Cleanup.cpp's historical
BFME_DX8_Thread_Lock selected-copy blocker. All three rows verify. Its current
object alone still reports the stale-index blocker; paired with the current
BfmeDX8ThreadLock.cpp provider, both preview LINKS (228 and 247 authored bytes).
This confirms the existing LINK-106 repair. No source repair, new census gain
or image-ownership measurement is claimed for either scope.
