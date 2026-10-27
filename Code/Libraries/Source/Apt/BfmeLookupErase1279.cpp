// cl: /MD
// ?Unset@AptNativeHash@@QAEXQBVEAStringC@@@Z @0x0070B2C0 191B.
// AptNativeHash::Set's null-value branch calls this (AptNativeHash.cpp): erase
// the key's entry through HashFindKey 0x0070AF90 and UnsetAt, else release the
// prototype (+0xC) or __proto__ (+0x8) slot whose name matches. The ids
// 0x699/0x6bbd and GetString indices 0x78/0 are the ones the constructor
// asserts for SC_prototype and SC___proto__. Callers 0x006F7275 and 0x006F80C0.
class EAStringC
{
public:
	bool IsEmpty() const;
	unsigned short rva006D3D10() const;
	void rva006D3470();
	bool rva006D3560(const EAStringC *other) const;
};
EAStringC *Rva0070B4F0GetString(int index);
struct AptHashItem;
class AptValue
{
public:
	virtual void AddRef();
	virtual void Release();
};
class AptNativeHash
{
	int mnTotalSize;
	void *mpData;
	AptValue *mp__proto__;
	AptValue *mpPrototype;
	unsigned int nEventHandlers;
public:
	void Unset(const EAStringC *const);
	static void UnsetAt(void *pHashItem);
private:
	AptHashItem *HashFindKey(const EAStringC *const) const;
};
void AptNativeHash::Unset(const EAStringC *const pKey)
{
	if (pKey->IsEmpty())
		return;
	unsigned int id = pKey->rva006D3D10();
	if (mpData != 0) {
		AptHashItem *found = HashFindKey(pKey);
		if (found != 0) {
			((EAStringC *)found)->rva006D3470();
			UnsetAt(found);
			return;
		}
	}
	if (id == 0x699) {
		if (pKey->rva006D3560(Rva0070B4F0GetString(0x78))) {
			if (mpPrototype != 0) {
				mpPrototype->Release();
				mpPrototype = 0;
			}
		}
	}
	else if (id == 0x6bbd) {
		if (pKey->rva006D3560(Rva0070B4F0GetString(0))) {
			if (mp__proto__ != 0) {
				mp__proto__->Release();
				mp__proto__ = 0;
			}
		}
	}
}
