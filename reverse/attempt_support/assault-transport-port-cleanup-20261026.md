# Assault transport: retire obsolete port definitions

Inspected parent: `8738ddb103` (2026-10-26). Claimed source:
`Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/AssaultTransportAIUpdate.cpp`.
Published preview index: `5ce093a71a`, 2026-10-26 19:02, retail-truth-4.

## Target evidence and change

The current source owns exactly two matched bodies: `beginAssault` at
`0x0048F45C` (17 bytes) and `Rva0048F472IsEqual` at `0x0048F472` (58 bytes).
Both remain in their existing approved unit with unchanged C++ bodies and rows.
The starting object was current according to the ordinary dependency cache.
Its link preview failed on `AICommandInterface::aiEnter` and
`AICommandInterface::aiAttackMoveToPosition` COMDATs emitted by unrowed port
methods. This reproduces the remaining obstacle in the
[2026-10-18 handoff](assault-transport-owner-link-20261018/readme.md).

Remove the ten `present-unmatched` Zero Hour definitions, the unrelated free
`calcSleepTime`, the unused vector-construction anchor, its two optimization
pragmas, and the unused local list comparison. Retain the existing class
declarations, the two rowed bodies, and the TU planner's unmerged-owner pointers.
No function, pin, data identity or source path is added or moved.

Existing target owners include:

| Operation | Existing retail row and owner |
| --- | --- |
| Reset helper | `0x0048F365`, `AssaultTransportAIUpdateHelper.cpp` |
| Destructor | `0x0048F3E0`, `Rva0026E836Derived.cpp` |
| Idle forwarder | `0x0048F46D`, `VslotSmallBodiesAJ.cpp` |
| Health comparison | `0x0048F472`, the retained body in this source |
| Transfer | `0x0048F4AC`, `AssaultTransportAIUpdateXfer.cpp` |
| Readiness | `0x0048F61A`, `AssaultTransportAIUpdateCheck.cpp` |
| Wounded comparison | `0x0048F64E`, `Rva0048F64EFinish.cpp` |
| Passenger retrieval | `0x0048F690`, `AssaultTransportAIUpdatePassengerHelper.cpp` |
| Final orders | `0x0048F6EE`, `AssaultTransportAIUpdateCommandHelper.cpp` |
| Request dispatch | `0x0048F7A7`, `AssaultTransportAIUpdateDispatch.cpp` |
| Update | `0x0048F828`, `AssaultTransportAIUpdateUpdate.cpp` |

The update owner's existing target-layout evidence identifies its passenger and
health callees independently of the port's spelling. The destructor and command
owners still use provisional identities; deleting the obsolete definitions does
not establish new names or recover their interfaces. CRC/load forwarding port
definitions have no matched row under those spellings and are not promoted to
new matches.

## Donor lead

Reviewed the pinned BFME 1 source at `001ccd8e27686e9887235b62ff797627f2dde7f5`:
`game/GameEngine/Source/GameLogic/Object/Update/AIUpdate/AssaultTransportAIUpdate.cpp`.
It separates several matched methods into dedicated owners but retains other
unmatched port definitions. Its byte addresses and layouts are donor facts,
not BFME 2 proof. No donor body or donor address was copied into this repair.

## Verification

`./build.sh` passes both complete bodies (2/2, 75 bytes), including string,
floating-point and import-reference checks. The frozen-file check now reports
all definitions matched, without the previous ten exemptions.
The final `link_check.py --prepare-current` run accepts one strict reusable
provider receipt and repeats the same 2/2 byte gate without changing the census,
index or status. Its log is `build/assault-link-20261026/prepare-current-final.log`.

The ordinary preview uses the ten current objects below. A paired in-memory
check uses the saved starting object at the same index position for the before
case and the repaired object for the after case, refreshing all ten objects in
each case with the existing `link_check.refresh` and `check_object` routines.

| Unit | Before | After |
| --- | --- | --- |
| `AssaultTransportAIUpdate.cpp` | 2 COMDAT blockers; 0 bytes | LINKS; 75 bytes |
| `AssaultTransportAIUpdateUpdate.cpp` | LINKS; 929 bytes | LINKS; 929 bytes |
| `AssaultTransportAIUpdateHelper.cpp` | LINKS; 123 bytes | LINKS; 123 bytes |
| `AssaultTransportAIUpdateCheck.cpp` | LINKS; 52 bytes | LINKS; 52 bytes |
| `AssaultTransportAIUpdatePassengerHelper.cpp` | LINKS; 93 bytes | LINKS; 93 bytes |
| `AssaultTransportAIUpdateCommandHelper.cpp` | LINKS; 185 bytes | LINKS; 185 bytes |
| `AssaultTransportAIUpdateXfer.cpp` | LINKS; 247 bytes | LINKS; 247 bytes |
| `AssaultTransportAIUpdateCtor.cpp` | LINKS; 87 bytes | LINKS; 87 bytes |
| `AssaultTransportAIUpdateFriendNew.cpp` | LINKS; 59 bytes | LINKS; 59 bytes |
| `Rva0026E836Derived.cpp` | U3, addresses 2 | Same U3, addresses 2 |

The ordinary preview totals 1,775 -> 1,850 authored bytes, 8 -> 9 clean units
out of ten. The destructor provider's existing `f2`, `f3`, `f4` unresolved
interfaces and two hard-coded image addresses remain prerequisites for broader
closure. The cohort command exits 1 because that provider remains blocked.

An object-symbol audit finds 106 removed external definitions; 78 have other
indexed providers. None of the 28 without another indexed provider has an
incoming index edge from a definition outside the starting object. This is a
bounded historical-index check, not a claim that every current consumer or the
whole image was remeasured.

`hatch_counters.py --update` retires only this source's ten unmatched exemptions
and two optimization occurrences; unrelated tree-wide reductions were undone.
There are no source-owned data, identity, gate-baseline or header-queue keys to
retire. No source paths change, so no path-consumer migration is needed.

Raw scratch receipts: `build/assault-link-20261026/after-preview.log`,
`paired-preview.json`, `removed-provider-audit.json` and the saved `before.obj`.
The next normal maintainer census must confirm the 75-byte preview clearance.
No census, smoke run, image-ownership receipt or headline gain is claimed.
