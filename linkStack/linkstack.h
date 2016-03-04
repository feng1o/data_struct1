#include "iostream"
#include "string"
#include "memory"
#include "cassert"
#include "iostream"

typedef int  elemType;
typedef struct tag_LinkStackNode linkStackNode;
typedef linkStackNode*  pLinkStackNode;
typedef void  vlinkstack;

struct tag_LinkStackNode {
	int num;
	elemType value;
	linkStackNode * next;
};


vlinkstack* CreatLinkStack();

void  vPush(vlinkstack *vstack, elemType value, int num);
pLinkStackNode  Push(vlinkstack  *vstack, elemType value, int num);
void * Pop(vlinkstack *vstack, pLinkStackNode node);
//pLinkStackNode FreeLinkStack(vlinkstack * vstack);
//void FreeLinkStack(vlinkstack* vstack);
void FreeLinkStack(pLinkStackNode* vstack);
void TravelLinkStack(vlinkstack *vstack);
