# Palantir neighbourhood TU-evidence handoff

Inspected `b771f76827` on 2026-10-28. The default picker served 14 rows
in nine sources in the 0x001042EB..0x00104E03 run, with distinct proposed
brackets at 0x001042CF (W3DAptComponentView3D.cpp, K) and 0x00104E45
(BfmeThingEHCb.cpp, N). Neither establishes an approved containing TU.

Target facts:

- `python3 tools/tu_evidence.py --source
  Code/GameEngine/Source/Common/System/Rva002D40F4.cpp` prints its CSV
  header and no evidence rows. The picker's W3DRoadBuffer R signal for
  the wider run is proposal-only, not permission to move these bodies.
- The current map leaves 0x001042EB and 0x0010461F unassigned. The
  out-of-line Draw_Sentence overload at 0x00104D97 is displaced from
  render2dsentence.cpp; its real method name does not anchor this run.
- The reset source contains both 0x002D40F4 (332 bytes) and its caller
  0x001042EB (110 bytes). The WB lead at 0x002D40F4 is a score-1
  callgraph pairing with Palantir::OnAptMovieInitialized in Palantir.cpp.
  It does not pair the separate caller with that source path.
- The ctor source documents RadarViewBoxEdge and three Coord2D arrays,
  plus the separately reconstructed 0x00104359 geometry routine. These
  facts support the radar relationship, not an original TU assignment.

Donor facts: the planner found BFME1 and WB evidence for the original
W3DAptComponentView3D.cpp path. BFME1's current reconstructed source at
that path is an HAnim binding implementation with unresolved receiver
identity. That path and BFME1's AptPalantirConstructor.cpp are donor
leads, not BFME2 source provenance. No matching Zero Hour Palantir
implementation was found in the available reference sources.

`name_lane.py consolidate --under Code/GameEngine/Source/Common/System/`
completed without missing inputs (624 source files, 114 investigation
groups). Its Rva002D40F4 placement remains a WB hint, explicitly not a
verified target TU. No source, name or TU-map changes were made.

Next useful work requires a direct retail file anchor or independently
proved native class name and corroborating path. Do not merge this run
into W3DRoadBuffer or move the caller into Palantir.cpp from the current
proposal alone. No new matching, linking or source-recovery gain is claimed.
