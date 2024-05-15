#include <iostream>
#include "HashTableLinearProbing.h"
#include "HashTableDoubleHash.h"
#include "HashTableExternalHash.h"

int main()
{
	const int size = 9999;
	HashTableExternalHash table(size);


	for (int i = 0; i < size; i++) table.add(i*i);

	//table.isExists
	//table.print();

	std::cout << table.isExists(996004);

	std::cout << std::endl;


}