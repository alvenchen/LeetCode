/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list. 
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *node = head;
		ListNode *startPrev = NULL, *start = NULL;
		int i=1;
		while(node && i<m)
		{
			startPrev = node;
			node = node->next;
			i++;
		}
		start = node;
		ListNode *next = node->next;;
		ListNode *tmp = next;
		i=0;
		while(i++ < n - m)
		{
			tmp = next->next;
			next->next = node;
			node = next;
			next = tmp;
		}
		start->next = next;
		if (startPrev)
		{
			startPrev->next = node;
		}
		else
		{
			head = node;
		}

		return head;
    }
};

ListNode *Create(int n)
{
	ListNode *head = new ListNode(1);
	ListNode *node = head;
	for (int i=1; i<n; i++)
	{
		node->next = new ListNode(i+1);
		node = node->next;
	}
	return head;
}

void Print(ListNode *head)
{
	while(head)
	{
		std::cout<<head->val<<" ";
		head = head->next;
	}
}

int main()
{
	ListNode *head = Create(10);
	Solution s;
	head = s.reverseBetween(head, 1, 5);
	Print(head);

	getchar();
	return 0;
}