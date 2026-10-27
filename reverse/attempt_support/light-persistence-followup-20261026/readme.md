# Light persistence cleanup follow-up

Inspected tree: `ff45f96b144ed03d8759cf03c723e00bfb9e2755`.
Published provider index: `5ce093a71a`, 2026-10-26 19:02.
Source: `Code/Libraries/Source/WWVegas/WW3D2/light.cpp`.

The factory instance and factory Load/Save definitions described in LINK-053
were already absent. The donor `LightClass::Save` and `LightClass::Load`
bodies and their two unmatched exemptions remained. Remove those two bodies
and their now-unused persistence chunk constants. Keep the W3D file reader
and writer, the matched `LightPersistFactoryClass::Chunk_ID`, all compile
flags and all other definitions.

`./build.sh` passes the complete one-row unit both before and after (six
bytes at RVA 0x00615B60), including string, float and import reference checks.
The paired previews use the actual saved pre-edit object and the rebuilt
post-edit object at the same census position. Both have zero unresolved,
duplicate, COMDAT, address or selected-provider blockers, and preserve six
linked authored bytes. This cleanup adds zero linked bytes.

The object audit removes three definitions. `RenderObjClass::Get_Transform`
has another indexed provider and its selected owner stays unchanged. The
other two are the removed persistence methods. Neither has an incoming
reference from an indexed definition with an outside provider. No retained
COMDAT digest changes, and no selected provider becomes wrong. The raw
comparison records the source, object and index hashes in
[comparison.json](comparison.json).

This is bounded evidence against the published index, not a fresh census or
a complete check of sources changed elsewhere since that index. The remaining
`Load_W3D` and `Save_W3D` exemptions remain separate work. Retire the two
persistence exemptions through `hatch_counters.py --update`; keep unrelated
register entries unchanged.
