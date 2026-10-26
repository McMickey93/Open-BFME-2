# INI merge: false new-variant refusal against the pre-merge census

The final PR115 INI object at `c2c47842de` passes all 53 function rows and
seven EXACT EH graphs. A LinkGuard prepared before any donor deletion at
`9e7231642d` nevertheless refuses it against census index `5ce093a71a`:

`breaks another unit's copy of ??R?$equal_to@VAsciiString@@@rts@@QBE_NABVAsciiString@@0@Z`

This is a false report of new damage; the differing copies are existing debt.
The guard's eight-file cohort contains INI.cpp and its seven absorbed donors.
Its first census position is INISeparatorGetters.cpp at 566; INI.cpp was 575.
The surviving ThingFactory copy remains at 4304.

| Copy | Before and after digest prefix | Size | Resolved call |
|---|---|---:|---|
| INI, position 575 -> 566 | `a77ddcc09da5` | 21 B | compareNoCase, RVA `0x00006A00` |
| ThingFactory, position 4304 | `53980c600d47` | 21 B | free operator==, RVA `0x0002C7C1` |

The digest includes relocations. The final INI object SHA256 is
`9638e06786759782ffb97e01ce97403f5a32fc56045d85cb3c593f0449a4e26b`;
its rts declaration block is unchanged from the pre-merge source. The original
census already lists this name among ThingFactory's COMDAT losers. Applying
the census keep rule to the real before and after orders selects INI in both
cases and leaves ThingFactory losing in both cases.

LinkGuard removes all cohort copies to form its trial view. Because INI moves
earlier, its existing digest receives no same-position exemption. The generic
new-variant check then treats the remaining ThingFactory copy alone as the
baseline, incorrectly turning its old loss into a new one.

Repair the verifier separately: compare the actual pre-merge copies and link
order with the overlay. Do not exempt every moved old digest. A moved copy
that crosses a previous winner, a changed body, or a newly wrong selected
provider must still be refused. Keep all object-level link checks.

No INI source change is justified by this refusal. Its case-insensitive
comparison and ThingFactory's equality are distinct existing implementations.
The free equality owner at `0x0002C7C1` is 19 B, not the 21 B functor; the
refuted `0x006E054B` identity must not be restored. This evidence does not
establish image-wide or runtime clearance. Rebase and a fresh pre-merge guard
are still required before publication of the INI merge.

Local receipts in the INI worktree: `iteration48-ini-guard-ready.json`,
`iteration48-ini-guard-result.json`, `iteration50-ini-dc8c028a5c-build.log` and
`iteration50-ini-dc8c028a5c-commit.log`, under `build/codex-cleanup-20261025/`.
