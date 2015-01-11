/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include <stack>
#include <set>
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
    int minDepth(TreeNode *root) {
		if (!root)
		{
			return 0;
		}
        int min = 0x7fffffff;
		int tmp = 0;
		stack<TreeNode*> s;
		set<TreeNode*> save;
		s.push(root);
		save.insert(root);
		tmp++;
		
		TreeNode *node;
		while(!s.empty())
		{
			node = s.top();
			if (!node->left && !node->right)
			{
				if (min > tmp)
				{
					min = tmp;
				}
			}
			if (node->left && save.count(node->left) < 1)
			{
				s.push(node->left);
				save.insert(node->left);
				tmp++;
			}
			else if(node->right && save.count(node->right) < 1)
			{
				s.push(node->right);
				save.insert(node->right);
				tmp++;
			}
			else
			{
				s.pop();
				tmp--;
			}
		}

		return min;
    }

};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);

	Solution s;
	s.minDepth(root);

	return 0;
}