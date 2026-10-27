# VP6 MV update-table transcription and endpoint handoff, 2026-10-27

model=gpt-6 lane=R budget=30m; t=13 minutes for the 331-byte function.
Production base: b8e318a126214af7b863fdca3ab24eace20abb15.
Only clean-room spec 001c6ef0, retail and independently recovered repository
code were used. No external decoder implementation was read. Historical
source comments mentioning a decoder correspondence are not evidence used here.

The existing 2 x 17-byte g_vp6MvUpdateProbs initializer has two transcription
errors: component 0 column 13 is 250 instead of native 254; component 1 column
14 (flat index 31) is 254 instead of native 251. These values disagree with
both retail and the independent clean-room spec. Both bytes are corrected;
all 34 initializer bytes now match. The same global name, array type, bound
and source owner are retained, with its exact data-row home registered.

Normal before/after gates and one add_match replacement pass the full
331-byte body. All six DIR32 operands are unchanged. The object comparison
proves identical code, symbol positions, non-debug section layouts and
relocations. The only non-debug payload changes are the two table bytes.
The cached control's .debug$S records a different compile-root path and size;
that debug difference is retained explicitly, not called a layout repair.

The endpoint prerequisite is separate. Retail operands at body offsets
127, 219 and 315 are table+35 (BD94CB), table+36 (BD94CC) and table+43
(BD94D3). The actual table's logical and compiled extent is 34 bytes;
BD94CA..BD94CB is zero native alignment padding, and the 14-byte defaultMvShort
owner starts at BD94CC. Thus the latter two endpoints coincide with
that separate default table's beginning and byte 7. These are end comparisons,
not proof that the probability array itself has extra rows or a prefix.
The existing fixed a150087a1c graph records data-back here as well as the
now-corrected content error. This change contains no allocation/placement fix.

The supported ordinary preview against index bf3dd31211 (2026-10-27 00:39)
returns LINKS, retaining 330 -> 330 authored bytes. That predictor does not
supply a new strict-closure or census measurement. No extra linking credit,
new function coverage, current-master census or runtime gain is claimed.
A full comparison was not launched for this still-open endpoint subset.

The next check is coordinated native storage/provider reconciliation through
fresh approved TU evidence. The committed tu_map.csv marks 001C6EF0 as
code-unledgered although the current function ledger already owns the matched
body; that stale/fallback assignment is not a move approval or a missing body.
Do not create a second row, artificial prefix, larger fictitious array, pin,
alias or weakened verifier to conceal the endpoint relationship.

At the origin-backed scope check, decodembs.cpp was held by davidrazidlo-claude
with the note 'coordinator: re-claim for queued upload' and about 3.8 hours left.
It owns defaultMvShort and was not edited. Its separate frame-decoder data-back
prerequisite remains in the fixed graph. Resume the coupled storage work when
that scope is available and the destination is approved. This is a real data
repair plus a bounded linking handoff, not completed MV-decoder closure.
