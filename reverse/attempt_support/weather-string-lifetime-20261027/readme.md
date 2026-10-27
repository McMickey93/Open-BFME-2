# GlobalWeatherSystem string lifetime, 2026-10-27

Inspected revision: `818311dee7`. Ordinary preview index: `73061d9452`,
2026-10-27 14:34, retail-truth-4. The default picker claimed constructor
0x00318588 and its source scope. The BFME 1 freshness receipt was current.

## Target facts and repair

The earlier LINK-009 inspection established that native constructor unwind
0x0077A838 destroys member +0x20 through the existing AsciiString cleanup
at 0x0048BA39. The complete destructor at 0x00318637 already represents
this member as AsciiString. Replace the constructor's private, undefined
Rva00318588Handle lifetime with that existing string type. Its semantic
purpose remains unknown. No class name, header, pin, alias or ledger row changes.

The current BFME 1 e74410b3 GlobalWeatherSystemConstructor.cpp likewise owns
a string between the pool handle and weather array, at its different +0x1C
offset. This is corroborating donor structure, not a BFME 2 layout proof.

## Verification

- Normal `./build.sh` passes all five source rows (133-byte parent, three
  unwind actions and the handler). The parent EH graph is EXACT; the
  declared-definition check reports all bodies matched.
- The paired ordinary previews report four unresolved names before and three
  after. The removed name is `??1Rva00318588Handle@@QAE@XZ`. Both previews
  retain zero linked authored bytes for this source.
- [Object comparison](object-diff.json), using objects from normal builds,
  finds all 18 retained external COMDAT definitions unchanged in size and
  relocation-aware digest. The opaque constructor disappears; the existing
  AsciiString constructor and destructor are emitted instead. The only added
  undefined name is the string's existing releaseBuffer provider. The preview
  reports no new selected-copy, duplicate or COMDAT blocker.
- Shadow data check has zero findings; enforced converged data check has zero
  second names and zero unjudged rows across ten addresses.

## Remaining scope

The unit still needs WeatherData's constructor and destructor bindings and
the GlobalWeatherSystem/Rva00318637 complete-destructor identity merge from
LINK-009. Do not substitute IPEnumeration's owning-list destructor for the
weather element's counted-reference lifetime merely because their zeroing
constructors fold together.

The exact parent graph now places `$L5363` at 0x0077A838. A separate claim
attempt found that generated unwind address held by another worker, so its
existing uw_gen_012.cpp row is untouched. Its prior unmasked repoint failure
can be reconsidered with this real string binding once the claim is available.

No census, executable link, runtime test or headline improvement is claimed.
