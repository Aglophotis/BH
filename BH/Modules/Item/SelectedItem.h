//
// Created by Admin on 26.01.2024.
//

#pragma once
#ifndef SELECTEDITEM_H
#define SELECTEDITEM_H
#include <map>
#include <string>

#include "../../D2Structs.h"

class SelectedItem {
public:
    std::map<int, std::wstring> properties;
    UnitAny* uqPtr;
    unsigned int page;
    static std::wstring copyProperty(wchar_t* source);
    static bool isMultipageableQuality(DWORD quality, DWORD dwFlags);
    bool addProperty(wchar_t* source, int nStat);
    void clear();
    bool assign(UnitAny* pItem);
    unsigned getPage() const;
    void incPage();
    void decPage();
    void parseD2Desc(const wchar_t* wTxt);
    std::wstring getResultDesc() const;
};



#endif //SELECTEDITEM_H
