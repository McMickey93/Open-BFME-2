# Browser donors: use the existing data owner

2026-10-26, codexb5 / Sol medium, Family B shard 1/2. Runner allocation approves
`Code/Libraries/Source/WWVegas/WW3D2/dx8webbrowser.cpp`; scoped planner original
paths, alternatives and mixed-donor prerequisites were reviewed. This is a
separate data-identity cleanup after the overload prerequisite, not a name vote.

## Existing identity and minimal repair

The existing owner in Common/BfmeConv804.cpp declares and defines
`BfmeObjECF *g_bfmeObjECF` at RVA 0x009F7040. The data register already records
three wrong-name uses of that same address in the clean browser donors. Do not
edit, rename or move the Common owner. In each donor, declare that existing real
pointer and cast its address at the point of use to the existing smart-pointer
view. Retain the checked operator-> and its E_POINTER behavior. The three views
remain private declarations; no new global, view, pin, alias or class is added.
Two donor-local /alternatename pragmas become unnecessary and are removed.
CreateBrowser no longer references the Rva00959410Dispatch alias; the separate
Common owner's alias and other consumers remain untouched.

## Acceptance and provider/consumer proof

- `./build.sh` on all three donors: 10/10 exact, one named import. After the
  last CreateBrowser edit its six rows independently pass again; the other four
  rows retain their just-verified objects. Declared-unmatched, class and
  Microsoft-header checks pass. Standalone EH: three EXACT, zero missing.
- `tools/data_check.py` finds zero findings in the changed sources;
  `--converged` reports ten addresses, zero second names and unjudged rows.
  Each source passes `tools/repair_queue.py retire data SOURCE`: exactly three
  fixed keys removed from reverse/data_check_baseline.txt, none silently lost.
- Supported scoped before/after object comparison retains all ten rows and
  23 references. Canonicalizing only the two obsolete data spellings to the
  existing owner proves every surviving external code definition, its raw
  bytes/relocations, COMDAT rule and section flags equal. Undefined sets and
  data bindings are equal under that explicit replacement; no data is defined
  by the changed donors. All surviving global selected providers are the same.
  Raw digests for the three referencing functions change because the referent
  name is part of the digest; this is the intentional, proven identity fix.
- Two unrowed conversion operators (D30 and E30 pointer conversions) disappear
  from standalone objects after the null tests use the real pointer. The
  supported name_dependents global current-ledger object/source-hash search
  finds no consumers. No matched body or external requirement is lost.
- Normal upstream merge dry-run still accepts the three clean donors / ten
  rows, with no clean donor rejected. Its final composed object is reverified
  under carried flags: twelve external definitions, no changed definitions or
  COMDAT rules, no new undefined names, 23/23 identical bindings, three EXACT
  EH parents, equal data definitions/bindings, no divergent standalone copies.
  Of thirteen touched selected names, the only removed provider is the existing
  D30 operator-> inline helper; the supported global consumer scan finds only
  its defining standalone object, and the composed rows do not require it.
  All twelve surviving selected definitions retain their providers/facts.

The adjacent JSON retains standalone snapshots, the explicit canonicalization
comparison, composition, global selection, consumer and EH evidence. Scratch
proof scripts use allowed_symbols, link_census, data_check, eh_verify and
name_dependents APIs under build/sol-b5-web-data-*; no gate is edited.

## Register ownership, audit and remaining blockers

The hatch register file claim is held by another worker. Leave that register
untouched; its owner can reconcile the two now-removed alternatename lines for
Rva001776a0Cluster.cpp and DX8WebBrowser_Is_Browser_Open.cpp. Source removal is
verified, but no hatch-register debt reduction is claimed. The data register
claim is held by this seat until publication. No code-identity key is retired.

Before this commit/publish, audit all origin/master..HEAD plus the staged change:
all source edits are in place, with no source path move, split, deletion, ledger
repoint, include/build-input change or historical EA-path change. Active tools,
hooks/workflows and registries need no repointing. The data register removes only
the three proven-fixed source keys; protected remaining keys retain ownership.
The scoped planner is regenerated after the final edit and its currency check
passes. No regenerated TU map, hatch growth or gate relaxation is staged.

Mixed donors and cross-family Common prerequisites remain for their owners;
this cleanup neither applies a merge nor proves a downstream Luna landing.
Measured improvement: three data debt keys retired. File reduction and recovered
C++ bytes: zero. No linked-byte, census or NOT OURS improvement is claimed.
