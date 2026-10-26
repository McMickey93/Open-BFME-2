# StructureTopple range-erase identity verification

Inspected revision `e8cee3be67`. The identity picker claimed constructor
0x00257A5E and its source,
`Code/GameEngine/Source/GameLogic/Object/Update/StructureToppleUpdateModuleDataCtor.cpp`.
The earlier repair is documented in
[20261022-angle-erase-link.md](20261022-angle-erase-link.md).
No game source, function row, pin or compiler option changes are required.

## Existing repaired binding

The constructor's REL32 relocation at offset 0xEB names the rowed
`_STL::vector<BfmePod8>::erase` range overload. Retail calls RVA 0x003FA4DB;
the identity checker classifies this reference as `owner`. The registered
divergent key still names the old `vector<AngleFXInfo>::erase` emission,
which the existing source no longer emits. The 38-byte native erase owner
remains in `stlport_pod_vector_malloc_bodies.cpp`.

This verifies the existing binding, not the application's element identity.
The earlier repair's inline forwarding specialization and container casts
remain legacy source debt. They are unchanged, and this check does not
recommend copying them into other consumers.

## Verification

The frozen-source check reports all definitions already matched. Normal
`./build.sh` passes all five source rows (307 bytes), the empty string and
three float literals. Three renumbered funclets resolve through their
verified parent EH data. `tools/eh_verify.py` reports one EXACT graph,
zero baseline graphs and zero missing parents.

The first owning-tool retirement attempt refuses without modifying the
register: 239 participating provider objects are not current. The official
2026-10-26 19:02 index at `5ce093a71a` is retained, and its object bundle
is imported. A normal source-scoped build refreshes those providers; scratch
inputs and output are under
`build/structure-topple-identity-20261026-codexb4/`.

The provider build passes 4,420/4,420 function rows across all 239 sources,
75 existing data rows, 1,297 string literals, 194 empty-string references,
417 float literals and 203 named imports. It verifies 1,895 renumbered
funclet rows through parent EH data and 14 complete STLport constructor
folds. Of the selected providers, 39 objects are already current by the
build's cache check, 13 restore from the object store, and 187 compile.

With these current objects, `repair_queue.py retire identity` reports
**PASS: one key retired, zero still found**. Only that owning tool removes
the register line. No new findings are hidden by the retirement.

The ordinary `link_check.py` preview against the same official index reports
LINKS, preserving 266/266 authored nonpadding bytes. `check_csv.py` passes
with 98,272 function rows, 15,626 pins and 2,225 data rows; `git diff --check`
is clean.

The census already records this source as linked. No new matched bytes,
linked-byte gain or image-ownership receipt is claimed. Its separate
AsciiString header-adoption prerequisite and provider-unit blockers remain
outside this identity retirement.
