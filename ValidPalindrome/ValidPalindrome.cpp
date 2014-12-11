/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		Cut(s);
		return IsPalindrome(s);
	}

	void Cut(string &s)
	{
		string::iterator it = s.begin();
		for (; it!=s.end();)
		{
			if ((*it) >= 'A' && (*it) <= 'Z')
			{
				(*it) = 'a' + ((*it) - 'A');
			}
			else if((*it) >= '0' && (*it) <= '9')
			{

			}
			else if((*it) < 'a' || (*it) > 'z')
			{
				it = s.erase(it);
				continue;
			}
			++it;
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
	string s = "A man, a plan, a canal: Panama";

	Solution solution;

	if (solution.isPalindrome(s))
	{
		cout << "palindrome" << endl;
	}
	else
	{
		cout << "not palindrome" << endl;
	}

	system("pause");
	return 0;
}