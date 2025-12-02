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
			kLandHgtAltered = 0x1,
			kLandClrAltered = 0x2,
			kLandTexAltered = 0x4,
			kLandLoaded = 0x8,
			kShaderLandTextureCount = 0x8,
			kLandGoodNormals = 0x10,
			kBlocksize = 0x10,
			kLandHiresHeightfield = 0x20,
			kLandSize = 0x21,
			kLandDataAltered = 0x27,
			kTilesPerBlock = 0x100,
			kTrisPerBlock = 0x200,
			kTriStripIndexCount = 0x3FD,  // TRISTRIPINDEXCOUNT
			kLandRemapped = 0x400,
			kLandArea = 0x441,
			kHalfLand = 0x800,
			kFullLand = 0x1000,
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
