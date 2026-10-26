// cl: /DNDEBUG /MD
// ??0Rva000647D4@@QAE@XZ @0x000647B5 25B: empty derived ctor over GODupBase then own two vtables. Evidence: calls rowed GODupBase ctor 0x00306782 then two vptr stores; same two-base shape as GODupBase; caller 0x00042036.
// Same class as the rowed destructor ??1Rva000647D4@@UAE@XZ (0x000647D4,
// LocomotorDerivedDtors.cpp): this ctor stores vptr 0xBC5A5C, whose slot 0 is
// that class's scalar deleting destructor 0x00064809. The view below is
// LocomotorDerivedDtors.cpp's, so both units emit the same vftables.

class LocomotorPrimaryBase
{
protected:
	virtual ~LocomotorPrimaryBase();
};

class LocomotorSnapshotBase
{
protected:
	virtual ~LocomotorSnapshotBase();
};

class GODupBase : public LocomotorPrimaryBase, public LocomotorSnapshotBase
{
public:
	GODupBase();
	virtual ~GODupBase();
};

class Rva000647D4 : public GODupBase
{
public:
	Rva000647D4();
	virtual ~Rva000647D4();
};

Rva000647D4::Rva000647D4()
{
}
