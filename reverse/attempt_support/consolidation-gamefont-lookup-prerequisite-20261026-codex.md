# GameFont lookup prerequisite attempt, 2026-10-26, codex

Allocated family A shard 0/2 target: `Code/GameEngine/Source/GameClient/GUI/GameFont.cpp`. Runner `--check-tu` exits zero. Current scoped GUI planner and fresh `--plan` reviewed: original WorldBuilder/donor paths support investigation only; the current skeleton independently approves routing. No merge, split, ledger move or TU-map update was applied.

## Boundary and verdict

Ordinary baseline `--merge TU --dry-run` accepts no composition. `FontLibraryFindRecord.cpp` fails C2065 because its selected receiver has no `m_fontSubstitution`. A shared receiver trial joins its existing virtual surface and table map at +0x14 with the seed's existing substitution-tree header at +0x20. It clears C2065 but the ordinary final dry-run rejects this donor on bytes. No newly compatible donor/row is claimed. The source trial was reverted; the exact patch is banked below for a future compiler-environment repair.

Read-only inspection of cached ordinary trial `build/tu_skeleton/0abf6d4abb401b86.obj` locates the boundary: styled lookup 0x0021857E is 283 bytes versus retail's 296, first difference at +11. The object uses x87 conversion where the standalone exact object uses SSE conversion. Its associated 0x0076E454 unwind body also cannot be located by the original label. A supported Verifier trial adding /EHsc alone (`8181568a18eae446.obj`) remains 29/31; it does not fix either boundary. No compiler flag, shared header, hatch or gate change was retained. This is not a lost row: all 31 standalone rows remain matched.

Other original diagnostics stay unchanged: FontLibraryFontList duplicates private `_Rb_tree_node_base`/`_Rb_global` against real STLport; Q3 introsort lacks comparator declarations; Q3 linear insert lacks MixFileCreator::FileInfoStruct; the rb-tree-hint and record-constructor donors duplicate allocator/pair/less; destroy/free lacks its private receiver; ParseDefaultSettings lacks constructor/parser declarations. Twenty-two mixed owners remain behind, including Libraries donors outside this family's scope. The current report contains 119 approved entries; only current routing and normal claims authorize a later move.

## Measured trial checks

- `./build.sh GameFont.cpp FontLibraryFindRecord.cpp` before and after: 31/31 exact, one float and one import, verified renumbered funclets. `find_declared_unmatched.py` and `class_gate.py` pass both. EH verification: five EXACT, none missing.
- Complete before/after non-debug object sections: 729 seed + 47 lookup equal, including payloads, relocation referents, section flags, COMDAT policies and SafeSEH. Complete external code providers/undefined sets equal: 685/32 seed and 41/15 lookup. All 79 allowed_symbols reference facts equal; per-source data references and definitions equal. Baseline funclets were resolved through their saved object's own parent EH, not today's numeric labels.
- Strict `link_check.py --prepare-current --paths-from build/codex-session9-gamefont-sources.txt` verifies both providers/31 rows with current reusable receipts. Data enforcement: zero findings; converged: ten addresses, zero second names or unjudged rows. These are scoped receipts, not census or merged-provider acceptance.
- Code-identity shadow scan prints ten findings: two existing seed wrong bindings and eight existing shared-template divergent definitions. The complete before/after provider and reference proofs show these are unchanged; no identity key is retired. Hatch staged check passes without register edits.

One planner refresh raced the temporary ordinary trial source and failed on its removal. After the trial finished, a fresh GUI planner and `--check build/consolidation` pass. Scratch receipts/scripts are `build/codex-session9-gamefont-*`; all compilation used build.sh or the supported TU Verifier, with no manual shared-cache compilation. No maintainer-only runner was invoked.

File reduction 0; debt retired 0; recovered C++ bytes 0; newly accepted downstream rows 0. Release the abandoned source/header claims after banking; retain only this handoff claim until publication. Do not repeat this trial without a new explanation for its SSE/x87/environment boundary.

## Banked receiver patch (not applied)

```diff
diff --git a/Code/GameEngine/Source/GameClient/GUI/FontLibraryFindRecord.cpp b/Code/GameEngine/Source/GameClient/GUI/FontLibraryFindRecord.cpp
index 7815597e4f..7e775efb79 100644
--- a/Code/GameEngine/Source/GameClient/GUI/FontLibraryFindRecord.cpp
+++ b/Code/GameEngine/Source/GameClient/GUI/FontLibraryFindRecord.cpp
@@ -92,25 +92,7 @@ struct BfmeFontRecord
 	bool m_flag08; // +0x08
 };
 
-class FontLibrary
-{
-public:
-	void *rva002186A6(const AsciiString *name, float size);
-	GameFont *getFont(const AsciiString *name, float size, bool bold);
-	GameFont *rva0021857E(const AsciiString *name, float size, bool bold, int style);
-	void rva00218468(const AsciiString *name, float *size, bool *bold);
-
-	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
-	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
-	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
-	virtual void slot12(); virtual void slot13();
-	virtual bool loadFontData(GameFont *font); // +0x38
-private:
-	char m_pad04[0x0C - 4];
-	GameFont *m_fontList; // +0x0C
-	int m_fontCount; // +0x10, updated by the matched list-prepend helper
-	_STL::map<AsciiString, AsciiString> m_tables;
-};
+#include "FontLibraryLookupView.h"
 
 void *FontLibrary::rva002186A6(const AsciiString *name, float size)
 {
diff --git a/Code/GameEngine/Source/GameClient/GUI/FontLibraryLookupView.h b/Code/GameEngine/Source/GameClient/GUI/FontLibraryLookupView.h
new file mode 100644
index 0000000000..fe3d09212e
--- /dev/null
+++ b/Code/GameEngine/Source/GameClient/GUI/FontLibraryLookupView.h
@@ -0,0 +1,45 @@
+#ifndef BFME2_FONT_LIBRARY_LOOKUP_VIEW_H
+#define BFME2_FONT_LIBRARY_LOOKUP_VIEW_H
+
+class GameFont;
+struct Rva00475680Node;
+
+// The adjustment helper only needs the tree header at FontLibrary +0x20.
+// Its node/value view remains in GameFont.cpp; the lookup methods use the
+// existing table map at +0x14. Neither view allocates a FontLibrary object.
+class Rva00475680Tree
+{
+public:
+	Rva00475680Node *find(const AsciiString &key) const
+	{
+		return reinterpret_cast<Rva00475680Node *>(
+			reinterpret_cast<const _STL::map<AsciiString, AsciiString> *>(this)
+				->find(key)
+				._M_node);
+	}
+
+	Rva00475680Node *m_header;
+};
+
+class FontLibrary
+{
+public:
+	void *rva002186A6(const AsciiString *name, float size);
+	GameFont *getFont(const AsciiString *name, float size, bool bold);
+	GameFont *rva0021857E(const AsciiString *name, float size, bool bold, int style);
+	void rva00218468(const AsciiString *name, float *size, bool *bold);
+
+	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
+	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
+	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
+	virtual void slot12(); virtual void slot13();
+	virtual bool loadFontData(GameFont *font); // +0x38
+private:
+	char m_pad04[0x0C - 4];
+	GameFont *m_fontList; // +0x0C
+	int m_fontCount; // +0x10
+	_STL::map<AsciiString, AsciiString> m_tables; // +0x14
+	Rva00475680Tree m_fontSubstitution; // +0x20
+};
+
+#endif
diff --git a/Code/GameEngine/Source/GameClient/GUI/GameFont.cpp b/Code/GameEngine/Source/GameClient/GUI/GameFont.cpp
index edd01ddf9b..a8afadcc01 100644
--- a/Code/GameEngine/Source/GameClient/GUI/GameFont.cpp
+++ b/Code/GameEngine/Source/GameClient/GUI/GameFont.cpp
@@ -65,19 +65,7 @@ struct Rva00475680Node
 	Rva004779C0Vector *m_value;
 };
 
-class Rva00475680Tree
-{
-public:
-	Rva00475680Node *find(const AsciiString &key) const
-	{
-		return reinterpret_cast<Rva00475680Node *>(
-			reinterpret_cast<const _STL::map<AsciiString, AsciiString> *>(this)
-				->find(key)
-				._M_node);
-	}
-
-	Rva00475680Node *m_header;
-};
+#include "FontLibraryLookupView.h"
 
 struct Gen00473A40Elem
 {
@@ -100,18 +88,6 @@ struct Gen00473A40Less
 	unsigned char m_pad0x00;
 };
 
-class FontLibrary
-{
-public:
-	void rva00218468(const AsciiString *name, float *size, bool *style);
-
-	// Nothing before the tree is read here; the landed sibling
-	// FontLibraryFontList.cpp spells the real prefix (font list at +0x0C,
-	// count at +0x10, table map at +0x14), so this stays a pad.
-	char m_pad0x00[0x20];
-	Rva00475680Tree m_fontSubstitution;
-};
-
 struct Rva004738A0Obj
 {
 	int m_00;
```

## Bank publication audit

Fetched origin and audited complete pending `origin/master..HEAD` plus this evidence/log commit. The sole authored pending source commit is 82534d015b (in-place Smudge static ownership cleanup); new staged paths are this handoff and re_log.py output. No source moves or active new headers remain. Tools, hooks, workflows, includes, build inputs and registries require no path update; historical EA paths remain. Exact audit: build/codex-session9-gamefont-bank-path-audit.txt. Restored original GameFont sources verify 31/31 again. Abandoned source/header claims released; this evidence claim and three pending Smudge claims remain until publication.
