# PlayerList canonical Xfer prerequisite

Recovered inherited work on 2026-10-26, codex, family A shard 0/2.
Destination: Code/GameEngine/Source/Common/RTS/PlayerList.cpp.
The source/ledger owners stay in place; no merge or split is applied.

PlayerListDoXfer.cpp had a private Xfer declaration, while the registered
BfmeXfer.h needs explicit operand forward declarations in each consumer.
The donor now supplies those declarations, includes the canonical header,
and uses its integer and Snapshot transfer operators. No shared header,
class contract, pin or virtual layout was changed. MSVC's overloaded virtual
ordering retains the retail dispatch offsets, verified by the complete body.

`python3 tools/header_adopt_lane.py accept --class Xfer
Code/GameEngine/Source/Common/RTS/PlayerListDoXfer.cpp` passes and retires one
queue row. Before/after `./build.sh` on the destination and donor preserves
2/2 matched rows (22 and 109 bytes) and the destination's data row.
`find_declared_unmatched.py` passes; class and converged-data checks pass;
there are no scoped EH rows. No code/data identity keys were removed.

Saved verified before objects versus current objects, using upstream
allowed_symbols/link_check/link_census helpers: the seed's six code
definitions and 552 non-debug sections, and donor's one code definition and
two non-debug sections are identical. Comparison includes section bytes,
named relocations, COMDAT policies, undefined names, aliases and external
data definitions. All four code reference facts and every data binding and
definition fact remain equal. There is no provider or consumer binding
change in this header prerequisite, including seed-emitted shared helpers.
Local receipts: build/codex-playerlist-{object-proof,reference-delta,
data-delta}.json and build/codex-recovery-build.txt.

The full ordinary `tu_skeleton.py --merge TU --dry-run` completes and accepts
the seed and three unrelated small donors (six existing rows). DoXfer is still
rejected: the composed scratch file triggers MSVC C1001 at line 46. Other
donors retain AsciiString redefinitions, missing PlayerList members and byte
mismatches. This adoption retires header debt; it demonstrates no increase in
merge acceptance. Receipt: build/codex-playerlist-after-trial.txt. No merge is
published and no confirmed downstream Luna landing is claimed.

After the trial, `link_check.py --prepare-current --paths-from
build/codex-playerlist-sources.txt` passes for both explicit providers and
writes strict reusable receipts. This does not check LINK closure or change
the census/index. The blocked composition verdict is recorded at 0x002A7D63.

Compatibility audit of origin/master..HEAD plus the staged adoption finds
no source move, rename or deletion. The existing header resolves via the
explicit relative include; active tooling, hooks, workflows, includes, build
inputs and registries need no path repoint. Historical paths remain intact.
File claims on the destination, donor and this handoff stay until confirmed
publication. File reduction, identity debt retired and recovered bytes: zero.
