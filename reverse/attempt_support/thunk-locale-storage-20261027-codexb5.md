# Thunk data identity: locale index correction and remaining boundaries

Inspected BFME2 `9ac97a4584`; published ordinary-preview index `bf3dd31211`
(2026-10-27 00:39). This is data cleanup, with no census or debt retirement.

## Retained correction

At data RVA `0x00A06665`, the committed heuristic data index still named
`?g_00E06665@@3IA`, an undefined unsigned-int spelling. The existing definition
in `Common/Rva007AB81ACtorInits_Rva007ACC20.cpp` is instead `unsigned char`,
COFF `?g_00E06665@@3EA`. Its initializer `0x007B4C38` and the cleanup thunk
`0x007B9806` in `Common/Rva007B6880Thunks.cpp` both bind that symbol to the
same native address. The constructor and destructor are the existing
STLport `ios_base::_Loc_init` providers. No original BFME2 variable name or
original owning TU is established here.

Refresh only this address from `tools/data_ledger.py`'s scratch output. The
generator reports 13 matched sources without objects, so its unrelated rows
are not substituted. The retained row records the existing char symbol and
its defining source, one definition and two references. The heuristic extent
of three bytes is unchanged; it is not a verified sizeof claim.

Normal builds pass 6/6 initializer-source rows and 909/909 thunk-source rows.
The initializer source has no data findings. The thunk source's findings fall
from 13 to 12, and findings outside its register fall from four to three.
The locale wrong-name finding is gone. No source code or hatch was changed.

## Rejected trials and prerequisites

A trial explicit one-byte data row for the char sentry passed its normal
source-scoped data-byte verification. CSV integrity correctly refused it:
the preceding `?g_00E06664@@3IA` row in the thunk source claims four bytes
starting at `0x00A06664`. The trial row was removed. Recover the preceding
`ios_base::Init` sentry's actual storage type and update all its declarations
and its data row together before registering the adjacent locale sentry.
Do not overlap the existing row or shrink its extent without changing its
four-byte C++ definition and verifying the replacement type.

Three other thunk consumers bind competing symbols at data RVAs
`0x009FE358`, `0x00A02310` and `0x00A04424`. Existing explicit data rows
select the `g_Va...` storage owners. Trial consumer rebinding preserved all
909 code rows, but `hatch_counters.py --update` correctly refused three new
address-global token keys. The trial source and its provisional 37-key
retirement were restored. These repairs need supported admission or recovery
of real storage identities; no manual hatch admission was performed. The
final data baseline is unchanged.

The selected category-6 reference-slot debt also remains. Startup bodies
`0x007B3EB4` and `0x007B3EBF` store addresses of `DefaultModuleKey<6>::VALUE`
and `DefaultModuleName<6>::VALUE` into placeholder globals. Existing real
owners in `GameClient/FXParticleSystemModules.cpp` declare
`DefaultModuleTag<6>::s_key` and `s_name` as static references. Taking the
address of either reference in C++ addresses its referent, not the reference
slot. Recover the compiler-generated reference initialization and approved TU
ownership before removing those duplicate definitions; an unsigned-int alias
of a mangled reference slot is not an established C++ declaration.

The ordinary thunk link preview has the same sole reported unresolved symbol
before and after: `?g_lgaKeyRecords@@3PAIA`. Its own 9,050 code bytes do not
preview as linked in this retained index. No linking improvement is claimed.

The three random-seed consumer leads were also checked without edits. Their
owner in `GameLogicRandomInit.cpp` still declares `theGameLogicSeed` static;
the earlier consolidation prerequisite remains. Their temporary scope claims
were released without repeating an extern trial.
