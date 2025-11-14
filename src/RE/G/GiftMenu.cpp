#include "RE/G/GiftMenu.h"
#include "RE/P/PlayerCharacter.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	RefHandle GiftMenu::GetGifterRefHandle()
	{
		static REL::Relocation<RefHandle*> handle{ RELOCATION_ID(519570, 406111) };
		return *handle;
	}

	RefHandle GiftMenu::GetReceiverRefHandle()
	{
		static REL::Relocation<RefHandle*> handle{ RELOCATION_ID(0, 406112) };
		return *handle;
	}

	bool GiftMenu::GetShowStolenItems()
	{
		static REL::Relocation<bool*> showStolenItems{ RELOCATION_ID(0, 406086) };
		return *showStolenItems;
	}

	bool GiftMenu::GetUseFavorPoints()
	{
		static REL::Relocation<bool*> useFavorPoints{ RELOCATION_ID(0, 382811) };
		return *useFavorPoints;
	}

	BGSListForm* GiftMenu::GetFilterList()
	{
		static REL::Relocation<BGSListForm**> filterList{ RELOCATION_ID(0, 406085) };
		return *filterList;
	}

	bool GiftMenu::IsPlayerGifting()
	{
		RE::TESObjectREFRPtr refptr = nullptr;

		if (RE::TESObjectREFR::LookupByHandle(GetGifterRefHandle(), refptr)) {
			return refptr && refptr.get() == RE::PlayerCharacter::GetSingleton();
		}
		return false;
	}

	bool GiftMenu::IsPlayerReceiving()
	{
		RE::TESObjectREFRPtr refptr = nullptr;

		if (RE::TESObjectREFR::LookupByHandle(GetReceiverRefHandle(), refptr)) {
			return refptr && refptr.get() == RE::PlayerCharacter::GetSingleton();
		}
		return false;
	}
}
