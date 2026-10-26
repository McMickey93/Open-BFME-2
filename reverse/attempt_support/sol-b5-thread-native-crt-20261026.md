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

## Final allocated probes and session handoff

Prerequisite commit: `569d4d26f9` (pending runner publication at handoff).
Inherited evidence commits rebased to `d2963c2d59` and `4b29cac09e`; the runner
held the three-commit batch. Preserve these verified commits. No further
source trials or failed reconstructions remain in Code/.

Additional read-only allocated plans and normal merge dry-runs:

| Target | Current result | Remaining prerequisite |
| --- | --- | --- |
| GameNetwork/udp.cpp | 14 approved rows, accepted none, exit 2 | Three private UDP alias members and fields absent from shared header; no independent naming decision made |
| GameNetwork/NAT.cpp | 73 approved rows, accepted none, exit 2 | PortNegotiationSchema::attachSlotList/NAT::setConnectionState and incompatible private fields; native cstring strtok_unimported in negotiation donor; six mixed files and Common owners retained |
| WW3D2/linegrp.cpp | 26 approved rows, accepted none, exit 2 | Render and SetArrays flag overrides differ from carried -G7; destructor byte rejection; no new pragma/flag override |

All three boundaries were recorded with `tools/re_log.py` at 0x00594976,
0x005A678E and 0x001B3510. They held no trial file/RVA claims. Logs are under
`build/sol-b5-{udp,nat,linegrp}-{plan,trial}.log`. One WW3D2 planner run raced a
NAT temporary trial file disappearing; it is a transient inventory failure,
not evidence of no work. The final WW3D2 planner/currency check was rerun only
after both trials finished. No gate/build was duplicated or bypassed.

Immediately before this final handoff commit, outgoing `origin/master..HEAD`
plus staged changes contain two source modifications in place, the inherited
evidence file, this new evidence file and attempt-log appends. No source path
changes or newly affected path consumer exist; the previous compatibility
audit still applies. No protected register, TU map or header queue changed.

`python3 tools/progress.py origin/master`: BYTE-MATCHED 7,978,500 (100.00%),
LINKING 7,322,361 (97.47%), LINKED 7,567,229 (98.14%); all deltas zero. Linking
figures are the existing 2026-10-26 13:18 census at d1f046749a, retail-truth-4.
The verified result is the eleven-row thread composition unblock, not new C++
bytes or a measured link gain. BFME 1 reference freshness remains the inherited
verification boundary recorded in the recovery handoff; no success receipt
was fabricated and no maintainer-only runner was used.

Until publication is confirmed retain this seat's four file claims:
`Code/Libraries/Source/WWVegas/WWLib/thread.cpp`, `ThreadClassLifecycle.cpp` in
that directory, `reverse/attempt_support/sol-b5-thread-native-crt-20261026.md`,
and `reverse/attempt_support/sol-b5-prerequisite-session-20261026.md`.
After the runner lands the batch, release those file claims and run
`python3 tools/claims.py release --landed`. Complete claim snapshot:
`build/sol-b5-thread-final-claims.txt`. Other allocated work remains; this is
a completed prerequisite pass, not an assertion that every lane is empty.

## Inherited batch recovery, next session

Clean-tree recovery retained four unpublished commits (`065c8e1fb1`,
`14da88962f`, `afc925697f`, `ea8cc531b2` after runner rebase). Re-read current
AGENTS.md and consolidation instructions; pull/rebase and check_csv pass.
Reverification of both thread sources passes 11/11 rows, two data rows,
two literals and eleven imports; declared-unmatched passes. No source edits
were needed. The full pending path audit contains only the same two in-place
source edits, evidence and attempt-log entries: no moved/deleted source or
affected active path consumer. Protected registers retain their owners.

Official BFME 1 fetch compares verified checkout `de077dd5` against
`fc68fb74` (76 commits ahead). The inherited full-input update verification
remains incomplete; preserve verified inputs, do not write a success receipt.
No reference update or maintainer-only measurement was attempted. Retain the
four file claims above until publication of this recovered batch is confirmed.
