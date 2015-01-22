/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.empty())
		{
			return NULL;
		}
		int n = inorder.size();
		int sPost = 0, iPost = n-1, sIn = 0, iIn = 0;
		TreeNode *head = NULL, *node = NULL;
		head = new TreeNode(postorder[iPost]);

		for (iIn=sIn; iIn<inorder.size(); iIn++)
		{
			if (postorder[iPost] == inorder[iIn])
			{
				break;
			}
		}

		if (sIn < iIn)
		{
			BuildLeft(head, postorder, inorder, 0, iPost, sIn, iIn);
		}
		if (iIn < n)
		{
			BuildRight(head, postorder, inorder, 0, iPost, iIn+1, n);
		}		

		return head;
	}
	void BuildLeft(TreeNode *root, vector<int> &postorder, vector<int> &inorder,  int sPost, int ePost, int sIn, int eIn)
	{
		int iPost = ePost, iIn = sIn;

		for (; iPost>=sPost; iPost--)
		{
			for (iIn = sIn; iIn<eIn; iIn++)
			{
				if (postorder[iPost] == inorder[iIn])
				{
					TreeNode *node = new TreeNode(postorder[iPost]);
					root->left = node;
					BuildLeft(node, postorder, inorder, sPost, iPost-1, sIn, iIn);
					BuildRight(node, postorder, inorder, sPost, iPost-1, iIn+1, eIn);
					return;
				}
			}
		}

	}
	void BuildRight(TreeNode *root, vector<int> &postorder, vector<int> &inorder,  int sPost, int ePost, int sIn, int eIn)
	{
		int iPost = ePost, iIn = eIn-1;

		for (; iPost>=sPost; iPost--)
		{
			for (iIn = eIn-1; iIn>=sIn; iIn--)
			{
				if (postorder[iPost] == inorder[iIn])
				{
					TreeNode *node = new TreeNode(postorder[iPost]);
					root->right = node;
					BuildLeft(node, postorder, inorder, sPost, iPost-1, sIn, iIn);
					BuildRight(node, postorder, inorder, sPost, iPost-1, iIn+1, eIn);
					return;
				}
			}
		}		
	}
};


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

void Fun(int &i)
{
	i = 32;
}

int main()
{
	int treeIn[] = {7, 40, 27, 1, 80, 79, 74};
	int treePost[] = {27, 40, 7, 74, 79, 80, 1};

	printf("solution:\n");

	vector<int> pre, in;
	pre.insert(pre.begin(), treeIn, treeIn+sizeof(treeIn)/sizeof(int));
	in.insert(in.begin(), treePost, treePost+sizeof(treePost)/sizeof(int));

	Solution s;
	TreeNode *root = s.buildTree(pre, in);

	Print(root);

	getchar();

	return 0;
}