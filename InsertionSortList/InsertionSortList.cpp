//Sort a linked list using insertion sort.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct ListNode 
{
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *insertionSortList(ListNode *head) 
{
	if (!head)
	{
		return head;
	}

	ListNode *p = head->next;
	ListNode *prev = head;
	ListNode *curr = head;
	curr->next = NULL;
	ListNode *tmp;
	
	while(p)
	{
		prev = curr = head;
		while(curr)
		{
			if (p->val < curr->val)
			{
				if (curr == head)
				{
					tmp = p;
					p = p->next;
					tmp->next = curr;
					curr = tmp;
					head = curr;
					prev = curr;
				}
				else
				{
					tmp = p;
					p = p->next;
					prev->next = tmp;
					tmp->next = curr;
				}
				break;
			}
			else
			{
				if (prev != curr)
				{
					prev = prev->next;
				}
				curr = curr->next;
			}
		}

		if (!curr)
		{
			tmp = p;
			p = p->next;
			prev->next = tmp;
			tmp->next = NULL;
		}
	}

	return head;
}


ListNode * CreatList(ListNode *head, int size)
{
	for (int i=0; i< size; i++)
	{
		ListNode *p = new ListNode(rand() % (size * 2));
		p->next = head;
		head = p;
	}

	return head;
}

void PrintList(ListNode *head)
{
	int i = 0;
	ListNode *p = head;

	while(p)
	{
		printf("%d ", p->val);
		if (++i % 16 == 0)
		{
			printf("\n");
		}
		p = p->next;
	}
}

int main()
{
	srand(GetTickCount());

	ListNode *head = NULL;

	head = CreatList(head, 10);
	PrintList(head);
	
	printf("after :\n");
	head = insertionSortList(head);
	PrintList(head);

	system("pause");

	return 0;
}