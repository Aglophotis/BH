#include "GameSettings.h"
#include "../../Drawing.h"
#include "../Module.h"
#include "../../Config.h"
#include "../../Common.h"
#include "../../BH.h"
#include "../Item/Item.h"
#include "../ScreenInfo/ScreenInfo.h"

// This module was inspired by the RedVex plugin "Item Mover", written by kaiks.
// Thanks to kaiks for sharing his code.

unsigned int GameSettings::KeyHookOffset = 300;

void GameSettings::Init() {
}

void GameSettings::LoadConfig() {

}

void GameSettings::LoadGeneralTab() {
	Drawing::Texthook* colored_text;

	Drawing::UITab* generalTab = new Drawing::UITab(BH::translation->menu.general.tab.value, BH::settingsUI);

	unsigned int x_tab = 15;
	unsigned int x = 8;
	unsigned int y = 7;

	// General
	new Drawing::Texthook(generalTab, x, (y), BH::translation->menu.general.title.value);

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::translation->menu.general.playerGear.value);
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.showPlayersGear.hotkey, "");

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::translation->menu.general.resync.value);
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.resyncHotkey.hotkey, "");

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::translation->menu.general.advanceStat.value);
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.characterStats.hotkey, "");

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::translation->menu.general.reloadConfig.value);
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.general.reloadConfig.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.experienceMeter.toggle.isEnabled, BH::translation->menu.general.expMeter.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.experienceMeter.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.screenshake.toggle.isEnabled, BH::translation->menu.general.screenshake.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.screenshake.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.dpsCounter.toggle.isEnabled, BH::translation->menu.general.dpsMeter.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.dpsCounter.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.beltStatus.toggle.isEnabled, BH::translation->menu.general.beltStatus.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.beltStatus.toggle.hotkey, "");


	// Quick Cast
	y += 20;
	new Drawing::Texthook(generalTab, x, (y), BH::translation->menu.quickCast.title.value);

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.quickCast.toggle.isEnabled, BH::translation->menu.quickCast.quickCast.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.quickCast.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.skillBar.toggle.isEnabled, BH::translation->menu.quickCast.skillBar.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.skillBar.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x + x_tab, y, &App.game.skillBarDisable.toggle.isEnabled, BH::translation->menu.quickCast.onlyEnable.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.skillBarDisable.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &App.game.buffTimers.toggle.isEnabled, BH::translation->menu.quickCast.buffTimers.value);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &App.game.buffTimers.toggle.hotkey, "");

}

void GameSettings::LoadInteractionTab() {
	Drawing::Texthook* colored_text;
	Drawing::UITab* tab = new Drawing::UITab(BH::translation->menu.interaction.tab.value, BH::settingsUI);

	unsigned int x = 8;
	unsigned int y = 7;
	int offset = 160;
	int indent = 5;

	// QoL
	colored_text = new Drawing::Texthook(tab, x, y, BH::translation->menu.interaction.hoveringItem.value);
	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.identifyByTome.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.identifyByTomeHotkey.value);
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.moveBetweenInventories.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.moveBetweenInventoriesHotkey.value);
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.dropItemHotkey.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.dropItem.value);
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.moveToCubeHotkey.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.moveToCube.value);
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.stackUnstackHotkey.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.stackUnstack.value);
	colored_text->SetColor(Gold);

	y += 20;
	colored_text = new Drawing::Texthook(tab, x, y,
		"Holding an item");

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.placeOneStackedItemHotkey.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.placeOneStackedItem.value);
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.placeOneUnstackedItemHotkey.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.placeOneUnstackedItem.value);
	colored_text->SetColor(Gold);

	y += 20;
	colored_text = new Drawing::Texthook(tab, x, y,
BH::translation->menu.interaction.changeFilterLvl.value);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
BH::translation->menu.interaction.setFilterLvlHotkey.value);
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
BH::translation->menu.interaction.setFilterLvl.value);
	colored_text->SetColor(Gold);

	// Auras
	y += 20;
	new Drawing::Texthook(tab, x, (y), BH::translation->menu.aura.title.value);

	y += 15;
	new Drawing::Checkhook(tab, x, y, &App.general.maxLevelAura.toggle.isEnabled, BH::translation->menu.aura.lvl99.value);
	new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &App.general.maxLevelAura.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(tab, x, y, &App.general.dcloneAura.toggle.isEnabled, BH::translation->menu.aura.dclone.value);
	new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &App.general.dcloneAura.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(tab, x, y, &App.general.rathmaAura.toggle.isEnabled, BH::translation->menu.aura.rathma.value);
	new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &App.general.rathmaAura.toggle.hotkey, "");

	y += 15;
	new Drawing::Checkhook(tab, x, y, &App.general.pvpAura.toggle.isEnabled, BH::translation->menu.aura.pvp.value);
	new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &App.general.pvpAura.toggle.hotkey, "");

	y += 20;
	new Drawing::Texthook(tab, x, (y), BH::translation->menu.aura.developerTitle.value);
	y += 15;
	new Drawing::Checkhook(tab, x, y, &App.general.devAura.toggle.isEnabled, BH::translation->menu.aura.developer.value);
	new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &App.general.devAura.toggle.hotkey, "");
}

void GameSettings::OnLoad() {
	LoadConfig();
	LoadGeneralTab();
	LoadInteractionTab();
}

void GameSettings::OnKey(bool up, BYTE key, LPARAM lParam, bool* block) {
	bool ctrlState = ((GetKeyState(VK_LCONTROL) & 0x80) || (GetKeyState(VK_RCONTROL) & 0x80));
	for (vector<Toggle*>::iterator it = App.hotkeyToggles.begin(); it != App.hotkeyToggles.end(); it++) {
		if (key == (*it)->hotkey && !ctrlState && D2CLIENT_GetUIState(UI_GAME)) {
			*block = true;
			if (up) {
				(*it)->isEnabled = !(*it)->isEnabled;
				App.config->SaveConfig();
			}
			return;
		}
	}

	if (key == App.game.showPlayersGear.hotkey) {
		*block = true;
		if (up)
			return;
		UnitAny* selectedUnit = D2CLIENT_GetSelectedUnit();
		if (selectedUnit && selectedUnit->dwMode != 0 && selectedUnit->dwMode != 17 && ( // Alive
			selectedUnit->dwType == 0 ||					// Player
			selectedUnit->dwTxtFileNo == 291 ||		// Iron Golem
			selectedUnit->dwTxtFileNo == 357 ||		// Valkerie
			selectedUnit->dwTxtFileNo == 417 ||		// Shadow Warrior
			selectedUnit->dwTxtFileNo == 418)) {	// Shadow Master
			Item::viewingUnit = selectedUnit;
			if (!D2CLIENT_GetUIState(0x01))
				D2CLIENT_SetUIVar(0x01, 0, 0);
			return;
		}
	}

	if (!BH::settingsUI->IsMinimized() && key == VK_ESCAPE) {
		*block = true;
		if (up)
			return;
		BH::settingsUI->SetMinimized(true, true);
		return;
	}
}
