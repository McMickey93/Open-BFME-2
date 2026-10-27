# matpass.cpp consolidation: flag conflict behind the rejected donors (claudeb, 2026-10-27)

Target facts (retail bytes, read at the RVAs):

- The approved matpass rows (0x0013EDD0 ctor, 0x0013EE40 dtor, 0x0013EEB0 stage
  setter, 0x0013EF40 stage getter, 0x0013EF70 material getter, 0x0013EFA0
  Install_Materials) all use the `/G7` refcount forms: `add dword [x+4],-1` and
  `add word [x+4],1`. That is the WW3D2 region default (`/O2 /arch:SSE /G7`).
- The seed `matpass.cpp` also holds two *displaced* rows with no TU in the map:
  `Set_Material` 0x0030D3AD (39 B) and `Peek_Texture` 0x002C7469 (11 B). The
  0x0030D3AD body uses `inc dword [edi+4]` / `dec dword [ecx+4]`, the blend form.
  That is why `reverse/flag_overrides.csv` gives matpass.cpp the empty override:
  under the region default, the seed loses this row.
- The seed's flags are carried into the merge, so every `/G7` donor loses its
  rows. This is the "loses 2 rows under the carried flag override ''" rejection
  for the destructor and Install_Materials. The stage setter and getter
  ("no baseline match") use the same `add word` form.

Structural inference (not verified by a build): the BFME2 class is ZH's layout
with `RefCountPtr<TextureClass> Texture[8]`. The ctor passes the stage
ctor/dtor 0x00326BE6/0x0017098D to `__ehvec_ctor`; the dtor runs the vector
dtor after REF_PTR_RELEASE(Material). The stage setter at 0x0013EEB0 is
`Texture[stage] = tex` on a RefCountPtr. The getter at 0x0013EF40 returns
`Texture[stage]` by value. 0x0013EF70 is ZH `Get_Material`. A TU-scoped
`matpass.h` shim with that member type would let the donors drop their private
views.

Prerequisite before any merge: `Set_Material` 0x0030D3AD (and `Peek_Texture`
0x002C7469) need an owning unit, i.e. the TU whose header-inline COMDAT copy
retail kept, approved in `reverse/tu_map.csv`. Then move them out of
matpass.cpp and prune the empty override (`flag_defaults.py propose`). Moving
them now would be a move outside an approved unit. No edits made; claim
released.
