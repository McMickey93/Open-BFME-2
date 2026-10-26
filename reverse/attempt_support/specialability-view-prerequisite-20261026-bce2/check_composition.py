import sys
from pathlib import Path
sys.path.insert(0, str(Path.cwd() / 'tools'))
import allowed_symbols
import build
import link_batch_audit
import link_census
import link_check

source = 'Code/GameEngine/Source/GameLogic/Object/Update/SpecialAbilityUpdate.cpp'
donor = 'Code/GameEngine/Source/GameLogic/Object/Update/Rva0044EECACheck.cpp'
index = link_check.load_index()
rows = link_census.ledger()
truth = link_census.RetailTruth(rows)
obj = build.obj_path(Path.cwd() / source)
assert link_census.object_current(Path.cwd() / source, obj)
assert not (Path.cwd() / donor).exists()
assert not any(row['source'] == donor for row in rows)
retired = index['blockers'][donor]['object']
updated = link_batch_audit.overlay(index, [obj], {retired}, truth)
updated['selection'] = {**index['selection'], 'owners': dict(link_census.ledger_owners(rows))}
result = link_check.check_object(obj, updated, truth, source)
print('Published index:', index.get('meta'))
print('Current receipt:', obj.name)
print('Retired donor object:', retired)
print('Composition result:', result)
ident, scoped_rows = allowed_symbols.load([source])
found = allowed_symbols.scan(ident, scoped_rows)
for row, where, kind, name, target, classification, detail in found:
    if row['target_rva'].lower() == '0x0044eeca':
        print('Moved predicate binding:', where, name, hex(target), classification, detail)
