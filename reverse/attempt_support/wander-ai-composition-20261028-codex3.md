# WanderAIUpdate declaration cleanup and composition prerequisite

Inspected base: `f7755f211c`. Owner: `yasinschroeder-codex3`.

The default picker claims WanderAIUpdate.cpp and WanderAIUpdatePoolKey.cpp.
The naming planner inventories 121 AIUpdate sources. Its stale-map routes
remain hints; tu_skeleton rebuilds the map in memory and approves 16 rows
for this TU, with two clean input files and three mixed files retained.
Both input files pass the frozen-file check. The supported dry run accepts
no donor: the destination lacks the pool-key method declaration, and
tu_views reports incompatible WanderAIUpdate base clauses.

## Reverted declaration trial

Adding the donor's NameKeyType and virtual getModuleNameKey declaration to
the destination keeps all nine destination rows exact. It changes the
primary ObjectModule vftable from four to eight bytes, adding the method
at slot 1. Target facts independently show the constructor installs primary
VA 0x00C53D30 and its slot 4 contains VA 0x008A9384, the existing key body.
The trial was reverted. Code-byte success and the ordinary LINKS preview
do not prove this incomplete primary-interface layout correct.

The supported merge needs a coherent primary-interface declaration first.
The root table's other native entries are 0x008A9408, 0x0089A7EE,
0x008A9357 and 0x0089060D; identify and reconcile their existing owners
before retrying. The three mixed files are ConstIntGetters4.cpp,
Rva0026E836Derived.cpp and AIMachineFactories.cpp. No row, pin, source path
or TU-map approval is changed by this repair.

## Landed cleanup

The constructor's native store at VA 0x008A9343 installs table
0x00C47B88 at object +0x20. That table's first entry is 0x006673F6,
the existing rowed AIUpdateInterface::aiDoCommand(const AICommandParms *).
Its provider independently declares the command interface with the same
parameter and AIUpdateInterface override. These are target/current-provider
facts, not a donor-name inference.

WanderAIUpdate.cpp now uses that declaration pair. The command table
directly references the existing provider; the placeholder no-argument
linker alias is removed. The owning hatch tool drops exactly one
alternatename key (2,921 to 2,920). No new definition or pin is added.

Verification:

- Ordinary byte builds: all nine destination rows, all three pool-key rows
  and the 2,308-byte aiDoCommand provider are exact. Both Wander parent EH
  graphs are EXACT. Frozen-file, class and scoped data checks pass.
- Destination external COMDAT inventory remains 28 bodies. Twenty-seven
  byte/relocation digests are identical. Only the four-byte command vftable
  changes, replacing the old placeholder relocation with the proven
  aiDoCommand provider. Exclusive definitions and weak externals are
  identical; the sole undefined-symbol change is that same binding.
- Before/after ordinary previews retain two LINKS and 646 authored bytes
  (567 destination + 79 pool-key), index `54b83e4f69` dated 2026-10-28 09:35.
  The destination has a current strict reusable receipt. This is no census
  or runtime gain.
- The staged shadow identity check reports the existing Unwind@00b8e0fc
  reference to ??1Rva00261058@@UAE@XZ at RVA 0x0049C38A as wrong/unknown.
  A read-only scan using the saved pre-edit object produces the identical
  finding. No shared cached object was replaced; this cleanup does not
  resolve that pre-existing identity uncertainty.
- Outgoing staged-tree batch audit exits 2 / INCONCLUSIVE: its index is
  `54b83e4f69`, older than this outgoing base, so its since-index selection
  is provisional. Affected consumer
  Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp lacks a
  current receipt. Carry the consumer and the retained command-table
  binding into the next census; full consumer verification is unclaimed.

BFME 1 freshness was checked against official upstream: the pinned verified
input is `e74410b3738a2bb75d626085d9ebfd3406a43ff7`; official master is
`ea2916a82ded9db4736834269771be8df13216b6`. The update's file scope is held
by another worker, so this seat preserves the verified checkout and does
not refresh the success timestamp. The update still needs its owning
worker's full verification and pointer publication.
