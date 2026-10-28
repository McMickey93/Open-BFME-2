// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva005533BC@Rva005533BC@@QAEPAXPBX@Z @0x005533BC 37B
// Evidence: unlock lane tree lower_bound byte key at +0x10 left +8 right +0xC
// header root at +4 via holder at +0; callers 0x005538BE 0x00554822 0x00554868
// 0x005548B1 unclaimed; LINK BONUS via 0x0055485B 0x00554816; frameless /O1.
struct Rva005533BCNode {
  char pad00[8];
  Rva005533BCNode *m_left;
  Rva005533BCNode *m_right;
  unsigned char key10;
};
struct Rva005533BCRoot {
  char pad00[4];
  Rva005533BCNode *m_root;
};
class Rva005533BC {
public:
  Rva005533BCRoot *holder00;
  void *rva005533BC(const void *key);
};
void *Rva005533BC::rva005533BC(const void *key)
{
  Rva005533BCRoot *header = holder00;
  Rva005533BCNode *node = header->m_root;
  if (node == 0)
    return header;
  unsigned char k = *(const unsigned char *)key;
  void *ret = header;
  while (node != 0) {
    if (node->key10 >= k) {
      ret = node;
      node = node->m_left;
    } else
      node = node->m_right;
  }
  return ret;
}
