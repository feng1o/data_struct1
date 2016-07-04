#include "leftheap.h"
PriorityQueue merge(PriorityQueue h1, PriorityQueue h2){
	if (h1== nullptr)
	{
		return h2;
	}
	if (h2 == nullptr)
	{
		return h1;
	}
	if (h1->value <= h2->value)
	{
		innerMerge(h1, h2);
	}
	else{
		innerMerge(h2, h1);
	}
}
void swap(PriorityQueue h1){
	PriorityQueue temp;

	temp = h1->left;
	h1->left = h1->right;
	h1->right = temp;
}


PriorityQueue innerMerge(PriorityQueue h1, PriorityQueue h2){
	if (h1->left == nullptr)
	{
		h1->left = h2;
	//	return h1;
	}
	else
	{
		h1->right = merge(h1->right, h2);
		if (h1->left->nullPathLen > h1->right->nullPathLen)
		{
			swap(h1);
		}
		h1->nullPathLen = h1->right->nullPathLen + 1;
	}
	return h1;
}
PriorityQueue insert(ElementType value, PriorityQueue pq){
	TreeNode node = new ("new传递一个参数") leftheap; //不可传递其他的了，必须是这个leftheap，当做类了
	if (!node)
	{
		cout << "空 new失败。。。。\n";
	}
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;
	if (pq)
		merge(pq, node);
	else{
		pq = node;
		return pq;
	}
}


void printPreorder(int depth, TreeNode root){
	if (!root)
		return;
	for (int i = 0; i < depth; ++i)
	{
		cout << " ";
	}
	cout << root->value << endl; //为什么有换行
	printPreorder(depth + 1, root->left);
	printPreorder(depth + 1, root->right);
	for (int i = 0; i < depth; ++i)
	{
		cout << " ";
	}
	cout << "null" << endl;
}


int main(){
	PriorityQueue h1 ;  
	PriorityQueue h2 ;
	int a1[] = { 1, 2, 5, 6, 32, 64, 7, 23, 53 };
	int a2[] = { 23, 34, 6, 8, 23, 35, 5, 7, 123, 2 };
	h1 = insert(a1[0], NULL);
	for (int i = 1; i < sizeof(a1) / sizeof(a1[0]); ++i)
	{
		insert(a1[i], h1);
	}

	cout << "......print a1...init....." << endl;
	printPreorder(1, h1);


	h2 = insert(a2[0], NULL);
	for (int i = 1; i < sizeof(a2) / sizeof(a2[0]); ++i)
	{
		insert(a2[i], h2);
	}
	cout << "......print a2...init....." << endl;
	printPreorder(1, h2);
	return 0;
}