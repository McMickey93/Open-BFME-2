# BuddyThread base cleanup and consolidation handoff

Inspected BFME 2 `f7c25b0bd4` on 2026-10-27. Census index:
`bf3dd31211`, 2026-10-27 00:39, retail-truth-4. The default picker claimed
BuddyThread.cpp and its ten standalone donors before investigation.

## Target evidence and retained change

Retail destructor RVA 0x0055133F (170 bytes) calls RVA 0x00610480 at
instruction offset 152 (REL32 relocation offset 153). The existing matched
owner at that target is `ThreadClass::~ThreadClass`, seven bytes, in
`ThreadClassLifecycle.cpp`. Both that provider and BuddyThread.cpp already
have a ThreadClass view with a vptr, name[64], thread ID, handle and priority
(size 0x50). These are target/provider facts, not donor-name recovery.

The derived destructor view now inherits BuddyThread.cpp's existing
ThreadClass directly. Its padding begins at +0x50 and ends at +0x60, leaving
all five string members, the critical section and lock holder at their old
offsets. The placeholder Gen_uwm_00610480 base declaration and its linker
alternatename are removed. No application class name is inferred for the
derived Rva0055133F view, and no header, pin, row or source path is added.

## Verification

- Before and after `./build.sh BuddyThread.cpp`: 23/23 matched rows;
  string references 53 literals plus two empty references; one named import.
  Eight funclet rows resolve through their verified parent graphs despite
  renumbered compiler labels.
- Before and after `eh_verify.py`: EXACT 4, zero nonexact or missing objects.
- The saved before object and rebuilt after object have identical raw
  170-byte destructor bodies and eleven relocations. Their only relocation
  difference is offset 153, REL32, changing
  `??1Gen_uwm_00610480@@QAE@XZ` to `??1ThreadClass@@UAE@XZ`.
  Both bind to the same existing retail address.
- `find_declared_unmatched.py` passes for all eleven original candidate
  sources and again for the edited seed. No unrowed body was introduced.
- `data_check.py`: zero shadow findings.
- The hatch register is lowered only through `hatch_counters.py --update`:
  one alternatename removed. The three existing optimization directives stay.
  The tool also removes an old allow stamp on the unchanged 49-count
  0x0007FAB3 pin key; that count is unchanged.
- Ordinary before/after link previews have the same five duplicate blockers,
  reporting 1,406 historical linked bytes versus 1,750 current authored bytes.
  The index still supplies these names from deleted Rva0055133FDtor.cpp,
  Rva00550995LockCleanup.cpp and S1PointerOrDefaultGetters.cpp objects. Those
  rows now belong to BuddyThread.cpp after earlier consolidation `ea4412ec3a`.
  This is stale index ownership, not evidence of lost rows or new duplicates.
  No census-linked-byte or runtime gain is claimed.

## Consolidation attempt and prerequisites

The supported name-lane planner was regenerated with pinned inputs. The TU
map on disk is stale; tu_skeleton rebuilt routing in memory without committing
that map. Its plan approves 133 rows, eleven standalone donors (82 rows,
including the 23-row seed), twelve mixed files and no refused rows. The
normal exhaustive `--merge ... --dry-run` exits 2 with no accepted merge.
Its complete output is in the adjacent `.dry-run.txt` file. No merge was
applied, and no nonmatching source remains under Code/.

| Donor | Remaining prerequisite from normal dry run |
| --- | --- |
| BuddyRequestDequePushBackAux.cpp | duplicate `_STL::_Construct` template |
| BuddyResponseDequePushBackAux.cpp | duplicate `_STL::_Construct` template |
| BuddyThreadClassCtor.cpp | duplicate `_STL::char_traits` template |
| BuddyThreadConnectCallback.cpp | string destructor specialized after instantiation |
| BuddyThreadFeslCallback.cpp | incompatible BuddyResponse view (`kind`, `error`) |
| BuddyThreadStartThread.cpp | receiver lacks donor's `m_lock70` member |
| StlportDeque2148Cleanup.cpp | combined bytes fail; row not localized by report |
| GameResultsThread_GameResultsInterface_createNewGameResultsInterface.cpp | combined bytes fail; row not localized by report |
| BuddyThread_Unresolved.cpp | unresolved response deque map creation and allocators |
| StlSweepR3Rva00551B02.cpp | unresolved `Rva00551B02Record` destructor; existing owner lead is LINK-043 |

Reconcile donor views and existing provider identities in separately verified
changes before retrying the merger. The former static-enum semicolon rejection
is no longer the blocker; current tooling has its regression test. The alias
cleanup does not claim to clear the above donor incompatibilities. One existing
queue<Response> wrong-binding identity key stays registered; no identity or
header key is retired by this change. Source paths did not move, so no new
path-consumer migration is needed for this commit.

## Reference freshness

Official BFME 1 master was fetched at
`9116bca34d7112fb7f5d3eafef197a1e5f6c555b`; the reference-update scope is
held by `yasinschroeder-codex4`. This seat briefly advanced its local checkout
before noticing the refused claim, stopped the resulting build, and restored
the original `e74410b3738a2bb75d626085d9ebfd3406a43ff7` pin and git index.
No reference update or successful freshness stamp is recorded. This cleanup
uses retail and existing BFME 2 providers independently of those upstream edits.
