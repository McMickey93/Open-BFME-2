# LaserDraw key declaration prerequisite, 2026-10-26

Seat codexb5, family B shard 1/2. Allocated destination:
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DLaserDraw.cpp`.
The current Draw planner was reviewed for original-path evidence, alternatives
and class/include prerequisites. Normal routing rebuilds the stale TU map in
memory; no map was regenerated or committed.

## Concrete blocker and repair

The full normal baseline dry run approves 38 rows but accepts no multi-source
subset. The pool-key donor fails because the seed's W3DLaserDraw declaration
omits the already-rowed `getModuleNameKey() const`. Add that declaration and a
forward declaration of the existing NameKeyType enum to the seed. The real
name, signature and 69-byte body at 0x000C9BCC already belong to
`Drawable/W3DLaserDrawPoolKey.cpp`; no new function identity is inferred.
The donor and its EH companion at 0x007622D8 remain in place for Luna.

## Verification

Before the change, `./build.sh` on all seven eligible whole sources verifies
31/31 rows, two strings, one empty string, 22 float literals and zero imports.
After the change, the seed remains 8/8 exact with its one float literal.
Supported allowed_symbols, link_census and data_check before/after facts over
all seven sources are identical: 31 rows, 88 bindings (68 owner, ten alias,
four fold, six EH), definitions/digests, undefined names, COMDAT selection
flags and data facts. No divergent external definitions exist among these
standalone sources. Only local EH label spellings are normalized.

`find_declared_unmatched.py`, class gate and Microsoft-header gate pass.
Converged data check passes on seed and key donor: ten addresses, zero second
names or unjudged rows. EH verification is EXACT for both scoped EH parents.
No body, compiler flag, hatch, protected register, include or source path moves.
The existing seed ABI queue and pool-key data finding remain accounted for.

The complete normal after trial accepts seed plus key donor: two sources, ten
rows, versus no accepted subset before. All 18 composed bindings are identical;
53 external definitions have unchanged selected providers and COMDAT facts.
No definitions drop, no new unresolved name appears, and data binding/definition
sets are equal. Composed EH verification remains EXACT for both parents. No
merge was applied; this demonstrates compatibility for the existing 69-byte
body and EH companion, not a confirmed downstream Luna landing.

The refreshed Draw planner passes its --check. The outgoing commits from merge
base 60a1f8bf2a through 38e523d8d8 plus this staged prerequisite
change one source in place and add evidence only. There are no outgoing source
path moves; active tools, hooks, workflows, includes, build inputs and registries
need no path repoint. Original EA paths and all protected debt remain intact.
The adjacent JSON retains complete source/object/composition/selection facts.
Keep seed/key/evidence file claims and both key RVAs until publication, then
release file scopes and settle landed RVAs. Other trial-only claims may release.

## Remaining prerequisites

Baseline rejections: constructor duplicate RefCountPtr definitions;
doDrawModule duplicate AsciiString definitions; module-data destructor bytes;
draw destructor incompatible void-pointer/vector element views; vector
overflow bytes. Mixed GlobalFlagClearers, W3DDrawNameGetters and STLport
construct/fill donors remain behind. No full-TU clearance is claimed.

Scratch commands and receipts are under `build/sol-b5-laser-*`. The observer
only captures the object from the complete normal merge verifier. It does not
filter routing, alter flags/admission or compile into the shared match cache.
No recovered C++ bytes, file reduction, identity retirement or census/ownership
improvement is claimed by this declaration prerequisite.
