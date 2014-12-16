/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int maxProfit = 0;
		int currBuy = 0x80000000;

		if (prices.size() < 2)
		{
			return 0;
		}

		for (int i=0; i<prices.size() - 1; i++)
		{
			if (currBuy == 0x80000000)
			{
				if (prices[i+1] > prices[i])
				{
					currBuy = prices[i];
				}
			}
			else
			{
				if (prices[i] > currBuy)
				{
					maxProfit += prices[i] - currBuy;
					if (prices[i+1] > prices[i])
					{
						currBuy = prices[i];
					}
					else
					{
						currBuy = 0x80000000;
					}
				}
			}
		}
		if (currBuy != 0x80000000)
		{
			if (prices[prices.size()-1] > currBuy)
			{
				maxProfit += prices[prices.size()-1] - currBuy;
			}
		}

		return maxProfit;
	}
};

void Create(vector<int> &vec, int n)
{
	int r;
	for (int i=0; i<n; i++)
	{
		r = rand() % 10;
		vec.push_back(r);
	}
}

void Print(vector<int> &vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	srand(GetTickCount());

	vector<int> vec;

	Create(vec, 10);
	Print(vec);

	Solution solution;

	cout<<solution.maxProfit(vec);
	system("pause");

	return 0;
}