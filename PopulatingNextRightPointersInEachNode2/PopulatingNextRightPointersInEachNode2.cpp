/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.

For example,
Given the following binary tree,

     1
   /   \
  2     3
 / \     \
4   5    7

After calling your function, the tree should look like:

     1 -> NULL
   /   \
  2 ->  3 -> NULL
 / \     \
4-> 5 ->  7 -> NULL

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
	TreeLinkNode *tree = NULL;
	TreeLinkNode *root = new TreeLinkNode(1);
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
					TreeLinkNode *tmp = new TreeLinkNode(rand() % 100);
					tree->left = tmp;
				}
				tree = tree->left;
				break;
			case 1:
				if (!tree->right)
				{
					TreeLinkNode *tmp = new TreeLinkNode(rand() % 100);
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


void Print(TreeLinkNode *tree)
{
	if (!tree)
	{
		return;
	}
	queue<TreeLinkNode*> fifo;
	fifo.push(tree);
	TreeLinkNode *tmp;
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
	void connect(TreeLinkNode *root)
	{
		if (!root)
		{
			return;
		}
		TreeLinkNode *node = root;
		TreeLinkNode *left = node->left, *right = node->right;
		TreeLinkNode *next = NULL, *tmp = NULL;

		if (left)
		{
			if (right)
			{
				left->next = right;
				//cout<<left->val<<"->"<<right->val<<endl;
			}
			else
			{
				next = FindNext(node->next);
				if (next)
				{
					left->next = next;
					//cout<<left->val<<"->"<<next->val<<endl;
				}
			}
		}
		if (right)
		{
			next = FindNext(node->next);
			if (next)
			{
				right->next = next;
				//cout<<right->val<<"->"<<next->val<<endl;
			}
		}

		connect(node->right);
		connect(node->left);
	}

	TreeLinkNode *FindNext(TreeLinkNode *Node)
	{
		TreeLinkNode *next = NULL;
		while(Node && !next)
		{
			if (Node->left)
			{
				next = Node->left;
			}
			else if(Node->right)
			{
				next = Node->right;
			}
			else if(Node->next)
			{
				Node = Node->next;
			}
			else
			{
				break;
			}
		}
		return next;
	}
};

int main()
{
	srand(GetTickCount());

	int n = 100;
	TreeLinkNode *root = Create(n);
	Print(root);

	Solution solution;

	cout<<"after solution:\n";
	solution.connect(root);

	system("pause");

	return 0;
}