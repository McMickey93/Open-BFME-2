# GameLOD audio header prerequisite, 2026-10-26, codex

Allocated family A shard 0/2 destination:
`Code/GameEngine/Source/Common/GameLOD.cpp`. The allocated runner queue lists
this destination. The Common planner's GameLOD packet, original-path evidence,
alternatives and blockers were reviewed; placement is determined independently
by the current TU routing. No merge or split is applied and the committed TU
map is unchanged.

## Narrow repair

The seed already force-includes the canonical BFME2 AsciiString header through
zh_ascii.h. The clean audio-lookup donor instead redeclares AsciiString as a
private StringBase base. Its existing header-queue entry records the failed
canonical adoption: debug operator<< cannot deduce StringBase from BFME2's
one-pointer AsciiString wrapper.

Use header_adopt_lane.swap to remove the donor's private AsciiString,
StringBase and unused BfmeStringData definitions and include the registered
header. Pass an explicit const StringBase<char> reference view to the existing
streaming operator, as the canonical wrapper does for its own operations.
The receiver address, one-pointer representation and called retail function
remain identical. Correct the stale function-size comment from 124 to the
ledger's verified 130 bytes. This changes no names, compiler flags, layouts,
pins or manually written escape hatches.

## Verified evidence

Scratch evidence prefix: `build/codex-session9-gamelod-audio-`.
The initial scratch Verifier trial matches the row at RVA 0x00202C76 exactly.
The seven non-debug sections retain identical code/data/relocations and COMDAT
policies except .drectve. Code definitions and undefined references are exact.
The directive delta is exactly the seven existing canonical-header aliases;
every one already occurs identically in the seed object and none is referenced
by the donor. Its four code references bind to the expected owners before the
edit. Baseline build: donor 1/1 row; seed 7/7 rows.

The globally claimed `reverse/header_queue.tsv` is held by
`yasinschroeder-codex4`; it must remain untouched. Header retirement is deferred
to that register's owner via header_adopt_lane.py accept --class AsciiString
Code/GameEngine/Source/Common/GameLODManagerGetAudioLODIndex.cpp. No header,
code-identity or data debt is claimed retired by this prerequisite.

## Pending-batch audit

At the audit fetch origin/master is e1cdb1014f. The four pending commits are
82534d015b, ff61936194, ab2bb13ccc and d540d07ecc, plus this in-place repair.
The full outgoing commit set is origin/master..HEAD; the own path delta is
measured from its merge base to avoid counting unrelated incoming edits.
The batch contains no source moves, deleted donors or changed original EA
path evidence. The new include resolves to the existing registered header.
No active tool, hook, workflow, build input or source registry requires path
repointing. Smudge's two data-key retirements and one alias shrink remain the
only protected-register changes in this batch; other debt keys are preserved.

No new C++ bytes or actual file reduction is claimed. Any downstream acceptance
reported below is a dry-run result, not a confirmed Luna landing or census gain.

## Completed checks and remaining prerequisites

`./build.sh` before and after passes the donor's 1/1 row, both strings and all
reference checks. `find_declared_unmatched.py` passes. The header lane's
non-mutating `verdict('AsciiString', source)` returns PASS, running the same
canonical-body/include/byte acceptance checks used by `accept`; its register
mutation is deliberately not invoked while another seat holds the queue.
`allowed_symbols.py` retains four correct owner references, zero wrong bindings
and no before/after delta. Enforced data_check and the converged ten-address
check pass. Data reference/definition facts are unchanged.

The final standalone object repeats the scratch proof: six non-directive,
non-debug sections are exact; the only seventh-section delta is the already
explained canonical-header aliases. No defined code provider, undefined symbol,
code/data payload, relocation or COMDAT policy changed.
`link_check.py --prepare-current TU DONOR` produces strict reusable receipts
for the two explicit providers, preserving all 8/8 rows. The refreshed Common
planner's `--check build/consolidation` passes. No shared header was edited.

The initial ordinary `tu_skeleton.py --merge TU --dry-run` returns 2, accepts
nothing and names this donor's StringBase C2953/C2955 conflict. Its independent
seed rejection reports unresolved `?showShellMap@Shell@@QAE_N_N0@Z` under the
supported LinkGuard, with flag/include conflicts in other combinations. This
is the current guard's finding, not a claim that a retail body is unrowed.

Using the upstream compose, Verifier and redefinition loop, the two-source
comparison tests all four supported declaration strategies under the seed's
flags. Before: all four fail the duplicate StringBase and stream-conversion
errors. After: all four compile and byte-match 8/8 rows / 704 existing bytes.
This demonstrates removal of the audio header prerequisite for one donor/row
(130 existing bytes); it does not demonstrate an admitted full-TU merge.

Compare the resulting object a4ad3e25db155671.obj with the complete current
standalone union: all 25 code providers, 90 data symbols, COMDAT policies,
aliases, data reference facts and unresolved externals are equivalent, with no
new/missing/changed provider or reference. The audio table's real eight-byte
extent is registered at RVA 0x009B96B0 in data_ledger.csv. Section coalescing
places the seed's local `_SECONDS_PER_LOGICFRAME_REAL` immediately after it
and raises the shared .data section's alignment from four to eight. The data
comparison ends symbols at the next static or external label and judges this
table's payload/relocations over its registered extent; only that section's
alignment bits are normalized. All eight table bytes and both Low/High
relocations are exact. No payload or binding difference is waived.

The supported LinkGuard prepares this pair successfully but still refuses it
solely for the same unresolved Shell method. Do not apply this composition.
The seed remains unchanged: its seven matched rows and fourteen unclaimed
definitions, existing markers, data ownership and donor flags require their
own reconciliation. Other original-plan blockers include CpuType/GlobalData
ABI declarations, OptionPreferences::setSetting, GameLODManager's member
surface and further private-string views. Four mixed files remain untouched.
No full ordinary trial was repeated against the unchanged seed blocker.

Local evidence also includes `build/codex-session9-gamelod-before-trial.txt`,
the current plan, combined identity/data scans, scoped composition-trial
JSON/text/script, final provider proof, composition proof and guard report,
strict preparation receipts, planner checks, frozen checks, source backup and
before-object. The complete path consumer search is
`build/codex-session9-gamelod-path-consumers.txt`: 309 hits, comprising existing
canonical-header consumers/register entries and historical source comments;
none requires a repoint. No source was renamed, moved or deleted. Shared
link-index/receipt freshness remains the existing LINK-017/LINK-008 prerequisite
for the outgoing audit and must be judged by the next normal census; no
maintainer-only runner was started.
