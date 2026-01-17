#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{
	class BSShadowDirectionalLight : public BSShadowLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShadowDirectionalLight;
		inline static constexpr auto VTABLE = VTABLE_BSShadowDirectionalLight;

		struct RUNTIME_DATA
		{
#define RUNTIME_DATA_CONTENT                                                                \
	NiPoint3                              sunVector;                      /* 560, VR 5C0 */ \
	NiPoint3                              lastSunVector;                  /* 56C, VR 5CC */ \
	NiPointer<NiCamera>                   fullFrustumCamera;              /* 578, VR 5D8 */ \
	BSTArray<NiPointer<BSCullingProcess>> fullFrustumCullingProcessArray; /* 580, VR 5E0 */ \
	float                                 startSplitDistances[3];         /* 598, VR 5F8 */ \
	float                                 endSplitDistances[3];           /* 5A4, VR 604 */ \
	float                                 sunUpdate;                      /* 5B0, VR 610 */ \
	std::uint32_t                         sunUpdateMode;                  /* 5B4, VR 614 */
            RUNTIME_DATA_CONTENT
		};
		static_assert(sizeof(RUNTIME_DATA) == 0x58);

		~BSShadowDirectionalLight() override;  // 00

		// override (BSShadowLight)
		bool          AreFocusShadowsSupported() override;                                                                                                     // 04
		void          GetIsDirectionalLight() override;                                                                                                        // 06
		void          Accumulate(std::uint32_t& a_globalShadowLightCount, std::uint32_t& a_shadowMaskChannel, NiPointer<NiAVObject> a_cullingScene) override;  // 09
		void          Render() override;                                                                                                                       // 0A
		void          ClearShadowMapData() override;                                                                                                           // 0C
		std::uint32_t GetPassExtraParam(std::uint32_t a_accumFlag) override;                                                                                   // 0D
		bool          GetNeedsClipPlanes() override;                                                                                                           // 0E
		void          UpdateClipPlanes(void* a_unk1, void* a_unk2) override;                                                                                   // 0F
		bool          UpdateCamera(const NiCamera* a_viewCamera) override;                                                                                     // 10

		[[nodiscard]] inline RUNTIME_DATA& GetShadowDirectionalLightRuntimeData() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x560, 0x5C0);
		}

		[[nodiscard]] inline const RUNTIME_DATA& GetShadowDirectionalLightRuntimeData() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x560, 0x5C0);
		}

		// members
#ifndef SKYRIM_CROSS_VR
		RUNTIME_DATA_CONTENT;  // 560, VR 5C0
#endif
	private:
		KEEP_FOR_RE()
	};
#if defined(EXCLUSIVE_SKYRIM_FLAT)
	static_assert(sizeof(BSShadowDirectionalLight) == 0x5B8);
#elif defined(EXCLUSIVE_SKYRIM_VR)
	static_assert(sizeof(BSShadowDirectionalLight) == 0x618);
#else
	static_assert(sizeof(BSShadowDirectionalLight) == 0x148);
#endif
}
#undef RUNTIME_DATA_CONTENT
