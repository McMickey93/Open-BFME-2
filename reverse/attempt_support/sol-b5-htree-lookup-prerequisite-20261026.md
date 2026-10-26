# HTree lookup composition blocker, 2026-10-26

Seat codexb5, family B shard 1/2. Allocated destination:
`Code/Libraries/Source/WWVegas/WW3D2/htree.cpp`. This is a blocked
prerequisite investigation; all attempted game-source changes were restored.
No merge, path move, recovered bytes, identity retirement or demonstrated
Luna unblock is claimed.

The WW3D2 consolidation planner was reviewed (original-path evidence,
alternatives and prerequisites). Current routing rebuilt in memory approves
42 rows across eight sources, including the seed's 15 rows. The normal full
`tu_skeleton.py --merge DEST --dry-run` accepts no multi-source subset.
This supersedes the earlier local handoff's compatible-subset observation;
it does not establish a regression or lost row.

## Lookup donor trial

`HTreeClassBoneLookup.cpp` owns four existing matched rows: Simple_Evaluate_Pivot
(0x001606E0, 1144), Get_Bone_Index (0x00160B60, 68), Get_Bone_Name
(0x00160BB0, 22), Get_Parent_Index (0x00160BD0, 35). The initial composition
fails because the seed header's PivotClass replaces the donor's compact
0x58-byte storage view (negative size assertion; missing Base member).

An explicit private HTreeLookupPivotView plus per-method casts preserves the
existing compact layout without replacing the seed's class declaration. This
removes the compile obstacle, but normal composition matches only 18/19 rows.
Only Get_Bone_Index fails. Object inspection establishes the cause:

- standalone: 68 bytes; relocation offset 28, DIR32 __imp___strcmpi;
- composed: 67 bytes; relocation offset 27, REL32 __strcmpi.

The seed sets `_CRTIMP=`. The imported call becomes a direct call and register
allocation changes. Explicitly redeclaring _strcmpi as dllimport keeps the
standalone donor exact but fails composition with C2375 (different linkage),
and `ms_header_audit.py check` refuses the local Microsoft-header declaration.
No header bypass or compiler override was attempted. A proper CRT-header
ownership/import solution is needed before this view repair can be accepted.
The adjacent JSON preserves the attempted diff, object facts and full final
trial report; its matching-RVA list is from the view-only trial.

## Verification and other prerequisites

Before, after view-only, and after explicit-import standalone `./build.sh`
passes all four rows, three float literals and one named import. Seed build
passes 15/15 rows and seven floats. Supported allowed_symbols, link_census
and data_check object facts are identical before/after for the donor: four
rows, 19 external definitions, one owner binding, undefined symbols, COMDAT
selection flags and data facts. These standalone facts do not prove composed
provider selection; no successful final composition exists to audit.

`find_declared_unmatched.py` passes both sources (the seed reports its eight
existing unclaimed definitions). Class gate and converged data check pass
(two sources, ten addresses, zero second names/unjudged rows). EH check finds
zero EH rows. The explicit-import header refusal is a real remaining blocker.
No protected register or hatch changed; the seed's existing ABI queue remains.

Other normal-trial rejections remain: ArchiveFile max macro collision (family
A donor); StlSweepR3Rva00162860 explicit-specialization instantiation ordering;
copy constructor Start/Finish storage mismatch; InitDefault missing m_bfme54;
LoadW3D compiler C1001; CaptureBone Elem36 declaration ordering. Mixed donors
remain behind. Do not repeat these unchanged trials without new evidence.

Scratch logs and observers are under `build/sol-b5-htree-lookup-*`. Observers
only call the normal merge verifier and inspect its objects, without filtered
donors or hand compilation into the shared match cache. No path consumer audit
is required for this evidence-only commit: no source/ledger/register paths
move in origin/master..HEAD or the staged change.

Official BFME1 fetch reports upstream cc78d407 versus preserved verified
de077dd5. Full update verification remains incomplete; no success receipt or
submodule advancement was made. No maintainer-only runner was used.
