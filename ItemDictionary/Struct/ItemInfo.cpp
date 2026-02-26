#include "ItemInfo.h"

bool C_ITEMINFO::operator==(const C_ITEMINFO& other) const
{
    return
        this->m_name == other.m_name &&
        this->m_itemType == other.m_itemType &&
        this->m_description == other.m_description;
}
