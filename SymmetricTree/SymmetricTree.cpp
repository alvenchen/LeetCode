/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

  1
 / \
2   2
 \   \
 3    3

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
	bool isSymmetric(TreeNode *root) {
		queue<TreeNode*> qLeft;
		queue<TreeNode*> qRight;
		if (root && root->left)
		{
			qLeft.push(root->left);
		}
		if (root && root->right)
		{
			qRight.push(root->right);
		}

		bool bSymmetric = true;
		TreeNode *nodeLeft, *nodeRight;
		while(!qLeft.empty() && !qRight.empty())
		{
			nodeLeft = qLeft.front();
			nodeRight = qRight.front();
			qLeft.pop();
			qRight.pop();

			if (!nodeLeft && !nodeRight)
			{
				continue;
			}
			if (!nodeLeft || !nodeRight)
			{
				bSymmetric = false;
				break;
			}

			if (nodeLeft->val != nodeRight->val)
			{
				bSymmetric = false;
				break;
			}
			
			qLeft.push(nodeLeft->left);
			qLeft.push(nodeLeft->right);
			qRight.push(nodeRight->right);
			qRight.push(nodeRight->left);			
		}

		if (!qLeft.empty() || !qRight.empty())
		{
			bSymmetric = false;
		}

		return bSymmetric;
	}
};