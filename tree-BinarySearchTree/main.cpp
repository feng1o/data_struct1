#include "searchTree.h"

int main()
{

#if 0
	pBinSearchTree tree = CreatAndMakeEmptyBinSearchTree(NULL);

	//tree = InsertBinSearchTree(tree, 3);
	//tree = InsertBinSearchTree(tree, 4);
	tree = InsertBinSearchTree(tree, 1);
	tree = InsertBinSearchTree(tree, 2);
	tree = InsertBinSearchTree(tree, 7);
	tree = InsertBinSearchTree(tree, 9);
#endif


#if 01  //二级指针 一样ok
	pBinSearchTree tree = CreatAndMakeEmptyBinSearchTree(NULL);
	InsertBinSearchTree2(&tree, 1);
	InsertBinSearchTree2(&tree, 2);
	InsertBinSearchTree2(&tree, 7);
	InsertBinSearchTree2(&tree, 9);
#endif

	tree = DeleteBinSearchTreeNode(tree, 1);
	//std::cout << "&&====" << DeleteBinSearchTreeNode2(&tree, 2) <<std:: endl;
	TravellBinBinSearchTree(tree);
	std::cout << "..................\n";
	RecursiveBacktraceTravell(tree);

	std::cout << "..................\n";
	std::cout << "finMAX==" << FindMaxBinSearchTreeNode(tree)->value << std::endl;

	static pBinSearchTreeNode snode = FindMaxBinSearchTreeNodeRecursive(tree);
	//std::cout << "finMAXRecursive==" << FindMaxBinSearchTreeNodeRecursive(tree)->value << std::endl;
	std::cout << snode->value << std::endl;

	//获取一个树的高度
	int height = GetHeightOfTree(tree);
	std::cout << "树高度是=" << height << std::endl;
	return 0;
}