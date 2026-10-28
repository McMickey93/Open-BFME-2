# Tree-copy worker binding at 0x00501B33

Inspected base: `9daf20b530cdbff22ea69964c818aacc93ac2c91`. Published preview index: `14dc3d2467`
(2026-10-28 02:44, retail-truth-4). This is LINK-054's copy-constructor
subset; the other units retain their separate prerequisites.

## Target facts and source change

Retail's 165-byte tree copy constructor calls get_allocator at 0x0021983A,
the existing 36-byte proxy constructor at 0x004FF55E (call 0x00501B58),
and the existing 115-byte copy worker at 0x0050146E (call 0x00501B8E).
The proxy allocates 0x6C bytes. The tree worker's node prefix is 16 bytes,
with parent/left/right at +4/+8/+12, followed by a 92-byte value. Its owner
is Rva00500BF5Tree::copy in Rva00500BF5TreeInsert.cpp. The tree receiver
uses header/count at +0/+4. The separate 18-byte set wrapper still calls
the same tree copy constructor.

The source now uses STLport 4.5.3's copy-constructor structure with direct
calls to those existing owners. Its base adapter preserves the one-word
proxy storage and passes the allocator address in the existing constructor's
ignored one-word argument slot. The element's opaque extent is corrected
from eight to 92 bytes. No application type name or unconstrained field
meaning is recovered. The STLport source is an algorithm guide, not evidence
of the application's element identity or original source path.

Declaring the unused tree destructor specialization prevents this constructor
instantiation from emitting an unrelated element-destruction family. Two
obsolete pins, for the former tree-base constructor and copy-worker
instantiations, are removed. `hatch_counters.py --update` retires their two
register keys. No new pin, alias, row, shared header or compiler flag is added.
The get_allocator pin is retained; its emitted seven-byte body is unchanged.

An initial inline copy adapter added a register load before pushing the source
node and changed the constructor bytes. It was replaced by the direct call
inside the constructor specialization; no nonmatching trial is retained.

## Verification

- `./build.sh` passes 97/97 rows and one data row across the edited source,
  stlport_proxy_004FF55E.cpp, Rva00500BF5TreeInsert.cpp,
  StlportElementCopyCtorsW3G15.cpp and PickAndPlayUnitVoiceResponse.cpp.
- `eh_verify.py` checks the edited constructor's graph: EXACT 1, no baseline.
  The emitted base destructor keeps the original byte/relocation digest.
- The frozen-file, class, CSV, pin-consistency and diff checks pass. Scoped
  data checking has zero findings; staged code identity has zero new findings
  for the two rows in shadow mode.
- All five sources have current strict reusable receipts through
  `link_check.py --prepare-current`; this does not certify link closure.
- The ordinary current-object preview changes the edited source from
  U2/C1/S1 (0 authored bytes) to LINKS (183). The two providers retain
  36 and 618 bytes; the existing caller units retain 203 and 8,150 bytes.
  All five preview LINKS: 9,007 -> 9,190 authored bytes in this scope.
- External COMDATs in the edited object fall from 37 to 19: 21 names disappear,
  three trivial allocator/base-destructor helpers appear, and two retained
  bodies change fingerprints. The tree constructor's change is its worker
  relocations; the base constructor becomes the inline adapter. The set
  wrapper and get_allocator fingerprints remain unchanged. Removed names
  include the unneeded value construct/destroy, tree copy/erase/clear and
  allocation helper family. No application element constructor/destructor
  remains undefined in the object.

The staged-tree batch audit exits 2, **INCONCLUSIVE**: the index predates the
outgoing base and lacks per-object consumer names. The verified five-source
preview does not certify every external consumer of removed COMDATs. Carry
this scope into the next normal census; the strict receipts alone do not
resolve that missing index provenance. No census headline, runtime result,
source-file recovery or image-ownership gain is claimed.
