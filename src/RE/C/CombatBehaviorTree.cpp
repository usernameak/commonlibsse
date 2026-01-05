#include "RE/C/CombatBehaviorTree.h"

namespace RE
{
	CombatBehaviorTree::CombatBehaviorAttacker::operator Actor*()
	{
		using func_t = decltype(&CombatBehaviorTree::CombatBehaviorAttacker::operator Actor*);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46264, 47519) };
		return func(this);
	}

	CombatBehaviorTree::CombatBehaviorTarget::operator Actor*()
	{
		using func_t = decltype(&CombatBehaviorTree::CombatBehaviorTarget::operator Actor*);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46265, 47520) };
		return func(this);
	}

	CombatBehaviorTree::TreeBuilder* CombatBehaviorTree::AddNode(TreeBuilder* a_out, const char* a_name, CombatBehaviorTreeNode* a_node)
	{
		using func_t = decltype(&CombatBehaviorTree::AddNode);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46261, 47516) };
		return func(a_out, a_name, a_node);
	}
}
