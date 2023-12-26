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

map<std::string, Toggle> GameSettings::Toggles;
unsigned int GameSettings::KeyHookOffset = 300;

void GameSettings::Init() {
}

void GameSettings::LoadConfig() {
	BH::config->ReadToggle("Quick Cast", "None", false, GameSettings::Toggles["Quick Cast"]);
	BH::config->ReadToggle("Skill Bar", "None", false, GameSettings::Toggles["Skill Bar"]);
	BH::config->ReadToggle("Skill Bar Disable", "None", false, GameSettings::Toggles["Skill Bar Disable"]);
	BH::config->ReadToggle("Buff Timers", "None", false, GameSettings::Toggles["Buff Timers"]);
	BH::config->ReadToggle("Screenshake", "None", true, GameSettings::Toggles["Screenshake"]);
	BH::config->ReadToggle("DPS", "None", false, GameSettings::Toggles["DPS"]);
	BH::config->ReadToggle("Belt Status", "None", true, GameSettings::Toggles["Belt Status"]);

	BH::config->ReadToggle("Developer Aura", "None", true, GameSettings::Toggles["Developer Aura"]);
	BH::config->ReadToggle("99 Aura", "None", true, GameSettings::Toggles["99 Aura"]);
	BH::config->ReadToggle("Rathma Aura", "None", true, GameSettings::Toggles["Rathma Aura"]);
	BH::config->ReadToggle("Dclone Aura", "None", true, GameSettings::Toggles["Dclone Aura"]);
	BH::config->ReadToggle("PVP Aura", "None", true, GameSettings::Toggles["PVP Aura"]);

	BH::config->ReadKey("Show Players Gear", "VK_0", showPlayer);
	BH::config->ReadKey("Resync Hotkey", "VK_9", resyncKey);
	BH::config->ReadKey("Character Stats", "VK_8", advStatMenuKey);
	BH::config->ReadKey("Reload Config", "VK_NUMPAD0", reloadConfig);
	BH::config->ReadKey("Reload Config Ctrl", "VK_R", reloadConfigCtrl);
}

void GameSettings::LoadGeneralTab() {
	Drawing::Texthook* colored_text;

	Drawing::UITab* generalTab = new Drawing::UITab(BH::menu->GetStringOrDefault("tab.general", "General"), BH::settingsUI);

	unsigned int x_tab = 15;
	unsigned int x = 8;
	unsigned int y = 7;

	// General
	new Drawing::Texthook(generalTab, x, (y), BH::menu->GetStringOrDefault("menu.gen.general", "General"));

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::menu->GetStringOrDefault("menu.gen.gear", "Show Player's Gear"));
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &showPlayer, "");

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::menu->GetStringOrDefault("menu.gen.resync", "Resync"));
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &resyncKey, "");

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::menu->GetStringOrDefault("menu.gen.adv_stat", "Advanced Stat Display"));
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &advStatMenuKey, "");

	y += 15;
	colored_text = new Drawing::Texthook(generalTab, x, (y), BH::menu->GetStringOrDefault("menu.gen.reload", "Reload Config"));
	colored_text->SetColor(Gold);
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &reloadConfig, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &ScreenInfo::Toggles["Experience Meter"].state, BH::menu->GetStringOrDefault("menu.gen.exp", "Experience Meter"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &ScreenInfo::Toggles["Experience Meter"].toggle, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &GameSettings::Toggles["Screenshake"].state, BH::menu->GetStringOrDefault("menu.gen.shake", "Enable Screenshake"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Screenshake"].toggle, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &GameSettings::Toggles["DPS"].state, BH::menu->GetStringOrDefault("menu.gen.dps", "Enable DPS Counter"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["DPS"].toggle, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &GameSettings::Toggles["Belt Status"].state, BH::menu->GetStringOrDefault("menu.gen.belt", "Enable Belt Status"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Belt Status"].toggle, "");


	// Quick Cast
	y += 20;
	new Drawing::Texthook(generalTab, x, (y), BH::menu->GetStringOrDefault("menu.gen.qcast", "Quick Cast"));

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &GameSettings::Toggles["Quick Cast"].state, BH::menu->GetStringOrDefault("menu.gen.qcast", "Quick Cast"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Quick Cast"].toggle, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &GameSettings::Toggles["Skill Bar"].state, BH::menu->GetStringOrDefault("menu.gen.skill", "Skill Bar"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Skill Bar"].toggle, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x + x_tab, y, &GameSettings::Toggles["Skill Bar Disable"].state, BH::menu->GetStringOrDefault("menu.gen.skill_dis", "Only enable with Quick Cast"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Skill Bar Disable"].toggle, "");

	y += 15;
	new Drawing::Checkhook(generalTab, x, y, &GameSettings::Toggles["Buff Timers"].state, BH::menu->GetStringOrDefault("menu.gen.buff", "Always show Buff Timers"));
	new Drawing::Keyhook(generalTab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Buff Timers"].toggle, "");

}

void GameSettings::LoadInteractionTab() {
	Drawing::Texthook* colored_text;
	Drawing::UITab* tab = new Drawing::UITab(BH::menu->GetStringOrDefault("tab.interaction", "Interaction"), BH::settingsUI);

	unsigned int x = 8;
	unsigned int y = 7;
	int offset = 150;
	int indent = 5;

	// QoL
	colored_text = new Drawing::Texthook(tab, x, y,
		BH::menu->GetStringOrDefault("menu.inter.hover_item", "Hovering an item"));

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.id_tome_key", "Shift+Left Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.id_tome", "ID with an ID tome"));
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.move_btwn_inv_key", "Shift+Right Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.move_btwn_inv", "Move between inventories"));
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.drop_item_key", "Ctrl+Right Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.drop_item", "Move to ground"));
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.move_to_cube_key", "Ctrl+Shift+Right Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.move_to_cube", "Move to closed cube"));
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.stack_key", "Ctrl+Shift+Left Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.stack", "Toggle stacked/unstacked"));
	colored_text->SetColor(Gold);

	y += 20;
	colored_text = new Drawing::Texthook(tab, x, y,
		BH::menu->GetStringOrDefault("menu.inter.hold", "Holding an item"));

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.place_one_stacked_key", "Ctrl+Left Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.place_one_stacked", "Place 1 stacked item"));
	colored_text->SetColor(Gold);

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.place_one_unstacked_key", "Ctrl+Shift+Left Click"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.place_one_unstacked", "Place 1 unstacked item"));
	colored_text->SetColor(Gold);

	y += 20;
	colored_text = new Drawing::Texthook(tab, x, y,
		BH::menu->GetStringOrDefault("menu.inter.change_filter", "Changing filter levels"));

	y += 15;
	colored_text = new Drawing::Texthook(tab, x + indent, y,
		BH::menu->GetStringOrDefault("menu.inter.set_filter_key", "Ctrl+Numpad [0 - 9]"));
	colored_text->SetColor(Gold);
	colored_text = new Drawing::Texthook(tab, x + indent + offset, y,
		BH::menu->GetStringOrDefault("menu.inter.set_filter", "Set filter level"));
	colored_text->SetColor(Gold);

	// Auras
	//y += 20;
	//new Drawing::Texthook(tab, x, (y), "Auras (only for top 3 players)");

	//y += 15;
	//new Drawing::Checkhook(tab, x, y, &GameSettings::Toggles["99 Aura"].state, "Show 99 Aura");
	//new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["99 Aura"].toggle, "");

	//y += 15;
	//new Drawing::Checkhook(tab, x, y, &GameSettings::Toggles["Dclone Aura"].state, "Show Dclone Aura");
	//new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Dclone Aura"].toggle, "");

	//y += 15;
	//new Drawing::Checkhook(tab, x, y, &GameSettings::Toggles["Rathma Aura"].state, "Show Rathma Aura");
	//new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Rathma Aura"].toggle, "");

	//y += 15;
	//new Drawing::Checkhook(tab, x, y, &GameSettings::Toggles["PVP Aura"].state, "Show PVP Aura");
	//new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["PVP Aura"].toggle, "");

	//y += 20;
	//new Drawing::Texthook(tab, x, (y), "Developer Only");
	//y += 15;
	//new Drawing::Checkhook(tab, x, y, &GameSettings::Toggles["Developer Aura"].state, "Show Developer Aura");
	//new Drawing::Keyhook(tab, GameSettings::KeyHookOffset, y + 2, &GameSettings::Toggles["Developer Aura"].toggle, "");
}

void GameSettings::OnLoad() {
	LoadConfig();
	LoadGeneralTab();
	LoadInteractionTab();
}

void GameSettings::OnKey(bool up, BYTE key, LPARAM lParam, bool* block) {
	bool ctrlState = ((GetKeyState(VK_LCONTROL) & 0x80) || (GetKeyState(VK_RCONTROL) & 0x80));
	for (map<string, Toggle>::iterator it = Toggles.begin(); it != Toggles.end(); it++) {
		if (key == (*it).second.toggle && !ctrlState) {
			*block = true;
			if (up) {
				(*it).second.state = !(*it).second.state;
				BH::config->Write();
			}
			return;
		}
	}

	if (key == showPlayer) {
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
}
