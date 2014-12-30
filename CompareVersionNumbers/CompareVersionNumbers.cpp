/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		int pos1=0, pos2=0;
		int v1, v2;
		while(1)
		{

			v1 = GetValue(version1, pos1);
			v2 = GetValue(version2, pos2);
			if (v1<0 && v2<0)
			{
				break;
			}
			else if (v1<0)
			{
				if(v2 != 0)
				{
					return -1;
				}
			}
			else if(v2 < 0)
			{
				if (v1 != 0)
				{
					return 1;
				}
			}
			else if (v1 < v2)
			{
				return -1;
			}
			else if (v1 > v2)
			{
				return 1;
			}
		}

		return 0;
	}

	int GetValue(string &s, int &pos)
	{
		if(pos == s.size())
		{
			return -1;
		}
		int i=pos;
		int ret = -1;
		for (; i<s.size(); i++)
		{
			if (s[i] == '.')
			{
				ret = atoi(s.substr(pos, i-pos).c_str());
				pos = i+1;
				return ret;
			}
		}
		if (i == s.size())
		{
			ret = atoi(s.substr(pos, i-pos).c_str());
			pos = s.size();
		}

		return ret;
	}
};

int main()
{
	string a="1.0.0", b="1.0.0.0.0";
	Solution s;

	cout << s.compareVersion(a, b);

	system("pause");

	return 0;
}