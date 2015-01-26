/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

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
    bool isValidBST(TreeNode *root) {
        queue<TreeNode*> q;
		queue<long long> qMin, qMax;
		if (root)
		{
			q.push(root);
			qMin.push(0x8000000000000000);
			qMax.push(0x7fffffffffffffff);
		}
		bool bBST = true;
		TreeNode *node;
		long long min, max;

		while(!q.empty())
		{
			node = q.front();
			min = qMin.front();
			max = qMax.front();
			q.pop();
			qMin.pop();
			qMax.pop();

			if (node->val <= min || node->val >= max)
			{
				bBST = false;
				break;
			}

			if (node->left)
			{
				q.push(node->left);
				qMax.push(node->val);
				qMin.push(min);
			}
			if (node->right)
			{
				q.push(node->right);
				qMax.push(max);
				qMin.push(node->val);
			}
		}

		return bBST;
    }
};