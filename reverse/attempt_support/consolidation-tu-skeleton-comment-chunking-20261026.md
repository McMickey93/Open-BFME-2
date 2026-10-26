# tu_skeleton chunker: remaining type-definition misreads (handoff, 2026-10-26)

Landed first: 65d27d52f6 (storage-specified aggregates; BuddyThread.cpp dry-run
0 -> seed + 8 donors / 39 rows). This note covers what that commit does not fix.

## Census of misread items

Scratch scan over `Code/` (`.cpp`/`.c`, excluding gen_asm and masm_dumps): a
`def` chunk whose head names class/struct/enum/union without a parameter list
is a type definition that `chunks()` split at its `}` and so orphaned its `;`.
- HEAD before 65d27d52f6: 18 items. After it: 16.
- With the unlanded patch below: 14. All 14 are family D.

## B + C: patch ready but not landed (no TU dry-run yet; wind-down)

- **B (`strip` order):** block comments were removed before line comments.
  A `//*****` banner followed by `/*! ... */` therefore left a `/` ahead of
  the head.
  - Affects dx8caps.cpp `BFME_DX8Caps_DepthStencilFields`, a TU with 78
    approved rows.
  - Affects dx8wrapper.cpp `Bfme2LightEnvironmentInputView`.
  - Fix: a single left-to-right COMMENT tokenizer that also keeps string and
    char literals intact.
  - Side effect: `norm()` keys of strings containing `//` change. They were
    previously truncated. This is why a dry-run is required before landing.
- **C (comment on a directive line):** `#include "WinMain.h" /** ...` was
  read with the pp line ending at the newline. The comment's tail, braces
  included, leaked into the next item.
  - Affects W3DView.cpp and W3DView_MoveCameraOrLocatorAlongSplinePathInit.cpp
    (`BfmeW3DViewViewportVtable`).
  - Fix: the directive extends to the `*/` that closes a block comment opened
    on its line.
- **To land it:**
  1. Apply the patch.
  2. Add the tests below to `class CommentReadingTests` in
     tools/tests/test_tu_skeleton.py. The suite passes 40/40 with the patch;
     the 3 new tests fail on HEAD.
  3. Run `tools/tu_skeleton.py --merge Code/Libraries/Source/WWVegas/WW3D2/dx8caps.cpp --dry-run`
     before and after, and compare the accepted donors.
  4. Commit with `Verifier-Change:`.

## D: macro-led and nested-template heads (open, needs design)

The 14 remaining items:
- `_STLP_BEGIN_NAMESPACE` / `_STLP_END_NAMESPACE` before a struct: the
  STLport ctype files, Open2381C0Impl_invoke.cpp, ArmySummaryDescription.cpp
  `LocomotorStore12`.
- `_STLP_TEMPLATE_NULL struct __type_traits<...>` in PeerThread.cpp, a TU
  with 209 approved rows.
- A pp line glued after such a macro, because `code` is still true.
- `template <class _Tp, class _Alloc = allocator<_Tp> >` heads whose nested
  `<>` defeat `template\s*<[^>]*>`: the `vector<Drawable*>` specializations,
  and IMEManager.cpp `vector<HKL>` (47 approved rows).

Do not simply split a namespace macro off as a decl. compose() hoists and
dedupes decls, so a second donor's BEGIN/END pair would be dropped and its
types would land outside `_STL`. The namespace macros need the opaque-region
handling that `#if` regions get (composition_chunks).

## Patch (B + C)

```diff
diff --git a/tools/tu_skeleton.py b/tools/tu_skeleton.py
index 30ec20f14d..33276d8619 100644
--- a/tools/tu_skeleton.py
+++ b/tools/tu_skeleton.py
@@ -173,7 +173,13 @@ def chunks(text):
                     k = n
                     break
                 if text[k - 1:k] != "\\" and not text[j:k].rstrip("\r").endswith("\\"):
-                    break
+                    # a block comment opened on the directive's line ends with the directive
+                    o = COMMENT.sub(lambda m: m.group(0) if m.group(0)[0] in "\"'" else " " * len(m.group(0)),
+                                    text[i:k]).find("/*")
+                    if o < 0 or text.find("*/", i + o + 2) < 0:
+                        break
+                    j = text.find("*/", i + o + 2) + 2
+                    continue
                 j = k + 1
             lead = text[start:text.rfind("\n", 0, i) + 1]
             if lead.strip():
@@ -215,9 +221,13 @@ def chunks(text):
     return out
 
 
+# one left-to-right pass, as the compiler reads it: a `//****` banner before a `/* ... */` block
+# is a line comment, and comment openers inside string and character literals are text
+COMMENT = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|//[^\n]*|/\*.*?\*/', re.S)
+
+
 def strip(t):
-    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
-    return re.sub(r"//[^\n]*", "", t)
+    return COMMENT.sub(lambda m: m.group(0) if m.group(0)[0] in "\"'" else " ", t)
 
 
 def norm(t):
```

## Tests

```python
class CommentReadingTests(unittest.TestCase):
    def test_a_line_comment_banner_before_a_block_comment_leaves_no_slash(self):
        # dx8caps.cpp: `//*****` then `/*! ... */` left a `/` before the struct head,
        # which then split at its `}` and orphaned the `;`
        text = "//********\n/*! doc */\nstruct S { int a; };\nint f() { return 1; }\n"
        self.assertEqual([(k, T.strip(c).strip()) for k, c in T.chunks(text)],
                         [("decl", "struct S { int a; };"), ("def", "int f() { return 1; }")])

    def test_a_comment_opener_in_a_string_is_text(self):
        self.assertEqual(T.norm('const char *p = "/* x */ //y";'), 'const char *p = "/* x */ //y";')

    def test_a_block_comment_opened_on_a_directive_line_ends_with_the_directive(self):
        # W3DView.cpp: `#include "WinMain.h" /** ...` leaked the comment's braces into the next item
        text = '#include "WinMain.h" /** start\n * more } {\n */\nclass V { int x; };\nint g() { return 2; }\n'
        items = T.chunks(text)
        self.assertEqual([k for k, _ in items], ["pp", "decl", "def"])
        self.assertEqual(T.strip(items[0][1]).strip(), '#include "WinMain.h"')
        self.assertEqual(T.strip(items[1][1]).strip(), "class V { int x; };")


```
