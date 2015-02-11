/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		return binarySearch(A, 0, n-1, target);
	}

	int binarySearch(int A[], int start, int end, int target)
	{
		if (end - start <= 1)
		{
			if (A[start] == target)
			{
				return start;
			}
			if (A[end] == target)
			{
				return end;
			}
			return -1;
		}
		int mid = (start + end) / 2;
		if (A[end] > A[start])//no rotated
		{
			if (target >= A[mid])
			{
				return binarySearch(A, mid, end, target);
			}
			return binarySearch(A, start, mid, target);
		}

		if (A[mid] > A[end])
		{
			if (target >= A[mid])
			{
				return binarySearch(A, mid, end, target);
			}
			if (target <= A[end])
			{
				return binarySearch(A, mid, end, target);
			}
			return binarySearch(A, start, mid, target);
		}

		if (target <= A[mid])
		{
			return binarySearch(A, start, mid, target);
		}
		if (target >= A[start])
		{
			return binarySearch(A, start, mid, target);
		}
		return binarySearch(A, mid, end, target);
	}
};

int main()
{
	int A[] = {4, 5, 6, 7, 0, 1, 2};
	Solution so;
	for (int i=0; i<sizeof(A)/sizeof(int); i++)
	{
		cout<<so.search(A, sizeof(A)/sizeof(int), A[i])<<endl;
	}

	getchar();

	return 0;
}