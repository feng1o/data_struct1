# if 0
#include "seqlist_pointer.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h" //system pause needs it 


/*
creat a struct
*/

/*
creat a list
*/
SeqList* Creat_list(int capacity) //这里不可以是 List* Creat_list(int capacity) 声明中是！！！！！可以返回一个指针给void*！
{
	List* ret = NULL;
	if (capacity >= 0)
	{
		// List* ret =  不可以在此处定义，否则如果capacity为0时候，这个程序运行出错
		ret = (List*)malloc(sizeof(List) + sizeof(ListNode)*capacity);

		//意义深刻，现有个sruct 结构提，后面跟着的是listnode；
	}
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;


		ret->node = (ListNode*)(ret + 1);//加1的意思是跳过结构提直接指向第一个node元素！！！


	}
	return ret;
}

void Destroy_list(SeqList* list)
{
	free(list);
}

void Clear_list(SeqList* list)
{
	List* SList = (List*)list;//这里进行强制类型转换，因为申明实际就是void，这里必须转换成真实形式
	//如果在申明的时候声明为List* 就不需要类型转换，但这样没有复用性***
	if (SList != NULL)
	{
		SList->length = 0;
	}
}

int Length_list(SeqList* list)
{
	int i = -1;
	List* LList = (List*)list; //LList可以用SList，不同函数之间可以同变量名的
	if (LList != NULL)
	{
		i = LList->length;
	}
	return i;
}

int insert_list(SeqList* list, int pos, SeqListNode* c)
{
	List* SList = (List*)list;
	int i = 0;
	if (SList != NULL && pos >= 0 && SList->length + 1 <= \
		SList->capacity) 		       //这里的是length加1和capacity比，不是pos，顺序存储超过就在最后加

	{
		if (pos >= SList->length)
		{
			pos = SList->length;   //这里把length给pos，因为pos和length有1的差距
		}
		for (i = SList->length; i >= pos; i--)
		{
			//	SList->node[i] = SList->node[i-1];//这里length就和pos之间有个1的差，
			(SList->node)[i + 1] = SList->node[i];//另外用到指针和数组，顺序存储，所以这样找到pos位置
		}

		SList->node[pos] = (ListNode)c;//这里有一个疑问？？为何c是地址，
		//经过强制类型转换为一个unsigned int的数没错？这里的c指向的是地址还是数据？？
		SList->length++;
	}

	return i;

}

SeqListNode* Get_list(SeqList* list, int pos)
{
	List* SList = (List*)list;
	ListNode* temp = NULL;
	int ret = SList != NULL;
	ret = ret && pos >= 0;
	ret = ret && pos <= SList->length - 1;
	if (ret)
	{
		temp = (ListNode*)SList->node[pos];
	}

	return temp;

}


SeqListNode * delete_list(SeqList* list, int pos)
{
	List* Slist = (List*)list;
	ListNode* temp = NULL;
	if (Slist != NULL && pos >= 0 && pos <= Slist->length - 1)
	{
		int i;
		temp = (ListNode*)Slist->node[pos]; //此处为何用强制类型转换要搞清楚
		for (i = pos; i <= Slist->length - 2; i++) //此处-2是对的，或者pos+1 =i，这里length-1页是可以的
		{
			Slist->node[i] = Slist->node[i + 1];
		}
		Slist->length--;
	}
	return temp;

}



void main()
{

	SeqList* list = Creat_list(8);

	int i = 0;
	int j = 1;
	char k = 2;
	int n = 3;

	Clear_list(list);

	insert_list(list, 0, &i);
	insert_list(list, 1, &j);
	insert_list(list, 2, &k);
	insert_list(list, 3, &n);

	int index;
	for (index = 0; index <= 3; index++)
	{
		ListNode *node = (ListNode*)Get_list(list, index);//任然要类型转换
		printf(" number %d = %d\n", index, *node);

	}

	int ii;
	ii = (int)Length_list(list);
	printf("length = %d\n", ii);

	printf("\n");
	delete_list(list, 1);
	int ii2;
	ii2 = (int)Length_list(list);
	printf("length = %d\n", ii2);



	int shixingcan(void *a);
	char* a;
	*a = 10;
	int c;
	c = shixingcan(a);
	system("pause");
	printf("c=%d", c);

}

int shixingcan(void* a);

int shixingcan(void* a) //验证形参为void指针，那么实参可以是任何类型指针
{
	int* b = (int*)a;
	return *b;
}

#endif