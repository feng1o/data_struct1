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
SeqList* Creat_list(int capacity) //���ﲻ������ List* Creat_list(int capacity) �������ǣ������������Է���һ��ָ���void*��
{
	List* ret = NULL;
	if (capacity >= 0)
	{
		// List* ret =  �������ڴ˴����壬�������capacityΪ0ʱ������������г���
		ret = (List*)malloc(sizeof(List) + sizeof(ListNode)*capacity);

		//������̣����и�sruct �ṹ�ᣬ������ŵ���listnode��
	}
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;


		ret->node = (ListNode*)(ret + 1);//��1����˼�������ṹ��ֱ��ָ���һ��nodeԪ�أ�����


	}
	return ret;
}

void Destroy_list(SeqList* list)
{
	free(list);
}

void Clear_list(SeqList* list)
{
	List* SList = (List*)list;//�������ǿ������ת������Ϊ����ʵ�ʾ���void���������ת������ʵ��ʽ
	//�����������ʱ������ΪList* �Ͳ���Ҫ����ת����������û�и�����***
	if (SList != NULL)
	{
		SList->length = 0;
	}
}

int Length_list(SeqList* list)
{
	int i = -1;
	List* LList = (List*)list; //LList������SList����ͬ����֮�����ͬ��������
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
		SList->capacity) 		       //�������length��1��capacity�ȣ�����pos��˳��洢������������

	{
		if (pos >= SList->length)
		{
			pos = SList->length;   //�����length��pos����Ϊpos��length��1�Ĳ��
		}
		for (i = SList->length; i >= pos; i--)
		{
			//	SList->node[i] = SList->node[i-1];//����length�ͺ�pos֮���и�1�Ĳ
			(SList->node)[i + 1] = SList->node[i];//�����õ�ָ������飬˳��洢�����������ҵ�posλ��
		}

		SList->node[pos] = (ListNode)c;//������һ�����ʣ���Ϊ��c�ǵ�ַ��
		//����ǿ������ת��Ϊһ��unsigned int����û�������cָ����ǵ�ַ�������ݣ���
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
		temp = (ListNode*)Slist->node[pos]; //�˴�Ϊ����ǿ������ת��Ҫ�����
		for (i = pos; i <= Slist->length - 2; i++) //�˴�-2�ǶԵģ�����pos+1 =i������length-1ҳ�ǿ��Ե�
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
		ListNode *node = (ListNode*)Get_list(list, index);//��ȻҪ����ת��
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

int shixingcan(void* a) //��֤�β�Ϊvoidָ�룬��ôʵ�ο������κ�����ָ��
{
	int* b = (int*)a;
	return *b;
}

#endif