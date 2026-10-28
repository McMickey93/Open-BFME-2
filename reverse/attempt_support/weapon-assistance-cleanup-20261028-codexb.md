# Weapon donor assistance cleanup

Inspected base: `4b6b2ff79f`; date: 2026-10-28; preview index: `41c28839bf`.

The default picker served Weapon.cpp's linking debt. Its current preview has
18 unresolved names and the conflicting/selected DamageInfo constructor.
Those require the shared class/provider work recorded in LINK-004; this
cleanup does not clear them.

Weapon.cpp still contained Zero Hour's unused static void-returning assistance
callback and its AssistanceRequestData constructor, after the caller moved
to WeaponRva002C9DF5.cpp. No remaining expression in Weapon.cpp used either.
The retail caller at 0x002C9DF5 and int-returning callback at 0x002C9D47 are
already rowed together there, including the callback's EH handler and guard
rollback. Remove the obsolete donor block. Also remove stale unmatched
markers for the already-removed WeaponTemplate and WeaponStore constructors.

This does not assign the AssistanceRequestData name to the provisional
0x002C95CC initializer in R3ScalarFieldConstructors3.cpp. Its ledger explicitly
records the BFME 1 name as a lead only; that body and its ownership stay intact.
The other declaration-only donor view in Weapon_Weapon_getAttackRange.cpp
is outside this edit.

Verification:

- Before and after normal builds: all 12 function rows across Weapon.cpp and
  WeaponRva002C9DF5.cpp, plus the data row, verify. The literal check passes.
- The frozen-file check passes after removal (30 remaining unclaimed
  definitions, previously 33).
- Comparing saved pre-edit objects with link_census.comdat_bodies preserves
  all 1,012 retained Weapon.cpp COMDAT byte-and-relocation digests and all
  five native assistance COMDAT digests. The sole removed external definition
  is the unused `??0AssistanceRequestData@@QAE@XZ`; no definitions are added.
  Undefined symbols, weak bindings, reference roots and retained reference
  edges are unchanged. Blank lines at the removed stale markers preserve
  source-line constants in three unrowed donor bodies.
- The native callback's EH graph remains EXACT.
- data_check reports zero findings; strict preparation provides reusable
  current receipts for both inspected units.
- The paired ordinary preview retains LINKS for the assistance unit's 267
  authored bytes; Weapon.cpp retains its 18 unresolved names and DamageInfo
  constructor blocker. No new linking gain is claimed.
- hatch_counters.py --update retires three present_unmatched occurrences.
  No source path, shared header, pin, code/data row or TU assignment changes.
- The staged outgoing batch audit is INCONCLUSIVE: the index predates the
  base and affected consumer Common/0CreateAHeroManager21FE49.cpp lacks a
  current receipt. Carry the removed-definition scope and affected consumers
  into the next normal census; full consumer selection remains unverified.

Remaining work: reconcile the DamageInfo family and WeaponTemplate/Object/
Drawable/INI/iterator signatures and providers. This bounded cleanup removes
unused donor code and hatch debt only; it does not complete Weapon.cpp's
link repair or claim census/image-ownership progress.
