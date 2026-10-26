# GlobalLanguage parser prerequisite, 2026-10-26, codex

Allocated family A shard 0/2 destination:
`Code/GameEngine/Source/GameClient/GlobalLanguage.cpp`. The runner's --check-tu
returned 0; the current scoped GameClient planner and its original-path,
alternative and prerequisite packet were reviewed. Its --check passed after
the edit and after the ordinary trial. Routing was rebuilt in memory; the
committed TU map was not regenerated.

## Repair and demonstrated acceptance

The seed's existing private INI view omitted `AsciiString getNextAsciiString()`.
The clean parser donor already declares that exact member and calls the verified
233-byte owner at RVA 0x0002EA4F. Add its declaration to the seed; no body,
receiver layout, calling convention, flag or symbol spelling changes.

Spell the existing global declaration as `extern class GlobalLanguage *...`
so the pointer type is declared when composition moves the complete class.
This introduces no second global or alternate symbol. The global identity and
all existing data definitions remain unchanged.

Before: ordinary `tu_skeleton.py --merge TU --dry-run` returned 2, accepted no
donors and rejected the parser because INI lacked getNextAsciiString.
After: the ordinary trial returns 0 and accepts exactly:

- `Code/GameEngine/Source/GameClient/GlobalLanguage.cpp`: 5 rows, 649 bytes.
- `Code/GameEngine/Source/Common/INI/StringEntryParserRva001EAD69.cpp`: 4 rows,
  133 bytes (107-byte parser plus its three EH rows).

The now-compatible composition preserves **9 rows / 782 existing retail bytes**.
Four rows / 133 bytes become newly admissible relative to the initial trial.
The supported tool's census link guard admits this composition; all six clean
sources in the investigation are census-linked. No merge was applied. The
compatible donor remains for Luna; no subsequent Luna landing is claimed.
This is prerequisite progress, with zero recovered C++ bytes, zero actual file
reduction, zero debt retirement and zero hatch change.

## Verification and provider/consumer evidence

`./build.sh TU PARSER` before and after: 9/9 rows and three data rows pass,
with five string literals, one empty-string reference, one float literal and
thirteen named import references. `find_declared_unmatched.py TU PARSER` passes.
The supported EH verifier is run for both sources.

The complete object comparison (debug sections excluded; SafeSEH handlers
compared by their symbol names) preserves all 79 existing sections: 70 seed,
nine parser. Section payloads, relocations, external names and COMDAT selection
policies are unchanged. The code-identity scan checks 24 references (15 owners,
seven aliases and two EH references), with zero wrong bindings and no before/
after delta. Data reference/definition facts are identical; enforced data_check
finds zero issues, and its converged check finds no second names or unjudged
rows across the ten registered addresses.

`link_check.py --prepare-current TU PARSER` byte-verifies the two explicit
providers with strict reusable receipts. It does not run a link cycle, update
census status or establish a new headline linking result.

The accepted composed object `build/tu_skeleton/ec6ed0dd35318892.obj` is checked
against the complete current union of both standalone objects: all 28 code
providers and all 41 data symbols match, including code bytes/relocations,
data payloads/relocations, COMDAT selection policies, alternatename bindings,
data reference/definition facts and unresolved externals after internal
resolution. No code provider or external reference was added, removed or
changed. There are no conflicting shared definitions. This evidence is
separate from byte matching and the supported admission guard.

Scratch evidence prefix: `build/codex-session9-globallanguage-`:
`before-build.txt`, `after-build.txt`, `before-trial.txt`, `after-trial.txt`,
`section-proof.{py,json,txt}`, `refs-proof.py`, `reference-delta.json`,
`data-proof.py`, `data-delta.json`, `identity.txt`, `data-check.txt`,
`converged.txt`, `prepare.txt`, `eh.txt`, `composition-proof.{py,json,txt}`,
and the two standalone before-objects and seed backup. The report files are
local evidence, not additional authored or recovered source.

## Remaining blockers

The ordinary trial still rejects constructor and destructor composition: the
complete GlobalLanguage declaration is required before the field table's
parseFontDesc member pointer. Their independent private layouts and list value
types also need a real ABI reconciliation. The list-clear donor fails because
Rva001EA443 is not declared before template use; onGameEngineExit fails LPCSTR/
calling-convention declaration ordering. Three mixed donors remain untouched:
StringRecordCopyBFME2.cpp, stlport_list_001ea478_insert.cpp and
stlport_list_create_nodes.cpp. Do not manually split them or guess a common
layout. The existing inline x87 helper was not edited.

## Complete pending-batch path audit

After fetching, the pending commits are the Smudge static-owner consumer fix
82534d015b, GameFont bank ff61936194 and UserPreferences bank ab2bb13ccc, plus
this in-place prerequisite. The exact pending commit/path lists are saved under
the scratch prefix. The outgoing commit set is origin/master..HEAD; the path
delta is measured from its merge base to avoid classifying incoming upstream
changes as our moves. There are no pending source moves, deleted donors or new
header/include consumers. No active tool, hook, workflow, build input, include,
registry or source history requires repointing. Historical EA path evidence is
preserved. The Smudge data retirement/alias shrink follows its owner tools and
remains the only protected-register change in this pending batch. Header queues,
code-identity keys, TU ownership and all other protected registers are unchanged.
The earlier landed Smudge move-free audit remains in its own handoff; its
inconclusive stale-index push report is carried into the next ordinary census.

Keep the destination, parser and this handoff's file claims until publication
is confirmed. Then release those file claims and run claims.py release --landed.
