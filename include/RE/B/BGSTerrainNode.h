#pragma once

namespace RE
{
	class BGSDistantObjectBlock;
	class BGSDistantTreeBlock;
	class BGSTerrainChunk;
	class BGSTerrainManager;

	class BGSTerrainNode
	{
	public:
		enum class Flag
		{
			kLAND_HGT_ALTERED = 0x1,
			kLAND_CLR_ALTERED = 0x2,
			kLAND_TEX_ALTERED = 0x4,
			kLAND_LOADED = 0x8,
			kSHADER_LAND_TEXTURE_COUNT = 0x8,
			kLAND_GOODNORMALS = 0x10,
			kBLOCKSIZE = 0x10,
			kLAND_HIRES_HEIGHTFIELD = 0x20,
			kLANDSIZE = 0x21,
			kLAND_DATA_ALTERED = 0x27,
			kTILESPERBLOCK = 0x100,
			kTRISPERBLOCK = 0x200,
			kTRISTRIPINDEXCOUNT = 0x3FD,
			kLAND_REMAPPED = 0x400,
			kLANDAREA = 0x441,
			kHALFLAND = 0x800,
			kFULLLAND = 0x1000,
		};

		std::uint32_t GetLODLevel() const { return (nodeState.underlying() >> 21) & 0x3FC; }

		// members
		BGSTerrainManager*                manager;         // 00
		BGSTerrainChunk*                  chunkHandle;     // 08 - BSResource::RHandleType<BSResource::Entry<BGSTerrainChunk*,BSResource::EntryDBTraits<BGSBtrDB::DBTraits,BSResource::EntryDB<BGSBtrDB::DBTraits> >::CArgs>,BSResource::EntryDB<BGSBtrDB::DBTraits> > ChunkHandle;
		BGSDistantObjectBlock*            blockHandle;     // 10
		BGSDistantTreeBlock*              treeHandle;      // 18
		BGSTerrainChunk*                  mapChunkHandle;  // 20
		BGSDistantObjectBlock*            mapBlockHandle;  // 28
		BGSTerrainNode*                   children;        // 30
		BGSTerrainNode*                   parent;          // 38
		REX::EnumSet<Flag, std::uint32_t> nodeState;       // 40
		std::uint32_t                     nodeNumber;      // 44
		std::int16_t                      baseCellX;       // 48
		std::int16_t                      baseCellY;       // 4A
		float                             fade;            // 4C
	};
	static_assert(sizeof(BGSTerrainNode) == 0x50);
}
