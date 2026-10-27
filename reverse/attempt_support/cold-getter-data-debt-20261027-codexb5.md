# Cold getter storage ownership and stale data debt

Inspected revision: `e1a73387fd`, 2026-10-27. Scope claim:
`file:Code/GameEngine/Source/Common/ColdGlobalDwordGetters.cpp`.

The picker served the getter's historical data-identity debt at RVA A046B4.
Current-object inspection finds four of this source's eleven registered keys.
The other seven already disappeared through prior owner/name repairs. A fifth
finding, outside the register, compares the existing descriptive symbol
`g_currentAptOnlineCustomMatch` with its obsolete address-derived spelling in
the heuristic data ledger. No new name or storage definition is introduced.

The existing sole definition is a four-byte `int` in this source. Target facts
for `?g_currentAptOnlineCustomMatch@@3HA`, from current compiled rows:

| Native body RVA | DIR32 operand offset | Object addend | Retail VA |
| --- | --- | --- | --- |
| 004FDA11, getter (6 bytes) | 1 | 0 | 00E063EC |
| 005A5BC7, constructor (1535 bytes) | 12B | 0 | 00E063EC |
| 005A0009, destructor (195 bytes) | 33 and 42 | 0 | 00E063EC |

The constructor stores its receiver in the slot. The destructor compares its
receiver with the slot and clears it when equal. The new matched data row
records this existing owner at RVA A063EC: the data probe verifies sizeof 4 and
all four loader-zero bytes. Its descriptive name and integer storage ABI are
retained; these facts do not establish the original source identifier. Explicit
verified ownership supersedes the stale heuristic spelling when the data checker
loads its index; the generated heuristic ledger is unchanged.

Eighteen `extern int` declarations immediately duplicated definitions already
preceding their uses. Removing them lowers sixteen address-global occurrence
counts by one each. The two forward declarations whose definitions follow
their uses remain. No global, linker alias or matched function is removed.

Validation:

- `./build.sh` on the storage owner, AptOnlineCustomMatchCtor.cpp and
  AptOnlineCustomMatchDtor.cpp: 69/69 function rows and 2/2 data rows exact.
- Final owner-only build: 37/37 rows and 2/2 data rows exact.
- `eh_verify.py` on both lifecycle users: 2 EXACT exception graphs.
- `repair_queue.py retire data` on the owner: seven keys retired, four retained.
- `data_check.py`: four findings, zero outside the remaining baseline.
- `data_check.py --converged`: zero second names, zero unjudged rows.
- `check_csv.py`, `find_declared_unmatched.py` and `git diff --check`: pass.

The remaining keys are the three getter spellings at A04450, A046B4 and A04904,
plus the competing linked-list spelling at A0ABB0. They still need owner/type
reconciliation. This pass records data ownership and retires stale exemptions;
it makes no new linking or image-ownership headline claim.
