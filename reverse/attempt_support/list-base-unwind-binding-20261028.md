# Existing list-base unwind binding in Rva005262BFDtor.cpp

Inspected after `323ec3aef5` (CRT declaration cleanup). Its commit hook
reported a shadow code-identity binding, despite 11/11 matched rows across
the four edited sources and an EXACT parent EH graph for this source.
This finding remains unresolved; the byte and EH results do not certify
the linked callee's identity.

Target facts:

- `uw_00796887` is an existing 11-byte row in
  `Code/GameEngine/Source/Common/Rva005262BFDtor.cpp`, with parent
  `??1Rva005262BF@@QAE@XZ` at 0x005262BF. Its ledger notes retain
  `object-symbol=$L337`; the newly compiled physical label is `$L708`.
  The verifier resolves that renumbering through the parent's EH graph.
- Retail 0x00796887 is `mov ecx,[ebp-0x10]; add ecx,0x10; jmp
  0x00200667`. Retail 0x00200667 is the complete five-byte tail jump to
  0x004EC395. The latter is a separate 23-byte list-base destructor.
- The current object's `$L708` has bytes `8b4df083c110e900000000` and
  one REL32 at offset 7 naming
  `??1?$_List_base@HV?$allocator@H@_STL@@@_STL@@QAE@XZ`.
  That name's own ledger row is at 0x004EC395, not 0x00200667.
- The hook reports this reference as `divergent` at 0x00200667. There
  is no corresponding key in `reverse/code_identity_baseline.tsv`;
  its current mode is shadow. No baseline or exemption was added.
- The parent class, its two `_List_base<int, allocator<int> >` members
  and the external destructor declaration are unchanged from
  `323ec3aef5^`. The cleanup replaced only the local `free` prototype,
  added the CRT include/flag and corrected the parent size comment.
  This inspection did not rebuild the historical source.

Structural inference: retail's unwind edge goes through a complete-list
destructor thunk while this reconstruction names the base destructor.
Replacing member lifetime views may recover that distinction, but must
also preserve the parent's direct base-destructor calls and all emitted
COMDAT providers. Do not pin a second address onto the existing real
list-base name or treat EH placement as a proof of that binding.

Follow-up: reconcile the member types in a separate source repair, then
verify the full parent, both unwind actions, emitted helper providers and
affected consumers. The label-renumbering mechanism itself is not shown
to be defective. No linking or runtime gain is claimed here.
