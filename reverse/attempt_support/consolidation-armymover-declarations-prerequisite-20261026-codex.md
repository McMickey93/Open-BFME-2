# ArmyMover trial and Sol session 7 handoff

Seat codex, family A shard 0/2, 2026-10-26. Wind-down was observed at
16:39 UTC. No new target will be started. The allocated queue authorized
LivingWorldAIArmyMover; both sources and the proposed scoped header were
claimed, and all three source claims were released after reverting the trial.

## Blocked ArmyMover trial: do not merge on bytes alone

Destination:
`Code/GameEngine/Source/GameLogic/System/LivingWorld/LivingWorldAISupport/LivingWorldAIArmyMover.cpp`.
Donor: the adjacent `LivingWorldAIArmyMoverDefendHomeTerritory.cpp`.
The current ordinary baseline trial accepts neither. Its first error is a
hoisted specialization using BfmePod20 before declaration. Competing player,
campaign, scenario and receiver views also prevent composition.

A trial scoped header shared the existing declarations, preserving accessed
offsets and signatures without new names, pins, flags or hatches. Both sources
passed **17/17 exact**, including eight EH-located funclets. Before/after
standalone COFFs retained all **201 non-debug sections** (160 + 41), with
identical bytes, relocations and COMDAT policies, all **154 external code
definitions**, data facts and external references. EH was **EXACT 3**, no
missing objects; frozen/class and converged-data checks passed (ten addresses,
zero second names or unjudged rows).

Raw allowed-symbol scans appeared to change eight unwind-row bindings because
the header renumbered local labels. Repeating the comparison with labels
located by `build.located_funclet` from exact parent EH data preserved all
**138 reference facts**, with no additions/removals. This was a scratch reader
comparison, not a change to a gate, ledger pin or identity register.

Once the declarations compiled together, only the 779-byte 0x0059C631 body
failed: its zero-field store moved after two stack pops and two loads at +739.
Moving the existing `move.m_08 = 0` assignment before `move.m_id` preserved
standalone bytes and made the ordinary dry-run accept both sources. That is
**not** sufficient acceptance evidence:

- Ordinary composed object `build/tu_skeleton/74a92b7dcc2ce782.obj` retains
  only **136 of 154** external code definitions. Eighteen COMDATs disappear;
  no new definition or changed surviving policy was found.
- Data facts and eleven external data definitions remain equal, as do aliases.
- Undefined references gain BfmePod20 vector `push_back` and ModuleData-pointer
  vector range `erase`. The declaration-only donor suppresses definitions
  emitted by the standalone seed, plus dependent template machinery.
- Selected replacement providers and affected outside consumers were not
  established. No census or link gain is claimed. Do not land a merge until
  those bindings are demonstrated against current providers.

The entire source/header trial was reverted; the restored sources again pass
17/17. Scratch `build/codex-session7-armymover-*` retains original and trial
sources/objects, ordinary trials, exact section/provider/data/EH comparisons,
EH-located reference facts and the composition mismatch. The substantive
blocked attempt is recorded through re_log.py at 0x0059C631. No game source,
header, identity key or routing map from this attempt is published.

## Verified prerequisites in this outgoing batch

The three source commits are separate from the inherited documentation repair:

- `a4024bef3f`: TunnelTracker valid-container declarations/intrinsic context.
  Standalone 10/10 exact; ordinary accepted scope 10 rows / 587 existing bytes.
- `066c861dfb`: TunnelTracker removal/membership receiver. Standalone 12/12;
  ordinary accepted scope **12 rows / 715 existing bytes**, up from the session
  baseline nine / 511. This demonstrates three newly compatible rows / 204
  existing bytes; no subsequent Luna landing has been confirmed.
- `efe58b203b`: TransitionDamageFX copy-forwarder provider declarations.
  Standalone 29/29 including eight aliases; ordinary accepted scope **21
  non-alias rows / 1,261 existing bytes**. The seed and 29-byte copy donor now
  compose with the same 57 code providers, policies, data and bindings. The
  inactive omitted fallback alias is documented in that prerequisite handoff.

The two completed TUs passed scoped before/after COMDAT/provider/consumer
comparisons. Full header gates passed 37/37 and then 39/39 for TunnelTracker;
the copy donor's commit gate passed 1/1. Final strict prepare-current checked
eight providers and 58/58 rows, including the ArmyMover trial before its
reversion; the six completed-TU provider receipts remain current. Scoped
new-variants checks pass for both completed scopes. ArmyMover is excluded
from the published source batch.

Recovered C++ bytes, source-file reduction and identity debt retirement are
each **zero**. This is verified prerequisite progress, not new coverage or a
measured linked-byte gain. Existing debt keys remain accounted for.

## Surveys and remaining prerequisites

AIUpgradeScienceBuilder was allocated and surveyed with its scoped planner,
`--plan` and ordinary `--merge --dry-run`: 30 approved rows, eight donor files,
two mixed files, no accepted merge. Most donors collide with the seed's STL
allocator/vector declarations; NormalUpgrades has declaration/type conflicts
and shutdown uses ScienceType before declaration. No source was edited or
claimed there. The first planner snapshot overlapped a temporary composition
file and refused currency; the sequential retry completed normally.

SupplyWarehouseDockUpdate remains blocked by allocator C2950 and missing AI
interfaces; CrushDie needs compatible multiple-inheritance receiver and
constructor/vtable declarations. WeaponBonusUpgrade's provisional data/function
identity cannot be guessed. Existing constructor/layout blockers in the other
allocated surveys were left intact; MessageStream issue #116 was not touched.
No cross-family donor, clean-room source or maintainer-only runner was used.

TunnelTracker still needs special members/vtable evidence, append ObjectID
conversion, replacement Object methods and Xfer/list/snapshot reconciliation.
TransitionDamageFX still needs Xfer enum/receiver, FDE/record members, pool
receiver, erase/destructor bytes and append/map allocator reconciliation.
The shared linking obstacle register was held by another worker, so these
bounded receipts are handed off here rather than overwriting its work. Its
old TunnelTracker contain total of 611 must be read as **511**, as established
by the current target_size sum and corrected in this batch's earlier handoff.

## Complete pending-batch tooling audit and claims

Audited the outgoing four commits from upstream 00af29220b plus this staged
attempt log/handoff. Earlier source SHAs in individual handoffs predate the
rebase; the three source SHAs above identify the current outgoing commits.
There are no game source additions, deletions, renames or moves, no protected
register changes and no changed include consumers beyond the four scoped
TunnelTracker sources and two TransitionDamageFX sources verified together.
Combined path/basename searches cover tools, hooks, workflows, includes,
build/configuration inputs, ledgers, registries and documentation. Existing
owners, fold proofs, debt keys and historical EA paths remain valid. Nothing
needs repointing. The abandoned ArmyMover header is absent from the index.

Keep these file claims until publication is confirmed: TunnelTracker seed,
contain, scoped Nemesis header, Thing valid-container/removal donors and both
session TunnelTracker handoffs; TransitionDamageFX seed, Common copy donor and
its handoff; inherited DataChunk writer handoff; this handoff. After landing,
release these twelve file scopes and settle RVAs with claims.py release
--landed. If publish queues the batch, the runner owns final publication; do
not invoke it alone. The pre-push audit's stale/inconclusive evidence remains
for the next normal census, with no headline measurement claimed.
