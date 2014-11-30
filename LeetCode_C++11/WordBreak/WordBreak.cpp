/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
	bool wordBreak(string s, unordered_set<string> &dict) 
	{
		int cmpLen = s.length();
		int cmpPos = s.length();
		string tmp;
		bool ret = false;
		unordered_set<string> dictCp = dict;

		while (cmpLen > 0 && !ret)
		{
			if (dictCp.end() != dictCp.find(s.substr(0, cmpLen)))//cmp begin with longest pre-substring
			{
				//dictCp.erase(s.substr(0, cmpLen));//allow repeat
				cmpPos = cmpLen;
				int subCmpLen = s.length() - cmpPos;
				if (subCmpLen == 0)
				{
					ret = true;
					break;
				}
				while (subCmpLen > 0)
				{
					if (dictCp.end() != dictCp.find(s.substr(cmpPos, subCmpLen)))
					{
						if (cmpPos + subCmpLen == s.length())
						{
							ret = true;
							break;
						}
						else
						{
							cmpPos += subCmpLen;
							subCmpLen = s.length() - cmpPos;
						}
					}
					else
					{
						subCmpLen--;
					}
				}
				cmpLen--;
				dictCp = dict;
			}
			else
			{
				cmpLen--;
			}
		}
		return ret;
	}
};

int main()
{
	unordered_set<string> set;
	set.emplace("bbb");
	set.emplace("b");
	set.emplace("a");
	set.emplace("bbbb");

	Solution solution;
	cout << solution.wordBreak("bb", set);

	system("pause");
	return 0;
}