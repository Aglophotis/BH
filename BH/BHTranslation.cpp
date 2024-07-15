#include "BHTranslation.h"
#include <nlohmann/json.hpp>
#include <fstream>

#include "Common.h"

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
    std::string filename = GetLangCode() + "." + menu.filename;

    std::ifstream ifile(filename);
    if (ifile) {
        json config = json::parse(std::ifstream{filename});

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
        SetString(config, "/chat"_json_pointer, "reloadConfig", &menu.chat.reloadConfig);
        SetString(config, "/chat"_json_pointer, "reloadFilter", &menu.chat.reloadFilter);

        SetString(config, "/property"_json_pointer, "affixLvl", &menu.property.affixLvl);
        SetString(config, "/property"_json_pointer, "itemLvl", &menu.property.itemLvl);
        SetString(config, "/property"_json_pointer, "to", &menu.property.to);
        SetString(config, "/property"_json_pointer, "tooLongDescription", &menu.property.tooLongDescription);

        SetString(config, "/party"_json_pointer, "autoloot", &menu.party.autoloot);
        SetString(config, "/party"_json_pointer, "autoparty", &menu.party.autoparty);

        SetString(config, "/stash"_json_pointer, "exportOnMenu", &menu.stash.exportOnMenu);
        SetString(config, "/stash"_json_pointer, "exportType", &menu.stash.exportType);
        SetString(config, "/stash"_json_pointer, "gear", &menu.stash.gear);
        SetString(config, "/stash"_json_pointer, "includeEquipment", &menu.stash.includeEquipment);
        SetString(config, "/stash"_json_pointer, "tab", &menu.stash.tab);
        SetString(config, "/stash"_json_pointer, "title", &menu.stash.title);

        SetString(config, "/settings"_json_pointer, "tab", &menu.settings.tab);
        SetString(config, "/settings"_json_pointer, "closeSettings", &menu.settings.closeSettings);
        SetString(config, "/settings"_json_pointer, "moveSettings", &menu.settings.moveSettings);
        SetString(config, "/settings"_json_pointer, "openSettings", &menu.settings.openSettings);

        SetString(config, "/color"_json_pointer, "choose", &menu.color.choose);
        SetString(config, "/color"_json_pointer, "close", &menu.color.close);
        SetString(config, "/color"_json_pointer, "select", &menu.color.select);

        SetString(config, "/stats"_json_pointer, "additionalXp", &menu.stats.additionalXp);
        SetString(config, "/stats"_json_pointer, "lvl", &menu.stats.lvl);
        SetString(config, "/stats"_json_pointer, "merc", &menu.stats.merc);
        SetString(config, "/stats"_json_pointer, "name", &menu.stats.name);
        SetString(config, "/stats"_json_pointer, "xp", &menu.stats.xp);
        SetString(config, "/stats"_json_pointer, "absorp", &menu.stats.absorp);
        SetString(config, "/stats"_json_pointer, "attackRate", &menu.stats.attackRate);
        SetString(config, "/stats"_json_pointer, "baseAR", &menu.stats.baseAR);
        SetString(config, "/stats"_json_pointer, "baseDamage", &menu.stats.baseDamage);
        SetString(config, "/stats"_json_pointer, "baseDef", &menu.stats.baseDef);
        SetString(config, "/stats"_json_pointer, "blockRate", &menu.stats.blockRate);
        SetString(config, "/stats"_json_pointer, "breakpoints", &menu.stats.breakpoints);
        SetString(config, "/stats"_json_pointer, "castRate", &menu.stats.castRate);
        SetString(config, "/stats"_json_pointer, "coldResist", &menu.stats.coldResist);
        SetString(config, "/stats"_json_pointer, "curseResist", &menu.stats.curseResist);
        SetString(config, "/stats"_json_pointer, "damageReduction", &menu.stats.damageReduction);
        SetString(config, "/stats"_json_pointer, "dex", &menu.stats.dex);
        SetString(config, "/stats"_json_pointer, "elementalMastery", &menu.stats.elementalMastery);
        SetString(config, "/stats"_json_pointer, "elementalPierce", &menu.stats.elementalPierce);
        SetString(config, "/stats"_json_pointer, "equip", &menu.stats.equip);
        SetString(config, "/stats"_json_pointer, "fcr", &menu.stats.fcr);
        SetString(config, "/stats"_json_pointer, "fhr", &menu.stats.fhr);
        SetString(config, "/stats"_json_pointer, "fireResist", &menu.stats.fireResist);
        SetString(config, "/stats"_json_pointer, "hitRecovery", &menu.stats.hitRecovery);
        SetString(config, "/stats"_json_pointer, "ias", &menu.stats.ias);
        SetString(config, "/stats"_json_pointer, "iasFrames", &menu.stats.iasFrames);
        SetString(config, "/stats"_json_pointer, "lightningResist", &menu.stats.lightningResist);
        SetString(config, "/stats"_json_pointer, "oneHanded", &menu.stats.oneHanded);
        SetString(config, "/stats"_json_pointer, "poisonResist", &menu.stats.poisonResist);
        SetString(config, "/stats"_json_pointer, "resistLength", &menu.stats.resistLength);
        SetString(config, "/stats"_json_pointer, "runWalk", &menu.stats.runWalk);
        SetString(config, "/stats"_json_pointer, "thornDamage", &menu.stats.thornDamage);
        SetString(config, "/stats"_json_pointer, "total", &menu.stats.total);
        SetString(config, "/stats"_json_pointer, "twoHanded", &menu.stats.twoHanded);
        SetString(config, "/stats"_json_pointer, "crushingBlow", &menu.stats.crushingBlow);
        SetString(config, "/stats"_json_pointer, "openWounds", &menu.stats.openWounds);
        SetString(config, "/stats"_json_pointer, "deadlyStrike", &menu.stats.deadlyStrike);
        SetString(config, "/stats"_json_pointer, "criticalStrike", &menu.stats.criticalStrike);
        SetString(config, "/stats"_json_pointer, "lifeLeech", &menu.stats.lifeLeech);
        SetString(config, "/stats"_json_pointer, "manaLeech", &menu.stats.manaLeech);
        SetString(config, "/stats"_json_pointer, "projectilePierce", &menu.stats.projectilePierce);
        SetString(config, "/stats"_json_pointer, "hpMpPerKill", &menu.stats.hpMpPerKill);
        SetString(config, "/stats"_json_pointer, "addedDamage", &menu.stats.addedDamage);
        SetString(config, "/stats"_json_pointer, "over", &menu.stats.over);
        SetString(config, "/stats"_json_pointer, "second", &menu.stats.second);
        SetString(config, "/stats"_json_pointer, "magicFind", &menu.stats.magicFind);
        SetString(config, "/stats"_json_pointer, "goldFind", &menu.stats.goldFind);
        SetString(config, "/stats"_json_pointer, "stashGold", &menu.stats.stashGold);
        SetString(config, "/stats"_json_pointer, "iasFramesNotAvailable", &menu.stats.iasFramesNotAvailable);

        SetString(config, "/altStyle"_json_pointer, "identify", &menu.altStyle.identify);
        SetString(config, "/altStyle"_json_pointer, "teleport", &menu.altStyle.teleport);
        SetString(config, "/altStyle"_json_pointer, "andarielDuriel", &menu.altStyle.andarielDuriel);
        SetString(config, "/altStyle"_json_pointer, "antidote", &menu.altStyle.antidote);
        SetString(config, "/altStyle"_json_pointer, "baal", &menu.altStyle.baal);
        SetString(config, "/altStyle"_json_pointer, "choking", &menu.altStyle.choking);
        SetString(config, "/altStyle"_json_pointer, "diablo", &menu.altStyle.diablo);
        SetString(config, "/altStyle"_json_pointer, "ethereal", &menu.altStyle.ethereal);
        SetString(config, "/altStyle"_json_pointer, "exploding", &menu.altStyle.exploding);
        SetString(config, "/altStyle"_json_pointer, "fullRejuvenation", &menu.altStyle.fullRejuvenation);
        SetString(config, "/altStyle"_json_pointer, "fulminating", &menu.altStyle.fulminating);
        SetString(config, "/altStyle"_json_pointer, "gtHeal", &menu.altStyle.gtHeal);
        SetString(config, "/altStyle"_json_pointer, "gtMana", &menu.altStyle.gtMana);
        SetString(config, "/altStyle"_json_pointer, "heal", &menu.altStyle.heal);
        SetString(config, "/altStyle"_json_pointer, "ltHeal", &menu.altStyle.ltHeal);
        SetString(config, "/altStyle"_json_pointer, "ltMana", &menu.altStyle.ltMana);
        SetString(config, "/altStyle"_json_pointer, "lvl", &menu.altStyle.lvl);
        SetString(config, "/altStyle"_json_pointer, "mana", &menu.altStyle.mana);
        SetString(config, "/altStyle"_json_pointer, "mephisto", &menu.altStyle.mephisto);
        SetString(config, "/altStyle"_json_pointer, "minHeal", &menu.altStyle.minHeal);
        SetString(config, "/altStyle"_json_pointer, "oil", &menu.altStyle.oil);
        SetString(config, "/altStyle"_json_pointer, "rancid", &menu.altStyle.rancid);
        SetString(config, "/altStyle"_json_pointer, "rejuvenation", &menu.altStyle.rejuvenation);
        SetString(config, "/altStyle"_json_pointer, "stamina", &menu.altStyle.stamina);
        SetString(config, "/altStyle"_json_pointer, "strangling", &menu.altStyle.strangling);
        SetString(config, "/altStyle"_json_pointer, "supHeal", &menu.altStyle.supHeal);
        SetString(config, "/altStyle"_json_pointer, "supMana", &menu.altStyle.supMana);
        SetString(config, "/altStyle"_json_pointer, "thawing", &menu.altStyle.thawing);
    }
    ifile.close();
}
