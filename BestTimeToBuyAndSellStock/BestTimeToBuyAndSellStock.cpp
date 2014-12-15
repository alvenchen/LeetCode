/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
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
		int currMin, currMax;
		int maxProfit = 0;

		if (prices.size() < 2)
		{
			return 0;
		}
		currMin = currMax = prices[0];
		for (int i=1; i<prices.size(); i++)
		{
			if (prices[i] < currMin)
			{
				currMax = currMin = prices[i]; 
			}
			else if(prices[i] > currMax)
			{
				currMax = prices[i];
				if(currMax - currMin > maxProfit)
				{
					maxProfit = currMax - currMin;
				}
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