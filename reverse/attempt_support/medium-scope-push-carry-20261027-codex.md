# Carry verified medium push scopes after a concurrent master update

The final GameClient `SubsystemInterface` adoption from PR #115 repeatedly
passed the ordinary pre-push gate but lost the Git compare-and-swap race with
other writers. The last observed attempt, at local tip `81ecff31f4`, verified
549 sources, 714 EH records (711 EXACT and the same three baseline exceptions)
and zero converged-data violations. Git then rejected the update: advertised
master `2a4c654a3b585870d316955ba53e8bf156b3381d` had become
`f826af9b9c4433dd6e2d7f52dc3a638c028aedb1`. The bounded gate takes about eight
minutes on this Windows host. This is publication contention, not a verifier
false reject or an unverified source repair.

The existing receipt path only asked for and recorded scopes of 1,024 sources
or more. Lower that cost threshold to 512. Leave the independent 1,024-source
full-provider classification threshold unchanged. A first bounded push still
verifies every selected source and completes every required audit before the
hook records its commit. A carried retry records no new receipt.

Receipt eligibility is unchanged: the verifier and tree-wide baselines must
agree, the intervening dependency change must be bounded, and the pushed
sources and headers must agree with the working tree. A retry verifies the
intervening source/flag/header/name scope and retains tree-wide cross-source
checks, plus all-source EH/converged-data audits when those registers changed.
The hook edit invalidates older receipts; the first source gate with this
verifier must create its own evidence. No receipt is manufactured manually.
Shadow link and replay audits retain their existing inconclusive behavior.

Regression evidence before the change: the 511-source boundary passed, while
512 and 550 both failed the new receipt expectation (2 failed, 1 passed).
After the change all 11 new cases passed: 511/512/550 boundaries, no receipt
after build/EH/data failure, and a carried retry that builds only a newly
changed source while propagating build/cross-source/EH/data failures. The
real receipt eligibility guards remain covered by `test_full_gate_receipt.py`.
Independent read-only implementation review found no blocking issue.

The complete targeted regression run passed: 190 passed, 1 skipped, covering
`test_pre_push_chunks.py`, `test_full_gate_receipt.py`, `test_gate_exploits.py`,
`test_hook_fail_closed.py`, `test_hook_argmax.py`,
`test_pre_push_final_audits.py` and `test_pre_push_worktree_chunks.py`.
All exploit refusals remain intact. This tooling prerequisite changes no game
source, ledger row, baseline, escape hatch, census figure or runtime claim.
