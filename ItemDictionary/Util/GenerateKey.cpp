#include "GenerateKey.h"

GenerateKey* GenerateKey::m_instance = nullptr;

void GenerateKey::CreateInstance()
{
	// 객체 생성(생성되어있으면 아무것도 안함)
	if (m_instance == nullptr)
	{
		m_instance = new GenerateKey();
	}
}

void GenerateKey::ReleaseInstance()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

GenerateKey* GenerateKey::GetInstance()
{
	return m_instance;
}

GENERATED_KEY GenerateKey::MakeKey(int keyInteger)
{
	return abs(keyInteger);
}

GENERATED_KEY GenerateKey::MakeKey(std::string keyString)
{
	int key{ 0 };
	for (size_t i{ 0 }; i < keyString.length(); ++i)
	{
		key = key * 31 + keyString[i];
	}
	
	return abs(key);
}
