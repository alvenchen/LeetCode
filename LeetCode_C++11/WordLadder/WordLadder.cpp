/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//recursive
class Solution
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		int min = 0, currMin = 1;

		ladder(start, end, dict, min, currMin);

		return min;
	}

	void ladder(string &start, string &end, unordered_set<string> &dict, int &min, int &currMin)
	{
		if (min > 0 && currMin > 0 && currMin>= min)
		{
			return;
		}
		
		if (start == end)//done
		{
			if (min == 0 || min > currMin)
			{
				min = currMin;
				printf("\n\n%s %s  %d\n\n", start.c_str(), end.c_str(), min);
			}
			return;
		}
		else
		{
			for (int i=0; i<start.size(); i++)
			{
				string tmp;
				for (char j='a'; j<'z'; j++)
				{
					tmp = start;
					tmp[i] = j;
					if (dict.find(tmp) != dict.end())
					{
						dict.erase(tmp);
						currMin++;
						ladder(tmp, end, dict, min, currMin);
						currMin--;
						dict.insert(tmp);
					}
				}
			}
		}
	}
};

//non-recursive
//breadth-first : store all of the tmpString in a queue, to determine whether it can transfer to end
//because it's breadth-first, it's length will be the shortest
//tmpString fifo
class Solution2
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		queue<string> ladder;
		ladder.push(start);
		map<string, int> m;//store length, and make tmpString to be unique
		m.insert(std::pair<string, int>(start, 1));//init length to 1
		string tmp;
		bool bFind = false;

		while (!ladder.empty() && !bFind)
		{
			tmp = ladder.front();
			ladder.pop();

			string find;
			int length;
			for (int i=0; i<start.size() && !bFind; i++)
			{
				find = tmp;
				for (int j='a'; j<'z'; j++)
				{
					find[i] = j;
					if (dict.find(find)!=dict.end() && m.find(find) == m.end())
					{
						length = m[tmp];
						ladder.push(find);
						m.insert(std::pair<string, int>(find, length + 1));
						if (find == end)
						{
							bFind = true;
							break;
						}
					}
				}
			}
			
		}

		return bFind ? m[end] : 0;
	}
};

void Create(unordered_set<string> &set, int n, int size, string &start, string &end)
{
	string tmp;
	char r;
	int s, e;
	s = rand() % n;
	do
	{
		e = rand() % n;
	}while(s == e);
	
	for (int i=0; i<n; i++)
	{
		tmp.clear();
		for (int j=0; j<size; j++)
		{
			r = rand() % 4 + 'a';
			tmp += r;
		}
		if (i == s)
		{
			start = tmp;
		}
		if(i == e)
		{
			end = tmp;
		}
		set.insert(tmp);
	}
}

void Print(unordered_set<string> &set)
{
	unordered_set<string>::iterator it = set.begin();
	for (; it!=set.end(); ++it)
	{
		printf("%s ", (*it).c_str());
	}
	printf("\n");
}

int main()
{
	srand(GetTickCount());

	unordered_set<string> dict;
	string start, end;

	Create(dict, 20, 2, start, end);
	Print(dict);
	printf("start %s   end %s\n", start.c_str(), end.c_str());

 	Solution soluton;
 	printf("solution1: %d\n", soluton.ladderLength(start, end, dict));
	
	Solution2 soluton2;
	printf("solution2: %d\n", soluton2.ladderLength(start, end, dict));

	system("pause");

	return 0;
}