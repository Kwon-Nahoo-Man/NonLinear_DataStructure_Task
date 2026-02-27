#pragma once
#include <string>
#include "Enumeration/ItemType.h"

// 원래는 struct였으나, 연산자 오버로딩도 필요하고 init도 따로 만들어서
// 그냥 클래스로 함
class C_ITEMINFO
{
public:

	C_ITEMINFO() = default;
	~C_ITEMINFO() = default;

	C_ITEMINFO(const C_ITEMINFO&) = delete;
	const C_ITEMINFO& operator=(const C_ITEMINFO&) = delete;

	void Init(int itemID, std::string name, E_ITEMTYPE itemtype, std::string description);

	bool operator==(const C_ITEMINFO& other) const;
	
public:
	// hashTable의 key를 아이템 고유의 id값으로 하면 편하지 않을까?
	int m_itemID{};
	std::string m_name{};
	E_ITEMTYPE m_itemType{};
	std::string m_description{};
};
