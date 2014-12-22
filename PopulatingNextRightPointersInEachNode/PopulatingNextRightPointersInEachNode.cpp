/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

     1
   /   \
  2     3
 / \   / \
4  5  6   7

After calling your function, the tree should look like:

     1 -> NULL
   /   \
  2  -> 3 -> NULL
 / \   / \
4 ->5->6->7 -> NULL

*/

#include <iostream>
#include <queue>
#include <vector>
#include <Windows.h>
#include <math.h>

using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


TreeLinkNode * Create(int n)
{
	vector<TreeLinkNode*> vec;
	TreeLinkNode *node, *root;
	for (int i=0; i<pow((double)2, (double)n)-1; i++)
	{
		node = new TreeLinkNode(i+1);
		vec.push_back(node);
	}

	for (int i=0; i<pow((double)2, (double)(n-1))-1; i++)
	{
		vec[i]->left = vec[i*2+1];
		vec[i]->right = vec[i*2+2];
	}

	return vec[0];
}


class Solution
{
public:
    void connect(TreeLinkNode *root)
	{
		if (!root)
		{
			return;
		}
		TreeLinkNode *node = root;
		TreeLinkNode *left = node->left, *right = node->right;

		if (left && right)
		{
			left->next = right;
			if (node->next)
			{
				right->next = node->next->left;
			}
		}
		
		connect(node->right);
		connect(node->left);
    }

};

int main()
{
	srand(GetTickCount());

	int n = 3;
	TreeLinkNode *root = Create(n);


	Solution solution;

	solution.connect(root);
	cout<<"after solution"<<endl;

	system("pause");

	return 0;
}