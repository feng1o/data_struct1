#ifndef  _SEQ_LIST_HEAD_
#define  _SEQ_LIST_HEAD_

typedef void SeqList;
typedef void SeqListNode;
#define  MAXSIZE 100  //原来用的，现在这个不需要他了

typedef unsigned int ListNode; //这里是为了能复用,与头文件中的比较区别？？ 头文件中的typedef 了干嘛的？？

SeqList* Creat_list(int capacity);
typedef struct _tag_list
{
	int capacity;
	int length;
	ListNode* node; //用了指针，和上面数组不一样  //区别在这里，，.....
}List; //这里的Tseqlist和定义的线性表，seqlist，不一样

/*
长度
*/
int Length_list(SeqList* list);

void Destroy_list(SeqList* list);

void Clear_list(SeqList* list);


/*
获取线性表中的第pos个元素
*/
//char Get_list(SeqList *list, int pos);
SeqListNode* Get_list(SeqList* list, int pos); //为什么是返回指针类型？

/*
插入一个元素
*/
int insert_list(SeqList* list, int pos, SeqListNode *c);


/*
删除一个元素
*/
//int delete_list (SeqList* list, int pos );
SeqListNode* delete_list(SeqList* list, int pos);
#endif

//为什么  要用SeqListNode* 而不是SeqlistNode直接用？SeqListNode* delete_list(SeqList * list, int pos );
//为什么  int Length_list(SeqList* list); 不是struct里面定义的SeqList*；
//为什么  结构体和创建线性表区别