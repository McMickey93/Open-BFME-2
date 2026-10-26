# DataChunk counted-reader API prerequisite, 2026-10-26

Allocated Sol codex family A shard 0/2 destination DataChunk.cpp; --check-tu
exit 0. Normal seed file claim acquired, frozen checks pass before/after.
Current in-memory routing approves the two counted-string reader donors.
Scoped Common/System planner reviewed and regenerated after this edit at
`build/consolidation/datachunk-api-session6`; its check passes. No planner
hint, historical mapping or stale TU map was treated as merge approval.

The previous ordinary merge trial rejected both counted-string readers because
the seed's DataChunkInput view omitted readAsciiString/readUnicodeString.
Added those two existing nonvirtual APIs and a UnicodeString forward declaration.
No member layout, vtable, body, compiler flags or initializer changes.

Verified prerequisite:

- Before/after `./build.sh .../DataChunk.cpp`: 23/23 ledger rows exact;
  one empty literal and three imports verified. Frozen/class gates pass.
  `eh_verify.py`: one EXACT graph, no missing/failing objects.
- Preserved standalone COFF: all 48 external code definitions, normalized
  relocations, undefined references, aliases, COMDAT policies, external data
  and all 55 non-debug sections identical. All twenty scoped code-reference
  facts and all data definition/reference facts agree. Source-only change
  cannot alter the standalone provider/consumer bindings.
- `link_check.py --prepare-current --paths-from
  build/codex-session6-datachunk-api-sources.txt`: one explicit provider's
  strict receipt accepted; no census/index/status or closure claim.
- Ordinary `tu_skeleton.py --merge .../DataChunk.cpp --dry-run` now accepts
  seed + DataChunkInputReadAsciiString.cpp + DataChunkInputReadUnicodeString.cpp.
  Before accepted no composition. The two donors contribute six existing
  ledger rows / 381 retail bytes (188 ASCII, 193 Unicode). The printed plan
  has 27 address rows; standalone ledger includes two existing seed aliases.
  These are demonstrated newly compatible rows, not recovered bytes or a
  confirmed Luna landing.
- Compared the verified trial object build/tu_skeleton/fa371326b5780370.obj
  to the complete three-source union: all 57 external code definitions,
  three external data definitions with bytes/relocations, COMDAT policies,
  alias union, data facts and undefined references after internal resolution
  agree; no missing/new/changed definitions or conflicting copies. Scratch
  receipt: build/codex-session6-datachunk-api-composition-composition-proof.json.

No merge applied; leave the compatible donors for Luna. Remaining independent
DataChunk donors still reject: Mapping next/id/name and destructor identity,
legacy/canonical AsciiString include collision, receiver/class ordering in
DataChunkInput.cpp, output fwrite/member/API differences, missing readInt,
readNameKey/readDict declarations and output writer prerequisites. Mixed and
protected rows stay untouched. Do not retry the documented Mapping identity
refusal by a manual rename or field alias.

Publication audit covers all pending commits 022d9b9a58..4a181c519b plus this
staged change. There are no outgoing game-source moves/deletions/renames;
active tools/hooks/workflows, includes/build inputs and path registries need no
repointing. Historical EA paths preserved. The existing new-header consumers
remain exactly FunctionLexicon and its constructor; both verified together.
Incoming origin changes are separated using the outgoing commit list and
merge-base diff. Protected gate/data/identity/header/hatch registers unchanged
by this prerequisite. Whole-batch checks retain the two previously accepted
header retirements and the separate one-finding DataChunk identity fix.
Source files removed 0, identity debt retired 0, recovered C++ bytes 0.
Keep seed and handoff claims until confirmed publication; normal future merge
must renew routing/planner/current-object evidence and acquire all donors.
