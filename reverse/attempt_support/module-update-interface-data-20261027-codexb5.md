# Shared nine-slot module interface storage

Inspected revision: `139e5e9393`. Ordinary-preview index: `bf3dd31211`
(2026-10-27 00:39 UTC, retail-truth-4).

## Target facts and repair

The constructor at RVA `0x00492402` and destructor at `0x00492439` install
RVA `0x0084DFD4` at object offset `+0x20`. The generated data index already
assigns that address to `_s_dummy20` in `Rva00492402Ctor.cpp`; the destructor
used a separate file-static `_s_dummyDFD4` scalar. Earlier recorded attempts
stopped at the owner's file-static linkage.

Retail holds nine code pointers (36 bytes), followed immediately by the
primary table at RVA `0x0084DFF8`. Its slot targets, in order, are:

`004500A3 0050B5C6 005C4AE5 000D43D0 0047A699 0047A69C 0044EECA 0044F09F 00492543`.

The owner now defines all nine pointers as an externally visible constant
array under its existing provisional symbol. Every pointer names an existing
matched code owner, including the shared folded bodies. The destructor
declares and references that array; its duplicate scalar is removed. The new
matched data row verifies the complete 36 bytes and all nine relocations.
No new pin, alias, class layout, method identity or donor attribution is used.
In particular, these address bindings do not prove the original interface or
the original names of its folded methods.

## Verification and limits

- Before and after, the normal two-source build passes all **29 function
  rows**. Afterward it also verifies **three data rows**, including this table.
  String, float and import-reference checks pass.
- Both sources pass `find_declared_unmatched.py`. The constructor source's
  existing destructor exemption remains; no exemption is added or removed.
- `data_check.py` reports **zero findings** across both sources (previously
  two registered findings). Its enforced converged check reports zero second
  names and zero unjudged rows over ten referenced converged addresses.
- `repair_queue.py retire data .../ModuleUpdateDtors.cpp` accepts and removes
  both registered keys, with zero remaining findings. The register was changed
  only through that tool.
- `eh_verify.py` reports no EH-bearing rows and no missing objects.
- The ordinary current-object preview reports both units **LINKS**, preserving
  their census-linked **909 authored bytes** (860 + 49). The copied pre-edit
  objects were refused as non-current by the preview; no paired before/after
  preview or strict executable closure is claimed.
- `check_csv.py` passes: 98,522 function rows, 15,302 pins and 2,232 data rows.

This repairs storage and retires two data-debt keys. Original module/interface
identities, the other provisional scalar owners and broader dependency closure
remain separate work. Census-linked bytes and image-ownership figures are
unchanged; no runtime result is claimed.
