/*
Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2]times
You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int> &num)
	{
		vector<int> tmp;
		while(num.size() > 1)
		{
			tmp.clear();
			for (int i=0; i<num.size(); i+=2)
			{
				if (i == num.size()-1)
				{
					tmp.push_back(num[i]);
					break;
				}
				if (num[i]==num[i+1])
				{
					tmp.push_back(num[i]);
				}
			}
			num = tmp;
		}

		return num[0];
	}

};

//Moore Voting Algorithm
class Solution2
{
public:
	int majorityElement(vector<int> &num)
	{
		int majority;
		int cnt = 0;
		for(int i=0; i<num.size(); i++)
		{
			if ( cnt ==0 )
			{
				majority = num[i];
				cnt++;
			}
			else
			{
				majority == num[i] ? cnt++ : cnt --;
				if (cnt >= num.size()/2+1)
				{
					break;		
				}
			}
		}
		return majority;
	}

};

void Create(vector<int> &vec, int n)
{
	int element = rand() % 10;
	for (int i=0; i<n; i++)
	{
		vec.push_back(element);
	}
	cout<<"majority:"<<element<<endl;
	
	int otherNum = rand();
	while(otherNum > n / 2)
	{
		otherNum = rand();
	}
	for (int i=0, pos = 0; i<otherNum; i++)
	{
		pos = rand() % n;
		vec[pos] = rand() % 100;
	}
}

void Print(vector<int> &vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	srand(GetTickCount());
	Solution solution;
	Solution2 solution2;
	vector<int> vec;
	Create(vec, 20);
	Print(vec);

	cout<<solution.majorityElement(vec)<<endl;
	cout<<solution2.majorityElement(vec);

	system("pause");

	return 0;
}