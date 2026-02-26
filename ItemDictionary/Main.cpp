#include <iostream>
#include "Container/HashTable.h"


int main()
{
	GenerateKey::CreateInstance();

	C_HASHTABLE<int> hashTable{};

	if (hashTable.IsEmpty())
	{
		std::cout << "Empty\n";
	}
	else
	{
		std::cout << "Not Empty\n";
	}
	
	
	
	hashTable.Add(GenerateKey::GetInstance()->MakeKey(10), 444);
	hashTable.Add(GenerateKey::GetInstance()->MakeKey(100), 4444);
	hashTable.Add(GenerateKey::GetInstance()->MakeKey(10), 444);
	hashTable.Add(GenerateKey::GetInstance()->MakeKey(5),777);

	hashTable.Delete(GenerateKey::GetInstance()->MakeKey(10));
	hashTable.Delete(GenerateKey::GetInstance()->MakeKey(20));

	std::pair<GENERATED_KEY, int> output;
	
	hashTable.Find(GenerateKey::GetInstance()->MakeKey(5), output);

	std::cin.get();

}