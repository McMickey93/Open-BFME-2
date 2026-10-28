# AsciiString header adoption: 28-byte vector record

Inspected the default header-queue pick at the current checkout. The source's
private AsciiString view has an implicit pointer assignment, whereas the shared
header's assignment calls StringBase<char>::set. The prior header trial recorded
at 0x00101F5C found that this changes the rowed fill and backward-copy bodies.
The current source and queue still retain that arrangement; no trial was repeated.

The record's separately rowed assignment at 0x00101EF5 uses the canonical
string assignment for both string fields. Meanwhile, the 0x00583A4F and
0x00583AA9 fill/copy helpers currently emitted from the private view use its
implicit assignment. The linking register's assigned-vector follow-up ties
0x00583A4F to a different provisional 28-byte element family. The source also
has three existing code-identity findings for its mutable construction path.
These are evidence that the helper and element identities need reconciliation;
the matching layout alone does not establish that raw pointer assignment is
correct for this string record.

Next: establish the retail element and assignment identities for the 0x00583A4F
and 0x00583AA9 users, then retype or repoint the affected owners and adopt the
header using the queue's acceptance command. No source or queue row was changed;
no header debt or linking gain is claimed.
