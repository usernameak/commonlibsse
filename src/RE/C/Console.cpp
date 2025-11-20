#include "RE/C/Console.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	NiPointer<TESObjectREFR> Console::GetSelectedRef()
	{
		auto handle = GetSelectedRefHandle();
		return handle.get();
	}

	ObjectRefHandle Console::GetSelectedRefHandle()
	{
		static REL::Relocation<ObjectRefHandle*> selectedRef{ Offset::Console::SelectedRef };
		return *selectedRef;
	}

	TESQuest* Console::GetCommandScriptParentQuest()
	{
		static REL::Relocation<TESQuest**> quest{ RELOCATION_ID(0, 504093) };
		return *quest;
	}

	void Console::SetSelectedRef(NiPointer<TESObjectREFR> a_refPtr)
	{
		ObjectRefHandle handle(a_refPtr.get());
		SetSelectedRef_Impl(handle);
	}

	void Console::SetSelectedRef(TESObjectREFR* a_ref)
	{
		ObjectRefHandle handle(a_ref);
		SetSelectedRef_Impl(handle);
	}

	void Console::SetSelectedRef(ObjectRefHandle a_handle)
	{
		SetSelectedRef_Impl(a_handle);
	}

	void Console::SetSelectedRef_Impl(ObjectRefHandle& a_handle)
	{
		using func_t = decltype(&Console::SetSelectedRef_Impl);
		static REL::Relocation<func_t> func{ Offset::Console::SetSelectedRef };
		return func(this, a_handle);
	}
}
