/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int iA = m-1, iB = n-1;

		for (int i=m+n-1; i>=0; i--)
		{
			if (iB < 0)
			{
				break;
			}
			if (iA < 0)
			{
				A[i] = B[iB--];
				continue;
			}

			if (A[iA] >= B[iB])
			{
				A[i] = A[iA--];
			}
			else
			{
				A[i] = B[iB--];
			}
		}
	}


};
