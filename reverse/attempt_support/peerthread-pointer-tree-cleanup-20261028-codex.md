# PeerThread server-pointer tree cleanup

Inspected revision: `3b9f8855e0`, 2026-10-28. Scope:
`Code/GameEngine/Source/GameNetwork/GameSpy/Thread/PeerThread.cpp`.

## Target facts and existing ownership

Native `_M_insert` at 0x005E4415 (136 bytes) calls node creation at
0x005E42B1 (34 bytes). That node calls `_Construct` at 0x005E3EB9,
which calls the pair copy at 0x005E3D67, which copies the owned SBServer
handle through 0x005E3B2D. The last body increments the nonnull handle's
reference count. These are target disassembly facts, not donor naming evidence.

The pointer-valued tree forced at the end of PeerThread uses GameSpy's
`typedef struct _SBServer *SBServer`; its trivial pair copy cannot express
that native lifetime operation. Its two byte-matched rows at 0x005E4415
and 0x005E449D therefore asserted a false helper identity. The earlier
blocked attempt on 0x005E4415 already identifies this distinction.

Both complete native bodies already have owned-value SBServer rows in
`Code/Libraries/Source/WWVegas/WWLib/StlportMapSBServerSubscript.cpp`.
The node, construction and pair-copy owners are in
`Code/Libraries/Source/WWVegas/WWLib/stlport_map_int_sbserver.cpp`.
No donor source path or additional native identity is asserted here.

## Applied cleanup

Remove the unused explicit instantiation, its two duplicate pointer rows
(270 overclaimed bytes), and the pointer node pin at 0x005E42B1. Record
both removed names in `reverse/deleted_rows.csv`. The complete native
ranges remain covered by the existing owners above. No source path moves.

Before/after COFF comparison removes 23 external function definitions and
adds none. All 487 surviving external functions retain identical bytes.
Only Thread_Function's relocation name changes, from `$L58388` to
`$L57580`; the byte verifier checks the renumbered EH graph. No surviving
function references any removed definition. The indexed definition
referrers for the two removed row names are empty.

## Verification and limits

- `./build.sh PeerThread.cpp`: 174/174 remaining function rows exact;
  117 string literals, 26 empty-string references, 26 named imports and
  two data rows verify. Source claims and funclet checks pass.
- `./build.sh StlportMapSBServerSubscript.cpp stlport_map_int_sbserver.cpp`:
  26/26 existing provider rows exact.
- `find_declared_unmatched.py`: all defined functions already matched.
  `check_csv.py` and `pin_consistency.py --check` pass.
- `allowed_symbols.py`: references 839 -> 834; wrong references 5 -> 3;
  the two wrong/unknown pointer-node references disappear. Seven rows
  still have findings: 14 divergent/extent references, two wrong/bytes
  and one wrong/static-extent. This does not clear the whole unit.
- Ordinary three-unit `link_check.py` preview against the fetched
  2026-10-27 14:34 index at `73061d9452`: all three remain LINKS.
  PeerThread's authored total falls 18,892 -> 18,622 because the two
  duplicate claims are removed; the existing providers remain 723 and
  561 bytes. This is not a census gain or a current strict closure proof.

Raw local evidence is under `build/peerthread-cleanup/`, including the
before object, native disassembly, row/referrer snapshots, builds and
the full-path after-preview. An initial after-preview using basenames
failed path resolution; the full-path invocation completed successfully.

## Identity retirement prerequisite

`repair_queue.py retire identity` refuses: two row names held by HEAD
are gone from PeerThread ("lost coverage hides findings"). The existing
owned-value rows preserve those ranges, but this verdict does not account
for that duplicate cleanup. Neither registered PeerThread key is edited
by hand. The older 492-byte deque key also remains registered; its native
1432-byte correction already lives in StlportOwnedRecordDeque.cpp (see
the 2026-10-24 PeerThread deque handoff), and is not reimplemented here.

Next: reconcile the remaining callback/listGroupRooms and divergent
bindings using native evidence, then obtain a clean supported retirement
verdict. A tooling seat may review the duplicate-row coverage refusal
separately; do not weaken the check in this cleanup commit. LINK-002
remains open and whole-unit census confirmation remains pending.
