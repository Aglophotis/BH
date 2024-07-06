#include "BHTranslation.h"
#include <nlohmann/json.hpp>
#include <fstream>

BHMenu menu;

using json = nlohmann::ordered_json;


std::string GetString(json config, json::json_pointer sectionKey, std::string key, ConfigString def) {
    std::string val = def.defValue;
    if (config.contains(sectionKey) && config[sectionKey].contains(key)) {
        try {
            val = config[sectionKey][key].template get<std::string>();
        } catch (const std::exception &e) {
            // Handle conversion error here
            //error_log("Error converting string config key '%s' in section '%s', check your values! Exception: %s", key.c_str(), sectionKey.c_str(), e.what());
        }
    }
    return val;
}

void SetString(json config, json::json_pointer sectionKey, std::string key, ConfigString *def) {
    std::string val = def->defValue;
    if (config.contains(sectionKey) && config[sectionKey].contains(key)) {
        try {
            val = config[sectionKey][key].template get<std::string>();
        } catch (const std::exception &e) {
            // Handle conversion error here
            //error_log("Error converting string config key '%s' in section '%s', check your values! Exception: %s", key.c_str(), sectionKey.c_str(), e.what());
        }
    }

    def->value = val;
}


BHTranslation::BHTranslation() {
    std::ifstream ifile(menu.filename);
    if (ifile) {
        json config = json::parse(std::ifstream{menu.filename});

        SetString(config, "/general"_json_pointer, "title", &menu.general.title);
        SetString(config, "/general"_json_pointer, "tab", &menu.general.tab);
        SetString(config, "/general"_json_pointer, "resync", &menu.general.resync);
        SetString(config, "/general"_json_pointer, "screenshake", &menu.general.screenshake);
        SetString(config, "/general"_json_pointer, "advanceStat", &menu.general.advanceStat);
        SetString(config, "/general"_json_pointer, "beltStatus", &menu.general.beltStatus);
        SetString(config, "/general"_json_pointer, "dpsMeter", &menu.general.dpsMeter);
        SetString(config, "/general"_json_pointer, "expMeter", &menu.general.expMeter);
        SetString(config, "/general"_json_pointer, "playerGear", &menu.general.playerGear);
        SetString(config, "/general"_json_pointer, "reloadConfig", &menu.general.reloadConfig);

        SetString(config, "/quickCast"_json_pointer, "title", &menu.quickCast.title);
        SetString(config, "/quickCast"_json_pointer, "buffTimers", &menu.quickCast.buffTimers);
        SetString(config, "/quickCast"_json_pointer, "onlyEnable", &menu.quickCast.onlyEnable);
        SetString(config, "/quickCast"_json_pointer, "quickCast", &menu.quickCast.quickCast);
        SetString(config, "/quickCast"_json_pointer, "skillBar", &menu.quickCast.skillBar);

        SetString(config, "/interaction"_json_pointer, "tab", &menu.interaction.tab);
        SetString(config, "/interaction"_json_pointer, "hoveringItem", &menu.interaction.hoveringItem);
        SetString(config, "/interaction"_json_pointer, "changeFilterLvl", &menu.interaction.changeFilterLvl);
        SetString(config, "/interaction"_json_pointer, "dropItem", &menu.interaction.dropItem);
        SetString(config, "/interaction"_json_pointer, "dropItemHotkey", &menu.interaction.dropItemHotkey);
        SetString(config, "/interaction"_json_pointer, "holdingItem", &menu.interaction.holdingItem);
        SetString(config, "/interaction"_json_pointer, "identifyByTome", &menu.interaction.identifyByTome);
        SetString(config, "/interaction"_json_pointer, "identifyByTomeHotkey", &menu.interaction.identifyByTomeHotkey);
        SetString(config, "/interaction"_json_pointer, "moveBetweenInventories",
                  &menu.interaction.moveBetweenInventories);
        SetString(config, "/interaction"_json_pointer, "moveBetweenInventoriesHotkey",
                  &menu.interaction.moveBetweenInventoriesHotkey);
        SetString(config, "/interaction"_json_pointer, "moveToCube", &menu.interaction.moveToCube);
        SetString(config, "/interaction"_json_pointer, "moveToCubeHotkey", &menu.interaction.moveToCubeHotkey);
        SetString(config, "/interaction"_json_pointer, "placeOneStackedItem", &menu.interaction.placeOneStackedItem);
        SetString(config, "/interaction"_json_pointer, "placeOneStackedItemHotkey",
                  &menu.interaction.placeOneStackedItemHotkey);
        SetString(config, "/interaction"_json_pointer, "placeOneUnstackedItem", &menu.interaction.placeOneUnstackedItem);
        SetString(config, "/interaction"_json_pointer, "placeOneUnstackedItemHotkey",
                  &menu.interaction.placeOneUnstackedItemHotkey);
        SetString(config, "/interaction"_json_pointer, "setFilterLvl", &menu.interaction.setFilterLvl);
        SetString(config, "/interaction"_json_pointer, "setFilterLvlHotkey", &menu.interaction.setFilterLvlHotkey);
        SetString(config, "/interaction"_json_pointer, "stackUnstack", &menu.interaction.stackUnstack);
        SetString(config, "/interaction"_json_pointer, "stackUnstackHotkey", &menu.interaction.stackUnstackHotkey);

        SetString(config, "/aura"_json_pointer, "title", &menu.aura.title);
        SetString(config, "/aura"_json_pointer, "dclone", &menu.aura.dclone);
        SetString(config, "/aura"_json_pointer, "developer", &menu.aura.developer);
        SetString(config, "/aura"_json_pointer, "developerTitle", &menu.aura.developerTitle);
        SetString(config, "/aura"_json_pointer, "lvl99", &menu.aura.lvl99);
        SetString(config, "/aura"_json_pointer, "lvl99", &menu.aura.pvp);
        SetString(config, "/aura"_json_pointer, "lvl99", &menu.aura.rathma);

        SetString(config, "/item"_json_pointer, "altStyle", &menu.item.altStyle);
        SetString(config, "/item"_json_pointer, "colorMod", &menu.item.colorMod);
        SetString(config, "/item"_json_pointer, "style", &menu.item.style);
        SetString(config, "/item"_json_pointer, "tab", &menu.item.tab);
        SetString(config, "/item"_json_pointer, "title", &menu.item.title);
        SetString(config, "/item"_json_pointer, "shortenNames", &menu.item.shortenNames);
        SetString(config, "/item"_json_pointer, "showEthereal", &menu.item.showEthereal);
        SetString(config, "/item"_json_pointer, "showItemLvl", &menu.item.showItemLvl);
        SetString(config, "/item"_json_pointer, "showItems", &menu.item.showItems);
        SetString(config, "/item"_json_pointer, "showItemStatRanges", &menu.item.showItemStatRanges);
        SetString(config, "/item"_json_pointer, "showRuneNumbers", &menu.item.showRuneNumbers);
        SetString(config, "/item"_json_pointer, "showSockets", &menu.item.showSockets);

        SetString(config, "/lootFilter"_json_pointer, "allItems", &menu.lootFilter.allItems);
        SetString(config, "/lootFilter"_json_pointer, "closeNotifications", &menu.lootFilter.closeNotifications);
        SetString(config, "/lootFilter"_json_pointer, "decFilterLvl", &menu.lootFilter.decFilterLvl);
        SetString(config, "/lootFilter"_json_pointer, "detailedNotifications", &menu.lootFilter.detailedNotifications);
        SetString(config, "/lootFilter"_json_pointer, "dropNotifications", &menu.lootFilter.dropNotifications);
        SetString(config, "/lootFilter"_json_pointer, "enable", &menu.lootFilter.enable);
        SetString(config, "/lootFilter"_json_pointer, "filterLvl", &menu.lootFilter.filterLvl);
        SetString(config, "/lootFilter"_json_pointer, "incFilterLvl", &menu.lootFilter.incFilterLvl);
        SetString(config, "/lootFilter"_json_pointer, "normal", &menu.lootFilter.normal);
        SetString(config, "/lootFilter"_json_pointer, "restoreFilterLvl", &menu.lootFilter.restoreFilterLvl);
        SetString(config, "/lootFilter"_json_pointer, "title", &menu.lootFilter.title);
        SetString(config, "/lootFilter"_json_pointer, "verboseNotifications", &menu.lootFilter.verboseNotifications);

        SetString(config, "/chat"_json_pointer, "changeFilterText", &menu.chat.changeFilterText);
        SetString(config, "/chat"_json_pointer, "changeFilterToAllItemsText", &menu.chat.changeFilterToAllItemsText);
        SetString(config, "/chat"_json_pointer, "closeNotification", &menu.chat.closeNotification);
        SetString(config, "/chat"_json_pointer, "dropNotificationDrop", &menu.chat.dropNotificationDrop);
        SetString(config, "/chat"_json_pointer, "dropNotificationDropped", &menu.chat.dropNotificationDropped);

        SetString(config, "/property"_json_pointer, "affixLvl", &menu.property.affixLvl);
        SetString(config, "/property"_json_pointer, "itemLvl", &menu.property.itemLvl);
        SetString(config, "/property"_json_pointer, "to", &menu.property.to);
        SetString(config, "/property"_json_pointer, "tooLongDescription", &menu.property.tooLongDescription);
    }
    ifile.close();
}
