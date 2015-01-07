/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 ¡ú a2
					¨K
					c1 ¡ú c2 ¡ú c3
					¨J            
B:     b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

#include <iostream>
#include <Windows.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void CreateList(ListNode **head, int n)
{
	ListNode *node = *head;
	ListNode *tmp = NULL;

	for (int i=0; i<n ;i++)
	{
		tmp = new ListNode(rand()%100);
		node->next = tmp;
		node = node->next;
	}
}

void Print(ListNode *head)
{
	ListNode *node = head;
	while(node)
	{
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}


class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
        int n1 = 0, n2 = 0, n = 0;
		n1 = GetLen(headA);
		n2 = GetLen(headB);

		ListNode *nodeShort, *nodeLong;
		ListNode *ret = NULL;
		int iShort, iLong;
		if (n1 > n2)
		{
			iShort = n2;
			nodeShort = headB;
			iLong = n1;
			nodeLong = headA;
		}
		else
		{
			iShort = n1;
			nodeShort = headA;
			iLong = n2;
			nodeLong = headB;
		}

		for (int i=0; i<iLong-iShort; i++)
		{
			nodeLong = nodeLong->next;
		}

		for (int i=0; i<iShort; i++)
		{
			if (nodeLong == nodeShort)
			{
				ret = nodeShort;
				break;
			}
			nodeLong = nodeLong->next;
			nodeShort = nodeShort->next;
		}

		return ret;
    }

	int GetLen(ListNode *head)
	{
		ListNode *tmp = head;
		int n = 0;
		tmp = head;
		while(tmp && tmp->next)
		{
			n += 2;
			tmp = tmp->next->next;
		}
		if (tmp && !tmp->next)
		{
			n += 1;
		}
		return n;
	}
};


int main()
{
	srand(GetTickCount());

	ListNode *headA = new ListNode(0);
	CreateList(&headA, 4);
	Print(headA);

	ListNode *headB = new ListNode(0);
	CreateList(&headB, 13);
	
	ListNode *tmp = headB;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = headA->next;
	Print(headB);

	Solution s;

	cout<<s.getIntersectionNode(headA, headB)->val;

	return 0;
}