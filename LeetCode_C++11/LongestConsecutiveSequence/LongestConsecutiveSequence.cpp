// /*
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// 
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
// 
// Your algorithm should run in O(n) complexity. 
// */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &num)
	{
		if (num.empty())
		{
			return 0;
		}
		unordered_set<int> s;
		for (int i=0; i<num.size(); i++)
		{
			s.insert(num[i]);
		}
		
		int cmp, tmp, currLongest, longest = 1;
		while (!s.empty())
		{
			currLongest = 0;
			cmp = (*s.begin());
			tmp = cmp;

			s.erase(cmp);
			while (s.count(++tmp) > 0)
			{
				s.erase(tmp);
			}
			currLongest += (tmp - cmp);

			tmp = cmp;
			while (s.count(--tmp) > 0)
			{
				s.erase(tmp);
			}
			currLongest += (cmp - tmp- 1);

			if (currLongest > longest)
			{
				longest = currLongest;
			}
		}
		
		return longest;
	}
};

int main()
{

	vector<int> vec;
	vec.push_back(-1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(3);

	Solution solution;

	cout << solution.longestConsecutive(vec) <<endl;

	system("pause");

	return 0;
}


