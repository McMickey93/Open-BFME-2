# Resize record provider repair

Inspected BFME 2 `2eea4ae57b` on 2026-10-27. Ordinary preview index:
`bf3dd31211`, 2026-10-27 00:39, retail-truth-4. Claimed resize RVA
0x00215A8D and file scope before editing.

## Target facts and change

The 100-byte resize calls range erase 0x002157DB, fill insert 0x00215949
and record destruction 0x002154BE. Existing matched owners are respectively
`vector<BfmeVectorRecord0002154F3>::erase`,
`vector<Rva00215949Element>::_M_fill_insert` and
`BfmeVectorRecord0002154F3::~BfmeVectorRecord0002154F3`.
The record copy 0x002154F3 and destructor 0x002154BE establish ownership of
an AsciiString and vector<AsciiString>, rather than the donor's undefined
`BfmeStrERE` and `BfmeSubERE` operations. These facts establish storage and
operation compatibility; they do not recover the record's application name.

BfmeConv1950.cpp now uses those members and explicitly declares the kept
string-vector cleanup specializations. Direct calls through the existing
provider types replace the two donor-only vector helper declarations.
No pin, alias directive, row, source path or shared header was added or moved.
The by-value resize symbol remains unchanged for its existing caller.

BFME 1's pinned `e74410b3738a2bb75d626085d9ebfd3406a43ff7` copy was reviewed:
it retains the same unresolved donor helper declarations and provides no
applicable linking repair. The retail targets and existing BFME 2 owners
support this repair independently.

## Verification

- Before and after `./build.sh Code/GameEngine/Source/Common/BfmeConv1950.cpp`:
  all 3 rows exact (100-byte parent, 10-byte handler, 8-byte funclet).
  The final compiler funclet label is $L5542; the unchanged ledger's $L369
  is resolved through verified parent EH data.
- `find_declared_unmatched.py`: all defined functions already matched.
- `eh_verify.py`: 1 EXACT graph, zero nonexact, zero missing objects.
- `data_check.py`: zero shadow findings.
- `repair_queue.py retire identity`: 1 key retired, zero remaining findings.
  Its initial freshness refusals were resolved with normal byte builds of
  W3DModelDraw.cpp (6/6 rows) and GroupOrderCtor.cpp (1/1), then the same
  retirement command succeeded. No check was bypassed or weakened.
- Before ordinary preview: U4, naming `BfmeSubERE::~BfmeSubERE`,
  `BfmeStrERE::releaseBuffer`, and both BfmeVecERE vector helpers.
  After: LINKS, 0 -> 100 authored bytes.
- Paired ordinary preview: resize, stlport_vector_record_2154f3_allocate_copy.cpp
  and stlport_vector_record_2154f3_erase.cpp LINKS (100, 676 and 51 authored
  bytes). StlSweepW4Rva00215949.cpp stays blocked: unresolved element copy,
  destructor and assignment, plus nonretail selected `_M_insert_overflow`.
  No dependency-closure or census-linked-byte gain is claimed.

The discarded forwarding-wrapper trials changed argument evaluation and
register allocation in the parent, failing byte verification. Direct provider
calls preserve the retail push order and all 100 bytes. No failed trial remains
under Code/.

## Remaining work

Reconcile the fill-insert provider's element identity and overflow with its
existing copy/assignment/destruction owners, then recheck the complete family.
Await the normal maintainer census for this resize consumer's linking status.

Official BFME 1 master was fetched at
`9116bca34d7112fb7f5d3eafef197a1e5f6c555b`; reference refresh scope is held
by `yasinschroeder-codex4`. This seat retained the verified pin and did not
write a successful freshness stamp or launch competing full verification.
