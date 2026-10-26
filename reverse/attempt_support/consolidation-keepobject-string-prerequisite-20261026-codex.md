# KeepObjectDie string prerequisite, 2026-10-26

Sol codex family A shard 0/2; runner `--check-tu
Code/GameEngine/Source/GameLogic/Object/Die/KeepObjectDie.cpp` exits 0.
Source and header-queue file claims acquired before editing. Frozen checks
pass before and after. Scoped Die planner reviewed and regenerated after
the edit at `build/consolidation/keepobject-session6`; its check passes.
Its stale-map and same-name ZH hints are not merge approval. The current
in-memory TU plan approves this constructor at the allocated destination.

The ordinary merge trial lists AsciiString adoption as a prerequisite.
`KeepObjectDieCtor.cpp` declared a private AsciiString derived from a private
StringBase. The canonical AsciiString is a four-byte wrapper, so implicit
template deduction at the debug stream call previously failed (the queue's
C2784). Replaced those private declarations with the registered header and
passed the existing string representation explicitly as a const
StringBase<char> view, as the canonical wrapper itself does. The debug
operator specialization, receiver address and string ownership stay the same.
No shared header, compiler flags, global, pin or class identity changes.

Acceptance and binding evidence:

- Before/after `./build.sh .../KeepObjectDieCtor.cpp`: 5/5 exact, 236 retail
  bytes including constructor, destructor, deleting destructor and EH rows;
  one string literal verified. The build independently places the renamed
  `$L1326` at retail funclet 0x0078C134 (ledger spelling `$L499`).
- `header_adopt_lane.py accept --class AsciiString .../KeepObjectDieCtor.cpp`
  passes and retires exactly one row through the supported queue path.
  No other debt retired; existing receiver identity findings remain.
- `find_declared_unmatched.py`, `class_gate.py` and `check_csv.py` pass.
  `eh_verify.py`: one EXACT graph, zero missing objects/failures.
  `data_check.py --converged`: ten addresses, zero second names/unjudged rows.
- `link_check.py --prepare-current --paths-from
  build/codex-session6-keepobject-sources.txt`: explicit provider byte-verified
  with strict reusable receipt, no census/index/status change or closure claim.
- COFF comparison of preserved before/current supported build objects: all
  four external code definitions, normalized code relocations, undefined
  targets, external data, COMDAT policies and every non-debug section except
  `.drectve` agree exactly. The header exposes its seven existing AsciiString
  alias mappings; none is referenced here. Those exact mappings already exist
  in the pending FunctionLexicon batch's constructor, so the complete outgoing
  batch introduces no alias-union or selected-provider change.
- All eleven code-reference facts agree after resolving the single renamed
  funclet using the exact section placement and independently EXACT EH graph.
  An unadjusted diagnostic reports 11 -> 10 solely because its row lookup
  uses the stale label. No ledger or checker was changed to suppress it.
  Scoped data reference/definition facts agree exactly.

Ordinary after `tu_skeleton.py --merge .../KeepObjectDie.cpp --dry-run` no
longer lists `adopt_first`. It still accepts no composition: the constructor's
private receiver lacks getModuleNameKey from the seed. Reconciling the primary
and secondary module vtables and receiver members is a separate prerequisite;
adding a virtual without proving those bindings would be unsound. No merge
applied, no confirmed downstream Luna landing. Local receipts and scratch
comparison scripts: `build/codex-session6-keepobject-*`.

Complete pending batch publication audit: FunctionLexicon declaration commit
022d9b9a58 plus this staged change has no game-source move/deletion/rename.
The existing canonical header is included through a source-relative path;
no new include-path setting or active tooling consumer needs repointing.
Tools/hooks/workflows, include/build inputs and protected path registers were
reviewed; historical EA paths remain. Header queue loses only the accepted
row; no gate/data/identity baseline changes. Source-file reduction 0, identity
debt retired 0, header debt retired 1, recovered C++ bytes 0. Retain the
constructor, header-queue and handoff file claims until confirmed publication.
