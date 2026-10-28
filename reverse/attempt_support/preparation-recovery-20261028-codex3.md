# Preparation recovery, 2026-10-28

The preparation record names backup
`refs/runner/preparation/1793214988636676631`, upstream
`49d65e3beadc5f9b784d87bdbc17ed7356aa8104`, and preserved tip
`fbf8577292cce4bde307de2f39cd75cfa3e1efcc` (nine outgoing commits).
At recovery entry the recorded resync had already completed: HEAD exactly
equalled the backup, the index and working tree were clean, and no rebase
operation remained. No commit was skipped or rewritten in this recovery.
The record names neither a stash nor a resync stash. No staged, unstaged or
untracked edit needed restoration; older stashes and the backup remain intact.

## Cached publisher refusal

The publisher's stored refusal refers to combined tree
`63b6ac47bef792f2592efc6d6df271c4f1678e3e`, based on
`5eb461cefdf341b80b9bbe7d7d79b93671560669`. It reports two funclet rows
still naming deleted donors. Current upstream already contains the merges:

- `e1493aef3f4b0b25ad9286db3eac0ee2d301bd1c` absorbs
  `Common/Rva005B947DTicker.cpp` into `Common/AptOnlineHome.cpp`.
  The row at `0x0079F984` now names that surviving owner.
- `bd20921ccbae4e58fc3ddcb389bab57ead407344` absorbs
  `GUICallbacks/Apt/AptMpClansRva0057FA1C.cpp` into
  `GUICallbacks/Apt/AptMpClans.cpp`. The row at `0x0079C65F` now names
  that surviving owner.

Both corrected rows are present in the preserved tip. Restoring either
deleted donor would reintroduce obsolete source. The first recovery publish
attempt returned the cached refusal despite the current dry-run gate passing.
This handoff records the already-reconciled state for a fresh publication
candidate without modifying the preserved commits or the publisher's state.

## Current verification and batch path audit

`python3 tools/check_csv.py` passes: 98,945 function rows, 9,417 symbols and
2,203 data rows. `git push --dry-run origin HEAD:master` at the preserved tip
passes the actual push hook: 211/211 matched functions across nine source
files, two data rows, 29 EXACT EH graphs, 20 string literals plus five empty
strings, 26 float literals and 13 imports. Enforced converged data checking
reports 11 addresses, zero second names and zero unjudged rows. Pin and
protected-register checks pass. The earlier ledger refusal is not reproduced
against this checkout and base.

The complete outgoing path audit covers `49d65e3bea..fbf8577292`, including
all 53 absorbed source paths and their basenames (ParticleSys and
InvisibilityUpdate composition, net 52 fewer source files). A combined
tracked search covers tools, hooks, workflows, Code, docs and reverse. It
finds no active tool, include, build/configuration, Doxygen, source-registry,
debt-register, queue or fold-proof consumer left on a deleted path. Remaining
mentions are source provenance comments, archived attempt support, the
census-owned link-status snapshot, deleted-row history, append-only naming
refusal details and attempt records. Preserve those historical references.
Existing per-composition handoffs retain provider/COMDAT comparisons and
the protected-register transfers; no additional source move is made here.

The current push-hook link audit remains INCONCLUSIVE: index `d92e7e6635`
predates base `49d65e3bea`, and 84 affected objects lack current receipts
(first `Common/BigChainBaseDtorsO1.cpp`). The existing ParticleSys,
InvisibilityUpdate and UnitRevivalEntry obstacle entries retain the pending
provider/consumer and scheduled-census scope. This recovery establishes no
census-linked-byte gain, image ownership result or runtime result.
