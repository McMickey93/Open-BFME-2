import sys
from pathlib import Path
sys.path.insert(0, str(Path.cwd() / 'tools'))
import build

source = Path('Code/GameEngineDevice/Source/W3DDevice/GameClient/Water/W3DWaterRva0007F0FB.cpp').resolve()
old_name = '?BFME_DX8_Thread_Assert@@YAXXZ'
new_name = '?BFME_DX8_Thread_Assert@@YA_NXZ'

def code_sections(path):
    stat = path.stat()
    data, sections, symbols = build._object_layout(str(path), stat.st_mtime_ns, stat.st_size)
    result = []
    for number, section in enumerate(sections, 1):
        if not section['characteristics'] & 0x20:
            continue
        start = section['raw_pointer']
        names = sorted((s['name'], s['value']) for s in symbols if s['section'] == number)
        refs = []
        for i in range(section['reloc_count']):
            offset = section['reloc_pointer'] + 10 * i
            refs.append((build.u32(data, offset), build.u16(data, offset + 8),
                         symbols[build.u32(data, offset + 4)]['name']))
        result.append((section['name'], section['characteristics'], names,
                       data[start:start + section['raw_size']], refs))
    return result

before = code_sections(Path('build/resume-eh-local/turn80-water/before.obj'))
after = code_sections(build.obj_path(source))
assert len(before) == len(after)
changes = []
for old, new in zip(before, after):
    assert old[:4] == new[:4], 'Executable section metadata or bytes changed'
    assert len(old[4]) == len(new[4])
    for a, b in zip(old[4], new[4]):
        if a != b:
            assert a[:2] == b[:2] and a[2] == old_name and b[2] == new_name, (a, b)
            changes.append((old[2], a, b))
assert len(changes) == 2, changes
print(f'{len(before)} executable sections: all bytes, flags and defined symbols unchanged.')
print('Exactly two REL32 referents change from the void alias to the rowed bool owner:')
for names, old, new in changes:
    print(names, old, '->', new)
