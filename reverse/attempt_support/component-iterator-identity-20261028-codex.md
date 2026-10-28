# Component callback iterator identity

Inspected BFME 2 revision `e1b88db116ad`; provider index `14dc3d2467`,
2026-10-28 02:44 UTC. Scope:
`Code/GameEngine/Source/GameClient/Rva00462710ModeCheckForEach.cpp`.

## Target facts and existing ownership

The rowed 95-byte `for_each` at RVA 0x004113F4 calls RVA 0x00411084 at
operand offset 40. The ledger already gives that 22-byte body to
`Rva000411084::next` in `EvaMessageName.cpp`. Its lazy bucket advance calls
the existing 47-byte `Rva000411084::advance` in `EvaBucketAdvance.cpp`.

The component TU instead emitted a separate STLport iterator increment and
bucket-advance family. The increment's masked bytes agree with the native
22-byte helper, but its bucket-advance relocation names a different template
specialization. That is insufficient evidence for a second identity at the
native address. The source had one registered wrong binding.

## Change and limits

Specialize the rowed `for_each` loop to advance through the existing two-word
cursor ABI view and call the established `next` owner directly. The loop still
invokes the component callback on each original typed iterator value. `inline`
preserves the original select-any COMDAT strength of this specialization.

This reuses existing ownership; it does not recover a retail class name or
assert that Eva and component records have the same layout. No donor facts,
new pins, aliases, hatches, ledger rows or provider source changes are involved.

The final 95-byte body is byte-for-byte identical to the previous object;
its call relocation at offset 40 now names `?next@Rva000411084@@QAEPAXXZ`.
No external code definition is added. Seven formerly emitted external COMDAT definitions
from the component iterator/bucket family disappear; the outgoing batch audit
must assess their consumers.

An initial iterator `operator++` specialization also matched, but the frozen
source checker could not associate its typedef spelling with a row. It was
replaced with the explicit specialization of the already-rowed loop, without
adding an unmatched-body exemption. A non-inline loop specialization also
matched but changed symbol strength, so the final specialization is inline.

## Verification

- `./build.sh` on the component TU: all six rows exact, including both verified
  funclet bindings; string, float and import checks pass.
- Existing `EvaMessageName.cpp` and `EvaBucketAdvance.cpp` providers were
  byte-verified before the change. The stale `PlayerUpdate.cpp` provider was
  refreshed through `./build.sh` before the retirement check.
- `find_declared_unmatched.py --fail`: all definitions already matched.
- `eh_verify.py`: one graph EXACT, none baselined or missing.
- `allowed_symbols.py --source`: 17 references, 10 owner, 5 fold, 1 EH,
  1 alias, zero wrong bindings (previously one).
- `repair_queue.py retire identity SOURCE`: one key retired, zero still found.
- Before and after ordinary `link_check.py` on the component TU and both
  providers: 3/3 LINKS, 566 -> 566 authored bytes (307 + 212 + 47).

The result is one retired identity debt key with matched and preview-linked
coverage preserved. No new census or image-ownership result is claimed.

## Outgoing audit follow-up

Repair commit `5b1a2c883a` passed the normal pre-commit gates and was handed to
the fleet publisher. The batch audit against base `e1b88db116ad` initially
lacked a strict compiler receipt for the changed TU. `link_check.py
--prepare-current SOURCE` then prepared a strict reusable receipt and passed
the same six-row byte gate. The follow-up audit exits 2, **INCONCLUSIVE**:

```
link batch audit: INCONCLUSIVE baseline: index at 14dc3d2467, outgoing base e1b88db116ad11c6c1ec34b2bd99503a3501ef76; findings below are provisional since-index changes
link batch audit: INCONCLUSIVE: census index lacks per-object consumer names; fetch a current index
```

The published index was fetched at selection time and was already this
revision. The bounded ordinary previews above pass, but the batch audit
cannot clear external consumers of the seven removed component template
definitions. This removed-provider scope needs the next census; LINK-001
records the remaining verification requirement.
