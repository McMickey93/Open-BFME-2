# StatusBitsUpgrade and WeaponBonusUpgrade guard ownership

Inspected at `10d8ab4531`, 2026-10-27, seat codex.

The data queue selected WeaponBonusUpgrade's obsolete guard spelling. The last
two standalone definitions in GlobalFlagClearers_E03Exx.cpp duplicate compiler
cleanup already emitted by these matched C++ parents:

| Parent | Parent RVA | Compiler label | Cleanup RVA | Extent | Guard RVA |
| --- | --- | --- | --- | --- | --- |
| StatusBitsUpgrade::getModuleNameKey | 0x004B48F9 | $L562 | 0x0078EC05 | 13 | 0x00A03E28 |
| WeaponBonusUpgrade::getModuleNameKey | 0x004B55EE | $L359 | 0x0078ED14 | 13 | 0x00A03E74 |

`eh_verify.verified_funclet_locations` binds each label through its own parent's
EXACT graph, including all associated cleanup bytes. This is target evidence,
not an adjacency or same-byte identity inference. The standalone free-function
names and external guard definitions are synthetic. Source search finds no
other Code reference to either external guard or clearer. Neither guard has a
data ownership row or converged name.

The first commit retracts the synthetic claims and records them in
reverse/deleted_rows.csv, as required before replacing a named row. It removes
the now-empty source and its two address-global hatch keys (six occurrences).
Both parents retain their cleanup code and pass all eight existing rows and
two EXACT EH graphs. A following admission will row their actual emitted
labels through add_match.py; the explicit cleanup-row coverage is temporarily
retracted in this first commit, not claimed as new recovery.

Path-consumer audit: the sole removed path is
Code/GameEngine/Source/Common/GlobalFlagClearers_E03Exx.cpp. Searches of tools,
hooks, workflows, includes and doxygen registries find no active dependency.
The two seed comments will be removed with funclet admission. link_status.csv
and the TU map's old source observations describe their measured inputs and
are retained; no TU approval is inferred from these historical source cells.
The current parent graph supplies the compiler ownership evidence.

The session also confirms two already-landed repairs against index
bf3dd31211 (2026-10-27 00:39, retail-truth-4): createVideoBuffer's four rows
verify and its paired current lock-provider preview is 2/2 LINKS (258 + 247
bytes); Rva005189CFText already previews LINKS (279 bytes). The latter's
LOD-table provider is held by another worker and was not edited. These checks
claim no new census-linked bytes or runtime result.
