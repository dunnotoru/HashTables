#include "HashTableDoubleHash.h"
#include <math.h>

int HashTableDoubleHash::getHash(int value, int i)
{
    return (value + i * getSecondHash(value)) % _size;
}

int HashTableDoubleHash::getSecondHash(int value)
{
    return static_cast<int> (value % (_size - 1) + 1);
}
