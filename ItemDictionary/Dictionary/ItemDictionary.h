#pragma once
#include "Container/HashTable.h"
#include "Struct/ItemInfo.h"

class C_ITEMDICTIONARY
{
public:
	C_ITEMDICTIONARY() = default;
	~C_ITEMDICTIONARY() = default;

	// 복사 방지
	C_ITEMDICTIONARY(const C_ITEMDICTIONARY&) = delete;
	const C_ITEMDICTIONARY& operator=(const C_ITEMDICTIONARY&) = delete;

	void Init(const char* fileName = "asset.csv");
	void Destroy();
	void FindItem(std::string itemName);

private:
	C_HASHTABLE<C_ITEMINFO*> m_itemTable{};



};
