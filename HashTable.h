#pragma once
#include "Node.h"

class HashTable
{
protected:
	Node *_table;
	int _size;
	virtual int getHash(int value, int i) = 0;
public:
	HashTable(int size);
	~HashTable();
	void add(int value);
	void remove(int value);
	bool isExists(int value, long& probe_count);
	void print();
};

