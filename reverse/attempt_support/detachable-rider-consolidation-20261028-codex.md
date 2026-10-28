# DetachableRiderUpdate transfer composition, 2026-10-28

Owner: `yasinschroeder-codex`. Prerequisite after runner rebase:
`253cb497cc`; inspected upstream base: `ed275ad525`.

The default picker claimed the approved DetachableRiderUpdate TU and its clean
donors. The supported Update-subsystem naming planner was refreshed after the
declaration edit and publication rebase; its currency check passed immediately
before `tu_skeleton.py --merge`. The tool rebuilt the stale placement map in
memory. No map regeneration was committed.

The separately published prerequisite adds the existing virtual module-name
getter declaration to the transfer donor's larger class view. Without it, that
view replaces the seed's smaller declaration and loses the getter. The donor
still byte-builds 1/1; both external COMDAT digests and external symbol records
are unchanged. Standalone seed and donor preview LINKS at index `14dc3d2467`.

## Refused composition and evidence

The ordinary merge accepts only the seed and DetachableRiderUpdateXfer.cpp,
moving the existing 72-byte transfer row at `0x004AE7AD` to its approved TU.
Its census-linked guard accepts the composition. The resulting object passes:

- 7/7 matched rows, one string literal, frozen-file and CSV checks;
- one EXACT EH graph, zero missing objects;
- identical union of 26 external COMDAT byte/relocation digests, 26 external
  definitions, 24 external dependencies and zero weak aliases;
- identical six data bindings, zero separately defined data symbols and zero
  unread rows; converged-data check passes;
- ordinary link preview LINKS for the same combined 849 authored bytes, and
  the new-COMDAT-variant check passes.

The shadow data checker reports the existing getter guard at `0x00A03D60`
under its current name, outside the stale baseline's former `rva004AE832`
spelling. The before/after binding comparison shows no new data binding. That
guard's canonical identity remains separate debt; no register is retired here.

`class_gate.py --staged` passes, but `tu_ownership.py --staged` refuses B1:
"private body of registered class Xfer". Its `CLASS` expression reads
`class Xfer::Version` as class `Xfer` with base clause `::Version`. This is the
existing nested Version operand definition, not a private Xfer definition.
The canonical Xfer header is included through DetachableRiderXferPrefix.h.
The false reject is recorded with `re_log.py`; the entire merge was restored,
including both ledger source columns. No source-file reduction is claimed for
that restored trial. The refused patch and object comparisons are scratch
receipts under `build/detachable-consolidation-20261028/`.

## Registers, consumers and remaining work

The transfer donor has no identity/data baseline, header/MS-header queue,
hatch, flag-override, fold-proof or data-provider key to carry. The destination's
existing data debt and data-ledger ownership survive unchanged. The merge tool
refreshes both affected header queues and produces no queue change.

The combined outgoing path audit at `ed275ad525` covers the 16 previous NAT/SAS
absorptions and the proposed transfer absorption: exact old paths and basenames
across tools, hooks, workflows, Code includes, root tracked configuration,
registries and docs. No executable consumer needs updating. Old references are
donor-provenance comments, two explanatory destructor comments, historical
attempts/logs and census-owned link_status.csv. Function/map references would
be repointed by the merge; no directory is moved and globs keep their meaning.

Remaining clean donors are still refused: constructor/receiver enum order,
duplicate STL `_Construct`, duplicate `__false_type`/uninitialized-copy template,
killRider's DisabledType and class-view context, and the global-flag clearer's
compiler context. Five mixed sources stay intact. The tooling lane should fix
the qualified-class false reject with a regression test in a separate commit
before retrying this unchanged composition. Full selected-provider/consumer
closure still needs the next normal census/index (LINK-017); no new census,
image-ownership or runtime result is claimed.
