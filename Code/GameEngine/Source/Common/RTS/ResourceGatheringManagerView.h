#pragma once

// Existing list-maintenance and transfer bodies share the measured prefix:
// primary vptr +0, warehouse list +4 and center list +8. Real STLport lists
// retain their single-node-pointer layout. The lifecycle donor supplies the
// empty polymorphic base and the four-slot abstract table; the transfer body
// defines slot three out of line even though that slot remains pure here.
#ifndef _STLP_NO_EXCEPTIONS
#define _STLP_NO_EXCEPTIONS 1
#endif
#include <list>

class Object;
class Xfer;
struct EmitVtableTag;

class ResourceGatheringManagerBase
{
public:
    virtual ~ResourceGatheringManagerBase() {}
};

class ResourceGatheringManager : public ResourceGatheringManagerBase
{
public:
    ResourceGatheringManager();
    // Existing deleter donor's non-retail vtable-emission constructor.
    ResourceGatheringManager(EmitVtableTag *);
    virtual ~ResourceGatheringManager();
    void removeSupplyCenter(Object *oldCenter);
    void removeSupplyWarehouse(Object *oldWarehouse);
    void addSupplyCenter(Object *newCenter);
    void addSupplyWarehouse(Object *newWarehouse);
    void rva004F5C44(Object *newCenter);
protected:
    virtual void slot1() = 0;
    virtual const char *name() const = 0;
    virtual void xfer(Xfer *xfer) = 0;
private:
    typedef _STL::list<int> objectIDList;
    objectIDList m_supplyWarehouses;
    objectIDList m_supplyCenters;
};
