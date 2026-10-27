# Geometry consolidation: existing seed rejected under carried flags

2026-10-27; input `6f01dd46ce`; claim owner `yasinschroeder-codexb`.

The default picker claimed the approved Geometry.cpp destination and twelve
clean donors. The scoped naming planner's inputs passed its currency check.
The current in-memory TU plan lists 35 approved rows, thirteen donor files
including the seed, eleven mixed sources and zero mechanically refused files.
The planner's stale-map hints were not treated as routing approval.

`tu_skeleton.py --merge Code/GameEngine/Source/Common/System/Geometry.cpp
--dry-run` exits 2 without accepting or changing any source. Its existing seed
is the 39-byte `clamp<float>` at `0x0000575A`. The report says the seed has
"no baseline match" and blocks before composing donors. This is a verifier
false reject for the existing seed, not a lost match or an unrowed body:

- The ordinary `./build.sh` for Geometry.cpp passes 1/1 matched rows, plus
  the string, float and named-import checks.
- `Verifier.effective` with ordinary regional selection writes
  `// cl: /O1 /arch:SSE /G7` for that seed.
- The donor override vote selects the empty managed override held by the
  calcPitches and getMaxHeightAbovePosition donors (three registered rows).
  `_merge` sets `v.flags` to the empty string before checking its seed.
  `Verifier.effective` then writes an empty `// cl:` line, discarding the
  seed's region flags. The dry-run baseline check consequently rejects it.
- Four donors are independently excluded by incompatible registered overrides:
  expandFootprint and set require `-O2`, rva006BD9C0 requires `-Ox -G6`, and
  the Rva0087E370 view requires `-O2 -G6`. Their compatibility remains untested.
- Declared-body checks pass for the seed and every clean donor. Construction's
  placement-new definition retains its existing absent-from-retail marker.

Recorded the false reject with `re_log.py`, left the check and every source
unchanged, and released all thirteen scope claims. No merge, codegen workaround,
new matched bytes, link gain or debt retirement is claimed. A tooling seat can
reproduce this case from the ordinary build and the supported dry run; it needs
to distinguish a seed's own flags from a carried donor override before judging
whether a composition can preserve both. After that repair, rerun the dry run
and handle genuine declaration/flag prerequisites through the normal lane.

Raw plan, dry-run, seed-build and declared-body results are under ignored
`build/codexb-geometry-*` paths. The shared linking-obstacle document was held
by another worker when claimed; this handoff preserves the result without
editing that claimed document.
