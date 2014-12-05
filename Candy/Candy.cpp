/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
*/

/*
note :  be care for equal
example:
ratings:	1 2 2
candies:	1 2 1
not:		1 2 2

ratings:	1 2 2 3
candies:	1 2 1 2
not:		1 2 2 3
*/


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>

using namespace std;

void Create(vector<int> &vec, int n)
{
	int r, count = 0;
	for (int i=0; i<n; i++)
	{
		r = rand() % 10;
		vec.push_back(r);
	}
}

void Print(vector<int> &vec)
{
	int count = 0;
	for (int i=0; i<vec.size(); i++)
	{
		printf("%d ", vec[i]);
		if (++count % 16 ==0)
		{
			printf("\n");
		}
	}
	printf("\n");
}


class Solution
{
public:
	int candy(vector<int> &ratings)
	{
		int minimum = ratings.size();
		if (minimum < 2)
		{
			return minimum;
		}
		
		vector<int> rate;
		rate.resize(minimum);
		int weight = 0;
		bool ascending = false;

		for (int i=1; i<ratings.size(); i++)
		{
			if (ratings[i] > ratings[i-1])
			{
				ascending = true;
				minimum += ++weight;
			}
			else if(ratings[i] == ratings[i-1])
			{
				weight = 0;
			}
			else
			{
				rate[i-1] = weight;
				weight = 0;
				ascending = false;
			}
		}

		//reverse parse
		weight = 0;
		ascending = false;
		for (int i=ratings.size()-2; i >= 0; i--)
		{
			if (ratings[i] > ratings[i+1])
			{
				ascending = true;
				++weight;
				if (weight > 1)
				{
					minimum += (weight - 1);
				}
				if(i == 0)
				{
					minimum += weight;
				}
			}
			else if(ratings[i] == ratings[i+1])
			{
				if (weight > rate[i+1])
				{
					minimum += (weight - rate[i+1]);
				}
				weight = 0;
			}
			else
			{
 				if (weight > rate[i+1])
 				{
 					minimum += (weight - rate[i+1]);
 				}
				ascending = false;
				weight = 0;
			}
		}
		
		return minimum;
	}


	int candy2(vector<int> &ratings) {
		vector<int> candyCnt(ratings.size()) ;
		//allocate candies, considering the minimal rating on the left
		candyCnt[0] = 1;
		for(int i = 1; i < ratings.size(); i++){
			candyCnt[i] = ratings[i] > ratings[i-1] ? candyCnt[i-1]+1 : 1;
		}
		//modify the allocation, considering the minimal rating on the right
		int totalCandy = candyCnt[ratings.size()-1];
		for(int i = ratings.size()-2; i >= 0; i--){
			candyCnt[i] = (ratings[i] > ratings[i+1] && candyCnt[i+1]+1 > candyCnt[i]) ? candyCnt[i+1]+1 : candyCnt[i];
			//count total candies by the way
			totalCandy += candyCnt[i];
		}
		return totalCandy;
	}
};

int main()
{
	srand(GetTickCount());
	vector<int> vec;
	Create(vec, 30);
	Print(vec);

	Solution solution;
	printf("%d %d\n", solution.candy(vec), solution.candy2(vec));	

	system("pause");

	return 0;
}