# UserPreferences consolidation prerequisite investigation, 2026-10-26, codex

Allocated family A shard 0/2 target: `Code/GameEngine/Source/Common/UserPreferences.cpp`.
The runner allocation check returned 0. The scoped Common planner was read and
passed `name_lane.py consolidate --check build/consolidation`; current routing
was rebuilt in memory. No source, row, flag, hatch or register was changed.

## Ordinary admission result

`python3 tools/tu_skeleton.py --plan Code/GameEngine/Source/Common/UserPreferences.cpp`
reported 125 approved rows, five donor files, no mixed or refused files.
The corresponding ordinary `--merge ... --dry-run` accepted no donors and returned
2. Its report says the seed fails under every merged flag set (`bytes`). The
wins/losses donor also reports missing `UserPreferences::rva00537505` and `getInt`.
All five sources are census-linked, so admission also requires the current
supported link guard; a successful isolated byte comparison cannot replace it.

The existing declarations differ: the destination owns the real map base and
thirteen-slot typed virtual interface. The large stats donor uses v0..v12
placeholders; the wins/losses donor names getInt/setInt; time/turn statistics
have partial placeholder declarations. The constructor/destructor, const getter
signatures and map fields must remain those of the existing real owner. No new
class spelling, data layout or compiler override was guessed.

## Narrow cached diagnosis

The dry-run's cached seed-only compositions were inspected without compiling
through build.compile_source or modifying the shared match cache. Under the
stats donor's reduced preprocessor flags, `write` at RVA 0x003B1BF3 has the same
150-byte extent but first differs at +21. With the seed's own flags (and with
STLP static-library flags), all 48 of the seed's rows match.

A direct supported `tu_skeleton.Verifier` check confirmed baseline 48/48 and
seed-only composition 48/48, no lost row or compiler error; object
`build/tu_skeleton/b6a970d49dfcd055.obj`. This does not explain or override the
ordinary full trial's refusal. Investigate its flag/order/admission evidence
before attempting a broad declaration repair. No merge or downstream unblock
is claimed.

`find_declared_unmatched.py` reports all destination definitions already matched.
The source remains unchanged. Its blocked scope claim is released after banking
this handoff. Scratch evidence:

- `build/codex-session9-userpreferences-{planner,plan,before-trial}.txt`
- `build/codex-session9-userpreferences-diagnose.py`
- `build/codex-session9-userpreferences-cached-misses.json`
- `build/codex-session9-userpreferences-cached-*.cpp`

## Pending batch audit and other preflight

The outgoing commits are selected by `origin/master..HEAD`, rather than treating
new upstream commits as our changes. The pending Smudge prerequisite changes
consumer declarations in place, retires two data keys by the owning tool, and
removes one alias; the GameFont handoff and this handoff add documentation/log
entries. There are no pending source path moves, new include consumers or
registry repoints. Historical EA paths remain unchanged. The earlier Smudge
handoff contains the complete byte, data, identity, provider/consumer and
composition evidence and the inconclusive stale-index push audit.

The allocated SimpleObjectIterator target currently has zero approved rows and
zero donor files in the upstream plan. No claim or source edit was made there.
GlobalLanguage has a changed seed since its older blocked handoff (adjustFontSize
is now present); it is being reassessed separately rather than repeating that
older failed composition.
