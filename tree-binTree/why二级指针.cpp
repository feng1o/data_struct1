#if 01
//http://blog.chinaunix.net/uid-26983585-id-3219788.html
#include<stdio.h>
#include<stdlib.h>
struct BiTNode {
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;//�������Ľṹ struct BiTNode* rchild;
};
typedef struct BiTNode * BiTree;
void CreatBiTree(BiTree*); //����������
void PreOrderTraverse(BiTree); // �����ö���������ӡ�����ڵ��ֵ
void main(){
	BiTree T = NULL; //TΪ���ڵ�
	CreatBiTree(&T);
	PreOrderTraverse(T);
	system("pause");
}
//������ݹ���̽���������
void CreatBiTree(BiTree * T)
{
	char ch;
	ch = getchar();
	if (ch == '*') //��������Ǻ���������Ľڵ�Ϊ�սڵ�
		*T = NULL;
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(struct BiTNode))))
		{
			printf("�ڴ����ʧ�ܣ�");
			return; //�������Ĳ����Ǻš���Ϊ�½ڵ�����ڴ�ռ�
		}
		else
		{
			(*T)->data = ch;
			CreatBiTree(&((*T)->lchild)); //����ɹ�����Ž�����������������
			CreatBiTree(&((*T)->rchild));
		}
	}
}


void PreOrderTraverse(BiTree T){
	if (T)
	{
		printf("%c", T->data);;
		if (T->lchild)
			PreOrderTraverse(T->lchild); //������������������ڵ��ֵ
		if (T->rchild)
			PreOrderTraverse(T->rchild);
	}
}

/*
�������У�������Ϊ��ѧ�����׷�һ�¼�������
1��������������������ģʽ��
a: ��main �����ж���һ��BiTree ע�����Ǹ��������ڵ��ָ�����ͣ�Ȼ������������ݸ�һ��CreatBiTree ������
�ڸú����еݹ鴴�����������������£�
*/

void CreatBiTree(BiTree * T) //ע�������õ��Ƕ���ָ�룻��������׷�����ĵط���

{
	char ch;
	ch = getchar();
	if (ch == '*') //��������Ǻ���������Ľڵ�Ϊ�սڵ�
		*T = NULL;
	else{
		if (!(*T = (BiTree)malloc(sizeof(struct BiTNode)))) {
			printf("�ڴ����ʧ�ܣ�");
			return; //�������Ĳ����Ǻš���Ϊ�½ڵ�����ڴ�ռ�
		}
		else
		{
			(*T)->data = ch;
			CreatBiTree(&((*T)->lchild)); //����ɹ�����Ž�����������������
			CreatBiTree(&((*T)->rchild));}
	}
}
/*
b:����ֱ����CreatBiTree�����д����������������ض������ĸ� ָ�룻
 �磺BiTree T=CreatBiTree��������������
 */
BiTree CreatBiTree()
{
	char ch;
	BiTNode *pt = NULL;
	ch = getchar();
	if ('*' == ch)
		return NULL;
	else {
		pt = (BiTNode *)malloc(sizeof(BiTNode));
		pt->data = ch;
		pt->lchild = CreatBiTree();
		pt->rchild = CreatBiTree();
		return pt;
	}


	/*
�Ǻǡ������ϱߵ������������̿��������ǵڶ����������һ�㣺
�����󲿷��ˣ������ɻ�һ�����⣬�Ǿ����� ��һ�� ���� A) �Ĺ����У�Ϊʲôһ��Ҫʹ�ö���ָ�룬��һ��Ϊʲô�Ͳ����أ���
����˵�����д���ָ�룬�ں����иı�ָ���ֵ�������ڸı� ʵ���е�������Ϣ�����
�������ʵ�ɣ��ϱ�˵��Ҳ�ԣ��������������ˡ����������ǣ��ڽ����������Ĺ����У����Ǹı����βε�ֵ�����ǣ� �ı����βε�ָ�򣻶��Ƴ��ú������βα��ͷ��ˣ���ôΪ�βζ�̬����Ŀռ䣬Ҳ��û�취�ͷ��ˣ�������ڴ�й¶���⡣��
�ٸ����Ӱɣ�
*/
void get_Vale1(char *pt)
{
		pt = (char *)malloc(strlen("sx_liang") + 1);
		strcpy(pt, "sx_liang");
	}
void get_Vale2(char **pt)
	{
		*pt = (char *)malloc(strlen("sx_liang") + 1);
		strcpy(*pt, "sx_liang");
	}

	int main()
	{
		char *pt = NULL;
		get_Vale1(pt); //������������õĹ����У����ݵ���һ��ָ�룻
		if (NULL == pt) //��������������أ��ͻ�ִ��if ��ߵ���Ϣ�ˡ�����
		{
			cout << "pt is NULL" << endl;
			exit(1);
		}
		else
			cout << pt << endl;
		get_Vale2(&pt); //�����أ����ݵ��Ƕ���ָ�룬����أ�������ˡ�sx_liang";
		if (NULL == pt)
		{
			cout << "pt is NULL";
		}
	}
/*ʲôԭ���أ� �ۿ�ʼ����һ�£�
void get_Vale1(char *M)//�����أ�������һ��ָ�룬��ʱ��M�� ʵ�� pt ��ָ���ڴ��ͬһ��ռ䣬��ָ����null;
M=(char *)malloc(strlen("sx_liang")+1); //��ʱ�أ���M�����¿�����һ��ռ䣬 ��ʵ��pt û�б仯����ָ��NULL��
//�������M ��pt �Ѿ�û����ϵ�ˣ����ױ��������ָ��ͬ��ָ�룻
strcpy(M,"sx_liang");//�˳�����ʱ����ΪM�Ǿֲ���������ջ�з���Ŀռ䣬��ôM�Զ����٣����ڶ���ΪM����Ŀռ��أ�й¶�ˣ�û�б��ͷţ��Ǹ����⣡
void get_Vale2(char **M)//�����أ����ݵ��Ƕ���ָ�룻��ʱ��M ָ��ʵ�Σ������Ǻ�ʵ��һ��ָ��null��*M ��ʱ�ź�pt��ͬ����ָ����NULL��ע�����һ�£�
*M=(char *)malloc(strlen("sx_liang")+1);//�������أ�*M���� ʵ��pt ,��*M����ռ䣬������Ϊpt ����ռ䣻ע������ˣ�
strcpy(*M,"sx_liang");//�Ƴ�������M���٣�����������Ŀռ�û���ͷţ����Ǹÿռ���pt ָ�������������ͷ����⣻
������������ˣ�Ӧ�þ�������Ϊʲô �������Ĵ��������� A �취Ҫʹ�ö���ָ���˰ɡ�������һ��ָ�룬ÿ�δ����Ľڵ㣬��û�к�ͷָ��root ��ϵ��������Ȼ��û�취��ӡ�ˣ� �������ء������Ǻǡ�������OK�ˡ�������
���������ˡ������Ǻǡ�����*/
#endif