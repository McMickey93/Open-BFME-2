# Audio identity retirement: a verified renumbered EH label is rejected

Inputs: upstream `b1071e9a2636856cd6d840965af51c747ee4d44f`, outgoing audio
tip `42e205255d`, BFME 1 `001ccd8e27686e9887235b62ff797627f2dde7f5`.
The normal pre-push hook refused the two identity-key retirements for
`Code/GameEngine/Source/GameLogic/LargeGroupAudio/LargeGroupAudioKeyMapBfmeAddKey.cpp`.

The audio batch passes 992/992 function rows and 26 data rows across ten sources.
The affected AddKey source passes all five rows. A separate `eh_verify.py`
run reports two EXACT graphs, zero missing objects and zero baselined failures.
The byte verifier explicitly locates the ledger's `$L4992` at retail 0x00773EC5
through the parent's exact EH graph as the current compiler label `$L5053`.

The current COFF has no `$L4992`. `$L5053` is a local STATIC symbol in section
54 at offset 13, with an eight-byte body `8d4df0e900000000` and one REL32 at
offset four to `AsciiString::~AsciiString`. Retail bytes are
`8d4df0e96c7bd1ff`, targeting 0x0048BA39. This is target/compiled evidence;
no donor inference or new source-name recovery is involved.

Two independent prerequisites were reported by the hook:

1. Five missing ledger objects and seven stale participating provider objects.
   Those are legitimate refusals and are being refreshed by normal `build.sh`.
2. A literal lookup for `$L4992` rejects the already located funclet. Both
   `repair_queue.identity_verdict` and `allowed_symbols.Identity.row_refs`
   repeat that lookup; merely removing the first check would silently skip
   the actual cleanup relocation in the second.

The second condition is the LINK-061 false reject. Seven real-COFF regression
cases fail before any verifier edit: a missing old label, a still-existing
wrong old label, and unproven, duplicate, external, non-code or absent physical
labels. The intended separate tooling repair must use the verified parent EH
location in both paths, inspect the located body's relocations, keep the
original ledger identity for baseline keys, and retain all provider checks.
No pins, ledger labels, source bytes or register entries are changed by this
handoff. No census, linking or debt clearance is claimed.
