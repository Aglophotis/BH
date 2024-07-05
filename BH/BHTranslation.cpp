#include "BHTranslation.h"

BHMenu menu;

using json = nlohmann::ordered_json;


std::string GetString(json config, json::json_pointer sectionKey, std::string key, SettingsString def)
{
    std::string val = def.defValue;
    if (config.contains(sectionKey) && config[sectionKey].contains(key)) {
        try {
            val = config[sectionKey][key].template get<std::string>();

        }
        catch (const std::exception& e) {
            // Handle conversion error here
            //error_log("Error converting string config key '%s' in section '%s', check your values! Exception: %s", key.c_str(), sectionKey.c_str(), e.what());
        }
    }
    return val;
}


BHTranslation::BHTranslation() {
    std::ifstream ifile(menu.filename);
    if (ifile)
    {
        json config = json::parse(std::ifstream{ menu.filename });

        std::string temp = GetString(config, "/general"_json_pointer, "title", menu.general.title);
        menu.general.title.defValue =  temp;
    }
    ifile.close();
}


