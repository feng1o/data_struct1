#define  _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
//#include "iostream"
#include "assert.h"

typedef char elemType;
typedef struct tag_BinTreeNode binTreeNode;
typedef  binTreeNode * pBinTree;

struct tag_BinTreeNode
{
	//tag_BinTreeNode() :lchild(NULL), rchild(NULL), data(0){};
	elemType data;
	binTreeNode* lchild, *rchild;
};

//ǰ�����������
	void CreatBinTree(pBinTree *tree)//����ָ��
	{
		char ch ;
		//std::cin >> ch;

		scanf("%c", &ch);
		//std::cout << c << std::endl;
		if (' ' == ch)
		{
			*tree = NULL;
		}
		else
		{
			//*tree = new binTreeNode;//������Ҫ������
			*tree = (pBinTree)malloc(sizeof(binTreeNode));
			assert(*tree != NULL);
			(*tree)->data = ch;
			CreatBinTree(&(*tree)->lchild);
			CreatBinTree(&(*tree)->rchild);
		}
}

	pBinTree CreatBinTree2()//����ָ��  ���У���Ҫһ�����ܣ�����������������Ϊʲô������
		{
			char ch;
		//	static pBinTree tmptree ;  //static �ᵼ�·��ص�������һ�ν����ֵ����null
			pBinTree tmptree;
			//std::cin >> ch;

			scanf("%c", &ch);
			//std::cout << c << std::endl;
			if (' ' == ch)
			{
				tmptree = NULL;
				return tmptree;
			
			}
			else
			{
				//*tree = new binTreeNode;//������Ҫ������
				tmptree = (pBinTree)malloc(sizeof(binTreeNode));
				//tmptree = (pBinTree)calloc(1,sizeof(binTreeNode));
				assert(tmptree != NULL);
				tmptree->data = ch;
				tmptree->lchild = NULL;
				tmptree->rchild = NULL;
				printf("������= %c\n", tmptree->data);

				CreatBinTree2();
				CreatBinTree2();
			}
			return tmptree;
		}
void VistBinTree(pBinTree tree, int level)
{
	//std::cout << "���ʽڵ� " << tree->data <<"������ "<< level << std::endl;
	printf("%cλ�ڵ�%d��\n", tree->data, level);
}

//����������
void PreOrderTravelBinTree(pBinTree tree, int level)
{
	if (tree)
	{
		VistBinTree(tree, level);
		PreOrderTravelBinTree(tree->lchild, level + 1); //������ǵ����ݹ飬�ǻ��ݣ����ݻ���ѡ�񣬱���
		PreOrderTravelBinTree(tree->rchild, level + 1);
	}
	else
	{
		printf("�ݹ���]\n");
	}
#if 0
//���ݷ�����������������
	/*tip�����ݶ���ɨ���������Ȼ�����õģ��ȼ��ڱ���һ�飬��Ϊ�����������ڵ�һ����Ķ�����·��*/
	if (tree)
	{
		for (����n;i=1;i<=n��i++ )
		{
			VistBinTree(����i��level);
			PreOrderTravelBinTree(����i��level + 1);
		}
	}

#endif


#if 0
	//���ݷ���������,��һ�δӸ�ɨ�赽Ҷ�Ӿ�ֹͣ��returnʵ��
	if (tree)
	{
		for (����n; i = 1; i <= n��i++)
		{
			VistBinTree(����i��level);
			if(PreOrderTravelBinTree(����i��level + 1))
				return 1;//Ҫ�����÷���ֵ��bool;������һ�α����󷵻�1��һ��㲻ͣ����1���Ͳ������forѭ���ˣ�
			//8�ʺ�����
		}
	}
	else
		return 1;//���ʵ��һ�θ㶨 

#endif

}

int main()
{
#ifdef _cplusplus
	printf("c_++\n");
#else
	printf("this is a c program!\n");
#endif // _cplusplus

	//pBinTree tree = NULL;//һ��ָ�룬���Ͷ���һ��ָ���βΣ����ݱ�����ַ����
	//CreatBinTree(&tree);//����ָ��
	//PreOrderTravelBinTree(tree, 1);

	
	pBinTree tree2 = CreatBinTree2();//1��ָ��
	printf("��ַ��= %p\n", tree2);  //��ַ��0000������
	PreOrderTravelBinTree(tree2, 1);

	return 0;
}