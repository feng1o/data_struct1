#include "searchTree.h"

//���������з�ֹ���ڴ�й¶
pBinSearchTree CreatAndMakeEmptyBinSearchTree(pBinSearchTree tree)
{
	if (NULL!=tree)
	{
		CreatAndMakeEmptyBinSearchTree(tree->lchild);
		CreatAndMakeEmptyBinSearchTree(tree->rchild);
		free(tree);
	}
	return NULL;
}


//��linkstack����ķ����Ƚϣ������pushû�еݹ飬����ʹ���˵ݹ飬������ʱ��Ҳ��null����α�֤�ݹ��ܷ��أ������ģ�ʹ��һ��ָ�룬�������ʵ�֣�
//�����tree�����ǿգ�Ҳ���ܲ��ǿգ���ô��������
pBinSearchTree InsertBinSearchTree(pBinSearchTree tree, elemType value)
{
	//pBinSearchTreeNode tempNode = (pBinSearchTreeNode)malloc(sizeof(binSearchTreeNode));
	//assert(tempNode != NULL);
	//tempNode->lchild = NULL;
	//tempNode->rchild = NULL;
	//tempNode->value = value;
	if (NULL==tree)
	{
		pBinSearchTreeNode tempNode = (pBinSearchTreeNode)malloc(sizeof(binSearchTreeNode));
		assert(tempNode != NULL);
		tempNode->lchild = NULL;
		tempNode->rchild = NULL;
		tempNode->value = value;
		tree = tempNode;
		//return tree;//������return��һ���ʵ���� ���һ��returnһ���Ĺ���
	}
	if (value < tree->value)
	{
		tree->lchild = InsertBinSearchTree(tree->lchild, value);
		//return tree;//������return����ʵ���� ���һ��returnһ���Ĺ���
	}
	if (value > tree->value)
	{
		tree->rchild = InsertBinSearchTree(tree->rchild, value);
		//return tree;//������return����ʵ���� ���һ��returnһ���Ĺ���
	}
	return tree;//Ϊʲô���returnҪ�������������
	//���return�����return���Ƚ�����Ǹ�ʵ�Σ��������������if���棬return�������ģ�
	//һ����return��ʧ����������return
}

/*����ָ��---ok*/
void InsertBinSearchTree2(pBinSearchTree *tree, elemType value)
{
	if (NULL == *tree)
	{
		pBinSearchTreeNode tempNode = (pBinSearchTreeNode)malloc(sizeof(binSearchTreeNode));
		assert(tempNode != NULL);
		tempNode->lchild = NULL;
		tempNode->rchild = NULL;
		tempNode->value = value;
		*tree = tempNode;
		//return tree;//������return��һ���ʵ���� ���һ��returnһ���Ĺ���
	}
	if (value < (*tree)->value)
	{
		 InsertBinSearchTree2(&(*tree)->lchild, value);
		//return tree;//������return����ʵ���� ���һ��returnһ���Ĺ���
	}
	if (value >(*tree)->value)
	{
		 InsertBinSearchTree2(&(*tree)->rchild, value);
		//return tree;//������return����ʵ���� ���һ��returnһ���Ĺ���
	}
}

pBinSearchTreeNode FindMaxBinSearchTreeNode(pBinSearchTree tree)
{
	while (NULL!=tree && NULL!=tree->rchild)
	{
		tree = tree->rchild;
	}
	return tree;
}

//�ݹ�ʵ�֣�����η��������Ǹ���******************************************************8
static pBinSearchTreeNode rNode = NULL;
pBinSearchTreeNode FindMaxBinSearchTreeNodeRecursive(pBinSearchTree tree)
{
	//pBinSearchTreeNode rNode = tree;//�����ﲻ�У�������ζ��壬ÿ�ζ���һ��
	if (NULL != tree && NULL != tree->rchild)
	{
		 FindMaxBinSearchTreeNodeRecursive(tree->rchild);
		 return rNode; //ÿ��return����һ��ֵ
		// return tree;//���return tree���ȵ��ǴΣ���ͣ�ݹ���ȥ
	}
	rNode = tree;//���һ�θ�ֵ������ǰ�治ͣ��return
	//return rNode;
	
}

pBinSearchTreeNode FindMinBinSearchTreeNode(pBinSearchTree tree)
{
	//def_MyAssert(tree);
	if (NULL == tree)
	{
		return tree;
	}
	while (tree->lchild != NULL)
	{
		tree = tree->lchild;
	}
	return tree;
}

//ɾ���ڵ�  ����ɾ����  һ�����ӣ���������ӵ�
/*
*tip:�ѵ���һ���ݹ鷵��һ�������������Һ��ӣ����ı���������Ľṹ��������⣬***************************
*/
pBinSearchTreeNode DeleteBinSearchTreeNode(pBinSearchTree tree,elemType value)
{
	def_MyAssert(tree);//�����еݹ�ģ���ò�Ҫʹ�����assert�ж�����Ϊ�ܿ��ܴ��ݵĲ�������������NULL
	pBinSearchTree tmpNode = NULL;
	if (value < tree->value)
	{
		tree->lchild = DeleteBinSearchTreeNode(tree->lchild, value);//�ѵ��ǽ��ܷ���ֵһ��㷵��
	}
	else if (value > tree->value)
	{
		tree->rchild = DeleteBinSearchTreeNode(tree->rchild, value);
	}
	else if (tree->lchild  && tree->rchild )
	{
		tmpNode = FindMinBinSearchTreeNode(tree->rchild);
		tree->value = tmpNode->value;
		tree->rchild = DeleteBinSearchTreeNode(tree->rchild, tmpNode->value);
	}
	else
	{	
		tmpNode = tree;
		if (NULL == tree->lchild)
		{
			tree = tree->rchild;
		}
		else if (NULL == tree->rchild)//�˴�if��else if����ϴ� 
		{
			tree = tree->lchild;
		}
		delete tmpNode;
	}
	return tree;//����ÿһ��ķ��ؾ��в�ͬ�����壬��������ݹ���û�н����ߣ���ô���м�ϲ㣬�᷵���ײ�

}
//����ָ��
/*����Ĳ��return����ô������������δ��͵�
�����return �Ǹ�boolֵ��ʵ�ʵȼ�����һ��ȫ�ֱ��������һ�㸳ֵ��Ȼ��һֱ���أ����أ����أ���û�����
��return tree������ͺ������ˣ���*/
bool DeleteNode(pBinSearchTree *tree)
{
	pBinSearchTreeNode currentNode, preNode;
	if ((*tree)->rchild ==NULL)
	{
		currentNode = *tree;
		*tree = (*tree)->lchild;//����ָ��  ����changel 
		delete currentNode;
	}
	else if ((*tree)->lchild == NULL)
	{
		currentNode = *tree;
		*tree = (*tree)->rchild;//����ָ��  ����changel 
		delete currentNode;
	}
	else
	{
		currentNode = *tree;
		preNode = (*tree)->lchild;
		while (preNode->rchild != NULL)
		{
			currentNode = preNode; //��¼Ҫɾ���ڵ��ǰһ���ڵ㣬��
			preNode = preNode->rchild;//�ҵ��ڵ�����ӵĵ������������㣬��
		}
		(*tree)->value = preNode->value;
		//currentNode->rchild = preNode->lchild;
		if (*tree == currentNode)//��������û����������ֻ����������ʱ��
		{
			(*tree)->lchild = preNode->lchild;
		}
		else
		{
			currentNode->rchild = preNode->lchild;//������������������ʱ�򣬣�����
		}

		delete preNode;
	}
	return true;
}
bool DeleteBinSearchTreeNode2(pBinSearchTree *tree, elemType value)
{
	def_MyAssert(*tree);
	if ((*tree)->value == value)
	{
		/*����Ĳ��return����ô������������δ��͵�
		�����return �Ǹ�boolֵ��ʵ�ʵȼ�����һ��ȫ�ֱ��������һ�㸳ֵ��Ȼ��һֱ���أ����أ����أ���û�����
		��return tree������ͺ������ˣ���*/
		return DeleteNode(tree);
	}
	else if ((*tree)->value > value)
	{
		return DeleteBinSearchTreeNode2(&(*tree)->lchild, value);
		/*����Ĳ��return����ô������������δ��͵�
		 �����return �Ǹ�boolֵ��ʵ�ʵȼ�����һ��ȫ�ֱ��������һ�㸳ֵ��Ȼ��һֱ���أ����أ����أ���û�����
		 ��return tree������ͺ������ˣ���*/
	}
	else if ((*tree)->value < value)
	{
		 return DeleteBinSearchTreeNode2(&(*tree)->rchild, value);
	}
	//return false;
}








//����������
void TravellBinBinSearchTree(pBinSearchTree tree)
{
	if (tree!=NULL)
	{
		TravellBinBinSearchTree(tree->lchild);
		TravellBinBinSearchTree(tree->rchild);
		std::cout << "Travell: " << std::setw(2) << tree->value << std::endl;

	}
}
//���ݱ���������
void RecursiveBacktraceTravell(pBinSearchTree tree)
{
	if (tree==NULL)
	{
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << "Travell: " << std::setw(2) << tree->value << std::endl;
		if (tree->lchild != NULL)
		{
			RecursiveBacktraceTravell(tree->lchild);
		}
		if (tree->rchild!=NULL)
		{
			RecursiveBacktraceTravell(tree->rchild);
		}
	}
}

int GetHeightOfTree(pBinSearchTree tree)
{
	if (NULL == tree)
	{
		return -1;
	}
	else
	{
		return 1 + (GetHeightOfTree(tree->lchild) > GetHeightOfTree(tree->rchild) ? GetHeightOfTree(tree->lchild) : GetHeightOfTree(tree->rchild));
	}
}