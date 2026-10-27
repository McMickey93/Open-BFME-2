# Current-frame texture counters

2026-10-27, inspected BFME 2 revision `83f299b390`.
Scope: `DebugStatisticsRecordTexture.cpp`, `TextureStatisticsVector.cpp` and
`DebugStatisticsRecordTextureEnd.cpp` in `Code/Libraries/Source/WWVegas/WW3D2/`.
All three source scopes were claimed before editing.

The recording, reset and reporting units each defined private current-frame
counters. Their matched DIR32 sites identify the following existing data-ledger
addresses and owners. These are target binding facts and existing source names;
no new donor-name or original-TU claim is made.

| Existing COFF name | Retail RVA | Retained definition |
| --- | --- | --- |
| `_procedural_texture_memory` | `009EE87C` | TextureStatisticsVector.cpp |
| `_lightmap_texture_memory` | `009EE8A8` | TextureStatisticsVector.cpp |
| `_texture_count` | `009EE8C4` | DebugStatisticsRecordTextureEnd.cpp |
| `_texture_memory` | `009EE8CC` | TextureStatisticsVector.cpp |
| `_lightmap_texture_count` | `009EE8E0` | TextureStatisticsVector.cpp |
| `_procedural_texture_count` | `009EE8FC` | TextureStatisticsVector.cpp |

Give these six definitions external C linkage and declare them in their two
consumers. C linkage preserves the existing COFF spellings. Each counter keeps
one four-byte zero-initialized definition; twelve private copies disappear.
No constructor, destructor, initializer, function row, pin, name or source path
is added or removed. The provisional data ledger is not regenerated.

## Checks

- Before and after: `./build.sh` passes all 31 matched rows in the three units.
  The declared-unmatched check is clean. Three stale funclet labels resolve
  through their matched parents' EH data; all four EH graphs are EXACT.
- Saved control objects versus final objects: all 58 executable sections
  (20 recording, 26 reset, 12 reporting) have identical raw bytes and symbolic
  relocation tuples. This includes unrowed compiler-generated code and lifetime
  helpers. The six owner symbols have external storage class; their consumers
  contain undefined external references rather than private definitions.
- `repair_queue.py retire data SOURCE` retires six recording, five reporting
  and one reset key, respectively, from `reverse/data_check_baseline.txt`.
  The owning tool performs every deletion. The fourteen remaining findings
  (5 + 6 + 3) are all registered; enforced checking finds zero new keys.
- Enforced converged-data checking covers ten addresses with zero second names
  and zero unjudged rows. `link_check.py --prepare-current` verifies all three
  sources and supplies strict reusable receipts without changing the census.
- Before/after ordinary previews against index `bf3dd31211` (2026-10-27 00:39,
  retail-truth-4) give three LINKS: 774 recording, 722 reset and 1,006 reporting
  authored bytes, totaling 2,502. The recording unit's unreferenced 20-byte
  RefCountPtr pointer constructor remains the same codegen diagnostic as the
  saved control (majority copy: 11 bytes); it is not a preview blocker.

This retires twelve data-register keys. It claims no new census-linked bytes,
image-ownership receipt or runtime result. The normal push-hook batch audit
still owns outgoing selected-provider/lost-byte conclusions; an older index
must be carried into the next maintainer census rather than called a gain.

A scoped pre-commit batch-audit probe supplies these three verified sources at
base `83f299b390`. All three receipts are current, but the audit marks its
baseline INCONCLUSIVE: its older index contains 293 objects retired by the
current ledger, producing 1,663 provisional provider-disappeared findings and
one provisional wrong selected hashtable provider. There are no lost-byte
lines. The hashtable constructor at `003A37FA` is now rowed in `Team.cpp`;
the old index selected STLSweepW5Rva003A37FA.obj, and the bounded overlay instead
selects ArmorHashMapCtor003A393A.obj. Neither unit nor that code definition is
changed here. Sample disappeared rows likewise remain rowed in consolidated
owners: CommandTranslator::translateGameMessage in CommandXlat.cpp and
PoisonedBehavior::xfer in PoisonedBehavior.cpp. This does not prove wider
closure; carry current provider composition and selection into LINK-017 and
the next normal census. No verifier or unrelated source is changed.

## Restored whole-file trials and remaining prerequisites

Sharing all eight current-frame counters preserves 30/31 rows, but changes the
333-byte `Debug_Statistics::Record_Texture` parent at `0012A2B0`. Externalizing
`record_count` (`009EE8B4`) and `texture_change_count` (`009EE888`) delays the
argument's pointee load and changes the comparison form, consistent with an
alias-analysis effect; the trial parent is two bytes shorter. An explicit
`TextureClass *referent = t.Peek()` before the increment restores that early
load but introduces a reference-count null guard in the null arm, adding
sixteen bytes. These are compiler-output observations; an original alias
contract or source layout explaining them has not been recovered.

Both failed trials were restored. The final patch shares only the six counters
above and leaves both record/change counters private in all three units.
Reconcile their native alias/load contract before retrying; do not admit an
optimization hatch or relax verification. The recording-mode trial and
vector/handle/string storage extent, initialization and teardown prerequisites
from the [previous scalar repair](texture-statistics-data-20261026-bce2/readme.md)
also remain. No lifetime object is replaced with a smaller placeholder.

## Default-link-queue triage

Before selecting this debt repair, the default queue served W3DUtility.cpp's
historical thread-wrapper selected-copy failure. Its five rows pass normal
byte verification. Paired current-object previews with BfmeDX8ThreadLock.cpp
and BfmeDX8ThreadCheck.cpp all LINKS: 1,502 + 247 + 31 = 1,780 authored bytes.
This confirms the existing LINK-106 repair for another caller without source
changes; census confirmation remains pending. Those claims were released.
