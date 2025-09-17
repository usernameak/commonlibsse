#pragma once
#include "BSCullingProcess.h"

namespace RE
{
	class NiFrustum;
	class BSPortalGraphEntry;
	class BSCullingProcess;

	class BSCuller
	{
	public:
		// members
		BSShaderAccumulator*                         accumulator;             // 00
		std::uint64_t                                unk08;                   // 08
		NiCamera*                                    camera;                  // 10
		BSCompoundFrustum*                           compoundFrustum;         // 18
		NiFrustum*                                   frustum;                 // 20
		BSPortalGraphEntry*                          portalGraphEntry;        // 28
		BSCullingProcess*                            cullingProcess;          // 30
		NiFrustumPlanes*                             frustumPlanes;           // 38
		std::uint64_t                                unk40;                   // 40
		BSTArray<NiAVObject*>*                       accumulatedObjectArray;  // 48
		REX::Enum<BSCullingProcess::BSCPCullingType> cullMode;                // 50
		std::uint32_t                                unk54;                   // 54
		std::uint32_t                                jobIndex;                // 58
		std::byte                                    unk5C[12];               // 5C
	};
	static_assert(sizeof(BSCuller) == 0x68);
}
