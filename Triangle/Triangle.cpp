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
			vec.push_back(rand()%10 - 5);
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

	int v1[] = {-7};
	int v2[] = {-2, 1};
	int v3[] = {-5,-5,9};
	int v4[]={-4,-5,4,4};
	int v5[]={-6,-6,2,-1,-5};
	int v6[]={3,7,8,-3,7,-9};
	int v7[]={-9,-1,-9,6,9,0,7};
	int v8[]={-7,0,-6,-8,7,1,-4,9};
	int v9[]={-3,2,-6,-9,-7,-6,-9,4,0};
	int v10[]={-8,-6,-3,-9,-2,-6,7,-5,0,7};
	int v11[]={-9,-1,-2,4,-2,4,4,-1,2,-5,5};
	int v12[]={1,1,-6,1,-2,-4,4,-2,6,-6,0,6};
	int v13[]={-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1};

	srand(GetTickCount());
 	vector<vector<int>> triangle;
 	triangle.push_back(vector<int>(v1, v1+sizeof(v1)/sizeof(int)));
	triangle.push_back(vector<int>(v2, v2+sizeof(v2)/sizeof(int)));
	triangle.push_back(vector<int>(v3, v3+sizeof(v3)/sizeof(int)));
	triangle.push_back(vector<int>(v4, v4+sizeof(v4)/sizeof(int)));
	triangle.push_back(vector<int>(v5, v5+sizeof(v5)/sizeof(int)));
	triangle.push_back(vector<int>(v6, v6+sizeof(v6)/sizeof(int)));
	triangle.push_back(vector<int>(v7, v7+sizeof(v7)/sizeof(int)));
	triangle.push_back(vector<int>(v8, v8+sizeof(v8)/sizeof(int)));
	triangle.push_back(vector<int>(v9, v9+sizeof(v9)/sizeof(int)));
	triangle.push_back(vector<int>(v10, v10+sizeof(v10)/sizeof(int)));
	triangle.push_back(vector<int>(v11, v11+sizeof(v11)/sizeof(int)));
	triangle.push_back(vector<int>(v12, v12+sizeof(v12)/sizeof(int)));
	triangle.push_back(vector<int>(v13, v13+sizeof(v13)/sizeof(int)));

	//Create(triangle, 4);
	Print(triangle);
	Solution solution;
	cout<<solution.minimumTotal(triangle);

	system("pause");
	return 0;
}