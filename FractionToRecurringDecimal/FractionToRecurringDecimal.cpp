/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <map>
#include <math.h>

using namespace std;

class Solution
{
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			return 0;
		}
		string s;

		bool bNeg = false;
		if ((long long)numerator * denominator < 0)
		{
			bNeg = true;
			numerator = -numerator;
		}

		//calc decimal
		map<long long, int> m;
		long long remained = (long long)numerator % denominator;
		int pos = 0;

		if (remained != 0)
		{
			while (remained != 0)
			{
				//because denominator is the same, so if remained is the same, the number repeats
				//eg. 1/7 remained 3/7. remained 2/7. remained 6/7. remained 4/7 remained 5/7 remained 1/7 (that's it) 
				if (m.count(remained) > 0)
				{
					s.insert(m[remained],1,'(');
					s.push_back(')');
					break;
				}

				m[remained] = pos++;
				s.push_back(remained*10/denominator + '0');
				remained = remained*10 % denominator;
			}
			s.insert(0, 1, '.');	
		}

		//calc interger
		remained = (long long)numerator / denominator;
		do
		{
			s.insert(0, 1, abs((int)(remained % 10)) + '0');
			remained = remained / 10;
		}while(remained != 0);

		if (bNeg)
		{
			s.insert(0, 1, '-');
		}
		return s;
	}
};

int main()
{
	srand(GetTickCount());
	//int numerator = rand(), denominator = rand();
	int numerator = -2147483648, denominator = 1;
	//int numerator = 45, denominator = 56;

	Solution solution;

	cout << numerator << "/" <<denominator << ":" <<solution.fractionToDecimal(numerator, denominator);

	system("pause");

	return 0;
}