#if !defined(_HASH_H)
#define  _HASH_H

#include "iostream"
#include "memory"
#include "cassert"
#include "iomanip"
#include "new"

#define  def_MyAssert(x) if(!(x)) {cout << "error" << __FILE__ << __LINE__ << __FUNCDNAME__ << __TIME__ <<endl;\
						abort();}
#define  def_MinSize 10
using namespace std;
#define  elementType   char* 
typedef struct str_hashTable hashTable;
//typedef ListNode *pListNode; //is error£¬£¬before declare£¬£¬

typedef struct str_ListNode {
	elementType  element;
	struct str_ListNode * next;
}ListNode;
typedef ListNode* pListNode;

struct str_hashTable{
	int size;
	pListNode* ppTableList;   //¶þ¼¶Ö¸Õë£¬£¬£¬
};

hashTable* initHashTable(int size);
pListNode  find(elementType element, hashTable* hTable);
void insert(elementType key, hashTable* hTable);
void travelHashTable(hashTable* hTable);

int myHash(elementType key, int size);
#endif