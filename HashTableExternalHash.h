#pragma once
#include <vector>
#include <list>


struct HashNode {
    int key;
    HashNode(int k) : key(k) {}
};


class HashTableExternalHash {
private:
    std::vector<std::list<HashNode>> table;
    int _size;
    int getHash(int value);
public:
    HashTableExternalHash(int size) : _size(size), table(size) {}
    void add(int value);
    void remove(int value);
    bool isExists(int value);
    void print();
};