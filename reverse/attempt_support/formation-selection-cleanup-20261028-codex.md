# Formation selection parser alias cleanup and TU evidence

Inspected base: `1d3867f364`. BFME 1 reference: `e74410b3738a2bb75d626085d9ebfd3406a43ff7`,
with the verified 2026-10-27 freshness receipt. Preview index: `41c28839bf`,
2026-10-28 11:08; underlying census: `c8734bec0c`.

The default picker claimed the TU-evidence run 0x00423D0D..0x00424709
(18 rows in 16 sources). Its lower bracket is FormationAssistant at
0x00423AEC; its upper bracket is LightSubPoint at 0x004247E3. Different
brackets do not approve the intervening rows.

`tu_evidence.py --source Code/GameEngine/Source/Common/Rva00423D0DCreate.cpp`
produces no structural signal. The supported Common-subsystem planner reports
no placement evidence or alternatives for the allocator, UnitDefinition parser
or FormationSelection parser. `tu_map.py --dir` for the served allocator
rebuilds one code/none row and zero approved TUs. The current wb/zh/bfme1
name-evidence scan offers no candidate for those two parsers, the allocator,
the sort thunk or the run's final deque helper.

The catalogue's `Code/GameEngine/Source/Common/System/FormationAssistant.cpp`
path comes only from WorldBuilder (offset/RVA 0x01ACFF60). The parser's
FormationSelection registration and error strings establish its purpose,
not its original function name or retail TU. No name, TU map or source path
was changed. Next placement work needs an independently supported name or
another retail anchor; do not infer a boundary from adjacent functions.

Within the claimed scope, the FormationSelection parser used a linker alias
from `Rva00424185Deque::append` to the existing 0x00423BFD
`_STL::deque<BfmeE12>::push_back` provider. Replace the surrogate declaration
with the provider's call-only template declaration and cast the locally
reconstructed 12-byte argument to its existing opaque element view. This
does not claim the original element identity or introduce a container body.
`hatch_counters.py --update` removes exactly one alias entry (2920 -> 2919).

[Object comparison](formation-selection-object-20261028-codex.json) finds
the same 29 external COMDATs. All bodies and relocation targets agree after
resolving the old alias. The only changed COMDAT digest is the parser's,
whose relocation now names the provider directly. The undefined-name set
changes by precisely that substitution.

Verification:

- Before and after `./build.sh`: all five parser rows, its data row,
  four literals, two empty-string references and one float literal pass.
- EH verification: one EXACT graph; frozen-file checks pass before and
  after, class gate passes, and scoped data checking reports zero findings.
- `link_check.py --prepare-current` verifies 23/23 rows across parser and
  deque provider with strict reusable receipts.
- Ordinary paired preview preserves LINKS for both units: 384 and 1,526
  authored bytes respectively. No census-linked gain is claimed.
- `git diff --check` passes. The staged-tree batch audit exits 2,
  INCONCLUSIVE: the index predates the base and affected consumer
  `Common/0CreateAHeroManager21FE49.cpp` lacks a current receipt. Carry this
  alias removal into the next normal census; full consumer selection remains
  unverified.

Scratch evidence: `build/formation-selection-20261028/`; pre-edit planner
snapshot: `build/consolidation/formation-codex/` (invalidated by this edit).
No source-file reduction or TU approval is claimed.
