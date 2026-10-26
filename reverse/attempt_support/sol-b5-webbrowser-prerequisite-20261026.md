# DX8 web-browser overload and wrapper-view prerequisite

2026-10-26, codexb5 / Sol medium, Family B shard 1/2. Target:
`Code/Libraries/Source/WWVegas/WW3D2/dx8webbrowser.cpp`.
The runner's `--check-tu` authorized this target. No merge or split was applied.

## Concrete dependency and repair

The normal upstream merge trial accepted CreateBrowser and Is_Browser_Open
(nine rows), but rejected Rva001776a0Cluster.cpp (one row / 109 bytes): the
first class view exposed only the two-argument Rva00958D30::invoke overload.
Declaring its already-rowed one-argument sibling at retail RVA 0x001770C0
exposed a second conflict: the composed smart-pointer view points to
Rva00958E30, whose invoke takes _bstr_t rather than BfmeBstrVGP.

Add the existing overload declaration to CreateBrowser's view and explicitly
cast the helper's checked pointer to its existing Rva00958D30 view. This keeps
the original wrapper call and null-check ABI. No new name, layout, alias,
pin, data symbol, compiler flag, or hatch is introduced.

## Verification and demonstrated downstream result

- `./build.sh` on all three donors before the repair: 10/10 exact, one import.
  After the edits, CreateBrowser is 6/6 exact and the helper is 1/1 exact;
  unchanged Is_Browser_Open remains 3/3 exact.
- `tools/find_declared_unmatched.py`, `tools/class_gate.py`,
  `tools/ms_header_audit.py check` pass for both edited sources.
- `tools/eh_verify.py` on the three donors: three EXACT parents, zero missing
  or nonexact. `tools/data_check.py --converged` checks ten addresses with zero
  second definitions or unjudged references.
- Regenerated the scoped WW3D2 naming planner. Normal
  `python3 tools/tu_skeleton.py --merge Code/Libraries/Source/WWVegas/WW3D2/dx8webbrowser.cpp --dry-run`
  now accepts **three donors / ten rows**, no rejected clean donor. This is a
  demonstrated one-donor / one-row prerequisite unblock, not a Luna landing.
- Supported scoped object APIs (`allowed_symbols.scan`, `_object_defs`,
  `link_census._comdat_selections`, `data_check.object_facts`) compare fresh
  standalone objects before/after: ten rows and all 23 code references are
  unchanged, as are definitions, digests, undefined names, COMDAT rules,
  data definitions and data bindings. Funclet compiler ordinals are normalized
  using the build's located-funclet mapping, without changing retail ownership.
- The normal composition verifier's final object preserves every row and all
  23 references (14 owner, four fold, three EH, two alias), all 13 surviving
  external code definitions and COMDAT rules, and the data binding/definition
  sets. There are no new undefined names.
- Composition removes two unrowed inline definitions:
  `??BBfmeObjECFPtr@@QBEPAVRva00958D30@@XZ` (three bytes) and
  `??CBfmeObjECFPtr@@QBEPAVRva00958D30@@XZ` (22 bytes). Their selected providers
  disappear; this was investigated rather than ignored. The supported
  `name_dependents._row_objects` / `dependents` scan over current ledger inputs,
  using current-source object guards and conservative source fallback, returns
  **only the defining Rva001776a0Cluster.cpp donor**. Its symbols are definitions
  in sections 5/7, not external requirements. The composed donor references
  neither old helper, and every rowed relocation retains its provider target.
  No external consumer requires these discarded duplicate pointer-view helpers.

Machine-readable scoped facts are in the adjacent JSON. Scratch probe scripts
and compiler transcripts are under `build/sol-b5-web-*`; they call the existing
normal trial verifier and do not modify any gate or shared match-cache compiler.

## Debt, ownership, audit and remaining work

The planner's original-path evidence routes all accepted rows to this TU; its
alternatives and mixed donors remain visible. The current plan has 21 approved
rows; four mixed donors remain untouched. Common/BfmeConv804.cpp and
Common/R1GuardedReleaseHelpers.cpp belong to Family A. WebBrowserComWrappers.cpp
and DX8WebBrowserInitialize.cpp need the supported split lane and their own
composition checks. No manual split, row move, or regenerated TU map is staged.

All three existing data-baseline keys and MS-header queue findings remain at
current owners. Their provisional globals still require a separate canonical
data/header repair; no debt key is retired or silently lost. No code-identity
register change is claimed. Leave the now-compatible clean donors for Luna;
a future merge must carry protected keys and rerun checks against current input.

Prepublication path-consumer audit covers origin/master through the pending
batch and this staged repair: existing sources are edited in place; the only
new paths are attempt evidence. There are **no source moves, deletes, ledger
repoints, include-path changes, build-input changes, or registry changes** in
this outgoing batch, so no old-to-new path consumer needs updating. Historical
EA paths remain intact. The push hook still owns the outgoing link-batch audit;
an inconclusive audit is not a census clearance.

Actual file reduction: zero. Debt retired: zero. Recovered C++ bytes: zero.
No linked-byte gain, image-ownership receipt, new census, or global link closure
is claimed. This prerequisite makes one additional existing donor composable.
