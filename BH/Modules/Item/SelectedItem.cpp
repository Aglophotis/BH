//
// Created by Admin on 26.01.2024.
//

#include "SelectedItem.h"

#include <sstream>

#include "../../Constants.h"
#include "../../D2Ptrs.h"

std::vector<std::wstring> properties;
std::vector<unsigned> pages = {0};

UnitAny* uqPtr;
unsigned int page;
unsigned int maxPage = 0;
short maxLines = 20;
unsigned int maxLength = 1023;
bool inited = false;
bool notIgnore = true;

short currentLine = 0;
unsigned int currentLength = 0;

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
            ++currentLine;
            currentLength += property.length();

            if (currentLength > maxLength || currentLine >= maxLines + 1)
            {
                ++maxPage;
                pages.push_back(properties.size());
                currentLength = property.length();
                currentLine = 0;
            }

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
    pages.clear();
    pages.push_back(0);
    uqPtr = nullptr;
    page = 0;
    maxPage = 0;
    currentLine = 0;
    currentLength = 0;
    notIgnore = false;
    inited = false;
}

bool SelectedItem::assign(UnitAny* pItem)
{
    if (uqPtr != pItem)
    {
        clear();
        uqPtr = pItem;
        notIgnore = isMultipageableQuality(pItem->pItemData->dwQuality, pItem->pItemData->dwFlags);

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
    if (page < maxPage)
    {
        ++page;
    }
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
        if (page < maxPage)
        {
            result.append(L"...\n");
        }
        for (unsigned i = pages[page + 1]; i > pages[page]; i--)
        {
            result.append(properties[i - 1]).append(L"\n");
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
    if (!inited)
    {
        inited = true;
        pages.push_back(properties.size());
    }
}