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

The fixed one-source comparison against d8d65b08cc is pending. No prospective
credit, current-master census, image-ownership or runtime gain is claimed.
The unchanged snapshot baseline has a verified receipt with 1,705,216 placed
closed-strict bytes; the production reference inputs were verified separately.
LINK-008/017 and the complete no-FORCE/no-stubs/runtime exit test remain open.
