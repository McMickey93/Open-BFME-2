# AptString constructor prerequisite handoff, 2026-10-26 (codexb)

Family B shard 0/2 allocation lists AptString.cpp, unheld before selection.
Claimed the seed and Rva006D6D20Ctor.cpp, read the Apt parent naming packet,
and checked its currency. The current plan has 48 approved rows, nine donor
files, one mixed Common donor and no refused files. The planner's original
paths are context, not approval; its ordinary group contains the seed/find
subset and flags incomplete routing, compiler settings and private views.

The retained ordinary trial build/codexb-aptstring-repair-before-trial.txt
accepts the existing 37-row seed/find subset. It rejects the constructor with
C2614: its m_0C initializer is not a member of the selected free-list view,
whose corresponding member is m_next. The current source still has exactly
this disagreement. More deeply, the seed flattens Rva006D6D20's base and its
BfmeAptValue006DCD20 view includes string payload, while the constructor
declares the polymorphic eight-byte base and derived string payload.

Before any source edit, ./build.sh on AptString.cpp, Rva006D6D20Ctor.cpp and
AptValue/AptStringFindCallback.cpp passes 41/41 rows and 27 string references.
All three pass find_declared_unmatched.py. Saved those three verified objects
and source/object hashes in build/codexb-aptstring-base-before.json. The seed
hash is b94f7d5948e171698f7f64f24c2fc8426db8c215891f38a7f3b22e2c38b03e37.
No production source was edited and no duplicate failed build was launched.

A complete repair must reconcile the constructor, free-list allocation and
string consumers together, preserving constructor/vtable/data providers and
all call signatures. It must also use the naming lane's evidence path when
unifying the differently spelled member; this prerequisite seat does not
cast independent inferred-name votes or hand-rename the member. No alias,
overlap union, offset-store workaround or guessed base was introduced.

Recorded a blocked prerequisite verdict for the deleting-destructor row
0x006D7320 with tools/re_log.py and released both source scope claims.
Common-owned EAStringC/AptString donor prerequisites and the slice flag
boundary remain with their owners. No merge, new compatible donor, later
Luna landing, file reduction, debt retirement or recovered byte is claimed.
This evidence-only handoff adds no production path consumer; the pending
NetPacket batch still edits three production files in place.
