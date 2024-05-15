#pragma once
#include "HashTable.h"

class HashTableLinearProbing final : public HashTable {
private:
	int getHash(int value, int i) override;
public:
	HashTableLinearProbing(int size) : HashTable(size) { }
};