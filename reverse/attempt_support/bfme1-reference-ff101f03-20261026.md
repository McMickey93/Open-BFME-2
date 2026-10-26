# BFME 1 reference freshness, 2026-10-26 (claude)

Mandatory freshness maintenance before BFME 2 work; not an independent BFME 1
work lane. It claims no recovered bytes, file reduction, debt retirement or
census gain.

The committed pointer at session start is
001ccd8e27686e9887235b62ff797627f2dde7f5 (verified in
`bfme1-reference-001ccd8e-20261026.md`). Its detached submodule checkout was
clean and agreed with the pin; no dirty or unpublished reference work existed.
Official Open-BFME/Open-BFME-1 `master` was fetched and confirmed by
`git ls-remote` as ff101f03e2e533d73b130c24af64ac9760ea70a9, 14 commits ahead.

## Inputs

The upstream difference touches 74 paths: 49 `game/**/*.cpp` sources, its own
docs and `targets/game/reverse/` ledgers, and its nested
`inputs/reference/open-bfme-2` gitlink (not initialized here: no recursion
back into BFME 2). It changes no header, inline/include file, `inputs/`
toolchain or setting, and no layout; the existing `game/` and
`inputs/reference/` resolver still applies. Scanning all 25,879
`build/match/*.deps.json` receipts finds zero intersections with the 49
changed sources.

## Verification

With the clean reference advanced in place and its gitlink staged (so the
reference-pin guard stays active), `./build.sh` at BFME 2 7419f4ac20 exits
zero with FULL GATE: OK in 19.5 minutes: 98,269/98,269 functions across 22,725
sources, 31,537 literals plus 2,257 empty-string references, 9,116 float
references, 6,419 imports, DIR32 consistency, pin consistency, the module
registry, source claims (22,544), 2,223 data rows and the no-op patch. There
is no failure, so no old-pointer comparison run was needed to separate update
regressions from pre-existing ones. Log: build/claude-freshness-20261026-new-full.txt.

## Refreshed derived evidence

`python3 tools/bfme1_sweep.py scan --min-size 16` exits zero against ff101f03:
5,538 unique placements, 5,531 at exactly the claimed RVA and size, zero on
free ground, 617 near misses. New scratch `build/bfme1_sweep/match.json`
SHA256 9e0257f8b2ce2e30ea1b8310c652790b39896c80e4fea370546341ea7670f1a4,
donor revision and command in `build/bfme1_sweep/claude-20261026-inputs.json`;
the previous result is kept aside as `match.pre-ff101f03.json`, not used as
current evidence. No cached compile trial involves a changed BFME 1 source.

The update moves no production source path and needs no tooling, include,
build-input or registry repointing.

## Rebase note

Upstream meanwhile verified and committed f50a955121cf51d7a4dee61376c590aaac415056
(`bfme1-reference-f50a9551-20261026-codex5.md`). ff101f03 descends from it
(9 commits ahead), so this refresh is rebased onto f50a9551 and still advances
the pointer; the 74-path difference above was measured from 001ccd8e. The
pre-push full gate re-verifies the result at the rebased base.
