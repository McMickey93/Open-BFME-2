# Miles request-set finder: remaining owner reconciliation

Inspected revision `3641be0d80`; ordinary-preview index `bf3dd31211`,
2026-10-27 00:39. The default picker claimed RVA 0x00054EBE and
`Code/Libraries/Source/WWVegas/WWLib/StlSweepW4Rva00054EBE.cpp`.

The unchanged source passes its frozen-file check and both byte rows
(0x00054EBE, 27 bytes; 0x00055811, 20 bytes). Its ordinary preview remains
blocked by the int-keyed `_M_find` copy, which is selected but not retail's.
The native callee 0x00053FD2 is already rowed in HashRefIdFind53FD2.cpp;
LINK-002's opaque STL subset records this prerequisite. No source trial was
made and no incorrect generic helper was suppressed or forwarded.

Current evidence goes beyond the original handoff: MilesAudioManager.cpp
defines the request-set view using `Rva00051107AudioRequest *`,
`Rva00051B89Hash`, `_Identity` and `Rva00050E1CEqualTo`. Its matched handle
lookup at 0x00055951 builds a temporary request, sets its handle at +8 and
calls the table's find at 0x00054EBE. Existing pins at 0x00053FD2 and
0x00054EBE spell those pointer-keyed table operations, with fold proof citing
MilesAudioManager.cpp. This is existing structural identity evidence, not a
newly proven original class name or new pin admission.

The served unit still explicitly instantiates an unrelated
`hash_map<int, Rva00054EBEElement>` operation for both rows. Its old `_M_find`
pin at 0x00053FD2 remains alongside the newer request-set spelling. The owner
row, both wrapper rows and their consumers must be reconciled with the native
pointer-key/hash/equality contract. The outer 0x00055811 row must also be
checked for hash_set identity. A mangled signature change exceeds
rename.py's identifier-only rename; it needs a reviewed owner reconciliation
and normal byte/link admission, not a second alias or a copied ABI union.

No source, row, pin or debt register was changed. There is no new matched,
linked or ownership gain. This handoff updates the prerequisite from
rediscovering the key behavior to consuming the existing newer Miles evidence.
