#include "ItemDictionary.h"

void C_ITEMDICTIONARY::Init(const char* fileName)
{
	char path[2048]{};
	sprintf_s(path, 2048, "../Assets/%s", fileName);

	FILE* file = nullptr;
	fopen_s(&file, path, "rt");

	if (file == nullptr)
	{
		__debugbreak();
	}

	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);

	char* data = new char[fileSize + 1] {};
	fread(data, sizeof(char), fileSize, file);

	char* context{};
	char* token{};

	token = strtok_s(data, "\n", &context);
	while (token)
	{
		// ItemInfo에 저장할 데이터
		int itemID{};
		std::string name{};
		E_ITEMTYPE itemType{};
		std::string description{};

		char* oneLineContext{};
		char* part = strtok_s(token, ",", &oneLineContext);

		if (part == nullptr)
		{
			__debugbreak();
		}
		itemID = std::atoi(part);
		part = strtok_s(nullptr, ",", &oneLineContext);

		if (part == nullptr)
		{
			__debugbreak();
		}
		name = part;
		part = strtok_s(nullptr, ",", &oneLineContext);

		if (part == nullptr)
		{
			__debugbreak();
		}
		itemType = static_cast<E_ITEMTYPE>(std::atoi(part));
		part = strtok_s(nullptr, ",", &oneLineContext);

		if (part == nullptr)
		{
			__debugbreak();
		}
		description = part;

		// hashTable에 들어갈 키 생성
		GENERATED_KEY bucketIndex = GenerateKey::GetInstance()->MakeKey(name);
		
		// data로 들어갈 ItemInfo 생성
		C_ITEMINFO* itemInfo = new C_ITEMINFO();
		itemInfo->Init(itemID, name, itemType, description);
		
		// hashTable에 추가
		m_itemTable.Add(bucketIndex, itemInfo);

		token = strtok_s(nullptr, "\n", &context);

	}

	delete[] data;
	data = nullptr;

	fclose(file);

}

void C_ITEMDICTIONARY::Destroy()
{
	if (m_itemTable.IsEmpty() == true)
	{
		return;
	}
	
	// 동적할당한 메모리 해제
	int bucketCount = m_itemTable.GetBucketNumber();
	for (int i = 0; i < bucketCount; ++i)
	{
		for (auto iter = m_itemTable[i].begin(); iter != m_itemTable[i].end(); ++iter)
		{
			delete (*iter).second;
		}
	}

	m_itemTable.Clear();

}

void C_ITEMDICTIONARY::FindItem(std::string itemName)
{
	GENERATED_KEY key = GenerateKey::GetInstance()->MakeKey(itemName);
	std::pair<GENERATED_KEY, C_ITEMINFO*> output{};
	if (m_itemTable.Find(key, output))
	{
		std::cout
			<< "\n===================================\n"
			<< "\nItem ID: " << output.second->m_itemID << "\t"
			<< "Item Name: " << output.second->m_name << "\t"
			<< "Item Type: " << ITEMTYPE::ToString(output.second->m_itemType) << "\n\n"
			<< "<Item Description>" << "\n"
			<< output.second->m_description << "\n"
			<< "\n===================================\n\n";
	}
	else
	{
		std::cout
			<< "\n===================================\n"
			<< "\nThere's No data.\n"
			<< "\n===================================\n\n";
	}
}
