/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

	1
   / \
  /   \
 0 --- 2
	  / \
	  \_/

*/



#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define COMMA 0xcdcdcdcd // to be different from label
#define SHARP 0xcececece

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

void Print(vector<int> vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		if (vec[i] == COMMA)
		{
			printf(", ");
		}
		else if(vec[i] == SHARP)
		{
			printf("# ");
		}
		else
		{
			printf("%d ", vec[i]);
		}
	}
	printf("\n");
}

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node)
		{
			return NULL;
		}
		vector<int> vec;
		Seriallization(node, vec);
	
        return Create(vec);
    }

	void Seriallization(UndirectedGraphNode *node, vector<int> &vec)
	{
		if (!node)
		{
			return;
		}
		
		set<UndirectedGraphNode *> s;
		queue<UndirectedGraphNode *> q;
		q.push(node);
		s.insert(node);
		UndirectedGraphNode *tmp;
		while(!q.empty())
		{
			tmp = q.front();
			q.pop();

			vec.push_back(tmp->label);
			for (int i=0; i<tmp->neighbors.size(); i++)
			{
				vec.push_back(COMMA);
				vec.push_back(tmp->neighbors[i]->label);
				if (s.find(tmp->neighbors[i]) == s.end())
				{
					s.insert(tmp->neighbors[i]);
					q.push(tmp->neighbors[i]);
				}
			}
			vec.push_back(SHARP);
		}
	}

	UndirectedGraphNode *Create(vector<int> vec)
	{
		UndirectedGraphNode *graph = NULL;
		UndirectedGraphNode *tmp = NULL, *node = NULL;
		bool bNode = true;
		map<int, UndirectedGraphNode*> m;

		for(int i=0; i<vec.size(); i++)
		{
			if (vec[i] == COMMA)
			{
				bNode = false;
			}
			else if(vec[i] == SHARP)
			{
				bNode = true;
			}
			else
			{
				if (m.find(vec[i]) == m.end())
				{
					tmp = new UndirectedGraphNode(vec[i]);
					m.insert(std::pair<int, UndirectedGraphNode*>(vec[i], tmp));
				}
				if (bNode)
				{
					if (!graph)
					{
						graph = m[vec[i]];
					}
					node = m[vec[i]];
				}
				else
				{
					node->neighbors.push_back(m[vec[i]]);
				}
			}
		}

		return graph;
	}

};


int main()
{
 	int buf[] = {0, COMMA, 1, COMMA, 5, SHARP, 1, COMMA, 2, COMMA, 5, SHARP, 2, COMMA, 3, SHARP, \
 	3, COMMA, 4, COMMA, 4, SHARP, 4, COMMA, 5, COMMA, 5, SHARP, 5};

	//int buf[] = {0, COMMA, 1, COMMA, 2, SHARP, 1, COMMA, 2, SHARP, 2, COMMA, 2};

	vector<int> vec(buf, buf + sizeof(buf)/sizeof(int));
	Print(vec);

	Solution solution;
	UndirectedGraphNode *graph = solution.Create(vec);

	UndirectedGraphNode *newGraph = solution.cloneGraph(graph);

	vec.clear();
	solution.Seriallization(newGraph, vec);
	Print(vec);

	system("pause");

	return 0;
}
