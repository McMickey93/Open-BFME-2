# WOLLoginMenu consolidation, 2026-10-28

Inspected base: 75b54b305c. Preview census index: 41c28839bf.
The naming planner supplies an S-level WOLLoginMenu path anchor, an alternative
GameSpyLoginPreferences path, and structural contiguity/EH-parent evidence.
These are distinct evidence kinds; the supported skeleton planner rebuilds the
stale TU map in memory and approves 106 rows. No regenerated map is committed.
Five whole-file donors own 26 matched rows; four mixed sources remain outside
this batch. All five pass baseline byte verification and ordinary link preview
(1638 authored bytes). No census gain is claimed.

## Cleanup prerequisite

The destination explicitly specialized the list-pair tree's _M_erase as a
function declaration, suppressing emission of the cleanup donor's owned body.
Removing that declaration lets the existing destructor instantiation emit the
same teardown chain as the donor. It preserves all 25 existing external COMDAT
byte-and-relocation digests. Its three additional COMDATs (_M_erase, _S_left,
_S_right; 53, 8 and 8 bytes) exactly match the cleanup donor's copies. This
reconciles the private declaration environment; it introduces no new code row,
name, pin, or layout claim.

The destination passes 6/6 normal byte matches, its literal, frozen-file and
data checks, and two EXACT EH graphs. The baseline cleanup donor passes its
one 53-byte row. The remaining whole-file donors still need header/private-view
reconciliation: the password helper imports incompatible AsciiString and
GameSpyLoginPreferences declarations; tree hint insertion redeclares the
allocator; pair construction has a different pair specialization and default
construction context. Trial constructor reconciliation was reverted because it
did not preserve the composed bytes. Those sources are unchanged.

The supported dry run now accepts the destination and cleanup donor, keeping
all seven rows and passing its bounded census-linked donor guard. Both files
have strict reusable receipts and pass the ordinary byte gates. The tool's
chosen include search path union also contains the other candidates' reference
include directories; its emitted code is still checked, not assumed equivalent.
No code/data identity register or header-adoption queue key belongs to these
two files. The destination's existing nine-declaration MS-header ABI queue
entry is a separate, unchanged prerequisite.

Code identity shadow reports the existing lastEmail setter's AsciiString
destructor binding at 0x00036410 as divergent. That row's byte-and-relocation
digest and callee spelling are unchanged; no identity debt is retired.

Both units retain LINKS in the ordinary preview (314 + 53 authored bytes).
The prerequisite batch audit is INCONCLUSIVE: index 41c28839bf predates base
75b54b305c, and affected consumer Common/0CreateAHeroManager21FE49.cpp lacks a
current receipt. Carry the provider selection and affected-consumer scope into
the next scheduled census; runtime and broader consumer closure remain unverified.
