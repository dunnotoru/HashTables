#include <iostream>
#include "HashTableExternalHash.h"

int HashTableExternalHash::getHash(int value)
{
	return value % _size;
}


void HashTableExternalHash::add(int value)
{
    int index = getHash(value);
    table[index].push_back(HashNode(value));
}

void HashTableExternalHash::remove(int value)
{
    int index = getHash(value);
    for (auto i = table[index].begin(); i != table[index].end(); i++)
    {
        if (i->key == value) {
            table[index].erase(i);
            return;
        }
    }
}

bool HashTableExternalHash::isExists(int value)
{
    int index = getHash(value);
    for (auto i = table[index].begin(); i != table[index].end(); i++)
    {
        if (i->key == value)
            return true;
    }
    return false;
}

void HashTableExternalHash::print()
{
    std::cout << "индекс элемента хэш-таблицы | значения в этом элементе" << std::endl;
    for (int index = 0; index < table.size(); index++)
    {
        if (table[index].size() == 0) continue;
        std::cout << index << ". ";
        for (auto i = table[index].begin(); i != table[index].end(); i++)
        {
            std::cout << i->key << " ";
        }
        std::cout << std::endl;
    }
}
