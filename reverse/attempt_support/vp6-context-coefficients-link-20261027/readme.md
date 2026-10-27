# VP6 context coefficient initialization, 2026-10-27

model=gpt-6 lane=R budget=30m; t=8 minutes for the 331-byte context function.
Production base: fd9943a1267e482d876fc6e67793d3219daa1f36.
Only clean-room spec 001c6da0, retail and independently recovered repository
code were used. No external decoder source was consulted.

The existing sole g_bfmeToneCoef owner was a zero-filled 120-byte .bss array.
Retail VA BD9430 contains fifteen signed (slope, bias) pairs, ordered by five
nodes and three contexts, exactly as independently stated in the clean-room
spec. The fixed dc81d055af graph records data-content on this owner and its
331-byte context function. before-closure-nodes.json retains that witness.

The same global, element type, array bound and field layout now have the real
aggregate initializer. All 120 bytes agree with retail. The compiler emits a
120-byte initialized .data allocation; its source-level mutability is retained.
The data row records the retail .rdata home and proves sizeof/initial contents
through the normal tool. The existing data_ledger.csv already identifies this
symbol and sole source owner; no second name, provider, pin or alias is added.
All ten coefficient DIR32 targets and the CPU-clear-slot reference are unchanged.

This corrects real computation: at probability 128, the first (122, 133) pair
produces 194 under the existing rounded-shift/clamp expression. The old zero
pair produced the clamp minimum 1. The code body and arithmetic are unchanged.

Normal before/after controls pass the complete 331-byte function. The expanded
control passes the unchanged 556-byte entropy-decoder caller as well: two bodies,
887 bytes, and six data rows. One add_match replacement records this existing
body exactly once, with zero new function coverage. Source work finalized at
t=8 minutes; automated full-measurement time is separate.

The fixed comparison against dc81d055af is pending. It must contain only this
source change and the single newly proven data row, with every other comparison
input held fixed. No prospective credit, current-master census, image-ownership
or runtime gain is claimed. The previous receipt has 1,708,093 placed
closed-strict bytes. Motion-vector/default-table storage prerequisites remain
separate; the complete no-FORCE/no-stubs/runtime exit test is not met.
