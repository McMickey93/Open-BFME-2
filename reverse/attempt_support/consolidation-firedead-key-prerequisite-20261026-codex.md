# FireWeaponWhenDeadBehavior pool-key declaration prerequisite

Seat codex, Sol family A shard 0/2, 2026-10-26. The allocated queue lists
Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDeadBehavior.cpp.
Read current AGENTS.md, consolidation workflow, original-path planner packet,
current plan and the Luna handoff. No merge, split or naming vote was applied.

The ordinary trial rejected FireWeaponWhenDeadBehaviorPoolKey.cpp with C2039:
getModuleNameKey was absent from the seed class. The seed now declares the
existing NameKeyType return type and virtual method after xfer, in primary
vtable slot 4. This is target evidence: retail table RVA 0x008497B4 has the
rowed 0x00482E51 method at offset +16. No layout or donor name is inferred
from a same-name hit. All earlier vtable entries are unchanged.

The ordinary --merge TU --dry-run now accepts seed plus pool-key donor:
**six existing rows / 306 retail bytes**, where previously no donor batch
was accepted. Two rows / 79 existing bytes are newly composable. This is a
demonstrated prerequisite unblock for Luna, not a confirmed downstream
landing, new coverage, file reduction, debt retirement or link census gain.

Verification:

- ./build.sh TU FireWeaponWhenDeadBehaviorPoolKey.cpp passed 6/6 before and
  after, including EH-located constructor funclet; two literals and one float
  passed. find_declared_unmatched.py accepts both sources; class_gate passes.
- Before/after standalone COFF comparison preserves all eight external code
  definitions, code/data reference facts (12 code facts), COMDAT policies and
  non-debug sections except two explained changes: the primary vtable grows
  from four to five slots with the retail-correct method, and its SafeSEH
  symbol index changes while the named handler remains identical. The donor's
  eight sections are identical. Existing data reference/definition facts agree.
- The ordinary composed object build/tu_skeleton/2ad6b8c84f47e756.obj retains
  all eight external code definitions with identical normalized code and
  relocations, COMDAT selection policies and aliases; all eight external data
  definitions and their bytes/relocations/selection policies agree with the
  standalone union. There are no definition conflicts, missing providers or
  added/removed unresolved symbols after internal resolution. Per-source data
  bindings and union data definitions are equal. The only new standalone
  binding is the verified primary vtable slot to the existing pool-key owner.
- eh_verify.py: EXACT 2, no missing objects or non-exact graphs. Enforced
  converged data: ten addresses, zero second names and zero unjudged rows.
  link_check.py --new-variants on both sources exits 0. Strict
  link_check.py --prepare-current passes two reusable providers / 6 exact
  rows, changing no census, index or status. An earlier preparation overlapped
  the ordinary trial's temporary source and correctly refused input currency;
  the sequential retry above passed without any exception.
- Local evidence: build/codex-session8-firedead-{before,after}-build.txt,
  {before,after}-trial.txt, section-proof.json, vtable-proof.json,
  data-delta.json, reference-delta.json, composition-proof.json and prepare.txt.
  Scratch comparisons use the existing COFF, identity and data readers; no
  compile_source call touched the match cache.

Remaining prerequisites: OnDie still fails C2504 UpgradeMux base undefined in
ordinary composition; its wider receiver/field/view reconciliation was not
attempted here. The two mixed sources remain mixed, including the previously
reported hatch-rule-3 split refusal. The pool-key donor's existing data debt
key remains in reverse/data_check_baseline.txt and its data-ledger ownership
remains unchanged. A later merge must carry those keys with the tool's printed
Verifier-Change trailer; it does not retire them. Header queues and code
identity keys do not name the edited seed; no queue or register was edited.

Complete pending-batch tooling audit: origin/master..HEAD was empty before this
prerequisite, and the staged change has no source addition, deletion, rename,
move or changed include. Active tools, hooks, workflows, includes, build inputs
and registries retain the same paths and provider identities. Existing debt,
fold proofs, historical EA paths and ledger owners need no repoint. The scoped
Behavior planner was regenerated after the source edit. The shared obstacle
register was held by codexb, so this bounded receipt is handed off without
editing its claim. The pre-push audit remains required; no maintainer-only
runner was invoked.

Keep seed, pool-key donor and this handoff file claims until publication;
release those three scopes after landing and settle RVAs with
claims.py release --landed. Recovered C++ bytes, source-file reduction and
identity debt retired are each zero. No later Luna landing is claimed.
