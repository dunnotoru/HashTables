#pragma once
#include "HashTable.h"

class HashTableDoubleHash final : public HashTable {
private:
	int getHash(int value, int i) override;
	int getSecondHash(int value);
public:
	HashTableDoubleHash(int _size) : HashTable(_size) { }
};