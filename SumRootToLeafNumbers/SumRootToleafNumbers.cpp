/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <queue>
#include <vector>

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
					TreeNode *tmp = new TreeNode(rand() % 9 + 1);
					tree->left = tmp;
				}
				tree = tree->left;
				break;
			case 1:
				if (!tree->right)
				{
					TreeNode *tmp = new TreeNode(rand() % 9 + 1);
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
	int sumNumbers(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		int sum = 0;
		vector<int> vec;

		Traversal(root, vec, sum);

		return sum;
	}

	void Traversal(TreeNode *node, vector<int>&vec, int &sum)
	{
		vec.push_back(node->val);
		if (!node->left && !node->right)
		{
			sum += vecToInt(vec);
			return;
		}
		if (node->left)
		{
			Traversal(node->left, vec, sum);
			vec.pop_back();
		}
		if (node->right)
		{
			Traversal(node->right, vec, sum);
			vec.pop_back();
		}
	}

	int vecToInt(vector<int> vec)
	{
		if (vec.empty())
		{
			return 0;
		}
		int ret = vec[0];
		for (int i=1; i<vec.size(); i++)
		{
			ret *= 10;
			ret += vec[i];
		}
		return ret;
	}
};

int main()
{
	srand(GetTickCount());

	TreeNode *root = new TreeNode(1);
	Create(root, 20);
	Print(root);

	Solution solution;
	
	printf("\nsum : %d\n", solution.sumNumbers(root));

	system("pause");
	return 0;
}