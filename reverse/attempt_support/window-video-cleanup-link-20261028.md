# WindowVideo table cleanup provider selection

Inspected BFME2 `3aba05733d`; published census index `54b83e4f69`,
2026-10-28 09:35. The verified BFME1 freshness stamp remains current at
`e74410b3738a2bb75d626085d9ebfd3406a43ff7`.

The default picker selected WindowVideoHashtableDtor.cpp (134 authored
bytes). Current-object inspection reproduced its wrong-selected destructor,
so this is a link repair rather than a stale census lead. The prior
[map identity repair](window-video-map-link-20261024.md) and
[marker cleanup](window-video-debt-cleanup-20261026.md) remain intact.

## Cause and change

The census holds two copies of the WindowVideo hashtable destructor:

| Provider | Digest | Retail verdict |
| --- | --- | --- |
| window_video_manager.cpp, link position 3974 | 55938eed95e5 | wrong |
| WindowVideoHashtableDtor.cpp, link position 5014 | 1293f1039488 | retail |

No selected-holder exception overrides that order. The manager also emits
a competing clear copy. Its allocation policy must stay visible to preserve
the matched resize/insert bodies, as the earlier repair documents.

Declare just the table destructor and clear specializations in the manager;
their existing verified owner supplies RVA 0x0053F378 (57 bytes) and
0x001DBCDC (72 bytes). No template identity, row, address or pin changes.
The nested hash type is private in the existing shim. The first compile
refused access (C2248); the final source uses the same include-scoped access
exposure already used by Rva0041EC10Clear.cpp and Rva0041E9A4.cpp.
The shared header remains unchanged.

The before/after object comparison removes exactly those two external
COMDATs, adds none, and preserves all 112 remaining external COMDAT
byte-and-relocation digests. The exclusive symbol sets are equal. The only
new undefined symbols are those two cleanup methods; none disappear.

## Checks

- Normal byte verification: manager 40/40, cleanup owner 3/3. Both also pass
  `link_check.py --prepare-current` with strict reusable receipts.
- Frozen-file checks pass; class gate passes; manager data findings: zero.
- Both units' eight EH graphs are EXACT; compiler-label renumbering resolves
  through verified parent EH data without changing ledger labels.
- Before: both units fail the ordinary paired preview. After: both LINKS,
  with 2,206 and 134 authored bytes respectively.
- The index's per-object consumer names identify two more affected units:
  Rva0021237EAudioEvents.cpp and Rva001D92C0Dtor.cpp. The four-unit current
  preview passes 4/4 and retains those consumers' existing 842 and 331 bytes.
  All eleven EH graphs across this cohort are EXACT.
- Two unreferenced allocator/delete-node codegen diagnostics remain. They
  are not blockers in this preview and their emitted digests are unchanged.

Identity retirement was also checked through `repair_queue.py retire
identity`. It refuses because 22 ledger objects are missing, 280 providers
are not proven current, and existing bucket-initializer/AsciiString bindings
still have findings. Nothing is retired; all four registered keys remain.
The unchanged remaining COMDAT digests do not establish those dependencies'
semantic identity.

The index predates this change's base. Ordinary previews establish the stated
four-source scope only; the outgoing batch audit and next normal census must
check broader current selection. No headline linked-byte increase, whole-image
link, runtime result, ownership change or source-file reduction is claimed.

Post-publication audit of `46b60c2874` against parent `8c36c2edab` exits 2,
INCONCLUSIVE: the index predates the base, and affected consumer
Common/0CreateAHeroManager21FE49.cpp lacks a current receipt. The whole-batch
audit considers every symbol supplied by the edited source, a broader scope
than the four users of the two removed cleanup copies above. Carry that
consumer and the window-video cohort into the next normal census; this audit
does not establish absence of losses across that broader scope.
