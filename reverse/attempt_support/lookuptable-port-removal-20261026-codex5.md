# Lookup-table port removal

Inspected BFME 2 `78413ee546` on 2026-10-26. Claimed retail 0x00141120
and `file:Code/Libraries/Source/WWVegas/WWMath/lookuptable.cpp`.

The current ledger has one row in that source: the 24-byte
`RefMultiListClass<LookupTableClass>::Peek_Head` at 0x00141120. The older
blocked attempt in re_attempts.log (GenericMultiListClass constructor at
0x00065815) described three rows / 80 bytes before the generic list bodies
moved to multilist.cpp. This repair preserves current ownership and does not
restore a missing row or approve a TU move.

The source contained an unverified Zero Hour lookup-table manager port,
including table storage, loading, persistence and lifetime functions. Neither
LookupTableClass nor LookupTableMgrClass has another named function/data row
requiring those definitions in the current ledgers. Current Code consumers
contain no calls to them. The independently matched WWMathInit.cpp explicitly
omits the manager's initialization/shutdown calls. These are target coverage
and consumer facts; the same donor port in the pinned BFME 1 reference does
not prove its presence in BFME 2.

Replace that port with an explicit instantiation of the existing header's
Peek_Head member. Preserve the compiler flags, original license comments and
real class declarations; add no layout, alias, pin or alternate provider.
The object now defines only Peek_Head and GenericMultiListClass's inline
Internal_Get_List_Head, with no undefined symbols. Remove nine
present-unmatched occurrences and six pragma-optimize occurrences through
`hatch_counters.py --update` (12 baseline keys, 15 occurrences).

Verification:

- `find_declared_unmatched.py` passes before and after; the prior nine
  definitions were already marked, rather than newly recovered bodies.
- `./build.sh .../WWMath/lookuptable.cpp`: 1/1 exact, 24 bytes.
- `link_check.py --prepare-current .../WWMath/lookuptable.cpp`: strict
  reusable receipt passes. `link_check.py` predicts LINKS, 0 -> 24 bytes;
  the former two unresolved and two wrong-COMDAT blockers disappear.
- `./build.sh .../WWMath/WWMathInit.cpp`: 3/3 exact. Paired link preview
  preserves its 388 bytes and predicts both units link (388 -> 412 bytes).
- No gate, identity, data or canonical-header register key is attached to
  the edited source. The historical ms-header queue's stricmp source use
  disappears with the port; no header or reference input changes.

Provider/consumer audit:

The downloaded index is dated 2026-10-26 13:18 at `d1f046749a`, older than
the inspected checkout. Thirty removed definitions have no other indexed
provider. A COFF undefined-symbol scan covers all thirty names in the 23,766
other build/match objects: no references found. Of these objects, 8,967 are
byte-identical to the index's recorded digests. The wider historical object
store scan finds references only in versions of lookuptable.cpp itself:
sidecar source hashes match its commits `2cc0164764`, `807ae26368`,
`1221a70069` and `46edfef528`. There is no unidentified historical consumer.
These cached inputs are bounded evidence, not a fresh whole-game closure.

A bounded replacement of this object in the index examines all 64 former
definitions: thirty disappear, and SimpleVecClass<float>::Length changes
selected provider to StreakVectorConstructorsBFME2.cpp. Its four-byte body
and relocation digest `dbc10ce76e7d` equal the removed copy. Rebuilding that
provider passes 5/5 exact and emits the same digest. No changed selection
chooses a wrong provider; the matched Peek_Head provider remains this object.

The outgoing batch audit is provisional: its older index also retires 183
objects removed from the current ledger by intervening changes and reports
disappeared providers. The lookup-table subset is the intentional unrowed
port removal checked above. Its other since-index findings require the next
normal census; this repair does not clear unrelated provider changes.
No census, nightly run, smoke run, LINKED headline gain or image-ownership
receipt is claimed. Confirm this 24-byte unit and the removed-provider scope
in the next scheduled census.

Reference freshness remains due: official BFME 1 master was fetched at
`001ccd8e27686e9887235b62ff797627f2dde7f5`; the clean verified pin remains
`de077dd5dd8339716a6abe453a1d81dfdf77e651`. No update success stamp is written.
