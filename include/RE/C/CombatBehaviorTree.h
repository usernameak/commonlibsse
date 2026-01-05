#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class Actor;
	class CombatBehaviorTreeNode;

	class CombatBehaviorTree
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTree;
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTree;

		class CombatBehaviorAttacker
		{
		public:
			operator Actor*();
		};

		class CombatBehaviorTarget
		{
		public:
			operator Actor*();
		};

		class TreeBuilder
		{
		public:
			// members
			BSTArray<CombatBehaviorTreeNode*> nodeArray;  // 00
		};
		static_assert(sizeof(TreeBuilder) == 0x18);

		virtual void Initialize();  // 00

		static TreeBuilder* AddNode(TreeBuilder* a_out, const char* a_name, CombatBehaviorTreeNode* a_node);

		// members
		BSFixedString           name;  // 08
		CombatBehaviorTreeNode* root;  // 10
	};
	static_assert(sizeof(CombatBehaviorTree) == 0x18);
}
