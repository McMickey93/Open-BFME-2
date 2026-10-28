# Texture statistics storage ownership

Publication reconciliation, 2026-10-28: upstream `fc5da7fbc2` independently
landed the shared storage repair with C++ linkage and repointed 0x007B7060 to
the recording unit's compiler-emitted _$E5. The rebase onto `d6a91b0f7e`
keeps upstream's source and data-ledger definitions, including its reporting
consumer fix; it does not restore the removed standalone thunk or the older
C-linkage names below. This commit retains the historical investigation and
handoff only. The six data keys and two hatch keys are already retired upstream,
so no additional debt or linking gain is credited for replaying this evidence.
The retained upstream five-source scope passes 941/941 function rows and all
17 data rows after conflict resolution; eight funclets verify through their
parent EH data and all literal/import checks pass.

Inspected revision: a6ff8c1f32. Ordinary preview index: 41c28839bf,
2026-10-28 11:08 (census commit c8734bec0c).

Target evidence:

- The existing `DebugStatisticsRecordTexture.cpp` initializer at RVA
  0x007ACCC0 constructs `latest_texture` at VA 0x00DEE918 and registers
  callback 0x007B7040. The callback invokes the rowed destructor at 0x0017098D.
- The same unit's initializer at RVA 0x007ACD20 constructs
  `texture_statistics` at VA 0x00DEE920 through 0x0012A520 and registers
  callback 0x007B7060. That callback invokes the base destructor at 0x0012A4D0.
- Matched reset and recording bodies independently bind these same addresses.
  No donor source, inferred donor path or new data name establishes this repair.

The recording unit now defines both objects with their existing C symbol
spellings. TextureStatisticsVector.cpp declares them, eliminating its private
copies and extra initialization. The two shutdown fragments reference these
objects directly; the four-byte address-named vector placeholder is removed.
DebugStatisticsRecordTextureEnd.cpp also shares the vector. Its old nonvirtual
view bound a separate static object at VA 0x00DEE924; restoring the vptr and
the two dynamic-vector counters makes its Vector member correctly address
the shared object at +4. Its eight rows remain exact.
Opaque destructor declarations retain the native tail calls. Record/change
counter statics remain separate debt: previous external-linkage trials changed
load scheduling, and this change does not repeat those trials.

Verification:

- Before and after source changes: 933/933 matched rows across all four files,
  plus 17 data rows. The reporting consumer adds eight exact rows (941 total).
  Eight renumbered funclets verify through parent EH data.
- All five frozen-file checks pass. Data identity finds no unregistered debt.
- `repair_queue.py retire data` retires three keys from each of the two
  statistics units. `hatch_counters.py --update` removes five address-global
  occurrences (two keys).
- `data_ledger.py --out build/texture-data-codexb/data_ledger-final.csv` generates one
  definition and one symbol for each repaired address. Only its two exact
  generated rows are copied into the committed index, and the stale interior
  0x009EE924 row is removed when it disappears from that generated output. The full collection
  reports 58 unrelated sources without objects; all previously indexed users
  of these two addresses and the interior reporting view were compiled here. No global index refresh or claim
  of complete data ownership is made.
- Paired ordinary previews: RecordTexture and TextureStatisticsVector retain
  LINKS (774 and 722 authored bytes). The reporting consumer retains LINKS
  (1,006 authored bytes). DebugStatisticsTextureShutdown changes
  from unresolved address-name to LINKS (10 authored bytes).
- Rva007B6880Thunks has the same unresolved
  `?rva001EAF7B@Rva001EAF7B@@QAE_NXZ` before and after. Its current owner is
  FreelistPool.cpp, which independently passes its 11-row byte gate but is
  absent from this census. Adding it to an ordinary preview is refused as
  unmeasured. This is not evidence of a new loss or a clearance of that unit.

Local raw checks: build/texture-data-codexb/build-before.log,
link-before.log, link-end-before.log, build-after.log and link-after.log. The changed sources stay
at their existing paths and keep every code row. No census, ownership receipt
or runtime smoke was run; measured LINKED and NOT OURS gains are not claimed.
