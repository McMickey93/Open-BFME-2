# Particle info lifetime and dispatch prerequisite

Inspected BFME 2 revision: `eba54d75878625c80bb00d011aad441c26bace8c`.
Model: `gpt-6`; lane R; body budget 30 minutes; verdict **blocked**.
The production source was restored and its normal small build passed again.
No function row, pin, header, register or source change is retained.

## Target and current evidence

`Rva0056224FCtor.cpp` owns the 87-byte constructor at 0x0056224F, the
376-byte constructor at 0x00562366 and their existing lifetime/EH rows.
The seven-row control passes. The native Windows reference comparison at
`a32b57717fbe` also reports this class's vftable symbol resolving to
0x00C1D358 in construction and 0x00BBB554 in teardown. The complete comparison
is linked by `20261027-bfme1-reference-refresh.md`; the short relevant lines
are preserved in `native-run-conflicts.txt`.

The constructor's native table at 0x00C1D358 has four entries:

| Slot | Native code RVA | Observation |
| --- | --- | --- |
| 0 | 0x004A10FD | Deleting lifetime; its complete emitted counterpart still needs checking. |
| 1 | 0x000B3FD0 | Empty post-process implementation. |
| 2 | 0x003AE26A | Returns `RenderObjectParticleUpdateModuleInfo` from 0x00C1D368. |
| 3 | 0x005622A6 | Existing transfer body: version, twelve floats and rotation type. |

The destructor at 0x0049B47C is `C7 01 54 B5 BB 00 C3`: it restores the
canonical Snapshot table. The existing comment's deduction of
BoxEmissionVolumeInfo identity from the folded destructor name is therefore
unsupported. The literal is a target naming lead; no class rename or original
namespace claim is made here.

The 0x00562366 constructor installs another four-entry secondary table at
0x00C1D348. Its native words target code RVAs 0x003A5A48, 0x000B3FD0,
0x003ACAFA and 0x003ACB00. It needs its own complete dispatch contract too.

## One tested candidate

`candidate.patch` adds the canonical `Common/Snapshot.h` include and derives
the existing info view from Snapshot. It corrects the misleading identity
comment without inventing a new class name. It adds no pins or aliases.

The candidate passes all seven existing function rows, all three EH-label
fallbacks and the post-edit frozen-file check. The official DIR32 guard,
restricted to those seven freshly verified rows, reports six symbols with
zero inconsistencies (`candidate-dir32.txt`). This is a scoped result,
not a new full-tree control.

The same ordinary index, `73061d9452` (2026-10-27 14:34), predicts LINKS for
both before and after, with 480 authored bytes in either state. Both tool
outputs independently print the historical index's 473 -> current 480;
**that seven-byte difference predates this attempt**. The attempt's own
comparison is 480 -> 480. No new census, closed-strict credit, matched bytes
or image ownership is claimed.

The passing code and preview do not establish a correct data provider.
`native-table-proof.json` shows that the candidate emits a 16-byte info
table, but slots 1, 2 and 3 all name `__purecall`, unlike the native table.
The first deleting-lifetime entry also lacks a complete native proof here.
Landing this candidate as a complete class repair would overstate the result.
The source was restored, then verified through `./build.sh` again; the normal
builder restored cache currency. No object or dependency receipt was copied
back into `build/match/` by hand.

## Prerequisite for resuming

Recover the actual info and secondary-table interfaces as one coherent class
scope. The name getter is currently a free integer-returning placeholder in
`ConstIntGetters4.cpp`; the transfer implementation is a separate
`Rva005622A6` nonvirtual view. Their real Snapshot override signatures,
owners, the empty post-process entry, deleting lifetime and the derived
secondary overrides need reconciling before either table is admitted.
Keep existing coverage and verify every affected consumer/provider together.
The current TU map must approve any move; this evidence approves none.

The single result was recorded through `re_log.py`; there is no partial score
or stash because function-byte matching was already exact. The patch is
handoff evidence, not landed progress. Claims were released after the source
and cache were restored.
