# GameWindowManager consolidation, 2026-10-28

Inspected f5979062a5 with census index 2026-10-28 02:44 at 14dc3d2467.
Scope: the 21 clean donors selected for GameWindowManager.cpp by the current
in-memory TU map (70 rows, 7,912 bytes). The committed TU map was not regenerated.
The naming packet was regenerated under build/consolidation/gamewindowmanager-codexb.
Its exact original GameWindowManager.cpp path comes from WorldBuilder, not the game
image; BFME1/Zero Hour paths are donor leads, not direct target path evidence.

## Reconciliation

The initial supported merge dry run accepted no combination: duplicate enums,
UnicodeString/STL definitions, incompatible GameWindow/manager member declarations,
and byte differences remain. The tu_views dry run reported conflicting virtual
slots and a field under a vfptr; no broad class rewrite was applied.

The lone-window donor at 0x002C12DC duplicated GGM_CLOSE at namespace scope.
Move that constant into the function, and call through the seed's identical
BfmeWindowManagerSendView instead of relying on the donor's manager declaration.
This preserves target slot 58 (+0xE8) when the merge retains the shared Zero Hour
manager header (which places winSendSystemMsg earlier). The native manager's
winSetLoneWindow slot 52 and m_loneWindow offset +0x2C remain intact.
The now-unused private winSendSystemMsg declaration and padding slots are removed.
No new function body, global identity, pin or escape hatch is introduced.

## Verification

Before reconciliation, ./build.sh verified all 70 rows across the 21 donors.
After reconciliation, the seed and lone-window donor pass 7/7 rows together,
and both find_declared_unmatched checks are clean. The donor's entire COMDAT
bytes and relocation identities, defined externals and undefined externals
are unchanged against the saved pre-edit object. Ordinary link_check previews
both sources LINKS (319 and 51 own bytes); these are predictions, not a census.
The initial scope data_check found no findings; code identity remains shadow,
with the pre-existing divergent list-base funclet in Rva002C5398Dtor.cpp untouched.
The lone-window donor owns no debt-register, header-queue or hatch entries.

## Native manager field prerequisite

The full retry after the enum/dispatch prerequisite still accepted no merge:
the lone-window donor progressed from a declaration error to a byte mismatch.
The composed scratch object f9e565856d5f7c7c.obj read and wrote [esi+0x28],
where the unchanged 51-byte matched donor reads and writes [esi+0x2C]. The
slot-58 call remained correct. This is target object evidence of a field-offset
difference, rather than evidence that the Zero Hour header is a BFME layout.

Extend the existing BfmeWindowManagerSendView in both files with padding from
+4 through +0x2B and m_loneWindow at +0x2C. Access that field through the view,
and remove the donor manager's now-unused private field/padding. This keeps
the shared header unchanged and makes the declaration identical in both files.
No assertion about an original target view/type name is made.

Verification: ./build.sh again passes all seven rows; the complete COMDAT sets,
bytes, relocation identities, defined and undefined externals of BOTH objects
are identical to the pre-edit snapshots. Both frozen-file checks remain clean.
A read-only pair probe through tu_skeleton.compose and tu_skeleton.Verifier
(using its scratch try_compile_source, not build.compile_source) matches 7/7
rows under union-first; LinkGuard.prepare returns None and judge returns [].
This probe preceded the full tool run described below.

## Applied merge

After the two separate prerequisite commits, tools/tu_skeleton.py --merge
accepted GameWindowManager.cpp and GameWindowManager_winSetLoneWindow.cpp:
seven rows, 370 bytes. Its census-linked donor guard passed. The tool deleted
the donor and repointed its 0x002C12DC row in functions.csv and the source column
of tu_map.csv; no TU assignment, approval, name, extent or address changed.
The committed map was not regenerated. The old pointer comment now refers to
the body in this TU; the tool's historical donor-path comment is preserved.

The absorbed donor has no code/data identity debt, header queue, Microsoft
header queue, flag override or hatch entries to transfer or retire. The seed
retains the sole TheWindowManager definition at VA 0x00DFEF1C, its data row and
data-ledger owner. The three Microsoft-header queue entries belong to rejected
donors and remain unchanged. No debt retirement or hatch reduction is claimed.

Final ./build.sh verification passes 70/70 rows across the 20 surviving sources,
the data row, ten EH-label bindings and 13 string literals. Frozen-file,
check_csv, allowed_symbols and data_check pass. Code identity remains shadow
with only the same pre-existing divergent list-base funclet noted above.
The merged object's 546 COMDAT names, bytes and relocation identities exactly
equal the saved pair's union. No definitions or external dependencies were
added or lost. Thus the moved provider and its call bindings are preserved;
the full tool's LinkGuard also accepted the composition.

progress.py reports SOURCE FILES 22,027 (-1 against the current HEAD's 22,028),
with BYTE-MATCHED 100% and TU-APPROVED unchanged. Other workers' intervening
changes explain the difference from the initial scope's source count. The new
TU previews LINKS for all 370 own bytes against index 2026-10-28 02:44 at
14dc3d2467. The preview's 151-to-370 comparison includes older seed additions
and is not a linked-byte gain attributable to this merge or a census result.

## Outgoing batch audit

Audited origin/master a6874d8a6a through c84bb75ef8 plus the staged merge. The
only removed path in the whole pending batch is the lone-window donor. One
combined search of tracked full paths and basenames found no active tooling,
hook, workflow, include or build-config consumer requiring an edit. Remaining
mentions are the tool's historical donor comment, this handoff and the old
reverse/link_status.csv census snapshot; that snapshot stays measurement-owned.
The supported repointing changed only functions.csv and tu_map.csv's source
column. Protected registers, header queues, fold proofs and the global's owner
need no additional transfer; the merge refreshed the destination header scans.

link_batch_audit.py ran against that base and the staged tree d1b5b7132b with
all 20 byte-verified scope sources. It returned INCONCLUSIVE (exit 2): its
14dc3d2467 index predates the outgoing base and lacks per-object consumer names.
The direct composition guard and complete pair-object comparison pass, but the
batch-wide selected-provider/unchanged-consumer audit is unverified. Carry this
case into the next ordinary census; neither a clean batch audit nor a census
link gain is claimed. No maintainer-only measurement or smoke job was started.

## Remaining work

The full trial rejected the other 19 clean donors. Sixteen still fail to
compile alongside the seed: duplicate enums, UnicodeString/STL definitions,
missing or incompatible GameWindow/manager declarations (including slot0,
native link fields and winCreate's overload). linkWindow, winDestroyAll and
winPrevTab compile in a trial but fail byte comparison. Reconcile each donor
in its own verified prerequisite before retrying; the trial is not evidence
that their layouts or donor names are correct. Twelve mixed files remain
outside this merge. LINK-075's previous repair still awaits census confirmation.
No runtime, image-ownership or new linked-byte measurement is claimed.
