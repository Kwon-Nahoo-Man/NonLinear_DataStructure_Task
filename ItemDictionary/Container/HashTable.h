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

	const std::list<Entry>& operator[](int index) const
	{
		if (index >= hashBucketCount)
		{
			__debugbreak();
		}
		return hashtable[index];
	}

	inline int GetBucketNumber() const { return hashBucketCount; }
	
	bool IsEmpty() const;
	bool Add(GENERATED_KEY key, const Value& value);
	bool Delete(GENERATED_KEY key);
	bool Find(GENERATED_KEY key, Entry& outPut);
	void Clear();

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
			std::cout << "HashTable: Data with same key is already stored.\n\n";
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
	std::cout << "HashTable: Couldn't find data to delete.\n\n";
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

template<typename Value>
inline void C_HASHTABLE<Value>::Clear()
{
	for (int i = 0; i < hashBucketCount; ++i)
	{
		hashtable[i].clear();
	}
}

