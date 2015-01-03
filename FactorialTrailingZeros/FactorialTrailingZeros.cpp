/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

/*
2*5			1
4*25		2
8*125		3	
16*625		4
32*3125		5
*/

class Solution
{
public:
	int trailingZeroes(int n)
	{
		int ret = 0;
		double m = 5;
		int count = (double)n / m;
		while(count > 0)
		{
			ret += count;
			m *= 5;
			count = (double)n / m;
		}

		return ret;
	}
};

string Factorial(int n)
{
	string data;
	int carry = 0;
	int curr = 0;
	int tmp = 0;
	data = '1';
	for (int i=2; i<=n; i++)
	{
		carry = 0;
		for (int j=data.size()-1; j>=0; j--)
		{
			curr = data[j] - '0';
			tmp = curr;
			curr = (curr * i + carry) % 10;
			carry = (tmp * i + carry) / 10;
			data[j] = curr + '0';
			if (carry>0 && j==0)
			{
				data.insert(0,1,carry+'0');
				break;
			}
		}
	}
	return data;
}

int Count(string str)
{
	int n = 0;
	for (int i=str.size()-1; i>=0; i--)
	{
		if (str[i]!='0')
		{
			break;
		}
		n++;
	}
	return n;
}

int main()
{
	srand(GetTickCount());
	int n = 1808548329;//n=rand()%500
	string fac;
// 	for (int i=n; i<=n; i++)
// 	{
// 		fac = Factorial(i);
// 		cout<<i<<":"<<fac.c_str()<<":"<<Count(fac)<<endl;
// 	}

	Solution s;
	cout <<"\n"<<n<<"trailingZeroes:"<<s.trailingZeroes(n);

	system("pause");
	return 0;
}