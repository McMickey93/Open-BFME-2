# Microsoft-header queue: imported game operator collision

Inspected revision: `c01848c0b16`, 2026-10-26.
The default picker served the whole header
`reference/shims/bfme_colmathaabox/vector3.h` as one conflicting `<dvec.h>`
definition. This structural candidate has no retail RVA or body extent.

The real VC7.1 index compares line 216's
`Vector3 operator*(float, const Vector3&)` against `<dvec.h>` line 371's
`I64vec2 operator*(const Iu32vec4&, const Iu32vec4&)`. These are unrelated
C++ overloads. The game declaration's `dllimport` suppressed the classifier's
existing unrelated-overload filter, causing a bogus ABI finding and migration
instruction. Replacing this game function with the SIMD header is not valid.

The repair allows ordinary imported C++ operators through the existing exact
parameter-type overload filter. Named functions and allocation operators keep
their conservative import treatment; same-parameter Microsoft operators still
report ABI differences. No game source or shim was changed. No per-file bypass,
whitelist or hand-added pin is involved.

Validation:

- The regression test fails before the repair (1 failed, 2 passed).
- The real header scan changes from one ABI finding to no local occurrences.
  Its standalone unresolved `always.h` include notes remain; this is not a
  claim that the header's include closure or every dependent has been verified.
- `test_ms_header_audit.py` and `test_gate_exploits.py`: 107 passed, 1 skipped.
  The skip is the empty audit-escape fixture parametrization (this checkout has
  no `tools/tests/fixtures/audit_escapes/` directory). The named exploit tests run.
- The existing mocked Wine test needed a host-independent fake path mapping:
  on Windows it previously produced `Z:C:\...` and failed its own assertion.
  Only the test mock was corrected; compiler invocation code is unchanged.
- `ms_header_audit.refresh_queue` rescanned the selected header and removed its
  single false row; an exact byte comparison checked every unrelated queue row
  stayed unchanged. Other queued files were not rescanned or retired.

Attached before/after scans and test reports preserve the reproduction.
This is a tooling false-positive repair, not newly recovered C++, a link gain,
or retirement of genuine game-source debt.
