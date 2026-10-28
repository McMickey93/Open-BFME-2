# Icon diamond: current prerequisite check

Inspected BFME 2 revision `2b9f5c4d64`, 2026-10-28 UTC. The default picker
claimed `Common/Rva005F422CDtor.cpp` through row 0x005E3A6E. No source or
ledger identity was changed; the claim was released after diagnosis.

The normal current-object link preview against published index `73061d9452`
(2026-10-27 14:34) retains zero linked bytes for this unit, whose current
authored nonpadding scope is 473 bytes. It reports these nine unresolved
references:

- `Rva005F422C::CreateMovieClip(AptMovieClipFrame *)`, returning
  `TreeHintRef00217D4C`;
- `Rva005F4179::DoUpdate()` and `Rva005F422C::DoUpdate()`;
- `Rva005F4179::rva005F4710()` and `Rva005F422C::rva005F4710()`, both returning
  `TreeHintRef00217D4C`;
- `Rva005E3A76::slot01()`, `slot05()`, `slot06()` and `slot07()`.

Command: `python3 tools/link_check.py
Code/GameEngine/Source/Common/Rva005F422CDtor.cpp` (exit 1). Its dependency
check found the object's inputs current. The frozen-file check also passes:
19 matched rows and two existing absent-from-retail emission constructors.

This confirms LINK-086's existing class/table prerequisite; it does not
establish any missing retail body. The existing hero factory provider in
`StrategicInGameUIArmyHeroIcon.cpp` uses `StrategicInGameUI::ArmyHeroIcon`
and returns `HeroClipReference`, whereas this lifetime unit uses
`Rva005F422C` and `TreeHintRef00217D4C`. Merely changing the member label
would not reconcile the class or result ABI. The prior handoff identifies
the details slots' existing owners as well. No unchanged alias or table
suppression trial was repeated.

Next work must reconcile the eight-slot class contracts, lifetime owners,
hidden-result signatures and emitted vtordisp thunks across the providers
and constructor consumers together. No new fold, pin, C++ conversion,
linked-byte gain or census clearance is claimed.
