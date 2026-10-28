# Scripts skip-predicate cleanup, 2026-10-28

Inspected revision: `0e9a68f517c61721cbedd3f069e166493076ca1e`.
Owner: `yasinschroeder-codexb4`.

## Verified change

`WriteGroupDataChunk` (0x003B6975, 166 B) called the bool spelling of
`Rva003B485AHolder::skipGroup`. The existing row at 0x003B485A is the
43-byte int-returning body. Its two return paths produce zero or one, while
the writer tests AL. The recursive clear caller at 0x003B4982 already calls
the int owner and explicitly truncates its result to an unsigned byte.

The writer now uses that same declaration and byte conversion. The predicate
needs no bool `/alternatename`, and its redundant bool pin is removed. No row,
class or file is renamed, and no translation-unit assignment changes.

Verification:

- `./build.sh` passes the predicate, writer and unchanged recursive caller:
  43 + 166 + 158 bytes, including string, float and import references.
- `link_check.py --prepare-current` verifies those three explicit providers
  with strict reusable receipts; it changes no census, index or status.
- `find_declared_unmatched.py` passes both edited sources before and after.
- EH verification has no EH rows or missing objects. Converged-data checking
  passes three sources and 11 addresses, with no second names or unjudged rows.
- Pin consistency passes. `hatch_counters.py --update` removes exactly the
  alias and pin entries: alternatename 2,915 -> 2,914; pin 9,417 -> 9,416.
- Before/after object facts retain all strong definitions, COMMON definitions
  and weak externals. The predicate and recursive caller retain every COMDAT
  digest. Only the writer's COMDAT digest changes, with its sole external-name
  change from the bool predicate to the existing int predicate. None of these
  three objects retains the bool spelling.
- Ordinary previews before and after report all three units LINKS, 367 -> 367
  authored bytes, using census index `41c28839bf` (2026-10-28 11:08). These are
  previews, not census gains.
- The staged-tree outgoing link audit is **inconclusive**: the index predates
  the outgoing base, and affected consumer
  `Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp` lacks a current
  receipt. Whole-batch consumer preservation remains for a current census;
  no clean batch-audit result is claimed.

The two edited sources have no code-identity, data, canonical-header or
Microsoft-header queue keys. No paths move, so no debt transfers, header-queue
repointing or path-consumer rewrites are needed.

## Consolidation exploration and remaining prerequisites

The consolidation picker claimed Scripts.cpp's 98 donor scopes. A fresh
`name_lane.py consolidate` packet under `build/consolidation/codexb4-scripts`
covered ScriptEngine; the original-path evidence, alternatives and declaration
and compiler blockers were reviewed. The current approved plan lists 312 rows,
98 clean donor files and 20 mixed files; the picker estimates at most 97 file
removals and 266 mergeable rows. The mixed files were not split.

All 98 clean donors passed the declared-unmatched precheck. Existing object
facts were saved before any edit. The supported broad `tu_skeleton.py --merge
.../Scripts.cpp --dry-run` was interrupted after about 24 minutes of active
compilation without returning an accepted/rejected report. It wrote no tracked
source or ledger changes. This is an incomplete exploration, not a failed
exhaustive merge. Its captured inputs precede the cleanup above; a future pass
must refresh the naming packet and trial inputs.

LINK-063 remains open: the protected OrCondition destructor's placeholder
identity and the seed's extra virtual pool slot are unchanged. Source-file
count and approved-TU coverage do not change, and no census or ownership gain
is claimed. Reconcile the seed's compiler/declaration context and those
documented identity prerequisites before another broad trial.
