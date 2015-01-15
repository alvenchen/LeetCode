/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <Windows.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
		int max = 0, tmp = 0;
		TreeNode *node;
		stack<TreeNode*> s;
		stack<int> tmpMax;
		if (root)
		{
			s.push(root);
		}
		while (!s.empty())
		{
			node = s.top();
			s.pop();
			tmp++;
			if (!node->left && !node->right)
			{
				if (max < tmp)
				{
					max = tmp;
				}
				if (tmpMax.empty())
				{
					break;
				}
				tmp = tmpMax.top();
				tmpMax.pop();
			}
			if (node->left && node->right)
			{
				tmpMax.push(tmp);
			}
			if (node->right)
			{
				s.push(node->right);
			}
			if (node->left)
			{
				s.push(node->left);
			}
		}

		return max;
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
	cout<<endl<<s.maxDepth(root);

	getchar();

	return 0;
}