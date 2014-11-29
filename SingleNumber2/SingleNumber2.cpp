/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

class Solution 
{
public:
	int singleNumber(int A[], int n) 
	{
		int ret = 0;
		int bitsTimes[32] = {0};

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<32; j++)
			{
				if (A[i] & 0x1<<j)
				{
					bitsTimes[j]++;
				}
			}
		}
		for (int i=0; i<32; i++)
		{
			if (bitsTimes[i] % 3 != 0)//it's the key of algorism 0 or 3 times bits will be zero after mod 3
			{
				ret |= 0x1 << i;
			}
		}

		return ret;
	}
};

void Create(int *A, int n)
{
	int r = rand() % 100;
	printf("%d \n", r);
	int i=1;

	A[0] = r;

	for (; i<n; i+=3)
	{
		r = rand() % 100;
		A[i] = r;
		A[i + 1] = r;
		A[i + 2] = r;
	}
}

int main()
{
	srand(GetTickCount());
	const int NUM = rand() % 100 * 3 + 1;
	int *A = new int[NUM];
	Create(A, NUM);

	Solution solution;
	printf("%d", solution.singleNumber(A, NUM));

	system("pause");

	delete []A;
	return 0;
}