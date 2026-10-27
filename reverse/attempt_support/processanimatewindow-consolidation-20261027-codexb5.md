# ProcessAnimateWindow composition prerequisites (2026-10-27)

Scope: `Code/GameEngine/Source/GameClient/GUI/ProcessAnimateWindow.cpp` and
its six clean donors, selected by `next_work.py --claim`. Starting revision:
`f8924e3512`. Preview index: `bf3dd31211`, 2026-10-27 00:39.

## Evidence and baseline

The naming planner and its currency check passed. There is no literal retail
source-path xref for this group in the planner: the Zero Hour same-spelling
path and the approved current in-memory TU map provide routing evidence, not
proof that a donor path was BFME 2 source. The committed map was not regenerated.
The supported plan has 37 approved rows, seven clean sources including the
seed, and three mixed files. The two earlier 2026-10-26 handoffs and the
2026-10-27 inherited handoff describe the same declaration prerequisites.

All seven ordinary previews initially report LINKS, totaling 2,791 authored
bytes. All defined bodies pass the frozen-file check. The seed has 13 matched
rows and grandfathered markers; this work does not claim those markers as
recovered bodies. The unchanged supported dry run accepts no donors: four
shards lose the global BfmeVciAnchorElem declaration, and the two slide shards
conflict on canonical ICoord2D and the private AnimateWindow field spelling.

## Reconciled shards

| Shard | Native boundary | Bytes |
| --- | --- | ---: |
| SpiralInitReverse | 0x005C5BE2 | 79 |
| SpiralUpdate | 0x005C5D33 | 333 |
| SpiralReverse | 0x005C5E80 | 261 |
| SlideFromRightUpdate | 0x005C64BE | 219 |

Keep each existing unemitted compiler anchor, make its helper type local, and
use a distinct anchor function name per shard. Removing the anchor entirely
changed the 34-byte vector-constructor iterator digest from 6246c280fc30 to
79b5519c2c51; that trial was reverted. Removing the seed type was also reverted:
the seed anchor uses it. A second supported trial with local helper types
exposes duplicate static bfmeVciAnchor definitions, hence the distinct names.
The final local-type/name changes leave every emitted definition unchanged.

Remove the inline-only `_RV` accessor macros so these sources use the seed
header spellings. Compare COFF definitions by relocation-aware digest and size:
all common names are identical, and the 2/6/5/5 renamed accessor copies are
identical after name normalization. Strong definitions, undefined names and
weak bindings do not change. The math-header inline configuration remains.
All four native bodies byte-match; ordinary previews retain LINKS (892 bytes).
Shadow/converged data checks pass. The init-reverse object exposes the existing
13-byte setStartTime copy under its ordinary name; the preview and shadow
identity check flag its difference from the 10-byte majority copy. It is
unreferenced and the preview does not count it as a blocker. Do not treat that
diagnostic as proof of native identity or retire any register on its behalf.

## Microsoft header cleanup in the remaining slides

Replace both private timeGetTime prototypes with `<windows.h>` in
SlideLeftUpdate.cpp and SlideTopUpdate.cpp. All four rows remain exact
(456 + 466 bytes), every emitted definition and external binding matches the
original objects, and both ordinary previews retain LINKS. A scoped refresh
through ms_header_audit.refresh_queue removes exactly those two queued rows;
all unrelated queue records are preserved. No local Microsoft names remain
in either source. Canonical ICoord2D adoption is retained.

## Composition and remaining work

The supported dry run accepts the seed and all four reconciled shards (17
rows, 1,869 bytes), protected by the census-linked input guard. The two slide
files remain rejected on canonical ICoord2D and private AnimateWindow member
declarations. The normal apply run now merges those five files and removes the four donors.
All 21 scoped rows still verify exactly (2,791 bytes), including the four rows
in the two surviving slide files. The merged destination owns 17 rows. The
frozen-file check, ledger check and shadow/converged data checks pass.
The mixed RightFastInitReverse, SpiralCtor and Disp8ByteFieldGetters sources
remain intact. Earlier mixed-file split failures are not retried.

## Applied-object and register audit

The merged object retains every strong definition and weak binding from the
premerge union and introduces no undefined name. Five COMDAT digest/size pairs
differ from that union: `_cosf`, `_sinf`, `?cos@@YAMM@Z`, `?sin@@YAMM@Z` (17 bytes
each) and `?getRestPos@AnimateWindow@@QAE?AUICoord2D@@XZ` (18 bytes). These are
referenced, not discarded-copy exemptions. The supported LinkGuard accepts the
actual merged object; its read-only view removes the absorbed census objects
and reports no unresolved, duplicate, COMDAT or selected-provider error, no
new losing outside copy and no missing referenced provider. This is bounded
preview evidence, not a new census.

The ordinary old-index preview instead retains the four retired donor objects
and reports their four duplicate strong methods in the destination. Both
surviving slides still preview LINKS. Carry the donor-removal/index freshness
limit into the next scheduled census; do not report this as a linking loss or
as a newly recorded linking gain.

The merger changes four function-ledger paths and four TU-map source cells;
it does not regenerate the committed map. Its owning hatch updater transfers
all 18 animation optimize occurrences to the destination with totals kept.
That full-tree updater also removes 15 already-stale register records (17
occurrences): three address-global occurrences for Rva00789900Init and 14
alternatename occurrences in Upgrade sources. Those sources were not edited
by this pass; these removals reconcile the register to existing code rather
than crediting this animation repair with those earlier source fixes. No
hatch is hand-added or admitted. No animation data/code-identity register key
is retired; header queues retain their other records, with exactly the two
Microsoft prototype rows removed by the scoped owning refresh.

Path-consumer audit: across the pending batch, the only local path removals
are the four animation donors. Combined old-path/basename searches find no
active tools, hooks, workflow, include, build/configuration or source-registry
consumer. The remaining seed provenance comments, old census source records
and spiral-math attempt evidence are historical references and remain intact.
All repointed ledger sources are tracked. Final publication audit after the clean rebase covers
`75b39b52832cbbec8327db99b454d656d6c1586c..3939a7047c36f019527ece58e18951209702ac10`
(all 11 pending commits, including the inherited data repairs). There are
exactly four source removals and no other path move in that range. The same
combined old-path/basename search includes root build/configuration files;
the only additional occurrence is a historical re_attempts.log entry. No
active consumer needs an edit. The pulled source, build and merger inputs
for this animation group are unchanged, and check_csv passes after rebase.
AGENTS.md changed upstream; it was reread immediately. Its added source-file
headline makes this four-file reduction source-recovery progress; linked and
ownership figures still await their normal measurements.

No census, linked-byte or image-ownership gain is claimed. No nightly, link
cycle or smoke runner was started.
