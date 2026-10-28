# ScriptEngine / environment boundary: no approved TU anchor

Inspected `f66c63b330` on 2026-10-28. The default picker claimed the
0x0020D451..0x0020D6F5 no-signal run: nine ordinary code rows in six
sources, between ScriptEngine.cpp (0x0020D065, Z) and the proposed
LargeGroupAudio.cpp boundary (0x0020D7A6, K).

`tools/tu_evidence.py --source
Code/GameEngine/Source/GameLogic/ScriptEngine/Rva0020D451Guarded.cpp`
produces its CSV header only: no current layout signal reaches that source.
`tools/tu_map.py --dir` for the same source rebuilds current inputs and reports
one `code/none` row and zero approved TUs. No map was written or committed.
The frozen-file check passes for all six claimed sources.

Target facts: `wb_show.py 0x0020D451` pairs the 140-byte guarded action runner
with unnamed WB 0x00B3CE90 (261 bytes), score 3, callgraph. That body saves and
restores team/player state and calls executeActions, but supplies neither a
self-asserted function name nor a source path. These semantics alone do not
prove the original method name or its retail TU.

`wb_show.py 0x0020D6F5` pairs the 177-byte parser with WB 0x00B4F600,
iniParseEnvironmentSkyboxTextureDefinition, INIEnvironment.cpp:45, score 1,
callgraph. This is already cited in the source and ledger. The TU mapper's
`wb_self()` explicitly excludes a WB-cited row from corroborating its own
naming hint. Reusing this lead as an independent anchor would be circular.
The constructor at 0x0020D4E3 and container workers have existing placeholder
owners; there is no uncovered function to restore here.

Donor facts: BFME 1's reconstructed INISkyboxTextureSet.cpp is a semantic lead,
already documented by the target parser. Its path does not establish BFME 2's
translation unit. No donor name or grouping was admitted from it.

Next useful work needs an independent game __FILE__ reference, a uniquely
verified donor placement with a provable real name, or another independently
anchored row that brackets this run. Keep the current owners and placeholders
until that evidence exists. No source, name, row, pin or register was changed;
no approval, consolidation or coverage gain is claimed.
