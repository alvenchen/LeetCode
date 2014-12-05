/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>

using namespace std;


class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int n = gas.size();
		if (n < 2)
		{
			if (gas[0] < cost[0])
			{
				return -1;
			}
			return 0;
		}
		int startPos = 0, endPos;
		int gasSurplus = 0, costSurp = 0;;

		for (int i=0; i<n; i++, startPos++)
		{
			gasSurplus = 0;
			costSurp = 0;
			if (startPos > 0)
			{
				endPos = startPos - 1;
			}
			else
			{
				endPos = n - 1;
			}

			int j=0, iterStart = startPos, iterEnd = endPos;
			bool Find = true;
			for (; j<n/2; j++)
			{
				if (startPos + j >= n)
				{
					iterStart = startPos + j - n;
				}
				else
				{
					iterStart = startPos + j;
				}
				if (endPos - j < 0)
				{
					iterEnd = n + endPos - j;
				}
				else
				{
					iterEnd = endPos - j;
				}

				gasSurplus += (gas[iterStart] - cost[iterStart]);
				if (gasSurplus < 0)
				{
					Find = false;
					break;
				}
				costSurp += (cost[iterEnd] - gas[iterEnd]);
				if (costSurp < 0)
				{
					Find = false;
					break;
				}
			}
			if (Find)
			{
				if (n % 2 != 0)
				{
					int pos = iterStart + 1;
					if (pos >= n)
					{
						pos = 0;
					}
					if (gasSurplus + gas[pos] - cost[pos] >= costSurp)
					{
						return i;
					}
				}
				else if (gasSurplus >= costSurp)
				{
					return i;
				}
			}
		}

		return -1;
	}
};

int main()
{
	srand(GetTickCount());
	
	vector<int> gas, cost;
	gas.push_back(5);
 	gas.push_back(3);
 	gas.push_back(1);
 	gas.push_back(4);
 	gas.push_back(2);

	cost.push_back(6);
 	cost.push_back(3);
 	cost.push_back(2);
 	cost.push_back(3);
 	cost.push_back(1);

	Solution solution;
	printf("%d\n", solution.canCompleteCircuit(gas, cost));

	system("pause");
	return 0;
}