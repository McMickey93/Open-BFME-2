// cl: /O1 /G7 /arch:SSE /MD /EHsc
// BF1 ba7ddda7e8f261163972ddbe23c7e7a12ac5b84f semantic donors:
// game/GameEngine/Source/GameLogic/System/BfmeCellGridXfer.cpp and BfmeCellGrid.cpp.
// Native 56C50E..56C716 transfer and 56C16D..56C21B evaluation, corroborated
// by WB144A4C0/144A2B0 and the rowed CellGrid constructor 56C266.
// BFME2 has twenty players and 168-byte cells. Xfer's native table 7BB910
// establishes Version slot10, float slot28 and unsigned-int slot30.
// Original method names remain unresolved; address-derived names are retained.
typedef bool Bool;
typedef int Int;
typedef unsigned int UnsignedInt;
typedef float Real;
typedef unsigned char UnsignedByte;

struct XferVersionFields
{
	UnsignedByte m_version;
	UnsignedByte m_currentVersion;
};


class Snapshot;
class AsciiString;
class UnicodeString;
class PooledString;
struct Coord3DBase;
struct ICoord3D;
struct Region3D;
class IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
class RealRange;
struct RGBColor;
class RGBAColorReal;
class RGBAColorInt;
struct XferUnknown11;
#include "../../../Include/Common/BfmeXfer.h"

class Xfer::Version
{
public:
	union {
		XferVersionFields m_fields;
		UnsignedInt m_value;
	};
};

class Rva00404781
{
public:
	void rva0040475C();
	Real m_first[20];
	Real m_second[20];
	UnsignedInt m_firstMask;
	UnsignedInt m_secondMask;
};

class Rva00404781;
class Rva00404927
{
public:
	int rva00404927(Rva00404781 *cell, int player);
};
class Rva00404C26
{
public:
	Rva00404927 *rva00404C26(int player);
};
class VictorySystem;
extern VictorySystem *TheVictorySystem;

class CellGrid
{
public:
	Bool rva0056C50E(Xfer *xfer);
	Int rva0056C16D();

private:
	Int m_width;
	Int m_height;
	UnsignedInt m_cellCount;
	Real m_cellSize;
	Real m_offset;
	Rva00404781 *m_cells;
	UnsignedInt *m_cellValues;
};

Bool CellGrid::rva0056C50E(Xfer *xfer)
{
	Xfer::Version version;
	version.m_fields.m_version = 1;
	version.m_fields.m_currentVersion = 1;
	xfer->operator==(version);

	UnsignedInt cellCount = m_cellCount;
	UnsignedInt cellIndex;
	Bool mismatch = false;
	if (xfer->IsLoading())
	{
		Int width = m_width;
		Int height = m_height;
		Real cellSize = m_cellSize;
		Real offset = m_offset;

		xfer->operator==(*reinterpret_cast<UnsignedInt *>(&width));
		xfer->operator==(*reinterpret_cast<UnsignedInt *>(&height));
		xfer->operator==(cellCount);
		xfer->operator==(cellSize);
		xfer->operator==(offset);

		mismatch = m_width != width || m_height != height ||
			m_cellCount != cellCount || m_cellSize != cellSize ||
			m_offset != offset;
	}
	else
	{
		xfer->operator==(*reinterpret_cast<UnsignedInt *>(&m_width));
		xfer->operator==(*reinterpret_cast<UnsignedInt *>(&m_height));
		xfer->operator==(m_cellCount);
		xfer->operator==(m_cellSize);
		xfer->operator==(m_offset);
	}

	if (mismatch)
	{
		for (cellIndex = 0; cellIndex < cellCount; ++cellIndex)
		{
			for (Int playerIndex = 0; playerIndex < 20; ++playerIndex)
			{
				xfer->operator==(m_cells[0].m_first[0]);
				xfer->operator==(m_cells[0].m_second[0]);
			}
			xfer->operator==(m_cells[0].m_firstMask);
			xfer->operator==(m_cells[0].m_secondMask);
		}
	}
	else
	{
		for (cellIndex = 0; cellIndex < m_cellCount; ++cellIndex)
		{
			for (Int playerIndex = 0; playerIndex < 20; ++playerIndex)
			{
				xfer->operator==(m_cells[cellIndex].m_first[playerIndex]);
				xfer->operator==(m_cells[cellIndex].m_second[playerIndex]);
			}
			xfer->operator==(m_cells[cellIndex].m_firstMask);
			xfer->operator==(m_cells[cellIndex].m_secondMask);
		}

		if (xfer->IsLoading())
			rva0056C16D();
	}
	return mismatch;
}


Int CellGrid::rva0056C16D()
{
	Int affected = 0;
	for (UnsignedInt cellIndex = 0; cellIndex < m_cellCount; ++cellIndex)
	{
		m_cellValues[cellIndex] = 0;
		if (m_cells[cellIndex].m_firstMask != 0)
		{
			for (UnsignedInt playerIndex = 0; playerIndex < 20; ++playerIndex)
			{
				if ((m_cells[cellIndex].m_firstMask & (1 << playerIndex)) != 0)
				{
					Rva00404927 *parameters = ((Rva00404C26 *)TheVictorySystem)
						->rva00404C26((Int)playerIndex);
					if (parameters != 0 && (unsigned char)parameters->rva00404927(
						&m_cells[cellIndex], (Int)playerIndex) != 0)
					{
						m_cellValues[cellIndex] |= (1 << playerIndex);
						m_cells[cellIndex].rva0040475C();
						++affected;
					}
				}
			}
		}
	}
	return affected;
}
