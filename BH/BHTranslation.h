#pragma once
#include <string>

struct ConfigString {
    std::string value;
    std::string defValue;

    ConfigString(std::string val, std::string defVal) {
        defValue = defVal;
        value = val;
    }

    ConfigString(std::string defVal) {
        defValue = defVal;
        value = defVal;
    }

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
        ConfigString title = { "General"};
        ConfigString tab = { "General"};
        ConfigString playerGear = { "Show Player's Gear"};
        ConfigString resync = { "Resync"};
        ConfigString advanceStat = { "Advanced Stat Display"};
        ConfigString reloadConfig = { "Reload Config"};
        ConfigString expMeter = { "Experience Meter"};
        ConfigString screenshake = { "Enable Screenshake"};
        ConfigString dpsMeter = { "Enable DPS Counter"};
        ConfigString beltStatus = { "Enable Belt Status"};
    } general;

    struct {
        ConfigString title = { "Quick Cast"};
        ConfigString quickCast = { "Quick Cast"};
        ConfigString skillBar = { "Skill Bar"};
        ConfigString onlyEnable = { "Only enable with Quick Cast"};
        ConfigString buffTimers = { "Always show Buff Timers"};
    } quickCast;

    struct {
        ConfigString tab = { "Interaction"};
        ConfigString hoveringItem = { "Hovering an item"};
        ConfigString identifyByTomeHotkey = { "Shift+Left Click"};
        ConfigString identifyByTome = { "ID with an ID tome"};
        ConfigString moveBetweenInventoriesHotkey = { "Shift+Right Click"};
        ConfigString moveBetweenInventories = { "Move between inventories"};
        ConfigString dropItemHotkey = { "Ctrl+Right Click"};
        ConfigString dropItem = { "Move to ground"};
        ConfigString moveToCubeHotkey = { "Ctrl+Shift+Right Click"};
        ConfigString moveToCube = { "Move to closed cube"};
        ConfigString stackUnstackHotkey = { "Ctrl+Shift+Left Click"};
        ConfigString stackUnstack = { "Toggle stacked/unstacked"};
        ConfigString holdingItem = { "Holding an item"};
        ConfigString placeOneStackedItemHotkey = { "Ctrl+Left Click"};
        ConfigString placeOneStackedItem = { "Place 1 stacked item"};
        ConfigString placeOneUnstackedItemHotkey = { "Ctrl+Shift+Left Click"};
        ConfigString placeOneUnstackedItem = { "Place 1 unstacked item"};
        ConfigString changeFilterLvl = { "Changing filter levels"};
        ConfigString setFilterLvlHotkey = { "Ctrl+Numpad [0 - 9]"};
        ConfigString setFilterLvl = { "Set filter level"};
    } interaction;

    struct {
        ConfigString title = { "Auras (only for top 3 players)"};
        ConfigString lvl99 = { "Show 99 Aura"};
        ConfigString dclone = { "Show Dclone Aura"};
        ConfigString rathma = { "Show Rathma Aura"};
        ConfigString pvp = { "Show PVP Aura"};
        ConfigString developerTitle = { "Developer Only"};
        ConfigString developer = { "Show Developer Aura"};
    } aura;

    struct {
        ConfigString tab = { "Item"};
        ConfigString title = { "Settings"};
        ConfigString showItems = { "Always Show Items"};
        ConfigString showItemStatRanges = { "Always Show Item Stat Ranges"};
        ConfigString showItemLvl = { "Show Item Level"};
        ConfigString style = { "Display Style (only without loot filter)"};
        ConfigString showEthereal = { "Show Ethereal"};
        ConfigString showSockets = { "Show Sockets"};
        ConfigString showRuneNumbers = { "Show Rune Numbers"};
        ConfigString altStyle = { "Alt Style"};
        ConfigString colorMod = { "Color Mod"};
        ConfigString shortenNames = { "Shorten Names"};
    } item;

    struct {
        ConfigString title = { "Loot Filter"};
        ConfigString enable = { "Enable Loot Filter"};
        ConfigString dropNotifications = { "Drop Notifications"};
        ConfigString closeNotifications = { "Close Notifications"};
        ConfigString detailedNotifications = { "Detailed Notifications"};
        ConfigString verboseNotifications = { "Verbose Notifications"};
        ConfigString incFilterLvl = { "Increase Filter Level"};
        ConfigString decFilterLvl = { "Decrease Filter Level"};
        ConfigString restoreFilterLvl = { "Restore Previous Filter Level"};
        ConfigString filterLvl = { "Filter Level:"};
        ConfigString allItems = { "0 - Show All Items"};
        ConfigString normal = { "1 - Normal"};
    } lootFilter;

    struct {
        ConfigString changeFilterToAllItemsText = { "Filter level: ÿc50 - Show All Items"};
        ConfigString changeFilterText = { "Filter level: ÿc0"};
        ConfigString dropNotificationDropped = { "Dropped"};
        ConfigString dropNotificationDrop = { " ÿc5drop"};
        ConfigString closeNotification = { "ÿc5close"};
        ConfigString reloadConfig = { "Reloading config"};
        ConfigString reloadFilter = { "Reloading filter"};
    } chat;

    struct {
        ConfigString affixLvl = { "Affix Level"};
        ConfigString itemLvl = { "Item Level"};
        ConfigString to = { "to"};
        ConfigString tooLongDescription = { "ÿc1Item Description is too long."};
    } property;

    struct {
        ConfigString autoparty = { "Autoparty Enabled"};
        ConfigString autoloot = { "Autoloot Enabled"};
    } party;

    struct {
        ConfigString tab = { "StashExport"};
        ConfigString title = { "Stash"};
        ConfigString gear = { "Export Gear"};
        ConfigString includeEquipment = { "Include Equipment"};
        ConfigString exportOnMenu = { "Export On Menu"};
        ConfigString exportType = { "Export Type"};
    } stash;

    struct {
        ConfigString tab = { "Settings"};
        ConfigString openSettings = { "CTRL-click to open settings"};
        ConfigString moveSettings = { "Shift-drag to move"};
        ConfigString closeSettings = { "Right Click or ESC to Close"};
    } settings;

    struct {
        ConfigString choose = { "Choose Color"};
        ConfigString select = { "Left Click - Select"};
        ConfigString close = { "Right Click - Close"};
    } color;

    struct {
        ConfigString teleport = { "ÿc2**ÿc0TP"};
        ConfigString identify = { "ÿc2**ÿc0ID"};
        ConfigString stamina = { "Stam"};
        ConfigString antidote = { "Anti"};
        ConfigString thawing = { "Thaw"};
        ConfigString rancid = { "Ranc"};
        ConfigString oil = { "Oil"};
        ConfigString choking = { "Chok"};
        ConfigString exploding = { "Expl"};
        ConfigString strangling = { "Stra"};
        ConfigString fulminating = { "Fulm"};

        ConfigString minHeal = { "ÿc1**ÿc0Min Heal"};
        ConfigString ltHeal = { "ÿc1**ÿc0Lt Heal"};
        ConfigString heal = { "ÿc1**ÿc0Heal"};
        ConfigString gtHeal = { "ÿc1**ÿc0Gt Heal"};
        ConfigString supHeal = { "ÿc1**ÿc0Sup Heal"};
        ConfigString minMana = { "ÿc3**ÿc0Min Mana"};
        ConfigString ltMana = { "ÿc3**ÿc0Lt Mana"};
        ConfigString mana = { "ÿc3**ÿc0Mana"};
        ConfigString gtMana = { "ÿc3**ÿc0Gt Mana"};
        ConfigString supMana = { "ÿc3**ÿc0Sup Mana"};
        ConfigString rejuvenation = { "ÿc;**ÿc0Rejuv"};
        ConfigString fullRejuvenation = { "ÿc;**ÿc0Full"};

        ConfigString andarielDuriel = { "(Andariel/Duriel)"};
        ConfigString mephisto = { "(Mephtisto)"};
        ConfigString diablo = { "(Diablo)"};
        ConfigString baal = { "(Baal)"};
        ConfigString ethereal = { "Eth"};
        ConfigString lvl = { "L"};
    } altStyle;

    struct {
        ConfigString name { "Name"};
        ConfigString merc { "ÿc;Mercenary"};
        ConfigString lvl { "Level"};
        ConfigString xp { "XP"};
        ConfigString additionalXp { "Additional XP"};

        ConfigString fireResist { "Fire Resist"};
        ConfigString lightningResist { "Lightning Resist"};
        ConfigString poisonResist { "Poison Resist"};
        ConfigString coldResist { "Cold Resist"};
        ConfigString curseResist { "Curse Resist"};
        ConfigString resistLength { "Length"};

        ConfigString absorp { "Absorption"};
        ConfigString damageReduction { "Damage Reduction"};
        ConfigString thornDamage { "Attacker Takes Damage"};
        ConfigString elementalMastery { "Elemental Mastery"};
        ConfigString elementalPierce { "Elemental Pierce"};

        ConfigString baseAR { "Base AR"};
        ConfigString equip { "equip"};
        ConfigString total { "total"};
        ConfigString dex { "dex"};
        ConfigString oneHanded { "1h"};
        ConfigString twoHanded { "2h"};
        ConfigString baseDef { "Base Def"};
        ConfigString baseDamage { "Base Damage"};
        ConfigString castRate { "Cast Rate"};
        ConfigString blockRate { "Block Rate"};
        ConfigString hitRecovery { "Hit Recovery"};
        ConfigString runWalk { "Run/Walk"};
        ConfigString attackRate { "Attack Rate"};
        ConfigString ias { "IAS"};
        ConfigString breakpoints { "Breakpoints"};
        ConfigString fcr { "FCR"};
        ConfigString fhr { "FHR"};
        ConfigString iasFrames { "IAS (Frames)"};

        ConfigString crushingBlow { "Crushing Blow"};
        ConfigString openWounds { "Open Wounds"};
        ConfigString deadlyStrike { "Deadly Strike"};
        ConfigString criticalStrike { "Critical Strike"};
        ConfigString lifeLeech { "Life Leech"};
        ConfigString manaLeech { "Mana Leech"};
        ConfigString projectilePierce { "Projectile Pierce"};
        ConfigString hpMpPerKill { "HP/MP per Kill"};
        ConfigString addedDamage { "Added Damage"};
        ConfigString over { "over"};
        ConfigString magicFind { "Magic Find"};
        ConfigString goldFind { "Gold Find"};
        ConfigString stashGold { "Stash Gold"};
        ConfigString iasFramesNotAvailable { "IAS (Frames): N/A"};
    } stats;
};


class BHTranslation {
public:
    BHMenu menu = {};

    BHTranslation();

    ~BHTranslation() = default;
};


