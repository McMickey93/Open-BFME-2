# DX8Caps work-string storage ownership

2026-10-27; control `f3d49bea73`; ordinary preview index `bf3dd31211`
(2026-10-27 00:39 census).

The default picker served the two data-debt keys for `_CapsWorkString` in
`Code/Libraries/Source/WWVegas/WW3D2/dx8caps.cpp`. Its real StringClass object
and the unsigned placeholder in `Rva007B6880Thunks.cpp` both represented retail
RVA `0x009EE938` (VA `0x00DEE938`). The provisional data index preferred the
placeholder, although the real object owns matched initialization code.

Target facts:

- The existing DX8Caps logging rows and initializer at `0x007ACD40` bind this
  address. The initializer remains in its original TU and retains its complete
  50-byte match, including registration of cleanup `0x007B7070`.
- Cleanup `0x007B7070` loads the same object's address and tail-calls the rowed
  `StringClass::Free_String` at `0x00610A40`.
- A new explicit data row verifies `_CapsWorkString` as a four-byte StringClass
  object against the zero-filled retail load image. The verifier checks the
  source-level sizeof and allocation extent as well as bytes.

Keep the existing CapsWorkString definition and give it C external linkage so
the cleanup TU can refer to its existing COFF name. Replace that TU's unsigned
definition and cast with an external StringClass declaration and direct address.
There is one object, its existing initializer and its existing cleanup. This
binds an already named object; it makes no new donor-name or BFME 2 path claim.
BFME 1's current `game/Libraries/Source/WWVegas/WW3D2/dx8caps.cpp` also retains
the file-scope StringClass and offers no additional ownership repair to inherit.

Verification:

- `find_declared_unmatched.py` passes for both edited sources before and after.
- Normal build passes 932/932 matched function rows across both sources and
  22 data rows. String, float and named-import checks pass.
- `repair_queue.py retire data .../dx8caps.cpp` retires both registered keys,
  with zero remaining findings for this source. No debt line is deleted by hand.
- `hatch_counters.py --update` removes the placeholder's one address-global key
  (three occurrences). No escape hatch is added.
- Paired ordinary previews preserve DX8Caps's LINKS result and 8,058 authored
  bytes. In both controls the cleanup TU has only the unresolved
  `?g_lgaKeyRecords@@3PAIA` in this bounded cohort; its separately owned
  LargeGroupAudio provider is outside the preview. No linked-byte gain or
  closed-strict result is claimed.
- The cleanup TU's shadow data check still reports thirteen findings, four
  outside its historical register. Those four concern unchanged declarations
  `g_00DFE358`, `g_00E02310`, `g_00E04424` and `g_00E06665`, already present in
  the control source. Its other debt is not retired by this repair.

This is two retired data-debt keys and one retired hatch key. Census and
image-ownership changes remain unclaimed. The normal pre-push batch audit will
judge its own input freshness; an inconclusive result needs the next ordinary
census rather than a maintainer-only measurement run.
