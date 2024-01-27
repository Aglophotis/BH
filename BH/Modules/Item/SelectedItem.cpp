//
// Created by Admin on 26.01.2024.
//

#include "SelectedItem.h"

#include <sstream>

#include "../../Constants.h"
#include "../../D2Ptrs.h"

std::vector<std::wstring> properties;
UnitAny* uqPtr;
unsigned int page;
bool inited = false;
bool notIgnore = true;

std::vector<std::wstring> split (const std::wstring &s, wchar_t delim) {
    std::vector<std::wstring> result;
    std::wstringstream ss (s);
    std::wstring item;

    while (getline (ss, item, delim)) {
        if (!item.empty() && item.size() > 1)
        {
            result.push_back (item);
        }
    }

    return result;
}

std::wstring SelectedItem::copyProperty(wchar_t* source)
{
    auto w = std::wstring(source);
    auto* out = new wchar_t[w.size() + 1];
    std::copy(w.begin(), w.end(), out);
    out[w.size()] = L'\0';

    return out;
}

bool SelectedItem::isMultipageableQuality(DWORD quality, DWORD dwFlags)
{
    return quality == ITEM_QUALITY_MAGIC || quality == ITEM_QUALITY_SUPERIOR ||
        quality == ITEM_QUALITY_INFERIOR || (quality == ITEM_QUALITY_NORMAL && dwFlags != 10485776) ||
        quality == ITEM_QUALITY_UNIQUE || quality == ITEM_QUALITY_RARE || quality == ITEM_QUALITY_CRAFT;
}

bool SelectedItem::addProperty(wchar_t* source, int nStat)
{
    UnitAny* pItem = *p_D2CLIENT_SelectedInvItem;

    assign(pItem);
    if (inited)
    {
        if (notIgnore)
        {
            source[1] = L'\0';
        }

        return false;
    }

    if (notIgnore)
    {
        const auto property = copyProperty(source);
        if (!property.empty())
        {
            properties.push_back(property);
        }
        source[1] = L'\0';

        return true;
    }

    return false;
}

void SelectedItem::clear()
{
    properties.clear();
    uqPtr = nullptr;
    page = 0;
    notIgnore = false;
    inited = false;
}

bool SelectedItem::assign(UnitAny* pItem)
{
    if (uqPtr != pItem)
    {
        properties.clear();
        uqPtr = pItem;
        page = 0;
        notIgnore = isMultipageableQuality(pItem->pItemData->dwQuality, pItem->pItemData->dwFlags);
        inited = false;

        return true;
    }

    return false;
}

unsigned int SelectedItem::getPage() const
{
    return page;
}

void SelectedItem::incPage()
{
    ++page;
}

void SelectedItem::decPage()
{
    if (page > 0)
    {
        --page;
    }
}

void SelectedItem::parseD2Desc(const wchar_t* wTxt)
{
    if (notIgnore && !inited)
    {
        for (const auto& basic_string : split(wTxt, '\n'))
        {
            properties.push_back(basic_string);
        }
    }
}

std::wstring SelectedItem::getResultDesc() const
{
    std::wstring result;
    if (notIgnore)
    {
        short buffer = 15;

        for (unsigned i = page * buffer; i < (page * buffer) + buffer && i < properties.size(); i++)
        {
            result.append(properties[i]).append(L"\n");
        }
    }

    return result;
}

bool SelectedItem::isIgnore()
{
    return !notIgnore;
}

bool SelectedItem::isInitialized()
{
    return inited;
}

void SelectedItem::initialize()
{
    inited = true;
}