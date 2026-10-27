# GameLOD index getters: 0x00202C30 is likely mislabeled (handoff, 2026-10-21)

Status: unresolved by decision. Hans (2026-10-21 17:33 PT) declined a rename
rule for the getters, so both keep their names. Do not cite
`GameLODManager::getStaticGameLODIndex` at 0x00202C30 as evidence of anything.

## Claim

0x00202C30, rowed `?getStaticGameLODIndex@GameLODManager@@QAEHVAsciiString@@@Z`
(Code/GameEngine/Source/Common/GameLODManagerGetStaticGameLODIndex.cpp), is
most likely the *dynamic* index getter (`getDynamicGameLODIndex` in ZH/BFME1),
and the address-named 0x00202B6C (`Rva00202B6C::rva00202B6C`,
Code/GameEngine/Source/Common/Rva00202B6CGet.cpp) the *static* one.

## Evidence

- Retail block registrations (reverse/ini_blocks.tsv): token
  `DynamicGameLOD` -> 0x00202F05, token `StaticGameLOD` -> 0x00202BB2.
- 0x00202F05 calls 0x00202C30 and writes 16-byte records at
  TheGameLODManager + 0x1C8 + index*16 through retail table 0x007E3478
  (MinimumFPS, ParticleSkipMask, DebrisSkipMask, SlowDeathScale at 0x0..0xC):
  the dynamic LOD fields (ZH TheDynamicGameLODFieldParseTable).
- 0x00202C30's name table has 5 entries, VeryLow, Low, Medium, High,
  VeryHigh: exactly BFME1 GameLOD.cpp DynamicGameLODNames.
- 0x00202BB2 calls 0x00202B6C and writes 0x4C-byte records at
  TheGameLODManager + index*0x4C through table 0x007E3308 (ModelLOD ..
  MinParticleSkipPriority, 23 rows ending at offset 0x48): static fields.
  6 * 0x4C = 0x1C8, where the dynamic records begin.
- 0x00202B6C's table has 6 entries including Custom; in ZH only the static
  levels have Custom. INI::parseLODPreset (0x00202E23) also calls 0x00202B6C,
  as ZH's parseLODPreset calls getStaticGameLODIndex.
- Neither body matches a ZH or BFME1 compiled body (zh/bfme1 sweeps), so no
  existing canonical kind can rename them.

## What would settle it

A sanctioned basis for the getters (for example a narrow rule naming the sole
index getter a contradicted, renamed block callback calls). Until then leave
both names; the parse callbacks themselves are renamed by canonical:iniblock.
