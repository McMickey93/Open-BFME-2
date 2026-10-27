# AptNativeHash consolidation prerequisite and lookup binding

Inspected revision: `80c1c312ad2949348055b4231f67412a5bda9b7e`.
Scope: the six approved donors for
`Code/Libraries/Source/Apt/AptNativeHash.cpp`, selected by the default picker.
No merge or source-path move is retained.

## Evidence and retained repair

The current-input TU plan approves 23 existing matched rows in
`AptNativeHashBFME2.cpp`, `AptNativeHashMark.cpp`,
`AptNativeHashRva0070B180.cpp`, `BfmeLookupErase1279.cpp`,
`Rva0070A840Dtor.cpp`, and `Rva0070B380Cluster.cpp`.
These are existing row ownership facts, not newly recovered functions.

The lookup at 0x0070B380 calls the existing 489-byte
`AptNativeHash::HashFindKey` owner at 0x0070AF90. Its former private
address-named declaration used an alternate name to that same provider, plus
a pin. The retained C++ calls the owner's const pointer-argument signature
directly, with friendship declared in both views. This preserves the native
call ABI and complete caller bytes. It does not establish the original class
identity of the still address-named lookup wrapper.

The now-unused alternate-name directive and pin are removed. The supported
hatch updater lowers alternatename 3188 -> 3187 and pin 15302 -> 15301;
it also invalidates an unrelated content-bound allowance without changing
that key's count. No function extent, name, path or canonical header changes.

## Verification

- `./build.sh` across all six donors: 23/23 functions exact, one data row and
  38 string references pass. After adding the seed's friend declaration, the
  two changed units pass 19/19 functions and 36 string references again.
- `eh_verify.py` on the changed pair: one EH row EXACT. The declaration
  renumbers a compiler label; the verifier resolves it through parent EH data.
- `find_declared_unmatched.py`: all six donors initially pass; both edited
  sources pass after the repair.
- `data_check.py`: zero findings for the edited pair (shadow mode).
- Staged class and code-identity checks pass; identity reports zero new
  findings (shadow mode). `pin_consistency.py --check` and `check_csv.py` pass.
- Ordinary previews before and after use published index `bf3dd31211`
  (2026-10-27 00:39, retail-truth-4). All six donors remain LINKS:
  seed 2892, mark 145, event flag 158, erase 191, destructor 111, lookup 133
  authored bytes; total 3630 -> 3630. These are preview results, not a census
  gain. Local raw receipts: `build/apt-native-hash-{before,after,final}.log`.

## Remaining consolidation prerequisites

The dry run accepts the seed, destructor and lookup (20 rows), but refuses
three donors on incompatible private declarations:

- Event flag: the composed AptNativeHash lacks `rva0070B180`, and EAStringC
  lacks `rva00620090`.
- Mark: the composed Entry declaration encounters AptValue before its type
  declaration (C2143/C2501). Reconcile declaration ordering and the complete
  required interface before retrying; the diagnostic alone does not establish
  that ordering is the only blocker.
- Erase: the seed's private HashFindKey lacks friendship for BfmeLookup1279,
  and EAStringC lacks `rva006D3470`.

The planner also retains AsciiString adoption prerequisites for the seed and
destructor. LINK-099 and earlier attempt records document the canonical
header's missing native `hasData` contract. This pass does not repeat that
failed adoption, grow the shared header, or retire either header queue row.
The remaining failures concern composition of already matched bodies, not
evidence of missing retail functions. Reconcile each donor's interfaces in
verified commits before applying `tu_skeleton.py --merge`.
