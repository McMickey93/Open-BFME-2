# ThingTemplate FX-map identity prerequisites

Inspected `b986237bff16` on 2026-10-28; ordinary-preview index
`41c28839bf` (2026-10-28 11:08). Claimed the callback and its source.
No production source, ledger, pin or debt register was changed.

The default picker served the registered insert_unique binding in
`parseArbitraryFXIntoMap` (0x0033DB2F, 154 bytes). Its current C++ uses
`PerUnitFXMap` and inserts the pointer returned by `findFXList`. These
source types are donor facts; the existing byte match alone does not prove
the original retail template arguments.

Current owner facts:

- 0x0033D28A is the 151-byte insert_unique in
  `stlport_tree_asciistring_key_insert.cpp`, named with
  `NoCaseTreeValue4` and `BfmeStringNoCaseLess`.
- That source also owns its 148-byte _M_insert at 0x0033CC5E. Its comparator
  actually inlines the ordinary AsciiString operator<. Its comment explicitly
  identifies that comparator body as a structural inference.
- _M_create_node at 0x002CFA8E is in
  `stlport_rb_tree_create_node_nocase4_002CFA8E.cpp`. It calls the existing
  raw construction owner at 0x002CF954. The same placeholder tree identity
  also appears in the copy/assignment family at 0x002D0399/0x002D0867.
  A whole-token rename of the placeholder value/comparator would therefore
  assert considerably more than the callback proves.
- The source's third registered key is independent: WeaponTemplateSet's
  findBestInfoSlow binds 0x0033BE70, whose current 92-byte row names
  ArmorTemplateSet and BitFlags<11>. Do not treat a repaired FX insertion
  as proof of this separate binding.

Checks:

- `find_declared_unmatched.py` accepts the unchanged source (22 matched
  rows; existing unclaimed-definition notes remain).
- `./build.sh Code/GameEngine/Source/Common/Thing/ThingTemplate.cpp`
  passes 22/22 rows, including the parent-EH placement of the renumbered
  unwind label at 0x0077C65A.
- `repair_queue.py retire identity` refuses and changes no register. Two
  ledger objects are missing; five participating provider objects lack
  current receipts. The scan also reports six findings outside the source's
  three registered keys, including the WeaponTemplateSet tree clear binding
  and AsciiString destruction. Refreshing receipts alone cannot establish
  a clean retirement verdict.
- Ordinary `link_check.py` remains blocked, 0 -> 0 of 882 authored bytes.
  It reports the FX insert_unique and WeaponTemplateSet findBestInfoSlow
  copies, alongside existing audio, Overridable, INI and BitFlags blockers.

Next: reconcile the insert/_M_insert/allocation owner chain and its actual
callers together, preserving other tree consumers and checking their current
receipts. Recover the independent sparse-finder binding separately within
the same source scope. Retry the owning retirement only after its additional
findings are resolved. No alias, second provider identity, partial source,
register retirement, linking gain or census clearance is claimed.
