#include "ItemType.h"

// enum 번호에 맞는 출력할 문자열
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
		
		// 설정되지 않은 int값이면 unknown
		if (index < 0 || index >= static_cast<int>(E_ITEMTYPE::MAX))
		{
			return "Unkown";
		}

		return ITEMTYPE_NAMES[index];
	}
}


