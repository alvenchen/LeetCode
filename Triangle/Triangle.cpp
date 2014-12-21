/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
   [2],
  [3,4],
 [6,5,7],
[4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
*/

#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minimumTotal(vector<vector<int> > &triangle)
	{
		int n = triangle.size();
		if (n == 0)
		{
			return 0;
		}
		int cmp1, cmp2;
		vector<int> recordMin, recordTmp;
		recordMin.resize(triangle.size());
		recordTmp.resize(triangle.size());
		recordMin[0] = triangle[0][0];
		for(int i=1; i<triangle.size(); i++)
		{
			for (int j=1; j<i; j++)
			{
				cmp1 = recordMin[j-1] + triangle[i][j];
				cmp2 = recordMin[j] + triangle[i][j];
				recordTmp[j] = min(cmp1, cmp2);
			}
			recordTmp[0] = recordMin[0] + triangle[i][0];
			recordTmp[i] = recordMin[i-1] + triangle[i][i];
			recordMin = recordTmp;
		}

		int minimum = 0x7fffffff;
		for (int i=0; i<recordMin.size(); i++)
		{
			if (minimum > recordMin[i])
			{
				minimum = recordMin[i];
			}
		}

		return minimum;
	}
};

void Create(vector<vector<int>> &triangle, int n)
{
	for(int i=0; i<n; i++)
	{
		vector<int> vec;
		for (int j=0; j<=i; j++)
		{
			vec.push_back(rand()%10);
		}
		triangle.push_back(vec);
	}
}

void Print(vector<vector<int>> &triangle)
{
	for (int i=0 ;i<triangle.size(); i++)
	{
		for (int k=0; k<triangle.size()-i; k++)
		{
			cout<<" ";
		}
		for (int j=0; j<=i; j++)
		{
			cout<<triangle[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	srand(GetTickCount());
 	vector<vector<int>> triangle;
	Create(triangle, 5);
	Print(triangle);
	Solution solution;
	cout<<solution.minimumTotal(triangle);

	system("pause");
	return 0;
}