#ifndef  _SEQ_LIST_HEAD_
#define  _SEQ_LIST_HEAD_

typedef void SeqList;
typedef void SeqListNode;
#define  MAXSIZE 100  //ԭ���õģ������������Ҫ����

typedef unsigned int ListNode; //������Ϊ���ܸ���,��ͷ�ļ��еıȽ����𣿣� ͷ�ļ��е�typedef �˸���ģ���

SeqList* Creat_list(int capacity);
typedef struct _tag_list
{
	int capacity;
	int length;
	ListNode* node; //����ָ�룬���������鲻һ��  //�����������.....
}List; //�����Tseqlist�Ͷ�������Ա�seqlist����һ��

/*
����
*/
int Length_list(SeqList* list);

void Destroy_list(SeqList* list);

void Clear_list(SeqList* list);


/*
��ȡ���Ա��еĵ�pos��Ԫ��
*/
//char Get_list(SeqList *list, int pos);
SeqListNode* Get_list(SeqList* list, int pos); //Ϊʲô�Ƿ���ָ�����ͣ�

/*
����һ��Ԫ��
*/
int insert_list(SeqList* list, int pos, SeqListNode *c);


/*
ɾ��һ��Ԫ��
*/
//int delete_list (SeqList* list, int pos );
SeqListNode* delete_list(SeqList* list, int pos);
#endif

//Ϊʲô  Ҫ��SeqListNode* ������SeqlistNodeֱ���ã�SeqListNode* delete_list(SeqList * list, int pos );
//Ϊʲô  int Length_list(SeqList* list); ����struct���涨���SeqList*��
//Ϊʲô  �ṹ��ʹ������Ա�����