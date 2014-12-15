/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

	  1
	 / \
	2   3

Return 6. (2+1+3)
*/

#include <Windows.h>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
					TreeNode *tmp = new TreeNode(rand() % 100 - 50);
					tree->left = tmp;
				}
				tree = tree->left;
				break;
			case 1:
				if (!tree->right)
				{
					TreeNode *tmp = new TreeNode(rand() % 100 - 50);
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

class Solution
{
public:
    int maxPathSum(TreeNode *root)
	{
        int maxSum = 0x80000000;

		if (!root)
		{
			return 0;
		}
		maxPathSum(root, maxSum);

		return maxSum;
    }

	int maxPathSum(TreeNode *root, int &maxSum)
	{
		int left = 0, right = 0;

		if (root->left)
		{
			left = maxPathSum(root->left, maxSum);
		}
		if (root->right)
		{
			right = maxPathSum(root->right, maxSum);
		}
		
		int maxBranch = max(max(left, right) + root->val, root->val);//val  or  left + val  or  right + val
		int currMax = max(left + right + root->val, maxBranch);

		maxSum = max(maxSum, currMax);
		return maxBranch;
	}
};

int main()
{
	srand(GetTickCount());

	int n = 10;
	TreeNode *root = new TreeNode(1);

	root = Create(root, n);
	Print(root);

	Solution solution;

	printf("\nsum :%d", solution.maxPathSum(root));

	system("pause");

	return 0;
}
