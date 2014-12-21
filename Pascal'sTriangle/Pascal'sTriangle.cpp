/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
	   [1],
	  [1,1],
	 [1,2,1],
	[1,3,3,1],
   [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> triangle;
		if (numRows <= 0)
		{
			return triangle;
		}

		vector<int> vec;
		triangle.resize(numRows);
		vec.resize(1);
		vec[0] = 1;
		triangle[0] = vec;

		for (int i=1; i<numRows; i++)
		{
			vec.resize(i+1);
			vec[i] = 1;
			for (int j=1; j<i; j++)
			{
				vec[j] = triangle[i-1][j-1] + triangle[i-1][j];
			}
			triangle[i] = vec;
		}

		return triangle;
	}
};

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
	vector<vector<int>> vec;
	Solution solution;
	vec = solution.generate(2);

	Print(vec);
	system("pause");
	return 0;
}