#pragma once

enum class E_ITEMTYPE : int
{
	NONE = 0,
	ITEMTYPE_EQUITMENT = 1,
	ITEMTYPE_CONSUMABLE = 2,
	ITEMTYPE_MATERIAL = 3,
	ITEMTYPE_QUEST = 4,
	ITEMTYPE_SKILLBOOK = 5,
	MAX
};

namespace ITEMTYPE
{
	const char* ToString(E_ITEMTYPE type);
}

