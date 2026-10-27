# RAMFile reader standard-header adoption

Inspected BFME 2 revision `48cba50b7d` on 2026-10-27. Source:
`Code/GameEngine/Source/Common/System/RAMFileRead.cpp`.

Replace seven local Microsoft-header definitions/declarations (`NULL`, `memcpy`,
`isspace`, `atoi`, `atof`, array new and array delete) with `<string.h>`,
`<ctype.h>`, `<stdlib.h>` and `<new>`. These headers supply NULL without adding
the Windows SDK. Compiler flags and game declarations are unchanged.

Verification before and after the edit:

- Ordinary `./build.sh` passes all 14 matched rows, four empty-string references
  and all three named imports. `memcpy` keeps its direct `_memcpy` reference;
  the scanner/number conversions keep `__imp__isspace`, `__imp__atoi` and
  `__imp__atof`. Array allocation and deletion keep their existing externals.
- `find_declared_unmatched.py` passes with the same existing
  convertToRAMFile exemption. No marker, pin, class or row was added.
- `eh_verify.py` reports both exception graphs EXACT. The two already-renumbered
  funclet labels are resolved from those exact parent graphs by the byte gate;
  no funclet ledger rewrite is needed.
- Complete COFF comparison normalizes TU-local relocation targets by section
  and offset, excluding debug records. All 22 non-debug sections other than
  `.drectve` preserve their 1,339 bytes, 44 relocations, flags and external
  definitions. Undefined external names are identical. The sole directive
  difference is the standard `<new>` header prepending
  `/DEFAULTLIB:"msvcprt"`; the project linker uses `/NODEFAULTLIB`.
- The owning Microsoft-header scanner reports zero local occurrences and zero
  include-closure findings. Its `refresh_queue` operation removes only this
  source's row, preserving unrelated queue entries. `check_csv.py` passes.

Local comparison objects are in `build/ms-headers-ramfile-20261027/`.
This is source/header cleanup and one structural queue item retired. No census,
linked-byte or image-ownership change is claimed.

The independently picked requestPath logging declaration could not adopt CRT
headers: see [the prerequisite handoff](request-path-ms-header-prerequisite-20261027-codexb4.md).
