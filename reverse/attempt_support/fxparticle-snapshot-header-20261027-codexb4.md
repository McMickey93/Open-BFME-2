# FXParticleSystem Snapshot adoption: provider prerequisites and acceptance repair

Inspected revision: `ec06a82135fc123aa18ce8928ff325be37bfb72a`.
Date: 2026-10-27. Source:
`Code/GameEngine/Source/GameClient/FXParticleSystem.cpp`.
Queue item: `Snapshot`, anchored at 0x000011B4 (9 bytes), the existing
ModuleTemplate constructor. This is a header investigation across the unit,
not a new body or a lost-row repair.

## Controlled trial

The unit already includes the canonical Snapshot header with capitalized
slots, the name slot, a non-const getter and reference transfer enabled. It
also retains the one-slot private `FXParticleSystem::Snapshot`. Removing that
private base alone leaves several embedded info classes abstract, as the
earlier blocked verdict records.

The trial removed the private base and replaced the info views' placeholder
`v1` declarations with declaration-only `LoadPostProcess()` and
`DoXfer(::Xfer&)` overrides. The three obsolete pointer-transfer declarations
were removed from those views. The two `/alternatename` bindings for the
DefaultAlpha/DefaultColor `v1` placeholders were removed as part of that
trial. No shared header, ledger row, pin or compiler flag changed.

Normal `./build.sh` verification passed all 368 function checks, the one data
row, 17 strings and 10 floats. This proves byte preservation for this trial;
it does not prove that every declaration-only override is the correct retail
abstract/concrete surface.

The ordinary link preview against fetched index `bf3dd31211` (2026-10-27
00:39, `retail-truth-4`) then changed:

```text
before: LINKS          LINKED 5,649 -> 5,649 bytes
trial:  does not link  LINKED 5,649 -> 0 bytes
```

It reported both `LoadPostProcess()` and `DoXfer(Xfer&)` unresolved for each
of these nine `FXParticleSystem` classes:

- ButterflyDrawModuleInfo
- DefaultAlphaModuleInfo
- DefaultColorModuleInfo
- DefaultDrawModuleInfo
- DefaultUpdateModuleInfo
- LightningDrawModuleInfo
- QuadDrawModuleInfo
- RenderObjectUpdateModuleInfo
- StreakDrawModuleInfo

The complete source was restored, rebuilt normally and previewed again:
368/368 function checks and the data/string/float checks pass; LINKS remains
5,649 -> 5,649 bytes. `find_declared_unmatched.py` reports all defined
functions already matched (369 ledger rows, including aliases). No game
source or header-debt retirement is retained. Local source snapshots and raw
normal-build/preview logs are under `build/fx-snapshot-20261027/`.

## Target evidence and next work

`reverse/exports.csv` names these nine classes' LoadPostProcess exports at
0x000B3FD0. Their DoXfer export leads and current ledger owners are:

| Classes | Export RVA | Existing provider |
| --- | --- | --- |
| ButterflyDraw, DefaultDraw, QuadDraw, StreakDraw | 0x00306A9B | `Rva00306A9BDoXfer`, `Common/System/Xfer.cpp` |
| DefaultAlpha | 0x0055B266 | `Rva0055B266::rva0055B266`, `System/FXParticleSystem/Rva0055B266Xfer.cpp` |
| DefaultColor | 0x0055B8CD | `Rva0055B8CD::rva0055B8CD`, `System/FXParticleSystem/Rva0055B8CD.cpp` |
| DefaultUpdate | 0x0055F67C | `DefaultUpdateModuleInfo::xfer(Xfer*)`, `System/FXParticleSystem/DefaultUpdateModuleInfoXfer.cpp` |
| LightningDraw | 0x005614D9 | `LightningDrawModuleInfo::xfer(Xfer*)`, `System/FXParticleSystem/LightningDrawModuleInfoXfer.cpp` |
| RenderObjectUpdate | 0x00562182 | `RenderObjectUpdateModuleInfo::xfer(Xfer*)`, `System/FXParticleSystem/RenderObjectUpdateModuleInfoXfer.cpp` |

All source paths in the table are relative to
`Code/GameEngine/Source/GameClient/`, except Common/System/Xfer.cpp, which
is relative to `Code/GameEngine/Source/`. Class labels omit the common
`ModuleInfo` suffix. These are export-name leads and current ownership facts,
not proof of each class's complete vtable or abstract slots. Recover those
surfaces from retail first, reconcile the existing providers' names and
pointer/reference signatures in their approved units, then retry the header
adoption with a clean preview. Do not add a second named pin over these
already owned bodies. The empty callback RVA was held by another worker
when a smaller cleanup was considered; that cleanup was not started.
No donor source was used.

## Acceptance false positive repaired

Before this repair, `header_adopt_lane.py accept` passed the byte-exact trial
and removed its queue row despite the 5,649-byte preview loss. That queue
change was restored. The documented link check existed as an unused helper;
`verdict()` never called it.

Acceptance now requires an explicit per-source ordinary-preview result with
no loss of census-linked bytes, after the include/private-body/byte checks
pass. A missing, unknown or failed preview cannot retire the row. An already
blocked source may remain at 0 -> 0; this guard does not require header work
to solve unrelated link blockers. The same verdict is used by the trusted
header-debt hook. The tool does not fetch or publish an index or claim a new
census measurement.

Regression tests cover the observed 5,649 -> 0 loss, absent/ambiguous results,
compile errors mentioning the source, checker errors, a missing checker,
preserved/gained coverage and already blocked units. Hook tests confirm that
manually removing a row after lost/unknown linking is refused. The combined
header-lane, repair-queue and gate-exploit suites pass (294 passed, one skip).
