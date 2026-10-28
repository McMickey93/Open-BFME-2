# ProjectileStreamUpdate constructor header prerequisite

Inspected base: `7c98b18b59`, 2026-10-28. Destination:
`Code/GameEngine/Source/GameLogic/Object/Update/ProjectileStreamUpdate.cpp`.
This is a declaration cleanup, with no source-path moves or ledger changes.

## Evidence and change

- The supported planner and `tu_skeleton.py --plan` place the constructor
  (RVA `0x0033EE25`, 89 bytes) in the existing destination. Its standalone
  private base views and enums prevent composition with that TU's headers.
- The constructor now uses the destination's existing header environment.
  Retail's constructor stores and the existing matched member accesses give
  the ID ring at `+0x20` and the object extent `0x8C`; the donor header alone
  is not evidence of BFME 2 layout or virtual-slot identity.
- Removed the two `unused` virtuals and their linker aliases. The owning
  hatch tool removes exactly their two register keys, 2924 -> 2922 aliases.
  Its unrelated stale GameLogicDoXfer register removals were left out.
- Preserve the destination's include order. Omitting GameLogic/Object/Xfer
  headers changed VC7.1's inline pool guard from `$S14` to `$S10`, making
  `getClassMemoryPool` copies differ and the paired destination preview fail.
  The retained constructor has 595 external COMDATs: all 594 shared with the
  destination have identical bytes-and-relocation digests. The remaining
  COMDAT is the constructor itself. The two old placeholder base-vtable
  symbols disappear; the replacement tables already exist in the destination.
  This comparison does not certify their complete native virtual contracts.

## Verification and limits

- Initial five-source `./build.sh`: 11/11 exact. Final constructor passes
  `link_check.py --prepare-current` with a strict reusable compiler receipt
  and all ordinary body/reference gates; 1/1 exact, 89 bytes retained.
- Frozen-file, class, EH (zero rowed EH graphs), staged TU ownership and
  converged-data checks pass. Data: 11 addresses, no second names or unjudged
  rows. Shadow code identity: one row, zero new findings. No identity/data,
  header, Microsoft-header or flag-override register keys name this donor.
- Final paired preview of destination, constructor, GetAllPoints, PoolKey and
  Xfer: 5/5 LINKS, 757 -> 757 authored bytes against index `14dc3d2467`
  (2026-10-28 02:44). These are previews, not census gains.
- Staged-tree batch audit is INCONCLUSIVE: index `14dc3d2467` predates the
  outgoing base and lacks per-object consumer names. Fetching the published
  index retained that same index. Carry the changed constructor bindings and
  their external consumers into the next normal census. No runtime or image
  ownership result is claimed.

## Remaining consolidation prerequisites

The second supported dry run accepts no donor. The constructor now compiles
in composition but fails its byte comparison: the destination's `/GX` and
missing `/Oi` change constructor code generation. The standalone constructor
keeps its matching `/Oi` environment without `/GX`.

PoolKey still requires reconciling the placeholder static `rva0033EE84`
declaration with the module-name key contract. Xfer still conflicts between
canonical `BfmeXfer.h` and the destination's reference Xfer class, plus duplicate
enums. GetAllPoints still conflicts with GameLogic and Coord3D declarations
and needs its BFME 2 Drawable position accessor preserved. The two mixed
sources holding the destructor and snapshot-name rows remain outside the
whole-file merge. Reconcile these prerequisites in verified commits before
retrying `tu_skeleton.py`; no files were merged in this pass.
