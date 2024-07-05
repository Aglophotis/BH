#pragma once
#include <string>

#include "Config.h"

struct BHMenu {
    string filename = "menu.json";

    struct {
        SettingsString title = {"", "General"};
    } general;
};


class BHTranslation {
public:
    BHMenu menu = {};

    BHTranslation();

    ~BHTranslation() = default;
};


