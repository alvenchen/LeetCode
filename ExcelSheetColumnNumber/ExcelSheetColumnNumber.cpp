/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
*/

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int ret = 0;
		
		for (int i=0 ;i<s.size(); i++)
		{
			ret *= 26;
			ret += s[i] - 'A' + 1;
		}

		return ret;
	}
};

int main()
{
	srand(GetTickCount());

	Solution solution;
	string s = "GIGD";
	cout << s.c_str() << ":" << solution.titleToNumber(s);

	system("pause");

	return 0;
}