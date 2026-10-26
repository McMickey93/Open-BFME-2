# Stream constructor vbtable data false reject

Inspected 2026-10-26 at 3bdbac21fc, seat codexb. The data picker served
`Code/Libraries/Source/WWVegas/WWLib/stlport_file_stream_name_ctors.cpp`.
No source or register edit is retained in this report.

Normal byte verification passes all four constructor rows (1041 bytes).
The declared-unmatched check passes. Supported data retirement refuses the
existing wrong-name key at 007BCD24: the emitted
`??_8?$basic_ofstream@DV?$char_traits@D@_STL@@@_STL@@7B@` differs from the
data ledger's basic_fstream basic_ostream vbtable spelling at the same address.

Current-object evidence, read through build.read_object_symbol_bytes:

- The entire ofstream vbtable is eight bytes: `00000000b8000000`.
- It has no relocations. All eight bytes equal retail at RVA 007BCD24.
- This is an ordinary compiler-generated virtual-base offset table emitted
  by the STLport instantiation, not a manually declared second global.
- `data_ledger.kind_of` returns `global` for the `??_8` symbol. Its emitted
  prefix list handles `??_7` vftables but omits vbtables. The shadow
  `data_check.findings` consequently judges the compiler spelling as a
  user-global identity. Its documented compiler-table exemption is incomplete.

Record this false reject before changing the check. A separate tooling repair
should classify vbtables as compiler tables and test both the observed folded
table names and a genuine user-global alias. The enforced converged-address
check must continue refusing second names regardless of spelling; add a vbtable
case there as a control. Run the gate-exploit suite with the repair. Only then
retry supported retirement. This report neither changes table ownership nor
claims a link or census gain.
