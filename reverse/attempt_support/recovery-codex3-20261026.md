# Preserved consolidation recovery (2026-10-26)

Recovered the four commits originally ending at `427bc163e6`, rebasing onto
`f10505e4cf` without skipping or aborting any commit. The preserved changes are
AptArray's three-donor merge and one-row split, dx8vertexbuffer's four-donor
merge, and the existing TunnelTracker blocked-attempt handoff. No new work was
selected. These moves recover no new matched or census-linked bytes.

Conflict decisions:

- `reverse/ms_header_queue.tsv`: the original AptArray commit changed ordering
  only (the before/after sets of all 3,302 lines are identical). Kept the current
  upstream queue. A fresh `ms_header_audit.scan_text` / `write_queue` comparison
  for both destinations and the AptValueArrayAt residual gives exactly the
  existing scoped entries; no debt was removed.
- `reverse/data_check_baseline.txt`: kept upstream's register and transferred
  only the two DynamicVBAccessClassDeinit keys to dx8vertexbuffer. Discarded
  unrelated stale register additions bundled with the old merge. No debt was
  retired; the transferred diagnostics remain visible under their new owner.

Verification at recovered tip `b5416d650e`:

- `check_csv.py`: OK, 98,272 function rows, 15,626 pins, 2,224 data rows.
- `./build.sh` on AptArray, AptValueArrayAt and dx8vertexbuffer: 27/27 matched.
- `find_declared_unmatched.py` on those sources: all definitions matched.
- `git push --dry-run origin HEAD:master`: PRE-PUSH OK, 65/65 rows across six
  affected sources, 10/10 EXACT EH graphs, converged data and pin checks pass.
  The transport subsequently rejected this dry run because origin moved; the
  runner publisher rebases and checks the resulting outgoing batch again.
- The required path-consumer audit searched deleted source paths and basenames
  across tools, hooks, workflows, Code, docs and reverse. No executable consumer
  needs repair. Surviving old names occur in provenance/comments, historical
  evidence/map strings and the census link_status snapshot. No deleted donor
  path remains in header queues, identity/data registers or name_basis.

Link-provider limitation (LINK-017): the hook's batch audit uses provider index
`bcb191bfeb` against outgoing base `f10505e4cf` and reports four sources without
current receipts (first Eva.cpp). Selected-provider changes, consumer bindings
and lost-byte comparison remain inconclusive pending the next current census.
No provider clearance or linked-byte increase is claimed. The shared obstacle
register was held by another worker when this recovery requested its file claim;
this handoff and the runner finish note carry the evidence instead.

Saved edits: stash `def3e6f80c99b8bc6df28a9c1e56c484b012b6bb` has no tracked
index/worktree edits. Its 30 untracked files (20 orphan gen_asm dumps and ten
ZH sweep packets) were all checked byte-for-byte, then restored with
`git stash apply --index`. None is referenced by functions.csv or data_rows.csv.
They remain untracked in the checkout, with an additional identical local copy
under `build/recovery-codex3-saved-untracked/`; the stash and preparation backup
`refs/runner/preparation/1793043152549386023` remain intact. These saved files
are evidence/scratch, not new progress. Raw audits and publisher logs are under
`build/recovery-*`.
