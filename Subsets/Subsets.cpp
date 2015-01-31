/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
	[3],
	[1],
	[2],
	[1,2,3],
	[1,3],
	[2,3],
	[1,2],
	[]
]


*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		int n = S.size();
		sort(S.begin(), S.end());

		vector<vector<int>> ret;
		int iter = 0;
		SubSet(ret, S, iter);
		vector<int> tmp;
		ret.push_back(tmp);

		return ret;
	}

	void SubSet(vector<vector<int>> &vec, vector<int> &s, int &n)
	{
		if (n >= s.size())
		{
			return;
		}
		vector<int> tmp;
		vector<vector<int>> add;
		for (int i=0; i<vec.size(); i++)
		{
			tmp.clear();
			tmp = vec[i];
			tmp.push_back(s[n]);
			add.push_back(tmp);
		}
		tmp.clear();
		tmp.push_back(s[n]);
		add.push_back(tmp);
		for (int i=0; i<add.size(); i++)
		{
			vec.push_back(add[i]);
		}
		SubSet(vec, s, ++n);
	}
};

int main()
{
	int vec[] = {4, 1, 0};
	vector<int> v;
	v.insert(v.begin(), vec, vec+sizeof(vec)/sizeof(int));
	Solution s;
	s.subsets(v);

	return 0;
}