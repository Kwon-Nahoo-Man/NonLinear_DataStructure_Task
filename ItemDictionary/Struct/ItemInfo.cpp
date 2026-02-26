#include "ItemInfo.h"

void C_ITEMINFO::Init(int itemID, std::string name, E_ITEMTYPE itemtype, std::string description)
{
    m_itemID = itemID;
    m_name = name;
    m_itemType = itemtype;
    m_description = description;
}

bool C_ITEMINFO::operator==(const C_ITEMINFO& other) const
{
    return
        this->m_name == other.m_name &&
        this->m_itemType == other.m_itemType &&
        this->m_description == other.m_description;
}
