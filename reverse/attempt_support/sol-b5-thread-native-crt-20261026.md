# WWLib thread prerequisite: native CRT and virtual destructor, 2026-10-26

Allocated destination: `Code/Libraries/Source/WWVegas/WWLib/thread.cpp`.
This repairs the concrete Luna blocker recorded in
`consolidation-wwlib-thread-20261026.md`; it does not apply a merge.
Both source files were claimed before editing.

## Boundary and repair

The initial `tu_skeleton.py --merge Code/Libraries/Source/WWVegas/WWLib/thread.cpp
--dry-run` accepted no donor: `_beginthreadex` was undeclared (C3861).
The seed's include search selects the sweep `process.h`. Both files now select
MSVC's native CRT declarations through STLport's existing native-header macro.
Selecting it only in the seed exposed incompatible `_beginthread` declarations
when the lifecycle donor subsequently included sweep `process.h`.

Compilation then exposed the seed's `__declspec(novtable)` class declaration:
the composed destructor at 0x00610480 emitted `c3`, versus retail
`c701acb6c700c3`, and the scalar-deleting destructor was absent. Removing that
qualifier permits the normal destructor vptr store. The explicit constructor
table store preserves the standalone constructor. No body, symbol name,
layout, compiler optimization, pin, ledger, hatch or debt key changes.

## Verification and demonstrated downstream result

- `./build.sh Code/Libraries/Source/WWVegas/WWLib/thread.cpp
  Code/Libraries/Source/WWVegas/WWLib/ThreadClassLifecycle.cpp`: 11/11 matched;
  two data rows, two strings and eleven named imports verified.
- `find_declared_unmatched.py` both files: PASS before and after. The seed's
  pre-existing `Sleep_Ms` marker is retained. `class_gate.py` and
  `ms_header_audit.py check` both files: PASS.
- Planner scoped to `Code/Libraries/Source/WWVegas/WWLib/` and snapshot currency
  check: PASS. The current in-memory plan has ten approved rows; the standalone
  baseline and composed verification include eleven rows (the deleting dtor).
- Final normal merge dry-run accepts seed plus `ThreadClassLifecycle.cpp`,
  eleven rows, no rejected donor. This is a demonstrated prerequisite unblock,
  not a confirmed Luna landing.
- Supported `allowed_symbols` object facts and scans compared before/after:
  all eleven row owners, four code-owner references, fourteen external code
  definitions (eight seed, six lifecycle), undefined sets, COMDAT selections
  and section flags, and data definitions/references are identical.
- Capturing the dry-run object through `tu_skeleton.Verifier.matched` and
  comparing with those standalone facts: all fourteen code definitions retain
  their selected scoped provider's normalized bytes and COMDAT flags; no new
  undefined symbol or dropped definition; no divergent scoped provider copies;
  all four code-owner bindings unchanged. `data_check.object_facts` union is
  unchanged: fifteen data bindings and three definitions. No changed binding
  needs an external consumer repair. This uses current objects, not an old
  census. No shared build-cache compiler entrypoint was called.

Local reproducible receipts/scripts: `build/sol-b5-thread-{before,after}/proof.json`,
`build/sol-b5-thread-proof.py`, `build/sol-b5-thread-composition.py`,
`build/sol-b5-thread-composed-bindings.py`, `build/sol-b5-thread-data-selection.py`,
and their JSON/log outputs. These scratch receipts remain local; the normal
build and merge dry-run above reproduce acceptance.

## Registers, publication audit and remaining work

No paths move. After rebasing the inherited evidence commits onto c01848c0b1,
`git diff --name-status --find-renames origin/master..HEAD` contains only the
inherited evidence file; this staged prerequisite changes two sources in place
and adds this handoff. There are no absorbed paths, renamed includes, tool/hook/
workflow consumers, build inputs or source registries to repoint. Upstream did
not change either source against the saved pre-trial copies. CSV checks pass.

No code-identity key exists for these sources. Existing seed data-name debt
`_g_poolYieldEvent` at 0x00A07C00 and Microsoft-header findings (three lifecycle
Win32 prototypes and the seed's conflicting environment) remain accounted for.
Header queues and all protected registers are unchanged. Native vs address-named
vtable identity remains existing debt, not a new naming decision.

Luna can now attempt the approved merge with normal claims and complete batch
checks. Source count reduction: zero; identity/data debt retired: zero; recovered
C++ bytes: zero. No census, ownership or whole-image link improvement is claimed.
The stale global link-index boundary in LINK-017 remains for future compositions.

Other allocated probes in this pass: Shadow/W3DBufferManager retains its existing
three-row ReleaseResources acceptance, but Slots bytes and ReAcquireResources'
BfmeDynamicNativeVB/DX8VertexBufferClass boundary still block the other donors.
W3DDisplayStringManager still accepts none: Common/Rva00090360Ctor.cpp and
Common/W3DDisplayStringManager.cpp require missing m_14/rva00090381 declarations.
Those donors are outside family B; their existing handoff is retained and they
were not edited or claimed.
