/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
 /  \
15   7

return its bottom-up level order traversal as:

[
[15,7],
[9,20],
[3]
]

*/

#include <Windows.h>
#include <iostream>
#include <vector>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
		vector<vector<int>> ret;
		vector<int> vec;
		vector<int> levelNum;
		int level = 0;
		TreeNode *node;
		if (root)
		{
			levelNum.push_back(1);
			q.push(root); 
		}
		while(!q.empty())
		{
			node = q.front();
			q.pop();
			vec.push_back(node->val);
			level = ret.size();
			if (vec.size() == levelNum[level])
			{
				ret.push_back(vec);
				levelNum.push_back(0);
				vec.clear();
			}
			if (levelNum.size()-1 <= level)
			{
				levelNum.push_back(0);
			}
			if (node->left)
			{
				q.push(node->left);
				levelNum[level+1]++;
			}
			if (node->right)
			{
				q.push(node->right);
				levelNum[level+1]++;
			}
		}
		std::reverse(ret.begin(), ret.end());
		return ret;
    }
};


TreeNode * Create(TreeNode *root, int n)
{
	TreeNode *tree = NULL;
	bool bDone = false;

	for (int i=0; i<n; i++)
	{
		tree = root;
		bDone = false;
		for (int j=0; j<n; j++)
		{
			switch(rand() % 5)
			{
			case 0:
				if (!tree->left)
				{
					TreeNode *tmp = new TreeNode(rand() % 100);
					tree->left = tmp;
				}
				tree = tree->left;
				break;
			case 1:
				if (!tree->right)
				{
					TreeNode *tmp = new TreeNode(rand() % 100);
					tree->right = tmp;
				}
				tree = tree->right;
				break;
			default:
				bDone = true;
				break;
			}
			if(bDone)
			{
				break;
			}
		}
	}

	return root;
}

void Print(TreeNode *tree)
{
	if (!tree)
	{
		return;
	}
	queue<TreeNode*> fifo;
	fifo.push(tree);
	TreeNode *tmp;
	int i=0;

	while(!fifo.empty())
	{
		tmp = fifo.front();
		fifo.pop();

		if (!tmp)
		{
			printf("# ");
		}
		else
		{
			printf("%d ", tmp->val);
			fifo.push(tmp->left);
			fifo.push(tmp->right);
		}

		i++;
		if (i % 16 == 0)
		{
			printf("\n");
		}
	}

}

int main()
{
	srand(GetTickCount());

	int n = 20;
	TreeNode *root = new TreeNode(1);
	root = Create(root, n);
	Print(root);

	Solution s;
	vector<vector<int>> v = s.levelOrderBottom(root);
	printf("\nlevelOrderBottom:\n");
	for (int i=0; i<v.size(); i++)
	{
		for (int j=0; j<v[i].size(); j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}

	system("pause");

	return 0;
}