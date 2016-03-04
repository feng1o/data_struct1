#include "seqStack.h"
#include "assert.h"
#include "windows.h"
#define  _CRT_SECURE_NO_WARNINGS
using std::cin;
using std::cout;
using std::endl;
typedef seqStack* pSeqStack;

vSeqStack* CreatSeqStack(int capacity)
{
	assert(capacity >= 1);
	
	seqStack* stack = (pSeqStack)malloc(sizeof(seqStack));
	assert(stack != nullptr);
	stack->node = (elemType *)malloc(sizeof(elemType)*capacity);//��ʹ�� ��������
	stack->topOfStack = defEmptyTOS;
	stack->capacity = capacity;
	stack->length = 0;
	return stack;
}

bool IsFull(vSeqStack * vstack)
{
	pSeqStack stack = (pSeqStack)vstack;
	return (stack->topOfStack) == stack->capacity-1;
}

bool IsEmpty(vSeqStack * vstack){
	pSeqStack stack = (pSeqStack)vstack;
	return stack->topOfStack == defEmptyTOS;
}
void Push(elemType elem, vSeqStack* vstack)
{
	pSeqStack stack = (pSeqStack)vstack;
	assert(nullptr != stack);
	assert(!IsFull(stack));
	stack->node[++stack->topOfStack] = elem;
	stack->length++;
	cout <<"push- "<<elem<< "  ����Ϊ��" << stack->length << endl;
}

elemType Pop(vSeqStack *vstack)
{
	pSeqStack stack = (pSeqStack)vstack;
	assert(!IsEmpty(stack));
	assert(nullptr != stack);
	stack->length--;
	cout << "pop - " << stack->node[stack->topOfStack] << "  ����Ϊ��" << stack->length << endl;
	return stack->node[stack->topOfStack--];
}

#define  myassert(x) \
	if(x>1) {printf("�ļ�����%s..line=%d...fun����=%s\n",__FILE__,__LINE__,__FUNCTION__);\
	char str[50];\
	sprintf_s(str,"�ļ�����%s..line=%d...fun����=%s\n",__FILE__,__LINE__,__FUNCTION__);\
	MessageBoxA(0,str,str,0);}
#define  x 10
int main()
{
			//system("calc");
			//cout << __DATE__ << endl;
			//MessageBoxA(0, "xxx", "liufeng", 0);
			//getchar();
			////assert(2 < 1);
			////cout << xx << endl;
			//myassert(2);
	pSeqStack stack = (pSeqStack)CreatSeqStack(1);
	Push(0, stack);
	//cout << "����Ϊ��"<< stack->length << endl;
//	Push(1, stack);
	//Push(2, stack);
	//Push(3, stack);
	cout << endl;
	cout << "isfull test: " << IsFull(stack) << endl;

	cout << Pop(stack) << endl;
	//cout << "����Ϊ��" << stack->length << endl;
	cout << Pop(stack) << endl;

	cout << "isfull test: " << IsFull(stack) << endl;
	return 0;
}