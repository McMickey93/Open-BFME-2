// cl: /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// BFME1 1281192f682ce6f29b8f06b7daea4b5e8fdfbb24 and ZH GameState.cpp
// establish the registration purpose and nested record relationship. Native
// 2DE34B independently tests the string and Snapshot pointer then copies an
// 8-byte record: Snapshot pointer at +0 and AsciiString at +4. Its list array
// is at receiver+0x10 with a four-byte stride. Unused prefix remains opaque;
// this TU does not assert a complete GameState layout or names for kinds 3/4.
// Native initializer 2DE641 repeatedly calls this helper with CHUNK_ labels.
// The native insertion chain proves push_back2DDEA6 -> insert2DDE02 ->
// create_node2DD021 -> Construct2DCD64 -> copyCF475 -> StringBase copy365F0.
// The 29-byte SnapshotBlock copy folds onto the existing CF475 owner. The
// genuine Construct owns2DCD64; its native EH graph binds cleanup778027 and
// handler778035. Their proper home replaces the obsolete TreeKey alias view.
// All six complete emitted extents match strictly with the actual callees.
// stlport
#include <list>
#include "ascii_string.h"

// _List_iterator comparisons otherwise instantiate the base-class
// operator!= COMDAT (one byte shape per TU flags); exact-match free
// overloads take those calls instead so this TU emits no external copy.
namespace _STL {
template <class _IterTp, class _LeftTraits, class _RightTraits>
static inline bool operator!=(const _List_iterator<_IterTp, _LeftTraits> &a,
                              const _List_iterator<_IterTp, _RightTraits> &b)
{ return a._M_node != b._M_node; }
}
class Snapshot;
// Xfer as xferSaveData calls it (slot 2 returns the save/load mode as a bool;
// each named slot is read off retail 0x002DCE24's call offsets).
class AsciiString;
class UnicodeString;
class PooledString;
struct Coord3DBase;
struct ICoord3D;
struct Region3D;
struct IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
struct RealRange;
struct RGBColor;
struct RGBAColorReal;
struct RGBAColorInt;
#include "../../../../Include/Common/BfmeXfer.h"
// VA 0x00DBD038, ZH's SAVE_FILE_EOF token pointer.
extern const char *SAVE_FILE_EOF;
enum SnapshotType { SNAPSHOT_SAVELOAD=0, SNAPSHOT_DEEPCRC_LOGICONLY=1, SNAPSHOT_NATIVE3=3, SNAPSHOT_NATIVE4=4 };
class GameState
{
    struct SnapshotBlock { Snapshot *snapshot; AsciiString blockName; };
    char m_opaque00[0x10];
    _STL::list<SnapshotBlock> m_snapshotBlockList[5];
    void addSnapshotBlock(AsciiString blockName, Snapshot *snapshot, SnapshotType which);
    SnapshotBlock *findBlockInfoByToken(AsciiString token, SnapshotType which);
public:
    void xferSaveData(Xfer *xfer, SnapshotType which);
};
void GameState::addSnapshotBlock(AsciiString blockName, Snapshot *snapshot, SnapshotType which)
{
    if (blockName.isEmpty() || snapshot == 0)
        return;
    SnapshotBlock blockInfo;
    blockInfo.snapshot = snapshot;
    blockInfo.blockName = blockName;
    m_snapshotBlockList[which].push_back(blockInfo);
}
// Native 2DCDBF is the ZH lookup: empty-token early out, then a walk of
// m_snapshotBlockList[which] comparing each record's name (+4) against the
// by-value token through compare 0x69D6. Callers 2DCE24 and the save-file
// reader 2DEEC3 pass the chunk token read from the file.
GameState::SnapshotBlock *GameState::findBlockInfoByToken(AsciiString token, SnapshotType which)
{
    if (token.isEmpty())
        return 0;
    SnapshotBlock *blockInfo;
    _STL::list<SnapshotBlock>::iterator it;
    for (it = m_snapshotBlockList[which].begin(); it != m_snapshotBlockList[which].end(); ++it)
    {
        blockInfo = &(*it);
        if (blockInfo->blockName == token)
            return blockInfo;
    }
    return 0;
}
// Native 2DCE24 is ZH's xferSaveData without the null-xfer check: the save
// branch writes each block's name then the block inside a rethrowing try and
// ends with the SAVE_FILE_EOF token; the load branch reads tokens until EOF,
// skipping unknown blocks. Callers: saveGame 2DD38D, the CRC friend 2DDD0B.
// Both catch (...) trys share the rethrow funclet 2DCF62 (inside the extent).
void GameState::xferSaveData(Xfer *xfer, SnapshotType which)
{
    if (xfer->IsStoring())
    {
        SnapshotBlock *blockInfo;
        _STL::list<SnapshotBlock>::iterator it;
        AsciiString blockName;
        for (it = m_snapshotBlockList[which].begin(); it != m_snapshotBlockList[which].end(); ++it)
        {
            blockInfo = &(*it);
            blockName = blockInfo->blockName;
            *xfer == blockName;
            try
            {
                xfer->BeginBlock("Snapshot");
                *xfer == *blockInfo->snapshot;
                xfer->EndBlock();
            }
            catch (...)
            {
                throw;
            }
        }
        AsciiString eofToken = SAVE_FILE_EOF;
        *xfer == eofToken;
    }
    else
    {
        AsciiString token;
        bool done = false;
        SnapshotBlock *blockInfo;
        while (done == false)
        {
            *xfer == token;
            if (((const StringBase<char> &)(token)).compareNoCase(SAVE_FILE_EOF) == 0)
            {
                done = true;
            }
            else
            {
                blockInfo = findBlockInfoByToken(token, which);
                if (blockInfo == 0)
                {
                    xfer->SkipBlock("Snapshot");
                    continue;
                }
                try
                {
                    xfer->BeginBlock("Snapshot");
                    *xfer == *blockInfo->snapshot;
                    xfer->EndBlock();
                }
                catch (...)
                {
                    throw;
                }
            }
        }
    }
}
