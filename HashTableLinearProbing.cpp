#include "HashTableLinearProbing.h"


int HashTableLinearProbing::getHash(int value, int i) {
	return (value + i) % _size;
}
