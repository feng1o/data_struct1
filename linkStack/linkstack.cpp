#include "linkstack.h"

vlinkstack* CreatLinkStack()
{
	return NULL;//returnһ���պ� ���������creat��ʱ������ͷ�������ǣ���������insert���뷵��һ���ڵ㣬��������˵��һ��ͷ����ȥ�������ſ�ʼ��¼����
}

//�Ͷ�������������ķ����Ƚϣ������pushû�еݹ飬����ʹ���˵ݹ飬������ʱ��Ҳ��null����α�֤�ݹ��ܷ��أ������ģ�ʹ��һ��ָ�룬�������ʵ�֣�
#if 01
pLinkStackNode Push(vlinkstack * vstack, elemType value, int num)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
	pLinkStackNode node = (pLinkStackNode)malloc(sizeof(struct tag_LinkStackNode));
	//pLinkStackNode node = (pLinkStackNode)malloc(sizeof(pLinkStackNode));//���У�\
	ע���������sizeof������

	node->num = num;
	node->value = value;
	node->next = nullptr;
	assert(node != NULL);
	if (stack == NULL)
	{
		if (stack == NULL)
		{
			std::cout << "stackΪ��"<<"  yaru " << node->value<<std::endl;
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
	std::cout << "stack��Ϊ��" <<"yaru " << node->value<< std::endl;
	tmp_node->next = node;
	return stack;
}
#endif

//�Ͷ�������������ķ����Ƚϣ������pushû�еݹ飬����ʹ���˵ݹ飬������ʱ��Ҳ��null����α�֤�ݹ��ܷ��أ������ģ�ʹ��һ��ָ�룬�������ʵ�֣�
#if 01
void vPush(vlinkstack * vstack, elemType value, int num)
{
	pLinkStackNode stack = (pLinkStackNode)vstack;
	pLinkStackNode node = (pLinkStackNode)malloc(sizeof(struct tag_LinkStackNode));
	//pLinkStackNode node = (pLinkStackNode)malloc(sizeof(pLinkStackNode));//���У�\
			ע���������sizeof������

	node->num = num;
	node->value = value;
	node->next = nullptr;
	assert(node != NULL);
	if (stack == NULL)
	{
		if (stack == NULL)
		{
			std::cout << "stackΪ��" << "  yaru " << node->value << std::endl;
			//	std::cout << __LINE__ << "  " << __FILE__ << __FUNCTIONW__ << std::endl;
		}
		stack = node;
		return ;
	}
	while (stack->next != NULL)
	{
		stack  = stack->next;
	}
	std::cout << "stack��Ϊ��" << "yaru " << node->value << std::endl;
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
		TravelLinkStack(stack->next); //�ݹ�ķ�����������Ƿ������ 
	}
}
#if 01
/*
ɾ�����һ���ڵ㣬�����˵����ڶ����㣬Ȼ��ɾ����next���������㣬
������������ѣ�Ȼ��ʼ�Ӻ���ɾ�����Ǵ����
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
	free(head->next);//ɾ�����һ���ڵ㣬�����ڶ����ڵ㻹�ڣ���
	head->next = NULL;//�����ڶ����ڵ㻹��head������head-next�ܺ�������������
	return stack ;
}
#endif

#if 0
/*
�˴��Ǵ���ģ�������ض��ˣ�������û�м�¼ͷ��㣬����pop��ɾ����null
null�Ĳ���������Ľڵ��ˣ�������������ֹ�ڵ���
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
			free(head); //head���������һ���ڵ㣬free����ͷ����ڴ棬������������һ���ڵ�Ϊ�����ǲ�֪������
			head = NULL; //head=null������ָ�����һ���ڵ����һ���ڵ�Ϊnull�ˣ����Դ�����
			return stack;		
}
#endif

#if 0
	/*
	ɾ������ڵ����⣺
	1.ʹ�÷��ؽڵ�϶��ǿ��Եģ�
	2.ʹ�ö���ָ�룬ע�⣬�������ָ�벻��ʹ����ʱ����ȥ��Ȼ���ͷ������ʱ�����ĵ�ַ������һ��������ڵ��ַ
	3.ʹ�÷���Ϊvoid��һ��ָ�룬һ�����޷���ɵ�
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
		//	p1->next = p2->next;//����p2����p1����һ���ڵ����
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
		pLinkStackNode p1 = stack, p2 = NULL; //ǰ��ķ�����������ģ���ǰ��������ˣ�
		while (p1->next != NULL)
		{
			p2 = p1->next;
			p1->next = p2->next;//����p2����p1����һ���ڵ����
			free(p2);
		}
		*/
		free(stack);
		*vstack = NULL;
		//stack = NULL;//���У���������ͨ������ָ�뷵������ֵ������\
		���Ҫ�ı�*vstack,��Ҫ�ö���ָ�룬��Plinkstack **stack = vstack;Ȼ���� *stack=NULL;
		//Ū��Ϊʲô���У�����Ϊstackֻ�ǵ���*vstack��ֵ��ʵ�ε�ĳ���ڵ��ַ�����ֵû��\
		������˵stack��ִ��ĵ�ַһ����������һ���ڵ�ĵ�ַ��stack=NULL,��������\
		*vstack��ֵΪnull�������˵��û�иı�vstack��ֵ��������

		//�������������Ҫ������ı�ʾ������һ��Ҫ��ס��Ҫ�ı�ͷ������ͬʱ���ܶϣ���������
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
		p1->next = p2->next;//����p2����p1����һ���ڵ����
		free(p2);
	}
	free(stack);
	stack = NULL;
	return ;
}
#endif