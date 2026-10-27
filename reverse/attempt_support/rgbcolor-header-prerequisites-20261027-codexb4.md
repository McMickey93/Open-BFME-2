# RGBColor header and inline-emission prerequisites

Recovered on 2026-10-27 from the saved notes, attempt log and local receipts
of the pass at `6b62f0f97e`. The saved handoff file itself was empty. No source
trial is retained or repeated during recovery.

Current-owner facts: `color.cpp` owns the 18-byte copy assignment at
0x0000353A, and `color_rgbcolor_ctor.cpp` owns the 18-byte integer constructor
at 0x00006538. The canonical `Code/Libraries/Include/Lib/RGBColor.h` lacks
these declarations. That is a header-contract prerequisite, not an unrowed
retail body or evidence for a new name.

Prior evidence, distinct from this pass: the `RGBColor-canonical-operator`
entry in `reverse/re_attempts.log` reports that adding assignment to the
canonical header changes dependent code generation in GlobalDataSetTimeOfDay
and exposes a W3DRopeDrawInitRopeParms extent discrepancy. This recovery did
not reproduce that earlier shared-header trial.

The preserved emission trial removed `bfmeEmitcolor` and outlined getAsInt
and setFromInt. `build/rgbcolor-header-20261027-codexb4/anchor-cleanup.log`
records all 14 color.cpp rows and their reference gates passing. However,
`link-anchor-cleanup.log` records a duplicate
`?setFromInt@RGBColor@@QAEXH@Z`; the saved investigation identifies the other
inline emitter as DrawableFlashAsSelected.cpp. The ordinary preview falls
from 674 to 18 authored bytes across the two units. Its baseline receipt,
`link-before.log`, reports both units LINKS against census index bf3dd31211
(2026-10-27 00:39, retail-truth-4).

The source was restored. `restored-build.log` verifies all 14 color.cpp rows;
the saved `link-restored.log` is empty and supplies no restored-link verdict.
Recovery's ordinary build verifies all 15 rows across both restored color
units, together with the five sources in the three recovered commits
(47/47 rows across seven sources). This is byte-verification evidence only.

Before adopting the canonical header, reconcile assignment and constructor
contracts across existing dependent copies and aggregate initializers, then
verify the affected consumers. Before retiring the emission anchor, preserve
compatible COMDAT selection with the existing inline setter provider. No
header, queue, pin, alias or source change is retained for this attempt; no
census or image-ownership gain is claimed. The obstacle is recorded as
LINK-115 in `docs/linking_obstacles.md`.
