#include "hash.h"

hashTable* initHashTable(int size)
{
	if (size < def_MinSize)
		cerr << "to small \n";
	hashTable* hTable = new hashTable;
	def_MyAssert(hTable);
	hTable->size = size;
	hTable->ppTableList = new pListNode[size]; //这里使用的是地址
	def_MyAssert(hTable->ppTableList);

	for (int i = 0; i < size; i++)
	{
		hTable->ppTableList[i] = new ListNode;
		def_MyAssert(hTable->ppTableList[i]);
		hTable->ppTableList[i]->next = nullptr;
	}
	return hTable;
}

void travelHashTable(hashTable* hTable)
{
	int size = hTable->size;
	for (int i = 0; i < size; ++i)
	{
		pListNode tmp = hTable->ppTableList[i]->next;
		cout << "  结点" << i << "分离链表值:";
		while (tmp)
		{
			 cout << std::left << setw(10) << tmp->element;
			tmp = tmp->next;
		}
		cout << endl;
	}
}

void insert(elementType key, hashTable* hTable)
{
	def_MyAssert(hTable);
	int hashKey = myHash(key, hTable->size);
	ListNode *node = new ListNode{ key, nullptr };
	node->next = hTable->ppTableList[hashKey]->next;
	hTable->ppTableList[hashKey]->next = node;
}

int myHash(elementType key, int size)
{
	unsigned int hashKye = 0;
	while (*key++ != '\0')
	{
		hashKye += *key++;
	}
	return hashKye % size;
}
