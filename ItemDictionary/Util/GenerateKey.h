#pragma once
#include <string>

// 변환되는 키 값도 int지만, 그냥 int와 구별하기 위해 typedef
typedef int GENERATED_KEY;

// input 값을 hashTable의 key값으로 변환해주는 객체
// 전역적으로 사용할 수 있게 Singleton
class GenerateKey
{
public:
	GenerateKey() = default;

public:
	static void CreateInstance();
	static void ReleaseInstance();
	static GenerateKey* GetInstance();

	// 아직은 키를 변환해주는 것이 int와 string 밖에 없음
	GENERATED_KEY MakeKey(int keyInteger);
	GENERATED_KEY MakeKey(std::string keyString);

private:
	static GenerateKey* m_instance;


};