# VP6 quantizer end-comparison layout, 2026-10-26

model=gpt-6 lane=R budget=30m; initial match t=11 minutes; final layout t=22 minutes.
Production base: 0044debbb5997dbbab5158ad1309f6a0186b3ca0.
Only the reviewed clean-room spec 001b71f0, retail and independently recovered
repository code were used; no decoder donor source was consulted.

Retail's correction array is 64 signed dwords at BD8360, followed immediately
by the existing 64-dword scan table at BD8460. The last quantizer loop starts
its pointer at correction+4, processes four entries through offsets -4/0/4/8,
advances by 16 and compares against correction+260, native VA BD8464. This
compares to scan entry one; the actual reads remain correction entries 0..63.
The old COFF contribution put the unrelated double 65536.0 after correction,
so the endpoint mapped its bytes instead of the scan table. Both tables were
already individually complete and had the correct initializers.

The existing scan definition now immediately follows correction, after the two
unrelated scalars. No value,
type, global name, source path, code algorithm, header, pin or alias changes.
The normal before/after controls reproduce the full 945-byte function and all
16 data initializers. An independent COFF/retail comparison retains all 26
native DIR32 sites and targets and proves the new 256-byte adjacency.
The expanded normal control also passes the unchanged quantize.cpp caller:
two bodies, 1,130 bytes, and all 16 data rows.

The remaining chain is explicit. GetQuantizedCoeffsMSE_RD (185 bytes) compares
against scan+260 at BD8564, entry one of the separate IdentityIndex owner at
BD8560 in InitLibrary.cpp. The measured f012cbcc5e graph already rejects that
unit with scan backward/forward-map conflicts. Seven consumer objects contain
14 relevant references; the only scan reference outside its 256-byte object
is this native end comparison. consumer-reference-proof.json verifies it from
retail. No cross-unit ownership move, invented prefix or checker change was
used to hide that prerequisite. Keep its full closure in the next comparison;
require no loss of previously credited bytes. This repair claims only the
correction-to-scan edge, not the whole native table chain.

At source-commit time the full comparison against f012cbcc5e was pending;
no prospective credit was claimed. The completed scoped result follows below.
No new function coverage, current-master census or runtime pass is claimed.
The private diagnostics are under build/vp6-quantizer-layout-link-20261026/.

The first byte-exact order put the scalars after the adjacent arrays. Tracking
the second end comparison showed why that order was insufficient: it would put
a scalar where the already-open scan endpoint lands. The final order moves the
unrelated scalars before the array pair. It preserves the scan table at section
offset 272 and its biased end at offset 532, with the same 528-byte contribution
size and identical section alignment/flags. Thus the existing caller endpoint
keeps its original placement while correction-to-scan adjacency becomes correct.
Both final normal controls pass. first-order-native-proof.json retains the
superseded ordering; after-native-proof.json and final-gate.txt prove the final
source. No second add_match or attempt-log record was made: the single original
945-byte match record remains accurate. source-finalization.json records the
additional layout work separately from that initial record.

The completed authoritative comparison f012cbcc5e -> d8d65b08cc
changes unique placed closed-strict credit from 1,703,678 to 1,705,216 bytes.
The gain is 1,538 bytes in 3 rows, with zero losses and zero new
function coverage. Exactly one of 23,460 canonical objects changes; all other
23,459 agree. The target is placed and closed-strict. The actual runner
exits zero after 3626 seconds, with zero final drift and new unresolved
references, no missing objects or failed compiles, and no stale warm start.
This is a fixed-comparison receipt, not a new current-master census.
The unchanged quantization-error caller is still closure-blocked; its actual status
and reachable failures are retained in remaining-caller-witness.json. Each
gaining row's previous blockers and complete passing closure are retained in
beneficiary-closure.json. Source work finalized at t=22 minutes, including
the layout review after the initial t=11 match record. Measurement time is
recorded separately; no repeated match record was made.

The three gaining rows are VP6_init_quantizer (945 bytes), VP6_UpdateQC (93)
and VP6_quantize_c (500). All three now have placed, self-strict and closed-strict
status. The unchanged 185-byte GetQuantizedCoeffsMSE_RD loses its prior backward
conflict; its forward-map failure on scan+260 remains, so it is not counted.
All other 23,459 canonical objects agree, including both gaining caller objects.

The independent report reproduces the 1,705,216-byte credit and every one of
98,202 status rows; it additionally forces and rechecks 25 closure roots.
The bound receipt/graph/tool hashes are retained in
independent-closure-verification.json. The fixed comparison uses the same
32774ab03393709a7f14331ba8d98d281a55ffd9 reference in both states, while the
ordinary source controls passed against production reference
001ccd8e27686e9887235b62ff797627f2dde7f5. No input was silently substituted.

The remaining native table chain and the separately recorded import-twin
prerequisite stay open. The complete game's no-FORCE/no-stubs/runtime exit test
is not met: the fixed receipt still records five forced duplicate symbols
(ten diagnostics), and no runtime pass is claimed. Current-master confirmation
belongs to the next normal census; no extra census or nightly runner was used.

The first normal publication hook passes 39/39 bodies across four sources,
18 data rows, four exact EH graphs, 15 float literals, 11 imports and
converged-data enforcement. Its shadow batch audit is inconclusive: index
d1f046749a predates outgoing base ced3615d0f3 and four scoped objects lack
current strict receipts, first Eva.cpp. The exact source paths and output are
retained in publication-audit.json and publication-gate-before-retry.txt and
carried under LINK-008 for the next normal census. No current-master provider
or lost-byte verdict follows from that audit. The Git push was rejected as
non-fast-forward after all hooks passed; only a normal rebase/retry is used,
with no repeated add_match, attempt record or full comparison.
