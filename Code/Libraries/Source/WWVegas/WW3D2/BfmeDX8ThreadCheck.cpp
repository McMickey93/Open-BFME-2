// cl: /O2 /arch:SSE /G7 /MD /DNDEBUG /Ireference/shims/bfme2_thread /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib
#include "thread.h"
// Full retail 0x0011F500..0x0011F51F; the 6-byte row at 0x0011F519
// is the shared true arm reached by two conditional jumps.
extern volatile unsigned long bfmeDX8DeviceOwner;
extern volatile int bfmeDX8DeviceRecursion;
int Rva0011F500() {
 if(ThreadClass::_Get_Current_Thread_ID()==bfmeDX8DeviceOwner || bfmeDX8DeviceRecursion==0)
  return 1;
 return 0;
}
