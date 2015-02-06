/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
		{
			return 0;
		}
		if (s.size()==1)
		{
			return (IsDigit(s[0]) && s[0]!='0') ? 1 : 0;
		}

		int last2 = (IsDigit(s[0]) && s[0]!='0') ? 1 : 0;
		int last1 = 0;
		if (s[1] == '0')
		{
			if (CouldMerge(s[0], s[1]))
			{
				last1 = 1;
			}
			else
			{
				last1 = 0;
			}
		}
		else
		{
			last1 = last2 + CouldMerge(s[0], s[1]);
		}
		int sum = last1;
		Calc(last2, last1, sum, 2, s);

		return sum;
	}

	void Calc(int &last2, int &last1, int &sum, int pos, string &s)
	{
		if (pos >= s.size() )
		{
			return;
		}
		if (!IsDigit(s[pos]) || s[pos-1] == '0' && s[pos] == '0')//case for  "100":sum==0
		{
			sum = 0;
			return;
		}
		if (s[pos] != '0')
		{
			sum = last1;
		}
		else
		{
			sum = 0;
		}
		
		if (CouldMerge(s[pos-1], s[pos]))
		{
			sum += last2;
		}

		if (sum == 0)
		{
			last2 = 0;
			last1 = 0;
		}
		else
		{
			last2 = last1;
			last1 = sum;
		}


		Calc(last2, last1, sum, ++pos, s);
	}

	bool IsDigit(char c)
	{
		return c >= '0' && c <= '9';
	}

	bool CouldMerge(char a, char b)
	{
		if (a == '1' || (a == '2') && b <= '6')
		{
			return true;
		}
		return false;
	}
};

int main()
{
	string str = "301";

	Solution s;
	s.numDecodings(str);

	getchar();

	return 0;
}