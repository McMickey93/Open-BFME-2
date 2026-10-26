# Region3D adoption: Coord3D streamer prerequisite

Inspected revision: `c973319b7d3`, 2026-10-26.
Selected whole file: `Code/Libraries/Source/WWVegas/WWMath/region.cpp`.
The served Region3D header-queue entry reports a `Coord3D` class redefinition
when its canonical header meets this file's private `class Coord3D`.

## Supported prerequisite trial

The non-applying command
`py -3 tools/header_adopt_lane.py run --class Coord3D --sample 1 --seed 17 --jobs 1`
selected exactly `region.cpp`. It tested the registered canonical header and
restored source and scoped ledger changes afterward. Result: 0/1 units pass,
with a bytes/callee identity failure in the 47-byte Region3D debug streamer,
`??6@YAAAVDebug@@AAV0@ABURegion3D@@@Z`, RVA `0x0000517C`.

Canonical `struct Coord3D` changes the trial object's two call references,
at body offsets 11 and 35, to `??6@YAAAVDebug@@AAV0@ABUCoord3D@@@Z`.
That symbol is undefined in the trial object and has no ledger/pin provider.
Both retail calls target `0x000050BA`, whose 103-byte provider in
`Code/Libraries/Source/WWVegas/WWMath/coord3d.cpp` is still named
`??6@YAAAVDebug@@AAV0@ABVCoord3D@@@Z`. The scoped adoption tool does not migrate
this separate provider. Matching instruction shapes do not resolve the
callee-identity failure; this is not a false reject.

`coord3d.cpp` retains a private `class Coord3D : public Coord3DBase`, including
explicit constructor behavior. `PathDebugOutput.cpp` is another V-form caller.
The next repair must reconcile the provider and its callers together and
verify affected rows; a second alias or hand-added pin is not a repair.
Canonical member growth also has the separate dependent-EH obstacle documented
in LINK-018. No shared-header expansion was tested in this trial.

## Preservation and whole-file scope

The restored file passes normal `build.sh`: 45/45 matched rows and all seven
string references. `find_declared_unmatched.py` accepts its six existing
absent-from-retail anchors. No source, ledger row, header-queue row, pin or hatch
is changed by this handoff. The Region3D header was not accepted.

The file also contains queued IRegion2D and Region2D views. Inspection shows
their canonical headers do not declare all the out-of-line members present
here; no adoption of either was applied or claimed verified. Do not treat the
single served sample (Coord3D::scale) as the whole file's adoption scope.

Ordinary `link_check.py` reports the restored file links, retaining 1,287 bytes
against census `d1f046749a` (2026-10-26 13:18). This is a prediction and does not
record census progress. No new matched bytes, linked bytes or debt retirement
is claimed. Attached logs retain the supported trial, exact call references,
restored verification and current link preview.
