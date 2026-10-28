# NAT predicate consolidation, 2026-10-28

Inspected initial base: `cadd4c46f3`. Merge base after prerequisite publication:
`9c6829533a`. Owner: `yasinschroeder-codex`.

## Scope and placement

`next_work.py --claim` selected `Code/GameEngine/Source/GameNetwork/NAT.cpp`
and claimed its clean donor scopes, including the Common fragments. The
supported `name_lane.py consolidate --under Code/GameEngine/Source/GameNetwork/`
report was refreshed after the prerequisite edit; its input/output check passed
before the merge. WorldBuilder and reference paths are corroborating leads,
not proof of a BFME 2 source path. `tu_skeleton.py` rebuilt the stale map in
memory and approved the existing predicate's NAT destination. The committed map
changes only the predicate's source column, not its placement or evidence.

The prerequisite commit declares the already-rowed `rva005A6732` in the
destination and gives its donor the seed's existing slot-pointer type and
member names. The ordinary paired build verifies 5/5 rows. All 14 external
COMDAT byte/relocation digests, definitions and references remain unchanged.

`tu_skeleton.py --merge Code/GameEngine/Source/GameNetwork/NAT.cpp` then
absorbs `Code/GameEngine/Source/Common/Rva005A6732Check.cpp`. Its sole row,
`0x005A6732` (92 bytes), moves to the approved destination. Together with
`0x005A688C`, `0x005A6C90`, `0x005A6A4C` and `0x005A6E7A`, the destination
holds five matched rows totaling 383 bytes. No extent, name, status or notes
change. At the merge base, source files fall from 22,318 to 22,317.

## Verification and bindings

- Before composition, the normal paired build passes 5/5 rows; both units
  preview LINKS for 92 and 291 authored bytes against the census index measured
  at `14dc3d2467`, 2026-10-28 02:44 UTC.
- After composition, `./build.sh` passes the same 5/5 rows in the destination,
  with seven string references verified and no float or import references.
  Frozen-file checks pass before and after; `check_csv.py` passes.
  `progress.py` retains BYTE-MATCHED 100% and reports SOURCE FILES 22,317 (-1).
- Before/after object inspection with `link_census.comdat_bodies` preserves all
  14 external COMDAT symbols, sizes and byte/relocation digests. The external
  definition set is identical. The same three external dependencies remain:
  the StringBase C-string constructor, StringBase::releaseBuffer and
  PortNegotiationSchema::handleNegotiationResult. This also verifies the
  merge-selected compiler settings and the unchanged ascii shim resolution.
- The merge engine's census-linked guard accepts the composition. The ordinary
  destination preview reports LINKS for 383 authored bytes: the donor's 92
  bytes have moved, with no new census-linked coverage claimed.
- The whole outgoing-range batch audit is **INCONCLUSIVE**. It compares base
  `a1bc365655` with staged tree `e1dfd6ab470bbfbcfa37bf051af57a632ad8807f`.
  The index predates that base and lacks complete per-object consumer names.
  Fetching the published index through the supported helper confirms that the
  available asset is the same 02:44 census; no newer index replaces it.
  Full consumer/provider selection verification and census confirmation remain
  outstanding. Carry this moved scope to the next normal census. No image
  ownership or runtime gain is claimed.

## Registers, queues and path-consumer audit

Neither the absorbed donor nor the destination owns a code-identity baseline,
data baseline, header-queue or Microsoft-header queue key. The merge tool
refreshes affected queues and produces no queue change. There is no data row,
pin, hatch, fold proof or flag-override key to transfer or retire.

The complete outgoing path batch at `a1bc365655` consists of this single donor
absorption; the prerequisite changes no paths. The combined donor path and
basename search covers active tools, hooks, workflows, source/header includes,
root build/configuration files, registries and documentation. No executable
consumer or include needs an update. Function and TU-map source columns resolve
to NAT.cpp. Remaining old-path mentions are the destination's donor-provenance
comment and census-owned `reverse/link_status.csv`; both are intentionally
retained. The directory itself is not moved, so existing directory globs retain
their meaning. This handoff adds historical mentions only.

## Remaining composition prerequisites

The broad view trial accepts no additional donor. NAT's class/struct spellings
differ, and PortNegotiationSchema views report incompatible explicit sizes
(empty partial views versus the 0x8BC view). The attempted GameSlot superset
needs complete UnicodeString and NetPacketAddress definitions in its consumers;
the tool reverts it. Its address-only change enables no merge and was reverted
before the bounded predicate repair.

Nine clean donors remain rejected: attachSlotList and processGlobalMessage
have competing/missing NAT members; Common/NAT.cpp, probeMangler and both
Rva005A8666 donors need their methods and fields reconciled; Rva005A69C0Box and
sendPings need the PortNegotiationSchema declaration context; sendNegotiationRequests
also encounters the native cstring/strtok_unimported conflict. Six mixed files
stay in place. Reconcile a bounded donor in a separate verified commit before
retrying it. No nonmatching reconstruction or temporary trial remains under Code/.
