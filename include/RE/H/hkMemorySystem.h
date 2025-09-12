#pragma once

#include "RE/H/hkBaseTypes.h"
#include "RE/H/hkMemoryRouter.h"

namespace RE
{
	class hkDebugMemorySnapshot;
	class hkMemoryAllocator;
	class hkOstream;

	class hkMemorySystem
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkMemorySystem;
		inline static constexpr auto VTABLE = VTABLE_hkMemorySystem;

		using MemoryWalkCallback = void(void* a_start, std::size_t a_size, bool a_allocated, std::int32_t a_pool, void* a_param);

		struct FrameInfo
		{
			std::int32_t SolverBufferSize;
		};
		static_assert(sizeof(FrameInfo) == 0x4);

		enum class FlagBits
		{
			kPersistent = 1,
			kTemporary,
			kAll,

			kRouter = kPersistent,
			kFrame = kTemporary
		};

		using Flags = hkEnum<FlagBits, std::int32_t>;

		virtual ~hkMemorySystem();  // 00

		// add
		virtual hkMemoryRouter*            MainInit(const FrameInfo& a_info, Flags a_flags) = 0;                         // 01
		virtual hkResult                   MainQuit(Flags a_flags) = 0;                                                  // 02
		virtual void                       ThreadInit(hkMemoryRouter& a_router, const char* a_name, Flags a_flags) = 0;  // 03
		virtual void                       ThreadQuit(hkMemoryRouter& a_router, Flags a_flags) = 0;                      // 04
		virtual hkResult                   SetHeapSoftLimit(std::int32_t a_numBytes) { return hkResult::kFailure; };     // 05
		[[nodiscard]] virtual std::int32_t GetHeapSoftLimit() const { return -1; }                                       // 06
		virtual bool                       SolverCanAllocSingleBlock(std::int32_t a_numBytes) { return true; }           // 07
		virtual bool                       HeapCanAllocTotal(std::int32_t a_numBytes) { return true; }                   // 08
		virtual void                       PrintStatistics(hkOstream& a_ostream) = 0;                                    // 09
		virtual hkMemoryAllocator*         GetUncachedLockedHeapAllocator() = 0;                                         // 0A
		virtual void                       GetHeapStatistics(hkMemoryAllocator::MemoryStatistics& a_stats) = 0;          // 0B
		virtual hkResult                   WalkMemory(MemoryWalkCallback a_callback, void* a_param) = 0;                 // 0C
		virtual void                       GarbageCollectThread(hkMemoryRouter& a_router) {}                             // 0D
		virtual void                       GarbageCollectShared() {}                                                     // 0E
		virtual void                       GarbageCollect()                                                              // 0F
		{
			GarbageCollectThread(hkMemoryRouter::GetInstance());
			GarbageCollectShared();
		}
		virtual void        AdvanceFrame() {}                                                                                                                           // 10
		virtual const void* DebugFindBaseAddress(const void* a_ptr, std::int32_t a_numBytes) { return nullptr; }                                                        // 11
		virtual hkResult    GetMemorySnapshot(hkDebugMemorySnapshot& a_snapshot) { return hkResult::kFailure; }                                                         // 12
		virtual void        DebugLockBaseAddress(const void* a_baseAddress) {}                                                                                          // 13
		virtual void        DebugUnlockBaseAddress(const void* a_baseAddress) {}                                                                                        // 14
		virtual void        DebugTagAddress(const void* a_baseAddress, const void* a_tag) {}                                                                            // 15
		virtual hkResult    GetAllocationCallStack(void* a_ptr, std::uint64_t* a_callstack, int& a_stackSize, std::size_t& a_allocSize) { return hkResult::kFailure; }  // 16
	};
	static_assert(sizeof(hkMemorySystem) == 0x8);
}