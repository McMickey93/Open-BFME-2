# MetaEvent declaration cleanup and provider-index prerequisite

Inspected the original `442a92e102` inputs, then rebased through upstream
`6c583e82f0`. The unchanged merge trial completed before applying any TU merge:
19 approved rows, six clean donor files, one mixed file, no accepted merge.
Prior handoffs already document the private declarations and reference-header
conflicts. This trial used the newer 2026-10-26 19:02 index at `5ce093a71a`.

The seed was refused for unresolved
`?appendIntegerArgument@GameMessage@@QAEXH@Z` and
`?getArgument@GameMessage@@QBEPBTGameMessageArgumentType@@H@Z`.
The index still places those definitions in the removed
GameMessageIntWideArgs.cpp and GameMessageGetArgument.cpp objects. The current
ledger instead assigns both bodies to Common/MessageStream.cpp. LinkGuard
removes the obsolete objects but does not refresh their replacement provider.
This is a provider-index freshness prerequisite, not evidence of a missing
retail body. No check or index was edited to admit a merge.

The unchanged MessageStream provider freshly verifies 18/18 rows. An ordinary
preview of the six fragments remains clean at 1,389 authored bytes. Adding
the current provider also keeps the six clean, but reports duplicate
GameMessage destructor, integer/wide append and argument-access definitions
in MessageStream.cpp against the old index. That preview retains the obsolete
providers, unlike the merge guard. Neither result proves whole-image link
closure; a current coherent provider index or a separately verified guard
freshness repair is required before another merge trial.

Two declaration prerequisites are independently verified:

- Common/MetaMap.cpp uses the registered SubsystemInterface header and the
  seed's `m_metaMaps` spelling for its existing +0x0C pointer. See the separate
  canonical-base handoff. Four byte rows and one EH graph remain exact.
- MetaMapRecDtor.cpp uses the registered UnicodeString header, first in the
  include search, for the established two string words at +0x1C/+0x20. Its
  private StringBase template is removed. All three byte rows remain exact,
  including the unwind body after compiler-label renumbering. The one EH
  graph is EXACT, all six code references have correct bindings, and the
  shadow data check has zero findings. The frozen-file check passes.

No sources, rows, protected keys, pins or hatches move. The current source
changes remove duplicate private declarations; no debt retirement or linking
gain is claimed. The seed's existing TheMessageStream wrong-name finding
remains unchanged, as documented by the earlier MetaEvent handoff. The
reference-header conflicts in the lookup/debug parser donors and mixed-file
constructor still need separate work after the guard can judge the seed.

Publication audit: the complete unpublished range after rebasing onto
6c583e82f0 changes no existing source paths. There are no old-to-new source
bindings to update. Active ledgers/registers keep the same owners, and no
header/MS-header queue transfer is required. The preceding pre-push gate
verified 980 rows across 12 affected sources and nine EXACT EH graphs; its
batch-link audit was inconclusive because the index predates the outgoing
base and 11 objects lacked its required current receipts. Carry that
uncertainty into the next census; no census or smoke run was started here.
