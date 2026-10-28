# TransportContain payload parser consolidation, 2026-10-28

Inspected revision: `f8b430a969`. Destination:
`Code/GameEngine/Source/GameLogic/Object/Contain/TransportContain.cpp`.
The default picker claimed the destination and its thirteen remaining donors.

## Declaration prerequisite

The supported merge dry run rejects `Rva00467DE6PayloadParse.cpp` because its
private `_STL::list` declaration conflicts with the destination's STLport
headers (C2953/C2955). The parser now includes `<list>` and shares the
destination's declaration of the separately rowed node allocator. No new pin
or alias is introduced. VS2003 rejects an `extern template` suppression when
composed with the destination's explicit instantiation (C2929), so that trial
was discarded. Including the header alone preserves the callback bytes but
emits a non-retail allocator and an unresolved allocation import; that trial
was also discarded. The allocator declaration prevents those emissions.

This is declaration reconciliation, not recovery of the list's native element
identity. The existing address-derived names and pointer-list cast remain.
The callback's name/count interpretation and +0xA4 access are existing target
evidence; the Zero Hour comparison in its comment is a structural lead, not
proof of a BFME 2 name or source path.

Before the change, `./build.sh` verifies all 31 rows across the destination,
the payload parser and the upgrade parser. After the change, the payload
parser's two rows still match and its EH graph is EXACT. Comparing its saved
before object with the rebuilt object through `link_census.comdat_bodies`
shows all five original external COMDAT bodies and relocations unchanged.
The five newly emitted list/iterator COMDATs, including `push_back`, are each
identical to the destination's existing copies (body and relocation digest).
The allocator remains external and the two-unit link preview stays clean.
`find_declared_unmatched.py` reports all defined functions matched.

The ordinary link preview against measured index `14dc3d2467` (2026-10-28
02:44) reports LINKS for both original units: payload parser 133 -> 133 B,
destination 2,455 -> 2,534 B. The latter comparison reflects the index's
historical byte total, not a new census gain. The earlier getter duplicate
in LINK-031 does not reproduce in this scope. The destination's unreferenced
`Object::clearCondition` shadow diagnostic remains pre-existing.

The parser owns no code-identity, data, header-adoption, MS-header, hatch or
flag-override register entry. The destination's existing debt remains owned
by the destination. No debt retirement or census increase is claimed.

Local receipts: `build/transportcontain-before-build.txt`,
`build/transportcontain-payload-real-list-build.txt`,
`build/transportcontain-real-list-link.txt`, the rejected suppression trial
`build/transportcontain-payload-dry-run.txt`, and saved before objects in
`build/transportcontain-before/`. These scratch files are not progress.
