#include "linkList.h"
#include "iostream"



int main(int argv, char **argc)
{
	pLinkList list = (pLinkList)CreatLinkList();
	int a1(1),a2(2),a3(3),a4(4);
	std::cout << "input 4 number ...\n";
	std::cin.clear();
	//std::cin >> a1 >> a2 >> a3 >> a4;
	InsertNodeLinkList(list, 9,a1);
	InsertNodeLinkList(list, 9, a2);
	InsertNodeLinkList(list, 2, a3);
	InsertNodeLinkList(list, 2, a4);
	InsertNodeLinkList(list, 2, 5);
	InsertNodeLinkList(list, 9, 6);

	//LinkListNode *dLinkNode = DeleteNodeLinkList(list, 1); //测试删除
	//std::cout << std::endl << "delete-1:" << dLinkNode->value << std::endl << std::endl;
	TravelLinkList(list);
	std::cout << "\n sort后的... ------" << std::endl;
	SortLinkList(list);
	TravelLinkList(list);

	std::cout << "\n 二级指针逆序后的链表 ------" << std::endl;
	PReverseLink((void**)&list);
	TravelLinkList(list);
	
	std::cout << "\n逆序后的链表 ------" << std::endl;
	pLinkList rlist = (pLinkList)ReverseLink(list);
	TravelLinkList(rlist);

	std::cout<<"\\\nlist length is: " << LengthLinkList(list) << std::endl;

	std::cout << "\n递归实现逆序打印链表 ------" << std::endl;
	PrintListReversingly(&rlist->header);//递归打印
	return 0;
}