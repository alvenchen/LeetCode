/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

1
\
2
/
3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Recursive solution

class Solution 
{
public:
	vector<int> preorderTraversal(TreeNode *root) 
	{
		vector<int> vec, tmp;
		if (root)
		{
			vec.push_back(root->val);

			tmp = preorderTraversal(root->left);
			if (!tmp.empty())
			{
				vec.insert(vec.end(), tmp.begin(), tmp.end());
			}

			tmp = preorderTraversal(root->right);
			if (!tmp.empty())
			{
				vec.insert(vec.end(), tmp.begin(), tmp.end());
			}
		}
		return vec;
	}
};


//iterative solution

class Solution2 
{
public:
	vector<int> preorderTraversal(TreeNode *root) 
	{
		vector<int> vec;
		stack<TreeNode *> s;
		if (root)
		{
			s.push(root);
		}
		TreeNode *node;
		while(!s.empty())
		{
			node = s.top();
			s.pop();
			vec.push_back(node->val);
			if (node->right)
			{
				s.push(node->right);
			}
			if(node->left)
			{
				s.push(node->left);
			}

		}
		return vec;
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

	Solution solution;
	vector<int> vec = solution.preorderTraversal(root);

	printf("\nafter preorderTraversal1:\n");
	for (int i=0; i<vec.size();)
	{
		printf("%d ", vec[i]);
		i++;
		if (i % 16 == 0)
		{
			printf("\n");
		}
	}

	Solution2 solution2;
	vec = solution2.preorderTraversal(root);
	printf("\nafter preorderTraversal1:\n");
	for (int i=0; i<vec.size();)
	{
		printf("%d ", vec[i]);
		i++;
		if (i % 16 == 0)
		{
			printf("\n");
		}
	}

	system("pause");

	return 0;
}