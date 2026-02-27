#pragma once

// 아이템 타입을 위한 enum
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

// enum(int)값을 문자열로 바꿔주는 것
// 그냥 전역적으로 선언하면 ToString이 누구를 위한 것인지 모호하여
// namespace 사용
namespace ITEMTYPE
{
	const char* ToString(E_ITEMTYPE type);
}

