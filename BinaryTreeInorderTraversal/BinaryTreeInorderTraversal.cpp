/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

1
 \
  2
 /
3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <stack>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
		TreeNode *node = root;
		vector<int> vec;
		
		while(!s.empty() || node)
		{
			if (node)
			{
				s.push(node);
				node = node->left;
			}
			else
			{
				if (!s.empty())
				{
					node = s.top();
					s.pop();
					vec.push_back(node->val);
					node = node->right;
				}
			}
		}
		return vec;
    }
};
