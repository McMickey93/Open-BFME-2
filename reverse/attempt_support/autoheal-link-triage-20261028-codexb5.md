# AutoHealBehavior link triage

Inspected BFME 2 revision `2fd3f18efc4cc618d519c3180c4ea06ac0ec2a3e`.
The published provider index is `14dc3d2467` (2026-10-28 02:44 UTC).

`find_declared_unmatched.py` accepts the source and `./build.sh` verifies all
four matched rows. The ordinary `link_check.py` preview remains 0 of 142
authored bytes, with seven unresolved names: four mask-taking UpgradeMux
methods, `upgradeMuxCRC`, `upgradeMuxLoadPostProcess`, and the particle
factory.

The target ledger names `UpgradeMux::attemptUpgrade` at 0x004CE27C with a
const-reference mask; the donor view emits a by-value reference. The target
ledger's `ParticleSystemManager::createParticleSystem` at 0x001F5A6A returns
`BfmeParticleSystemHandle`, whereas this source emits the pointer-return
signature. These are ABI differences, not evidence that the target bodies are
absent. The other unresolved methods also need provider and class-contract
investigation. Reconcile the declarations and affected consumers together,
then rerun byte verification and the ordinary preview. No source change or
linking gain was claimed in this triage.
