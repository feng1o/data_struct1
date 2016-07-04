
//http://www.cnblogs.com/pacoson/p/5142330.html
//
#if 0
#include "leftheap.h" 

// swap the left and the right in priority queue.
void swap(PriorityQueue h1)
{
	PriorityQueue temp;

	temp = h1->left;
	h1->left = h1->right;
	h1->right = temp;
}

// analog print directories and files name in the BinaryTree, which involves postorder traversal. 
void printPreorder(int depth, TreeNode root)
{
	int i;

	if (root)
	{
		for (i = 0; i < depth; i++)
			printf("    ");
		printf("%d\n", root->value);
		printPreorder(depth + 1, root->left);
		// Attention: there's difference between traversing binary tree and common tree.
		printPreorder(depth + 1, root->right);
	}
	else
	{
		for (i = 0; i < depth; i++)
			printf("    ");
		printf("NULL\n");
	}
}

// insert an element with value into the priority queue.
PriorityQueue insert(ElementType value, PriorityQueue pq)
{
	TreeNode node;

	node = (TreeNode)malloc(sizeof(struct leftheap));
	if (!node)
	{
		Error("failed inserting, for out of space !");
		return pq;
	}
	node->left = NULL;
	node->right = NULL;
	node->nullPathLen = 0;
	node->value = value;

	if (pq == NULL) // means that just only creating a node with value.
	{
		return node;
	}
	else
	{
		return merge(node, pq);
	}
}

// return the minimal between a and b.
int minimal(int a, int b)
{
	return a > b ? b : a;
}

// merge the priority queue h1 and h2.
PriorityQueue merge(PriorityQueue h1, PriorityQueue h2)
{
	if (h1 == NULL)
	{
		return h2;
	}
	else if (h2 == NULL)
	{
		return h1;
	}
	if (h1->value > h2->value)
	{
		return innerMerge(h2, h1);
	}
	else
	{
		return innerMerge(h1, h2);
	}
}

// merge the priority queue h1 and h2.
PriorityQueue innerMerge(PriorityQueue h1, PriorityQueue h2)
{
	if (h1->left == NULL)
	{
		h1->left = h2;
	}
	else
	{
		h1->right = merge(h1->right, h2);

	}
	// update the null path length
	if (h1->right == NULL)
	{
		h1->nullPathLen = 0;
	}
	else
	{
		h1->nullPathLen = minimal(h1->left->nullPathLen, h1->right->nullPathLen) + 1;
		// exchange the left and the right
		if (h1->left->nullPathLen < h1->right->nullPathLen)
		{
			swap(h1);
		}
	}
	return h1;
}

// delete the minimal element in the priority queue.
PriorityQueue deleteMin(PriorityQueue h1)
{
	PriorityQueue left;
	PriorityQueue right;

	if (!h1)
	{
		Error("failed deleteMin, for the root doesn't point to any position!");
		return NULL;
	}
	left = h1->left;
	right = h1->right;
	free(h1);

	return merge(left, right);
}

int main2()
{
	PriorityQueue h1;
	PriorityQueue h2;
	int data[] = { 21, 10, 23, 14, 3, 26, 17, 8 };
	int data2[] = { 18, 12, 33, 24, 6, 37, 7, 18 };
	int i;

	h1 = insert(data[0], NULL);
	for (i = 1; i < 8; i++)
	{
		h1 = insert(data[i], h1);
	}
	printf("\n=== after the leftist heap h1 is merged===\n");
	printPreorder(1, h1);

	h2 = insert(data2[0], NULL);
	for (i = 1; i < 8; i++)
	{
		h2 = insert(data2[i], h2);
	}
	printf("\n=== after the leftist heap h2 is merged===\n");
	printPreorder(1, h2);

	h1 = merge(h1, h2);
	printf("\n=== after both h1 and h2 are merged===\n");
	printPreorder(1, h1);

	h1 = deleteMin(h1);
	printf("\n=== after executing deleteMin operation ===\n");
	printPreorder(1, h1);

	return  0;
}
#endif