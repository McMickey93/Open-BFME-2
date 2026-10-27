# AptOptions destructor: use the CRT free declaration

## Scope and callee identity

Target: AptOptions::~AptOptions at RVA 0x00518769, 297 bytes, in
Code/GameEngine/Source/Common/Rva00518769Dtor.cpp. The whole translation unit,
its deleting destructor and five unwind funclets are part of verification.
The initial local trial used BFME 2 base
69fe964ceac1befa94d9f5aaf17023a21d7ef745; the native completion workflow
records the current official parent actually qualified.

The intended C _free provider is the game's 17-byte wrapper at RVA 0x00030830
(VA 0x00430830), in Common/System/GameMemoryFree.cpp:
it forwards to __gameMemFreePtr(block, 3).
The CRT IAT entry at 0x00BBA6E8 is not this target.
Consumer and provider are verified together; no pin or alias is added.

## Minimal measured compiler context

Replace the local C++ free(void *) prototype with <stdlib.h>.
The existing /MD /EHsc context also requires /D_CRTIMP= and /EHc- after
/EHsc. Disabling _CRTIMP prevents an imported CRT call; /EHc- preserves the
exception visibility and state graph after free acquires C linkage.

Header plus _CRTIMP alone failed the parent and was reverted. The combined
settings pass all nine consumer/provider rows and the complete EH graph
under native MSVC 7.1. The normal verifier resolves five renumbered unwind
labels from parent data; no handwritten funclet pin is needed.
See also ai-countmap-native-lifecycle-seat2-20261023.md for the prior mechanism.

## Header and whole-file checks

The completed local SDK audit indexed 954 headers and 223,083 names.
Before the edit the file was classified conflicting, including the local
C++ free versus the header's C declaration. Afterwards it was clean and
had no local free occurrence. The native completion workflow rebuilds the
index and repeats show/check, declared-body, byte and EH verification.

The actual game Shell class and forward declaration remain: their collision
with an SDK typedef is not evidence that the game class should be replaced.
No reconstruction body changes, new C++ coverage or debt-register retirement
are claimed. This is declaration and ABI cleanup, +0 new C++ bytes.

Autonomous implementation and measurements: OpenAI Codex.

## Source-only completion after the blocked reference refresh

The completion uses official BFME 2 base
5d04574add898b9f3ea362bd0c62cad593f805ad and retains its canonical
reference/open-bfme-1 pointer, 4fa9d591641a743b86f2320343b7a276585b814b.
The current unmodified consumer/provider baseline passes all nine rows.

The separate refresh to BFME 1 e74410b3738a2bb75d626085d9ebfd3406a43ff7
passed complete comparative gates, but integration run 40439315444 stopped
at the ordinary cross-source DIR32 check. It found the existing
??_7Rva001F376E@@6B@ symbol at bases 0xBBB554 and 0xBE15B4 after rebasing
onto newer upstream work. No exception or verifier change is justified here.
The refresh commits and their native objects remain banked in that run's
artifacts; they are not part of this source-only patch. No successful
freshness stamp for the blocked refresh is claimed.

This smaller contribution changes only this consumer, its measured recipe
and this evidence. Normal scoped builds, EH/header checks and commit/push
hooks qualify it against the retained project inputs. It does not establish
that unrelated global DIR32 debt or runtime smoke checks are clean.
