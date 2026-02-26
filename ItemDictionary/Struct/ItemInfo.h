#pragma once
#include <string>
#include "Enumeration/ItemType.h"

class C_ITEMINFO
{
public:

	C_ITEMINFO() = default;
	~C_ITEMINFO() = default;

	C_ITEMINFO(const C_ITEMINFO&) = delete;
	const C_ITEMINFO& operator=(const C_ITEMINFO&) = delete;

	bool operator==(const C_ITEMINFO& other) const;
	
public:

	//int m_itemID{};
	std::string m_name{};
	E_ITEMTYPE m_itemType{};
	std::string m_description{};
};
