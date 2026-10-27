# Buffer-slot FVF table identity

Inspected BFME 2 revision: `1710ea0aea`, 2026-10-27.
Scope: `Code/GameEngineDevice/Source/W3DDevice/GameClient/Shadow/W3DBufferManager_Slots.cpp`.

The data register held one `wrong-name` key: `_SlotFVFTypeIndexList` at
RVA `0x009B5F30`. The data ledger names `?g_00DB5F30@@3PAIA` there.
Current source inspection finds its existing eighteen-entry unsigned-array
definition in `W3DBufferManager_ReAcquireResources.cpp`; the indexed getter in
`GlobalArrayIndexGetters.cpp` already declares that same array. These are target
address/binding and current-owner facts, not evidence of a recovered source name.

Replace the slot unit's private eighteen-entry table with `extern unsigned
g_00DB5F30[]` and use that array in the vertex-buffer allocation call. The
existing definition, global name, ledger rows and headers are unchanged.

Verification:

- Before and after, the slot unit passes all ten matched rows and the declared
  unmatched check. Its two exception graphs are EXACT after the edit.
- The saved control object and final object have identical raw bytes in all
  ten executable sections (1,067 bytes). The old static table definition is
  absent; the canonical array symbol is an undefined external in this consumer.
- The owner and getter pass all six of their matched rows.
- Shadow data checking reports zero findings for the changed source.
  `repair_queue.py retire data SOURCE` removes exactly its one registered key,
  with zero keys still found. The enforced converged-data check also passes.
- Paired ordinary `link_check.py` calls include all three sources that mention
  either table spelling. All three LINKS before and after: slot unit 1,036,
  owner 208, getters 24 authored bytes, totaling 1,268. The published preview
  index is `bf3dd31211`, 2026-10-27 00:39, retail-truth-4.

This retires one data-identity debt item and removes duplicate private storage.
It claims no new census-linked bytes or image-ownership receipt. Wider storage
ownership work in LINK-007 remains open; no maintainer-only measurement ran.
