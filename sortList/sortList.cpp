//Sort a linked list in O(n log n) time using constant space complexity.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
void PrintList(ListNode* h);

 //merged two sorted list, ascending
ListNode *MergeList(ListNode* p1, ListNode* p2)
{
	ListNode *head = NULL, *tmp = NULL;

	while(p1 && p2)
	{
		if (p1->val < p2->val)
		{
			if (!head)
			{
				head = p1;
				tmp = head;
			}
			else
			{
				tmp->next = p1;
				tmp = tmp->next;
			}
			p1 = p1->next;
		}
		else
		{
			if (!head)
			{
				head = p2;
				tmp = head;
			}
			else
			{
				tmp->next = p2;
				tmp = tmp->next;
			}
			p2 = p2->next;
		}
	}

	if (tmp)
	{
		if (p1)
		{
			tmp->next = p1;
		}
		else if (p2)
		{
			tmp->next = p2;
		}
	}

	return head;
}

ListNode *SplitList(ListNode* head)
{
	ListNode *p1, *p2;
	p1 = head;
	p2 = head->next;
	while(p2 && p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	p2 = p1->next;
	p1->next = NULL;

	return p2;//right part of the list
}

ListNode *SortList(ListNode* head)
{
	if(head && head->next)
	{
		ListNode *head2 = SplitList(head);
		return MergeList(SortList(head), SortList(head2));
	}
	else
	{
		return head;
	}
}

void PrintList(ListNode* h)
{
	while(h!=NULL)
	{
		printf("%d ", h->val);
		h = h->next;
	}
	printf("\n");
}

ListNode* CreateList(int a[], int n)
{
	ListNode *head=NULL, *p=NULL;
	for(int i=0; i<n; i++)
	{
		if (head == NULL)
		{
			head = p = new ListNode(a[i]);
		}
		else
		{
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}


int main()
{
	srand(time(NULL));
	int n = 10;
	int *a = new int[n];

	for(int i=0; i<n; i++)
	{
		a[i] = rand()%(2*n) + 1;
	}
	ListNode *p = CreateList(a, n);
	PrintList(p);
	PrintList(SortList(p));
	delete[] a;

	system("pause");

	return 0;
}