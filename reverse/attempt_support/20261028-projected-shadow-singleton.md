# Projected-shadow singleton ownership, 2026-10-28

## Target facts

- LINK-121 recorded the retail load `8b0dd4c2de00` from VA 0x00DEC2D4
  in doFXPos (RVA 0x001E0E43 +238) and TerrainResourceClaimFeedback
  (RVA 0x004E7FCA +313). The native shadow-manager constructor writes the
  projected manager to that same slot.
- W3DProjectedShadowUpdate.cpp already defines
  `ProjectedShadowManager *TheProjectedShadowManager`; TerrainResourceClaimFeedback.cpp
  already consumes it. Rva0029E159Audio.cpp separately defined the pointer as
  `AudioManager0029E159 *g_00DEC2D4`. These were competing names for one
  four-byte, initially zero slot, not two globals.
- A new explicit data_rows.csv row verifies the existing definition at RVA
  0x009EC2D4. Explicit verified ownership overrides the old heuristic data_ledger
  owner; data_ledger.csv was not hand-edited.

## Donor facts and scope

The pinned reference/open-bfme-1 checkout is
e74410b3738a2bb75d626085d9ebfd3406a43ff7. Under its
inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Source/W3DDevice/GameClient/Shadow/:

- W3DProjectedShadow.cpp:85 defines the same named singleton.
- W3DShadow.cpp:113 assigns the projected manager to it; :121 clears it.

Those are Zero Hour donor facts, not BFME 2 source-path evidence. The target
address identity above supports reusing the already present target name. No
new class identity or class layout is claimed.

The duplicate definition was removed and all nine affected sources now bind
the existing canonical pointer. Existing private ABI views remain casts at
use sites. data_converged.csv protects the address from second names.
rename.py global --dry-run refused because the old heuristic name has no
data_rows.csv row; deleting a competing unrowed definition and reusing an
existing owner also changes its declared type. No named ledger row or pin was
renamed or removed.

## Verification and limits

- find_declared_unmatched.py passed before and after on all ten scoped sources.
- build.sh: 74/74 function rows and 2/2 data rows verified across ten sources;
  string, float and import checks passed. Existing funclet label renumbering
  was verified through parent EH data. eh_verify.py: 13/13 exact.
- data_check.py: eleven sources, zero findings; --converged: eleven protected
  addresses, zero second names and zero unjudged rows. check_csv.py passed.
- Ordinary link previews against published index 73061d9452 pass for all ten
  previewable affected providers/consumers, including TerrainResourceClaimFeedback.
  DynamicDecalFXNuggetDoFXPos.cpp already passed before this change; its stale
  census status is not evidence of a new linking gain.
- The merged W3DShadow.cpp is absent from that index and cannot be previewed
  there. Its matched code/data and EH checks pass; its current link closure
  remains for the next census. No strict receipt, census gain, image ownership
  gain, source-file reduction or counted hatch reduction is claimed.

Scratch receipts: build/projected-singleton-{build,eh,data-check,converged,after}.log.
