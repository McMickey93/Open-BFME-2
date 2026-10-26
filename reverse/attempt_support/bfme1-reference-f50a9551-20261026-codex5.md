# BFME 1 reference freshness, 2026-10-26 (codex5)

The ignored local freshness receipt was older than 72 hours. The clean BFME 1
checkout agreed with BFME 2's committed gitlink,
`001ccd8e27686e9887235b62ff797627f2dde7f5`. Official
`Open-BFME/Open-BFME-1` master was fetched and independently checked with
`git ls-remote`: the fixed update target is
`f50a955121cf51d7a4dee61376c590aaac415056`. No dirty or unpublished submodule
work is discarded, and nested cross-repository references are not initialized.

The comparison keeps BFME 2 at `e1ecb55890879407f363b5f925f868b922eef3bc`,
with Code tree `f77e4570f33a99ec2b2f0d92465c1b11fea51984` and function-ledger
blob `6b240d2fc9011fc3eb989548dad1c6356cfddb26`. The upstream difference has
36 paths, including 19 C++ source paths. It changes no headers, toolchain
settings or reference layout. The existing `game/` and `inputs/reference/`
layout resolver remains applicable. An audit of 24,613 local dependency
receipts finds zero intersections with changed reference paths; the build
still applies its normal dependency-currency checks.

Scratch input evidence is `build/codex5-freshness-20261026-inputs.json`.
Old/new full verification logs are
`build/codex5-freshness-20261026-{old,new}.log`.
This maintenance claims no new matched bytes, census gain or debt retirement.

The old-pin `./build.sh` exits zero with FULL GATE: OK: 98,269/98,269
function rows across 22,735 sources, 2,217 data rows, 31,537 string literals
plus 2,257 empty-string references, 9,116 float references, 6,419 imports,
DIR32 consistency, pin/module/source checks and the no-op patch all pass.
The new-pin gate uses unchanged BFME 2 sources and flags, with runtime
parallelism increased from BUILD_POOL=8 to 16. Its initial dependency check
finds all 22,734 compiled function providers current.

`python3 tools/bfme1_sweep.py scan --min-size 16` exits zero at the new
reference: 5,538 unique placements, all covered, with 5,531 independently
matched exact boundaries, zero free placements and 617 near misses. The
scratch match.json SHA256 is
`9e0257f8b2ce2e30ea1b8310c652790b39896c80e4fea370546341ea7670f1a4`;
build/bfme1_sweep/codex5-20261026-inputs.json records the command and donor
revision. The previous scratch output is preserved separately without
claiming it is fresh. No compile trial involving changed BFME 1 sources is
reused as current evidence.

The new-pin full gate also exits zero with FULL GATE: OK and the same passing
counts as the old-pin run. Neither run has a residual failure. Only after both
runs and the donor refresh pass is build/bfme1-last-check.txt stamped with the
verified/upstream f50a9551 pointer. CSV integrity passes. The update moves no
production source path and needs no build-input or source-registry repointing.
