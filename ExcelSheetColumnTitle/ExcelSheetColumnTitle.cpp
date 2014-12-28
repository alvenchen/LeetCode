/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
*/

#include <Windows.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		string s;
		do
		{
			s.insert(0,1,(n-1) % 26 + 'A');
			n = (n-1) / 26;
		}while(n > 0);

		return s;
	}

};

int main()
{
	srand(GetTickCount());

	Solution solution;
	int r = rand();
	cout << r << ":" << solution.convertToTitle(rand());

	system("pause");

	return 0;
}