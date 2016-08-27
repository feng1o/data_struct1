//http://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html
#define  _CRT_SECURE_NO_WARNINGS

/*二叉树的遍历* 2011.8.25*/
#include <iostream>
#include<string.h>
#include<stack> 
using namespace std;

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BinTree;

typedef struct node1
{
	BinTree *btnode;
	bool isFirst;
}BTNode;


void creatBinTree(char *s, BinTree *&root)  //创建二叉树，s为形如A(B,C(D,E))形式的字符串 
{
	int i;
	bool isRight = false;
	stack<BinTree*> s1;          //存放结点 
	stack<char> s2;              //存放分隔符
	BinTree *p, *temp;
	root->data = s[0];
	root->lchild = NULL;
	root->rchild = NULL;
	s1.push(root);
	i = 1;
	while (i < strlen(s))
	{
		if (s[i] == '(')
		{
			s2.push(s[i]);
			isRight = false;
		}
		else if (s[i] == ',')
		{
			isRight = true;
		}
		else if (s[i] == ')')
		{
			s1.pop();
			s2.pop();
		}
		else if (isalpha(s[i]))
		{
			p = (BinTree *)malloc(sizeof(BinTree));
			p->data = s[i];
			p->lchild = NULL;
			p->rchild = NULL;
			temp = s1.top();
			if (isRight == true)
			{
				temp->rchild = p;
				cout << temp->data << "的右孩子是" << s[i] << endl;
			}
			else
			{
				temp->lchild = p;
				cout << temp->data << "的左孩子是" << s[i] << endl;
			}
			if (s[i + 1] == '(')
				s1.push(p);
		}
		i++;
	}
}

void display(BinTree *root)        //显示树形结构 
{
	if (root != NULL)
	{
		cout << root->data;
		if (root->lchild != NULL)
		{
			cout << '(';
			display(root->lchild);
		}
		if (root->rchild != NULL)
		{
			cout << ',';
			display(root->rchild);
			cout << ')';
		}
	}
}

void preOrder1(BinTree *root)     //递归前序遍历 
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preOrder1(root->lchild);
		preOrder1(root->rchild);
	}
}

void inOrder1(BinTree *root)      //递归中序遍历
{
	if (root != NULL)
	{
		inOrder1(root->lchild);
		cout << root->data << " ";
		inOrder1(root->rchild);
	}
}

void postOrder1(BinTree *root)    //递归后序遍历
{
	if (root != NULL)
	{
		postOrder1(root->lchild);
		postOrder1(root->rchild);
		cout << root->data << " ";
	}
}

void preOrder2(BinTree *root)     //非递归前序遍历 
{
	stack<BinTree*> s;
	BinTree *p = root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void inOrder2(BinTree *root)      //非递归中序遍历
{
	stack<BinTree*> s;
	BinTree *p = root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rchild;
		}
	}
}

void postOrder2(BinTree *root)    //非递归后序遍历
{
	stack<BTNode*> s;
	BinTree *p = root;
	BTNode *temp;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点 
		{
			BTNode *btn = (BTNode *)malloc(sizeof(BTNode));
			btn->btnode = p;
			btn->isFirst = true;
			s.push(btn);
			p = p->lchild;
		}
		if (!s.empty())
		{
			temp = s.top();
			s.pop();
			if (temp->isFirst == true)     //表示是第一次出现在栈顶 
			{
				temp->isFirst = false;
				s.push(temp);
				p = temp->btnode->rchild;
			}
			else                        //第二次出现在栈顶 
			{
				cout << temp->btnode->data << " ";
				p = NULL;
			}
		}
	}
}

void postOrder3(BinTree *root)     //非递归后序遍历
{
	stack<BinTree*> s;
	BinTree *cur;                      //当前结点 
	BinTree *pre = NULL;                 //前一次访问的结点 
	s.push(root);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->lchild == NULL&&cur->rchild == NULL) ||
			(pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != NULL)
				s.push(cur->rchild);
			if (cur->lchild != NULL)
				s.push(cur->lchild);
		}
	}
}
#define x

int main(int argc, char *argv[])
{
	char s[100];
	while (scanf("%s", s) == 1)
	{
		BinTree *root = (BinTree *)malloc(sizeof(BinTree));
		creatBinTree(s, root);
		display(root);
		cout << endl;
		preOrder2(root);
		cout << endl;
		inOrder2(root);
		cout << endl;
		postOrder2(root);
		cout << endl;
		postOrder3(root);
		cout << endl;
	}
	return 0;
}

/*
http://blog.csdn.net/ns_code/article/details/12977901
void pre_traverse(BTree pTree)
{
	PSTACK stack = create_stack();  //创建一个空栈  
	BTree node_pop;                 //用来保存出栈节点  
	BTree pCur = pTree;             //定义用来指向当前访问的节点的指针  

	//直到当前节点pCur为NULL且栈空时，循环结束  
	while (pCur || !is_empty(stack))
	{
		//从根节点开始，输出当前节点，并将其入栈，  
		//同时置其左孩子为当前节点，直至其没有左孩子，及当前节点为NULL  
		printf("%c ", pCur->data);
		push_stack(stack, pCur);
		pCur = pCur->pLchild;
		//如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，  
		//同时置其右孩子为当前节点,循环判断，直至pCur不为空  
		while (!pCur && !is_empty(stack))
		{
			pCur = getTop(stack);
			pop_stack(stack, &node_pop);
			pCur = pCur->pRchild;
		}
	}
}
http://blog.csdn.net/ns_code/article/details/12977901
void in_traverse(BTree pTree)
{
	PSTACK stack = create_stack();  //创建一个空栈  
	BTree node_pop;                 //用来保存出栈节点  
	BTree pCur = pTree;             //定义指向当前访问的节点的指针  

	//直到当前节点pCur为NULL且栈空时，循环结束  
	while (pCur || !is_empty(stack))
	{
		if (pCur->pLchild)
		{
			//如果pCur的左孩子不为空，则将其入栈，并置其左孩子为当前节点  
			push_stack(stack, pCur);
			pCur = pCur->pLchild;
		}
		else
		{
			//如果pCur的左孩子为空，则输出pCur节点，并将其右孩子设为当前节点，看其是否为空  
			printf("%c ", pCur->data);
			pCur = pCur->pRchild;
			//如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，  
			//同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空  
			while (!pCur && !is_empty(stack))
			{
				pCur = getTop(stack);
				printf("%c ", pCur->data);
				pop_stack(stack, &node_pop);
				pCur = pCur->pRchild;
			}
		}
	}
}



http://blog.csdn.net/ns_code/article/details/12977901
void in_traverse(BTree pTree)
{
	PSTACK stack = create_stack();  //创建一个空栈  
	BTree node_pop;                 //用来保存出栈节点  
	BTree pCur = pTree;             //定义指向当前访问的节点的指针  

	//直到当前节点pCur为NULL且栈空时，循环结束  
	while (pCur || !is_empty(stack))
	{
		if (pCur->pLchild)
		{
			//如果pCur的左孩子不为空，则将其入栈，并置其左孩子为当前节点  
			push_stack(stack, pCur);
			pCur = pCur->pLchild;
		}
		else
		{
			//如果pCur的左孩子为空，则输出pCur节点，并将其右孩子设为当前节点，看其是否为空  
			printf("%c ", pCur->data);
			pCur = pCur->pRchild;
			//如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，  
			//同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空  
			while (!pCur && !is_empty(stack))
			{
				pCur = getTop(stack);
				printf("%c ", pCur->data);
				pop_stack(stack, &node_pop);
				pCur = pCur->pRchild;
			}
		}
	}
}
*/