# ProductionUpdate queue: use the real Windows SDK constants

Selected with tools/ms_header_audit.py next --class drop-in-candidate.
Inspected BFME 2 base: 658c11de7b6efab1745186c66e4b0f0221e1c524.
Scope: Code/GameEngine/Source/GameLogic/Object/Update/ProductionUpdateQueue.cpp.
The complete 2,197-line original source was read before changing its includes.

## Change and contract

The audit identified exactly three local Microsoft macro copies: TRUE 1,
FALSE 0 and NULL 0. Vc7/PlatformSDK/Include/WinDef.h supplies these same
integer-valued definitions in C++. Keep every existing usage unchanged.
Add the normal platformsdk build marker and include <windows.h>; remove
only those three private definitions. NOMINMAX is a configuration input to
the SDK, needed to preserve the source's existing local STLport max overload.
No function body, declaration, layout, compiler flag, pin or ledger row changes.
In particular, the existing /MD, /GX, /O1 and /D_CRTIMP= settings are retained.

## Whole-file verification and bounded queue refresh

The ordinary native MSVC 7.1 build passes 47/47 rows before and 47/47 after.
It verifies four literals plus four empty-string references, five float
literals, no named imports, and zero skipped references. All 21 generated
funclet labels resolve through their parent EH graphs after normal compiler
label renumbering. No pins or verifier exceptions were added.

The normal object dependency sidecar records the actual retained BFME 1
inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/
Vc7/PlatformSDK/Include/windows.h and windef.h, rather than local substitutes.
COFF inspection finds 147 executable sections before and after and identical
external definition and undefined-symbol sets, with no new external bindings.
The after-change Microsoft audit is clean; only exempt configuration macro
NOMINMAX remains. The declared-body check also passes.

The supported ms_header_audit.refresh_queue API rescans only this source.
It removes its one queue entry (three same-valued macro copies); every
unrelated queue record is preserved byte-for-byte. Its occurrences cache is
written to ignored build scratch. No other identity or Microsoft debt is retired.

This is header cleanup: +0 new C++ bytes and +0 measured census-linked bytes.
Normal commit and publication hooks remain enabled.

## Mandatory BFME 1 freshness check

Fetched official BFME 1 master 8ab948fcc04d4dfb71944e0ec4d766ecc553b715.
The canonical gitlink and clean physical reference are still at
e74410b3738a2bb75d626085d9ebfd3406a43ff7. An ordinary attempt to claim
file:reference/open-bfme-1 was refused by live peer claim
refs/claims/file/5635fb671f614ba9, token
3c37538247b9dd243cbd3bad6ffe60dbf56158ee, lease
eb25466fc2954078af671a32d30e121f, expiring 2026-10-27 18:42:50 UTC.
A fresh logical-footprint check confirmed that blocker. Do not edit the
reference under another worker's reservation. Per docs/matching.md, keep
the canonical verified inputs and repeat the reference check after release.
No new reference full scan or successful bfme1-last-check.txt stamp is claimed.
The original compiler and SDK used above are from that retained reference.

Autonomous implementation and measurements: OpenAI Codex.

## Outgoing batch audit

The ordinary native pre-push after rebasing onto
30de31a686c79263d9806b5f10cb9cd1c2740c99 passes 85/85 functions across
four sources, two data rows, 16 literals plus nine empty-string references,
ten float literals, 11 named imports and seven EXACT EH graphs.
The normal include-dependency gate selects this four-source scope; no gate
scope is shortened. AGENTS.md remains at blob
922001686b9b38567dd6ef67d16d46cb68320a1b.

The normal link batch audit is INCONCLUSIVE: index 73061d9452 predates that
outgoing base, and four affected objects lack current strict receipts
(first Code/GameEngine/Source/GameClient/Eva.cpp). Linking is UNVERIFIED,
not a clearance or measured regression. Carry the scope in LINK-001 of
docs/linking_obstacles.md to the next normal maintainer census.
No new census or maintainer-only measurement was started.

The commit's shadow identity scan reports six findings in the queue source
(AsciiString, list/ObjectID, DrawableList and getBehaviorModules bindings),
and the shadow data scan reports one wrong-name static at VA 0x00A03B58.
These surrounding identity/data obligations remain open; this header change
does not repair or baseline them. The enforced byte, EH and converged-data
gates above pass, and the object external bindings are unchanged.
