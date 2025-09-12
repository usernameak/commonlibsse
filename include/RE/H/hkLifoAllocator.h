#pragma once

#include "RE/H/hkMemoryAllocator.h"

namespace RE
{
	class hkLifoAllocator : public hkMemoryAllocator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkLifoAllocator;
		inline static constexpr auto VTABLE = VTABLE_hkLifoAllocator;

		class Implementation;

		hkLifoAllocator() { stl::emplace_vtable(this); }

		// override (hkMemoryAllocator)
		void*        BlockAlloc(std::int32_t a_numBytes) override;                                                       // 01
		void         BlockFree(void* a_ptr, std::int32_t a_numBytes) override;                                           // 02
		void*        BufAlloc(std::int32_t& a_reqNumBytesInOut) override;                                                // 03
		void         BufFree(void* a_ptr, std::int32_t a_numBytes) override;                                             // 04
		void*        BufRealloc(void* a_ptrOld, std::int32_t a_oldNumBytes, std::int32_t& a_reqNumBytesInOut) override;  // 05
		void         GetMemoryStatistics(MemoryStatistics& a_usage) override;                                            // 08
		std::int32_t GetAllocatedSize(const void* a_obj, std::int32_t a_numBytes) override;                              // 09

		// members
		Implementation*    impl{ nullptr };               // 08
		const std::int32_t SlabSize{ 0x4000 };            // 10
		void*              Cur{ nullptr };                // 18
		void*              End{ nullptr };                // 20
		void*              FirstNonLifoEnd{ nullptr };    // 28
		void*              CachedEmptySlab{ nullptr };    // 30
		hkMemoryAllocator* SlabAllocator{ nullptr };      // 38
		hkMemoryAllocator* LargeAllocator{ nullptr };     // 40
		hkMemoryAllocator* InternalAllocator{ nullptr };  // 48
	};
	static_assert(sizeof(hkLifoAllocator) == 0x50);
}