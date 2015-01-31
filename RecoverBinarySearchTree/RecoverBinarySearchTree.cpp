/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
*/

#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void recoverTree(TreeNode *root)
	{
		node1 = node2 = currMin = NULL;
		Traversal(root);
		if (node1 && node2)
		{
			int tmp = node1->val;
			node1->val = node2->val;
			node2->val = tmp;
		}
    }

	void Traversal(TreeNode *node)
	{
		if (!node)
		{
			return;
		}
		Traversal(node->left);
		if (currMin)
		{
			if (currMin->val > node->val)
			{
				if (!node1)
				{
					node1 = currMin;
				}
				node2 = node;
			}
		}
		currMin = node;
		Traversal(node->right);
	}

private:
	TreeNode *node1, *node2, *currMin;
};

int main()
{
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);

	n1->left = n2;

	Solution s;
	s.recoverTree(n1);

	return 0;
}