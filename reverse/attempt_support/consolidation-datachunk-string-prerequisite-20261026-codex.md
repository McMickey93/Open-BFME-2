# DataChunk counted-string header prerequisite, 2026-10-26

Sol codex family A shard 0/2; allocated DataChunk.cpp (`consolidation_queue.py
--check-tu` exit 0). Current in-memory `tu_skeleton.py --plan` routes this
three-row reader to that destination. Source and queue claims held before
editing. Reviewed prior DataChunk scalar/API and Mapping-boundary handoffs;
this does not retry or bypass Mapping's naming/identity refusal. The scoped
Common/System planner was regenerated after this repair at
`build/consolidation/datachunk-session6`; its currency check passes.

The reader's queued AsciiString adoption failed because the canonical wrapper
has no getBufferForRead member. Removed the private AsciiString/StringBase
bodies and included the registered header. Access the existing four-byte
StringBase<char> representation explicitly, as the wrapper itself does.
Use its existing BFME_ASCII_DTOR_DECL option because this reader and its
unwind call the out-of-line destructor. The initial default-header trial was
byte-exact but emitted a new destructor provider; the declaration option
preserves the original external calls instead. No compiler flags, shared
header, pin, global or inferred identity changes.

Acceptance and provider evidence:

- Before/after `./build.sh .../DataChunkInputReadAsciiString.cpp`: 3/3 exact,
  188 retail bytes. `eh_verify.py`: one EXACT graph, no missing objects or
  failures. Parent EH independently places renamed $L1226 (old $L413) at
  retail funclet 0x00779BE7. Frozen-file and class gates pass.
- `header_adopt_lane.py accept --class AsciiString ...`: PASS; exactly one
  header queue row retired through its acceptance path. No identity/data
  debt retired. `check_csv.py` and `data_check.py --converged` pass (ten
  converged addresses, zero second names/unjudged rows).
- Preserved supported-build objects compare equal for all three surviving
  external code definitions, their normalized relocations, undefined targets
  and external data. All nine scoped allowed-symbol facts agree after
  resolving only the independently exact renamed funclet. Scoped data
  definition/reference facts agree.
- The old object's unused six-byte StringBase<char> default-constructor
  COMDAT disappears. Its digest 595907fb5146 has 23 identical other providers,
  no undefined referrers in current objects; the first provider remains
  RegistryAsciiPath.obj, also first in the published census selection.
  No surviving COMDAT body/policy or provider binding changes. The header's
  seven pre-existing aliases are unreferenced here and already present in
  the pending batch's original FunctionLexicon constructor: alias union
  unchanged. Scratch evidence: `build/codex-session6-datachunk-binding-proof.json`.
- `link_check.py --prepare-current --paths-from
  build/codex-session6-datachunk-sources.txt`: one explicit provider verified
  with strict reusable receipt, no census/index/status or closure claim.
  An earlier preparation overlapped a temporary dry-run source and correctly
  refused changed inputs; rerun sequentially after trial cleanup passed.

Ordinary current full merge dry-run accepts no composition. This reader now
compiles past the string access and stops because the seed lacks
DataChunkInput::readAsciiString; Unicode/readNameKey/readDict have analogous
missing API declarations. Other donors retain Mapping member/name boundary,
wrong AsciiString include resolution, output member/API and compiler-context
blockers. The trial's adopt_first list preceded queue acceptance; the source
now passes the supported acceptance check. No merge applied or downstream
Luna landing claimed. Next narrow candidate: seed input-reader declarations,
with whole-object/provider proof and a fresh ordinary merge trial.

Publication audit covers pending commits 022d9b9a58 and 428ce33a29 plus this
staged change. There are no outgoing game-source moves/deletions/renames.
`origin/master..HEAD` also shows incoming peers' changes as reverse diffs;
merge-base..HEAD and the outgoing commit list isolate this batch. Active
tools/hooks/workflows, includes/build inputs and protected registers need no
path repointing. The new FunctionLexicon header has exactly its two verified
consumers; existing canonical headers and historical EA paths stay in place.
Queue changes are only accepted header retirements. Source files removed 0,
identity debt retired 0, header debt retired 1, recovered C++ bytes 0.
Retain source, queue and handoff claims until publication is confirmed.
