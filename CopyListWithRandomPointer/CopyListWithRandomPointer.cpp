/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <map>

using namespace std;

struct RandomListNode 
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 

RandomListNode* CreatList(int n)
{
	RandomListNode *head = NULL;
	RandomListNode *node, *tmp;
	vector<RandomListNode *> vec;
	for (int i=0; i<n; i++)
	{
		tmp = new RandomListNode(rand() % 100);
		if (!head)
		{
			head = tmp;
			node = head;
		}
		else
		{
			node->next = tmp;
			node = node->next;
		}
		vec.push_back(tmp);
	}
	int r;
	for (int i=0; i<n; i++)
	{
		r = rand() % (n+1);
		if (r != n)
		{
			vec[i]->random = vec[r];
		}
	}

	return head;
}

void PrintList(RandomListNode *head)
{
	RandomListNode *node = head;
	while(node)
	{
		if (node->random)
		{
			printf("[%d  %d]\n", node->label, node->random->label);
		}
		else
		{
			printf("[%d  NUll]\n", node->label);
		}
		node = node->next;
	}
}

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode *headCopy = NULL;
		RandomListNode *tmp, *nodeCopy;
		map<RandomListNode *, RandomListNode *> mapSrc, mapTmp;
		
		RandomListNode *nodeSrc = head;
		while(nodeSrc)
		{
			mapSrc.insert(std::pair<RandomListNode*, RandomListNode*>(nodeSrc, NULL));
			nodeSrc = nodeSrc->next;
		}

		nodeSrc = head;
		while(nodeSrc)//map : node-->random
		{
			if (nodeSrc->random)
			{
				mapSrc[nodeSrc] = nodeSrc->random;
			}
			nodeSrc = nodeSrc->next;
		}
	
		nodeSrc = head;
		while(nodeSrc)
		{
			tmp = new RandomListNode(nodeSrc->label);
			if (!headCopy)
			{
				headCopy = tmp;
				nodeCopy = tmp;
			}
			else
			{
				nodeCopy->next = tmp;
				nodeCopy = nodeCopy->next;
			}
			nodeSrc = nodeSrc->next;
		}

		nodeCopy = headCopy;
		nodeSrc = head;
		while(nodeSrc)//map : nodeSrc-->nodeCpy
		{
			mapTmp.insert(std::pair<RandomListNode *, RandomListNode *>(nodeSrc, nodeCopy));
			nodeSrc = nodeSrc->next;
			nodeCopy = nodeCopy->next;
		}

		map<RandomListNode *, RandomListNode *>::iterator it = mapSrc.begin();
		for(; it!=mapSrc.end(); ++it)//create Copy's random
		{
			if (it->second)//random
			{
				mapTmp[it->first]->random = mapTmp[it->second];
			}
		}

		return headCopy;
    }
};


int main()
{
	srand(GetTickCount());

	RandomListNode* head = CreatList(10);
	PrintList(head);

	Solution solution;
	RandomListNode *copy = solution.copyRandomList(head);

	printf("\ncopy:\n");

	PrintList(copy);
	system("pause");

	return 0;
}