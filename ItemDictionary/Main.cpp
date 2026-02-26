#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <iostream>
#include "Dictionary/ItemDictionary.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	GenerateKey::CreateInstance();

	C_ITEMDICTIONARY dictionary{};
	dictionary.Init();


	std::string Input{};

	while (Input != "exit")
	{
		std::cout << "Type item name want to know(type \"exit\" to Exit): ";
		std::getline(std::cin, Input);

		for (char& oneChar : Input)
		{
			oneChar = std::tolower(static_cast<unsigned char>(oneChar));
		}

		if (Input != "exit")
		{
			dictionary.FindItem(Input);
		}
		

	}


	dictionary.Destroy();
	GenerateKey::ReleaseInstance();

}