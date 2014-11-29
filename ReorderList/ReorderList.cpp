/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>

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
	 for (int i=0; i<n ;i++)
	 {
		 ListNode *tmp = new ListNode(rand()%100);
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
	void reorderList(ListNode *head) 
	{
		if (!head)
		{
			return;
		}
		//find mid
		ListNode *mid;
		ListNode *node1=head;
		ListNode *node2=head;
		while(node2 && node2->next)
		{
			node1 = node1->next;
			node2 = node2->next->next;
		}
		mid = node1;
		if (head == mid)
		{
			return;
		}
		//reverse
		node1 = mid->next;
		mid->next = NULL;
		while(node1)
		{
			node2 = node1->next;
			node1->next = mid;
			mid = node1;
			node1 = node2;
			if (!node2)
			{
				break;
			}
			node2 = node2->next;
		}
		
		//merge
		node1 = head;
		node2 = head->next;
		ListNode *rev1 = mid;
		ListNode *rev2 = mid->next;
		while(node1 && rev1)
		{
			node1->next = rev1;
			rev1->next = node2;
			node1 = node2;
			rev1 = rev2;
			if (!node1->next)//odd
			{
				break;
			}
			if(!rev2)//even
			{
				node1->next = NULL;
				break;
			}
			node2 = node2->next;
			rev2 = rev2->next;
		}
	}

};

int main()
{
	srand(GetTickCount());
	ListNode *head = new ListNode(1);
	CreateList(&head, 9);
	Print(head);

	Solution solution;
	solution.reorderList(head);
	Print(head);

	system("pause");

	return 0;
}
