/*
*file£ºcircle list
*time:
*autho:lf
*/

#ifndef _H_CIRCLE_BILIST_H
#define _H_CIRCLE_BILIST_H

#include "iostream"
#include "string"
#include "memory"

using namespace std;
typedef int elementType;
typedef struct circlList   cListNode;
typedef cListNode* pCListNode;
struct circlList{
	elementType  val; //value
	pCListNode  next;
	pCListNode forward;
};

bool init(pCListNode* clist){
	*clist = (pCListNode)malloc(sizeof(cListNode));
	if (*clist == nullptr)
	{
		return false;
	}
	else{
		(*clist)->next = nullptr;
		(*clist)->forward = nullptr;
		(*clist)->val = 0;
		//return true;
		pCListNode front = *clist;
		for (int i = 0; i < 26; ++i)
		{
			pCListNode node = (pCListNode)malloc(sizeof(cListNode));
			node->next = node->forward = nullptr;
			if (node == nullptr)
			{
				return false;
			}
			node->val = 'A' + i;
			front->next = node;
			//front->forward = node;
			node->forward = front;
			front = node;
		}
		(*clist)->forward = front;
		front->next = (*clist);
	}
	return true;
	
}




#endif