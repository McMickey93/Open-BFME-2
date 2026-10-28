# STLport 4.6 (vendored, pristine)

STLport 4.6 (`_STLPORT_VERSION 0x460`, October 2003), held beside the project's
4.5.3 headers (vendor/stlport). This is the release retail BFME 2 linked; the
evidence is below. Nothing compiles against it by default: a unit opts in with
an exact `// stlport46` line (tools/stlport_overlay.py), and no plain
`// stlport` unit sees it.

Source: https://sourceforge.net/projects/stlport/files/STLport%20archive/STLport%204/STLport-4.6.tar.gz
(the official STLport archive on SourceForge; the tarball's gzip header dates it
2003-10-31).

SHA256 of the archive: 744dd31ac34246bdba4ef50f79b4d936c842a3e4f13915a86cc06f7c7cf84f60

Contents: `stlport/` (headers) and `src/` (the compiled library: iostreams,
locale, facets, strings, and upstream's makefiles), plus the release `README`,
which carries the license. `doc/`, `etc/` and `test/` were not copied. Files are
byte-identical to the archive (LF line endings, as shipped, including the two
`stlport/config/*.h.orig` files the release carries). `SHA256SUMS` records each
of the 531 payload files; it and this file are the only non-upstream files.

License: STLport license (permissive, BSD-style; HP, SGI, Moscow Center for
SPARC Technology, Boris Fomitchev): use, copy, modify and distribute with the
notices retained and modified copies marked as modified. See `README`.

Modifications: none. Keep it that way: an edit here is no longer the 4.6
reference. Retail-demanded deviations belong in the opt-in patch layer
`vendor/stlport-4.6-bfme/` (applied into build/, never here), each with its
evidence.

## Which 4.6.x retail used (2026-10-28)

Archives fetched from the official SourceForge folder "STLport archive/STLport 4":

| release | archive SHA256 | gzip date |
| --- | --- | --- |
| 4.6   | 744dd31ac34246bdba4ef50f79b4d936c842a3e4f13915a86cc06f7c7cf84f60 | 2003-10-31 |
| 4.6.1 | 372a53f0579f313b05c52fda7c88cf36fdaaf02ed6c65e29211f96b8f9e47f03 | 2004-02-05 |
| 4.6.2 | b506f0e79adc60663a0dbef7192efa0936566c0d5bcf67637807df70541b9fe3 | 2004-04-11 |

`src/` and `stlport/` differ between them only in: `src/iostream.cpp`,
`src/locale_impl.cpp`, `src/locale_impl.h` (4.6 -> 4.6.1: init counters moved
into `_S_initialize`/`_S_uninitialize`, `~locale` null-checks, the classic
locale moves into an aligned buffer; 4.6.1 -> 4.6.2: `locale::_S_initialize`
placement-constructs that classic locale), `stl/_config.h` (version 0x460 ->
0x461; 4.6.2 still says 0x461), `config/stl_msvc.h` (4.6.2 enables the
warning/`pack(push,8)` prolog for VC7.1), `stl/_threads.h` (pthread, BeOS, OS/2
and a disabled debug block), `stl/_ios_base.h` (an unused template removed),
`stl/debug/*` and makefiles. No header change alters VC7.1 /Zp8 code, so header
users cannot tell the releases apart; the two library sources can.

Retail's bodies of those functions (target facts, game.dat 1.06):

- `ios_base::Init::Init` 0x00016AA0 tests `_S_count == 0` before calling
  `_S_initialize`; `~Init` 0x00015E70 tests `> 0` (4.6; 4.6.1+ call
  unconditionally).
- `locale::_S_initialize` 0x0000BAC0 returns on `count > 0`, then
  assigns ids, `make_classic_locale`, stores the global impl and increments
  last (4.6; 4.6.1+ post-increment in the test, 4.6.2 adds the classic-locale
  store).
- `locale::~locale` 0x00007150 is 7 bytes, `_M_impl->decr()` with no null
  check (4.6).

Measurement (tools/stlport_trial.py `library`, upstream VC7 static-library
flags, compiled with the pinned VC7.1 toolchain, compared with the byte gate's
`build.compile_function`):

| row | 4.6 | 4.6.1 | 4.6.2 |
| --- | --- | --- | --- |
| 0x000070E0 `locale::_S_uninitialize` 27 B | match | mismatch +0x0 | mismatch +0x0 |
| 0x00007150 `locale::~locale` 7 B | match | mismatch +0x0 | mismatch +0x0 |
| 0x00007670 `_Loc_init::~_Loc_init` 27 B | match | mismatch +0x0 | mismatch +0x0 |
| 0x00010A70 `__put_integer<..., unsigned short>` 332 B | match | mismatch +0x11E | mismatch +0x11E |
| 0x00015440 `ios_base::_S_uninitialize` 894 B | match | mismatch +0x0 | mismatch +0x0 |
| 0x00015E70 `ios_base::Init::~Init` 15 B | match | mismatch +0x0 | mismatch +0x0 |
| 0x00016AA0 `ios_base::Init::Init` 21 B | match | mismatch +0x0 | mismatch +0x0 |
| 0x0000BAC0 `locale::_S_initialize` 31 B | call target only (+0xA) | mismatch +0x5 | mismatch +0x5 |
| 0x0000F740 `_Loc_init::_Loc_init` 37 B | call target only (+0xD) | mismatch +0x5 | mismatch +0x0 |

Across both sources 4.6 matches 298 ledger rows, 4.6.1 and 4.6.2 291 each; no
row matches under 4.6.1 or 4.6.2 that fails under 4.6. Pristine 4.5.3 does not
compile these sources under VC7.1 (`stl/_string.c(337)`), and retail's
`num_put_float.cpp` string-buffer interface is 4.6's. Retail is therefore
STLport 4.6, not 4.6.1 or 4.6.2. (Community report, Jonathan Wilson: "Its still
4.5, not the correct 4.6 version".)

Usage: tools/stlport_trial.py swaps this `stlport/` directory in for
vendor/stlport when it recompiles a `// stlport` unit (`headers` lane), and
compiles `src/*.cpp` with upstream's VC7 static-library flags (`library` lane).
Results are in reverse/stlport_trial.csv.
