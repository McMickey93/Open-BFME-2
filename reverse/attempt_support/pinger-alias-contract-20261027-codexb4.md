# Pinger alias-contract follow-up

Inspected `bb2acc05b2` on 2026-10-27. This follows the retained eight-global
repair in [the earlier evidence](gamespy-pinger-shared-data-20261027.md).
No source change is retained and no debt or linked-byte gain is claimed.

The default picker served pingerMain.c's four counter-identity keys at
0x00A0C0EC. The current provisional data ledger still selects the four-byte
`Rva00A0C0ECStorage` union defined in RvaSmallLeafTransfers.cpp. Its native
0x006B2150 owner reads a dword and updates a word, while the two C units use
the unsigned-short `piNextID`. Binding another name or silently replacing
that owner would not establish one shared storage definition. Reconciliation
of the existing owner, access widths and C linkage remains necessary.

Both C source scopes were claimed. Their declaration checks were clean.
The other outstanding same-file key, `piSettingData` at 0x00A0C104, was tested
with two additional hypotheses, retaining peerPing.c as its ledger owner:

1. Making the owner external and the pingerMain.c declaration extern, with
   `SOCKADDR_IN *__restrict from` on piProcessTrip2, fails compilation.
   VC7.1 reports C4235: the `__restrict` keyword is not supported in this
   product. This compiler cannot express that proposed alias contract.
2. An inline helper accepting the IP, port and data buffer by value before
   setting the shared flag changes piProcessTrip2's frame from 24 to 28
   bytes, its register allocation and its body. Ordinary byte verification
   fails that row; the other 18 pass. The helper does not solve the earlier
   scheduling problem.

Both trials were fully reversed. The final `./build.sh` over peerPing.c and
pingerMain.c passes all 19 rows and both named imports. All five remaining
data keys are preserved. A blocked verdict records the new compiler evidence;
both file claims are released. Next work should reconcile the counter's
existing storage owner or find a VC7.1-compatible shared-flag expression
that preserves the complete 230-byte piProcessTrip2 body.
