# ClickReaction module-data prerequisite, 2026-10-26, codex4

Allocated target: Code/GameEngine/Source/GameLogic/Object/Behavior/ClickReactionBehavior.cpp.
The Behavior planner and currency check passed before editing. Current routing
approves eight rows across four donors, two mixed; no refused routing rows.
The destination, constructor donor, private header and module-data class were
claimed. No ledger/source paths, routing map or protected keys changed.

The seed's module-data view read a scalar at +8 and five cooldown ints at +0xC.
The constructor donor independently described the same prefix as a vptr at +0,
an untouched word at +4, a scalar at +8 and five individual ints at +0xC..+0x1C.
Both now include ClickReactionModuleDataView.h. The constructor uses the seed's
existing field spellings and array; its stores, layout and vtable binding are
unchanged. This records structural agreement, not recovered upstream names.

Before --merge --dry-run accepted no pair: the constructor lacked the seed's
m_weight declaration. After it accepts seed plus constructor: four rows / 531
existing retail bytes, including the constructor's 28-byte ledger extent.
The pool-key donor still needs its getter declaration and the primary constructor
still needs receiver-field reconciliation (m_f28). Mixed donors remain separate.
No merge, new bytes or downstream Luna landing is claimed.

## Acceptance and binding comparison

Before and after ./build.sh for both sources: 4/4 exact; one string literal
verified, no float/import failures. Both find_declared_unmatched.py scans pass.
allowed_symbols.py --source reports eight references (seven owners, one fold),
zero wrong bindings. Ordinary data_check.py preserves the pre-existing constructor
_vtbl_00C4ED70 wrong-name finding at 0x0084ED70, outside its register; no data
identity is retired. --converged checks ten addresses across two sources with
zero second names or unjudged addresses. EH checks find no applicable rows or
missing objects. No canonical class or source-specific protected debt key was
silently discarded.

Before/after object snapshots are identical for all code/data definitions,
relocation digests, sizes, exclusivity, undefined references and COMDAT selections.
Using upstream COFF, allowed_symbols and data_check helpers, composition object
build/tu_skeleton/f49dec84fe29772a.obj equals the standalone union: eight code
definitions, one external data definition, eight COMDAT selections and nine
remaining undefined references. All four row DIR32 data-binding sets are equal
before/after/composed. The constructor's vtable reference and seed's diagnostic
path reference remain at 0x0084ED70 and 0x00841368 respectively.
Receipts: build/codex4-click-data-{before,after}.json, -before-trial.txt,
-after-trial.txt, -proof.txt and the corresponding build/check receipts.

## Complete pending-batch audit and handoff

Audit from merge-base 73dd328e9b includes all four earlier prerequisite commits
plus this change and its new private header. Combined searches cover active tools,
hooks, workflows, Code includes, reverse registries, docs and build.sh/build.ps1.
Only intended header consumers, current owner records, unmerged-row comments and
historical evidence refer to these paths; no consumer needs repointing. Both
private-header consumers compile standalone and together. Historical EA paths
remain intact. Receipt: build/codex4-click-data-path-audit.txt. No source moves,
deletions, regenerated TU map, baseline expansion or identity retirement occurred.

Keep the four ClickReaction claims and the earlier Prone/BattlePlan/Display scope
claims until publication is confirmed. Across the five-commit batch, three TUs
now compose 18 existing rows / 1710 bytes in normal dry-runs: Prone 5/189,
Display 9/990 and ClickReaction 4/531. BattlePlan separately retires one header
adoption row and one class-gate hatch; further receiver/header blockers remain.
Three private headers were added; no source files removed, no new retail bytes
recovered and no code/data identity debt retired. These are verified prerequisites,
not census linked-byte growth. DemoTrap, AssistedTargeting and DetachableRider
blocked investigations are banked in the preceding commits with claims released.
