// Partial layout from reverse/class_contracts/Rva0007DF07.json.
// Retail 7DF07 zeros +4 before installing BC6F20; 4E84A4 restores that
// vptr, whose only slot is deleting destructor 7E5EE. Original names and
// the complete original class hierarchy remain unknown.
//
// The word at +4 is an ordinary member. cl 13.10 /O1 schedules the
// out-of-line constructor's zero store ahead of the vptr store (7DF07),
// while a virtual-base construction inlined into a derived constructor
// keeps the vptr store first (5CC5E5, 5CDA92, 5EAF2E), as retail does.
#ifndef CANONICAL_RVA0007DF07_H
#define CANONICAL_RVA0007DF07_H

class Rva0007DF07 {
public:
    Rva0007DF07() : m_04(0) {}
    virtual ~Rva0007DF07() {}
    unsigned int m_04;
};

#endif // CANONICAL_RVA0007DF07_H
