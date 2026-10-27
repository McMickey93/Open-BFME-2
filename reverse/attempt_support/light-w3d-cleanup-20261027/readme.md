# Light W3D donor-remnant cleanup

Inspected tree: `7ed44e8ffd66316c8a48b08e87168d8b450e54d3`.
Published provider index: `bf3dd31211`, 2026-10-27 00:39, rules
`retail-truth-4`. Source: `Code/Libraries/Source/WWVegas/WW3D2/light.cpp`.

LINK-053's factory and earlier Save/Load cleanup were already present. The
remaining unrowed donor `LightClass::Load_W3D` and `Save_W3D` methods have no
call site in the current Code C++ sources and no incoming reference from an
indexed definition with an outside provider. Their presence is cleanup debt,
not a lost matched row. Remove these bodies and retire their two unmatched
exemptions using the hatch tool's snapshot, preserving unrelated allowances.
No ledger row, pin, shared header, compile flag or source path changes.

The complete unit passes `./build.sh` before and after: one row, six retail
bytes at RVA 0x00615B60 (`LightPersistFactoryClass::Chunk_ID`), with string,
float and import checks. Frozen-file, EH, shadow data and CSV checks pass.
The paired previews place actual saved before/after objects at the same
census position; neither reports unresolved, duplicate, COMDAT, address or
selected-provider blockers. The cleanup adds zero linked bytes.

[comparison.json](comparison.json) records source, object and index hashes,
removed emissions, alternatives, the incoming-reference audit and selected
provider changes. No retained COMDAT digest changes and no selected provider
becomes wrong. Definitions removed without an alternate have no indexed
incoming edge from an outside provider. This is bounded evidence against the
published index, not a fresh census or a check of every source changed since
that index. Carry the removed-provider audit into the next scheduled census.

The optimization anchor remains necessary. A separately built removal trial
kept the six-byte row exact but changed the retained `??_H` vector constructor
iterator from the 34-byte retail digest `6246c280fc30` to the 50-byte wrong
digest `4a16af1679c7`. Restore the original anchor and both optimization
pragmas; neither is retired. The rejected trial is retained in
[rejected-anchor-comparison.json](rejected-anchor-comparison.json).
