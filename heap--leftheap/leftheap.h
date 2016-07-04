#include "iostream"
#include "string"

using namespace std;

#define  Error(str) {perror((str));}
#define  ElementType  int 
typedef struct leftheap * PriorityQueue;
typedef PriorityQueue TreeNode;

struct leftheap{
	int value;
	PriorityQueue  left,  right;
	int nullPathLen;
	//TreeNode& operator new(int value){
	void* operator new(size_t size, const string& str) {
		cout << "my new..." << str << endl;
		return malloc(size);
	}
};
void swap(PriorityQueue h1);
void printPreorder(int depth, TreeNode root);
PriorityQueue insert(ElementType value, PriorityQueue pq);
int minimal(int a, int b);
PriorityQueue merge(PriorityQueue h1, PriorityQueue h2);
PriorityQueue innerMerge(PriorityQueue h1, PriorityQueue h2);
PriorityQueue deleteMin(PriorityQueue h1);