/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <Windows.h>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (!head)
		{
			return NULL;
		}
		vector<TreeNode *> vec;
		ListNode *lsNode = head, *lsHead = head, *lsTail = head;
		TreeNode *trNode = NULL;

		while(lsNode)
		{
			trNode = new TreeNode(lsNode->val);
			vec.push_back(trNode);
			lsTail = lsNode;
			lsNode = lsNode->next;
		}
		int trHead = 0, trTail = vec.size()-1;
	
		run(lsHead, lsTail, trHead, trTail, vec, true);

		if (vec.size() > 1)
		{
			vec[trHead+1]->left = vec[trHead];
		}
		if (vec.size() > 2)
		{
			vec[trTail-1]->right = vec[trTail];
		}

		return vec[(trTail+trHead+1) / 2];
	}
	TreeNode* run(ListNode *head, ListNode *tail, int trHead, int trTail, vector<TreeNode*> &vec, bool bLatter)
	{
		ListNode *lsMiddle;
		TreeNode *trNode = NULL;
		int trMiddle;
		if (!bLatter)
		{
			trMiddle = (trHead+trTail)/2;
			lsMiddle = GetMiddle(head, tail, false);
		}
		else
		{
			trMiddle = (trHead+trTail+1)/2;
			if ((trHead+trTail) % 2 != 0)
			{
				lsMiddle = GetMiddle(head, tail, true);
			}
			else
			{
				lsMiddle = GetMiddle(head, tail, false);
			}
		}
		if (lsMiddle)
		{
			trNode = vec[trMiddle];
			if ((trMiddle - trHead) % 2 == 0)
			{
				trNode->left = run(head, lsMiddle, trHead, trMiddle, vec, true);
			}
			else
			{
				trNode->left = run(head, lsMiddle, trHead, trMiddle, vec, false);
			}
			
			if ((trTail - trMiddle) % 2 == 0)
			{
				trNode->right = run(lsMiddle, tail, trMiddle, trTail, vec, false);
			}
			else
			{
				trNode->right = run(lsMiddle, tail, trMiddle, trTail, vec, true);
			}			
		}
		return trNode;
	}

	ListNode *GetMiddle(ListNode *head, ListNode *tail, bool bLatter)
	{
		if(head == tail || head->next == tail)
		{
			return NULL;
		}
		ListNode *middle=head, *tmp=head;
		while(tmp!=tail && tmp->next!=tail)
		{
			middle = middle->next;
			tmp = tmp->next->next;
		}
		if (bLatter && middle->next != tail)
		{
			middle = middle->next;
		}
		return middle;
	}
};

void Creat(ListNode **node, int n)
{
	vector<ListNode*> vec;
	ListNode *tmp;

	for (int i=0; i<n; i++)
	{
		tmp = new ListNode(i);
		vec.push_back(tmp);
	}
	for (int i=0; i<n-1; i++)
	{
		vec[i]->next = vec[i+1];
	}

	*node = vec[0];
}

int main()
{
	ListNode *head = NULL;
	Creat(&head, 1);

	Solution s;
	TreeNode *root = s.sortedListToBST(head);

	return 0;
}