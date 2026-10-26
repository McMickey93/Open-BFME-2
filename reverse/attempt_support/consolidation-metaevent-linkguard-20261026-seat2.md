# MetaEvent TU link-guard handoff — 2026-10-26

Shard 2/3 allocation check passed for
`Code/GameEngine/Source/GameClient/MessageStream/MetaEvent.cpp`. The current
plan has 19 approved rows, six clean donors and one mixed donor. The unchanged
merge dry run accepted no donor. The `MetaEvent.cpp` composition is census-linked
but the trial would not link; exact unresolved symbols were
`?OurLanguage@@3W4LanguageID@@A`,
`?appendIntegerArgument@GameMessage@@QAEXH@Z`, and
`?getArgument@GameMessage@@QBEPBTGameMessageArgumentType@@H@Z`. The link guard
blocked the whole merge across the six census-linked units (Common/MetaMap,
MessageStream/MetaEvent, MetaMapFindGameMessageMetaType,
MetaMapParseMetaMap, MetaMapRecDtor, and parseDebugCommandMap). Other rejected
donors also have compiler errors recorded in the trial output; no unchanged
retry is warranted. No source, ledger, or claim changes were made.
