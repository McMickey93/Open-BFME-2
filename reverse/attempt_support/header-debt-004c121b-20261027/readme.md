# Vanished GameLogic header-debt key at 0x004C121B

The default picker selected `GameLogic` in
`Code/GameEngine/Source/Common/BfmeConv892_Rva004C121B.cpp` at BFME 2 revision
`7ed44e8ffd66316c8a48b08e87168d8b450e54d3`. The file no longer exists.

Commit `67f241b840b2d619d50bc7714b2dec6992f233d7` deleted the donor port and
its sole row, `?bfmeGoFCB@BfmeThingFCB@@QAEXPAX@Z`, because it duplicated the
existing 33-byte owner at 0x004C121B. The same commit records that removed
name/address in `reverse/deleted_rows.csv`. This was an over-claim cleanup,
not a lost-body regression or a new reconstruction opportunity.

The surviving row is `?rva004C121B@SymbioticStructuresBody@@UAEXPAX@Z` in
`Code/GameEngine/Source/GameLogic/Object/Body/SymbioticStructuresBodySlots.cpp`.
It owns 18 matched rows totaling 1,306 ledger bytes. It already includes
`GameLogicObjectLookupView.h`, stores the host ID as `ObjectID`, and calls the
canonical `GameLogic::findObjectByID`. Its frozen-file check reports all defined
functions already matched. No game source, function row, pin, class identity or
TU assignment is changed here.

The deleted port left one `GameLogic` key in `reverse/header_queue.tsv`. The
ordinary header accept command requires a surviving source and cannot adopt this
one. Retire exactly that stale key through AGENTS.md's vanished-source exception,
with a per-key `Debt-Retired:` trailer identifying the earlier deletion and
surviving owner. A transfer would incorrectly assign the deleted port's failure
to an owner that already uses the canonical header. The retirement checker also
cannot infer an earlier tombstone from rows in this commit's parent, where the
port is already absent.

The prior deletion's byte verification and LINKS preview are recorded in
LINK-060 and its original `re_attempts.log` entry. This follow-up retires one
header-debt key and claims no new matched bytes, census-linked gain or image
ownership reduction.
