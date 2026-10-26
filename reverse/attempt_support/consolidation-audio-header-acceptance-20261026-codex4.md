# AudioEventRTS header-queue acceptance, 2026-10-26

Allocated family A, shard 1/2 destination:
`Code/GameEngine/Source/Common/Audio/AudioEventRTS.cpp`.
The current Audio-scoped planner and currency check pass. Normal routing
finds 66 approved rows, six donor files and four mixed files. No move applied.

The destination already includes the registered GameLogicObjectLookupView.h
and has no private GameLogic body. Its queue entry still describes an earlier
duplicate ObjectID failure. This change records current acceptance of that
existing adoption; it does not claim a new authored-source repair.

- `./build.sh SOURCE`: 28/28 exact; six funclet pins checked through parent EH
  placement despite local-label renumbering. String, float, import and scoped
  claim checks pass.
- `find_declared_unmatched.py SOURCE`: all defined functions already matched.
- `header_adopt_lane.py accept --class GameLogic SOURCE`: PASS and exactly one
  stale row retired through the supported acceptance path.
- Normal `tu_skeleton.py --merge TU --dry-run` accepts zero donors. Current
  blockers are AudioManager/TheAudio declaration order in Classification,
  Classification's Xfer adoption, incompatible ClientFrameSubsystem methods
  in Finish/Scale, Object/position-result views in OwnerPosition, and the
  remaining AudioManager getter declaration in the string donor. Mixed
  sources stay behind. There is no demonstrated new merge acceptance here.

Receipts: `build/codex4-audio-{header-build,header-accept,current-trial}.txt`.
No source or header content changes, compile flags, relocation bindings, data
definitions, COMDATs, selected providers or provider/consumer bindings change
in this queue-only commit. The source's normal cached object receipt is
current. Existing data and code-identity debt remains accounted for, with no
identity retirement. No composed object is published or asserted safe.

Audited the whole pending range plus this queue retirement: no source paths
move, rename or disappear. The merge-base/outgoing log distinguishes incoming
origin changes from the three local commits. Active tools, hooks, workflows,
includes, build inputs and registries need no path repointing. Original EA
strings and evidence remain. Header debt retired: one; files removed: zero;
recovered bytes: zero. No census or ownership receipt is created.

Other allocation probes, without claims or edits: LivingWorldEyeTower retains
the previously recorded constructor/STL and Xfer prerequisites. The Xfer view's
slot names disagree with the canonical majority view, so operand forward
declarations alone do not establish adoption. The existing receiver repair
remains in place. AIGroup's 131-row plan does not include AIGroupChain00472B54;
its similarly named header-queue entry is not a dependency of this destination
and was left alone. DockUpdate's two Coord3DCtorView users already use the
opt-in constructor view; replacing it with the plain aggregate header would
need code-generation evidence. No speculative ABI change or repeat of those
old blocked attempts was made.

Session batch also contains the ModelConditionUpgrade scanner false-reject
repair and PoisonedBehavior's actual GameLogic adoption. Those handoffs record
their tests and provider comparisons separately. Header debt retired in this
session: two; code/data identity debt retired: zero; file reduction: zero;
recovered C++ bytes: zero. Neither a later Luna landing nor new linked bytes
are claimed.

Keep all eight file claims (scanner, scanner tests, three handoffs,
PoisonedBehaviorUpdate, AudioEventRTS and header_queue.tsv) until the runner
confirms publication. No RVA claims were acquired. If the batch remains held,
release those scopes after landing and run claims.py release --landed.
Inherited commits were already upstream and their old scopes were released.
The unrelated untracked reverse/zh_sweep directory is preserved.

Recovery verification, next session on 2026-10-26: the three inherited commits
are still local (59ba4cfa22, b8c31040de, 74d2342e38), with no preserved tracked
edits. Pull/rebase and check_csv pass. The official two-source build again
passes 32/32, both frozen scans pass, and the scanner plus gate-exploit suites
pass 78 tests with the same one existing skip. PoisonedBehavior's scoped
allowed_symbols check again reports zero wrong bindings and data_check zero
findings. Re-audited origin/master..HEAD plus this documentation update:
no source path additions, deletions or renames, so no path consumer changes.
The existing provider comparison above remains applicable: source content and
the current cached objects are unchanged. This recovery receipt accompanies
the required commit-and-publish retry; release retained scopes after confirmed
publication, or carry them forward if the shared publisher holds the batch.
