#pragma once
#include <string>

typedef int GENERATED_KEY;

class GenerateKey
{
public:
	GenerateKey() = default;

public:
	static void CreateInstance();
	static void ReleaseInstance();
	static GenerateKey* GetInstance();

	GENERATED_KEY MakeKey(int keyInteger);
	GENERATED_KEY MakeKey(std::string keyString);

private:
	static GenerateKey* m_instance;


};