# ParticleSys bounded consolidation, 2026-10-28

Inspected base `77405bada3`; published link index `41c28839bf` (2026-10-28 11:08 UTC).
The supported merge rebuilds the TU map in memory from current inputs and selects
`Code/GameEngine/Source/GameClient/System/ParticleSys.cpp` as the approved destination.
The applied merge accepts 52 inputs containing 98 matched rows, removing 51 source files.
This is consolidation of existing matches; it adds no recovered body or new name.

The 36 mixed sources remain separate. Of the 26 rejected whole-file donors,
25 fail to compile together and one is refused by the link guard. Reconcile
private views in independently verified prerequisite commits before another merge;
`tools/tu_views.py` is the supported next investigation. Keep the linked constructor
separate until its allocator/hashtable COMDAT selection is resolved.

## Verification and path audit

The normal build passes 98/98 rows, two string literals and five float literals;
13 EH graphs are exact and nine funclet pins verify through parent EH data after
label renumbering. The unmatched-definition, CSV and class gates pass. Strict
current receipt preparation passes. Data shadow reports zero findings; converged
data checks 11 addresses with zero second names or unjudged rows. The scoped
ordinary preview reports LINKS for 4,360 authored bytes (the seed preview was
818); the guarded merge accepts all 52 census-linked inputs. These previews do
not establish a census gain. BYTE-MATCHED remains 7,978,500 bytes / 100%,
SOURCE FILES falls from 21,562 to 21,511, and TU-APPROVED remains 43,593 rows.

Code identity remains shadow: the composed TU reports three unreferenced
CategoryWind vtable alternatenames inherited from its accepted donor. TU ownership
reports a diagnostic BfmeParticleSystemHandle/BfmeVideoTableStorage layout
fingerprint resemblance; it does not prove those classes share an identity.
No identity or data baseline key belonged to an absorbed donor. The supported
merge transfers four alternatename hatch entries with totals unchanged, refreshes
header/MS-header reports (no affected queue entry), repoints four body-owner rows
and the Doxygen input, and changes only source cells in the committed TU map.
The fresh routing map was rebuilt in memory, not committed as a regenerated map.

The path audit covers the complete outgoing move batch from origin/master at
77405bada3 through the staged tree: all 51 removed full paths and basenames were
searched together across tools, hooks, workflows, Code, docs and reverse, including
build configuration and path-keyed registries. No include or active build consumer
needs a source change. One functions.csv fold-proof note still named the absorbed
Rva001FB94FDtor.cpp; add_match --replace-existing --icf-owner repoints that proof
and byte-verifies the existing folded row at 0x001F45EF. Pins are unchanged.
All active source columns, protected registers, queue entries and fold-proof
sources now resolve to surviving owners. Remaining old mentions are source
provenance comments, the census-owned link_status snapshot, deleted-row history,
append-only name_agreed refusal detail, and archived attempt evidence; they are
retained intentionally. The blocked name_agreed record's actual source key survives.

The staged-tree link batch audit is INCONCLUSIVE: index 41c28839bf predates base
77405bada3, and 77 affected sources lack current receipts (first:
Code/GameEngine/Source/Common/BigChainBaseDtorsO1.cpp). Carry all consumers of the
moved providers and their selected COMDAT copies into the next normal census.
The audit supplies no clean batch verdict; census confirmation remains pending.

## Rejected donors

| Donor basename | First reported obstacle |
| --- | --- |
| `ParticleSystemRotateLocalTransform.cpp` | Compile C2039: 'rotateLocalTransformX' : is not a member of 'ParticleSystem' |
| `Rva001F3D03Set.cpp` | Compile C2146: syntax error : missing ';' before identifier 'lifetime' |
| `ParticleSystemRva001F45F4.cpp` | Compile C2039: 'rva001F45F4' : is not a member of 'ParticleSystem' |
| `ParticleSystemRva001F465E.cpp` | Compile C2039: 'rva001F465E' : is not a member of 'ParticleSystem' |
| `Rva001F4C67Finish.cpp` | Compile C2039: 'm_slot2' : is not a member of 'ParticleSystem' |
| `ParticleSystemManagerFindByID.cpp` | Compile C2146: syntax error : missing ';' before identifier 'vel' |
| `rva001F5923Rva001F5923Farm.cpp` | Compile C2039: 'flag98' : is not a member of 'ParticleSystem' |
| `Rva001F5BBE.cpp` | Compile C2039: 'm_idB4' : is not a member of 'ParticleSystem' |
| `CPUParticleLoadPostProcess.cpp` | Compile C2039: 'm_owner' : is not a member of 'ParticleSystem' |
| `ParticleSystemLoadPostProcessBfme2.cpp` | Compile C2039: 'loadPostProcess' : is not a member of 'ParticleSystem' |
| `ParticleSystemManagerFindTemplate.cpp` | Compile C2039: 'destroyed' : is not a member of 'ParticleSystem' |
| `CPUParticleUpdate.cpp` | Compile C2039: 'getSystemID' : is not a member of 'ParticleSystem' |
| `ParticleSystemUpdate.cpp` | Compile C2118: negative subscript |
| `ParticleSystemDestructor.cpp` | Compile C2118: negative subscript |
| `ParticleSystemConstructor.cpp` | Compile C2118: negative subscript |
| `ParticleSystemCreateParticle.cpp` | Compile C3861: 'temporary731': identifier not found, even with argument-dependent lookup |
| `RenderParticleConstructor.cpp` | Compile C2065: 'm_8c' : undeclared identifier |
| `Rva001FA584Ctor.cpp` | Compile C2600: 'Rva001FC0B6::Rva001FC0B6' : cannot define a compiler-generated special member function (must be declared in the class first) |
| `ParticleSystemManagerMappedTextureUVs.cpp` | Compile C2011: 'FXParticleSystem::ParticleSystemTemplate' : 'class' type redefinition |
| `ParticleSystemManagerNewTemplate.cpp` | Compile C2953: '_STL::pair' : template class has already been defined |
| `ParticleSystemMake001FCBD7.cpp` | Compile C2011: 'FXParticleSystem::ParticleSystemTemplate' : 'class' type redefinition |
| `Rva001FA8DDParse.cpp` | Compile C2953: 'StringBase' : template class has already been defined |
| `BigChainBaseDtors.cpp` | Compile C2504: 'Sub005CD540Outer' : base class undefined |
| `ParticleSystemRva001F4696.cpp` | Compile C2039: 'destroy' : is not a member of 'ParticleSystem' |
| `Rva001FA440Ctor.cpp` | Link guard: census-linked constructor loses selected allocator/hashtable COMDATs in the merged object. |
| `Rva001FB201DoXfer.cpp` | Compile C2011: 'FXParticleSystem::ParticleSystemInfo' : 'class' type redefinition |
