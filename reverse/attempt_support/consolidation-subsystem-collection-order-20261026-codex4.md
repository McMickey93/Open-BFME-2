# SubsystemInterface collector blocked handoff, 2026-10-26 (codex4)

Allocated family-A codex4 target:
`Code/GameEngine/Source/Common/System/SubsystemInterface.cpp`.
The committed seed prerequisite remains intact. The collector experiment below
is reverted, including its temporary header. It produces no source change,
new accepted row, debt retirement, file reduction or recovered C++ byte.

## Tested hypotheses and boundary

The normal merge trial hoists the collector's `_STL` specialization before its
ModuleData forward declaration and inline overflow comparison. An experiment
kept these existing declarations in a collector-only header. Normal byte build
still verified all three rows / 243 bytes. The next dry-run cleared C2065
ModuleData and exposed missing postProcessLoadAll in the collector class view.
Adding that already-defined nonvirtual method declaration also kept all three
rows exact, but the subsequent dry-run rejected the collector at missing
rva001B51C0 and incompatible list views. Neither trial accepted another donor.
Do not repeat this declaration chain alone: the list's differing private vector
views and method sets need a coherent, verified reconciliation before it merges.

Receipts (scratch, not committed sources):
`build/codex4-subsystem-collection-order-trial.txt` and
`build/codex4-subsystem-collection-order-final-trial.txt`.
Standalone before/after snapshots compare equal. A comparison using upstream
allowed_symbols.Obj, digest, _object_defs and link_census._comdat_selections
also preserves every external code/data fingerprint, extent, exclusivity,
actual COMDAT mode and undefined reference. Allowed-symbol checks found zero
wrong bindings (7 owners, 1 EH, 1 fold, 1 alias); converged data has no second
names or unjudged bindings; EH data is EXACT. These checks prove the rejected
experiment preserved its own rows, not that a composition is safe.
The final restored collector was normally rebuilt and passes the frozen scan.
The blocked verdict is recorded through re_log.py; no nonmatching source or
extra header remains in Code.

## Coverage count correction and remaining prerequisites

The committed seed repair's normal trial accepts 15 distinct-address rows /
686 bytes. Whole-file byte checks count 16 ledger entries / 712 bytes because
rva001B4E49 and postProcessLoadAll both already name 0x001B4E49, 26 bytes.
That second spelling adds no coverage. The preceding handoff is corrected in
this commit; no identity decision, row edit or new fold proof is asserted.

The accepted seed/donor composition changes incidental STL providers and the
list constructor's relocation identity relative to the donor union. Those
bindings must be explained before Luna publishes the merge; exact row bytes
alone are insufficient. Reset/add private declarations, load-INI duplicate
placement new[] and two mixed-source routing cases remain separate blockers.
No merge or split was applied and no downstream Luna landing is claimed.

Other allocated read-only reviews this session: ModelConditionUpgrade's
missing getModuleNameKey requires unresolved vtable/ABI evidence; its existing
trial was not edited. LargeGroupAudio's already-recorded constructor/private
view blockers remain, and it later disappeared from the refreshed allocated
queue; no new work was started there. RiderChangeContain's native/reference
Xfer, AsciiString and DamageInfo conflicts and DeletionUpdate's canonical versus
full-reference GameLogic conflict match their existing handoffs. No unchanged
compiler trials or cross-family work were started for those reviews.
MessageStream issue #116 remains maintainer-owned and untouched.

## Batch and publication handoff

The complete outgoing batch has no source moves, deletions or renames. Combined
basename/path review of active tools, hooks, workflows, includes, build inputs
and protected registers needs no repointing; historical EA paths are retained.
Only the seed source prerequisite, inherited dispatcher/header adoption,
evidence and this verdict are outgoing. All actual changed source consumers
were rebuilt together or separately with scoped binding evidence. No TU map,
identity/data register or hatch baseline changes accompany this work.
No maintainer-only cycle, smoke or nightly ran.

The unused temporary-header claim is released. Retain these file claims until
the publisher confirms landing: Common/System/SubsystemInterface.cpp,
Common/SubsystemInterfaceListRva001B4FE9.cpp,
Common/SubsystemInterfaceListRva001B505F.cpp, and the dispatcher, seed and
collection-order handoffs in reverse/attempt_support. The collector claim is
retained solely for its unpublished inherited dispatcher commit; the new
collector attempt is closed. Settle landed RVA claims and release file claims
after the runner publishes the held batch.

File reduction 0; recovered C++ bytes 0; identity/data debt retired 0. The
inherited dispatcher repair retires two header-queue entries, reported
separately from this session's seed include improvement and blocked trial.
