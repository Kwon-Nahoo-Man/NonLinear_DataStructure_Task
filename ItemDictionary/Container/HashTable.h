#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Util/GenerateKey.h"

template<typename Value>
class C_HASHTABLE
{
private:
	using Entry = std::pair<GENERATED_KEY, Value>;

public:
	C_HASHTABLE() = default;
	~C_HASHTABLE() = default;

	C_HASHTABLE(const C_HASHTABLE&) = delete;
	const C_HASHTABLE& operator=(const C_HASHTABLE&) = delete;

	bool IsEmpty() const;
	bool Add(GENERATED_KEY key, const Value& value);
	bool Delete(GENERATED_KEY key);
	bool Find(GENERATED_KEY key, Entry& outPut);

private:

	static const int hashBucketCount{ 19 };
	std::list<Entry> hashtable[hashBucketCount];
};

template<typename Value>
inline bool C_HASHTABLE<Value>::IsEmpty() const
{
	for (size_t i = 0; i < hashBucketCount; ++i)
	{
		if (hashtable[i].size() != 0)
		{
			return false;
		}
	}
	return true;
}

template<typename Value>
inline bool C_HASHTABLE<Value>::Add(GENERATED_KEY key, const Value& value)
{
	int bucketIndex = key % hashBucketCount;
	std::list<Entry>& position = hashtable[bucketIndex];

	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		if (iter->first == key && iter->second == value)
		{
			std::cout << "해시테이블: 이미 동일한 키 값을 가진 데이터가 저장되어 있습니다.\n";
			return false;
		}

	}

	position.emplace_back(Entry(key, value));

	return true;
}

template<typename Value>
inline bool C_HASHTABLE<Value>::Delete(GENERATED_KEY key)
{
	int bucketIndex = key % hashBucketCount;
	std::list<Entry>& position = hashtable[bucketIndex];

	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		if (iter->first == key)
		{
			position.erase(iter);
			return true;
		}

	}
	std::cout << "해시테이블: 삭제할 데이터를 찾지 못했습니다.\n";
	return false;
}

template<typename Value>
inline bool C_HASHTABLE<Value>::Find(GENERATED_KEY key, Entry& outPut)
{
	int bucketIndex = key % hashBucketCount;
	std::list<Entry>& position = hashtable[bucketIndex];
	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		if (iter->first == key)
		{
			outPut = *iter;
			return true;
		}
	}
	
	return false;
}

