/*

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
		printf("cycle node : %d\n", cycle->val);
		tmp->next = cycle;
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
    ListNode *detectCycle(ListNode *head) 
	{
		if (!head || !head->next)
		{
			return NULL;
		}
		ListNode *iter1 = head;
		ListNode *iter2 = head->next;
		ListNode *cycle = NULL;
		while(iter2 && iter2->next)
		{
			if (iter1 == iter2)
			{
				cycle = iter1;
				break;
			}
			iter1 = iter1->next;
			iter2 = iter2->next->next;
		}
		if (cycle)
		{
			int cycleLen = 1;
			iter1 = cycle->next;
			while(iter1 != cycle)
			{
				iter1 = iter1->next;
				cycleLen++;
			}

			bool bFind = false;
			while(!bFind)
			{
				int lenGuard = cycleLen;
				iter1 = head;
				iter2 = head->next;
				while(lenGuard-- >= 0)
				{
					if (iter1 == iter2)
					{
						bFind = true;
						break;
					}
					iter2 = iter2->next;
				}				
				head = head->next;
			}
			return iter1;
		}

		return NULL;
    }
};

int main()
{
	srand(GetTickCount());

	ListNode *head = new ListNode(0);
	CreateList(&head, 10);

	Solution soluton;
	ListNode *pos = soluton.detectCycle(head);
	if (!pos)
	{
		printf("NULL");
	}
	printf("%d", pos->val);

	system("pause");

	return 0;
}