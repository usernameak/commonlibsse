#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class BGSListForm;
	struct ItemCard;
	struct ItemList;

	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kItemMenu
	class GiftMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_GiftMenu;
		inline static constexpr auto      VTABLE = VTABLE_GiftMenu;
		constexpr static std::string_view MENU_NAME = "GiftMenu";

		~GiftMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04
		void               PostDisplay() override;                           // 06

		[[nodiscard]] static RefHandle    GetGifterRefHandle();
		[[nodiscard]] static RefHandle    GetReceiverRefHandle();
		[[nodiscard]] static bool         GetShowStolenItems();
		[[nodiscard]] static bool         GetUseFavorPoints();  // always false regardless of the argument value in ShowGiftMenu papyrus function
		[[nodiscard]] static BGSListForm* GetFilterList();

		bool IsPlayerGifting();
		bool IsPlayerReceiving();

		// members
		GFxValue        root;                   // 30 - "Menu_mc"
		ItemList*       itemList;               // 48
		ItemCard*       itemCard;               // 50
		BSTArray<void*> unk58;                  // 58
		std::int32_t   totalValueTransferred;  // 70 - gold value, return value of ShowGiftMenu papyrus function
		std::uint32_t   unk74;                  // 74
		bool            pcControlsReady;        // 78
		std::uint8_t    pad79;                  // 79
		std::uint16_t   pad7A;                  // 7A
		std::uint32_t   pad7C;                  // 7C
	};
	static_assert(sizeof(GiftMenu) == 0x80);
}
