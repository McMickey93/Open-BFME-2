// cl: /DNDEBUG /MD
// ??0Rva00785140Handle@@QAE@ABVAssetReference@@@Z @0x000A9EB2 27B handle-from-AssetReference ctor: vtable 0x00BC940C at [this] then AssetReference copy at +4 via ??0AssetReference@@QAE@ABV0@@Z rowed; caller 0x000AB193
class AssetReference
{
public:
    AssetReference(const AssetReference &that);
};
extern "C" const void *const __identifier("??_7Rva00785140Handle@@6B@")[];
class Rva00785140Handle
{
public:
    Rva00785140Handle(const AssetReference &that);
private:
    const void *m_vptr;
    AssetReference m_ref;
};
Rva00785140Handle::Rva00785140Handle(const AssetReference &that) : m_vptr(__identifier("??_7Rva00785140Handle@@6B@")), m_ref(that)
{
}

