/*
Given an array of integers, every element appears twice except for one. Find that single one.

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
		int Xor = 0;
		for (int i=0; i<n; i++)
		{
			Xor ^= A[i];
		}
		return Xor;
	}
};

void Create(int *A, int n)
{
	int r = rand() % 100;
	printf("%d\n", r);
	A[0] = r;
	for (int i=1; i<n; i+=2)
	{
		r = rand() % 100;
		A[i] = r;
		A[i + 1] = r;
	}
}

int main()
{
	srand(GetTickCount());
	const int NUM = 9;
	int *A = new int[NUM];
	Create(A, NUM);

	Solution solution;
	printf("%d", solution.singleNumber(A, NUM));

	system("pause");

	delete []A;
	return 0;
}