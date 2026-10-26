# Narrow-string constructor identity debt retirement

Inspected BFME 2 `d76f1e98745f8ec4430a678f17c57358ad419703`.
The default picker claimed allocator constructor 0x000270D0; the companion
fill-constructor source was separately claimed for the same cause.

Both complete sources already contain the allocation-call repair from
`7a90bdc5bd`: the native call at 0x00007460 names the existing
`basic_string<char>::_M_allocate_block` owner rather than the private
`_String_base<char>` spelling retained in the identity register. The earlier
[constructor evidence](narrow-string-ctor-link-20261020/README.md) was read.
No source, pin, row, compiler option or provider definition changes here.

Verification:

- `find_declared_unmatched.py` passes for both sources before and after work.
- Normal `build.sh` preserves all six rows: allocator constructor 124 bytes,
  fill constructor 177 bytes, two 11-byte funclets and two 10-byte handlers.
  Both renumbered funclet labels resolve through their verified parent EH data.
- `eh_verify.py` reports two EXACT graphs, no exemptions and no missing objects.
- The first identity retirement refused without writing: 73 ledger objects
  were missing and the XferBlockWriter_rva009D86E0_Rva0060CB97.cpp provider was
  stale. Normal scoped `build.sh` refreshes that provider and the missing
  sources; the latter check passes 389/389 function rows, four data rows,
  39 string references, 17 float references and 254 named imports.
- `link_check.py --fetch-index` fetches index `5ce093a71a` (2026-10-26 19:02)
  and imports 21,834 cached objects. No measurement or index publication runs.
- With current inputs, `repair_queue.py retire identity SOURCE` passes for
  each constructor, removes exactly its one stale key and reports zero
  remaining findings. Only that owning tool edits the register.

The committed census already lists both units as linked. These two retired
keys are the result; no new matched bytes, linked bytes or ownership gain is
claimed. Other string-family identity and provider prerequisites remain
separate work.
