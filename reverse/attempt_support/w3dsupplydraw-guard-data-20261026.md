# Supply-draw local guard and data-debt handoff

Inspected 2026-10-26 at `1ced7676f8`, seat codexb. This is a data-identity
investigation of the already matched W3DSupplyDraw unit, not a missing-body
or new linking claim. No game source, data ledger or debt register changed.

## Current target evidence

`./build.sh Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DSupplyDraw.cpp`
passes all five rows (216 bytes), including the pool-key getter at 000CAE7B
and its EH handler at 0076238F. The declared-unmatched check passes.
`eh_verify.py` reports the getter's complete graph EXACT. Calling its
`verified_funclet_locations` helper on the current normal-build object maps
compiler label `$L1399` to **00762382**, the address already rowed as
`Rva00762382ClearFlag` in Common/GlobalFlagClearers_DEAFxx.cpp. The label
number is object-specific; recompute it after any source or compiler change.

The current object defines both of these as COFF storage class 3 (local):

- `?TheW3DSupplyDrawPoolKey@?1??getModuleNameKey@W3DSupplyDraw@@UBE?AW4NameKeyType@@XZ@4W43@A`
- `?$S1@?1??getModuleNameKey@W3DSupplyDraw@@UBE?AW4NameKeyType@@XZ@4IA`

The getter's prior rename is recorded in re_attempts.log; its consolidation
landed in 28f84379ee. The data ledger still spells the old static method for
009EBB84. At 009EBB88 it selects `g_Va00DEBB88`, defined and accessed by
the separate clear-flag source, alongside the old local guard name.
The independently exact parent EH graph establishes the cleanup relationship;
adjacency alone is not the evidence.

## Retirement result and remaining work

The supported `repair_queue.py retire data` call refuses and changes nothing:
both current local names are new wrong-name findings at 009EBB84/009EBB88.
The retained baseline key names the older address-derived getter. Deleting
that key by hand would not repair the duplicate guard storage.

The needed Common/GlobalFlagClearers_DEAFxx.cpp file claim was refused because
another worker holds it. No trial was applied to that file or the supply unit.
Do not add an external declaration for either local compiler symbol: it has
storage class 3 and cannot supply an external provider.

When both scopes are available, check fresh TU approval and the current EH
mapping, then reconcile the existing 00762382 row with its parent's emitted
cleanup through the supported row-move/funclet workflow. Remove the obsolete
separate guard definition and its hatch only with full verification of the
other clearer rows. Refresh the data index through `tools/data_ledger.py`
(tool-written; no hand edits), inspect its changes, and retry the owning
data-retirement tool. Preserve parent bytes, EH graph and one body per address.
No blanket merge or split of the mixed clearer source is approved here.

The exact graph, row owner and storage classes above are target facts. The
proposed repair order is a structural inference awaiting implementation and
verification. No donor identity, data placement, census gain or debt retirement
is claimed.
