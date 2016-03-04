#include "linkstack.h"
#include "iostream"
#define  _RETURN_HEAD
#define  _VOID_

int main()
{
	std::cout << sizeof(struct tag_LinkStackNode) << std::endl;
	std::cout << sizeof(linkStackNode) << std::endl; //等价于结构体的长度
	std::cout << sizeof(pLinkStackNode) << std::endl;//只是一个指针的长度

#ifdef _RETURN_HEAD1
	pLinkStackNode stack = nullptr; //使用push版本返回链表头结点的push
	stack = (pLinkStackNode)CreatLinkStack();

	Push(stack, 1, 1); //必不可少，至少有一个，这里二级指针也是不行的，头结点是不能改变的，否则头结点在插入后不停后移如何找到呢？
	stack = Push(stack, 2, 2);//stack放在哪里从哪里开始计，从2开始只有23压入栈了,
	Push(stack, 3, 3);//stack 从哪里开始返回值，就从哪里记录，因为后面的修改只是改了这个结构的值，不是结构本身地址
	            //和二叉搜索树里面的方法比较，这里的push没有递归，那里使用了递归，创建的时候也是null，如何保证递归能返回？？？的，使用一级指针，二级如何实现？
#endif 

#ifdef _VOID_
	//使用void  Push(vlinkstack *vstack, elemType value, int num);，此版本必须保证表头存在的\
	和链表创建区别在与creatLinkStack（）上，这个是返回的是一个null，表头还要push的时候创建，链表就不是
	pLinkStackNode stack = (pLinkStackNode)malloc(sizeof(pLinkStackNode));
	stack->num = 0;
	stack->value = 0;
	stack->next = NULL;
	vPush(stack, 1, 1);
	vPush(stack, 2, 2);
	vPush(stack, 3, 3);
#endif


	pLinkStackNode substack = stack; //打印下压入栈的地址为多少，，，
	do
	{
		std::cout << "压栈地址" << substack << std::endl;
		substack = substack->next;
	} while (substack != NULL);
	std::cout << "压栈地址" << substack << std::endl;

	//FreeLinkStack(stack);
	//FreeLinkStack(&stack);
	//stack = FreeLinkStack(stack);//清空栈，free all必须保证一个能操作指针节点，二级指针或者返回值必须的
	std::cout  << std::endl;
	std::cout << std::endl;
	std::cout << stack << std::endl;
	try{
		//while (nullptr != stack)
		{
			pLinkStackNode node = (pLinkStackNode)malloc(sizeof(linkStackNode));
			stack = (pLinkStackNode)Pop(stack, node);
			stack ?std::cout << "pop num= " << node->num << "  pop value=" << node->value << std::endl:std::cout<<"空栈\n\n";	
			TravelLinkStack(stack);
		}
	}
	catch (const char *str)
	{
		std::cout <<"铺货到异常，，，"<< str << std::endl;
		std::cout << __DATE__ << std::endl;
	}
	std::cout << "\n遍历一遍原始栈为 travel........\n";
	TravelLinkStack(stack);
	//std::cin.get();
	return 0;
}
