"""header_adopt_lane: source surgery, header generation, failure taxonomy and the closure check."""
import csv
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import header_adopt_lane as lane  # noqa: E402

UNIT = """// cl: /O2
typedef float Real;
// struct Coord3D { int fake; };
struct Coord3D
{
    Real x, y, z;
    void zero() { x = y = z = 0.0f; }
};
template <class T>
class StringBase { T *p; };
class AsciiString : public StringBase<char> { char *m_data; };
void use(Coord3D *c) { c->zero(); }
"""

CONTRACT = {"class": "Coord3D", "key": "struct", "key_by": "bytes", "size": 12, "size_by": "zh", "bases": [],
            "fields": [{"offset": o, "size": 4, "kind": "f4", "type": "float", "name": n}
                       for o, n in ((0, "x"), (4, "y"), (8, "z"))]}


@pytest.fixture(params=["Coord2D", "Coord3D"])
def constructor_companion(tmp_path, monkeypatch, request):
    name = request.param
    directory = "Code/Libraries/Include/Lib"
    header = f"{directory}/{name}.h"
    companion = f"{directory}/{name}CtorView.h"
    for path in (header, companion):
        full = tmp_path / path
        full.parent.mkdir(parents=True, exist_ok=True)
        full.write_text(f"class {name} {{}};\n")
    source = "Code/Body.cpp"
    body = tmp_path / source
    body.write_text(f'#include "Libraries/Include/Lib/{name}CtorView.h"\n')
    queue = tmp_path / "header_queue.tsv"
    queue.write_text("class\tsource\theader\n" + f"{name}\t{source}\t{header}\n")
    monkeypatch.setattr(lane, "ROOT", tmp_path)
    monkeypatch.setattr(lane, "QUEUE", queue)
    monkeypatch.setattr(lane, "registered", lambda: {name: header})
    monkeypatch.setattr(lane, "tracked_headers", lambda: [header, companion])
    calls = []
    monkeypatch.setattr(lane, "gate_one", lambda source: calls.append(source))
    return name, source, header, companion, body, queue, calls


def test_constructor_companion_uses_the_same_default_and_explicit_verdict(constructor_companion):
    name, source, header, companion, body, queue, calls = constructor_companion
    # The CLI and repair_queue's trusted-base verdict must agree without --header.
    assert lane.verdict(name, source) == []
    assert lane.verdict(name, source, header=header) == []
    assert lane.accept(name, [source]) == 0
    assert queue.read_text() == "class\tsource\theader\n"
    assert calls == [source, source, source]


def test_constructor_companion_cannot_retire_a_byte_mismatch(constructor_companion, monkeypatch):
    name, source, header, companion, body, queue, calls = constructor_companion
    before = queue.read_bytes()
    monkeypatch.setattr(lane, "gate_one", lambda source: "byte mismatch")
    assert lane.verdict(name, source) == ["byte mismatch"]
    assert lane.accept(name, [source]) == 1
    assert queue.read_bytes() == before


@pytest.mark.parametrize("case", ["comment", "disabled", "private", "missing", "ambiguous",
                                  "unapproved", "other-class", "other-header"])
def test_constructor_companion_does_not_bypass_adoption_checks(constructor_companion, monkeypatch, case):
    name, source, header, companion, body, queue, calls = constructor_companion
    text = body.read_text()
    explicit = None
    if case == "comment":
        body.write_text("/*\n" + text + "*/\n")
    elif case == "disabled":
        body.write_text("#if 0\n" + text + "#endif\n")
    elif case == "private":
        body.write_text(f"class {name} {{ float x, y; }};\n" + text)
    elif case == "missing":
        (lane.ROOT / companion).unlink()
    elif case == "ambiguous":
        body.write_text(f'#include "{name}CtorView.h"\n')
        monkeypatch.setattr(lane, "tracked_headers", lambda: [header, companion, f"Code/Other/{name}CtorView.h"])
    elif case in ("unapproved", "other-class"):
        fake = (f"Code/Other/{name}CtorView.h" if case == "unapproved" else
                "Code/Libraries/Include/Lib/" + ("Coord3D" if name == "Coord2D" else "Coord2D") + "CtorView.h")
        (lane.ROOT / fake).parent.mkdir(parents=True, exist_ok=True)
        (lane.ROOT / fake).write_text(f"#define CANONICAL_{name.upper()}_H\nclass {name} {{}};\n")
        body.write_text(f'#include "{fake.removeprefix("Code/")}"\n')
    elif case == "other-header":
        explicit = f"Code/Other/{name}.h"
        (lane.ROOT / explicit).parent.mkdir(parents=True)
        (lane.ROOT / explicit).write_text(f"class {name} {{}};\n")
    problems = lane.verdict(name, source, header=explicit)
    assert problems, case
    assert any(("private body" if case == "private" else "does not #include") in p for p in problems)
    assert calls == [source]  # Even rejected includes still run the byte gate.


def test_consolidation_transfers_all_debt_and_only_acceptance_retires_it(tmp_path, monkeypatch):
    queue = tmp_path / "header_queue.tsv"
    cols = ["class", "source", "retail_rvas", "header", "failure", "retry_budget", "acceptance"]
    rows = [dict(zip(cols, ["Coord3D", source, rva, "Coord3D.h", "original failure", "3",
                           lane.acceptance_command("Coord3D", source)]))
            for source, rva in [("Code/A.cpp", "0x10"), ("Code/B.cpp", "0x20"),
                                ("Code/Other.cpp", "0x30")]]
    with queue.open("w", newline="") as handle:
        writer = csv.DictWriter(handle, cols, delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    assert lane.transfer_sources(["Code/A.cpp", "Code/B.cpp"], "Code/T.cpp", queue) == 2
    with queue.open(newline="") as handle:
        moved = list(csv.DictReader(handle, delimiter="\t"))
    assert len(moved) == len(rows)
    for before, after in zip(rows[:2], moved[:2]):
        assert after == dict(before, source="Code/T.cpp",
                             acceptance=lane.acceptance_command("Coord3D", "Code/T.cpp"))
    assert moved[2] == rows[2]
    monkeypatch.setattr(lane, "QUEUE", queue)
    monkeypatch.setattr(lane, "ROOT", tmp_path)
    monkeypatch.setattr(lane, "verdict", lambda *args: ["not adopted"])
    assert lane.accept("Coord3D", ["Code/T.cpp"]) == 1
    assert len(list(csv.DictReader(queue.open(), delimiter="\t"))) == 3
    monkeypatch.setattr(lane, "verdict", lambda *args: [])
    assert lane.accept("Coord3D", ["Code/T.cpp"]) == 0
    assert list(csv.DictReader(queue.open(), delimiter="\t")) == rows[2:]


def test_swap_strips_the_view_and_includes_the_header_where_it_stood():
    out = lane.swap(UNIT, ["Coord3D"], "../Lib/Coord3D.h")
    assert "Real x, y, z;" not in out
    assert out.index('#include "../Lib/Coord3D.h"') < out.index("void use")
    assert "// struct Coord3D { int fake; };" in out          # a commented-out head is not a view
    assert lane.swap("void f();\n", ["Coord3D"], "x.h") is None


def test_dependency_views_go_with_the_class():
    out = lane.swap(UNIT, ["AsciiString", "StringBase"], "ascii_string.h")
    assert "StringBase" not in out.split("void use")[0].split('#include "ascii_string.h"')[1]
    assert "template <class T>" not in out
    assert out.count('#include "ascii_string.h"') == 1


def test_generated_header_spells_the_contract():
    text = lane.generate(CONTRACT, "data", {})
    assert "struct Coord3D {" in text and "float x;" in text and "float z;" in text
    assert "Coord3D() {}" not in text
    assert "Coord3D() {}" in lane.generate(CONTRACT, "data+ctor", {})


def test_failure_taxonomy():
    assert lane.failure_class("x.cpp(3) : error C2039: 'zero' : is not a member") == "C2039 missing member"
    assert lane.failure_class("x.cpp(3) : error C2371: 'Bool' : redefinition") == "C2371"
    assert lane.failure_class("Functions: FAIL ?f@@YAXXZ") == "bytes/callee identity"


def test_closure_diff_flags_lost_rows(tmp_path):
    head = "name,retail_rva,closed_strict\n"
    before, same, lost = tmp_path / "a.csv", tmp_path / "b.csv", tmp_path / "c.csv"
    before.write_text(head + "?f@@YAXXZ,0x00401000,1\n?g@@YAXXZ,0x00401010,0\n")
    same.write_text(head + "?f@@YAXXZ,0x00401000,1\n?g@@YAXXZ,0x00401010,1\n")
    lost.write_text(head + "?f@@YAXXZ,0x00401000,0\n?g@@YAXXZ,0x00401010,1\n")
    assert lane.closure_diff(before, same) == 0      # negative control: closure only grew
    assert lane.closure_diff(before, lost) == 1      # positive control: a closed row was lost


def test_view_methods_merge_void_spelling_and_skip_declspec_special_members(tmp_path, monkeypatch):
    # Region3D views spell width() and width(void), and declare
    # `__declspec(nothrow) Region3D(const Region3D&);`: both once made every
    # generated methods header C2535.
    monkeypatch.setattr(lane, "ROOT", tmp_path)
    (tmp_path / "a.cpp").write_text("struct Region3D {\n    float lo, hi;\n"
                                    "    float width() const { return hi - lo; }\n"
                                    "    bool in(const Coord3D *p) const;\n"
                                    "    __declspec(nothrow) Region3D(const Region3D&);\n};\n")
    (tmp_path / "b.cpp").write_text("struct Region3D {\n    float lo, hi;\n"
                                    "    float width(void) const { return hi - lo; }\n"
                                    "    bool in(const Coord3D *query) const { return query != 0; }\n};\n")
    assert len(lane.view_methods("Region3D", ["a.cpp", "b.cpp"])) == 1   # in() names a class not included
    methods = lane.view_methods("Region3D", ["a.cpp", "b.cpp"], {"Coord3D"})
    assert len(methods) == 2                    # one width, one in(): pointer parameter names do not count
    assert "{" in methods[lane.signature("bool in(const Coord3D *p) const;", "Region3D")]   # the body wins


def test_view_methods_keeps_hump_underscore_identifiers(tmp_path, monkeypatch):
    # WWLib method names are hump-underscore identifiers (Delete_This,
    # Add_Ref); the old all-uppercase-sounds-like-a-type filter dropped every
    # such method, so generated headers shipped vtables whose slot 0 was the
    # delete-dtor instead of the base class's Delete_This.
    monkeypatch.setattr(lane, "ROOT", tmp_path)
    (tmp_path / "rc.cpp").write_text(
        "class RefCountClass {\n"
        "public:\n"
        "    void Release_Ref(void);\n"
        "    virtual void Delete_This(void);\n"
        "    virtual ~RefCountClass(void);\n"
        "private:\n"
        "    int NumRefs;\n};\n")
    methods = lane.view_methods("RefCountClass", ["rc.cpp"])
    assert "virtual void Delete_This(void);" in " ".join(methods.values())


def test_generated_header_orders_destructor_last():
    # A leading destructor would put the delete-dtor in the class vtable's
    # first slot; the donor order keeps member virtuals before it.
    methods = {"void Delete_This();": "virtual void Delete_This();",
               "~dtor": "virtual ~RefCountClass(void) {}"}
    contract = {"class": "RefCountClass", "key": "class", "key_by": "bytes", "size": 8, "size_by": "zh",
                "bases": [], "fields": []}
    text = lane.generate(contract, "data+methods", methods, None)
    assert text.index("Delete_This") < text.rindex("~RefCountClass")
