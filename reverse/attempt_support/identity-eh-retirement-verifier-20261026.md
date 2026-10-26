# Strict identity scanning of renumbered EH funclets

Follow-up to the separately banked false reject `9af44083eb` and LINK-061.
No game source, ledger label, pin, escape hatch or debt register is changed by
this verifier repair.

`allowed_symbols.row_code_symbol` now resolves compiler-local funclets through
the existing `build.located_funclet` proof: a byte-verified parent and its exact
EH graph must place a unique local code label at the row's retail address.
The resolver checks the complete row extent and its relocation records. It
does not choose by similar bytes or trust a still-existing old label.

Both the relocation scanner and strict retirement use this resolver. They
inspect the physical symbol's actual relocations while preserving the logical
ledger row for classification and baseline keys. Failure to prove the funclet
raises `UnverifiedFunclet`; ordinary scanning and full reseeding cannot silently
drop this failure. Missing, stale and unreadable providers remain refusals.

Regression evidence uses real COFF objects. Before the repair, ten cases fail
and three pass across the initial row-scanning and retirement tests. The initial
thirteen pass after resolution is shared. Two further tests reproduce and then
close the ordinary-scan/full-scan error-suppression path found during review.
Additional negative cases cover incomplete bodies, crossing relocations and
missing relocation symbols. Existing funclet/EH tests retain wrong-parent,
masked/unresolved-parent, duplicate-parent and ambiguous-location refusals.
The final six-file suite passes 395 tests with one skipped case, including
every case in `tools/tests/test_gate_exploits.py` and the identity, retirement,
funclet, EH and library-source suites (276.01 seconds).

One existing local Git fixture needed isolation: its deliberately skewed clock
reached the production host claim-push pacer and slept for approximately an
hour. The captured live Python stack identified `test_colliding_work_is_exclusive_whatever_the_clocks_say`
inside `_pace`. The `seats` fixture now disables pacing only for its temporary
local bare repository. Production claim coordination and pacing are unchanged.

Current-object evidence after normal provider verification:

- Audio insertion retirement examines both outgoing identity keys and finds
  zero remaining wrong bindings, with no missing/stale-provider refusal.
- The complete ten-source audio scan judges 992 rows and 1,117 references,
  reporting zero findings in the existing shadow mode.
- AddKey's two parent EH graphs are EXACT. The separately verified normal
  audio build retains all 992 function rows and 26 data rows.
- The audio path audit has no moves or deletions. Its only added path is the
  tracked `LargeGroupAudioKeyTreeStorage.h`; all six direct include consumers
  are in the verified batch. No hard-coded tooling path needs repointing.

This resolves the audio verifier obstacle only. DX8 descriptor/vector repairs,
other window-video findings and census confirmation remain independent work;
no general LINK-061 debt or linking clearance is claimed.
