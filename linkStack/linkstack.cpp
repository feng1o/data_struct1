#include "linkstack.h"

vlinkstack* CreatLinkStack()
{
	return NULL;//return一个空和 链表里面的creat的时候分配表头的区别是，这里后面的insert必须返回一个节点，甚至可以说是一个头结点回去，后续才开始记录下来
}

//和二叉搜索树里面的方法比较，这里的push没有递归，那里使用了递归，创建的时候也是null，如何保证递归能返回？？？的，使用一级指针，二级如何实现？
#if 01
pLinkStackNode Push(vlinkstack * vstack, elemType value, int num)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
	pLinkStackNode node = (pLinkStackNode)malloc(sizeof(struct tag_LinkStackNode));
	//pLinkStackNode node = (pLinkStackNode)malloc(sizeof(pLinkStackNode));//不行，\
	注意这个长度sizeof的问题

	node->num = num;
	node->value = value;
	node->next = nullptr;
	assert(node != NULL);
	if (stack == NULL)
	{
		if (stack == NULL)
		{
			std::cout << "stack为空"<<"  yaru " << node->value<<std::endl;
		//	std::cout << __LINE__ << "  " << __FILE__ << __FUNCTIONW__ << std::endl;
		}
		stack = node;
		return stack;
	}
	pLinkStackNode tmp_node = stack;
	while (tmp_node->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	std::cout << "stack不为空" <<"yaru " << node->value<< std::endl;
	tmp_node->next = node;
	return stack;
}
#endif

//和二叉搜索树里面的方法比较，这里的push没有递归，那里使用了递归，创建的时候也是null，如何保证递归能返回？？？的，使用一级指针，二级如何实现？
#if 01
void vPush(vlinkstack * vstack, elemType value, int num)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
	pLinkStackNode node = (pLinkStackNode)malloc(sizeof(struct tag_LinkStackNode));
	//pLinkStackNode node = (pLinkStackNode)malloc(sizeof(pLinkStackNode));//不行，\
			注意这个长度sizeof的问题

	node->num = num;
	node->value = value;
	node->next = nullptr;
	assert(node != NULL);
	if (stack == NULL)
	{
		if (stack == NULL)
		{
			std::cout << "stack为空" << "  yaru " << node->value << std::endl;
			//	std::cout << __LINE__ << "  " << __FILE__ << __FUNCTIONW__ << std::endl;
		}
		stack = node;
		return ;
	}
	while (stack->next != NULL)
	{
		stack  = stack->next;
	}
	std::cout << "stack不为空" << "yaru " << node->value << std::endl;
	stack->next = node;
	return ;
}

#endif 
void TravelLinkStack(vlinkstack *vstack)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
//	assert(NULL != stack);
	if (NULL == stack)
	{
		return ;
	}
	else
	{
		std::cout << " stack.num" << stack->num << " stack.value " << stack->value << std::endl;
		TravelLinkStack(stack->next); //递归的方法，，这个是非逆序的 
	}
}
#if 01
/*
删除最后一个节点，保留了倒数第二个点，然后删除其next，理解这个点，
链表不能让其断裂，然后开始从后面删除那是错误的
*/
void* Pop(vlinkstack * vstack, pLinkStackNode node)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
	pLinkStackNode head = (pLinkStackNode)malloc(sizeof(linkStackNode));
	 head = stack;
	if (NULL == stack)
	{
		return stack;
	}
	else if (NULL == stack->next)
	{
		node->value = stack->value;
		node->num = stack->value;
		free(stack);
		stack = NULL;
		return stack;
	}
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	node->num = head->next->num;
	node->value = head->next->value;
	free(head->next);//删除最后一个节点，倒数第二个节点还在，，
	head->next = NULL;//倒数第二个节点还在head，所以head-next能和链表连接起来
	return stack ;
}
#endif

#if 0
/*
此处是错误的，把链表截断了，但是又没有记录头结点，后面pop后删除，null
null的并不是链表的节点了，等与链表无终止节点了
*/
	void* Pop(vlinkstack * vstack, pLinkStackNode node)
	{
		pLinkStackNode stack = (pLinkStackNode)vstack;
		pLinkStackNode head = stack;
		if (NULL == stack)
		{
			return stack;
		}
		else if (NULL == stack->next)
		{
			node->value = stack->value;
			node->num = stack->value;
			free(stack);
			stack = NULL;
			return stack;
		}
		while (head->next != NULL)
		{
			head = head->next;
		}		
			node->num = head->num;
			node->value = head->value;
			free(head); //head是链表最后一个节点，free后就释放了内存，此事链表的最后一个节点为多少是不知道的了
			head = NULL; //head=null并不是指向最后一个节点的下一个节点为null了，所以错误了
			return stack;		
}
#endif

#if 0
	/*
	删除链表节点问题：
	1.使用返回节点肯定是可以的；
	2.使用二级指针，注意，这个二级指针不可使用临时变量去等然后释放这个临时变量的地址，并不一定是链表节点地址
	3.使用返回为void的一级指针，一定是无法完成的
	*/
	pLinkStackNode FreeLinkStack(vlinkstack * vstack)
	{
		pLinkStackNode stack = (pLinkStackNode)vstack;
		if (NULL == stack)
		{
			return stack;
		}
		pLinkStackNode p1 = stack->next, p2 = NULL;
		while (p1->next != NULL)
		{
			p2 = p1->next;
			free(p1);
			p1 = NULL;
			p1 = p2;
		}
		free(p2);
		p2 = NULL;
		//pLinkStackNode p1 = stack, p2 = NULL;
		//while (p1->next != NULL)
		//{
		//	p2 = p1->next;
		//	p1->next = p2->next;//跳过p2，，p1的下一个节点后移
		//	free(p2);
		//}
		free(stack);
		stack = NULL;
		return stack;
	}
#endif
#if 01
void FreeLinkStack(pLinkStackNode * vstack)
	{
		if (NULL == *vstack)
		{
			return ;
		}
		pLinkStackNode stack = *vstack;
		pLinkStackNode p1 = stack->next, p2 = NULL;
		while (p1->next != NULL)
		{
		p2 = p1->next;
		free(p1);
		p1 = NULL;
		p1 = p2;
		}
		free(p2);
		p2 = NULL;
		/*
		pLinkStackNode p1 = stack, p2 = NULL; //前后的方法是有区别的，，前面链表断了，
		while (p1->next != NULL)
		{
			p2 = p1->next;
			p1->next = p2->next;//跳过p2，，p1的下一个节点后移
			free(p2);
		}
		*/
		free(stack);
		*vstack = NULL;
		//stack = NULL;//不行，，并不能通过二级指针返回她的值？？？\
		如果要改变*vstack,就要用二级指针，让Plinkstack **stack = vstack;然后让 *stack=NULL;
		//弄懂为什么不行！！因为stack只是等于*vstack的值，实参的某个节点地址是这个值没错，\
		并不是说stack所执向的地址一定是链表下一个节点的地址，stack=NULL,并不能让\
		*vstack的值为null，这就是说并没有改变vstack的值，，，，

		//理解这个问题很重要，链表的表示过程中一定要记住不要改变头，但是同时不能断，让其连上
		return ;
	}

#endif

#if 0
void FreeLinkStack(vlinkstack* vstack)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
	if (NULL == stack)
	{
		return ;
	}
	//pLinkStackNode p1 = stack->next, p2 = NULL;
	//while (p1->next != NULL)
	//{
	//	p2 = p1->next;
	//	free(p1);
	//	p1 = NULL;
	//	p1 = p2;
	//}
	//free(p2);
	//p2 = NULL;
	pLinkStackNode p1 = stack, p2 = NULL;
	while (p1->next != NULL)
	{
		p2 = p1->next;
		p1->next = p2->next;//跳过p2，，p1的下一个节点后移
		free(p2);
	}
	free(stack);
	stack = NULL;
	return ;
}
#endif