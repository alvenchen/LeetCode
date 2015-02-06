/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about tha
*/

#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> vec;
		if (n == 0)
		{
			vec.push_back(0);
			return vec;
		}

		vector<int> ass;
		ass.push_back(1);
		int num = 0;
		vec.push_back(0);
		int size = 1 << n;
		int iter = 0;
		int carry = 1;
		bool bRound = false;
		int calc = 1;
		for (int i=1; i<size; i++)
		{
			num ^= calc;
			vec.push_back(num);

			if (iter+1 >= carry)
			{
				carry *= 2;
				ass.push_back(carry);
				calc = carry;
				iter = 0;
			}
			else
			{
				 calc = ass[iter++];
				 ass.push_back(calc);
			}
		}

		return vec;
	}

	vector<int> grayCode2(int n) {
		vector<int> ret;
		int size = 1 << n;
		for(int i = 0; i < size; ++i) {
			ret.push_back((i >> 1)^i);
		}
		return ret;
	}
};

int main()
{
	Solution s;
	s.grayCode(6);
	s.grayCode2(6);

	return 0;
}