/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> result;
		vector<string> tmp;

		runWork(s, 0, tmp, result);
		
		return result;
	}
private:
	void runWork(string &s, int pos, vector<string> &one, vector<vector<string>> &result)
	{
		if (pos == s.size())
		{
			result.push_back(one);
			return;
		}
		for (int i=pos; i<s.size(); i++)
		{
			if (IsPalindrome(s.substr(pos, i-pos+1)))
			{
				one.push_back(s.substr(pos, i-pos+1));
				runWork(s, i+1, one, result);
				one.pop_back();
			}
		}
	}

	bool IsPalindrome(string &s)//param in leet code  should be : (string s)
	{
		int n = s.size();
		for (int i=0; i<n/2; i++)
		{
			if (s[i] != s[n-1-i])
			{
				return false;
			}
		}
		return true;
	}
};


int main()
{
	vector<vector<string>> vec;

	Solution solution;
	vec = solution.partition("aab");
	
	for (int i=0; i<vec.size(); i++)
	{
		for (int j=0; j<vec[i].size(); j++)
		{
			cout << vec[i][j] << ",";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}
