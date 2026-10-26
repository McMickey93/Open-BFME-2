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

The full fixed comparison against f012cbcc5e is pending. No prospective credit,
new function coverage, current-master census or runtime pass is claimed here.
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
