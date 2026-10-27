# Water reflection release declaration

Inspected BFME 2 revision: b3ff5cb28fb. Published link index: bf3dd31211,
2026-10-27 00:39. Claimed scope: the five-row
Code/GameEngineDevice/Source/W3DDevice/GameClient/Water/W3DWaterRva0007F0FB.cpp
and the picker's 0x00042F8C claim. The existing five ledger rows remain unchanged.

## Served blocker and current evidence

The picker reports a wrong selected BFME_DX8_Thread_Lock provider. This is the
already-repaired LINK-106 cause: the unchanged water object alone fails against
the historical provider, but including current BfmeDX8ThreadLock.cpp gives two
LINKS previews, 1,930 and 247 authored bytes. The 1,955-byte picker value is its
row total, not a new census credit. This work claims no new linked-byte gain.

The water file still declares BFME_DX8_Thread_Assert as returning void. The
existing owner in dx8wrapper.cpp is bool BFME_DX8_Thread_Assert(void), rowed at
0x00120F50 with extent 90. It releases the recursive device mutex and returns
whether this was the last unlock. The existing BfmeDX8ThreadLock.cpp linker
directive maps the void spelling to that bool owner. The water parent and its
five-byte DeviceLock destructor ignore the result.

## Repair and verification

Change only that declaration's return type to bool. Both calls now name the
verified owner directly. No body, pin, alias directive, shared header, flag,
ledger row or register key is added or changed.

- Before and after normal builds pass all five rows, six float literals and
  the one named import. The frozen-file check passes.
- Object comparison checks all 19 executable sections: raw bytes, flags and
  defined symbols are identical. Exactly two REL32 referents change from
  ?BFME_DX8_Thread_Assert@@YAXXZ to ?BFME_DX8_Thread_Assert@@YA_NXZ, at parent
  offset 1900 and destructor offset 1. Both still target native 0x00120F50.
- The scoped identity scan retains 21 references and zero wrong bindings.
  Owner bindings increase from 17 to 19 and aliases decrease from three to one;
  the remaining alias is the existing C++ EH handler route.
- The parent EH graph remains EXACT, and shadow data checking has zero findings.
- A normal symbol build independently verifies the 90-byte bool provider row
  and its three named imports. The supported receipt-preparation mode also
  verifies all five water rows and produces a strict reusable receipt.
- Paired current-provider link previews remain 2/2 LINKS before and after.
  These bounded previews do not measure full-image closure or census progress.

The comparison script and raw check outputs accompany this note. No source path
changes, consolidation, header-queue transfer or protected-debt retirement is
part of this batch. The final pre-push audit still checks affected consumers.

## Reference freshness

The overdue local reference check fetched official BFME 1 master and found
ce1daafa6a59b48c3ca371de266ce299f79cbd99. The checkout retains the verified
e74410b3738a2bb75d626085d9ebfd3406a43ff7 pin: the reference-update claim is held
by another worker. The claim attempt was refused, no submodule work was changed,
and the local success stamp remains unchanged. Repeat freshness checking in a
later work session; do not treat this check as a completed reference update.
