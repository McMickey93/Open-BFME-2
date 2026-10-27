# DX8 wrapper destructor identity retirement

Inspected `b8ac4b22c1`, ordinary-preview index `bf3dd31211` (2026-10-27
00:39). This repairs five code-identity keys, without changing game source,
function ownership, addresses or the number of pins.

## Completed proof

The existing pins for `DynamicVectorClass<StringClass>::~DynamicVectorClass`
at RVA `0x00121E20` and
`DynamicVectorClass<RenderDeviceDescClass>::~DynamicVectorClass` at
`0x00125D70` lacked machine-checked fold receipts. The native owners remain
the corresponding `VectorClass` destructors, respectively 67 and 70 bytes.
The native deleting destructors at `0x001243E0` and `0x00125FA0` call those
addresses; that target observation alone was not treated as a fold proof.

For each existing name, `pin_consistency.py --symbol` reports one consistent
body. `pin_admission.fold_proof_problems` accepts the whole emitted body and
all relocation bindings against every ledger owner. Its receipts each bind
only the proposed destructor to its existing address, using the actual kept
`dx8wrapper.cpp` object. Both old pins were removed and re-added through
`tools/pin_admission.py --add`, with `fold-proof=` naming this source. There
are no new names or addresses and no hatch-register change.

`repair_queue.py retire identity Code/Libraries/Source/WWVegas/WW3D2/dx8wrapper.cpp`
then retired three string-vector keys and two descriptor-vector keys. The
five retired callers are the two scalar deleting destructors and the three
static table teardown routines. Eight descriptor constructor/destructor keys
remain registered. The full source scan checks 692 references: 528 owner,
58 label, 58 alias, 21 EH, 14 fold and 13 wrong/unknown references (six rows).
Repeated references account for the difference between references and keys.

## Verification and provider prerequisites

- Normal `./build.sh` verifies all 230 function rows and 13 data rows in
  `dx8wrapper.cpp`, including 79 funclet labels resolved through parent EH.
- The former LINK-061 literal-funclet-label refusal is no longer present.
  Retirement initially refused 21 missing ledger objects and one stale
  participating provider. Normal `./build.sh` over those 22 sources passes
  all 404 function rows and three data rows; retirement then gives a complete
  verdict rather than an incomplete-provider refusal.
- `pin_consistency.py --check` passes. The declaration check reports the
  existing 19 unclaimed definitions and no newly unmatched function.
- `link_check.py dx8wrapper.cpp BfmeDX8ThreadLock.cpp` predicts 2/2 LINKS,
  28,658 and 247 authored bytes. The caller alone still reports the old
  thread-lock selected-copy blocker in this index; the current provider
  clears it. This confirms LINK-106's existing repair, not a census gain.
- The first picker target, `W3DDisplayRva0004A462.cpp`, likewise needs no
  source repair: all seven function rows pass, and the paired current-provider
  preview is 2/2 LINKS (1,432 and 247 authored bytes).

## Remaining descriptor work

The selected `DynamicVectorClass<RenderDeviceDescClass>::Clear` row at
`0x00125C60` (67 bytes) still references the unresolved descriptor destructor
identity. The real `RenderDeviceDescClass` header and the local
`BfmeEnumerationDesc` view now have the same 1,464-byte layout, nine strings,
D3D9 caps/adapter fields and resolution vector. Their constructor (417 bytes,
`0x001221B0`) and destructor (225 bytes, `0x00122360`) have equal instruction
bytes outside relocation fields, but the identity scan cannot place the
resolution-vector vtables under the alternate names. Equal masked bytes do
not establish a second native identity.

Next reconcile these views and the native owner names with adequate naming
evidence, preserving enumeration, assignment, public API, EH and vector
bindings together. Do not add constructor/destructor alias pins as a substitute
for that reconciliation. No descriptor source trial or rename was retained.
The eight remaining keys are not a byte-matching regression.
