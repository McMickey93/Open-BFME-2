# FESL secondary-vtable anchor ownership

Inspected BFME 2 revision: `eb4237832a`, 2026-10-27.
Scope: `GameNetwork/FeslBrowserFactory_ctor.cpp` and
`GameNetwork/Rva00803890FeslDtor.cpp` under `Code/GameEngine/Source/`.

The data ledger assigns RVA `0x008E3F08` to
`_Rva00803890SecondaryFinalVTableAnchor` in the constructor unit. The
destructor instead defined and referenced its own static
`_Rva00803890Vt2Anchor`. This produced the source's two registered findings:
`duplicate-def` and `wrong-name`.

Earlier attempts recorded that the owner was file-local. Claiming both files
allows the existing owner to acquire external C linkage, preserving its exact
object-symbol spelling. The destructor now declares and references that owner,
and its private definition is removed. No data-ledger name, row or source path
changes. This joins the existing placeholder storage; it does not reconstruct
the table or prove the original class/global names.

Verification:

- Both matched functions pass `./build.sh`: constructor 104 bytes at
  `0x0066F860`, destructor 96 bytes at `0x0066F8D0`. Both declaration checks pass;
  the destructor's pre-existing exempted base destructor remains unchanged.
- Comparing saved control and final objects finds identical raw bytes in all
  eight executable sections (121 and 163 bytes, including unrowed emissions).
  The constructor defines the canonical symbol with external storage; the
  destructor has exactly one undefined external of that spelling and no
  `Vt2Anchor` symbol.
- Shadow data checking reports zero findings across both sources.
  `repair_queue.py retire data` removes both destructor keys, with zero still
  found. The owner has no other registered data keys.
- Paired ordinary `link_check.py` calls include both sources. Both preview LINKS
  before and after, preserving 200 authored bytes against published index
  `bf3dd31211` (2026-10-27 00:39, retail-truth-4).

Scratch logs: `build/fesl-secondary-data-20261027/` (`before-link.log`,
`after-link.log`, `object-proof.log` and saved control objects).

The two retired data-identity keys and removed duplicate storage are the scope
of this repair. The four-byte zero-filled owner still stands in for a native
secondary vtable; full table ownership and class reconciliation remain open.
No new census-linked bytes, image-ownership receipt or runtime result is claimed.
