# Retire stale LOD-table data debt

Inspected base: `24518199023328f79b82ec63d43da7192b38672d` (2026-10-28).
Preview index: `41c28839bf`, 2026-10-28 11:08.

The earlier LINK-119 repair already provided the correct six strings and a
24-byte matched data row for `rva00202B6CNames` at RVA 0x009B95F4 in
`Code/GameEngine/Source/Common/Rva00202B6CGet.cpp`. The register still held
its duplicate-def and wrong-name findings from the older provisional data
identity. Current `data_check.py` reports zero findings for this owner.
No source, function row, data row, pin, symbol spelling or path changes here.

Verification:

- `find_declared_unmatched.py` accepts the owner.
- `./build.sh` on the owner, Rva005189CFText.cpp and
  OptionPreferences_setStaticGameLOD.cpp passes 12/12 code rows and the data
  row. Five renumbered funclet labels resolve through their verified parent
  graphs; all five checked literals pass.
- Same-index ordinary link preview: all three units LINKS, preserving
  70 + 279 + 137 = 486 authored bytes.
- `repair_queue.py retire data Code/GameEngine/Source/Common/Rva00202B6CGet.cpp`
  removes exactly two keys, with zero remaining source findings. This is the
  supported owning-tool retirement, not a manual register deletion.

The table's real target name remains unproven. The donor name alone does not
justify a rename. This retires two stale data keys; it claims no new census
linked coverage or image-ownership gain.
