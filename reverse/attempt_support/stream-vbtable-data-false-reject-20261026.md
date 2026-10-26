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

## Separate repair and supported retirement

Tooling repair `deb5eccc41` adds `??_8` to the existing compiler-table
classification alongside `??_7`. Both new classification/folded-table tests
failed before the repair and pass afterward. The genuine user-global alias
control remains refused. The real-COFF converged-address test also refuses
a vbtable spelling at a protected global address. The data-sweep,
converged-data and gate-exploit suites pass **125 tests**, with one existing
open-escape case skipped.

The indexed basic_fstream provider's eight-byte table was also inspected:
it is `00000000b8000000`, without relocations, matching the observed ofstream
table and retail. This verifies the original false-reject case's data bytes;
it is not an executable link receipt.

After that separate tooling commit, normal builds pass **71/71 rows** across
the following nine sources, and scoped EH verification reports **20 EXACT**
graphs. No source body changes were needed. `repair_queue.py retire data`
independently passes for every source and removes **11 keys** in total, with
zero remaining findings in each source:

- GameLogic/Object/BfmeCtor001B3A20.cpp (one key).
- WWLib/stlport_basic_ofstream_char_default_ctor.cpp (one).
- WWLib/stlport_file_stream_name_ctors.cpp (one).
- WWLib/stlport_ifstream_name_ctor_0084C300.cpp (one).
- WWLib/stlport_ofstream_fd_ctor.cpp (one).
- WWLib/stlport_wide_fstream.cpp (two).
- WWLib/stlport_wide_istream.cpp (one).
- WWLib/stlport_wide_ofstream.cpp (two).
- WWLib/stlport_wide_ofstream_name_ctor_0084BF70.cpp (one).

The data register shrinks through its owning tool. These retirements correct
compiler-data classification debt; they do not recover new C++ bodies,
establish data ownership or change any linking/ownership headline. The cached
data ledger was not regenerated, and the separate supply-draw local-guard
ownership prerequisite remains unresolved.
