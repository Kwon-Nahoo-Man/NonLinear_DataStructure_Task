#include "ItemType.h"

static const char* ITEMTYPE_NAMES[]
{
	"None",
	"Equipment",
	"Consumable",
	"Material",
	"Quest",
	"SkillBook"
};

namespace ITEMTYPE
{
	const char* ToString(E_ITEMTYPE type)
	{
		int index = static_cast<int>(type);
		if (index < 0 || index >= static_cast<int>(E_ITEMTYPE::MAX))
		{
			return "Unkown";
		}

		return ITEMTYPE_NAMES[index];
	}
}


