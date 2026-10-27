// cl: /DNDEBUG /MD /EHsc
//
// ?Save_Class_Info@AggregateDefClass@@MAE?AW4WW3DErrorType@@AAVChunkSaveClass@@@Z,
// retail 0x001A3690, 60 bytes. Dedicated TU: BFME2 keeps the aggregate Save
// family as plain success flags (retail checks cmp al,1 and returns mov
// al,bl), while the Zero Hour reference header declares WW3DErrorType.
// Declared locally with bool returns in BFME1 virtual order (sibling
// AggregateDefSaveW3D/AggregateDefReadSubobject precedent); the retail
// vtable 0x00BD6C70 drops the ZH Load_Assets/Create_Render_Object slots, so
// Is_Object_In_List sits at +0x3C and Build_Subobject_List at +0x40.
// Members mirror the ZH layout with the 24-byte subobject-list head:
// version +4, list +8, info name +20, subobject count +40, class id +44,
// flags +48, name +58. Chunk helpers resolve through the rowed chunkio
// bodies; W3D_CHUNK_AGGREGATE_CLASS_INFO is 0x604.

class ChunkLoadClass;
class RenderObjClass;
struct W3dAggregateSubobjectStruct;
template <class T> class DynamicVectorClass;

// Kernel32 string import (sweep/winbase_shim.h idiom, kept TU-local so this
// self-contained unit needs no include chain): retail calls the IAT slot
// directly.
extern "C" __declspec(dllimport) char * __stdcall lstrcpyn(char *, const char *, int);

struct W3dAggregateHeaderStruct
{
	unsigned Version; // W3D_CURRENT_AGGREGATE_VERSION is 0x10003
	char Name[16];
};

struct W3dAggregateInfoStruct
{
	char BaseModelName[32];
	unsigned SubobjectCount;
};

struct W3dAggregateMiscInfo
{
	unsigned OriginalClassID;
	unsigned Flags;
	unsigned reserved[3];
};

class ChunkSaveClass
{
public:
	bool Begin_Chunk(unsigned long chunk_type);
	unsigned long Write(const void *buffer, unsigned long size);
	bool End_Chunk();
};

class AggregateDefClass
{
public:
	virtual ~AggregateDefClass();
	virtual int Load_W3D(class ChunkLoadClass &chunk_load);
	virtual bool Save_W3D(ChunkSaveClass &chunk_save);
protected:
	virtual bool Read_Header(class ChunkLoadClass &chunk_load);
	virtual int Read_Info(class ChunkLoadClass &chunk_load);
	virtual bool Read_Subobject(class ChunkLoadClass &chunk_load);
	virtual int Read_Class_Info(class ChunkLoadClass &chunk_load);
	virtual bool Save_Header(ChunkSaveClass &chunk_save);
	virtual bool Save_Info(ChunkSaveClass &chunk_save);
	virtual bool Save_Subobject(ChunkSaveClass &chunk_save, void *subobject);
	virtual bool Save_Class_Info(ChunkSaveClass &chunk_save);
	virtual void Attach_Subobjects(RenderObjClass &base_model);
	virtual RenderObjClass *Find_Subobject(RenderObjClass &model, const void *mesh_path, const void *bone_path);
	virtual void Free_Subobject_List(void);
	virtual void Add_Subobject(const W3dAggregateSubobjectStruct &subobj_info);
	virtual bool Is_Object_In_List(const char *passet_name, DynamicVectorClass<RenderObjClass *> &node_list);
	virtual void Build_Subobject_List(RenderObjClass &original_model, RenderObjClass &model);

private:
	unsigned long m_Version; // +4
	unsigned char m_SubobjectList[0x18]; // +8, 24-byte vector head (untouched here)
	W3dAggregateInfoStruct m_Info; // +0x20
	W3dAggregateMiscInfo m_MiscInfo; // +0x44
	char *m_pName; // +0x58
};

// ?Save_Class_Info@AggregateDefClass@@MAE?AW4WW3DErrorType@@AAVChunkSaveClass@@@Z @0x1A3690
bool AggregateDefClass::Save_Class_Info(ChunkSaveClass &chunk_save)
{
	// Assume error
	bool ret_val = false;

	// Begin a chunk that identifies the texture replacer header
	if (chunk_save.Begin_Chunk(0x604) == true) {

		// Write the class information structure out to the chunk
		if (chunk_save.Write(&m_MiscInfo, sizeof(m_MiscInfo)) == sizeof(m_MiscInfo)) {
			// Success!
			ret_val = true;
		}

		// End the class info chunk
		chunk_save.End_Chunk();
	}

	// Return the success flag
	return ret_val;
}

// ?Save_Header@AggregateDefClass@@MAE_NAAVChunkSaveClass@@@Z @0x1A35F0
bool AggregateDefClass::Save_Header(ChunkSaveClass &chunk_save)
{
	// Assume error
	bool ret_val = false;

	// Begin a chunk that identifies the aggregate
	if (chunk_save.Begin_Chunk(0x601) == true) {

		// Fill the header structure
		W3dAggregateHeaderStruct header = { 0 };
		header.Version = 0x10003;
		::lstrcpyn(header.Name, m_pName, sizeof(header.Name));
		header.Name[sizeof(header.Name) - 1] = 0;

		// Write the header out to the chunk
		if (chunk_save.Write(&header, sizeof(header)) == sizeof(header)) {
			// Success!
			ret_val = true;
		}

		// End the header chunk
		chunk_save.End_Chunk();
	}

	// Return the success flag
	return ret_val;
}
