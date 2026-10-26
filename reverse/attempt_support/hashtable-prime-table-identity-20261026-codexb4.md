# STLport prime-table ownership and hashtable identity

Inspected BFME 2 `6b853bd614aa61109f79cb7911b9cc3204c7f54a`.
The default picker claimed insertion 0x0016E230 and its source,
`Code/Libraries/Source/WWVegas/WWLib/stlport_hashtable_asciistring.cpp`.
The companion `RvaHashIndex00928620.cpp` source and data RVA 0x007BD410
were separately claimed. No C++, function row, pin or compiler option changes.

## Verified data owner and retired key

The existing hashtable object emits the external COMDAT
`?_M_list@?$_Stl_prime@_N@_STL@@2QBIB`: STLport 4.5.3's
`_STL::_Stl_prime<bool>::_M_list[28]`. Its entire 112-byte section agrees
with retail .rdata at RVA 0x007BD410 (VA 0x00BBD410). The array is defined
in `vendor/stlport/stl/_hashtable.c`; its bound and bool specialization are
declared in `_hashtable.h`. All 28 upstream prime values, from 53 through
4294967291, agree. Normal data-row verification independently proves the
112-byte sizeof and complete initial value. The provisional 1564-byte
extent in the generated data ledger was not used as an array bound.

The 252-byte resize copy called by insertion 0x0016E230 already has retail's
body, following source repair `1e14f4ae93`. Identity certification was
`unknown` because three DIR32 relocations, at offsets 0x33, 0x38 and 0x45,
name this array with no verified address. All three retail operands place
the same array at RVA 0x007BD410, with their emitted addends accounted for.
The other four relocations already resolve: lower_bound 0x00568D2F,
get_allocator 0x00023B50, the bucket-vector constructor 0x00026A40 and
free 0x00030830.

One matched `data_rows.csv` entry now records the existing definition.
`repair_queue.py retire identity` then removes the source's one divergent
resize-binding key and reports zero remaining findings. The register is
changed only by that owning tool. This certifies the complete kept resize
copy, including its relocations; it does not establish the application
type names used by these old reconstructed units.

## Companion finding remains

The separately claimed `RvaHashIndex00928620.cpp` keeps its one wrong-binding
key. Its 76-byte subscript row at 0x0016E2C0 calls the edge-pair insertion
copy emitted by `MeshGeometryGetEdges.cpp`. That copy has the native
118-byte shape at 0x0016E230, but its resize and pair-construction names
have no independently recorded addresses:

| Insertion offset | Native target | Missing binding |
| --- | --- | --- |
| 0x0F | 0x0016DD70 | `hashtable<pair<const pair<int,int>,int>,...>::resize` |
| 0x53 | 0x0016CC30 | `_Construct<pair<const pair<int,int>,int>,...>` |

The allocation call at offset 0x3D resolves to 0x000307F0. The owning
identity tool refuses retirement with all one keys still found. No new
pins or hand-written aliases are added. Reconcile the existing helper
owners and native edge-map type evidence before changing these bindings.
The existing 8-byte AsciiString view and DamageFX resize naming remain
separate identity work. No class or application-name recovery is claimed.

Earlier evidence
[link-hash-resize-isolation-20261022.md](link-hash-resize-isolation-20261022.md)
and its correction were read: the attempted lookup split did not land.
Do not count that trial as an additional linked body or repeat the rejected
private canonical class view.

## Verification and scope

- `check_csv.py` passes with 98,272 function rows, 15,632 pins and 2,225 data rows.
- `find_declared_unmatched.py` passes for both complete sources before edits.
- Normal `build.sh` passes both sources' four rows (299 bytes) unchanged.
  After adding the data row it again passes the hashtable's two rows and
  verifies the full prime table. Both sources have no EH rows or exemptions.
- Initial retirement calls refuse without modifying the register, first for
  stale providers and then for the findings described above. Normal builds
  refresh GameClientDrawableTOC.cpp, GameLogicDoXfer.cpp, INI.cpp,
  window_video_manager.cpp and LivingWorldLogic.cpp: 358/358 function rows,
  one existing data row, 83 string references, two float references and
  11 named imports pass. Renumbered funclets use their verified parent EH data.
- `link_check.py --fetch-index` retains the official 2026-10-26 19:02 index
  at `5ce093a71a`. The ordinary preview of both sources and
  DamageFX_hashtableResize.cpp is already LINKS for all three units,
  preserving 551/551 bytes. The census already records them as linked.

The result is one verified 112-byte data owner and one retired identity key.
There are no new matched function bytes, linked-byte gains or ownership
receipts. The companion identity prerequisite remains open.
