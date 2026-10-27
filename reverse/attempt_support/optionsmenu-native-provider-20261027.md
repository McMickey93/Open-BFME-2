# OptionsMenu cleanup with a native folded getter provider

Base: bd08a890c4. Date: 2026-10-27. Model: GPT-6.
Scope: OptionsMenu.cpp and OptionPreferences_getLANIPAddress.cpp under
Code/GameEngine/Source/GameClient/GUI/GUICallbacks/Menus/.

## Target facts and retained ownership

- The existing GadgetSliderGetMinMax row at 0x0051822B is 27 bytes. Its retail
  loads read max at +4 and min at +0, after GameWindow::winGetUserData.
- OptionPreferences::getLANIPAddress at 0x002E4F98 calls the existing pinned
  EnumeratedIP::getIPstring symbol at 0x002E4336 (REL32 at 0x002E4FF9, retained
  from the original pin's evidence). The latter address already
  belongs to the 24-byte MultiplayerColorDefinition::getTooltipName row in
  Code/GameEngine/Source/Common/MultiplayerColorTooltipName.cpp. No second row
  was added, and the owner was not moved.
- The ordinary inline `return m_IPstring` in the LAN caller emits the complete
  24-byte getter, including its REL32 to AsciiString's copy constructor.
  pin_admission.fold_proof_problems with allow_weak=False accepts it against
  the existing owner. The getter binding in the consumer's strict build receipt
  is 0x002E4336. The existing pin was removed and re-admitted using
  tools/pin_admission.py --add with fold-proof naming this caller, not hand-edited
  into a new escape hatch. Pin count is unchanged.
- The LAN caller's five rows (parent, handler and three cleanup funclets) and
  the slider helper remain byte exact. The EH graph is EXACT after the compiler
  renumbers its internal labels. No dummy call, data anchor or emission pragma
  was introduced.

## Donor facts and cleanup

The pre-existing OptionsMenu.cpp is an imported Zero Hour menu implementation.
Its Gadget.h SliderData declaration supplies the first two field names; the
retail loads independently substantiate their offsets. This is donor context,
not proof that the imported callbacks reconstruct BFME 2 menu code.

Only the already rowed slider helper remains in OptionsMenu.cpp. The direct LAN
caller now owns the required folded getter's inline provider. The owning hatch
counter update deletes 23 present-unmatched and two pragma_optimize entries.
The scoped ms_header_audit.refresh_queue rescan deletes only the obsolete
stricmp source entry. No baseline was enlarged and no source path changed.

## Verification

- ./build.sh on the two changed sources: 6/6 exact, one literal verified, zero
  unresolved or masked relocations.
- find_declared_unmatched.py: both sources clear.
- eh_verify.py: one EXACT graph, no failures or missing parents.
- data_check.py on both sources: no findings; --converged: ten addresses, no
  second names or unjudged bindings.
- pin_consistency.py --check: no new, baselined or stale conflicts.
- check_csv.py and git diff --check pass.
- link_check.py --prepare-current on the two sources writes strict current
  receipts; it does not run a census or update its status/index.
- link_check.py --paths-from build/optionsmenu-before-paths.txt covers the
  approved 38-source donor scope: 37/38 clean before, 38/38 after; authored bytes
  4,548 -> 4,575. All previously linking donors remain clean.

These are ordinary previews against index bf3dd31211 dated 2026-10-27 00:39,
not a census LINKED increase or an image-ownership receipt.

## Selected-provider and consumer audit

The ordinary link_batch_audit report is provisional: HEAD is newer than the
saved index. In addition to the two changed objects, its current-ledger filter
retires 284 unrelated indexed source objects. It reports 1,757 provider findings
from that combined scope and no previously linked changed-unit unresolved-byte
loss. These findings need the next census; they are not all caused by this edit.

To isolate the source change, a scratch audit uses link_batch_audit.overlay on
the two current objects with an empty removal set, retaining the saved index's
other objects and order. Comparing selected providers identifies 105 names
losing their sole provider: 65 string literal names and 40 other names. It scans
the COFF symbol tables of all 22,430 indexed, still-rowed sources outside the
changed pair: no undefined EXTERNAL with value/section zero consumes those
names. No cached object in that scan is missing. Separately,
name_dependents.dependents on the 40 nonliteral names and its current-ledger
_row_objects mapping finds zero candidates, using source text when no object
with a matching source hash is available. This includes sources added since
the index.

Limits: the cached-object scan is a snapshot, not a fresh whole-tree compile;
the text fallback does not prove arbitrary future header-dependent emission.
The saved reference graph lacks per-object provenance and retains edges from
removed callbacks. Its aggregate references alone cannot establish current
external consumers. The next census must confirm the combined current tree.
The specific previously recorded live LAN consumer is freshly compiled and
strictly verified in this change.

Raw local artifacts are in build/optionsmenu-{link-before,link-after,
prepare,provider-audit,provider-scope}.log and
build/optionsmenu-{lost-names,provider-consumers,provider-fallback}.json.
They are scratch evidence, not tracked build inputs.

## Remaining work

The supported OptionsMenu consolidation dry-run was canceled in favor of this
prerequisite; no merge was applied and no TU approval changed. Regenerate the
name_lane consolidation report before resuming. LINK-094's WOLGameSetupMenu
gameAcceptTooltip/provider and combo-box-helper placement work remains open.
