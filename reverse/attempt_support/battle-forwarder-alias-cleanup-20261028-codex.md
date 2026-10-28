# Current-battle forwarder alias cleanup

2026-10-28, Codex; inspected base `a3adcc8d104f519af14c56656cc613dc3f8d846d`.

The link picker served BannerUI, but its destructor-fold repair already previews
LINKS. Its remaining `/alternatename` maps a second return-type spelling of the
current-battle forwarder at 0x0020E6B7 onto the existing owner:

```
?rva0020E6B7@Rva0020E6B7RegionManager@@QAEPAVLivingWorldBattle@@XZ
  -> ?rva0020E6B7@Rva0020E6B7RegionManager@@QAEPAVRva003F468D@@XZ
```

The existing nine-byte row in `GameLogic/LivingWorld/Rva002B2DAD.cpp` loads the
manager's current key at +0x0c and forwards to `rva0020E5BB`. This cleanup preserves
that owner and its current view name; it does not establish an original class
name or layout. Repository searches found two remaining callers declaring the
first spelling: LivingWorldLogic's tactical-battle completion and Player's
`initFromDict`. Their declarations now use the existing owner's return view,
with explicit casts at the call sites to preserve each caller's local view.
BannerUI already declared the owner correctly. Remove its alias and the
redundant pin for the first spelling. Hatch counters decrease by one alias and
one pin, using `hatch_counters.py --update`.

Verification:

- `./build.sh` for BannerUI.cpp, LivingWorldLogic.cpp, PlayerInitFromDict.cpp and
  Rva002B2DAD.cpp: 238/238 function rows, four data rows, with 77 funclet pins
  verified through parent EH data. `eh_verify.py` for the three edited units:
  47 EXACT EH graphs, zero failures or missing objects.
- `find_declared_unmatched.py` passes for each edited source. `data_check.py`
  reports zero findings for them; `pin_consistency.py --check` and
  `check_csv.py` pass (9,418 pins remain).
- Before/after object comparison: all 574 named COMDAT bodies in the three
  edited objects have identical bytes and names. Exactly two REL32 referents
  change from the removed spelling to the owner. The dispatcher's 29 renumbered
  local-label referents retain their section, value and storage class; all
  other relocation referents retain their name, section, value and storage.
- Joint ordinary previews before and after: BannerUI LINKS 1,885 bytes,
  LivingWorldLogic LINKS 20,081, PlayerInitFromDict LINKS 4,707 and the provider
  LINKS 261: unchanged 26,934 authored bytes against index `14dc3d2467`
  (2026-10-28 02:44). These are preview results, not a new census gain.
- The removed decorated name has no remaining occurrence in `Code/` or the
  symbol ledger. A cached-object search finds only the obsolete
  `LivingWorldLogic.harvest.obj`; the current build objects use the owner.

No source paths, provider definitions, TU assignments or registered class
layouts change. No data or identity-register entries are retired. The outgoing
batch audit still requires the published index's consumer coverage and a census
at its base; the previews and object comparisons above cover the four named
units. Carry any inconclusive batch result into the next normal census rather
than treating it as global clearance. The prior BannerUI fold's census
confirmation remains pending (LINK-016).
