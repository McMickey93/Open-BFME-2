# Melee approach logging: use the existing game provider's signature

Scope: AIAttackMeleeApproachState::onEnter, RVA 0x0034D5B7, 719 bytes,
in Code/GameEngine/Source/GameLogic/AI/AIAttackMeleeApproachStateOnEnter.cpp. Inspected BFME 2 revision:
b3ff5cb28fb20c0fe0d609b5ac3869998cdb803e.

## Target facts and source contract

The Microsoft-header picker serves this file for its private fprintf prototype.
All three retail direct calls go to RVA 0x002CEC42 (VA 0x006CEC42):

| Call RVA | Retail bytes | Target RVA |
| --- | --- | --- |
| 0x0034D640 | e8 fd 15 f8 ff | 0x002CEC42 |
| 0x0034D7DC | e8 61 14 f8 ff | 0x002CEC42 |
| 0x0034D816 | e8 27 14 f8 ff | 0x002CEC42 |

The existing 108-byte owner in Common/FprintfAppendLine.cpp formats through
_vsnprintf, constructs an AsciiString and appends it to the target's vector.
Its source defines extern C void fprintf(FprintfTarget *, const char *, ...).
This is a game object append helper, distinct from the CRT IAT at VA 0x00BBA5C4.
The symbols.csv pin's older description as static CRT fprintf contradicts this
provider's verified body. A stdio FILE interface is therefore not established.

Correct this consumer's int/void-pointer declaration to that existing provider's
void/FprintfTarget-pointer signature. Forward-declare the existing struct only;
keep the converged opaque global and cast at the call. No layout, new body,
calling convention, symbol name, pin or ledger row is introduced.

## Verification and accounting

The unmodified consumer passes 1/1. After the change the ordinary native MSVC
7.1 verifier passes 4/4 across consumer and provider, including the provider's
handler and unwind label. Three string literals and the provider's named import
verify with zero skipped references. The declared-body check and the normal
Microsoft-header check pass. Normal commit and publication hooks remain enabled.

This is a signature cleanup, +0 new C++ bytes and +0 measured census-linked bytes.
The audit still classifies the existing fprintf name as conflicting; no
Microsoft-header queue row or debt-register key is retired. Reconcile the game
provider's identity and its callers through the naming/identity tools before a
future CRT-header migration; do not repeat a stdio substitution on this caller.
The other callers and the older pin annotation are outside this file's scope.

## Mandatory BFME 1 freshness check

Fetched official BFME 1 master ce1daafa6a59b48c3ca371de266ce299f79cbd99.
The clean canonical gitlink and physical reference remain at
e74410b3738a2bb75d626085d9ebfd3406a43ff7. An attempted ordinary claim of
file:reference/open-bfme-1 was refused by the live peer claim
refs/claims/file/5635fb671f614ba9, observed token
3c37538247b9dd243cbd3bad6ffe60dbf56158ee, expiring 2026-10-27 18:42:50 UTC.
The reference is not changed while that claim is held.

A read-only old-reference full byte scan had started before the conflict was
known and was cancelled during compilation; it is not a completed gate.
In-flight generated objects and dependency sidecars were discarded. No new
reference verification or successful bfme1-last-check.txt stamp is claimed.
Per docs/matching.md, retain the canonical inputs and repeat the freshness check
when the peer releases its scope. This source-only cleanup uses retail evidence
and the existing local provider; no changed donor input is imported.

Autonomous implementation and measurements: OpenAI Codex.

## Outgoing batch audit

After rebasing onto 75b39b52832cbbec8327db99b454d656d6c1586c, reread the
updated AGENTS.md. The ordinary pre-push verifies 39/39 functions across four
sources, two data rows, 15 literals plus five empty-string references,
11 named imports and four EXACT EH graphs. The link audit initially lacked
an index. The normal project fetch_index(objects=False) then retrieved
the official 2026-10-27 14:34 index at 73061d9452 without a new census.
The recheck remains INCONCLUSIVE: that index predates the outgoing base, and
four affected objects lack current strict receipts (first Eva.cpp).
This is linking UNVERIFIED, not proof of clean linking or a regression.
The affected scope is carried in docs/linking_obstacles.md, LINK-001,
for the next normal maintainer census. Native byte gates remain successful.
