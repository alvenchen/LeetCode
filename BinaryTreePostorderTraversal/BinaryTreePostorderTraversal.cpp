/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

1
\
2
/
3

return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) 
	{
		vector<int> vec, tmp;
        if (root)
        {
			tmp = postorderTraversal(root->left);
			if (!tmp.empty())
			{
				vec.insert(vec.end(), tmp.begin(), tmp.end());
			}

			tmp = postorderTraversal(root->right);
			if (!tmp.empty())
			{
				vec.insert(vec.end(), tmp.begin(), tmp.end());
			}

			vec.push_back(root->val);
        }
		return vec;
    }
};


//iterative solution

class Solution2 
{
public:
	vector<int> postorderTraversal(TreeNode *root) 
	{
		vector<int> vec;
		if (!root)
		{
			return vec;
		}
		stack<TreeNode *> s;
		vector<TreeNode *> v;
		vector<TreeNode *>::iterator it;
		TreeNode *node = root;
		s.push(root);
		while(!s.empty())
		{
			node = s.top();
			if(node->left)
			{
				it = FindNode(v, node->left);
				if(it != v.end())
				{
					if (node->right)
					{
						vector<TreeNode *>::iterator it2 = FindNode(v, node->right);
						if (it2 !=v.end())
						{
							vec.push_back(node->val);
							s.pop();
							v.erase(it2);
							v.erase(it);
							v.push_back(node);
						}
						else
						{
							s.push(node->right);
						}
					}
					else
					{
						vec.push_back(node->val);
						s.pop();
						v.erase(it);
						v.push_back(node);
					}
				}
				else
				{
					s.push(node->left);
				}
			}
			else if (node->right)
			{
				it = FindNode(v, node->right);
				if(it != v.end())
				{
					vec.push_back(node->val);
					s.pop();
					v.erase(it);
					v.push_back(node);
				}
				else
				{
					s.push(node->right);
				}
			}
			else
			{
				s.pop();
				vec.push_back(node->val);
				v.push_back(node);
			}
		}
		return vec;
	}

	vector<TreeNode *>::iterator FindNode(vector<TreeNode *>&vec, TreeNode *node)
	{
		vector<TreeNode *>::iterator it = vec.begin();
		for (; it!=vec.end(); it++)
		{
			if (*it == node)
			{
				break;
			}
		}
		return it;
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

// 	root->left = new TreeNode(2);
// 	root->right = new TreeNode(3);
// 	root->left->left = new TreeNode(6);
// 	root->left->right = new TreeNode(7);
// 	root->left->right->right = new TreeNode(8);
// 	root->right->left = new TreeNode(9);
// 	root->right->right = new TreeNode(4);
// 	root->right->right->left = new TreeNode(5);

	Print(root);

	Solution solution;
	vector<int> vec = solution.postorderTraversal(root);

	printf("\nafter postorderTraversal1:\n");
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
	vec = solution2.postorderTraversal(root);
	printf("\nafter postorderTraversal1:\n");
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