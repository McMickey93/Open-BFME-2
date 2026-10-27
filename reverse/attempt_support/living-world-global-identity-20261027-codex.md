# LivingWorld callback global binding: hatch-counter false reject

Inspected revision: `03477c823da7`. The default picker claimed
`Common/Rva004EE5D2Erase.cpp`; the adjacent callback consumer
`Common/Rva004E0ADBFamily.cpp` was separately file-claimed before editing.
Both frozen-source checks report all definitions already matched before and
after the change.

## Existing owner and scope

The matched data row at RVA `0x00A04424` names
`?g_Va00E04424@@3IA`, defined as `unsigned` in
`Code/GameEngine/Source/Common/Rva007ABBB3CtorInits.cpp`. Its existing initializer
at `0x007B301A` uses that same symbol. The erase consumer instead defined an
empty-class global named `?g_00E04424@@3VRva002B7250@@A`, while the callback
consumer referenced that second name. All three absolute operands reach the
same retail address.

The verified trial made both consumers declare the ledger owner's exact type and symbol and cast
its address to their existing local views at each call. The trial removed the duplicate
empty-class definition. It changed no owner definition, storage extent,
function row, pin or compiler option. This follows the project's
one-global-per-address rule; it does not recover the callback type's original
name or settle its full storage layout. Earlier blocked verdicts for this
address raised the scalar-versus-four-word layout issue. That remains a
separate prerequisite for recovering the owner type and extent; this cleanup
claims only consistent binding to the existing ledger owner.

## Trial verification and attempted debt retirement

- Normal `./build.sh` passes all 14 function rows across the two consumers
  and their one owned data row. The unchanged initializer separately passes
  all 30 function rows and ten data rows.
- `tools/eh_verify.py` reports two EXACT graphs, zero nonexact, zero baselined
  and zero missing objects for the consumers.
- `tools/data_check.py` reports zero findings in both sources; enforced
  `--converged` reports zero second names and zero unjudged rows.
- `repair_queue.py retire data` removed two keys per source during the trial, leaving zero
  in each. Three keys concern the duplicate global. The fourth is the stale
  `TheLivingWorldLogic` binding key: that source already used the real symbol.
  Only the owning retirement tool removed these register entries during the trial;
  the register was restored with the rejected source change.
- The before/after object comparison checks every external COMDAT definition:
  two in the erase consumer and eighteen in the callback consumer. Bytes,
  sizes and relocation offsets/types/referents are identical after normalizing
  the one intended global-name substitution. The old erase object defines the
  second name; its new object references the ledger owner without defining it.
- Paired ordinary `link_check.py` previews for both consumers plus the
  initializer report 3/3 LINKS before and after: 215, 704 and 659 authored
  bytes, respectively (1,578 total), against index `bf3dd31211`, dated
  2026-10-27 00:39. These were already census-linked; no new census-linked
  bytes, strict closure, image ownership or runtime result is claimed.
- `tools/check_csv.py` passes; `git diff --check` is clean. No source path
  changes require a tooling compatibility audit.

Scratch before-objects are in
`build/living-world-global-identity-20261027-codex/`.

## Refused commit and handoff

The normal pre-commit hook refused the verified source change before creating
any commit:

```text
address_global +3 in Rva004E0ADBFamily.cpp: g_Va00E04424 (register grants 0)
address_global +2 in Rva004EE5D2Erase.cpp: g_Va00E04424 (register grants 0)
```

These occurrences are declarations and references to the existing data-ledger
owner, rather than definitions of a new symbol. The old address-derived name
is not charged in the same way. The hook recommends using the ledger name,
which is precisely the attempted change. No hatch admission or counter update
was attempted. Per the false-reject rule, both source edits and all four
register removals were restored, and both affected function leads were logged
as blocked with `tools/re_log.py`.

No debt is retired by this handoff. A tooling seat should reproduce the
inconsistent accounting of the old spelling versus the exact ledger owner and
fix the gate in its own tested verifier commit before retrying the consumer
cleanup. The scalar-versus-four-word owner-layout prerequisite remains separate.
The rejected patch is scratch-only at the path above (`trial.patch`).
