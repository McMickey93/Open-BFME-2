# VP6 Huffman table layout, 2026-10-27

model=gpt-6 lane=R budget=30m; t=8 minutes for the homogeneous three-body unit.
Production base: 9d6c94a6fe93c7a2b823beec6fd9f033df8c6c19.
Only the clean-room specifications 001c5310, 001c4fe0 and 001c50b0,
retail and the independently recovered repository code were consulted.
No external decoder source was read.

The existing 48-byte token-minimum array at BD8B48 is immediately followed
by the 260-byte coefficient-band map at BD8B78 in retail. The old compiler
layout placed masks/minima/bands at .rdata offsets 0/132/184. Its inferred
52-byte minimum contribution included four zero alignment bytes, while those
four native bytes are FFFFFFFF, the band map's first signed value. The fixed
d8d65b08cc graph records exactly this data-content failure twice for the parent.
The ordinary 48-byte data-row check already passed; it did not prove the
complete contribution. before-closure-nodes.json retains the actual graph.

Definition order is now minima/bands/masks at offsets 0/48/312. The minimum
extent is 48, band extent 264, mask extent 132. The band's four trailing zero
bytes match native padding. All three complete inferred data contributions
now match retail. Section size 444 and flags 0x40400040 remain unchanged.
All 440 logical initializer bytes, existing names/types and all four native
DIR32 references remain unchanged. A repository consumer search finds these
names only in HuffTokens.cpp; all data references have zero addends. No body,
header, pin, alias, data value, data row or source path changes.

Before/after normal controls and the single add_match replacement pass all
three existing bodies (1,829 bytes) and all three data rows. The parent is
1,661 bytes and the two register-convention static helpers are 94 and 74.
The body record is made once; no new function coverage is claimed. The source
repair finalized at t=8 minutes; full measurement time is separate.

At source-commit time the fixed one-source comparison against d8d65b08cc was
pending; no prospective credit was claimed. Its completed result follows below.
No current-master census, image-ownership or runtime gain is claimed.
The unchanged snapshot baseline has a verified receipt with 1,705,216 placed
closed-strict bytes; the production reference inputs were verified separately.
LINK-008/017 and the complete no-FORCE/no-stubs/runtime exit test remain open.

The fixed receipt still records five forced duplicate symbols (ten diagnostics); the complete no-FORCE/no-stubs/runtime exit test is not met. No runtime or image-ownership receipt is claimed.

The completed authoritative comparison d8d65b08cc -> dc81d055af changes unique placed closed-strict credit from 1,705,216 to 1,708,093 bytes: 2,877 gained in 3 rows, with zero losses and zero new function coverage. Exactly one of 23,460 canonical objects changes; the other 23,459 agree.

The actual process exits zero after 3471 seconds. Final drift and new unresolved references are zero; no missing objects, failed compiles or stale warm start are admitted. Each gaining row has its former failure path and complete passing closure retained in beneficiary-closure.json. This is a fixed-comparison receipt, not a new current-master census.

upstream-closure-witness.json retains the before/after failure paths for all six higher callers in the fixed graph. Any remaining motion-vector, tone-coefficient and neighbour-offset storage failures are separate prerequisites; no whole-decoder closure is claimed.

The three gaining rows are VP6_ReadHuffTokens (1,661 bytes), VP6_DecodeBlock (511) and VP6_DecodeMacroBlock (705). The two caller objects are unchanged. Independent reconstruction reproduces all 98,202 link-status rows and the 1,708,093-byte credit, with 25 additionally forced closure roots. The controlled comparison keeps reference 32774ab03393709a7f14331ba8d98d281a55ffd9 in both states; the ordinary source gates passed against production reference 4fa9d591641a743b86f2320343b7a276585b814b. No inputs were silently substituted.

The first normal publication gate passes 41/41 rows across four sources, five data rows, four exact EH graphs, five float references, eleven imports and converged-data enforcement. Its mandatory batch audit is inconclusive: index d1f046749a predates outgoing base 3e1e5f6d6a5, and three source objects lack current strict receipts (first Eva.cpp). No current-master selected-provider or lost-byte verdict follows. The exact cohort and output are retained in publication-audit.json and publication-gate-before-retry.txt and carried under LINK-008 for the next normal census. Git rejected the push only because master advanced; no match record or full comparison is repeated.
