# Particle-editor loader ownership and ScriptEngine data retirement

Control: `665f50f7cf`, ordinary provider index `5ce093a71a` from the
2026-10-26 19:02 census. The picker claimed ScriptEngine_dtor.cpp; the init
and cleanup-thunk sources were then claimed before editing. Their frozen-file
checks pass before and after the change.

## Existing ownership and target evidence

ScriptEngine_init.cpp already defines `TheFXParticleEditor`, a twelve-byte
loader with a vptr and two pointer fields at offsets four and eight. The init
and dtor bodies use that object, as does the existing initializer at RVA
`0x007AD7DD`. That initializer constructs the object at VA `0x00DFE180` and
registers the cleanup at RVA `0x007B75E2`.

The cleanup source instead defined a separate four-byte `g_00DFE180` and
cast its address to its existing loader view. Its data row claimed only that
placeholder, leaving the real loader owner outside the data register. The
cleanup now references the existing `TheFXParticleEditor` symbol, and the
data row records that owner's twelve-byte allocation at RVA `0x009FE180`.
The ordinary byte/reference gate verifies the cleanup's unchanged native
address and destructor target, and verifies all twelve initial storage bytes
against retail. Adjacent storage is not claimed.

The size and field interpretation come from the existing matched source
views, with allocation and initial bytes checked by the data verifier. The
identifier is reused from the existing reconstruction; this change does not
establish a recovered retail class or variable name. No donor-source identity
is inferred, and no constructor, pin, alias or second storage owner is added.

## Verification

Normal `./build.sh` verification of the cleanup, init and dtor sources passes
**950/950 function rows and 22 data rows**, with four string references and
five named imports exact. Both EH graphs are EXACT. Existing renumbered
funclets resolve through their verified parents; no ledger label is changed.
`check_csv.py` and `data_rows.py --check` pass with 2,224 data rows.

The paired four-current-source ordinary previews also include
Rva007AB81ACtorInits_Rva007ACC20.cpp. Before and after are identical:

| Source | Ordinary preview |
| --- | --- |
| Rva007B6880Thunks.cpp | 9,050 -> 0; unresolved `g_lgaKeyRecords` |
| ScriptEngine_init.cpp | 416 -> 416 |
| ScriptEngine_dtor.cpp | 900 -> 900 |
| Rva007AB81ACtorInits_Rva007ACC20.cpp | 132 -> 132 |

Both commands return one for that same missing storage provider. This bounded
control preserves the three clean units; it does not include the current
LargeGroupAudio owner among its overrides and does not contradict the separate
six-source preview documented in LINK-007. No strict closure, census gain or
image-ownership result is claimed. Scratch logs are in
`build/particle-editor-owner-20261026/{before-build,after-build,before-link,after-link,eh}.log`.

## Debt retirement and remaining scope

Commit `ec3ba89fca` already replaced the init/dtor copies of `st_DebugDLL`
with references to its existing owner. Its data retirement was blocked by
the particle-editor conflict. After this repair, `data_check.py` reports
zero findings for both ScriptEngine sources. The owning
`repair_queue.py retire data` commands remove their four stale registered
keys: duplicate-def and wrong-name for `_st_DebugDLL` in each source.

Retirement for the cleanup-thunk source is still refused because of unrelated
wrong-name findings at RVAs `0x009FE358`, `0x00A02310`, `0x00A04424` and
`0x00A06665`. Its stale particle-editor key is retained until that source's
other findings are resolved. No key is removed by hand, and this is not a
whole-source or whole-family convergence claim.
