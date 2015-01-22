/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 
*/

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
		queue<TreeNode*> queueP, queueQ;
		TreeNode *nodeP, *nodeQ;
		bool bSame = true;
		if (p)
		{
			queueP.push(p);
		}
		if (q)
		{
			queueQ.push(q);
		}

		int idP = 0, idQ = 0;
		while(!queueQ.empty() && !queueP.empty())
		{
			idP = 0;
			idQ = 0;
			nodeP = queueP.front();
			queueP.pop();
			if (nodeP->left)
			{
				queueP.push(nodeP->left);
				idP |= 1;
			}
			if (nodeP->right)
			{
				queueP.push(nodeP->right);
				idP |= 2;
			}

			nodeQ = queueQ.front();
			queueQ.pop();
			if (nodeQ->left)
			{
				queueQ.push(nodeQ->left);
				idQ |= 1;
			}
			if (nodeQ->right)
			{
				queueQ.push(nodeQ->right);
				idQ |= 2;
			}

			if (idP != idQ || nodeP->val != nodeQ->val)
			{
				bSame = false;
				break;
			}
		}
		if (!queueQ.empty() || !queueP.empty())
		{
			bSame = false;
		}

		return bSame;
    }

};


int main()
{


	return 0;
}