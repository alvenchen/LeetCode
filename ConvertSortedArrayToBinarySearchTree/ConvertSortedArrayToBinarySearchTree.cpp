/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		
		TreeNode *node  = build(num, 0, num.size()-1);

		return node;
	}
	TreeNode *build(vector<int> &num, int begin, int end)
	{
		if (begin > end)
		{
			return NULL;
		}
		int middle = (begin + end) / 2;
		TreeNode *node = new TreeNode(num[middle]);
		node->left = build(num, begin, middle-1);
		node->right = build(num, middle+1, end);

		return node;
	}

};


void Creat(vector<int> &vec, int n)
{
	for (int i=0; i<n; i++)
	{
		vec.push_back(i);
	}
}

int main()
{
	vector<int> vec;
	Creat(vec, 6);

	Solution s;
	TreeNode *root = s.sortedArrayToBST(vec);

	return 0;
}