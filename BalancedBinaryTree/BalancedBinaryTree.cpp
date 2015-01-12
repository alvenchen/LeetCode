/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
*/

#include <Windows.h>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isBalanced(TreeNode *root) {
		bool balanced = true;

		Count(root, balanced);

		return balanced;
	}

	int Count(TreeNode *node, bool &balanced)
	{
		if (!node || !balanced)
		{
			return 0;
		}
		int left=0, right = 0;
		if (node->left)
		{
			left++;
		}
		if (node->right)
		{
			right++;
		}
		left += Count(node->left, balanced);
		right += Count(node->right, balanced);

		if (abs(left - right) > 1)
		{
			balanced = false;
			return 0;
		}

		return max(left, right);
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
	cout<<endl<<s.isBalanced(root);

	system("pause");

	return 0;
}