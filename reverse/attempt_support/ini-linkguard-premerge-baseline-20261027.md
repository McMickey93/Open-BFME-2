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

## Separate verifier repair

The guard now compares the real pre-merge losses and selected implementation
with the proposed overlay. Both sides retain their own referenced-name state.
An unchanged digest is insufficient: the old object's complete SHA256 must
match the census index, and its raw COMDAT body, entry offset and ordinary
external relocations must equal the new object's. Local, weak, defined,
anonymous or aliased referents retain the refusal. Every absorbed object needs
an authenticated weak-route inventory; providers and routes inside that cohort
are excluded. Each referent must have a direct surviving provider. Unknown
/MAP holders, changed selected bodies and newly losing outside units remain
refused, including outside units that were already blocked for other reasons.

The optional raw evidence is kept outside the compiler cache at
`build/link_census/guard_objects/<index SHA256>.obj`. It comes from the published
`census-index` object bundle and is rehashed before use. Missing or changed
evidence preserves the conservative refusal; no whitelist or source workaround
is added. The old INI object SHA256 is
`f4c9a5cd6a38bb53e745bf6bd053820ed071c31dc08b3d8922e93dbb10ac30cc`.

The original failure and the newly-referenced/indirect-alias counterexamples
were first reproduced by failing tests. The final run passes **228 tests and
11 subtests, with one existing skip**, including all gate-exploit tests.
A bounded replay from the unmerged `55b80217e6` baseline against candidate
`ccd433d0fc` authenticates all eight census objects and returns no guard
problems. The candidate's object and source hashes remain those recorded
above. This is verifier reproduction, not the final post-rebase integration
receipt or a new census result.

Tooling-worktree receipts: `iteration53-guard-tests-broad.log`,
`iteration53-real-ini-guard-result.json` and `iteration51-census-object-proof.json`
under `build/codex-cleanup-20261025/`.
