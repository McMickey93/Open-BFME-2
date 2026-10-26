# W3DAptDisplayString TU proposal needs an anchor

Inspected BFME 2 `78413ee546` on 2026-10-26. Default `next_work.py --claim`
served `Code/GameEngineDevice/Source/W3DDevice/GameClient/GUI/W3DAptDisplayString.cpp`
as a 41-row / 23-source unanchored proposal. Claimed and released that file scope;
no game source, ledger ownership, TU map or naming basis changed.

Fresh `name_lane.py consolidate --under Code/GameEngineDevice/Source/W3DDevice/GameClient/GUI/`
reports the committed TU map stale. `tu_skeleton.py --plan` rebuilds in memory and
reports **0 approved rows, 0 donors** for that destination. The path is absent in
the checkout. `find_declared_unmatched.py` reports no definitions there.

Target facts: the existing constructor row at 0x000AA966 is already owned by
W3DAptDisplayStringCtor.cpp; SetText at 0x000AA7B2 is already in W3DAptAux.cpp.
Their prior recovery and failed class-view normalization are in re_attempts.log.
This is existing-placeholder/routing cleanup, not missing coverage.

Reference facts: the planner associates the constructor with W3DAptAux.cpp from
its WorldBuilder pairing, explicitly a hint without target-TU verification.
Its path catalogue records WorldBuilder image offset 0x019E7948 and BFME 1 EA
file evidence starting at ea_evidence.csv:22401 for W3DAptAux.cpp. Neither proves
the retail BFME 2 source path. No W3DAptDisplayString.cpp original-path anchor
was found in the scoped planner packet.

Next: establish a retail-supported path anchor for the Apt display-string
family before any merge or ownership move; inspect W3DAptAux's own routing and
private-view prerequisites separately. Do not promote the class-derived file
stem or the WorldBuilder path hint to approval. Do not regenerate/commit tu_map.
No merge, byte gain, debt retirement or new canonical name is claimed.

Freshness: official BFME 1 master fetched successfully at
001ccd8e27686e9887235b62ff797627f2dde7f5; pinned clean checkout remains
verified de077dd5dd8339716a6abe453a1d81dfdf77e651. The routine update still
needs old/new full verification and donor refresh; no success receipt written.
