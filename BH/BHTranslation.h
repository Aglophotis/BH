#pragma once
#include <string>

#include "Config.h"

struct BHMenu {
    string filename = "menu.json";

    struct {
        SettingsString title = {"", "General"};
        SettingsString tab = {"", "General"};
        SettingsString playerGear = {"", "Show Player's Gear"};
        SettingsString resync = {"", "Resync"};
        SettingsString advanceStat = {"", "Advanced Stat Display"};
        SettingsString reloadConfig = {"", "Reload Config"};
        SettingsString expMeter = {"", "Experience Meter"};
        SettingsString screenshake = {"", "Enable Screenshake"};
        SettingsString dpsMeter = {"", "Enable DPS Counter"};
        SettingsString beltStatus = {"", "Enable Belt Status"};
    } general;

    struct {
        SettingsString title = {"", "Quick Cast"};
        SettingsString quickCast = {"", "Quick Cast"};
        SettingsString skillBar = {"", "Skill Bar"};
        SettingsString onlyEnable = {"", "Only enable with Quick Cast"};
        SettingsString buffTimers = {"", "Always show Buff Timers"};
    } quickCast;

    struct {
        SettingsString tab = {"", "Interaction"};
        SettingsString hoveringItem = {"", "Hovering an item"};
        SettingsString identifyByTomeHotkey = {"", "Shift+Left Click"};
        SettingsString identifyByTome = {"", "ID with an ID tome"};
        SettingsString moveBetweenInventoriesHotkey = {"", "Shift+Right Click"};
        SettingsString moveBetweenInventories = {"", "Move between inventories"};
        SettingsString dropItemHotkey = {"", "Ctrl+Right Click"};
        SettingsString dropItem = {"", "Move to ground"};
        SettingsString moveToCubeHotkey = {"", "Ctrl+Shift+Right Click"};
        SettingsString moveToCube = {"", "Move to closed cube"};
        SettingsString stackUnstackHotkey = {"", "Ctrl+Shift+Left Click"};
        SettingsString stackUnstack = {"", "Toggle stacked/unstacked"};
        SettingsString holdingItem = {"", "Holding an item"};
        SettingsString placeOneStackedItemHotkey = {"", "Ctrl+Left Click"};
        SettingsString placeOneStackedItem = {"", "Place 1 stacked item"};
        SettingsString placeOneUnstackedItemHotkey = {"", "Ctrl+Shift+Left Click"};
        SettingsString placeOneUnstackedItem = {"", "Place 1 unstacked item"};
        SettingsString changeFilterLvl = {"", "Changing filter levels"};
        SettingsString setFilterLvlHotkey = {"", "Ctrl+Numpad [0 - 9]"};
        SettingsString setFilterLvl = {"", "Set filter level"};
    } interaction;

    struct {
        SettingsString title = {"", "Auras (only for top 3 players)"};
        SettingsString lvl99 = {"", "Show 99 Aura"};
        SettingsString dclone = {"", "Show Dclone Aura"};
        SettingsString rathma = {"", "Show Rathma Aura"};
        SettingsString pvp = {"", "Show PVP Aura"};
        SettingsString developerTitle = {"", "Developer Only"};
        SettingsString developer = {"", "Show Developer Aura"};
    } aura;
};


class BHTranslation {
public:
    BHMenu menu = {};

    BHTranslation();

    ~BHTranslation() = default;
};


