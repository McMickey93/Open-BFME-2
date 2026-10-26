# PlayerTemplate name-key declaration trial, 2026-10-26

Allocated destination: `Code/GameEngine/Source/Common/RTS/PlayerTemplate.cpp`.
The current RTS planner and ordinary merge dry-run retain the tree receiver
prerequisite from 07aee9b190. No actual merge or ledger move was attempted.

The lookup donor `RTS/Rva001FD4E1Find.cpp` initially reports missing
NameKeyGenerator/store declarations in composition. A seed-only trial adds
`class NameKeyGenerator;`, the existing nonvirtual store member
`bool rva001FD4E1(NameKeyType key, int *index);`, and
`const AsciiString &keyToName(NameKeyType key);` to the existing generator
view. No layout, virtual slot, flag, symbol spelling or donor body changes.

Before and after `./build.sh` over seed and lookup donor: 22/22 rows match,
including the existing EH cleanup, with three string references. Frozen-file
and class checks pass. Code identity is identical: 62 references, 45 owner,
eight alias, four fold, four EH and one pre-existing wrong/extent. Data checks
report zero findings. `build/codex4-player-key-proof.py` compares saved official
before objects with rebuilt objects: external code/data fingerprints, sizes,
exclusivity, COMDAT selections, undefined references and every row's data
binding facts remain identical.

The ordinary after dry-run still rejects the lookup donor as `compile: `
with no diagnostic text. Its accepted set remains only seed and assignment,
21 rows / 1,837 bytes. The trial therefore demonstrates no additional donor
acceptance and supplies no accepted lookup composition object for a binding
comparison. No claim that the compiler boundary cleared is made. The three
declarations were reverted to the saved seed; the inherited tree receiver
repair is retained. Official restored build and frozen checks pass again.
Do not treat blank diagnostics as evidence that a gate is incorrect.

Local receipts: `build/codex4-player-key-{before,after}-{build,identity,data}.txt`,
`build/codex4-player-key-before-{0,1}.{cpp,obj}`, after-trial/planner reports,
proof script/output and restored-build report. The lookup donor claim is
released. No new source edit, file reduction, debt retirement, recovered bytes,
census gain or downstream Luna landing results from this trial.

Publication audit covers `origin/master..HEAD` plus staged handoff/register/log.
This attempt introduces no source path change or consumer change. The previous
batch's sole new private tree header and its three verified consumers remain
as audited in the tree handoff; protected debt registers and historical EA
paths are retained. The runner holds the batch until a permitted shared push.
Keep the tree prerequisite's source/header claims and inherited unpublished
claims until that push is confirmed; release this handoff claim afterward.
