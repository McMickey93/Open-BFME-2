// cl: /MD
// Transferred from Open-BFME-1 5cae4bdff game/GameEngine/Source/Common/SmallGaps/Rva008792A0CloseFile.cpp;
// bfme1_sweep ambiguous: byte-identical bodies placed by the BFME1->BFME2 address map at 0x006B8B40.
// Addresses in the donor text are BFME1.

#include <stdio.h>

// BFME2 retail slot 0x00BBA5DC is msvcr71!fclose (import-ref verified).
void Rva008792A0CloseFile(void *file, void **slot)
{
    fclose((FILE *)file);
    *slot = 0;
}
