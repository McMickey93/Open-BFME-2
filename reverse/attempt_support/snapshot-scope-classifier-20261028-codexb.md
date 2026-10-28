# Nested allocator Snapshot is not the game Snapshot

Inspected base: `8fb6f4493c`, 2026-10-28. This is a verifier repair for the
existing false-reject entries at 0x00034D10, 0x000353F0 and 0x000304B0,
not a source reconstruction or a canonical-header adoption.

The three sources `Rva00034D10Snapshot.cpp`, `Rva000353F0Trace.cpp` and
`memory_pool.cpp` under `Code/GameEngine/Source/Common/System/` declare a
nested `EA::Allocator::GeneralAllocator::Snapshot` heap-report record.
The old `class_layouts.class_bodies` includes its bare name `Snapshot`;
`header_adopt_lane.body_span` can then select and replace that nested body.
The class-view survey used a different indentation rule, so the two readers
also disagreed about indented global definitions.

The readers and replacement now share source spans determined by brace
scope. Comments and literals cannot alter that scope. Class members,
template members and local classes are excluded; indented namespace-scope
definitions, explicitly qualified names and linkage blocks remain supported.
Template bodies are available explicitly to the existing dependency-view
replacement operation. This does not attempt to resolve namespace aliases,
preprocessor conditions or infer the identities of nested classes.

Verification:

- Focused class-layout, header-adoption, class-gate, qualified-contract and
  gate-exploit suites: 193 passed, one existing open-escape fixture skipped.
  Regression cases reproduce the three actual allocator sources; exercise
  nested heads with and without indentation, literal braces, local and
  template types, qualified names and C/C++ linkage blocks; prove that
  replacement preserves the nested record and that real private views are
  still refused. Missing canonical includes still fail acceptance.
- `./build.sh` on the three unchanged allocator sources: 56/56 matched rows,
  one data row, 14 literals, two empty-string references and 45 imports pass.
- `python3 tools/check_csv.py`, the declared-unmatched check on the five
  edited Python files, and `git diff --check` pass.

The existing three erroneous header-queue entries remain. They cannot
honestly pass the canonical-include requirement, and this repair does not
create an exemption or manually retire them. A separately reviewed owning-tool
path for retiring a proven misclassified queue entry remains necessary.
No game source, canonical header, ledger, pin, debt register or census changes.
