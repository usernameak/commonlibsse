#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTLocklessQueue.h"
#include "RE/N/NiCullingProcess.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSCompoundFrustum;
	class BSMultiBound;
	class BSOcclusionPlane;
	class BSPortalGraphEntry;
	class NiAVObject;
	class NiBound;

	class BSCullingProcess : public NiCullingProcess
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSCullingProcess;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSCullingProcess;
		inline static constexpr auto VTABLE = VTABLE_BSCullingProcess;

		enum class BSCPCullingType
		{
			kNormal = 0,
			kAllPass = 1,
			kAllFail = 2,
			kIgnoreMultiBounds = 3,
			kForceMultiBoundsNoUpdate = 4
		};

		struct Data
		{
		public:
			// members
			std::uint8_t unk00[0x10];  // 00
		};
		static_assert(sizeof(Data) == 0x10);

		// override (NiCullingProcess)
		const NiRTTI* GetRTTI() const override;  // 00

		~BSCullingProcess() override;  // 15

		void Process1(NiAVObject* a_object, std::uint32_t a_arg2) override;                                   // 16
		void Process2(const NiCamera* a_camera, NiAVObject* a_scene, NiVisibleArray* a_visibleSet) override;  // 17
		void AppendVirtual(BSGeometry& a_visible, std::uint32_t a_arg2) override;                             // 18

		// add
		virtual void               AppendNonAccum(NiAVObject& a_object);               // 19
		virtual bool               TestBaseVisibility1(BSMultiBound& a_bound);         // 1A
		virtual bool               TestBaseVisibility2(BSOcclusionPlane& a_bound);     // 1B
		[[nodiscard]] virtual bool TestBaseVisibility3(const NiBound& a_bound) const;  // 1C

		BSTArray<NiPointer<NiAVObject>>                   unk00128;           // 00128
		BSTLocklessQueue::ObjMultiProdCons<Data, 4096, 0> cullQueue;          // 00140
		BSTHashMap<NiAVObject*, bool>                     roomSharedMap;      // 30160
		BSPortalGraphEntry*                               portalGraphEntry;   // 30190
		std::int32_t                                      cullMode;           // 30198
		BSCompoundFrustum*                                compoundFrustum;    // 301A0
		std::uint64_t                                     unk301A8;           // 301A8
		std::uint64_t                                     unk301B0;           // 301B0
		std::uint64_t                                     unk301B8;           // 301B8
		std::uint64_t                                     unk301C0;           // 301C0
		std::uint64_t                                     unk301C8;           // 301C8
		std::uint32_t                                     unk301D0;           // 301D0
		bool                                              recurseToGeometry;  // 301D4
		std::uint8_t                                      unk301D5;           // 301D5
		std::uint16_t                                     unk301D6;           // 301D6
		BSTArray<void*>                                   unk301D8;           // 301D8
		std::uint64_t                                     unk301F0;           // 301F0
	};
	static_assert(sizeof(BSCullingProcess) == 0x301F8);
}
