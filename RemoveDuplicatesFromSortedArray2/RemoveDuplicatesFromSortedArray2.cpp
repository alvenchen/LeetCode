/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
*/

#include <iostream>

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 1)
		{
			return n;
		}
		int pos=0;
		bool bDuplocate = false;
		for (int i=0; i<n-1; i++)
		{
			if (bDuplocate)
			{
				if (A[i+1] > A[i])
				{
					A[++pos] = A[i+1];
					bDuplocate = false;
				}
			}
			else
			{
				if (A[i+1] == A[i])
				{
					bDuplocate = true;
				}
				else
				{
					bDuplocate = false;
				}	
				A[++pos] = A[i+1];			
			}
		}

		return pos+1;
	}
};

int main()
{
	int A[] = {0, 0, 0, 1, 2, 2, 4, 4};

	Solution so;
	so.removeDuplicates(A, sizeof(A)/sizeof(int));

	return 0;
}