#include "linkstack.h"
#include "iostream"
#define  _RETURN_HEAD
#define  _VOID_

int main()
{
	std::cout << sizeof(struct tag_LinkStackNode) << std::endl;
	std::cout << sizeof(linkStackNode) << std::endl; //�ȼ��ڽṹ��ĳ���
	std::cout << sizeof(pLinkStackNode) << std::endl;//ֻ��һ��ָ��ĳ���

#ifdef _RETURN_HEAD1
	pLinkStackNode stack = nullptr; //ʹ��push�汾��������ͷ����push
	stack = (pLinkStackNode)CreatLinkStack();

	Push(stack, 1, 1); //�ز����٣�������һ�����������ָ��Ҳ�ǲ��еģ�ͷ����ǲ��ܸı�ģ�����ͷ����ڲ����ͣ��������ҵ��أ�
	stack = Push(stack, 2, 2);//stack������������￪ʼ�ƣ���2��ʼֻ��23ѹ��ջ��,
	Push(stack, 3, 3);//stack �����￪ʼ����ֵ���ʹ������¼����Ϊ������޸�ֻ�Ǹ�������ṹ��ֵ�����ǽṹ�����ַ
	            //�Ͷ�������������ķ����Ƚϣ������pushû�еݹ飬����ʹ���˵ݹ飬������ʱ��Ҳ��null����α�֤�ݹ��ܷ��أ������ģ�ʹ��һ��ָ�룬�������ʵ�֣�
#endif 

#ifdef _VOID_
	//ʹ��void  Push(vlinkstack *vstack, elemType value, int num);���˰汾���뱣֤��ͷ���ڵ�\
	����������������creatLinkStack�����ϣ�����Ƿ��ص���һ��null����ͷ��Ҫpush��ʱ�򴴽�������Ͳ���
	pLinkStackNode stack = (pLinkStackNode)malloc(sizeof(pLinkStackNode));
	stack->num = 0;
	stack->value = 0;
	stack->next = NULL;
	vPush(stack, 1, 1);
	vPush(stack, 2, 2);
	vPush(stack, 3, 3);
#endif


	pLinkStackNode substack = stack; //��ӡ��ѹ��ջ�ĵ�ַΪ���٣�����
	do
	{
		std::cout << "ѹջ��ַ" << substack << std::endl;
		substack = substack->next;
	} while (substack != NULL);
	std::cout << "ѹջ��ַ" << substack << std::endl;

	//FreeLinkStack(stack);
	//FreeLinkStack(&stack);
	//stack = FreeLinkStack(stack);//���ջ��free all���뱣֤һ���ܲ���ָ��ڵ㣬����ָ����߷���ֵ�����
	std::cout  << std::endl;
	std::cout << std::endl;
	std::cout << stack << std::endl;
	try{
		//while (nullptr != stack)
		{
			pLinkStackNode node = (pLinkStackNode)malloc(sizeof(linkStackNode));
			stack = (pLinkStackNode)Pop(stack, node);
			stack ?std::cout << "pop num= " << node->num << "  pop value=" << node->value << std::endl:std::cout<<"��ջ\n\n";	
			TravelLinkStack(stack);
		}
	}
	catch (const char *str)
	{
		std::cout <<"�̻����쳣������"<< str << std::endl;
		std::cout << __DATE__ << std::endl;
	}
	std::cout << "\n����һ��ԭʼջΪ travel........\n";
	TravelLinkStack(stack);
	//std::cin.get();
	return 0;
}
