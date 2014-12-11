/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.

*/

//start and end is in the dict

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;


void Create(unordered_set<string> &set, int n, int size, int valid, string &start, string &end)
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
			r = rand() % valid + 'a';
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

void Print(vector<vector<string>> &seq)
{
	for (int i=0; i<seq.size(); i++)
	{
		for (int j=0; j<seq[i].size(); j++)
		{
			printf("%s ", seq[i][j].c_str());
		}
		printf("\n");
	}
}

class Solution
{
public:
	vector<vector<string>> ladderLength(string start, string end, unordered_set<string> &dict)
	{
		vector<vector<string>> ret;
		vector<vector<string>> tmpSaveAll;
		vector<string> beginSeq;
		beginSeq.push_back(start);
		tmpSaveAll.push_back(beginSeq);

		queue<string> ladder;
		ladder.push(start);
		map<string, int> m;//store length, and make tmpString to be unique
		m.insert(std::pair<string, int>(start, 1));//init length to 1
		string tmp;
		bool Done = false;
		int shortetLen = 0;

		while (!ladder.empty() && !Done)
		{
			tmp = ladder.front();
			ladder.pop();

			string find;
			int length;
			for (int i=0; i<start.size() && !Done; i++)
			{
				find = tmp;
				for (int j='a'; j<'z'; j++)
				{
					find[i] = j;
					if (dict.find(find)!=dict.end() && m.find(find) == m.end())
					{
						length = m[tmp];
						if (shortetLen!=0 && length+1 > shortetLen)
						{
							Done = true;
							break;
						}

						int k=0;
						for (; k<tmpSaveAll.size(); k++)
						{
							if (tmpSaveAll[k].back() == tmp)
							{
								tmpSaveAll.push_back(tmpSaveAll[k]);//copy that
								tmpSaveAll[k].push_back(find);
								break;
							}
						}

						if (find == end)
						{
							shortetLen = length + 1;
							ret.push_back(tmpSaveAll[k]);
							//tmpSaveAll.erase(tmpSaveAll.begin() + k);
						}
						else
						{
							ladder.push(find);
							m.insert(std::pair<string, int>(find, length + 1));
						}

					}
				}
			}
		}
		return ret;
	}
};

class Solution2
{
	map< string, unordered_set<string> >&
		buildTree(string& start, string& end, unordered_set<string> &dict) {
			static map< string, unordered_set<string> > parents;
			parents.clear();
			unordered_set<string> level[3];
			unordered_set<string> *previousLevel = &level[0];
			unordered_set<string> *currentLevel = &level[1];
			unordered_set<string> *newLevel = &level[2];
			unordered_set<string> *p =NULL;
			currentLevel->insert(start);
			bool reachEnd = false;
			while( !reachEnd ) {
				newLevel->clear();
				for(auto it=currentLevel->begin(); it!=currentLevel->end(); it++) {
					for (int i=0; i<it->size(); i++) {
						string newWord = *it;
						for(char c='a'; c<='z'; c++){
							newWord[i] = c;
							if (newWord == end){
								reachEnd = true;
								parents[*it].insert(end);
								continue;
							}
							if ( dict.count(newWord)==0 || currentLevel->count(newWord)>0 || previousLevel->count(newWord)>0 ) {
								continue;
							}
							newLevel->insert(newWord);
							//parents[newWord].insert(*it);
							parents[*it].insert(newWord);
						}
					}
				}
				if (newLevel->empty()) break;
				p = previousLevel;
				previousLevel = currentLevel;
				currentLevel = newLevel;
				newLevel = p;
			}
			if ( !reachEnd ) {
				parents.clear();
			}
			return parents;
	}
	void generatePath( string start, string end,
		map< string, unordered_set<string> > &parents,
		vector<string> path,
		vector< vector<string> > &paths) {
			if (parents.find(start) == parents.end()){
				if (start == end){
					paths.push_back(path);
				}
				return;
			}
			for(auto it=parents[start].begin(); it!=parents[start].end(); it++){
				path.push_back(*it);
				generatePath(*it, end, parents, path, paths);
				path.pop_back();
			}
	}
	vector< vector<string> >
		findLadders(string start, string end, unordered_set<string> &dict) {
			vector< vector<string> > ladders;
			vector<string> ladder;
			ladder.push_back(start);
			if (start == end){
				ladder.push_back(end);
				ladders.push_back(ladder);
				return ladders;
			}
			map< string, unordered_set<string> >& parents = buildTree(start, end, dict);
			if (parents.size()<=0) {
				return ladders;
			}
			generatePath(start, end, parents, ladder, ladders);
			return ladders;
	}
};



int main()
{
	srand(GetTickCount());

	unordered_set<string> dict;
	string start, end;
// 	start = "hit";
// 	end = "cog";
// 	dict.insert("hot");
// 	dict.insert("dot");
// 	dict.insert("dog");
// 	dict.insert("lot");
// 	dict.insert("log");
// 	dict.insert("cog");

	Create(dict, 1000, 5, 5, start, end);
	Print(dict);
	printf("-----------------------\n");
	printf("start %s   end %s\n", start.c_str(), end.c_str());
	printf("=======================\n\n");


	LARGE_INTEGER t1, t2, tc, fq;
	QueryPerformanceFrequency(&fq);
	QueryPerformanceCounter(&t1);
	printf("solution1:\n");
	Solution soluton;
	vector<vector<string>> sequence;
	sequence = soluton.ladderLength(start, end, dict);
	printf("seq:\n");
	Print(sequence);

	QueryPerformanceCounter(&tc);
	printf("spend :%f\n\n", float(tc.QuadPart - t1.QuadPart) / fq.QuadPart);

	QueryPerformanceCounter(&t2);

	printf("solution2:\n");
	Solution soluton2;
	sequence = soluton2.ladderLength(start, end, dict);
	printf("seq:\n");
	Print(sequence);

	QueryPerformanceCounter(&tc);
	printf("spend :%f\n\n", float(tc.QuadPart - t2.QuadPart) / fq.QuadPart);

	system("pause");

	return 0;
}