/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> row, tmp;
		row.resize(rowIndex+1);
		tmp.resize(1);
		row[0] = 1;
		row[rowIndex] = 1;
		tmp[0] = 1;
		for (int i=1; i<rowIndex+1; i++)
		{
			tmp.resize(i+1);
			tmp[i] = 1;
			for (int j=1; j<i; j++)
			{
				tmp[j] = row[j-1] + row[j];
			}
			row = tmp;
		}

		return row;
	}
};

void Print(vector<int> &vec)
{
	for (int i=0 ;i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> vec;
	Solution solution;
	vec = solution.getRow(3);
	Print(vec);
	system("pause");
	return 0;
}
