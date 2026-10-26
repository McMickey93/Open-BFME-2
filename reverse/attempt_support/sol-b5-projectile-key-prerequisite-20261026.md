# ProjectileStreamDraw key declaration prerequisite, 2026-10-26

Seat codexb5, family B shard 1/2. Allocated destination:
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DProjectileStreamDraw.cpp`.
The current Draw planner was reviewed for original-path evidence, alternatives
and prerequisites. The normal merge verifier rebuilt stale routing in memory;
no TU map was committed.

The full normal baseline approves 32 rows in six whole sources and four mixed
donors, but accepts no multi-source subset. Its pool-key donor fails because
the seed omits the already-rowed getModuleNameKey declaration. Add the existing
NameKeyType enum forward declaration and method signature. The real 69-byte
body at 0x000D140A and EH companion at 0x0076299F remain in
`Drawable/W3DProjectileStreamDrawPoolKey.cpp`. This repairs declaration
composition; it does not infer a new identity or alter a body.

## Verification and demonstrated unblock

All six standalone sources pass ./build.sh before the repair: 27/27 rows,
two string literals and two empty-string references. The changed seed passes
7/7 afterward. Supported allowed_symbols, link_census and data_check facts
before/after are identical for all six sources: 27 rows, 56 bindings (40 owner,
nine alias, seven EH), external definitions/digests, undefined names, COMDAT
selection flags and data facts. Only local EH label spellings are normalized.

The complete normal after dry run accepts seed plus key donor: two sources,
nine rows, versus none before. All 12 composed bindings are unchanged and the
11 selected external definitions preserve their providers and COMDAT facts.
No definitions drop or new unresolved symbols appear; data binding and
definition sets are equal. No divergent standalone external definitions exist
in this accepted subset. Both scoped EH parents remain EXACT standalone and
composed. The observer captures the normal merge verifier's object without
filtering routing, flags or admission, or manually compiling into match cache.

find_declared_unmatched, class gate and Microsoft-header check pass.
Converged data check passes for seed/key: ten addresses, zero second names or
unjudged rows. The refreshed planner passes --check. No source paths, includes,
compiler flags, hatches or protected registers change. Existing identity/data
findings remain owned and are not retired by a declaration.

The pending audit from merge base 60a1f8bf2a through 7852e91e9f plus this change
contains in-place source edits and evidence only: no moved/absorbed paths.
Active tools, hooks, workflows, includes, build inputs and registries need no
path repoint. Original EA paths and debt remain intact. The adjacent JSON
records object, composition, binding, selection and EH evidence.

No merge was applied; leave the accepted key donor for Luna. This is a verified
prerequisite, not a confirmed later Luna landing. Keep seed/key/evidence file
claims and both RVAs until publication; other trial-only claims can release.

## Remaining blockers

Module-data destructor differs in bytes. Module and destructor composition
fail with missing declarations before pointer types; constructor composition
has an undefined DrawModule base. Four mixed donors remain for separate
routing/split work. A 2025 handoff's seed/module-data-destructor compatible
subset is not reproduced by current input; no regression is inferred from
that historical statement alone. No recovered bytes, file reduction, identity
retirement, census gain or ownership improvement is claimed.

Scratch commands and receipts: build/sol-b5-projectile-*.
