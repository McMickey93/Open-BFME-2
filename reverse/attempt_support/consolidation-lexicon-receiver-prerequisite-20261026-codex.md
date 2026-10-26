# FunctionLexicon receiver prerequisite, 2026-10-26

Allocated Sol codex family-A shard 0 target:
`Code/GameEngine/Source/Common/System/FunctionLexicon.cpp`.
Inspected revision `f8522bc21a`; prior access prerequisite is recorded in
`consolidation-lexicon-access-20261025-codex.md`. File claims cover the seed,
constructor and new shared header. Current scoped planner:
`python3 tools/name_lane.py consolidate --under Code/GameEngine/Source/Common/System/ --out build/consolidation/lexicon-session6`;
its `--check` passes. Current in-memory routing approves the constructor here.

The ordinary merge trial rejected `Rva002D22CACtor.cpp`: its private receiver
omitted `rva002D22D5` and used an unnamed 48-byte tail, while the seed's validator
used twelve pointers after a different private base view. The two files now
include one receiver declaration using the constructor's existing
SubsystemInterface base, twelve pointers at +0x0C, and both existing methods.
The constructor still clears exactly 48 bytes. Its existing fourteen-slot
vtable, including all relocation targets, remains identical. The structural
receiver name is retained; this does not establish that it is FunctionLexicon.
No donor name, new class identity, flag, pin or global is inferred.

Verified prerequisite and demonstrated downstream acceptance:

- Before and after `./build.sh` on the seed and constructor: 7/7 exact rows,
  401 retail bytes. Literal, float and import verification passes.
- `find_declared_unmatched.py` on both: all definitions matched.
  `class_gate.py` on both and the header passes.
- Ordinary `tu_skeleton.py --merge ...FunctionLexicon.cpp --dry-run` changes
  from no accepted sources and the missing-member rejection to both sources
  accepted, seven rows, no rejected donor. The 30-row mixed destructor donor
  remains intact. Leave the now-compatible constructor for Luna.
- `link_check.py --prepare-current --paths-from
  build/codex-session6-lexicon-sources.txt`: both providers byte-verified with
  strict reusable receipts. This is not a link census or closure claim.
- Scoped allowed-symbol reference facts: 9 before, 9 after, no additions or
  removals. Scoped data reference/definition facts are identical.
  `data_check.py --converged` on both: 10 addresses, zero second names or
  unjudged rows. `eh_verify.py`: no EH rows, missing objects or failures.
- Preserved standalone objects versus current objects: all 17 external code
  definitions and their normalized relocations, data, undefined targets and
  COMDAT selections are unchanged. Constructor non-debug sections are all
  identical. The seed changes only `.drectve`: including the existing base
  header exposes seven existing AsciiString alternate-name directives. None
  is referenced by the seed, every mapping already existed in the constructor,
  and the complete batch's alias union is identical. No alias was added to
  source or changed in a shared shim.
- Composed trial `build/tu_skeleton/873403b8b812bc20.obj` versus the standalone
  union: all 17 external code definitions identical; no definition conflicts,
  new/missing/changed providers, or added/removed unresolved targets after
  internal resolution. COMDAT policies, alias union, the one external data
  definition (vtable bytes and all relocation targets), and scoped data facts
  agree. Local receipts/scripts are under `build/codex-session6-lexicon-*`.

Publication audit: no prior local outgoing commits and no source moves in this
change. The new header has exactly these two include consumers; active tools,
hooks, workflows and protected header/data/identity queues have no path consumer
requiring repointing. Original EA/donor path evidence is preserved. No ledger,
debt register, queue or hatch baseline changes. File reduction: 0; identity debt
retired: 0; recovered C++ bytes: 0. This is a verified consolidation prerequisite,
not a confirmed Luna landing or census improvement. Retain all four file claims
until publication is confirmed, then release them; no RVA claims acquired.

Other allocated trial this session: AssaultTransportAIUpdate's ordinary dry-run
still accepts no donors. The constructor/dispatch/helper declarations disagree
with its legacy receiver (`m_p3E4`, `m_object08`, `rva00048F411`,
`Rva0048F690Helper` and other existing helpers are missing); several GameLogic
and Xfer views also collide. No source edited or claim retained for that
unchanged blocker. Local diagnostic:
`build/codex-session6-assault-dryrun.txt`. It needs a coherent receiver/layout
prerequisite rather than another identical merge attempt.
