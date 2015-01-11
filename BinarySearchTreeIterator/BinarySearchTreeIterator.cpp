/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
*/

#include <Windows.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator
{
public:
    BSTIterator(TreeNode *root) {
		if (!root)
		{
			return;
		}
		Traversal(root, q);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return (!q.empty());
    }

    /** @return the next smallest number */
    int next() {
		int ret = q.front()->val;
		q.pop();
		return ret;
    }
private:

	TreeNode *Traversal(TreeNode *root, queue<TreeNode*> &q)
	{
		if (!root)
		{
			return NULL;
		}
		Traversal(root->left, q);
		q.push(root);
		Traversal(root->right, q);
	}

private:
	queue<TreeNode*> q;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


void insert(TreeNode *root, TreeNode *node)
{
	if (!root)
	{
		return;
	}
	if (node->val < root->val)
	{
		if (!root->left)
		{
			root->left = node;
		}
		else
		{
			insert(root->left, node);
		}
	}
	else
	{
		if (!root->right)
		{
			root->right = node;
		}
		else
		{
			insert(root->right, node);
		}
	}
}

void Create(TreeNode **root, int n)
{
	TreeNode *node = new TreeNode(rand() % 100);
	*root = node;
	for (int i=0; i<n-1; i++)
	{
		node = new TreeNode(rand() % 100);
		insert(*root, node);
	}
	
}

void Print(TreeNode *root)
{
	if (!root)
	{
		return;
	}
	cout<<root->val<<" ";
	Print(root->left);
	Print(root->right);
}

int main()
{
	srand(GetTickCount());

	TreeNode *root = NULL;
	Create(&root, 10);
	Print(root);
	cout<<endl;

	BSTIterator i =  BSTIterator(root);
	while (i.hasNext())
	{
		cout << i.next() << " ";
	}

	system("pause");

	return 0;
}