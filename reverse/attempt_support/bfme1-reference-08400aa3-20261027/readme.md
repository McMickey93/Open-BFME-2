# BFME 1 reference update: old-input control rejected

The proposed advance to official BFME 1 master
`08400aa3f07c4bbac6d652e78d288a70bc779ceb` was **not applied**.
The clean checkout and staged gitlink remain at the previously verified
`e74410b3738a2bb75d626085d9ebfd3406a43ff7`.
The successful freshness stamp was not updated. The reference-file claim was
released after the control finished. No game source, ledger, pin, whitelist or
verifier was changed in this pass.

## Frozen control and actual result

BFME 2 revision: `47d8342e4ce19e640a5046a1f60a8ed4b345585d`.
`old-inputs.json` records the Code tree, function/data ledger blobs, checkout
and staged gitlink. These inputs stayed unchanged throughout the run.
The ordinary `./build.sh` full verification ran through the existing container
lane environment with `BUILD_POOL=1` and model `gpt-6`.

`old-exit.json` records **exit 1**, after **8717 seconds** (145.3 minutes),
at 2026-10-27 17:09:13 UTC. The original process was polled to termination;
it was not restarted. This was reference maintenance, with no new body attempt.

The full log, `old-full.txt`, reports:

- 98,522/98,522 functions across 22,402 sources; 222 emitted STLport
  constructors checked against their owners.
- 31,537 literals, 2,254 empty-string references, 9,117 float literals and
  6,421 named imports verified.
- Pin consistency, module registry and source claims pass.
- DIR32 consistency fails for six vftable symbols.
- Data rows fail for one of 2,229 entries.
- The no-op patch passes. Final summary: two red checks, DIR32 consistency
  and data rows.

These failures occur with the old reference, before attempting the proposed
update. No new-reference full gate was started, and there is no successful
old/new comparison or new census-linked, ownership or matched-byte gain.

## Target facts and repair handoff

The following are absolute native VAs, after subtracting the compiled addend:

| Vftable symbol | Conflicting bases |
| --- | --- |
| `??_7BfmeMsgDN@@6B@` | `0x00BE5838`, `0x00C6CED8` |
| `??_7HashTableIteratorClass@@6B@` | `0x00BCEF9C`, `0x00BCF9AC` |
| `??_7Rva002C00E0Obj@@6B@` | `0x00BFE4EC`, `0x00BFE4F4` |
| `??_7Rva004E7392@@6B@` | `0x00BE5838`, `0x00BFD010` |
| `??_7Rva005CBB0AObj@@6B@` | `0x00BFE4EC`, `0x00C74DFC` |
| `??_7W3DProjectedShadow@@6B@` | `0x00BCEFA0`, `0x00BCF9F4` |

The read-only `dir32_witnesses.py` inspects existing current objects, never
compiles or writes the object cache. Its 304-row name-selected scope reproduces
all six base pairs in 18 native operands, with zero skipped non-funclet rows.
`dir32-witnesses.json` gives each source, function RVA, operand offset and
addend. `dir32-address-owners.json` records the ledger owners at those RVAs.
This is a witness scope, not a complete consumer or selected-provider audit.

Several conflicting references are in empty virtual destructors registered
with `fold-proof=`, while other references to the same symbol are in their
constructor/caller views. **Structural lead, not a completed recovery:** inspect
the base/derived contracts and resolved data relocations before accepting these
folds. A shared masked code shape does not prove the same vftable target.
The ProjectedShadow constructor views also require their actual table owners.
The evidence does not establish replacement class names or approve a TU move.

The data failure is
`?bfmeCameraProjectionOverride@@3_NA` in
`Code/Libraries/Source/WWVegas/WW3D2/camera.cpp`: its one-byte size remained
unproven because the generated sizeof probe failed. The captured compiler
text contains the `/EHc-` override warning, without a definitive cause.
`camera-size-probe.json` preserves the generated probe. No isolated rerun was
performed and no transient-failure or false-reject verdict is claimed.

Next: check these versioned findings against current master, claim the affected
scope, reconcile the actual class/table contracts and diagnose the isolated
camera probe. Retain matched coverage and verify consumer/provider bindings.
A passing old-input control is a prerequisite for resuming this reference
advance. Neither a whitelist addition nor a skipped check is part of this work.

## Proposed donor inputs, kept separate from target facts

Official upstream was fetched once. `input-change-audit.json` records 31 changed
paths, including ten game C++ paths and no changed headers, toolchain, baseline
or vendor inputs. Existing layout directories resolve; no layout migration was
needed. Nested BFME backreferences were not initialized.

The final dependency audit ran after the old gate terminated. It inspected
24,058 receipts, with zero references to the changed donor paths and zero
unreadable receipts. This is an input audit, not a passing full gate.

A broad donor-source sweep was not run: the reference contains VP6 decoder
sources, which this seat must not read. `affected_donors.py` instead streams
the proposed revision's ledger through a narrow path filter, then inspects
only retail bytes for the ten changed non-VP6 paths. It reads no donor source
text and does not overwrite the ordinary sweep cache. The scoped audit selects
405 ledger rows and inspects 256 bodies: 24 unique native placements, 79
ambiguous placements, 148 with no exact placement and five without a useful
needle. These are native observations only; no global sweep control-floor,
donor identity, source eligibility or source-transfer claim is made. No donor
implementation or cached compile-trial verdict was used to justify adoption.
