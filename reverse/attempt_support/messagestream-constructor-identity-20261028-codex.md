# MessageStream constructor identity retirement

Inspected BFME 2 revision `3e03b082b4`, 2026-10-28. No source or register
change retained. The selected keys are the `GameMessage(Type)` constructor
bindings in `MessageStream::appendMessage` (0x0030F6D4, 48 bytes) and
`insertMessage` (0x0030F704, 52 bytes).

## Target and object facts

- Retail constructor 0x0030F47A is 53 bytes. Its existing ledger owner is
  `??0Rva0030F47A@@QAE@PAX@Z` in `Rva0030F47ACtor.cpp`.
- The sole current kept definition of `??0GameMessage@@QAE@W4Type@0@@Z`
  comes from `MessageStream.cpp`. `allowed_symbols.definitions` reports
  digest `397f7d17b6f8`, size 53, exclusive definition.
- Disassembly agrees with retail outside the two DIR32 fields: the vtable
  store at +4 and `ThePlayerList` reference at +10. Retail stores vtable
  VA 0x00C09840 and reads `ThePlayerList` at VA 0x00DFEEE8, then offsets
  +0x10/+0x54. The remaining stores and `ret 4` agree.
- `ThePlayerList` has an explicit verified data row. The vtable name
  `??_7GameMessage@@6B@` has a literal entry at RVA 0x00809840 in
  `data_ledger.csv`, but no `data_rows.csv` home. Literal data-index evidence
  alone is not a verified data row. `allowed_symbols.Identity.certify`
  returns `unknown`; both caller references consequently remain `wrong`.

## Verification and boundary

`./build.sh Code/GameEngine/Source/Common/MessageStream.cpp` passes all 18
non-alias rows and its one data row. Its frozen-file check passes.
`link_check.py --fetch-index` retained the published index at `14dc3d2467`
(2026-10-28 02:44). The ordinary source preview remains LINKS, 573 -> 573
authored bytes. That preview does not certify all data relocations for code
identity and is not a new census result.

The first owning retirement verdict refused because 20 ledger objects were
missing locally. Building those exact sources through `./build.sh` passes
282/282 rows and three data rows. The repeated retirement verdict then reports
both original keys still found, with no new finding and no retired key.

## Next useful work

Establish a supported verified home for the compiler-emitted one-slot vtable,
or recover the constructor identity and its opaque consumers together. The
data-row verifier currently proves named data with `sizeof` probes, COMMON
size or isolated function-local-static COMDAT size; a vftable's section extent
alone is not its supported size proof. Do not add a pin or a guessed data row
to make this diagnostic disappear. The constructor has no approved TU in the
inspected committed map, so moving it also needs current TU evidence.

Prior attempt 0x0030F47A records that a constructor repoint lost linking when
MessageStream itself did not link. The current clean preview changes that
prerequisite but does not resolve the opaque caller identities automatically.
