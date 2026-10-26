# AIUpdate const tree lookup identity, 2026-10-26 (codex5)

The default picker selected the existing AIUpdate.cpp unit. This repair scope
is its registered map-to-tree lookup binding, independent of the disputed
TU placement recorded in LINK-062. The file claim covers the source; the
picker also claimed 0x00142C90. The frozen-file check accepts the existing
eight matched rows (241 bytes) and 64 annotated unclaimed definitions.

## Before the change

At BFME 2 `e1ecb55890879407f363b5f925f868b922eef3bc`, the current-object
identity scan reports nine references and one wrong binding (`wrong/extent`).
The const locomotor-map find wrapper at 0x00759B20, 22 bytes, calls its
const `_Rb_tree::find<LocomotorSetType>` at offset 12; retail's REL32 target
is 0x00759410. That symbol already appears in reverse/symbols.csv at this
address. Its sole indexed definition is the wrong copy emitted by AIUpdate.cpp.
The registered debt calls the binding `divergent`; its current classification
has become `wrong/extent`, so merely deleting that old key is not a repair.

The target's matched owner is the 71-byte tree lookup emitted by
Code/Libraries/Source/WWVegas/WW3D2/HashMapPeekValue.cpp. This is a retail
target/provider fact, not proof that the two source-level tree types have
the same original name. An undefined reference can become an alias candidate
in the identity tool; that classification alone would not supply a working
linker binding. This investigation admits no alias or pin.

The ordinary preview against census index `d1f046749a` (2026-10-26 13:18)
reports 17 unresolved, six COMDAT and five selected-definition blockers,
LINKED 0 -> 0 bytes. These are not fresh census figures. Scratch before
evidence is build/codex5-aiupdate-identity-before.{log,tsv}.

## Target and compiler evidence

The retail lookup occupies 0x00759410..0x00759457 (71 bytes, RET 8).
It loads the header through receiver offset zero, root at header+4,
left/right children at node+8/+12 and the key at node+16. Its comparisons
use JB and JAE, so the lookup compares unsigned keys. This establishes the
comparison domain of this helper, not the original locomotor enum definition.
The donor enum includes INVALID=-1 and its ordinary less<> is signed.

Reading the original compiled callee gives 70 bytes without relocations:
JL/JGE comparisons and a conditional ESI save/restore inside the nonempty
tree path. Retail saves ESI before EDI in the common prologue. The native
unsigned comparison and the register-save placement are separate differences.
The original object is preserved locally as build/codex5-aiupdate-before.obj.

## Bounded trials, all discarded

1. Explicit declaration-only specialization of const tree find: VC7.1 C1001
   in vendor/stlport/stl/_map.h:196 (Utc P2 main.c:148). An extern-template
   declaration reproduces the same failure. This agrees with the earlier
   MapUtil declaration-only failure in map-find-link-20261018/evidence.md.
2. Expand the vendor _M_find walk inside the outlined find specialization:
   the normal gate passes all eight rows, but the callee remains the original
   signed 70-byte body. Casting each compared key to unsigned int corrects
   the branch conditions, still at 70 bytes with the conditional ESI save.
3. Define that unsigned specialization inside the existing size-optimization
   region around privateGoProne, without adding a pragma: all eight rows pass,
   but the helper is 62 bytes, with a shared result epilogue. Not retail.
4. Keep the unsigned body at the original optimization state and remove /G7
   from the TU flags: the isolated helper comparison returns exact 71 bytes,
   with no relocations. The normal gate refuses vector<const LocomotorTemplate
   *>::empty at 0x00142C90: retail is 13 bytes, the trial is 11. No file-wide
   flag change is accepted. Scratch source is
   build/codex5-aiupdate-unsigned-default-cpu.cpp; this is not a verified TU.
5. Specialize the const map wrapper to call the existing integer-tree owner,
   adapting the one-pointer iterator return ABI through a typed member-function
   pointer: C1001 in the wrapper. Adding noinline to the owner's declaration
   still fails. A normal call followed by conversion of the returned node to
   the locomotor const_iterator also produces C1001. No alias is added.

The trial logs are build/codex5-aiupdate-{extern-template,expanded-find,
unsigned-find,sized-find,default-cpu-find,owner-call-typed,
owner-call-noinline,owner-result-typed}.log. A short comparison was made after
each completed compile; failed compiles supply no new current object evidence.
Only trial 4's helper matched retail, and its enclosing TU failed verification.

## Handoff

AIUpdate.cpp is restored byte for byte to its committed source. No source,
ledger, baseline, pin, hatch or TU-routing change is retained. The registered
identity debt remains. The next lever must preserve the existing G7 vector
row while either producing the retail lookup or binding its existing owner
without the declaration-only return-template compiler failure. Repeating the
forms above, or removing /G7 across this mixed unit, does not satisfy that.
The disputed TU approval in LINK-062 remains an independent prerequisite.

After restoration the normal gate passes eight of eight rows, its one string
reference and all float/import checks. The frozen-file check again reports
eight matched rows and 64 annotated unclaimed definitions. eh_verify reports
one EXACT graph, no baseline or missing object. The fresh identity scan retains
the same single wrong/extent binding; the current-object link preview against
d1f046749a again reports 17 unresolved, six COMDAT, five selected and zero
linked bytes. No compiler attempt remains under Code/.
