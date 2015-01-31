/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
	[2],
	[1],
	[1,2,2],
	[2,2],
	[1,2],
	[]
]

*/

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		int n = S.size();
		sort(S.begin(), S.end());

		set<vector<int>> sV;
		int iter = 0;
		SubSet(sV, S, iter);

		vector<vector<int>> ret;
		vector<int> tmp;
		ret.push_back(tmp);
		for (set<vector<int>>::iterator it=sV.begin(); it!=sV.end(); ++it)
		{
			ret.push_back((*it));
		}
		
		return ret;
	}

	void SubSet(set<vector<int>> &sV, vector<int> &s, int &n)
	{
		if (n >= s.size())
		{
			return;
		}
		vector<int> tmp;
		set<vector<int>> add;
		for (set<vector<int>>::iterator it=sV.begin(); it!=sV.end(); ++it)
		{
			tmp.clear();
			tmp = *it;
			tmp.push_back(s[n]);
			add.insert(tmp);
		}
		tmp.clear();
		tmp.push_back(s[n]);
		add.insert(tmp);
		sV.insert(add.begin(), add.end());
		SubSet(sV, s, ++n);
	}
};

int main()
{
	int vec[] = {4, 1, 0};
	vector<int> v;
	v.insert(v.begin(), vec, vec+sizeof(vec)/sizeof(int));
	Solution s;
	s.subsetsWithDup(v);

	return 0;
}