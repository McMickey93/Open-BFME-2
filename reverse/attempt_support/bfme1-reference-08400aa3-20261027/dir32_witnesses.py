"""Read existing, verified objects only; never invoke a compiler or alter cache."""
from pathlib import Path
import csv
import io
import json
import re
import struct
import subprocess
import sys

ROOT = Path.cwd()
sys.path.insert(0, str(ROOT / 'tools'))
import build

OUT = ROOT / 'build/bfme1-reference-08400aa3-20261027'
classes = ['BfmeMsgDN', 'HashTableIteratorClass', 'Rva002C00E0Obj',
           'Rva004E7392', 'Rva005CBB0AObj', 'W3DProjectedShadow']
symbols = {'??_7' + name + '@@6B@' for name in classes}
paths = subprocess.check_output(['rg', '-l', r'\b(' + '|'.join(classes) + r')\b',
                                'Code', '-g', '*.cpp', '-g', '*.c'], text=True).splitlines()
path_list = OUT / 'dir32-scope-paths.txt'
path_list.write_text('\n'.join(paths) + '\n')
selected = subprocess.check_output(['rg', '-F', '-f', str(path_list),
                                    'reverse/functions.csv'], text=True)
with Path('reverse/functions.csv').open() as handle:
    header = handle.readline()
rows = [row for row in csv.DictReader(io.StringIO(header + selected))
        if row.get('source') in paths and row.get('status') == 'matched']
witnesses = []
skips = []
for row in rows:
    symbol = build.ledger_object_symbol(row)
    if build.is_funclet_row(row, symbol):
        continue
    size = int(row['target_size'])
    obj = build.obj_path(ROOT / row['source'])
    try:
        body, relocs = build.read_object_symbol_bytes(obj, symbol, size)
    except (ValueError, FileNotFoundError) as exc:
        skips.append(dict(source=row['source'], rva=row['target_rva'], reason=str(exc)))
        continue
    for offset, kind, target in relocs:
        if kind != 6 or target not in symbols or offset + 4 > min(size, len(body)):
            continue
        native = build.read_target_bytes(int(row['target_rva'], 16) + offset, 4)
        final = struct.unpack('<I', native)[0]
        addend = struct.unpack_from('<I', body, offset)[0]
        witnesses.append(dict(symbol=target, source=row['source'], name=row['name'],
                              rva=row['target_rva'], operand_offset=offset,
                              native_value=hex(final), compiled_addend=hex(addend),
                              inferred_symbol_base=hex((final - addend) & 0xffffffff)))
by_symbol = {symbol: sorted({w['inferred_symbol_base'] for w in witnesses
                            if w['symbol'] == symbol}) for symbol in sorted(symbols)}
result = dict(scope='Existing current object relocations in name-selected C++ sources',
              model='gpt-6', compiler_invoked=False, source_modified=False,
              head=subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip(),
              symbol_bases=by_symbol, witnesses=witnesses, skipped_rows=skips)
(OUT / 'dir32-witnesses.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(rows=len(rows), witnesses=len(witnesses), skipped=len(skips),
                      symbol_bases=by_symbol), indent=2))
