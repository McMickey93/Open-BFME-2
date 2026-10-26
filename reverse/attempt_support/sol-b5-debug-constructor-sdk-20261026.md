# Debug console constructor SDK prerequisite, 2026-10-26

codexb5, family B shard 1/2. The refreshed runner allocation explicitly includes
Code/Libraries/Source/debug/debug_io_con.cpp. Reviewed its current debug planner
packet, original-path alternatives, private-class/include/flag prerequisites,
current normal --plan and the 2026-10-25 debug prerequisite handoff.

## Verified cleanup

Replace DebugIOConConstructor.cpp's 28 local Microsoft declarations with
<windows.h> and <string.h>, using the supported // platformsdk opt-in.
The initial headers-only attempt used the default toolchain windows wrapper,
which forwards to the sweep shim and lacks five called APIs. The SDK opt-in
selects the real SDK for this standalone source; no codegen option or function
body changes. Neither seed nor shared shim/header is edited.

Before: ./build.sh on seed, constructor, destructor and factory verifies
13/13 rows, nine string literals, one empty string and 31 named imports.
After: constructor remains 3/3 exact, six literals, one empty string and
19 imports. Its EH graph is EXACT. All four sources' supported
allowed_symbols, link_census COMDAT and data_check facts compare equal before
and after: 13 rows, 14 bindings (three EH, five owner, two pre-existing wrong,
one fold, three alias), external definitions/digests, undefined names, selection
flags and data facts. Thus actual compiled providers/consumers did not change;
only local EH label spellings are normalized. find_declared_unmatched, class
gate and Microsoft-header check pass; converged data check has zero findings.

The owning ms_header_audit scan_files/refresh_queue API removes exactly this
source's 28-definition queue row (15 same, seven source and six mangle
findings). No unrelated queue record changes. This is one header-queue entry
retired, not code-identity retirement. The constructor's wrong DebugIOConBase
destructor binding in code_identity_baseline.tsv remains untouched and owned.
No source paths or rows move, no hatches grow and no retail bytes are recovered.

## Composition remains blocked; no merge applied

The complete normal baseline accepts seed/destructor/factory: three sources,
ten rows. Constructor rejects with an internal compiler error and the
outside-family Common WriteFile caller has a conflicting SDK declaration.
After the SDK cleanup, the accepted subset is unchanged; constructor instead
reaches missing GetConsoleTitleA/FindWindowA/GetSystemMenu/DeleteMenu/DrawMenuBar
because the composed seed's explicit sweep include path wins over the donor's
SDK environment. A coherent seed/header environment is still prerequisite.
The Common donor remains for its family-A owner.

The supported binding observer additionally finds a pre-existing difference
in that accepted subset: destructor EH changes from private DebugIOConBase
to DebugIOInterface at the same retail target 0x0003F320, and composition
changes/drops associated external definitions and introduces two undefined
names. Its assertion fails, so this trial is not applied or published as a
merge. A successful function-byte dry run alone is insufficient. The observed
identity change needs its own verified repair/retirement and consumer checks;
this SDK cleanup does not claim to resolve it. The blocked constructor attempt
is recorded through re_log.py with this evidence. No newly compatible donor
or confirmed Luna landing is claimed here.

## Batch audit and handoff

Audited merge base 60a1f8bf2a through a25274d849 plus this staged change:
LaserDraw and ProjectileStreamDraw declaration prerequisites, this in-place SDK
cleanup and evidence only. No moved/absorbed paths occur in the pending batch;
active tools, hooks, workflows, includes, build inputs and registries require
no path repoint. Original EA paths and protected debt retain their owners.
The refreshed debug planner passes --check. Full source/object facts and the
negative composition receipts are adjacent JSON; commands under build/sol-b5-debug-*.
Keep constructor/RVA/evidence claims until publication. Other debug trial scopes
can release. File reduction, recovered C++ bytes and code-identity retirement
are separately zero; the header queue shrinks by one entry/28 declarations.
