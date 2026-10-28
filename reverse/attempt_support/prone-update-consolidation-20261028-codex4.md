# ProneUpdate consolidation trial

At base `fc86ff7e0c`, the approved destination is `ProneUpdate.cpp` and
the whole-file constructor donor is `ProneUpdateCtor.cpp`. Two other sources
are mixed. Both whole files pass the frozen-file check. The planner identifies
the donor as a whole-file candidate and flags macro context, internal linkage
and data-ledger review.

The destination models `UpdateModule` with polymorphic bases; the constructor
donor models its vtable slots as explicit fields. `tu_views.py` reports the
base view conflict and reverts its attempted class reconciliation because the
donor lacks `getModuleData`. A dry merge initially rejects the missing
constructor declaration. Adding declarations to the destination preserves its
8/8 rows. Replacing the donor's field stores with equivalent offset stores
preserves its 1/1 row in isolation, but the dry merge rejects the composed
object on bytes. Both trial edits were reverted.

Next compare the composed constructor's emitted bytes and vtable relocations
with retail, including compiler-generated polymorphic construction, before
choosing a coherent class view. The dry-run link guard identifies both original
files as census-linked; no move or linking gain is claimed.
