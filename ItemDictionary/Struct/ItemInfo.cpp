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
    // 아이템 마다의 고유 ID가 있다면 전부 비교 필요 없이 ID만 비교해도 될 듯

    return
        this->m_itemID == other.m_itemID &&
        this->m_name == other.m_name &&
        this->m_itemType == other.m_itemType &&
        this->m_description == other.m_description;
}
