/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
*/

/**
 * Definition for singly-linked list.
 */

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>


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
	 int cyclePos = rand() % n;
	 ListNode *cycle;
	 for (int i=0; i<n ;i++)
	 {
		 tmp = new ListNode(rand()%100);
		 node->next = tmp;
		 node = node->next;

		if (i == cyclePos)
		{
			cycle = tmp;
		}
	 }

	 if (n > 0)
	 {
		 tmp->next = cycle;
	 }
 }

class Solution 
{
public:
	bool hasCycle(ListNode *head) 
	{
		if (!head || !head->next)
		{
			return false;
		}
		ListNode *iter1 = head;
		ListNode *iter2 = head->next;
		while(iter2 && iter2->next)
		{
			if (iter1 == iter2)
			{
				return true;
			}
			iter1 = iter1->next;
			iter2 = iter2->next->next;
		}

		return false;
	}
};

int main()
{
	srand(GetTickCount());

	ListNode *head = new ListNode(0);
	CreateList(&head, 10);
	
	Solution soluton;
	printf("%d", soluton.hasCycle(head));

	system("pause");

	return 0;
}