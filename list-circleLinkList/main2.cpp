
#include "circlebiList.h"
#include "vector"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		int pLen = pre.size();
		int iLen = in.size();
		if (pLen == 0)
			return nullptr;
		return constructTree(pre, 0, pLen - 1, in, 0, iLen - 1);
	}
	TreeNode* constructTree(vector<int> pre, int ps, int pen, vector<int> in, int is, int ien){
		TreeNode* node = new TreeNode(pre.at(ps));
		//if(ps == pen && ien == is)
		// return node;
		if (pen == ps && ien != is)
			throw std::runtime_error("...error...\n");
		else if (pen != ps && ien == is)
			throw std::runtime_error("....error...\n");
		else {
			//TreeNode* node = new TreeNode(pre.at(ps));
			int i = 0;
			for (; in.at(i + is) != pre.at(ps) && i + is <= ien; ++i);
			if (i > 0 && i <= ien - is){
				node->left = constructTree(pre, ps + 1, ps + i, in, is, is + i - 1);
				//   node->right = constructTree(pre, ps+i+1, pen, in, is+i+1, ien);
			}
			if (i != ien - is)
				node->right = constructTree(pre, ps + i + 1, pen, in, is + i + 1, ien);
			return node;
		}

	}
	void print(TreeNode* tree , int level){
		if (tree == nullptr)
		{
			cout << "$" << endl;
		}
		cout << "...node.." << tree->val << "  level: " << level << endl;
		print(tree->left, level + 1);
		print(tree->right, level + 1);

	}
	using TreeNode = TreeNode;
private:
};


int main(){
	Solution sol;
	struct TreeNode *tree = sol.reConstructBinaryTree({ 2, 4 }, { 4, 2 });
	sol.print(tree, 1);
	pCListNode clist;
	cout << "..." << init(&clist);

	for (int i = 0; i < 269; ++i)
	{
		cout <<"...." << static_cast<char>(clist->val) << endl;
		clist = clist->next;
	}

	return 0;
}