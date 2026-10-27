# PlaceEventTranslator 0x0043218A: two stack homes follow the TU's symbol count

Date 2026-10-27, base `83f299b390`, model opus-5.5 (seat halilkkaya-pet).
Target: `PlaceEventTranslator::translateGameMessage`, RVA 0x0043218A, 1701 B,
`/O1 /arch:SSE /G7 /EHsc`. This is the LINK-004 blocker that refuses every
member added to `Code/GameEngine/Source/Common/GameLogicObjectLookupView.h`.
No source or header change was landed; the exact body is unchanged.

## Symptom

Only two frame homes move. The `/FAs` equates of the exact build:

```
$T6585 = -32   _builderObj$6097 = -32      (push_back Drawable* temp)
$T6763 = -28   _pendingBuild$6090 = -28    (insert result temp)
```

With one extra declaration anywhere before the function, `pendingBuild` and
`builderObj` exchange the two homes (stores at +0x25A/+0x2E5, reloads at
+0x476/+0x479). Every other home, every instruction and the frame size stay.
The two temps keep their homes; only which split home joins which temp group
changes. In the listing order each home enters its group before its temp, so
the decision is the packer's insertion order of the two equal-weight split
homes (each has one store and one reload).

## Measured mechanism

All trials compile scratch copies under `build/` with the unit's own command
(`build.compiler_command` plus the region flags), never `compile_source`; the
scripts are `cmp.py.txt` (body vs retail, relocations masked), `multi.py.txt`
(block-scope `extern int` probes before named anchor lines) and
`trialhdr.py.txt` (trial headers). A block-scope `extern int` is unreferenced,
emits nothing and only consumes one front-end symbol id (the `$N` suffixes in
the listing move by exactly one per probe).

1. **Period 64 in the declaration count.** With N probes inserted anywhere
   before the function (file top, after the GameLogic include, after the
   views, or at the top of the function body) the body is exact (E) or swapped
   (s) by N mod 64 only (N = 0..100 measured, 64..100 repeat 0..36):

   ```
   N mod 64: 0         1         2         3         4         5         6
             0123456789012345678901234567890123456789012345678901234567890123
             EssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEEEEEsssssssssssssssssss
   ```

   Probes after the function, comment changes and renames of any length
   (`m_6d` to names of 1..20 characters, probe names of 1..40 characters) are
   inert. Unused methods added to `GameLogic` follow the same table (verified
   at N = 2, 9, 12, 13, 16, 29, 44, 45).
2. **Only five symbols decide it: the function-scope static data.** Moving the
   probes inside the body showed which symbol ids matter. Probes before
   `pendingBuild`, between it and `builderObj`, after `builderObj` or before
   `cmt` give the table above; probes after `noCanDoSound`'s declaration are
   inert for all 64 counts. The ids that matter are the four string literals
   of the `canMakeUnit` messages (`GUI:NotEnoughMoneyToBuild`,
   `...ProductionQueueFull`, `...ParkingPlacesFull`, `...UnitMaxedOut`, four
   ids apart) and the local static `noCanDoSound`. Named locals (`pendingBuild`,
   `builderObj`, `lbc`, `localIndex`, `portBlocked`, `newWorld`, `newAngle`,
   `value`, `options`, `list`, `info`, the case-3 locals) and the
   compiler temporaries (`$T`) are inert: shifting any of them relative to the
   rest changes nothing.
3. **Each decisive symbol toggles the result by its own residue.** Shifting one
   literal alone by k (k probes before it, 64 - k after it) swaps the result
   only in a three-wide window plus one point (L1: k = 17..19 and 40; L2:
   13..15, 36; L3: 9..11, 32; L4: 5..7, 28; the windows move four per
   literal). With the static shifted by 5 the same L1 window toggles the other
   way. Shifting only `noCanDoSound` leaves the body exact at 6 of 64 residues.
4. **Without them the order is fixed but not retail's.** A scratch copy whose
   four literals are first created at namespace scope (an unused array before
   the function) makes the literals inert (one id per message disappears and
   L1 shifts change nothing); with `noCanDoSound` also replaced by a
   namespace-scope object (code changes, homes read from `/FAs`) the homes are
   `pendingBuild` -32 / `builderObj` -28 for all 64 counts. Retail's order is
   therefore the toggled one that the five static-data residues produce, not a
   property of the locals or of GameLogic's layout.
5. **No offset between the literals and the static removes it.** Shifting
   `noCanDoSound` by j against the literals (j = 0..63, 64 counts each,
   4,096 compiles) never gives an exact body for all 64 counts; the best row
   (j = 36) is exact at 32 of 64, with one 20-count run. See the j table
   below. The natural lever that exists (inlining `localIndex`, j = 63, i.e.
   -1, otherwise code-identical) is swapped at the current count.

Hypotheses from the assignment: (1) symbol-id hashing - confirmed, period 64
in front-end ids, but only the function's static data symbols take part;
(2) an inline GameLogic accessor or field use - ruled out, the body only calls
`findObjectByID`, and unrelated declarations anywhere before the function
reproduce it; (3) a tie in local declaration order - the tie is real (equal
split-home weights), but local order and scope are inert: declaring
`builderObj` before `pendingBuild`, moving ids between them and inlining
`localIndex` do not decide it.

## Consequence

No code-identical spelling of this unit makes the two homes independent of the
number of declarations before it. The decisive ids are the residues of
compiler-created static data inside the function, which every preceding
declaration shifts, and removing them changes code. Any header included before
the function counts, not only GameLogic: `Lib/Coord3D.h`,
`Common/BfmeAudioEventPrefix136.h`, `PlaceEventTranslatorView.h`,
`PlacementPositionValue.h` and the STLport headers shift the same table.

## Rule for header growth (verified)

A change before the function keeps the body exact when its net symbol delta
mod 64 is in **{0, 9..12, 16..19, 29..44}**. Count one per declared member
(data member, method, typedef, nested enum value) and one per removed one; a
field that splits a pad adds two (field plus the new pad); a field that
replaces a whole pad of its size adds none.

| Trial header (`trialhdr.py.txt`) | Delta | Result |
|---|---|---|
| A: `bool m_9d` at +0x9D | +2 | `./build.sh`: FAIL 1/5 (+0x25C, the known swap) |
| D: A plus `int m_A0` at +0xA0 | +4 | scratch: swapped |
| B: `m_6E`, `m_99` (replaces pad99), `m_9b`, `m_9d`, `m_9f`, `m_A0`, `m_118`, `m_11C` | +9 | `./build.sh`: Functions OK 5/5 |
| C: B plus `int m_1B4` at +0x1B4 | +10 | scratch: exact |

The trial header was restored before committing. A unit-local compensation in
PlaceEventTranslator.cpp of c declarations (before the function) shifts the
table by c: a single state of this file is exact for both the current header
and a +2 header only when c is in {9, 10, 16, 17, 29..42}. Such a change would
be count tuning, not a fix, so none was made; the lead chooses between batched
header deltas and a matching compensation.

## SND offset table (j = noCanDoSound shifted against the literals)

Each row is the 64-count table for that j (index = probes before the function).

```
     0123456789012345678901234567890123456789012345678901234567890123  E
j=0  EssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEEEEEsssssssssssssssssss 25
j=1  sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEsEEEsssssssssssssssssssE 23
j=2  sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEssEEsssssssssssssssssssEs 21
j=3  sssssssssEEEEsssEEEEsssssssssEEEEEEEEEsssEsssssssssssssssssssEss 19
j=4  sssssssssEEEEsssEEEEsssssssssEEEEEEEEsssssssssssssssssssssssEsss 17
j=5  sssssssssEEEEsssEEEEsssssssssEEEEEEEEsssEssssssssssssssssssEssss 18
j=6  sssssssssEEEEsssEEEEsssssssssEEEEEEEEssEEsssssssssssssssssEsssss 19
j=7  sssssssssEEEEsssEEEEsssssssssEEEEEEEEsEEEssssssssssssssssEssssss 20
j=8  sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssssssssssssssEsssssss 21
j=9  sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssssssssssssssEssssssss 21
j=10 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssssssssssssEsssssssss 21
j=11 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssssssssssssEssssssssss 21
j=12 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssssssssssEsssssssssss 21
j=13 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssssssssssEssssssssssss 21
j=14 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssssssssEsssssssssssss 21
j=15 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssssssssEssssssssssssss 21
j=16 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssssssEsssssssssssssss 21
j=17 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssssssEssssssssssssssss 21
j=18 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssssEsssssssssssssssss 21
j=19 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssssEssssssssssssssssss 21
j=20 sssssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssEsssssssssssssssssss 21
j=21 sssssssssEEEEsssEEEEEEEEEEEEEssssssssEEEsssEssssssssssssssssssss 21
j=22 sssssssssEEEEsssEEEEEEEEEEEEEssssssssEEsssEsssssssssssssssssssss 20
j=23 sssssssssEEEEsssEEEEEEEEEEEEEssssssssEsssEssssssssssssssssssssss 19
j=24 sssssssssEEEEsssEEEEEEEEEEEEEsssssssEsssssssssssssssssssssssssss 18
j=25 sssssssssEEEEEEEsssssssssssssssssEEEsssEssssssssssssssssssssssss 11
j=26 sssssssssEEEEEEEsssssssssssssssssEEsssEsssssssssssssssssssssssss 10
j=27 sssssssssEEEEEEEsssssssssssssssssEsssEssssssssssssssssssssssssss  9
j=28 sssssssssEEEEEEEssssssssssssssssEsssssssssssssssssssssssssssssss  8
j=29 ssssEEEEEssssssssssssssssssssEEEssssEsssssssssssssssssssssssssss  9
j=30 sssEEEEEEssssssssssssssssssssEEssssEEsssssssssssssssssssssssssss 10
j=31 ssEEEEEEEssssssssssssssssssssEssssEEEsssssssssssssssssssssssssss 11
j=32 sEEEEEEEEsssssssssssssssssssEssssEEEEsssssssssssssssssssssssssss 13
j=33 ssssssssEEEEEEEEEEEEEEEEEEEEssssEEEEEsssssssssssssssssssssssEEEE 29
j=34 sssssssEEEEEEEEEEEEEEEEEEEEssssEEEEEEssssssssssssssssssssssEEEEs 30
j=35 ssssssEEEEEEEEEEEEEEEEEEEEssssEEEEEEEsssssssssssssssssssssEEEEss 31
j=36 sssssEEEEEEEEEEEEEEEEEEEEssssEEEEEEEEssssssssssssssssssssEEEEsss 32
j=37 EsssEEEEsssssssssssssssssssssEEEEEEEEsssssssssssssssssssEEEEssss 17
j=38 sssEEEEssssssssssssssssssssssEEEEEEEEssssssssssssssssssEEEEssssE 17
j=39 ssEEEEsssssssssssssssssssssssEEEEEEEEsssssssssssssssssEEEEssssEs 17
j=40 sEEEEssssssssssssssssssssssssEEEEEEEEssssssssssssssssEEEEssssEss 17
j=41 EEEEsssssssssssssssssssssssssEEEEEEEEsssssssssssssssEEEEssssEsss 17
j=42 EEEssssssssssssssssssssssssssEEEEEEEEssssssssssssssEEEEssssEsssE 17
j=43 EEsssssssssssssssssssssssssssEEEEEEEEsssssssssssssEEEEssssEsssEE 17
j=44 EssssssssssssssssssssssssssssEEEEEEEEssssssssssssEEEEssssEsssEEE 17
j=45 sssssssssssssssssssssssssssssEEEEEEEEsssssssssssEEEEssssEsssEEEE 17
j=46 sssssssssssssssssssEsssssssssEEEEEEEEssssssssssEEEEssssEsssEEEEs 18
j=47 ssssssssssssssssssEEsssssssssEEEEEEEEsssssssssEEEEssssEsssEEEEss 19
j=48 sssssssssssssssssEEEsssssssssEEEEEEEEssssssssEEEEssssEsssEEEEsss 20
j=49 ssssssssssssssssEEEEsssssssssEEEEEEEEsssssssEEEEssssEsssEEEEssss 21
j=50 ssssssssssssssssEEEEsssssssssEEEEEEEEssssssEEEEssssEsssEEEEsssss 21
j=51 ssssssssssssssssEEEEsssssssssEEEEEEEEsssssEEEEssssEsssEEEEssssss 21
j=52 ssssssssssssssssEEEEsssssssssEEEEEEEEssssEEEEssssEsssEEEEsssssss 21
j=53 sssssssssssEEsssEEEEsssssssssEEEEEEEEssssEEEssssEsssEEEEssssssss 22
j=54 ssssssssssEEEsssEEEEsssssssssEEEEEEEEssssEEssssEsssEEEEsssssssss 22
j=55 sssssssssEEEEsssEEEEsssssssssEEEEEEEEssssEssssEsssEEEEssssssssss 22
j=56 ssssssssEEEEEsssEEEEsssssssssEEEEEEEEssssssssEsssEEEEsssssssssss 22
j=57 sssssssssEEEEsssEEEEsssssssssEEEEEEEEsssEsssEsssEEEEssssssssssss 22
j=58 sssssssssEEEEsssEEEEsssssssssEEEEEEEEssEEssEsssEEEEsssssssssssss 23
j=59 sssssssssEEEEsssEEEEsssssssssEEEEEEEEsEEEsEsssEEEEssssssssssssss 24
j=60 ssssEssssEEEEsssEEEEsssssssssEEEEEEEEEEEEEsssEEEEsssssssssssssss 26
j=61 sssEsssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsssEEEEssssssssssssssss 25
j=62 ssEssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEssEEEEsssssssssssssssss 25
j=63 sEsssssssEEEEsssEEEEsssssssssEEEEEEEEEEEEsEEEEssssssssssssssssss 25
```
