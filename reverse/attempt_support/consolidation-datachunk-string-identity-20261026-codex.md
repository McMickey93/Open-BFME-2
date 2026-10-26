# DataChunk counted-reader code identity, 2026-10-26

Separate cleanup following 3e3eb1ce45's header adoption. Its declaration-only
option preserved an existing wrong binding; it did not cause that finding.
The original private AsciiString view also spelled the parent's cleanup call
at retail 0x00036410 as ??1AsciiString, although that destructor owns the
five-byte jump at 0x0048BA39. The source had no registered identity key; the
shadow commit gate surfaced the pre-existing divergent/extent reference.

Removed the per-unit BFME_ASCII_DTOR_DECL option. The canonical inline cleanup
now emits the direct releaseBuffer call, which is the actual owner at
0x00036410. The unwind still calls the destructor at 0x0048BA39. This supersedes
the preceding handoff's recommendation to preserve the parent's destructor
spelling. No new name, alias directive, pin, compiler flag or receiver change.

Verification:

- `./build.sh .../DataChunkInputReadAsciiString.cpp`: all 3 rows/188 bytes exact.
  `eh_verify.py`: one EXACT graph, zero missing/failing; independently placed
  funclet $L1232 at 0x00779BE7 (was $L1226 after adoption, ledger $L413).
- Preserved before/current COFF objects plus upstream allowed-symbol scan:
  nine reference facts before/after. Exactly one changes, parent relocation
  +129: ??1AsciiString/divergent/extent -> releaseBuffer/owner at 0x00036410.
  Wrong findings 1 -> 0; the other eight facts, including unwind cleanup,
  agree. The raw function bytes remain identical; only that external code
  binding changes, apart from ordinary local EH section renumbering.
- The added five-byte destructor COMDAT is independently certified retail at
  0x0048BA39 by Identity.certify. Its digest d08bf29c9c2b matches 2640 other
  copies, and the selected provider remains WWLib/ascii_string.obj. Other
  external code definitions, data facts and alias directives agree; undefined
  destructor becomes internal, and releaseBuffer becomes its explicit target.
- `link_check.py --prepare-current --paths-from
  build/codex-session6-datachunk-identity-sources.txt`: strict provider receipt
  accepted, no closure/census/index/status change. Frozen, class, CSV and
  converged-data checks pass. Local comparison receipts are under
  `build/codex-session6-datachunk-identity-*`.
- `repair_queue.py retire identity SOURCE` reports no key for this source and
  changes nothing. Thus one proven finding fixed, zero registered identity
  debt retired; do not count it as baseline shrinkage. Header debt remains
  retired by the previous supported acceptance.

Current scoped planner regenerated at
`build/consolidation/datachunk-identity-session6`; its check passes. Missing
seed reader declarations and the remaining DataChunk composition blockers
from the prior handoff remain. No merge/downstream Luna landing claimed.

Publication audit: pending 022d9b9a58..3e3eb1ce45 plus this staged change still
has no outgoing game-source moves/deletions/renames or new path consumers.
The complete pending path audit in the preceding handoff remains applicable;
only this unit's existing cleanup option changes. Incoming origin differences
are distinguished from outgoing changes using the merge-base and commit list.
Protected debt registers remain unchanged in this commit. Files removed 0,
registered identity debt retired 0, recovered C++ bytes 0. Keep source and
handoff claims until publication.
