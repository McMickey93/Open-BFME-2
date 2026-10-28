# AutoHeal obsolete donor pulse cleanup

Base: `0e774508a3eac5cbda6ca8a166e029fcf082ff7d`.
Published provider index: `54b83e4f69`, 2026-10-28 09:35 UTC.

## Target and donor evidence

The target ledger owns `AutoHealBehavior::pulseHealObject(Object *, Bool)`
at 0x004526C6 (207 bytes) in AutoHealBehavior_pulseHealObject.cpp. The recovered
PlayerScan update calls that two-argument method. The one-argument private
method in AutoHealBehavior.cpp was a retained Zero Hour donor implementation,
marked present-unmatched. Source searches find no caller of that overload;
the published index has no incoming edge to its exact mangled name,
`?pulseHealObject@AutoHealBehavior@@AAEXPAVObject@@@Z`, and does not mark it
reachable. This cleanup removes that unused donor body, not a retail row.

Its particle creation call expected a ParticleSystem pointer, whereas the
native factory at 0x001F5A6A returns BfmeParticleSystemHandle. Removing the
unused body removes that incompatible dependency without changing a shared
declaration. The old declaration remains in the shared shim pending class
reconciliation.

## Verification

- Frozen-file check passes before and after. `./build.sh` verifies all four
  destination rows and all 13 rows in the native pulse and PlayerScan units.
- Before/after COFF comparison preserves all 617 surviving COMDAT symbols'
  byte-and-relocation digests. There are no added or changed copies.
- Six copies disappear: the obsolete pulse, getAutoHealBehaviorModuleData,
  getFrame, getModuleData, getPosition, and the zero float literal. The five
  methods are unreachable in the published graph; the literal has 458
  census providers before this removal.
- Five undefined references disappear: attemptHealing,
  attemptHealingFromSoleBenefactor, the pointer-return particle factory,
  ParticleSystem::setPosition, and __fltused. No undefined reference is added.
- `hatch_counters.py --update` retires exactly one present_unmatched entry
  (3,751 -> 3,750). No ledger row, source path, pin, data-identity key or
  header-queue entry changes.
- Ordinary three-source previews preserve the pulse's 207 and PlayerScan's
  1,719 linking bytes. AutoHealBehavior.cpp remains unlinked (142 authored
  bytes), with six unresolved UpgradeMux names instead of seven total names.
  This is a preview; no census gain is claimed.
- `link_check.py --prepare-current` gives all three inspected sources strict
  reusable receipts and verifies all 17 rows. The staged-tree batch audit is
  still INCONCLUSIVE: the published index predates the outgoing base, and
  affected consumer Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp
  lacks a current receipt. This wider consumer closure remains for the next
  census; the local previews are not a clean batch-audit claim.

## Consolidation prerequisite

The supported `tu_skeleton.py --merge .../AutoHealBehavior.cpp --dry-run`
accepted no donor. PoolKey and activation need missing class declarations;
Xfer, PlayerScan, the native pulse and the constructor expose incompatible
private class views. The 12-byte Rva004523F5Ctor donor compiles with the
destination but the link guard refuses to absorb a census-linked donor into
this unlinked TU. No source move was retained. Reconcile the six UpgradeMux
dependencies and class views before retrying consolidation; the particle
dependency alone is cleared by this cleanup.
