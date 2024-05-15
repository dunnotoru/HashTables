#include <unordered_map>
#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int size)
{
	_size = size;
	_table = new Node[size];
}

HashTable::~HashTable()
{
	delete[] _table;
}

void HashTable::add(int value)
{
	for (size_t i = 0; i < _size; i++)
	{
		int hash = getHash(value, i);
		if (_table[hash].isEmpty == true) {
			_table[hash].SetValue(value);
			return;
		}
	}
}


void HashTable::remove(int value)
{
	int emptyPlace = -1;
	size_t i = 0;
	for (i ; i < _size; i++)
	{
		int hash = getHash(value, i);
		if (_table[hash].value == value && _table[hash].isEmpty == false) {
			_table[hash].Remove();
			emptyPlace = hash;
			break;
		}
	}

	i++;
	for (i; i < _size; i++)
	{
		int currentHash = getHash(value, i);
		if (_table[currentHash].isEmpty == true)
			return;

		int actualValue = _table[currentHash].value;
		int actualHash = getHash(actualValue, 0);
		if (emptyPlace != currentHash && _table[emptyPlace].isEmpty == true
			&& actualHash != currentHash) {
			_table[currentHash].Remove();
			add(actualValue);
			emptyPlace = currentHash;
		}
	}
}

bool HashTable::isExists(int value)
{
	for (size_t i = 0; i < _size; i++)
	{
		int hash = getHash(value, i);
		if (_table[hash].isEmpty == true) {	
			return false;
		}
		if (_table[hash].value == value) {
			return true;
		}
	}
	return false;
}

void HashTable::print()
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_table[i].isEmpty == false) {
			std::cout << i << ". " << _table[i].value << std::endl;
		}
	}
}
