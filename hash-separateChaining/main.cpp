#include "hash.h"


int main()
{
	int *a = NULL ;
//	new(a) int(2);
	cout << "a" << a << endl;
	hashTable* hTable = initHashTable(10);
	insert("abc", hTable);
	insert("abc", hTable);
	insert("abc", hTable);
	insert("abc", hTable);
	insert("abdbc", hTable);
	insert("abdbc", hTable);
	insert("abdbc", hTable);
	insert("a", hTable);
	insert("ac", hTable);
	insert("ac", hTable);
	insert("a", hTable);
	insert("fac", hTable);
	insert("fac", hTable);
	insert("ffac", hTable);
	insert("fffac", hTable);

	travelHashTable(hTable);
	return 0;
}