# Shader shutdown data-identity retirement

Inspected `bdf391b638` on 2026-10-27 under the picker's file claim for
`Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DShaderManagerShutdown.cpp`.
The ten registered findings name old declarations already replaced in source.
The earlier attempt at this retirement (`reverse/re_attempts.log`, symbol
`?W3DShaders@@3PAPAVShaderInterface@@A`) requested provider definitions first.
Those definitions now exist in W3DShaderManager.cpp, so the prerequisite was
rechecked rather than assuming the earlier verdict still applied.

`find_declared_unmatched.py` reports all defined functions matched.
`./build.sh Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DShaderManagerShutdown.cpp`
passes all four rows, including its EH handler and funclet. The object is
current. `repair_queue.py retire data` refuses with two findings outside the
register and changes nothing:

- `?W3DShaders@@3PAPAVShaderInterface@@A` at RVA `0x009E1F24`.
- `?m_currentFilter@W3DShaderManager@@1HA` at RVA `0x009E1F5C`.

The first address is still indexed in data_ledger.csv under
`?g_00DE1F24@@3RCRAUShaderSlotObj@@C`, with no source. The actual two-entry
W3DShaders definition is in W3DShaderManager.cpp, whose constructor clears
both entries; the shutdown source describes the native operand/end-address
evidence for that bound. There is no explicit data_rows.csv owner at this
address. Reconcile the index with a verified definition and ownership evidence.

The second address has an explicit matched data_rows.csv owner:
`?g_00DE1F5C@@3HA` in `Code/GameEngine/Source/Common/Rva000756BFSelect.cpp`.
That file defines and writes the integer, while W3DShaderManager.cpp separately
defines m_currentFilter. This is a provider identity conflict requiring one
global and consistently typed references, with the existing data row kept or
properly transferred. Merely noticing the new provider definition is
insufficient. Do not add a baseline exception or another binding for the slot.

The originally selected texture-slot key at `0x009E1F8C` is already resolved
through the explicit g_shaderTextureSlots data row owned by
W3DShroudMaterialPass.cpp. The remaining old names likewise no longer appear
in the source, but the owning retirement tool correctly keeps all ten keys
until the two new findings are resolved. No source, register, index or data
row was changed; no linking or debt reduction is claimed.

Rechecked at `344e3c3b1e`: all four byte rows still pass, and the owning
retirement tool still reports precisely the two conflicts above. The data
register remains unchanged.
