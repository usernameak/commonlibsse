#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/C/CombatBehaviorStack.h"

namespace RE
{
	class CombatBehaviorController;
	class CombatBehaviorTreeNode;

	class CombatBehaviorThread
	{
	public:
		class ObjectPtr
		{
		public:
			template <typename T>
			T* GetObject()
			{
				if (!thread)
					return nullptr;

				if (stackIndex >= thread->stackFrame.size())
					return nullptr;

				const auto& frame = thread->stackFrame[stackIndex];
				return thread->stack.GetObject<T>(frame.second);
			}

			/*template <typename T>
			const T* GetObject() const
			{
				return stack ? reinterpret_cast<const T*>(&stack->buffer[pos]) : nullptr;
			}*/

			// members
			CombatBehaviorThread* thread;      // 00
			std::uint32_t         stackIndex;  // 08
			std::uint32_t         pad0C;       // 0C
		};
		static_assert(sizeof(ObjectPtr) == 0x10);

		enum class Status
		{
			kNormal = 0,
			kAdditiveDeprecated = 1,
			kAdditive = 2
		};

		enum class State
		{
			kAscending = 0,
			kUpdating = 1,
			kDescending = 2,
			kRestarting = 3
		};

		enum class Flag
		{
			kPaused = 1 << 0,
			kSuspended = 1 << 1,
			kUnk2 = 1 << 2,
			kIsWorking_mb = 1 << 3
		};

		template <typename T>
		T* GetCurrentStackObject()
		{
			return stack.GetObject<T>(stackPos);
		}

		template <typename T>
		T* GetCurrentObject()
		{
			return currentContextPtr.GetObject<T>();
		}

		// members
		CombatBehaviorStack                                                       stack;              // 000
		BSTSmallArray<BSTTuple<const CombatBehaviorTreeNode*, std::uint32_t>, 16> stackFrame;         // 010
		std::uint32_t                                                             stackPos;           // 120
		std::uint32_t                                                             pad124;             // 124
		CombatBehaviorThread::ObjectPtr                                           currentContextPtr;  // 128
		const CombatBehaviorTreeNode*                                             currentNode;        // 138
		const CombatBehaviorTreeNode*                                             previousNode;       // 140
		REX::EnumSet<Status, std::int32_t>                                        status;             // 148
		REX::EnumSet<State, std::int32_t>                                         state;              // 14C
		REX::EnumSet<Flag, std::int32_t>                                          flags;              // 150
		std::uint32_t                                                             threadID;           // 154
		CombatBehaviorController*                                                 controller;         // 158
		CombatBehaviorThread*                                                     parent;             // 160
		BSTSmallArray<CombatBehaviorThread*, 4>                                   children;           // 168
	};
	static_assert(sizeof(CombatBehaviorThread) == 0x198);
}
