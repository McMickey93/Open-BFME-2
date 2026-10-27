# Region-details icon: canonical counted-base lifetime

Inspected `9773ede65a85a3da43afe891415bc769e3443d9c`, 2026-10-27.
Source: `Code/GameEngine/Source/GameClient/RegionDetailsStructuresIconCtor.cpp`.
Ordinary preview index: `73061d9452`, 2026-10-27 14:34.

The constructor already owns its 207-byte row at `0x005E28FE`, its ten-byte
EH handler and one eleven-byte cleanup. This is dependency cleanup, not a
new body or a correction of the old false-boundary verdict.

## Target evidence and change

The constructor's primary prefix is a vptr and a zero-initialized word at +4;
the observer subobjects follow at +8 and +C. Its complete EXACT EH graph
places the first cleanup at `0x007A354D`: `mov ecx,[ebp-10h]` followed by a
tail jump to `0x004E84A4`. That target's complete seven bytes are
`C7 01 20 6F BC 00 C3`, restoring the primary base table at VA `0x00BC6F20`.

The existing canonical `Rva0007DF07.h` supplies that consumed eight-byte
prefix, its zero-before-vptr initialization and its real virtual destructor.
Replace the private `IconCountedBase` declaration with this header and use
`Rva0007DF07` as the first base. The emitted destructor is the complete
seven-byte store/return, with the sole DIR32 relocation to
`??_7Rva0007DF07@@6B@`; the existing row at `0x004E84A4` supplies its binding.
This reuses an existing partial lifetime contract, without asserting the
original class name or a complete original hierarchy. No donor layout is used.

Before/after objects were produced only through normal `./build.sh` builds.
All six common external code providers retain identical instruction bytes;
five also retain identical relocation lists. The constructor's relocation
changes are its primary table qualifier and compiler-generated EH numbering.
All three Icon vtables retain their bytes and slot relocations after changing
the primary table qualifier from `IconCountedBase` to `Rva0007DF07`.
The two removed code providers are the old private base constructor and
deleting destructor; no other source or ledger refers to `IconCountedBase`.
Canonical base lifetime providers replace those private emissions.

## Verification and remaining work

- Normal byte verification: **3/3 rows exact**. The existing `$L998` row
  resolves through its parent EH placement to the current `$L1023` label.
- `find_declared_unmatched.py`: all defined functions already matched.
- `eh_verify.py`: **EXACT 1**, no conflicts or baseline exceptions.
- `data_check.py`: zero findings for this source.
- `link_check.py --prepare-current`: one explicit source verified with a
  strict reusable receipt; no census or index update performed.
- Ordinary `link_check.py`: unresolved names fall **4 -> 3**; the unit still
  does not link, and authored linking contribution stays **0 -> 0**.

The remaining names are `Icon::~Icon`, `IconMouseObserver::~IconMouseObserver`
and `LivingWorldBuildPlotObserver::~LivingWorldBuildPlotObserver`. Their native
targets are the existing `Rva005E278E` owner at `0x005E278E` and the seven-byte
table restorations at `0x005E211F` and `0x00238D97`. Reconcile the complete
derived destructor identity and observer interfaces against those owners;
equal-sized observer bases alone do not prove compatible callback declarations.
The pre-existing callback tables in this constructor still contain purecall
slots and are unchanged by this repair.

The first generated cleanup `uw_007a354d` can now use the canonical destructor
binding. Its claim was refused because another worker holds `0x007A354D`, so
its `uw_gen_013.cpp` row remains untouched. Claim it before using the parent's
EXACT EH placement and normal unmasked admission to repoint it. The other two
generated base cleanups retain their existing callee prerequisites (LINK-095).

No linked-byte, ownership, registered-debt or runtime improvement is claimed.
The outgoing batch still needs the normal hook audit; the local index predates
the inspected base, so this bounded preview does not establish current census
provider selection or whole-image closure.
