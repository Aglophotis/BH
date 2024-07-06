#pragma once
#include <string>

struct ConfigString {
    std::string value;
    std::string defValue;

    char* charValue() {
        return &value[0];
    }

    std::wstring wStringValue() {
        return std::wstring(value.begin(), value.end());
    }
};

struct BHMenu {
    std::string filename = "menu.json";

    struct {
        ConfigString title = {"", "General"};
        ConfigString tab = {"", "General"};
        ConfigString playerGear = {"", "Show Player's Gear"};
        ConfigString resync = {"", "Resync"};
        ConfigString advanceStat = {"", "Advanced Stat Display"};
        ConfigString reloadConfig = {"", "Reload Config"};
        ConfigString expMeter = {"", "Experience Meter"};
        ConfigString screenshake = {"", "Enable Screenshake"};
        ConfigString dpsMeter = {"", "Enable DPS Counter"};
        ConfigString beltStatus = {"", "Enable Belt Status"};
    } general;

    struct {
        ConfigString title = {"", "Quick Cast"};
        ConfigString quickCast = {"", "Quick Cast"};
        ConfigString skillBar = {"", "Skill Bar"};
        ConfigString onlyEnable = {"", "Only enable with Quick Cast"};
        ConfigString buffTimers = {"", "Always show Buff Timers"};
    } quickCast;

    struct {
        ConfigString tab = {"", "Interaction"};
        ConfigString hoveringItem = {"", "Hovering an item"};
        ConfigString identifyByTomeHotkey = {"", "Shift+Left Click"};
        ConfigString identifyByTome = {"", "ID with an ID tome"};
        ConfigString moveBetweenInventoriesHotkey = {"", "Shift+Right Click"};
        ConfigString moveBetweenInventories = {"", "Move between inventories"};
        ConfigString dropItemHotkey = {"", "Ctrl+Right Click"};
        ConfigString dropItem = {"", "Move to ground"};
        ConfigString moveToCubeHotkey = {"", "Ctrl+Shift+Right Click"};
        ConfigString moveToCube = {"", "Move to closed cube"};
        ConfigString stackUnstackHotkey = {"", "Ctrl+Shift+Left Click"};
        ConfigString stackUnstack = {"", "Toggle stacked/unstacked"};
        ConfigString holdingItem = {"", "Holding an item"};
        ConfigString placeOneStackedItemHotkey = {"", "Ctrl+Left Click"};
        ConfigString placeOneStackedItem = {"", "Place 1 stacked item"};
        ConfigString placeOneUnstackedItemHotkey = {"", "Ctrl+Shift+Left Click"};
        ConfigString placeOneUnstackedItem = {"", "Place 1 unstacked item"};
        ConfigString changeFilterLvl = {"", "Changing filter levels"};
        ConfigString setFilterLvlHotkey = {"", "Ctrl+Numpad [0 - 9]"};
        ConfigString setFilterLvl = {"", "Set filter level"};
    } interaction;

    struct {
        ConfigString title = {"", "Auras (only for top 3 players)"};
        ConfigString lvl99 = {"", "Show 99 Aura"};
        ConfigString dclone = {"", "Show Dclone Aura"};
        ConfigString rathma = {"", "Show Rathma Aura"};
        ConfigString pvp = {"", "Show PVP Aura"};
        ConfigString developerTitle = {"", "Developer Only"};
        ConfigString developer = {"", "Show Developer Aura"};
    } aura;

    struct {
        ConfigString tab = {"", "Item"};
        ConfigString title = {"", "Settings"};
        ConfigString showItems = {"", "Always Show Items"};
        ConfigString showItemStatRanges = {"", "Always Show Item Stat Ranges"};
        ConfigString showItemLvl = {"", "Show Item Level"};
        ConfigString style = {"", "Display Style (only without loot filter)"};
        ConfigString showEthereal = {"", "Show Ethereal"};
        ConfigString showSockets = {"", "Show Sockets"};
        ConfigString showRuneNumbers = {"", "Show Rune Numbers"};
        ConfigString altStyle = {"", "Alt Style"};
        ConfigString colorMod = {"", "Color Mod"};
        ConfigString shortenNames = {"", "Shorten Names"};
    } item;

    struct {
        ConfigString title = {"", "Loot Filter"};
        ConfigString enable = {"", "Enable Loot Filter"};
        ConfigString dropNotifications = {"", "Drop Notifications"};
        ConfigString closeNotifications = {"", "Close Notifications"};
        ConfigString detailedNotifications = {"", "Detailed Notifications"};
        ConfigString verboseNotifications = {"", "Verbose Notifications"};
        ConfigString incFilterLvl = {"", "Increase Filter Level"};
        ConfigString decFilterLvl = {"", "Decrease Filter Level"};
        ConfigString restoreFilterLvl = {"", "Restore Previous Filter Level"};
        ConfigString filterLvl = {"", "Filter Level:"};
        ConfigString allItems = {"", "0 - Show All Items"};
        ConfigString normal = {"", "1 - Normal"};
    } lootFilter;

    struct {
        ConfigString changeFilterToAllItemsText = {"", "Filter level: ÿc50 - Show All Items"};
        ConfigString changeFilterText = {"", "Filter level: ÿc0"};
        ConfigString dropNotificationDropped = {"", "Dropped"};
        ConfigString dropNotificationDrop = {"", " ÿc5drop"};
        ConfigString closeNotification = {"", "ÿc5close"};
    } chat;

    struct {
        ConfigString affixLvl = {"", "Affix Level"};
        ConfigString itemLvl = {"", "Item Level"};
        ConfigString to = {"", "to"};
        ConfigString tooLongDescription = {"", "ÿc1Item Description is too long."};
    } property;
};


class BHTranslation {
public:
    BHMenu menu = {};

    BHTranslation();

    ~BHTranslation() = default;
};


