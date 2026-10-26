# MetaMap common-fragment declaration prerequisite

Inspected `442a92e102` and the fresh in-memory MetaEvent TU plan. The plan
approves Common/MetaMap.cpp's constructor, destructor and two EH companions
for GameClient/MessageStream/MetaEvent.cpp. The mixed GameClientDrawableTOC
constructor and generated funclet remain outside this change.

The common fragment included the broader subsystem shim while the destination
included the registered SubsystemInterface header. Prior trials documented a
base redefinition and the common fragment's `m_head` spelling being absent
from the seed's MetaMap. Use the registered header in the common fragment and
align the existing +0x0C pointer spelling with the seed's `m_metaMaps`.
The retail constructor/destructor already prove the 12-byte base and list
pointer placement; this changes no class layout or ledger identity.

Validation: `./build.sh` preserves all four rows, including the unwind body
whose compiler-local label changed. The frozen-file check passes, the one EH
graph is EXACT, code identity reports eight references with no wrong binding,
and the shadow data check reports zero findings. The paired six-unit ordinary
preview against the 2026-10-26 19:02 index at `5ce093a71a` keeps all six clean
and all 1,389 authored bytes. No linking gain or census change is claimed.

The other fragments' record/string and reference-header conflicts still need
their own verified reconciliation. This prerequisite moves no source paths,
rows, protected keys or hatches and does not apply a TU merge.
