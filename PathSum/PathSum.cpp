/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if (!root)
		{
			return false;
		}
		stack<TreeNode*> s;
		set<TreeNode*> save;
		s.push(root);
		save.insert(root);
		int tmp = root->val;
		TreeNode *node;
		while(!s.empty())
		{
			node = s.top();
			if (!node->left && !node->right && tmp == sum)
			{
				break;
			}
			if (node->left && save.count(node->left) < 1)
			{
				s.push(node->left);
				save.insert(node->left);
				tmp += node->left->val;
			}
			else if(node->right && save.count(node->right) < 1)
			{
				s.push(node->right);
				save.insert(node->right);
				tmp += node->right->val;
			}
			else
			{
				tmp -= node->val;
				s.pop();
			}
		}
		if (tmp != sum || s.empty())
		{
			return false;
		}
		return true;
	}

};




/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

return

[
	[5,4,11,2],
	[5,8,4,5]
]

*/

class Solution2 {
public:
	vector<vector<int>> pathSum(TreeNode *root, int sum)
	{
		vector<vector<int>> ret;
		if (!root)
		{
			return ret;
		}
		stack<TreeNode*> s;
		set<TreeNode*> save;
		s.push(root);
		save.insert(root);
		int tmp = root->val;
		TreeNode *node;
		while(!s.empty())
		{
			node = s.top();
			if (!node->left && !node->right && tmp == sum)
			{
				vector<int> vec;
				stack<TreeNode*> tmpS = s;
				while(!tmpS.empty())
				{
					vec.insert(vec.begin(), 1, tmpS.top()->val);
					tmpS.pop();
				}
				ret.push_back(vec);
			}
			if (node->left && save.count(node->left) < 1)
			{
				s.push(node->left);
				save.insert(node->left);
				tmp += node->left->val;
			}
			else if(node->right && save.count(node->right) < 1)
			{
				s.push(node->right);
				save.insert(node->right);
				tmp += node->right->val;
			}
			else
			{
				tmp -= node->val;
				s.pop();
			}
		}
		return ret;
	}

};
