/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

*/
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
		if (!root)
		{
			return;
		}
		vector<TreeNode*> vec;
		Save(root, vec);

		for (int i=0; i<vec.size()-1; i++)
		{
			vec[i]->left = NULL;
			vec[i]->right = vec[i+1];
		}
    }
	void Save(TreeNode *root, vector<TreeNode*>&vec)
	{
		if (!root)
		{
			return;
		}
		vec.push_back(root);
		Save(root->left, vec);
		Save(root->right, vec);
	}
};

int main()
{

	return 0;
}